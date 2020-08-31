#include "Interface.h"
#include "CatsChoose.h"
#include "SearchAlgorithm.h"
#include <fstream>
#include <regex>
#include <filesystem>
#include <msclr/marshal_cppstd.h>

using std::ifstream, std::regex, std::regex_match;
using namespace msclr::interop;
using namespace DiskAnalyzer;
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	DiskAnalyzer::Interface form;
	Application::Run(% form);
}

Interface::Interface()
{
	InitializeComponent();
	InitializeCatsList();
}

void Interface::InitializeComponent()
{
	System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
	System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
	System::Windows::Forms::DataVisualization::Charting::Title^ title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
	this->folderChooseButton = (gcnew System::Windows::Forms::Button());
	this->categoriesChooseButton = (gcnew System::Windows::Forms::Button());
	this->catsAndExtsTree = (gcnew System::Windows::Forms::TreeView());
	this->filesList = (gcnew System::Windows::Forms::DataGridView());
	this->nameColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
	this->sizeColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
	this->extensionColumns = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
	this->pathColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
	this->analyzeButton = (gcnew System::Windows::Forms::Button());
	this->filesChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
	this->folderBrowserDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->filesList))->BeginInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->filesChart))->BeginInit();
	this->SuspendLayout();
	// 
	// folderChooseButton
	// 
	this->folderChooseButton->Location = System::Drawing::Point(12, 89);
	this->folderChooseButton->Name = L"folderChooseButton";
	this->folderChooseButton->Size = System::Drawing::Size(138, 61);
	this->folderChooseButton->TabIndex = 0;
	this->folderChooseButton->Text = L"Выберите папку...";
	this->folderChooseButton->UseVisualStyleBackColor = true;
	this->folderChooseButton->Click += gcnew System::EventHandler(this, &Interface::FolderChooseButton_Click);
	// 
	// categoriesChooseButton
	// 
	this->categoriesChooseButton->Location = System::Drawing::Point(12, 12);
	this->categoriesChooseButton->Name = L"categoriesChooseButton";
	this->categoriesChooseButton->Size = System::Drawing::Size(138, 71);
	this->categoriesChooseButton->TabIndex = 1;
	this->categoriesChooseButton->Text = L"Категории файлов...";
	this->categoriesChooseButton->UseVisualStyleBackColor = true;
	this->categoriesChooseButton->Click += gcnew System::EventHandler(this, &Interface::CategoriesChooseButton_Click);
	// 
	// catsAndExtsTree
	// 
	this->catsAndExtsTree->Location = System::Drawing::Point(12, 156);
	this->catsAndExtsTree->Name = L"catsAndExtsTree";
	this->catsAndExtsTree->Size = System::Drawing::Size(281, 730);
	this->catsAndExtsTree->TabIndex = 4;
	this->catsAndExtsTree->Visible = false;
	this->catsAndExtsTree->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &Interface::CatsAndExtsTree_AfterSelect);
	// 
	// filesList
	// 
	this->filesList->AllowUserToAddRows = false;
	this->filesList->AllowUserToDeleteRows = false;
	this->filesList->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
		| System::Windows::Forms::AnchorStyles::Right));
	this->filesList->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
	this->filesList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
		this->nameColumn,
			this->sizeColumn, this->extensionColumns, this->pathColumn
	});
	this->filesList->Location = System::Drawing::Point(299, 307);
	this->filesList->Name = L"filesList";
	this->filesList->RowHeadersWidth = 62;
	this->filesList->RowTemplate->Height = 28;
	this->filesList->Size = System::Drawing::Size(374, 580);
	this->filesList->TabIndex = 6;
	this->filesList->Visible = false;
	// 
	// nameColumn
	// 
	this->nameColumn->HeaderText = L"Имя";
	this->nameColumn->MinimumWidth = 8;
	this->nameColumn->Name = L"nameColumn";
	this->nameColumn->ReadOnly = true;
	this->nameColumn->Width = 70;
	// 
	// sizeColumn
	// 
	this->sizeColumn->HeaderText = L"Размер";
	this->sizeColumn->MinimumWidth = 8;
	this->sizeColumn->Name = L"sizeColumn";
	this->sizeColumn->ReadOnly = true;
	this->sizeColumn->Width = 70;
	// 
	// extensionColumns
	// 
	this->extensionColumns->HeaderText = L"Расширение";
	this->extensionColumns->MinimumWidth = 8;
	this->extensionColumns->Name = L"extensionColumns";
	this->extensionColumns->ReadOnly = true;
	this->extensionColumns->Width = 120;
	// 
	// pathColumn
	// 
	this->pathColumn->HeaderText = L"Путь";
	this->pathColumn->MinimumWidth = 8;
	this->pathColumn->Name = L"pathColumn";
	this->pathColumn->ReadOnly = true;
	this->pathColumn->Width = 200;
	// 
	// analyzeButton
	// 
	this->analyzeButton->Enabled = false;
	this->analyzeButton->Location = System::Drawing::Point(156, 57);
	this->analyzeButton->Name = L"analyzeButton";
	this->analyzeButton->Size = System::Drawing::Size(133, 61);
	this->analyzeButton->TabIndex = 7;
	this->analyzeButton->Text = L"Анализ";
	this->analyzeButton->UseVisualStyleBackColor = true;
	this->analyzeButton->Click += gcnew System::EventHandler(this, &Interface::AnalyzeButton_Click);
	// 
	// filesChart
	// 
	this->filesChart->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
		| System::Windows::Forms::AnchorStyles::Right));
	chartArea1->Name = L"ChartArea1";
	this->filesChart->ChartAreas->Add(chartArea1);
	this->filesChart->Location = System::Drawing::Point(299, 12);
	this->filesChart->Name = L"filesChart";
	series1->ChartArea = L"ChartArea1";
	series1->Name = L"Ser";
	this->filesChart->Series->Add(series1);
	this->filesChart->Size = System::Drawing::Size(0, 289);
	this->filesChart->TabIndex = 11;
	this->filesChart->Text = L"Диаграмма занятого места";
	title1->Name = L"Title1";
	title1->Text = L"Диаграмма файлов";
	this->filesChart->Titles->Add(title1);
	this->filesChart->Visible = false;
	// 
	// Interface
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->AutoScroll = true;
	this->ClientSize = System::Drawing::Size(319, 155);
	this->Controls->Add(this->filesChart);
	this->Controls->Add(this->analyzeButton);
	this->Controls->Add(this->filesList);
	this->Controls->Add(this->catsAndExtsTree);
	this->Controls->Add(this->categoriesChooseButton);
	this->Controls->Add(this->folderChooseButton);
	this->Name = L"Interface";
	this->Text = L"Disk Analyzer";
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->filesList))->EndInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->filesChart))->EndInit();
	this->ResumeLayout(false);

}

