#include "CatsChoose.h"
#include "Structs.h"
#include "AddCatOrExt.h"
#include <fstream>
#include <regex>
#include <string>
#include <msclr/marshal_cppstd.h>

using std::ifstream, std::ofstream, std::regex, std::string, std::regex_match;
using namespace msclr::interop;
using namespace DiskAnalyzer;
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	DiskAnalyzer::CatsChoose form;
	Application::Run(% form);
}

CatsChoose::CatsChoose()
{
	InitializeComponent();
	InitializeTreeView(true);
}

CatsChoose::~CatsChoose()
{
	if (components)
	{
		delete components;
	}
}

void CatsChoose::InitializeTreeView(const bool& userSettings) {
	ifstream openCatsList;
	if (userSettings) {
		openCatsList.open("UserCategories.txt");
		if (!openCatsList.is_open())
			openCatsList.open("StandartCategories.txt");
	}
	else
		openCatsList.open("StandartCategories.txt");
	string extOrCat;
	size_t NodesIter = -1;
	regex regularCat("([\\w]+[\\s]*)");
	regex regularExt("([\\.]{1})([a-z]+)");
	if (!(openCatsList.peek() == ifstream::traits_type::eof()))
		while (true) {
			if (openCatsList.eof())
				break;
			else {
				getline(openCatsList, extOrCat);
				if (regex_match(extOrCat, regularCat)) {
					treeView->Nodes->Add(gcnew String(extOrCat.c_str()));
					++NodesIter;
				}
				else
					if (regex_match(extOrCat, regularExt))
						treeView->Nodes[NodesIter]->Nodes->Add(gcnew String(extOrCat.c_str()));
			}
		}
	openCatsList.close();
}

