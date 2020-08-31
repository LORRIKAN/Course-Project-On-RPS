#pragma once
#include "Structs.h"

namespace DiskAnalyzer {

	list<Category> listOfFilesByCategories;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Interface
	/// </summary>
	public ref class Interface : public System::Windows::Forms::Form
	{
	public: Interface();
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Interface();
	private: System::Windows::Forms::Button^ folderChooseButton;
	private: System::Windows::Forms::Button^ categoriesChooseButton;
	private: System::Windows::Forms::TreeView^ catsAndExtsTree;
	private: System::Windows::Forms::DataGridView^ filesList;
	private: System::Windows::Forms::Button^ analyzeButton;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ nameColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ sizeColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ extensionColumns;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ pathColumn;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^ filesChart;
	private: System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog;

	private: System::ComponentModel::IContainer^ components;
		   /// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent();
#pragma endregion
	private: void InitializeCatsList();
	private: System::Void CategoriesChooseButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void FolderChooseButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AnalyzeButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void CatsAndExtsTree_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e);
	};
}