#pragma once
#include "Calculator.h"



namespace calculatorGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
            
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
            isError = false;
            isResult = false;
            findedX = false;
            isEquation = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
    private: System::Windows::Forms::TextBox^  inputBox;
    protected: 

    private: System::Windows::Forms::Button^  buttonClear;
    private: System::Windows::Forms::Button^  buttonDivide;
    private: System::Windows::Forms::Button^  buttonMultiply;
    private: System::Windows::Forms::Button^  buttonClearInput;
    private: System::Windows::Forms::Button^  buttonNum7;
    private: System::Windows::Forms::Button^  buttonNum8;
    private: System::Windows::Forms::Button^  buttonNum9;
    private: System::Windows::Forms::Button^  buttonSub;
    private: System::Windows::Forms::Button^  buttonNum4;
    private: System::Windows::Forms::Button^  buttonNum5;
    private: System::Windows::Forms::Button^  buttonNum6;
    private: System::Windows::Forms::Button^  buttonAdd;
    private: System::Windows::Forms::Button^  buttonNum1;
    private: System::Windows::Forms::Button^  buttonNum2;
    private: System::Windows::Forms::Button^  buttonNum3;
    private: System::Windows::Forms::Button^  buttonLog;
    private: System::Windows::Forms::Button^  buttonNum0;
    private: System::Windows::Forms::Button^  buttonPoint;
    private: System::Windows::Forms::Button^  buttonOpeningBracket;
    private: System::Windows::Forms::Button^  buttonClosingBracket;
    private: System::Windows::Forms::Button^  buttonEqual;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
        bool isResult;
        bool isError;
        bool findedX;
        bool isEquation;

    private: System::Windows::Forms::Button^  buttonEquation;
    private: System::Windows::Forms::Button^  buttonX;
    private: System::Windows::Forms::MenuStrip^  MainMenu;
    private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^  guideToolStripMenuItem;

             System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
            System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
            this->inputBox = (gcnew System::Windows::Forms::TextBox());
            this->buttonClear = (gcnew System::Windows::Forms::Button());
            this->buttonDivide = (gcnew System::Windows::Forms::Button());
            this->buttonMultiply = (gcnew System::Windows::Forms::Button());
            this->buttonClearInput = (gcnew System::Windows::Forms::Button());
            this->buttonNum7 = (gcnew System::Windows::Forms::Button());
            this->buttonNum8 = (gcnew System::Windows::Forms::Button());
            this->buttonNum9 = (gcnew System::Windows::Forms::Button());
            this->buttonSub = (gcnew System::Windows::Forms::Button());
            this->buttonNum4 = (gcnew System::Windows::Forms::Button());
            this->buttonNum5 = (gcnew System::Windows::Forms::Button());
            this->buttonNum6 = (gcnew System::Windows::Forms::Button());
            this->buttonAdd = (gcnew System::Windows::Forms::Button());
            this->buttonNum1 = (gcnew System::Windows::Forms::Button());
            this->buttonNum2 = (gcnew System::Windows::Forms::Button());
            this->buttonNum3 = (gcnew System::Windows::Forms::Button());
            this->buttonLog = (gcnew System::Windows::Forms::Button());
            this->buttonNum0 = (gcnew System::Windows::Forms::Button());
            this->buttonPoint = (gcnew System::Windows::Forms::Button());
            this->buttonOpeningBracket = (gcnew System::Windows::Forms::Button());
            this->buttonClosingBracket = (gcnew System::Windows::Forms::Button());
            this->buttonEqual = (gcnew System::Windows::Forms::Button());
            this->buttonEquation = (gcnew System::Windows::Forms::Button());
            this->buttonX = (gcnew System::Windows::Forms::Button());
            this->MainMenu = (gcnew System::Windows::Forms::MenuStrip());
            this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->guideToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->MainMenu->SuspendLayout();
            this->SuspendLayout();
            // 
            // inputBox
            // 
            this->inputBox->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
            this->inputBox->AllowDrop = true;
            this->inputBox->Location = System::Drawing::Point(41, 58);
            this->inputBox->Name = L"inputBox";
            this->inputBox->Size = System::Drawing::Size(578, 22);
            this->inputBox->TabIndex = 0;
            this->inputBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::inputBox_KeyPress);
            // 
            // buttonClear
            // 
            this->buttonClear->Location = System::Drawing::Point(70, 131);
            this->buttonClear->Name = L"buttonClear";
            this->buttonClear->Size = System::Drawing::Size(75, 36);
            this->buttonClear->TabIndex = 1;
            this->buttonClear->Text = L"C";
            this->buttonClear->UseVisualStyleBackColor = true;
            this->buttonClear->Click += gcnew System::EventHandler(this, &Form1::buttonClear_Click);
            // 
            // buttonDivide
            // 
            this->buttonDivide->Location = System::Drawing::Point(313, 257);
            this->buttonDivide->Name = L"buttonDivide";
            this->buttonDivide->Size = System::Drawing::Size(75, 36);
            this->buttonDivide->TabIndex = 2;
            this->buttonDivide->Text = L"/";
            this->buttonDivide->UseVisualStyleBackColor = true;
            this->buttonDivide->Click += gcnew System::EventHandler(this, &Form1::buttonDivide_Click);
            // 
            // buttonMultiply
            // 
            this->buttonMultiply->Location = System::Drawing::Point(313, 215);
            this->buttonMultiply->Name = L"buttonMultiply";
            this->buttonMultiply->Size = System::Drawing::Size(75, 36);
            this->buttonMultiply->TabIndex = 3;
            this->buttonMultiply->Text = L"*";
            this->buttonMultiply->UseVisualStyleBackColor = true;
            this->buttonMultiply->Click += gcnew System::EventHandler(this, &Form1::buttonMultiply_Click);
            // 
            // buttonClearInput
            // 
            this->buttonClearInput->Location = System::Drawing::Point(151, 131);
            this->buttonClearInput->Name = L"buttonClearInput";
            this->buttonClearInput->Size = System::Drawing::Size(75, 36);
            this->buttonClearInput->TabIndex = 4;
            this->buttonClearInput->Text = L"CE";
            this->buttonClearInput->UseVisualStyleBackColor = true;
            this->buttonClearInput->Click += gcnew System::EventHandler(this, &Form1::buttonClearInput_Click);
            // 
            // buttonNum7
            // 
            this->buttonNum7->Location = System::Drawing::Point(70, 173);
            this->buttonNum7->Name = L"buttonNum7";
            this->buttonNum7->Size = System::Drawing::Size(75, 36);
            this->buttonNum7->TabIndex = 5;
            this->buttonNum7->Text = L"7";
            this->buttonNum7->UseVisualStyleBackColor = true;
            this->buttonNum7->Click += gcnew System::EventHandler(this, &Form1::buttonNum7_Click);
            // 
            // buttonNum8
            // 
            this->buttonNum8->Location = System::Drawing::Point(151, 173);
            this->buttonNum8->Name = L"buttonNum8";
            this->buttonNum8->Size = System::Drawing::Size(75, 36);
            this->buttonNum8->TabIndex = 6;
            this->buttonNum8->Text = L"8";
            this->buttonNum8->UseVisualStyleBackColor = true;
            this->buttonNum8->Click += gcnew System::EventHandler(this, &Form1::buttonNum8_Click);
            // 
            // buttonNum9
            // 
            this->buttonNum9->Location = System::Drawing::Point(232, 173);
            this->buttonNum9->Name = L"buttonNum9";
            this->buttonNum9->Size = System::Drawing::Size(75, 36);
            this->buttonNum9->TabIndex = 7;
            this->buttonNum9->Text = L"9";
            this->buttonNum9->UseVisualStyleBackColor = true;
            this->buttonNum9->Click += gcnew System::EventHandler(this, &Form1::buttonNum9_Click);
            // 
            // buttonSub
            // 
            this->buttonSub->Location = System::Drawing::Point(313, 173);
            this->buttonSub->Name = L"buttonSub";
            this->buttonSub->Size = System::Drawing::Size(75, 36);
            this->buttonSub->TabIndex = 8;
            this->buttonSub->Text = L"-";
            this->buttonSub->UseVisualStyleBackColor = true;
            this->buttonSub->Click += gcnew System::EventHandler(this, &Form1::buttonSub_Click);
            // 
            // buttonNum4
            // 
            this->buttonNum4->Location = System::Drawing::Point(70, 215);
            this->buttonNum4->Name = L"buttonNum4";
            this->buttonNum4->Size = System::Drawing::Size(75, 36);
            this->buttonNum4->TabIndex = 9;
            this->buttonNum4->Text = L"4";
            this->buttonNum4->UseVisualStyleBackColor = true;
            this->buttonNum4->Click += gcnew System::EventHandler(this, &Form1::buttonNum4_Click);
            // 
            // buttonNum5
            // 
            this->buttonNum5->Location = System::Drawing::Point(151, 215);
            this->buttonNum5->Name = L"buttonNum5";
            this->buttonNum5->Size = System::Drawing::Size(75, 36);
            this->buttonNum5->TabIndex = 10;
            this->buttonNum5->Text = L"5";
            this->buttonNum5->UseVisualStyleBackColor = true;
            this->buttonNum5->Click += gcnew System::EventHandler(this, &Form1::buttonNum5_Click);
            // 
            // buttonNum6
            // 
            this->buttonNum6->Location = System::Drawing::Point(232, 215);
            this->buttonNum6->Name = L"buttonNum6";
            this->buttonNum6->Size = System::Drawing::Size(75, 36);
            this->buttonNum6->TabIndex = 11;
            this->buttonNum6->Text = L"6";
            this->buttonNum6->UseVisualStyleBackColor = true;
            this->buttonNum6->Click += gcnew System::EventHandler(this, &Form1::buttonNum6_Click);
            // 
            // buttonAdd
            // 
            this->buttonAdd->Location = System::Drawing::Point(313, 131);
            this->buttonAdd->Name = L"buttonAdd";
            this->buttonAdd->Size = System::Drawing::Size(75, 36);
            this->buttonAdd->TabIndex = 12;
            this->buttonAdd->Text = L"+";
            this->buttonAdd->UseVisualStyleBackColor = true;
            this->buttonAdd->Click += gcnew System::EventHandler(this, &Form1::buttonAdd_Click);
            // 
            // buttonNum1
            // 
            this->buttonNum1->Location = System::Drawing::Point(70, 257);
            this->buttonNum1->Name = L"buttonNum1";
            this->buttonNum1->Size = System::Drawing::Size(75, 36);
            this->buttonNum1->TabIndex = 13;
            this->buttonNum1->Text = L"1";
            this->buttonNum1->UseVisualStyleBackColor = true;
            this->buttonNum1->Click += gcnew System::EventHandler(this, &Form1::button13_Click);
            // 
            // buttonNum2
            // 
            this->buttonNum2->Location = System::Drawing::Point(151, 257);
            this->buttonNum2->Name = L"buttonNum2";
            this->buttonNum2->Size = System::Drawing::Size(75, 36);
            this->buttonNum2->TabIndex = 14;
            this->buttonNum2->Text = L"2";
            this->buttonNum2->UseVisualStyleBackColor = true;
            this->buttonNum2->Click += gcnew System::EventHandler(this, &Form1::buttonNum2_Click);
            // 
            // buttonNum3
            // 
            this->buttonNum3->Location = System::Drawing::Point(232, 258);
            this->buttonNum3->Name = L"buttonNum3";
            this->buttonNum3->Size = System::Drawing::Size(75, 36);
            this->buttonNum3->TabIndex = 15;
            this->buttonNum3->Text = L"3";
            this->buttonNum3->UseVisualStyleBackColor = true;
            this->buttonNum3->Click += gcnew System::EventHandler(this, &Form1::buttonNum3_Click);
            // 
            // buttonLog
            // 
            this->buttonLog->Location = System::Drawing::Point(313, 300);
            this->buttonLog->Name = L"buttonLog";
            this->buttonLog->Size = System::Drawing::Size(75, 36);
            this->buttonLog->TabIndex = 16;
            this->buttonLog->Text = L"log";
            this->buttonLog->UseVisualStyleBackColor = true;
            this->buttonLog->Click += gcnew System::EventHandler(this, &Form1::buttonLog_Click);
            // 
            // buttonNum0
            // 
            this->buttonNum0->Location = System::Drawing::Point(151, 300);
            this->buttonNum0->Name = L"buttonNum0";
            this->buttonNum0->Size = System::Drawing::Size(75, 36);
            this->buttonNum0->TabIndex = 17;
            this->buttonNum0->Text = L"0";
            this->buttonNum0->UseVisualStyleBackColor = true;
            this->buttonNum0->Click += gcnew System::EventHandler(this, &Form1::buttonNum0_Click);
            // 
            // buttonPoint
            // 
            this->buttonPoint->Location = System::Drawing::Point(232, 131);
            this->buttonPoint->Name = L"buttonPoint";
            this->buttonPoint->Size = System::Drawing::Size(75, 36);
            this->buttonPoint->TabIndex = 18;
            this->buttonPoint->Text = L".";
            this->buttonPoint->UseVisualStyleBackColor = true;
            this->buttonPoint->Click += gcnew System::EventHandler(this, &Form1::buttonPoint_Click);
            // 
            // buttonOpeningBracket
            // 
            this->buttonOpeningBracket->Location = System::Drawing::Point(70, 299);
            this->buttonOpeningBracket->Name = L"buttonOpeningBracket";
            this->buttonOpeningBracket->Size = System::Drawing::Size(75, 36);
            this->buttonOpeningBracket->TabIndex = 19;
            this->buttonOpeningBracket->Text = L"(";
            this->buttonOpeningBracket->UseVisualStyleBackColor = true;
            this->buttonOpeningBracket->Click += gcnew System::EventHandler(this, &Form1::buttonOpeningBracket_Click);
            // 
            // buttonClosingBracket
            // 
            this->buttonClosingBracket->Location = System::Drawing::Point(232, 299);
            this->buttonClosingBracket->Name = L"buttonClosingBracket";
            this->buttonClosingBracket->Size = System::Drawing::Size(75, 36);
            this->buttonClosingBracket->TabIndex = 20;
            this->buttonClosingBracket->Text = L")";
            this->buttonClosingBracket->UseVisualStyleBackColor = true;
            this->buttonClosingBracket->Click += gcnew System::EventHandler(this, &Form1::buttonClosingBracket_Click);
            // 
            // buttonEqual
            // 
            this->buttonEqual->Location = System::Drawing::Point(467, 131);
            this->buttonEqual->Name = L"buttonEqual";
            this->buttonEqual->Size = System::Drawing::Size(75, 63);
            this->buttonEqual->TabIndex = 21;
            this->buttonEqual->Text = L"=";
            this->buttonEqual->UseVisualStyleBackColor = true;
            this->buttonEqual->Click += gcnew System::EventHandler(this, &Form1::button21_Click);
            // 
            // buttonEquation
            // 
            this->buttonEquation->Enabled = false;
            this->buttonEquation->Location = System::Drawing::Point(467, 266);
            this->buttonEquation->Name = L"buttonEquation";
            this->buttonEquation->Size = System::Drawing::Size(75, 69);
            this->buttonEquation->TabIndex = 22;
            this->buttonEquation->Text = L"X=";
            this->buttonEquation->UseVisualStyleBackColor = true;
            this->buttonEquation->Click += gcnew System::EventHandler(this, &Form1::buttonEquation_Click);
            // 
            // buttonX
            // 
            this->buttonX->Location = System::Drawing::Point(467, 199);
            this->buttonX->Name = L"buttonX";
            this->buttonX->Size = System::Drawing::Size(75, 61);
            this->buttonX->TabIndex = 23;
            this->buttonX->Text = L"Var \"x\"";
            this->buttonX->UseVisualStyleBackColor = true;
            this->buttonX->Click += gcnew System::EventHandler(this, &Form1::buttonX_Click);
            // 
            // MainMenu
            // 
            this->MainMenu->BackColor = System::Drawing::Color::Azure;
            this->MainMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->helpToolStripMenuItem});
            this->MainMenu->Location = System::Drawing::Point(0, 0);
            this->MainMenu->Name = L"MainMenu";
            this->MainMenu->Size = System::Drawing::Size(782, 28);
            this->MainMenu->TabIndex = 24;
            this->MainMenu->Text = L"MainMenu";
            // 
            // helpToolStripMenuItem
            // 
            this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->guideToolStripMenuItem});
            this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
            this->helpToolStripMenuItem->Size = System::Drawing::Size(53, 24);
            this->helpToolStripMenuItem->Text = L"Help";
            // 
            // guideToolStripMenuItem
            // 
            this->guideToolStripMenuItem->Name = L"guideToolStripMenuItem";
            this->guideToolStripMenuItem->Size = System::Drawing::Size(117, 24);
            this->guideToolStripMenuItem->Text = L"Guide";
            this->guideToolStripMenuItem->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::guideToolStripMenuItem_MouseDown);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
            this->ClientSize = System::Drawing::Size(782, 553);
            this->Controls->Add(this->buttonX);
            this->Controls->Add(this->buttonEquation);
            this->Controls->Add(this->buttonEqual);
            this->Controls->Add(this->buttonClosingBracket);
            this->Controls->Add(this->buttonOpeningBracket);
            this->Controls->Add(this->buttonPoint);
            this->Controls->Add(this->buttonNum0);
            this->Controls->Add(this->buttonLog);
            this->Controls->Add(this->buttonNum3);
            this->Controls->Add(this->buttonNum2);
            this->Controls->Add(this->buttonNum1);
            this->Controls->Add(this->buttonAdd);
            this->Controls->Add(this->buttonNum6);
            this->Controls->Add(this->buttonNum5);
            this->Controls->Add(this->buttonNum4);
            this->Controls->Add(this->buttonSub);
            this->Controls->Add(this->buttonNum9);
            this->Controls->Add(this->buttonNum8);
            this->Controls->Add(this->buttonNum7);
            this->Controls->Add(this->buttonClearInput);
            this->Controls->Add(this->buttonMultiply);
            this->Controls->Add(this->buttonDivide);
            this->Controls->Add(this->buttonClear);
            this->Controls->Add(this->inputBox);
            this->Controls->Add(this->MainMenu);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
            this->MainMenuStrip = this->MainMenu;
            this->Name = L"Form1";
            this->Text = L"Calculator";
            this->MainMenu->ResumeLayout(false);
            this->MainMenu->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
