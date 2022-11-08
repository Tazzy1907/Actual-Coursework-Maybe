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
	
	// Contents of the startUpGroup GroupBox
	private: System::Windows::Forms::GroupBox^ startUpGroup;
	private: System::Windows::Forms::Button^ quitButton;
	private: System::Windows::Forms::Button^ quickRenderButton;
	private: System::Windows::Forms::Button^ logInButton;
	private: System::Windows::Forms::Label^ welcomeLabel;
	private: System::Windows::Forms::Label^ authorLabel;

	// Contents of the loginGroup GroupBox
	private: System::Windows::Forms::GroupBox^ loginGroup;
	private: System::Windows::Forms::Label^ loginLabel;

	private: System::Windows::Forms::TextBox^ usernameBox;
	private: System::Windows::Forms::TextBox^ passwordBox;
	private: System::Windows::Forms::Button^ loginButton1;
	private: System::Windows::Forms::Button^ quitButton1;
	private: System::Windows::Forms::Button^ loginBackButton;
	private: System::Windows::Forms::ToolTip^ genericToolTip;

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
			this->quitButton = (gcnew System::Windows::Forms::Button());
			this->quickRenderButton = (gcnew System::Windows::Forms::Button());
			this->startUpGroup = (gcnew System::Windows::Forms::GroupBox());
			this->authorLabel = (gcnew System::Windows::Forms::Label());
			this->welcomeLabel = (gcnew System::Windows::Forms::Label());
			this->logInButton = (gcnew System::Windows::Forms::Button());
			this->loginGroup = (gcnew System::Windows::Forms::GroupBox());
			this->loginBackButton = (gcnew System::Windows::Forms::Button());
			this->loginButton1 = (gcnew System::Windows::Forms::Button());
			this->quitButton1 = (gcnew System::Windows::Forms::Button());
			this->passwordBox = (gcnew System::Windows::Forms::TextBox());
			this->usernameBox = (gcnew System::Windows::Forms::TextBox());
			this->loginLabel = (gcnew System::Windows::Forms::Label());
			this->genericToolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->startUpGroup->SuspendLayout();
			this->loginGroup->SuspendLayout();
			this->SuspendLayout();
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
			this->genericToolTip->SetToolTip(this->quitButton, L"Quit the application.");
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
			this->genericToolTip->SetToolTip(this->quickRenderButton, L"Upload an object to render it or access saved public objects.");
			this->quickRenderButton->UseVisualStyleBackColor = true;
			this->quickRenderButton->Click += gcnew System::EventHandler(this, &MyForm::quickRenderButton_Click);
			// 
			// startUpGroup
			// 
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
			// logInButton
			// 
			this->logInButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->logInButton->Location = System::Drawing::Point(25, 150);
			this->logInButton->Name = L"logInButton";
			this->logInButton->Size = System::Drawing::Size(300, 200);
			this->logInButton->TabIndex = 2;
			this->logInButton->Text = L"Login";
			this->genericToolTip->SetToolTip(this->logInButton, L"Log in and access your saved objects.");
			this->logInButton->UseVisualStyleBackColor = true;
			this->logInButton->Click += gcnew System::EventHandler(this, &MyForm::loginButton_Click);
			// 
			// loginGroup
			// 
			this->loginGroup->Controls->Add(this->loginBackButton);
			this->loginGroup->Controls->Add(this->loginButton1);
			this->loginGroup->Controls->Add(this->quitButton1);
			this->loginGroup->Controls->Add(this->passwordBox);
			this->loginGroup->Controls->Add(this->usernameBox);
			this->loginGroup->Controls->Add(this->loginLabel);
			this->loginGroup->Location = System::Drawing::Point(-7, -31);
			this->loginGroup->Name = L"loginGroup";
			this->loginGroup->Size = System::Drawing::Size(1000, 500);
			this->loginGroup->TabIndex = 7;
			this->loginGroup->TabStop = false;
			this->loginGroup->Text = L"groupBox1";
			this->loginGroup->Visible = false;
			// 
			// loginBackButton
			// 
			this->loginBackButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loginBackButton->Location = System::Drawing::Point(25, 50);
			this->loginBackButton->Name = L"loginBackButton";
			this->loginBackButton->Size = System::Drawing::Size(150, 50);
			this->loginBackButton->TabIndex = 7;
			this->loginBackButton->Text = L"Back";
			this->loginBackButton->UseVisualStyleBackColor = true;
			this->loginBackButton->Click += gcnew System::EventHandler(this, &MyForm::loginBackButton_Click);
			// 
			// loginButton1
			// 
			this->loginButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loginButton1->Location = System::Drawing::Point(350, 250);
			this->loginButton1->Name = L"loginButton1";
			this->loginButton1->Size = System::Drawing::Size(150, 50);
			this->loginButton1->TabIndex = 6;
			this->loginButton1->Text = L"Login";
			this->loginButton1->UseVisualStyleBackColor = true;
			// 
			// quitButton1
			// 
			this->quitButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->quitButton1->Location = System::Drawing::Point(500, 250);
			this->quitButton1->Name = L"quitButton1";
			this->quitButton1->Size = System::Drawing::Size(150, 50);
			this->quitButton1->TabIndex = 5;
			this->quitButton1->Text = L"Quit";
			this->quitButton1->UseVisualStyleBackColor = true;
			this->quitButton1->Click += gcnew System::EventHandler(this, &MyForm::quitButton_Click);
			// 
			// passwordBox
			// 
			this->passwordBox->Location = System::Drawing::Point(425, 175);
			this->passwordBox->MaxLength = 20;
			this->passwordBox->Name = L"passwordBox";
			this->passwordBox->Size = System::Drawing::Size(150, 20);
			this->passwordBox->TabIndex = 2;
			this->passwordBox->Text = L"Password";
			this->passwordBox->Enter += gcnew System::EventHandler(this, &MyForm::passwordBox_Enter);
			this->passwordBox->Leave += gcnew System::EventHandler(this, &MyForm::passwordBox_Leave);
			// 
			// usernameBox
			// 
			this->usernameBox->Location = System::Drawing::Point(425, 150);
			this->usernameBox->MaxLength = 20;
			this->usernameBox->Name = L"usernameBox";
			this->usernameBox->Size = System::Drawing::Size(150, 20);
			this->usernameBox->TabIndex = 1;
			this->usernameBox->Text = L"Username";
			this->usernameBox->Enter += gcnew System::EventHandler(this, &MyForm::usernameBox_Enter);
			this->usernameBox->Leave += gcnew System::EventHandler(this, &MyForm::usernameBox_Leave);
			// 
			// loginLabel
			// 
			this->loginLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Pixel,
				static_cast<System::Byte>(0)));
			this->loginLabel->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->loginLabel->Location = System::Drawing::Point(150, 50);
			this->loginLabel->Name = L"loginLabel";
			this->loginLabel->Size = System::Drawing::Size(700, 70);
			this->loginLabel->TabIndex = 0;
			this->loginLabel->Text = L"Login Page";
			this->loginLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
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
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1000, 500);
			this->MinimumSize = System::Drawing::Size(1000, 500);
			this->Name = L"MyForm";
			this->Text = L"My A-Level Coursework";
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

private: System::Void usernameBox_Enter(System::Object^ sender, System::EventArgs^ e) {
	usernameBox->Text = "";
}
private: System::Void usernameBox_Leave(System::Object^ sender, System::EventArgs^ e) {
	if (usernameBox->Text == "") {
		usernameBox->Text = "Username";
	}
}
private: System::Void passwordBox_Enter(System::Object^ sender, System::EventArgs^ e) {
	passwordBox->PasswordChar = '*';
	passwordBox->Text = "";
}
private: System::Void passwordBox_Leave(System::Object^ sender, System::EventArgs^ e) {
	if (passwordBox->Text == "") {
		passwordBox->PasswordChar = false;
		passwordBox->Text = "Password";
	}
}
private: System::Void loginBackButton_Click(System::Object^ sender, System::EventArgs^ e) {
	loginGroup->Visible = false;
	startUpGroup->Visible = true;
}
};
}
