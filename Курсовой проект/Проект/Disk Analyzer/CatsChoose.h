#pragma once

namespace DiskAnalyzer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ CatsChoose
	/// </summary>
	public ref class CatsChoose : public System::Windows::Forms::Form
	{
	public:
		CatsChoose();
		static String^ catOrExtToAdd = gcnew String("");
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~CatsChoose();
	private: System::Windows::Forms::TreeView^ treeView;
	private: System::Windows::Forms::Button^ addCategoryButton;
	private: System::Windows::Forms::Button^ addExtButton;
	private: System::Windows::Forms::Button^ deleteCatsOrExtsButton;
	private: System::Windows::Forms::Button^ resetButton;
	private: System::Windows::Forms::Button^ okButton;
	private: System::Windows::Forms::Button^ AbortButton;



	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeTreeView(const bool&);
		void InitializeComponent();
#pragma endregion
	private: System::Void deleteCatsOrExtsButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void treeView_AfterCheck(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e);
	private: void RemoveElemsFromTreeView();
	private: System::Void resetButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void okButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AbortButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void TreeView_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e);
	private: System::Void AddCategoryButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AddExtButton_Click(System::Object^ sender, System::EventArgs^ e);
	};
}