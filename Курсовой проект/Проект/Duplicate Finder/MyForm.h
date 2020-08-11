#pragma once
#include "pch.h"
#include "FieldsAndCalc.h"
#include "About.h"

map <WhatToCompare, list<File>, Comparator> duplicates;
list <string> fileTypes;

namespace DuplicateFinder {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: bool check1;
	private: bool check2;
	private: bool check3;
	private: bool check4;

	private: System::Windows::Forms::Button^  FolderChooseButton;
	private: System::Windows::Forms::Button^  SearchButton;
	private: System::Windows::Forms::CheckBox^  NameCheckBox;
	private: System::Windows::Forms::CheckBox^  SizeCheckBox;
	private: System::Windows::Forms::CheckBox^  ModifiedTimeCheckBox;
	private: System::Windows::Forms::CheckBox^  ContentCheckBox;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
	private: System::Windows::Forms::Label^  PathLabel;
	private: System::Windows::Forms::Label^  ChosenPathLabel;
	private: System::Windows::Forms::Label^  ChooseCriteriaLabel;
	private: System::Windows::Forms::Button^  SaveButton;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::DataGridView^  DuplicatesList;

	private: System::Windows::Forms::Label^  DuplicatesLabel;
	private: System::Windows::Forms::Label^  AddFileTypesLabel;
	private: System::Windows::Forms::TextBox^  AddFileTypesTextBox;
	private: System::Windows::Forms::CheckedListBox^  FileTypesList;
	private: System::Windows::Forms::Button^  AddFileTypeButton;
	private: System::Windows::Forms::Label^  AllTypesLabel;
	private: System::Windows::Forms::Button^  DeleteTypesButton;
	private: System::Windows::Forms::Label^  FileTypesLabel;
	private: System::Windows::Forms::ToolTip^  toolTip1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::DirectoryServices::DirectoryEntry^  directoryEntry1;
	private: System::Windows::Forms::Button^  AboutProgram;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->FolderChooseButton = (gcnew System::Windows::Forms::Button());
			this->SearchButton = (gcnew System::Windows::Forms::Button());
			this->NameCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->SizeCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->ModifiedTimeCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->ContentCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->PathLabel = (gcnew System::Windows::Forms::Label());
			this->ChosenPathLabel = (gcnew System::Windows::Forms::Label());
			this->ChooseCriteriaLabel = (gcnew System::Windows::Forms::Label());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->DuplicatesList = (gcnew System::Windows::Forms::DataGridView());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DuplicatesLabel = (gcnew System::Windows::Forms::Label());
			this->AddFileTypesLabel = (gcnew System::Windows::Forms::Label());
			this->AddFileTypesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->FileTypesList = (gcnew System::Windows::Forms::CheckedListBox());
			this->AddFileTypeButton = (gcnew System::Windows::Forms::Button());
			this->AllTypesLabel = (gcnew System::Windows::Forms::Label());
			this->DeleteTypesButton = (gcnew System::Windows::Forms::Button());
			this->FileTypesLabel = (gcnew System::Windows::Forms::Label());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->directoryEntry1 = (gcnew System::DirectoryServices::DirectoryEntry());
			this->AboutProgram = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DuplicatesList))->BeginInit();
			this->SuspendLayout();
			// 
			// FolderChooseButton
			// 
			this->FolderChooseButton->Location = System::Drawing::Point(13, 35);
			this->FolderChooseButton->Name = L"FolderChooseButton";
			this->FolderChooseButton->Size = System::Drawing::Size(102, 34);
			this->FolderChooseButton->TabIndex = 0;
			this->FolderChooseButton->Text = L"Выберите папку...";
			this->toolTip1->SetToolTip(this->FolderChooseButton, L"Выберите папку для поиска дубликатов.");
			this->FolderChooseButton->UseVisualStyleBackColor = true;
			this->FolderChooseButton->Click += gcnew System::EventHandler(this, &MyForm::FolderChooseButton_Click);
			// 
			// SearchButton
			// 
			this->SearchButton->Enabled = false;
			this->SearchButton->Location = System::Drawing::Point(13, 91);
			this->SearchButton->Name = L"SearchButton";
			this->SearchButton->Size = System::Drawing::Size(102, 35);
			this->SearchButton->TabIndex = 1;
			this->SearchButton->Text = L"Поиск";
			this->toolTip1->SetToolTip(this->SearchButton, L"Ищет дубликаты. Если не выбраны типы файлов, будет выполнен поиск по всем типам.");
			this->SearchButton->UseVisualStyleBackColor = true;
			this->SearchButton->Click += gcnew System::EventHandler(this, &MyForm::SearchButton_Click);
			// 
			// NameCheckBox
			// 
			this->NameCheckBox->AutoSize = true;
			this->NameCheckBox->Location = System::Drawing::Point(132, 52);
			this->NameCheckBox->Name = L"NameCheckBox";
			this->NameCheckBox->Size = System::Drawing::Size(48, 17);
			this->NameCheckBox->TabIndex = 2;
			this->NameCheckBox->Text = L"Имя";
			this->NameCheckBox->UseVisualStyleBackColor = true;
			this->NameCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::NameCheckBox_CheckedChanged);
			// 
			// SizeCheckBox
			// 
			this->SizeCheckBox->AutoSize = true;
			this->SizeCheckBox->Location = System::Drawing::Point(182, 52);
			this->SizeCheckBox->Name = L"SizeCheckBox";
			this->SizeCheckBox->Size = System::Drawing::Size(65, 17);
			this->SizeCheckBox->TabIndex = 3;
			this->SizeCheckBox->Text = L"Размер";
			this->SizeCheckBox->UseVisualStyleBackColor = true;
			this->SizeCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::SizeCheckBox_CheckedChanged);
			// 
			// ModifiedTimeCheckBox
			// 
			this->ModifiedTimeCheckBox->AutoSize = true;
			this->ModifiedTimeCheckBox->Location = System::Drawing::Point(253, 52);
			this->ModifiedTimeCheckBox->Name = L"ModifiedTimeCheckBox";
			this->ModifiedTimeCheckBox->Size = System::Drawing::Size(118, 17);
			this->ModifiedTimeCheckBox->TabIndex = 4;
			this->ModifiedTimeCheckBox->Text = L"Время изменения";
			this->ModifiedTimeCheckBox->UseVisualStyleBackColor = true;
			this->ModifiedTimeCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::ModifiedTimeCheckBox_CheckedChanged);
			// 
			// ContentCheckBox
			// 
			this->ContentCheckBox->AutoSize = true;
			this->ContentCheckBox->Location = System::Drawing::Point(377, 52);
			this->ContentCheckBox->Name = L"ContentCheckBox";
			this->ContentCheckBox->Size = System::Drawing::Size(251, 17);
			this->ContentCheckBox->TabIndex = 5;
			this->ContentCheckBox->Text = L"Содержание (только для текстовых файлов)";
			this->ContentCheckBox->UseVisualStyleBackColor = true;
			this->ContentCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::ContentCheckBox_CheckedChanged);
			// 
			// folderBrowserDialog1
			// 
			this->folderBrowserDialog1->Description = L"Выберите папку для поиска дубликатов";
			this->folderBrowserDialog1->ShowNewFolderButton = false;
			// 
			// PathLabel
			// 
			this->PathLabel->AutoSize = true;
			this->PathLabel->Location = System::Drawing::Point(229, 91);
			this->PathLabel->Name = L"PathLabel";
			this->PathLabel->Size = System::Drawing::Size(0, 13);
			this->PathLabel->TabIndex = 6;
			// 
			// ChosenPathLabel
			// 
			this->ChosenPathLabel->AutoSize = true;
			this->ChosenPathLabel->Location = System::Drawing::Point(129, 91);
			this->ChosenPathLabel->Name = L"ChosenPathLabel";
			this->ChosenPathLabel->Size = System::Drawing::Size(94, 13);
			this->ChosenPathLabel->TabIndex = 7;
			this->ChosenPathLabel->Text = L"Выбранный путь:";
			// 
			// ChooseCriteriaLabel
			// 
			this->ChooseCriteriaLabel->AutoSize = true;
			this->ChooseCriteriaLabel->Location = System::Drawing::Point(241, 31);
			this->ChooseCriteriaLabel->Name = L"ChooseCriteriaLabel";
			this->ChooseCriteriaLabel->Size = System::Drawing::Size(146, 13);
			this->ChooseCriteriaLabel->TabIndex = 8;
			this->ChooseCriteriaLabel->Text = L"Выберите критерии посика";
			// 
			// SaveButton
			// 
			this->SaveButton->Enabled = false;
			this->SaveButton->Location = System::Drawing::Point(13, 150);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(102, 49);
			this->SaveButton->TabIndex = 9;
			this->SaveButton->Text = L"Сохранить в текстовый файл...";
			this->toolTip1->SetToolTip(this->SaveButton, L"Выберите или создайте файл для сохранения списка дубликатов");
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &MyForm::SaveButton_Click);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->CreatePrompt = true;
			this->saveFileDialog1->DefaultExt = L"*.txt";
			this->saveFileDialog1->Filter = L"(*.txt)|";
			// 
			// DuplicatesList
			// 
			this->DuplicatesList->AllowUserToAddRows = false;
			this->DuplicatesList->AllowUserToDeleteRows = false;
			this->DuplicatesList->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->DuplicatesList->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->DuplicatesList->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->DuplicatesList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Column5,
					this->Column1, this->Column2, this->Column3, this->Column4
			});
			this->DuplicatesList->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->DuplicatesList->Location = System::Drawing::Point(132, 126);
			this->DuplicatesList->Name = L"DuplicatesList";
			this->DuplicatesList->ReadOnly = true;
			this->DuplicatesList->Size = System::Drawing::Size(939, 514);
			this->DuplicatesList->TabIndex = 10;
			// 
			// Column5
			// 
			this->Column5->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->Column5->HeaderText = L"№";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Programmatic;
			this->Column5->Width = 75;
			// 
			// Column1
			// 
			this->Column1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->Column1->HeaderText = L"Имя";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Programmatic;
			// 
			// Column2
			// 
			this->Column2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->Column2->HeaderText = L"Путь";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Programmatic;
			this->Column2->Width = 200;
			// 
			// Column3
			// 
			this->Column3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->Column3->HeaderText = L"Размер";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Programmatic;
			this->Column3->Width = 60;
			// 
			// Column4
			// 
			this->Column4->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->Column4->HeaderText = L"Дата изменения";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Programmatic;
			this->Column4->Width = 150;
			// 
			// DuplicatesLabel
			// 
			this->DuplicatesLabel->AutoSize = true;
			this->DuplicatesLabel->Location = System::Drawing::Point(414, 102);
			this->DuplicatesLabel->Name = L"DuplicatesLabel";
			this->DuplicatesLabel->Size = System::Drawing::Size(67, 13);
			this->DuplicatesLabel->TabIndex = 11;
			this->DuplicatesLabel->Text = L"Дубликаты:";
			// 
			// AddFileTypesLabel
			// 
			this->AddFileTypesLabel->AutoSize = true;
			this->AddFileTypesLabel->Location = System::Drawing::Point(703, 31);
			this->AddFileTypesLabel->Name = L"AddFileTypesLabel";
			this->AddFileTypesLabel->Size = System::Drawing::Size(264, 13);
			this->AddFileTypesLabel->TabIndex = 14;
			this->AddFileTypesLabel->Text = L"Добавить типы файлов (по одному) напр.(.txt;.doc):";
			// 
			// AddFileTypesTextBox
			// 
			this->AddFileTypesTextBox->Location = System::Drawing::Point(706, 50);
			this->AddFileTypesTextBox->Name = L"AddFileTypesTextBox";
			this->AddFileTypesTextBox->Size = System::Drawing::Size(168, 20);
			this->AddFileTypesTextBox->TabIndex = 15;
			this->toolTip1->SetToolTip(this->AddFileTypesTextBox, L"Добавьте расширения файлов для поиска");
			// 
			// FileTypesList
			// 
			this->FileTypesList->CheckOnClick = true;
			this->FileTypesList->Cursor = System::Windows::Forms::Cursors::Default;
			this->FileTypesList->FormattingEnabled = true;
			this->FileTypesList->Location = System::Drawing::Point(13, 240);
			this->FileTypesList->Name = L"FileTypesList";
			this->FileTypesList->Size = System::Drawing::Size(113, 349);
			this->FileTypesList->TabIndex = 16;
			this->toolTip1->SetToolTip(this->FileTypesList, L"Выберите типы файлов, среди которых будет выполняться поиск или которые вы хотите"
				L" удалить");
			this->FileTypesList->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::FileTypesList_SelectedIndexChanged);
			// 
			// AddFileTypeButton
			// 
			this->AddFileTypeButton->Location = System::Drawing::Point(892, 48);
			this->AddFileTypeButton->Name = L"AddFileTypeButton";
			this->AddFileTypeButton->Size = System::Drawing::Size(75, 23);
			this->AddFileTypeButton->TabIndex = 17;
			this->AddFileTypeButton->Text = L"Добавить";
			this->toolTip1->SetToolTip(this->AddFileTypeButton, L"Добавляет тип файла в список");
			this->AddFileTypeButton->UseVisualStyleBackColor = true;
			this->AddFileTypeButton->Click += gcnew System::EventHandler(this, &MyForm::AddFileTypeButton_Click);
			// 
			// AllTypesLabel
			// 
			this->AllTypesLabel->AutoSize = true;
			this->AllTypesLabel->Location = System::Drawing::Point(40, 264);
			this->AllTypesLabel->Name = L"AllTypesLabel";
			this->AllTypesLabel->Size = System::Drawing::Size(54, 13);
			this->AllTypesLabel->TabIndex = 18;
			this->AllTypesLabel->Text = L"Все типы";
			// 
			// DeleteTypesButton
			// 
			this->DeleteTypesButton->Enabled = false;
			this->DeleteTypesButton->Location = System::Drawing::Point(31, 604);
			this->DeleteTypesButton->Name = L"DeleteTypesButton";
			this->DeleteTypesButton->Size = System::Drawing::Size(75, 23);
			this->DeleteTypesButton->TabIndex = 19;
			this->DeleteTypesButton->Text = L"Удалить";
			this->toolTip1->SetToolTip(this->DeleteTypesButton, L"Удаляет выбранные элементы из списка типов файлов");
			this->DeleteTypesButton->UseVisualStyleBackColor = true;
			this->DeleteTypesButton->Click += gcnew System::EventHandler(this, &MyForm::DeleteTypesButton_Click);
			// 
			// FileTypesLabel
			// 
			this->FileTypesLabel->AutoSize = true;
			this->FileTypesLabel->Location = System::Drawing::Point(28, 224);
			this->FileTypesLabel->Name = L"FileTypesLabel";
			this->FileTypesLabel->Size = System::Drawing::Size(78, 13);
			this->FileTypesLabel->TabIndex = 20;
			this->FileTypesLabel->Text = L"Типы файлов:";
			// 
			// toolTip1
			// 
			this->toolTip1->AutoPopDelay = 5000;
			this->toolTip1->InitialDelay = 200;
			this->toolTip1->ReshowDelay = 100;
			this->toolTip1->ShowAlways = true;
			// 
			// AboutProgram
			// 
			this->AboutProgram->Location = System::Drawing::Point(0, -1);
			this->AboutProgram->Name = L"AboutProgram";
			this->AboutProgram->Size = System::Drawing::Size(94, 23);
			this->AboutProgram->TabIndex = 21;
			this->AboutProgram->Text = L"О программе...";
			this->AboutProgram->UseVisualStyleBackColor = true;
			this->AboutProgram->Click += gcnew System::EventHandler(this, &MyForm::AboutProgram_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(1083, 668);
			this->Controls->Add(this->AboutProgram);
			this->Controls->Add(this->FileTypesLabel);
			this->Controls->Add(this->DeleteTypesButton);
			this->Controls->Add(this->AllTypesLabel);
			this->Controls->Add(this->AddFileTypeButton);
			this->Controls->Add(this->FileTypesList);
			this->Controls->Add(this->AddFileTypesTextBox);
			this->Controls->Add(this->AddFileTypesLabel);
			this->Controls->Add(this->DuplicatesLabel);
			this->Controls->Add(this->DuplicatesList);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->ChooseCriteriaLabel);
			this->Controls->Add(this->ChosenPathLabel);
			this->Controls->Add(this->PathLabel);
			this->Controls->Add(this->ContentCheckBox);
			this->Controls->Add(this->ModifiedTimeCheckBox);
			this->Controls->Add(this->SizeCheckBox);
			this->Controls->Add(this->NameCheckBox);
			this->Controls->Add(this->SearchButton);
			this->Controls->Add(this->FolderChooseButton);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Duplicate Finder";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DuplicatesList))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void FolderChooseButton_Click(System::Object^  sender, System::EventArgs^  e) {
		folderBrowserDialog1->ShowDialog();
		PathLabel->Text = folderBrowserDialog1->SelectedPath;
		if ((NameCheckBox->Checked || SizeCheckBox->Checked || ModifiedTimeCheckBox->Checked || ContentCheckBox->Checked) && PathLabel->Text != "")
			SearchButton->Enabled = true;
		else
			SearchButton->Enabled = false;
	}
	private: System::Void SearchButton_Click(System::Object^  sender, System::EventArgs^  e) {
		fileTypes.clear();
		check1 = NameCheckBox->Checked;
		check2 = SizeCheckBox->Checked;
		check3 = ModifiedTimeCheckBox->Checked;
		check4 = ContentCheckBox->Checked;
		for (size_t i = 0; i < FileTypesList->CheckedIndices->Count; i++) {
			String^ str = gcnew String(FileTypesList->Items[FileTypesList->CheckedIndices[i]]->ToString());
			fileTypes.emplace_back(marshal_as<string>(str));
		}
		duplicates.clear();
		string path = marshal_as<string>(folderBrowserDialog1->SelectedPath);
		FolderChooseButton->Enabled = false;
		SearchButton->Enabled = false;
		SaveButton->Enabled = false;
		NameCheckBox->Enabled = false;
		SizeCheckBox->Enabled = false;
		ModifiedTimeCheckBox->Enabled = false;
		ContentCheckBox->Enabled = false;
		while (DuplicatesList->RowCount)
			DuplicatesList->Rows->RemoveAt(0);
		Search(path, duplicates, NameCheckBox->Checked, SizeCheckBox->Checked, ModifiedTimeCheckBox->Checked, ContentCheckBox->Checked, fileTypes);
		size_t k = 0, j = 0;
		for (const auto &itMap : duplicates)
			if (itMap.second.size() > 1) {
				j++;
				DuplicatesList->Rows->Add();
				DuplicatesList->Rows[k]->Cells[0]->Value = "Группа " + Convert::ToString(j);
				size_t i = 0;
				for (auto &itList : itMap.second) {
					i++;
					k++;
					DuplicatesList->Rows->Add();
					DuplicatesList->Rows[k]->Cells[0]->Value = i;
					String^ name = gcnew String(itList.name.c_str());
					String^ path = gcnew String(itList.path.c_str());
					String^ size = gcnew String(to_string(itList.size).c_str());
					size += " Б";
					String^ modifiedTime = gcnew String(itList.lastChangeTime.c_str());
					DuplicatesList->Rows[k]->Cells[1]->Value = name;
					DuplicatesList->Rows[k]->Cells[2]->Value = path;
					DuplicatesList->Rows[k]->Cells[3]->Value = size;
					DuplicatesList->Rows[k]->Cells[4]->Value = modifiedTime;
				}
				k++;
			}
		FolderChooseButton->Enabled = true;
		SearchButton->Enabled = true;
		NameCheckBox->Enabled = true;
		SizeCheckBox->Enabled = true;
		ModifiedTimeCheckBox->Enabled = true;
		size_t i = 0;
		for (; i < FileTypesList->CheckedIndices->Count; i++)
			if (FileTypesList->CheckedItems[i]->Equals(".txt"))
				break;
		if (i != FileTypesList->CheckedIndices->Count || !FileTypesList->CheckedIndices->Count)
			ContentCheckBox->Enabled = true;
		SaveButton->Enabled = true;
		MessageBox::Show("Поиск завершён!", "Результат", MessageBoxButtons::OK);
	}

	private: void CheckBoxCheck() {
		if ((NameCheckBox->Checked || SizeCheckBox->Checked || ModifiedTimeCheckBox->Checked || ContentCheckBox->Checked) && PathLabel->Text != "")
			SearchButton->Enabled = true;
		else
			SearchButton->Enabled = false;
		if (ContentCheckBox->Checked && !SizeCheckBox->Checked)
			SizeCheckBox->Checked = true;
	}
	private: System::Void NameCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		CheckBoxCheck();
	}
	private: System::Void SizeCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		CheckBoxCheck();
	}
	private: System::Void ModifiedTimeCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		CheckBoxCheck();
	}
	private: System::Void ContentCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		CheckBoxCheck();
	}
	private: System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e) {
		saveFileDialog1->ShowDialog();
		if (saveFileDialog1->FileName->EndsWith(".txt")) {
			ofstream output(marshal_as<string>(saveFileDialog1->FileName));
			struct tm newtime;
			__time32_t aclock;
			char buffer[32];
			errno_t errNum;
			_time32(&aclock);   // Get time in seconds.
			_localtime32_s(&newtime, &aclock);   // Convert time to struct tm form.
			errNum = asctime_s(buffer, 32, &newtime);
			string str = (string)buffer;
			output << str;
			output << "Вы искали дубликаты в папке: " << marshal_as<string>(folderBrowserDialog1->SelectedPath) << endl << "По следующим критериям:";
			if (check1) output << " имя";
			if (check2) output << " размер";
			if (check3) output << " время_изменения";
			if (check4) output << " содержание";
			output << endl << "Типы файлов: ";
			if (!fileTypes.empty())
				for (const auto &it : fileTypes)
					output << it << "; ";
			else
				output << "Все типы";
			output << "\n\n";
			size_t j = 0;
			for (const auto &itMap : duplicates)
				if (itMap.second.size() > 1) {
					j++;
					output << "Группа " << j << endl;
					size_t i = 0;
					for (const auto &itList : itMap.second) {
						i++;
						output << i << ". " << "Имя: " << itList.name << endl;
						output << "Размер: " << itList.size << " B" << endl;
						output << "Дата изменения: " << itList.lastChangeTime;
						output << "Путь: " << itList.path << endl;
					}
					output << endl;
				}
			if (!j)
				output << "Дубликаты не найдены";
			MessageBox::Show("Сохранено!", "Попытка сохранения", MessageBoxButtons::OK);
		}
		else {
			MessageBox::Show("Файл не был сохранён. Неверный формат!\nПопробуйте снова!", "Попытка сохранения", MessageBoxButtons::OK);
			remove(marshal_as<string>(saveFileDialog1->FileName));
		}
	}
	private: System::Void FileTypesList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		size_t i = 0;
		for (; i < FileTypesList->CheckedIndices->Count; i++)
			if (FileTypesList->CheckedItems[i]->Equals(".txt"))
				break;
		if (i == FileTypesList->CheckedIndices->Count && FileTypesList->CheckedIndices->Count) {
			ContentCheckBox->Checked = false;
			ContentCheckBox->Enabled = false;
		}
		else
			ContentCheckBox->Enabled = true;
		if (!FileTypesList->CheckedIndices->Count)
			DeleteTypesButton->Enabled = false;
		else
			DeleteTypesButton->Enabled = true;
	}
	private: System::Void AddFileTypeButton_Click(System::Object^  sender, System::EventArgs^  e) {
		string str = marshal_as<string>(AddFileTypesTextBox->Text);
		regex regular("([\\.]{1})([a-z]+)");
		if (!regex_match(str.c_str(), regular))
			MessageBox::Show("Неверный формат\nПопробуйте снова!", "Добавление расширения", MessageBoxButtons::OK);
		else {
			size_t i = 0;
			for (; i < FileTypesList->Items->Count; i++)
				if (FileTypesList->Items[i]->Equals(AddFileTypesTextBox->Text))
					break;
			if (i != FileTypesList->Items->Count)
				MessageBox::Show("Вы не можете добавить два одинаковых расширения\nПопробуйте снова!", "Добавление расширения", MessageBoxButtons::OK);
			else {
				AllTypesLabel->Text = "";
				FileTypesList->Items->Add(AddFileTypesTextBox->Text);
			}
		}
	}
	private: System::Void DeleteTypesButton_Click(System::Object^  sender, System::EventArgs^  e) {
		for (size_t j = FileTypesList->CheckedIndices->Count; j > 0; j--)
			FileTypesList->Items->RemoveAt(FileTypesList->CheckedIndices[j - 1]);
		size_t i;
		for (i = 0; i < FileTypesList->CheckedIndices->Count; i++)
			if (FileTypesList->CheckedItems[i]->Equals(".txt"))
				break;
		if (i == FileTypesList->CheckedIndices->Count && FileTypesList->CheckedIndices->Count) {
			ContentCheckBox->Checked = false;
			ContentCheckBox->Enabled = false;
		}
		else
			ContentCheckBox->Enabled = true;
		if (!FileTypesList->CheckedIndices->Count) {
			DeleteTypesButton->Enabled = false;
		}
		else {
			DeleteTypesButton->Enabled = true;
		}
		if (!FileTypesList->Items->Count) {
			ContentCheckBox->Enabled = true;
			AllTypesLabel->Text = "Все типы";
		}
	}
private: System::Void AboutProgram_Click(System::Object^  sender, System::EventArgs^  e) {
	About^ about = gcnew About();
	about->ShowDialog();
}
};
};