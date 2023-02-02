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
	private: System::Windows::Forms::Label^ loginMessage;
	private: System::Windows::Forms::Button^ signUp;
	private: System::Windows::Forms::GroupBox^ signUpGroup;
	private: System::Windows::Forms::Label^ signUpLabel;
	private: System::Windows::Forms::Button^ signUpBackButton;
	private: System::Windows::Forms::Button^ signUpConfirmButton;


	private: System::Windows::Forms::TextBox^ signUpConfirmPasswordBox;

	private: System::Windows::Forms::TextBox^ signUpPasswordBox;

	private: System::Windows::Forms::TextBox^ signUpUsernameBox;

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
			this->logInButton = (gcnew System::Windows::Forms::Button());
			this->welcomeLabel = (gcnew System::Windows::Forms::Label());
			this->loginGroup = (gcnew System::Windows::Forms::GroupBox());
			this->signUp = (gcnew System::Windows::Forms::Button());
			this->loginMessage = (gcnew System::Windows::Forms::Label());
			this->loginBackButton = (gcnew System::Windows::Forms::Button());
			this->loginButton1 = (gcnew System::Windows::Forms::Button());
			this->quitButton1 = (gcnew System::Windows::Forms::Button());
			this->passwordBox = (gcnew System::Windows::Forms::TextBox());
			this->usernameBox = (gcnew System::Windows::Forms::TextBox());
			this->loginLabel = (gcnew System::Windows::Forms::Label());
			this->genericToolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->signUpConfirmButton = (gcnew System::Windows::Forms::Button());
			this->signUpGroup = (gcnew System::Windows::Forms::GroupBox());
			this->signUpBackButton = (gcnew System::Windows::Forms::Button());
			this->signUpConfirmPasswordBox = (gcnew System::Windows::Forms::TextBox());
			this->signUpPasswordBox = (gcnew System::Windows::Forms::TextBox());
			this->signUpUsernameBox = (gcnew System::Windows::Forms::TextBox());
			this->signUpLabel = (gcnew System::Windows::Forms::Label());
			this->startUpGroup->SuspendLayout();
			this->loginGroup->SuspendLayout();
			this->signUpGroup->SuspendLayout();
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
			this->startUpGroup->Controls->Add(this->quitButton);
			this->startUpGroup->Controls->Add(this->quickRenderButton);
			this->startUpGroup->Controls->Add(this->logInButton);
			this->startUpGroup->Controls->Add(this->welcomeLabel);
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
			// loginGroup
			// 
			this->loginGroup->Controls->Add(this->signUp);
			this->loginGroup->Controls->Add(this->loginMessage);
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
			// signUp
			// 
			this->signUp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->signUp->Location = System::Drawing::Point(425, 306);
			this->signUp->Name = L"signUp";
			this->signUp->Size = System::Drawing::Size(150, 50);
			this->signUp->TabIndex = 9;
			this->signUp->Text = L"Sign Up";
			this->genericToolTip->SetToolTip(this->signUp, L"Sign up to the application using your email and password");
			this->signUp->UseVisualStyleBackColor = true;
			this->signUp->Click += gcnew System::EventHandler(this, &MyForm::signUp_Click);
			// 
			// loginMessage
			// 
			this->loginMessage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Pixel,
				static_cast<System::Byte>(0)));
			this->loginMessage->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->loginMessage->Location = System::Drawing::Point(300, 200);
			this->loginMessage->Name = L"loginMessage";
			this->loginMessage->Size = System::Drawing::Size(400, 30);
			this->loginMessage->TabIndex = 8;
			this->loginMessage->Text = L"Enter your details above!";
			this->loginMessage->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
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
			this->loginButton1->Click += gcnew System::EventHandler(this, &MyForm::loginButton1_Click);
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
			this->genericToolTip->SetToolTip(this->quitButton1, L"Quit the application.");
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
			// signUpConfirmButton
			// 
			this->signUpConfirmButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->signUpConfirmButton->Location = System::Drawing::Point(425, 225);
			this->signUpConfirmButton->Name = L"signUpConfirmButton";
			this->signUpConfirmButton->Size = System::Drawing::Size(150, 50);
			this->signUpConfirmButton->TabIndex = 10;
			this->signUpConfirmButton->Text = L"Sign Up";
			this->genericToolTip->SetToolTip(this->signUpConfirmButton, L"Sign up to the application using your email and password");
			this->signUpConfirmButton->UseVisualStyleBackColor = true;
			// 
			// signUpGroup
			// 
			this->signUpGroup->Controls->Add(this->signUpBackButton);
			this->signUpGroup->Controls->Add(this->signUpConfirmButton);
			this->signUpGroup->Controls->Add(this->signUpConfirmPasswordBox);
			this->signUpGroup->Controls->Add(this->signUpPasswordBox);
			this->signUpGroup->Controls->Add(this->signUpUsernameBox);
			this->signUpGroup->Controls->Add(this->signUpLabel);
			this->signUpGroup->Location = System::Drawing::Point(-7, -31);
			this->signUpGroup->Name = L"signUpGroup";
			this->signUpGroup->Size = System::Drawing::Size(1000, 500);
			this->signUpGroup->TabIndex = 10;
			this->signUpGroup->TabStop = false;
			this->signUpGroup->Text = L"groupBox1";
			this->signUpGroup->Visible = false;
			// 
			// signUpBackButton
			// 
			this->signUpBackButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->signUpBackButton->Location = System::Drawing::Point(25, 50);
			this->signUpBackButton->Name = L"signUpBackButton";
			this->signUpBackButton->Size = System::Drawing::Size(150, 50);
			this->signUpBackButton->TabIndex = 11;
			this->signUpBackButton->Text = L"Back";
			this->signUpBackButton->UseVisualStyleBackColor = true;
			this->signUpBackButton->Click += gcnew System::EventHandler(this, &MyForm::signUpBackButton_Click);
			// 
			// signUpConfirmPasswordBox
			// 
			this->signUpConfirmPasswordBox->Location = System::Drawing::Point(425, 175);
			this->signUpConfirmPasswordBox->MaxLength = 20;
			this->signUpConfirmPasswordBox->Name = L"signUpConfirmPasswordBox";
			this->signUpConfirmPasswordBox->Size = System::Drawing::Size(150, 20);
			this->signUpConfirmPasswordBox->TabIndex = 4;
			this->signUpConfirmPasswordBox->Text = L"Confirm Password";
			this->signUpConfirmPasswordBox->Enter += gcnew System::EventHandler(this, &MyForm::confirmPasswordBox_Enter);
			this->signUpConfirmPasswordBox->Leave += gcnew System::EventHandler(this, &MyForm::confirmPasswordBox_Leave);
			// 
			// signUpPasswordBox
			// 
			this->signUpPasswordBox->Location = System::Drawing::Point(425, 150);
			this->signUpPasswordBox->MaxLength = 20;
			this->signUpPasswordBox->Name = L"signUpPasswordBox";
			this->signUpPasswordBox->Size = System::Drawing::Size(150, 20);
			this->signUpPasswordBox->TabIndex = 3;
			this->signUpPasswordBox->Text = L"Password";
			this->signUpPasswordBox->Enter += gcnew System::EventHandler(this, &MyForm::signUpPasswordBox_Enter);
			this->signUpPasswordBox->Leave += gcnew System::EventHandler(this, &MyForm::signUpPasswordBox_Leave);
			// 
			// signUpUsernameBox
			// 
			this->signUpUsernameBox->Location = System::Drawing::Point(425, 125);
			this->signUpUsernameBox->MaxLength = 20;
			this->signUpUsernameBox->Name = L"signUpUsernameBox";
			this->signUpUsernameBox->Size = System::Drawing::Size(150, 20);
			this->signUpUsernameBox->TabIndex = 2;
			this->signUpUsernameBox->Text = L"Username";
			this->signUpUsernameBox->Enter += gcnew System::EventHandler(this, &MyForm::signUpUsernameBox_Enter);
			this->signUpUsernameBox->Leave += gcnew System::EventHandler(this, &MyForm::signUpUsernameBox_Leave);
			// 
			// signUpLabel
			// 
			this->signUpLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Pixel,
				static_cast<System::Byte>(0)));
			this->signUpLabel->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->signUpLabel->Location = System::Drawing::Point(150, 50);
			this->signUpLabel->Name = L"signUpLabel";
			this->signUpLabel->Size = System::Drawing::Size(700, 70);
			this->signUpLabel->TabIndex = 0;
			this->signUpLabel->Text = L"Sign Up Here!";
			this->signUpLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::AliceBlue;
			this->ClientSize = System::Drawing::Size(984, 461);
			this->Controls->Add(this->signUpGroup);
			this->Controls->Add(this->loginGroup);
			this->Controls->Add(this->startUpGroup);
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1000, 500);
			this->MinimumSize = System::Drawing::Size(1000, 500);
			this->Name = L"MyForm";
			this->Text = L"My A-Level Coursework";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->startUpGroup->ResumeLayout(false);
			this->loginGroup->ResumeLayout(false);
			this->loginGroup->PerformLayout();
			this->signUpGroup->ResumeLayout(false);
			this->signUpGroup->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void loginButton_Click(System::Object^ sender, System::EventArgs^ e) {
		startUpGroup->Visible = false;
		loginGroup->Visible = true;
		// Switches tabs to the login section.
	}
	private: System::Void quickRenderButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Current placeholder for what needs adding.
		pendingUpdate();
	}

	private: System::Void quitButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Simple quit button.
		Close();
	}