private:

    void MarshalString ( String ^ s, string& os ) 
    {
        using namespace Runtime::InteropServices;
        const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
        os = chars;
        Marshal::FreeHGlobal(IntPtr((void*)chars));
    }

    string getResult()
    {
        string output = "";
        try
        {
            Calculator c;
            string input;
            MarshalString(inputBox->Text, input);
            long double calculated = c.calculate(input);
        
            inputBox->Clear();
            isResult = true;

            output = to_string(calculated);
        }
        catch(const char message[])
        {
            isResult = true;
            isError = true;
            inputBox->Clear();
            output = string(message);
        }
        return output;
    }

    void clearAndSetBools()
    {
        this->inputBox->Enabled = true;
        if (isResult || isError)
        {
            inputBox->Clear();
            isResult = false;
            isError = false;
            findedX = false;
            isEquation = false;
        }
    }

    void clearAndSetBoolsForOperations()
    {
        this->inputBox->Enabled = true;
        if (isResult)
        {
            isResult = false;
            isEquation = false;
        }
        if (isError || findedX)
        {
            isError = false;
            findedX = false;
            inputBox->Clear();
            isEquation = false;
        }
        
    }

    private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e)
    {
        clearAndSetBools();
        inputBox->AppendText("1");
    }

    private: System::Void buttonNum7_Click(System::Object^  sender, System::EventArgs^  e)
    {
        clearAndSetBools();
        inputBox->AppendText("7");
    }

    private: System::Void buttonNum8_Click(System::Object^  sender, System::EventArgs^  e)
    {
        clearAndSetBools();
        inputBox->AppendText("8");
    }

    private: System::Void buttonNum9_Click(System::Object^  sender, System::EventArgs^  e)
    {
        clearAndSetBools();
        inputBox->AppendText("9");
    }

    private: System::Void buttonDivide_Click(System::Object^  sender, System::EventArgs^  e)
    {
        clearAndSetBoolsForOperations();
        inputBox->AppendText("/");
    }

    private: System::Void buttonClear_Click(System::Object^  sender, System::EventArgs^  e)
    {
        isError = false;
        isResult = false;
        if (inputBox->Text != "")
        {
            inputBox->Clear();
        }
    }

    private: System::Void buttonMultiply_Click(System::Object^  sender, System::EventArgs^  e)
    {
        clearAndSetBoolsForOperations();
        inputBox->AppendText("*");
    }

    private: System::Void buttonSub_Click(System::Object^  sender, System::EventArgs^  e)
    {
        clearAndSetBoolsForOperations();
        if (inputBox->Text == "" ||
            inputBox->Text->EndsWith("=") ||
            inputBox->Text->EndsWith("("))
        {
            inputBox->AppendText("0");
        }
        inputBox->AppendText("-");
    }

    private: System::Void buttonAdd_Click(System::Object^  sender, System::EventArgs^  e)
    {
        clearAndSetBoolsForOperations();
        inputBox->AppendText("+");
    }

    private: System::Void buttonNum4_Click(System::Object^  sender, System::EventArgs^  e)
    {
        clearAndSetBools();
        inputBox->AppendText("4");

    }

    private: System::Void buttonNum5_Click(System::Object^  sender, System::EventArgs^  e)
    {
        clearAndSetBools();
        inputBox->AppendText("5");
    }

    private: System::Void buttonNum6_Click(System::Object^  sender, System::EventArgs^  e)
    {
        clearAndSetBools();
        inputBox->AppendText("6");
    }

    private: System::Void buttonNum2_Click(System::Object^  sender, System::EventArgs^  e)
    {
        clearAndSetBools();
        inputBox->AppendText("2");
    }

    private: System::Void buttonNum3_Click(System::Object^  sender, System::EventArgs^  e)
    {
        clearAndSetBools();
        inputBox->AppendText("3");
    }

    private: System::Void buttonLog_Click(System::Object^  sender, System::EventArgs^  e)
    {
        clearAndSetBoolsForOperations();
        inputBox->AppendText("log");
    }

    private: System::Void buttonNum0_Click(System::Object^  sender, System::EventArgs^  e)
    {
        clearAndSetBools();
        inputBox->AppendText("0");
    }

    private: System::Void buttonPoint_Click(System::Object^  sender, System::EventArgs^  e)
    {
        clearAndSetBools();
        inputBox->AppendText(".");
    }

    private: System::Void buttonOpeningBracket_Click(System::Object^  sender, System::EventArgs^  e)
    {
        clearAndSetBools();
        inputBox->AppendText("(");
    }

    private: System::Void buttonClosingBracket_Click(System::Object^  sender, System::EventArgs^  e)
    {
        clearAndSetBools();
        inputBox->AppendText(")");
    }

    private: System::Void buttonClearInput_Click(System::Object^  sender, System::EventArgs^  e)
    {
        isError = false;
        isResult = false;
        if (inputBox->Text != "")
        {
            inputBox->Text = inputBox->Text->Substring(0, inputBox->Text->Length - 1);
        }
    }

    private: System::Void buttonX_Click(System::Object^  sender, System::EventArgs^  e)
    {
        clearAndSetBools();
        inputBox->AppendText("x");
        isEquation = true;
    }

    private: System::Void buttonEquation_Click(System::Object^  sender, System::EventArgs^  e) 
    {
        isEquation = false;
        string output = getResult();
        inputBox->AppendText("x=" + gcnew String(output.c_str()));
        buttonEquation->Enabled = false;
        buttonEqual->Enabled = true;
        this->inputBox->Enabled = false;
        findedX = true;
    }

    private: System::Void button21_Click(System::Object^  sender, System::EventArgs^  e) 
    {
        if (isResult)
        {
            inputBox->Clear();
        }

        if (isEquation)
        {
            inputBox->AppendText("=");
            buttonEquation->Enabled = true;
            buttonEqual->Enabled = false;
        }
        else
        {
            this->inputBox->Enabled = false;
            string output = getResult();
            inputBox->AppendText(gcnew String(output.c_str()));
        }
    }
    

    private: System::Void inputBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
    {
        // if user press x key on keyboard than this is equation
        if (e->KeyChar == 'x')
        {
            isEquation = true;
        }

        // add 0 before minus if expression starts with minus or brackets starts with
        if (e->KeyChar == '-')
        {
            if (inputBox->Text == "" ||
                inputBox->Text->EndsWith("=") ||
                inputBox->Text->EndsWith("("))
            {
                inputBox->AppendText("0");
            }
        }
        
        // unable to hit any other key than this following
        if (!Char::IsDigit(e->KeyChar) && e->KeyChar != '*' &&
            e->KeyChar != '/' && e->KeyChar != '+' && e->KeyChar != '-' &&
            e->KeyChar != 'x' && e->KeyChar != '.' && e->KeyChar != '(' &&
            e->KeyChar != ')' && e->KeyChar != 8 && e->KeyChar != '=')
        {
            e->Handled = true;
        }

        // if user hit "=" key on keyboard
        if (e->KeyChar == '=')
        {
            if (!isEquation)
            {
                e->Handled = true;
            }
            else
            {
                isEquation = false;
                buttonEqual->Enabled = false;
                buttonEquation->Enabled = true;
            }
        }
    }
       

private: System::Void guideToolStripMenuItem_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
             MessageBox::Show(
                 "Press \"=\" to calculate expression\nPress \" X=\" to calculate equation\nValid format for expressions are:\n\t2*x+1=2\n\tlog5.5+1\n\t5*(2+2)\n\t(4+4)*x+10=(2+3)*2",
                 "User Guide",
                 MessageBoxButtons::OK, 
                 MessageBoxIcon::Exclamation
                 );
         }
};
}

