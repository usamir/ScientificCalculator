#include "Calculator.h"

/************************************************************************/
/* Function that return priority of each available operation
    @param in: char operation
    @return priority of operation
*/
/************************************************************************/
int Calculator::priority(char operation)
{
    if(operation == 'l') 
    {
        return 3;
    }
    if(operation == '*' ||
        operation == '/')
    {
        return 2;
    }
    else if(operation == '+' ||
        operation == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/************************************************************************/
/* execute operation with numbers from stack
    @param in: stack<double> &stack - stack of numbers
    @param in: char operation - operation which to be executed */
/************************************************************************/
void Calculator::executeOperation(stack<double> &stack, char operation) 
{
    int stackSize = stack.size();
    // logic for log operation
    if(operation=='l')
    {
        if(stackSize < 1)
        {
            throw "Unbalanced operators and operand!";
        }
        double fromStack = stack.top();
        double result = log(fromStack);
        stack.pop();
        stack.push(result);
        return;
    }                
    if(stackSize < 2)
    {
        throw "Unbalanced operators and operand!";
    }

    // calculation of basic operations
    double op1 = stack.top();
    stack.pop();
    double op2 = stack.top();
    stack.pop();
    double result;
    if(operation == '+') 
    {
        result = op2 + op1;
    }
    else if(operation == '-')
    {
        result = op2 - op1;
    }
    else if(operation == '*') 
    {
        result = op2 * op1;
    }
    else if(operation == '/')
    {
        result = op2 / op1;
    }
    stack.push(result);
}

/************************************************************************/
/* Parsing unknown variable "X"
    @param in: const string& expression - expression which we are parsing
    @param in: int& pos - position of iterator through expression
    @param in: char& previous - type of previous character in expression
    */
/************************************************************************/
void Calculator::parseVariable(const string& expression, int& pos, char& previous)
{
    double number;

    // previous is number, bad format is should be something like 2*x, not 2x
    if (previous == '0')
    {
        throw "Bad format!";
    }

    // do not support divide operation
    if (previous == '/')
    {
        throw "Unexpected operator!";
    }

    // prior to 'x' we have number and multiply operation
    if (previous == '*')
    {
        // get the number from stack
        number = mStackNums.top();
        mStackNums.pop();
        // pop out multiply operation from stack
        if (mStackChars.top() == '*')
        {
            mStackChars.pop();
        }
        

        stringstream ss;
        ss << number;
        string numberStr = ss.str();

        // check for operation prior to variable
        if (pos > (int)numberStr.length() + 1)
        {
            if (expression[pos - numberStr.length() - 2] == '+')
            {
                mStackChars.pop();
            }
            if (expression[pos - numberStr.length() - 2] == '-')
            {
                mStackChars.pop();
            }
        }
    }
    else if (previous == '+' ||
             previous == '-' ||
             previous == '(' ||
             previous == '=')
    {
        if (previous == '-' || previous == '+')
        {
            mStackChars.pop();
        }
        number = 1.0;
    }

    if (previous != ')')
    {
        if (mPreviousSign == '-')
        {
            number = -number;
        }
    }
    
    mVectorVariables.push_back(number);
    pos++;
    previous = 'x';
}

/************************************************************************/
/* Parsing number from expression"
    @param in: const string& expression - expression which we are parsing
    @param in: int& pos - position of iterator through expression
    @param in: char& previous - type of previous character in expression 
*/
/************************************************************************/
void Calculator::parseNumber(const string& expression, int& pos, char& previous)
{
    string numberStr;
    bool continueOn = pos < (int)(expression.length());

    while (continueOn)
    {
        char c = expression[pos];

        continueOn = (c == '.');

        // logic for detecting digits of number and decimal number
        if (isdigit(c))
        {
            numberStr += c;
            pos++;
            continueOn = pos < (int)(expression.length());
        }
        else
        {
            bool continueOn = c == '.';
            if (continueOn)
            {
                numberStr += c;
                pos++;
                continueOn = pos < (int)(expression.length());
            }
        }
    }
    
    double number = atof(numberStr.c_str());

    // handle special scenarios regarding number and equation sign
    if (mStackNums.empty() && previous == '=')
    {
        number = -number;
    }
    if (mPreviousSign == '-' && !afterEqualSign && mStackChars.empty())
    {
        number = -number;
    }
    if (mPreviousSign == '+' && afterEqualSign && mStackChars.empty())
    {
        number = -number;
    }

    // handle the brackets after the equal sign
    if (previous == '(' && afterEqualSign)
    {
        number = -number;
    }

    mStackNums.push(number);
    previous = '0';
}

/************************************************************************/
/* Parsing available basic operation, add, sub, multiply and divide
    @param in: const string& expression - expression which we are parsing
    @param in: int& pos - position of iterator through expression
    */
/************************************************************************/
void Calculator::parseBasicOperators(const string& expression, int& pos, char previous)
{
    char c = expression[pos];

    // handle '+' and '-'
    if (c == '+')
    {
        mPreviousSign = '+';
        if (afterEqualSign && expression[pos + 1] != '(')
        {
            c = '-';
            mPreviousSign = '-';
        }
    }
    else if (c == '-')
    {
        mPreviousSign = '-';
        if (afterEqualSign && expression[pos + 1] != '(')
        {
            c = '+';
            mPreviousSign = '+';
        }
    }

    // push operation to stack if have priority bigger than previous operation on stack
    // execute operation
    while (true) 
    {
        // do not push to stack operation if previous char is 'x'
        // unless it is multiply operation
        if (mStackNums.empty() && (c == '+' || c == '-'))
        {
            break;
        }

        if (mStackChars.empty() ||
            priority(c) > priority(mStackChars.top()))
        {
            mStackChars.push(c);
            break;
        }
        executeOperation(mStackNums, mStackChars.top());
        mStackChars.pop();
    }
    
}

/************************************************************************/
/*  Function to parse expression that user have entered
    @param in: string& expression - inputed equation */
/************************************************************************/
void Calculator::parse(const string& expression)
{
    int numberBrackets(0);
    char previous = '(';
    

    if (expression.empty())
    {
        throw "Cannot parse empty expression!";
    }

    try 
    {
        int i = 0;
        while (i < (int)expression.length())   
        {
            char c = expression[i];

            // parse unknown variable 'x' in expression 
            if (c == 'x')
            {
                parseVariable(expression, i, previous);
            }
            // parse number from expression
            else if(c >= '0' && c <= '9') 
            {
                parseNumber(expression, i, previous);
            }
            // calculate operations, brackets and equality sign
            else
            {
                // when we get equal
                if (c == '=')
                {
                    // set flag to true
                    afterEqualSign = true;

                    if (i < (int)expression.length() - 1)
                    {
                        char nextC = expression[i + 1];
                        // next char at expression is number, push to stack of chars, sub operation
                        if ((nextC >= '0' && nextC <= '9'))
                        {
                            while(!mStackChars.empty()) 
                            {
                                executeOperation(mStackNums, mStackChars.top());
                                mStackChars.pop();
                            }

                            if (mStackChars.empty() && !mStackNums.empty())
                            {
                                mPreviousSign = '-';
                                mStackChars.push('-');
                            }
                        }
                        else if (nextC == 'x' && !mVectorVariables.empty())
                        {
                            mPreviousSign = '-';
                        }
                        else if (nextC == '(')
                        {
                            while(!mStackChars.empty()) 
                            {
                                executeOperation(mStackNums, mStackChars.top());
                                mStackChars.pop();
                            }
                            
                            if (mStackChars.empty() && !mStackNums.empty())
                            {
                                mPreviousSign = '+';
                                mStackChars.push('+');
                            }
                        }
                        else if (nextC == ')' ||
                                 priority(nextC) > 0)
                        {
                            throw "Unexpected operator!";
                        }
                    }
                    else
                    {
                        throw "Unbalanced operators and operand!";
                    }
                }
                else if(c != 'l' && priority(c) > 0) 
                {
                    if(priority(previous) > 0 || 
                        previous=='(')
                    {
                        throw "Unexpected operator!";
                    }

                    parseBasicOperators(expression, i, previous);
                    
                }
                else if (c == '(') 
                {
                    mStackChars.push('('); 
                    numberBrackets++;
                }
                // calculate in brackets
                else if (c==')') 
                {
                    numberBrackets--;
                    if (numberBrackets < 0)
                    {
                        throw "Too many closing brackets!";
                    }
                    while (mStackChars.top() != '(') 
                    {
                        executeOperation(mStackNums, mStackChars.top());
                        mStackChars.pop();
                    }
                    mStackChars.pop();
                }
                else if (c == 'l')
                {
                    if (i > 0)
                    {
                        if (previous == '0')
                        {
                            throw "Bad format! Expected operation prior to log";
                        }
                    }
                    if (i < (int)expression.length() - 2)
                    {
                        if (expression[i + 1] != 'o')
                        {
                            throw "Unexpected char!";
                        }
                        else if (expression[i + 2] != 'g')
                        {
                            throw "Unexpected char!";
                        }
                    }
                    else 
                    {
                        throw "Unbalanced operators and operand!";
                    }
                    i += 2;
                    mStackChars.push('l');
                }
                else
                {
                    throw "Unexpected operation!";
                }
                previous = c;
                i++;
            }
        }

        if(numberBrackets > 0)
        {
            throw "Missing closing bracket!";
        }

        while(!mStackChars.empty()) 
        {
            executeOperation(mStackNums, mStackChars.top());
            mStackChars.pop();
        }
        if(mStackNums.size() != 1)
        {    
            throw "Unbalanced operators and operand!";
        }
    }
    catch(const char message[]) 
    {
        throw message;
    }
}

/************************************************************************/
/* Function to calculate equation, equation with unknown variable and
   equation without unknown variable
   @param in: string& expression - inputed equation 
   @return: result of equation */
/************************************************************************/
double Calculator::calculate(const string& expression)
{
    double result(0);
    try
    {
        // parse expression
        parse(expression);
        // b will be calculated numbers without unknown variable
        // equation is of type a * x + b = 0 
        double b = mStackNums.top();

        if (!mVectorVariables.empty())
        {
            double a = 0;
            for (unsigned int i = 0; i < mVectorVariables.size(); i++)
            {
                a += mVectorVariables[i];
            }
            if (a == 0)
            {
                throw "Cannot divide with 0";
            }
            result = -b / a;
        }
        else
        {
            result = b;
        }
    }
    catch(const char message[]) 
    {
        throw message;
    }

    return result;
}
