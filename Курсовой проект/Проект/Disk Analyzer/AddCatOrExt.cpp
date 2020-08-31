#include "AddCatOrExt.h"
#include "CatsChoose.h"
#include <regex>
#include <string>
#include <msclr/marshal_cppstd.h>

using std::regex, std::regex_match, std::string;

regex regular;

using namespace DiskAnalyzer;
using namespace msclr::interop;
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main1() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	DiskAnalyzer::AddCatOrExt form;
	Application::Run(% form);
}

AddCatOrExt::AddCatOrExt() {
	InitializeComponent();
	//
	//TODO: добавьте код конструктора
	//
}

AddCatOrExt::~AddCatOrExt() {
	if (components)
	{
		delete components;
	}
}

void AddCatOrExt::InitializeComponent(void)
{
	this->abortButton = (gcnew System::Windows::Forms::Button());
	this->okButton = (gcnew System::Windows::Forms::Button());
	this->textBox = (gcnew System::Windows::Forms::TextBox());
	this->SuspendLayout();
	// 
	// abortButton
	// 
	this->abortButton->Location = System::Drawing::Point(367, 79);
	this->abortButton->Name = L"abortButton";
	this->abortButton->Size = System::Drawing::Size(97, 43);
	this->abortButton->TabIndex = 2;
	this->abortButton->Text = L"Отмена";
	this->abortButton->UseVisualStyleBackColor = true;
	this->abortButton->Click += gcnew System::EventHandler(this, &AddCatOrExt::AbortButton_Click);
	// 
	// okButton
	// 
	this->okButton->Location = System::Drawing::Point(305, 79);
	this->okButton->Name = L"okButton";
	this->okButton->Size = System::Drawing::Size(46, 43);
	this->okButton->TabIndex = 3;
	this->okButton->Text = L"ОК";
	this->okButton->UseVisualStyleBackColor = true;
	this->okButton->Click += gcnew System::EventHandler(this, &AddCatOrExt::OkButton_Click);
	// 
	// textBox
	// 
	this->textBox->Location = System::Drawing::Point(95, 35);
	this->textBox->Name = L"textBox";
	this->textBox->Size = System::Drawing::Size(289, 26);
	this->textBox->TabIndex = 4;
	this->textBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AddCatOrExt::textBox_KeyPress);
	// 
	// AddCatOrExt
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(476, 144);
	this->Controls->Add(this->textBox);
	this->Controls->Add(this->okButton);
	this->Controls->Add(this->abortButton);
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
	this->Name = L"AddCatOrExt";
	this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
	this->Text = L"AddCatOrExt";
	this->ResumeLayout(false);
	this->PerformLayout();

}

void AddCatOrExt::AddCategory() {
	this->Text = "Добавление категории";
	regular = "([\\w\\s]*)";
	this->ShowDialog();
}

void AddCatOrExt::AddExtension() {
	this->Text = "Добавление расширения";
	regular = "([\\.]{1})([a-z]+)";
	this->ShowDialog();
}

void AddCatOrExt::ExportCatOrExt() {
	if (textBox->Text != "" && regex_match(marshal_as<string>(textBox->Text), regular)) {
		CatsChoose::catOrExtToAdd = textBox->Text;
		this->Close();
	}
	else {
		MessageBox::Show("Неверный формат!", "Ошибка", MessageBoxButtons::OK);
	}
}

System::Void AddCatOrExt::OkButton_Click(System::Object^ sender, System::EventArgs^ e) {
	ExportCatOrExt();
}

System::Void AddCatOrExt::textBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (e->KeyChar == (char)13)
		ExportCatOrExt();
}

System::Void AddCatOrExt::AbortButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}