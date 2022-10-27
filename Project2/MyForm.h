#pragma once
#include "LoginForm.h";
#include "RenderForm.h";

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

			logInToolTip->SetToolTip(logInButton, "Log in and access your saved objects.");
			quickRenderToolTip->SetToolTip(quickRenderButton, "Upload an object to render it or access saved public objects.");
			quitToolTip->SetToolTip(quitButton, "Quit the application.");
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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ logInButton;
	private: System::Windows::Forms::Button^ quickRenderButton;
	private: System::Windows::Forms::Button^ quitButton;

	private: System::Windows::Forms::ToolTip^ logInToolTip;
	private: System::Windows::Forms::ToolTip^ quickRenderToolTip;
	private: System::Windows::Forms::ToolTip^ quitToolTip;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->logInButton = (gcnew System::Windows::Forms::Button());
			this->quickRenderButton = (gcnew System::Windows::Forms::Button());
			this->quitButton = (gcnew System::Windows::Forms::Button());
			this->logInToolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->quickRenderToolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->quitToolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Pixel,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label1->Location = System::Drawing::Point(150, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(700, 70);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Welcome to this Graphics Engine. Please select one of the following options:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->UseCompatibleTextRendering = true;
			this->label1->UseMnemonic = false;
			// 
			// logInButton
			// 
			this->logInButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->logInButton->Location = System::Drawing::Point(25, 175);
			this->logInButton->Name = L"logInButton";
			this->logInButton->Size = System::Drawing::Size(300, 200);
			this->logInButton->TabIndex = 1;
			this->logInButton->Text = L"Log In";
			this->logInButton->UseVisualStyleBackColor = true;
			this->logInButton->Click += gcnew System::EventHandler(this, &MyForm::loginButton_Click);
			// 
			// quickRenderButton
			// 
			this->quickRenderButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->quickRenderButton->Location = System::Drawing::Point(350, 175);
			this->quickRenderButton->Name = L"quickRenderButton";
			this->quickRenderButton->Size = System::Drawing::Size(300, 200);
			this->quickRenderButton->TabIndex = 2;
			this->quickRenderButton->Text = L"Quick Render";
			this->quickRenderButton->UseVisualStyleBackColor = true;
			this->quickRenderButton->Click += gcnew System::EventHandler(this, &MyForm::quickRenderButton_Click);
			// 
			// quitButton
			// 
			this->quitButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->quitButton->Location = System::Drawing::Point(675, 175);
			this->quitButton->Name = L"quitButton";
			this->quitButton->Size = System::Drawing::Size(300, 200);
			this->quitButton->TabIndex = 3;
			this->quitButton->Text = L"Quit";
			this->quitButton->UseVisualStyleBackColor = true;
			this->quitButton->Click += gcnew System::EventHandler(this, &MyForm::quitButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::AliceBlue;
			this->ClientSize = System::Drawing::Size(984, 461);
			this->Controls->Add(this->quitButton);
			this->Controls->Add(this->quickRenderButton);
			this->Controls->Add(this->logInButton);
			this->Controls->Add(this->label1);
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Welcome Menu";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void loginButton_Click(System::Object^ sender, System::EventArgs^ e) {
		LoginForm^ loginForm = gcnew LoginForm();
		loginForm->ShowDialog();
		
	}
	private: System::Void quickRenderButton_Click(System::Object^ sender, System::EventArgs^ e) {

		RenderForm^ renderForm = gcnew RenderForm();
		renderForm->ShowDialog();
	}

	private: System::Void quitButton_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
	}
};
}
