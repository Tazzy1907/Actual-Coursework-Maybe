#pragma once

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			//logInToolTip->SetToolTip(logInButton, "Log in and access your saved objects.");
			//quickRenderToolTip->SetToolTip(quickRenderButton, "Upload an object to render it or access saved public objects.");
			//quitToolTip->SetToolTip(quitButton, "Quit the application.");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::ToolTip^ logInToolTip;
	private: System::Windows::Forms::ToolTip^ quickRenderToolTip;
	private: System::Windows::Forms::ToolTip^ quitToolTip;
	
	// Contents of the startUpGroup GroupBox
	private: System::Windows::Forms::GroupBox^ startUpGroup;
	private: System::Windows::Forms::Button^ quitButton;
	private: System::Windows::Forms::Button^ quickRenderButton;
	private: System::Windows::Forms::Button^ logInButton;
	private: System::Windows::Forms::Label^ welcomeLabel;
	private: System::Windows::Forms::Label^ authorLabel;

	// Contents of the loginGroup GroupBox
	private: System::Windows::Forms::GroupBox^ loginGroup;
	private: System::Windows::Forms::Label^ label1;



	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->logInToolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->quickRenderToolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->quitToolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->startUpGroup = (gcnew System::Windows::Forms::GroupBox());
			this->loginGroup = (gcnew System::Windows::Forms::GroupBox());
			this->authorLabel = (gcnew System::Windows::Forms::Label());
			this->welcomeLabel = (gcnew System::Windows::Forms::Label());
			this->quitButton = (gcnew System::Windows::Forms::Button());
			this->quickRenderButton = (gcnew System::Windows::Forms::Button());
			this->logInButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->startUpGroup->SuspendLayout();
			this->loginGroup->SuspendLayout();
			this->SuspendLayout();
			// 
			// startUpGroup
			// 
			//this->startUpGroup->Controls->Add(this->loginGroup);
			this->startUpGroup->Controls->Add(this->authorLabel);
			this->startUpGroup->Controls->Add(this->welcomeLabel);
			this->startUpGroup->Controls->Add(this->quitButton);
			this->startUpGroup->Controls->Add(this->quickRenderButton);
			this->startUpGroup->Controls->Add(this->logInButton);
			this->startUpGroup->Location = System::Drawing::Point(-7, -31);
			this->startUpGroup->Name = L"startUpGroup";
			this->startUpGroup->Size = System::Drawing::Size(1000, 500);
			this->startUpGroup->TabIndex = 4;
			this->startUpGroup->TabStop = false;
			this->startUpGroup->Text = L"groupBox1";
			this->startUpGroup->Visible = false;
			// 
			// loginGroup
			// 
			this->loginGroup->Controls->Add(this->label1);
			this->loginGroup->Location = System::Drawing::Point(-7, -31);
			this->loginGroup->Name = L"loginGroup";
			this->loginGroup->Size = System::Drawing::Size(1000, 500);
			this->loginGroup->TabIndex = 7;
			this->loginGroup->TabStop = false;
			this->loginGroup->Text = L"groupBox1";
			this->loginGroup->Visible = true;
			// 
			// authorLabel
			// 
			this->authorLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->authorLabel->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->authorLabel->Location = System::Drawing::Point(150, 385);
			this->authorLabel->Name = L"authorLabel";
			this->authorLabel->Size = System::Drawing::Size(700, 70);
			this->authorLabel->TabIndex = 6;
			this->authorLabel->Text = L"By Tanaz Siriwardena";
			this->authorLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->authorLabel->UseCompatibleTextRendering = true;
			this->authorLabel->UseMnemonic = false;
			// 
			// welcomeLabel
			// 
			this->welcomeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Pixel,
				static_cast<System::Byte>(0)));
			this->welcomeLabel->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->welcomeLabel->Location = System::Drawing::Point(150, 50);
			this->welcomeLabel->Name = L"welcomeLabel";
			this->welcomeLabel->Size = System::Drawing::Size(700, 70);
			this->welcomeLabel->TabIndex = 5;
			this->welcomeLabel->Text = L"Welcome to this Graphics Engine. Please select one of the following options:";
			this->welcomeLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->welcomeLabel->UseCompatibleTextRendering = true;
			this->welcomeLabel->UseMnemonic = false;
			// 
			// quitButton
			// 
			this->quitButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->quitButton->Location = System::Drawing::Point(675, 150);
			this->quitButton->Name = L"quitButton";
			this->quitButton->Size = System::Drawing::Size(300, 200);
			this->quitButton->TabIndex = 4;
			this->quitButton->Text = L"Quit";
			this->quitButton->UseVisualStyleBackColor = true;
			this->quitButton->Click += gcnew System::EventHandler(this, &MyForm::quitButton_Click);
			// 
			// quickRenderButton
			// 
			this->quickRenderButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->quickRenderButton->Location = System::Drawing::Point(350, 150);
			this->quickRenderButton->Name = L"quickRenderButton";
			this->quickRenderButton->Size = System::Drawing::Size(300, 200);
			this->quickRenderButton->TabIndex = 3;
			this->quickRenderButton->Text = L"Quick Render";
			this->quickRenderButton->UseVisualStyleBackColor = true;
			this->quickRenderButton->Click += gcnew System::EventHandler(this, &MyForm::quickRenderButton_Click);
			// 
			// logInButton
			// 
			this->logInButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->logInButton->Location = System::Drawing::Point(25, 150);
			this->logInButton->Name = L"logInButton";
			this->logInButton->Size = System::Drawing::Size(300, 200);
			this->logInButton->TabIndex = 2;
			this->logInButton->Text = L"Login";
			this->logInButton->UseVisualStyleBackColor = true;
			this->logInButton->Click += gcnew System::EventHandler(this, &MyForm::loginButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(304, 165);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(328, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"THIS IS EXEMPLAR TEXT THAT SHHOULD HOPEFULLY SHOW";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::AliceBlue;
			this->ClientSize = System::Drawing::Size(984, 461);
			this->Controls->Add(this->startUpGroup);
			this->Controls->Add(this->loginGroup);
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Welcome Menu";
			this->startUpGroup->ResumeLayout(false);
			this->loginGroup->ResumeLayout(false);
			this->loginGroup->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void loginButton_Click(System::Object^ sender, System::EventArgs^ e) {
		startUpGroup->Visible = false;
		loginGroup->Visible = true;
	}
	private: System::Void quickRenderButton_Click(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void quitButton_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
