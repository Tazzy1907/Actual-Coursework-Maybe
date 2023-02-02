#pragma once

namespace testProject {
	using namespace System;
	using namespace System::Windows::Forms;

	public ref class LoginForm : public Form {
	public:
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Button^ button1;
	public:
		LoginForm() {
			InitializeComponent();
		}
		void InitializeComponent() {
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(202, 99);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// MyForm
			// 
			this->ClientSize = System::Drawing::Size(400, 300);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"My Form";
			this->ResumeLayout(false);
			this->PerformLayout();

			this->button1->Location = System::Drawing::Point(30, 30);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->Text = L"Go to Second Form";
			this->button1->UseVisualStyleBackColor = true;


		}

	};
}
