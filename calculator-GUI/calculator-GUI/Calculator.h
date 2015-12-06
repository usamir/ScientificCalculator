#include <stack>
#include <string>
#include <math.h>
#include <vector>
#include <sstream>

using namespace std;

class Calculator
{
private:
    vector<double> mVectorVariables;
    stack<char> mStackChars;
    stack<double> mStackNums;
    bool afterEqualSign;
    char mPreviousSign;

    int priority(char operation);
    void executeOperation(stack<double> &stack, char operation);
    void parseVariable(const string& expression, int& pos, char& previous);
    void parseNumber(const string& expression, int& pos, char& previous);
    void parseBasicOperators(const string& expression, int& pos, char previous);
    void parse(const string& expression);
public:
    Calculator(){ afterEqualSign = false; }
    double calculate(const string& expression);
};