void Interface::InitializeCatsList() {
	ifstream CatsAndExtsFile("UserCategories.txt");
	if (!CatsAndExtsFile.is_open())
		CatsAndExtsFile.open("StandartCategories.txt");
	string catOrExt;
	list<Category>::iterator category;
	regex regularCat("([\\w]+[\\s]*)");
	regex regularExt("([\\.]{1})([a-z]+)");
	if (CatsAndExtsFile.peek() != ifstream::traits_type::eof())
		while (true) {
			if (CatsAndExtsFile.eof())
				break;
			else {
				getline(CatsAndExtsFile, catOrExt);
				if (regex_match(catOrExt, regularCat)) {
					listOfFilesByCategories.push_back(catOrExt);
					category = listOfFilesByCategories.end();
					--category;
				}
				else
					if (regex_match(catOrExt, regularExt))
						category->mapOfFiles.emplace(catOrExt, list<File>());
			}
		}
	else
		listOfFilesByCategories.push_back(string("Other"));
	CatsAndExtsFile.close();
}

System::Void Interface::CategoriesChooseButton_Click(System::Object^ sender, System::EventArgs^ e) {
	CatsChoose^ CatsList = gcnew CatsChoose();
	CatsList->ShowDialog();
}

System::Void Interface::FolderChooseButton_Click(System::Object^ sender, System::EventArgs^ e) {
	folderBrowserDialog->ShowDialog();
	if (folderBrowserDialog->SelectedPath != "")
		analyzeButton->Enabled = true;
}

