#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void main() {
	setlocale(LC_ALL, "ru");
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	DuplicateFinder::MyForm form;
	Application::Run(%form);
}