void CatsChoose::InitializeComponent()
{
	this->treeView = (gcnew System::Windows::Forms::TreeView());
	this->addCategoryButton = (gcnew System::Windows::Forms::Button());
	this->addExtButton = (gcnew System::Windows::Forms::Button());
	this->deleteCatsOrExtsButton = (gcnew System::Windows::Forms::Button());
	this->resetButton = (gcnew System::Windows::Forms::Button());
	this->okButton = (gcnew System::Windows::Forms::Button());
	this->AbortButton = (gcnew System::Windows::Forms::Button());
	this->SuspendLayout();
	// 
	// treeView
	// 
	this->treeView->CheckBoxes = true;
	this->treeView->Location = System::Drawing::Point(12, 12);
	this->treeView->Name = L"treeView";
	this->treeView->Size = System::Drawing::Size(376, 419);
	this->treeView->TabIndex = 0;
	this->treeView->AfterCheck += gcnew System::Windows::Forms::TreeViewEventHandler(this, &CatsChoose::treeView_AfterCheck);
	this->treeView->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &CatsChoose::TreeView_AfterSelect);
	// 
	// addCategoryButton
	// 
	this->addCategoryButton->Location = System::Drawing::Point(408, 44);
	this->addCategoryButton->Name = L"addCategoryButton";
	this->addCategoryButton->Size = System::Drawing::Size(137, 63);
	this->addCategoryButton->TabIndex = 1;
	this->addCategoryButton->Text = L"Добавить категорию...";
	this->addCategoryButton->UseVisualStyleBackColor = true;
	this->addCategoryButton->Click += gcnew System::EventHandler(this, &CatsChoose::AddCategoryButton_Click);
	// 
	// addExtButton
	// 
	this->addExtButton->Enabled = false;
	this->addExtButton->Location = System::Drawing::Point(408, 127);
	this->addExtButton->Name = L"addExtButton";
	this->addExtButton->Size = System::Drawing::Size(137, 66);
	this->addExtButton->TabIndex = 2;
	this->addExtButton->Text = L"Добавить расширение...";
	this->addExtButton->UseVisualStyleBackColor = true;
	this->addExtButton->Click += gcnew System::EventHandler(this, &CatsChoose::AddExtButton_Click);
	// 
	// deleteCatsOrExtsButton
	// 
	this->deleteCatsOrExtsButton->Enabled = false;
	this->deleteCatsOrExtsButton->Location = System::Drawing::Point(408, 218);
	this->deleteCatsOrExtsButton->Name = L"deleteCatsOrExtsButton";
	this->deleteCatsOrExtsButton->Size = System::Drawing::Size(137, 66);
	this->deleteCatsOrExtsButton->TabIndex = 3;
	this->deleteCatsOrExtsButton->Text = L"Удалить выбранные";
	this->deleteCatsOrExtsButton->UseVisualStyleBackColor = true;
	this->deleteCatsOrExtsButton->Click += gcnew System::EventHandler(this, &CatsChoose::deleteCatsOrExtsButton_Click);
	// 
	// resetButton
	// 
	this->resetButton->Location = System::Drawing::Point(408, 303);
	this->resetButton->Name = L"resetButton";
	this->resetButton->Size = System::Drawing::Size(137, 84);
	this->resetButton->TabIndex = 4;
	this->resetButton->Text = L"Сброс к стандратному списку";
	this->resetButton->UseVisualStyleBackColor = true;
	this->resetButton->Click += gcnew System::EventHandler(this, &CatsChoose::resetButton_Click);
	// 
	// okButton
	// 
	this->okButton->Location = System::Drawing::Point(552, 390);
	this->okButton->Name = L"okButton";
	this->okButton->Size = System::Drawing::Size(75, 41);
	this->okButton->TabIndex = 5;
	this->okButton->Text = L"ОК";
	this->okButton->UseVisualStyleBackColor = true;
	this->okButton->Click += gcnew System::EventHandler(this, &CatsChoose::okButton_Click);
	// 
	// AbortButton
	// 
	this->AbortButton->Location = System::Drawing::Point(642, 390);
	this->AbortButton->Name = L"AbortButton";
	this->AbortButton->Size = System::Drawing::Size(92, 41);
	this->AbortButton->TabIndex = 6;
	this->AbortButton->Text = L"Отмена";
	this->AbortButton->UseVisualStyleBackColor = true;
	this->AbortButton->Click += gcnew System::EventHandler(this, &CatsChoose::AbortButton_Click);
	// 
	// CatsChoose
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(746, 443);
	this->Controls->Add(this->AbortButton);
	this->Controls->Add(this->okButton);
	this->Controls->Add(this->resetButton);
	this->Controls->Add(this->deleteCatsOrExtsButton);
	this->Controls->Add(this->addExtButton);
	this->Controls->Add(this->addCategoryButton);
	this->Controls->Add(this->treeView);
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
	this->Name = L"CatsChoose";
	this->Text = L"Редактирование категорий";
	this->ResumeLayout(false);

}

void CatsChoose::RemoveElemsFromTreeView() {
	for (size_t i = treeView->Nodes->Count; i > 0; --i)
		if (treeView->Nodes[i - 1]->Checked)
			treeView->Nodes[i - 1]->Remove();
		else
			for (size_t j = treeView->Nodes[i - 1]->Nodes->Count; j > 0; --j)
				if (treeView->Nodes[i - 1]->Nodes[j - 1]->Checked)
					treeView->Nodes[i - 1]->Nodes[j - 1]->Remove();
	deleteCatsOrExtsButton->Enabled = false;
	addExtButton->Enabled = false;
}

System::Void CatsChoose::deleteCatsOrExtsButton_Click(System::Object^ sender, System::EventArgs^ e) {
	RemoveElemsFromTreeView();
}

