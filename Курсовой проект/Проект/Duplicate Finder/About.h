#pragma once

namespace DuplicateFinder {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� About
	/// </summary>
	public ref class About : public System::Windows::Forms::Form
	{
	public:
		About(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~About()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  ab;
	protected:

	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ab = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// ab
			// 
			this->ab->Location = System::Drawing::Point(12, 9);
			this->ab->Name = L"ab";
			this->ab->Size = System::Drawing::Size(260, 69);
			this->ab->TabIndex = 0;
			this->ab->Text = L"��� ��������� ���� ���������� ������ � ��������� ���������� ������, ���� � �����"
				L"� ������. \r\n                        ������ ���� ��. 485\r\n                       "
				L"         ������ 1.1";
			// 
			// About
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 77);
			this->Controls->Add(this->ab);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"About";
			this->Text = L"� ���������";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
