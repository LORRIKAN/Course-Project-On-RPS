#pragma once

namespace DiskAnalyzer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� AddCatOrExt
	/// </summary>
	public ref class AddCatOrExt : public System::Windows::Forms::Form
	{
	public:
		AddCatOrExt(void);
	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~AddCatOrExt();
	private: System::Windows::Forms::Button^ abortButton;
	private: System::Windows::Forms::Button^ okButton;
	private: System::Windows::Forms::TextBox^ textBox;
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void);
#pragma endregion
	private: System::Void OkButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AbortButton_Click(System::Object^ sender, System::EventArgs^ e);
	public: void AddCategory();
	public: void AddExtension();
	private: System::Void textBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
	private: void ExportCatOrExt();

	};
}