System::Void CatsChoose::treeView_AfterCheck(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e) {
	bool toBreak = false;
	size_t i, j;
	for (i = 0; i < treeView->Nodes->Count && !toBreak; ++i) {
		if (treeView->Nodes[i]->Checked) {
			deleteCatsOrExtsButton->Enabled = true;
			break;
		}
		else
			for (j = 0; j < treeView->Nodes[i]->Nodes->Count; ++j) {
				if (treeView->Nodes[i]->Nodes[j]->Checked) {
					deleteCatsOrExtsButton->Enabled = true;
					toBreak = true;
					break;
				}
			}
	}
	if (i == treeView->Nodes->Count)
		deleteCatsOrExtsButton->Enabled = false;
}

System::Void CatsChoose::resetButton_Click(System::Object^ sender, System::EventArgs^ e) {
	for (size_t i = 0; i < treeView->Nodes->Count; ++i)
		treeView->Nodes[i]->Checked = true;
	RemoveElemsFromTreeView();
	InitializeTreeView(false);
}

System::Void CatsChoose::okButton_Click(System::Object^ sender, System::EventArgs^ e) {
	ofstream saveCats("UserCategories.txt");
	bool otherCategoryCreatedByUser = false;
	for (size_t i = 0; i < treeView->Nodes->Count; ++i) {
		saveCats << marshal_as<string>(treeView->Nodes[i]->Text) << std::endl;
		if (treeView->Nodes[i]->Text == "Other")
			otherCategoryCreatedByUser = true;
		if (treeView->Nodes[i]->Nodes->Count) {
			for (size_t j = 0; j < treeView->Nodes[i]->Nodes->Count; ++j)
				saveCats << marshal_as<string>(treeView->Nodes[i]->Nodes[j]->Text) << std::endl;
		}
	}
	if (!otherCategoryCreatedByUser)
		saveCats << "Other";
	saveCats.close();
	this->Close();
}

System::Void CatsChoose::AbortButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}

System::Void CatsChoose::TreeView_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e) {
	addExtButton->Enabled = true;
}

System::Void CatsChoose::AddCategoryButton_Click(System::Object^ sender, System::EventArgs^ e){
	AddCatOrExt addCat;
	addCat.AddCategory();
	bool alreadyExists = false;
	if (catOrExtToAdd != "") {
		for (size_t i = 0; i < treeView->Nodes->Count; ++i) {
			if (treeView->Nodes[i]->Text == catOrExtToAdd) {
				alreadyExists = true;
				break;
			}
		}
		if (!alreadyExists) {
			treeView->Nodes->Add(catOrExtToAdd);
		}
		else
			MessageBox::Show("Такая категория уже существует!", "Ошибка", MessageBoxButtons::OK);
	}
	catOrExtToAdd = "";
}

System::Void CatsChoose::AddExtButton_Click(System::Object^ sender, System::EventArgs^ e){
	AddCatOrExt addExt;
	addExt.AddExtension();
	bool toBreak = false;
	if (catOrExtToAdd != "") {
		for (size_t i = 0; i < treeView->Nodes->Count && !toBreak; ++i)
			if (treeView->Nodes[i]->IsSelected) {
				for (size_t j = 0; j < treeView->Nodes[i]->Nodes->Count; ++j)
					if (catOrExtToAdd == treeView->Nodes[i]->Nodes[j]->Text) {
						MessageBox::Show("Такое расширение уже существует!", "Ошибка", MessageBoxButtons::OK);
						toBreak = true;
						break;
					}
				if (!toBreak) {
					treeView->Nodes[i]->Nodes->Add(catOrExtToAdd);
					break;
				}
			}
			else
				for (size_t j = 0; j < treeView->Nodes[i]->Nodes->Count; ++j) {
					if (catOrExtToAdd == treeView->Nodes[i]->Nodes[j]->Text) {
						MessageBox::Show("Такое расширение уже существует!", "Ошибка", MessageBoxButtons::OK);
						toBreak = true;
						break;
					}
					else
						if (treeView->Nodes[i]->Nodes[j]->IsSelected) {
							treeView->Nodes[i]->Nodes->Add(catOrExtToAdd);
							toBreak = true;
							break;
						}
				}
	}
	catOrExtToAdd = "";
}