// The following is literally just for "aesthetics". Makes the box clear when entered, makes it have placeholder text when not focused on and empty :)
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
private: System::Void confirmPasswordBox_Enter(System::Object^ sender, System::EventArgs^ e) {
	signUpConfirmPasswordBox->PasswordChar = '*';
	signUpConfirmPasswordBox->Text = "";
}
private: System::Void confirmPasswordBox_Leave(System::Object^ sender, System::EventArgs^ e) {
	if (signUpConfirmPasswordBox->Text == "") {
		signUpConfirmPasswordBox->PasswordChar = false;
		signUpConfirmPasswordBox->Text = "Confirm Password";
	}
}
private: System::Void signUpPasswordBox_Enter(System::Object^ sender, System::EventArgs^ e) {
	signUpPasswordBox->PasswordChar = '*';
	signUpPasswordBox->Text = "";
}
private: System::Void signUpPasswordBox_Leave(System::Object^ sender, System::EventArgs^ e) {
	if (signUpPasswordBox->Text == "") {
		signUpPasswordBox->PasswordChar = false;
		signUpPasswordBox->Text = "Password";
	}
}
private: System::Void signUpUsernameBox_Enter(System::Object^ sender, System::EventArgs^ e) {
	signUpUsernameBox->Text = "";
}
private: System::Void signUpUsernameBox_Leave(System::Object^ sender, System::EventArgs^ e) {
	if (signUpUsernameBox->Text == "") {
		signUpUsernameBox->Text = "Username";
	}
}
// End of the useless-ish code that allows for placeholder code in text boxes.

private: System::Void loginBackButton_Click(System::Object^ sender, System::EventArgs^ e) {
	// This is the back button on the login page, makes the user go back to the start up menu.
	loginGroup->Visible = false;
	startUpGroup->Visible = true;
}
private: System::Void loginButton1_Click(System::Object^ sender, System::EventArgs^ e) {
	// Login button on the login page.
	pendingUpdate();
	// loginMessage->Text = "Your username and password are incorrect";
}

private: System::Void signUp_Click(System::Object^ sender, System::EventArgs^ e) {
	// Button on the login page, loads the sign up / register page.
	loginGroup->Visible = false;
	signUpGroup->Visible = true;
}
private: System::Void signUpBackButton_Click(System::Object^ sender, System::EventArgs^ e) {
	// Back button on the sign up / register page, loads the login page. 
	loginGroup->Visible = true;
	signUpGroup->Visible = false;
}
private: void pendingUpdate() {  // Will be re-used as a placeholder for all things that still need adding to the system.
	MessageBox::Show("This has not yet been added to the application.", "Pending Update", MessageBoxButtons::OK);
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}