System::Void Interface::AnalyzeButton_Click(System::Object^ sender, System::EventArgs^ e) {
	srand(static_cast<unsigned int>(time(nullptr)));
	while (filesList->RowCount)
		filesList->Rows->RemoveAt(0);
	filesChart->Series["Ser"]->Points->Clear();
	catsAndExtsTree->Nodes->Clear();
	listOfFilesByCategories.clear();
	InitializeCatsList();
	Search(marshal_as<string>(folderBrowserDialog->SelectedPath), listOfFilesByCategories);
	auto space = std::filesystem::space(marshal_as<string>(folderBrowserDialog->SelectedPath));
	double free = space.free / (1024 * 1024 * 1024);
	size_t i = 0, j = 0;
	filesChart->ChartAreas["ChartArea1"]->AxisX->Title = "Категория";
	filesChart->ChartAreas["ChartArea1"]->AxisY->Title = "Размер (Гб)";
	filesChart->Series["Ser"]->Points->AddXY("Свободно", free);
	filesChart->Series["Ser"]->Points[i]->Color = System::Drawing::Color::FromArgb(rand() % 256, rand() % 256, rand() % 256);
	for (const auto& Category : listOfFilesByCategories) {
		++i;
		String^ catName = gcnew String(Category.name.c_str());
		long double sizeInGb = Category.size;
		sizeInGb /= (1024 * 1024 * 1024);
		filesChart->Series["Ser"]->Points->AddXY(catName, sizeInGb);
		filesChart->Series["Ser"]->Points[i]->Color = System::Drawing::Color::FromArgb(rand()%256, rand()%256, rand()%256);
		String^ catToShowInTreeView = catName + "    ";
		if (sizeInGb > 0.006) {
			sizeInGb = round(sizeInGb * 100) / 100;
			catToShowInTreeView += sizeInGb;
		}
		else
			if (Category.size != 0)
				catToShowInTreeView += "0.00...";
			else
				catToShowInTreeView += "0";
		catToShowInTreeView += " Гб";
		catsAndExtsTree->Nodes->Add(catToShowInTreeView)->Name = catName;
		for (const auto& extAndFiles : Category.mapOfFiles) {
			String^ extName = gcnew String(extAndFiles.first.c_str());
			String^ extToShowInTreeView;
			if (extName->Length > 5)
				extToShowInTreeView = extName->Remove(4) + "...";
			else
				extToShowInTreeView = extName;
			extToShowInTreeView += " " + extAndFiles.second.size();
			if (extAndFiles.second.size() == 1)
				extToShowInTreeView += " файл";
			else
				extToShowInTreeView += " файла(ов)";
			catsAndExtsTree->Nodes[j]->Nodes->Add(extToShowInTreeView)->Name = extName;
		}
		++j;
	}
	String^ freeSpace = gcnew String("Свободно" + "    " + round(free * 100) / 100 + " Гб");
	catsAndExtsTree->Nodes->Add(freeSpace);
	this->ClientSize = System::Drawing::Size(1145, 584);
	catsAndExtsTree->Visible = true;
	filesList->Visible = true;
	filesChart->Visible = true;
}

System::Void Interface::CatsAndExtsTree_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e) {
	if (catsAndExtsTree->SelectedNode->Level != 0) {
		int catIndex = catsAndExtsTree->SelectedNode->Parent->Index;
		while (filesList->RowCount)
			filesList->Rows->RemoveAt(0);
		size_t check = 0;
		for (const auto& Category : listOfFilesByCategories) {
			if (check == catIndex) {
				const auto& itMap = Category.mapOfFiles.find(marshal_as<string>(catsAndExtsTree->SelectedNode->Name));
				auto& itFilesList = itMap->second.cbegin();
				for (size_t k = 0; k < itMap->second.size(); ++k, ++itFilesList) {
					filesList->Rows->Add();
					filesList->Rows[k]->Cells[0]->Value = gcnew String(itFilesList->name.c_str());
					filesList->Rows[k]->Cells[1]->Value = gcnew String(Convert::ToString(itFilesList->size) + " Б");
					filesList->Rows[k]->Cells[2]->Value = gcnew String(itMap->first.c_str());
					filesList->Rows[k]->Cells[3]->Value = gcnew String(itFilesList->path.c_str());
				}
				break;
			}
			else
				++check;
		}
	}
}

Interface::~Interface()
{
	if (components)
	{
		delete components;
	}
}