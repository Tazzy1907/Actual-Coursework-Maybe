#include "form1.h";
#include "form2.h";

using namespace System;
using namespace System::Windows::Forms;


ref class MyApp {
public: 
	testProject::LoginForm^ form1 = gcnew testProject::LoginForm();
	testProject::LoggedInForm^ form2 = gcnew testProject::LoggedInForm();

	MyApp() {
		form1->button1->Click += gcnew EventHandler(this, &MyApp::button_Click);
	}

	void button_Click(Object^ sender, EventArgs^ e) {
		form1->Hide();
		form2->Show();
	}
};

[STAThread]

int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	MyApp^ app;

	app = gcnew MyApp();

	Application::Run(app->form1);

	return 0;
};


