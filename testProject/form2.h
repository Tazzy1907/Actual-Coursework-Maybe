#pragma once

namespace testProject {
	using namespace System;
	using namespace System::Windows::Forms;

	public ref class LoggedInForm : public Form {
	public:
		LoggedInForm() {
			InitializeComponent();
		}

	private:

		System::Windows::Forms::Label^ label1;


		void InitializeComponent() {
			this->Text = "Newer Form!";
			this->ClientSize = System::Drawing::Size(400, 300);
			label1 = gcnew System::Windows::Forms::Label();
			label1->Location = System::Drawing::Point(10, 10);
			label1->Size = System::Drawing::Size(100, 20);
			label1->Text = "Hello, World!";
			this->Controls->Add(label1);

		};
	};
}
