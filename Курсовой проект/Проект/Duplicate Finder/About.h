#pragma once

namespace DuplicateFinder {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для About
	/// </summary>
	public ref class About : public System::Windows::Forms::Form
	{
	public:
		About(void)
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
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
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
			this->ab->Text = L"Эта программа ищет друбликаты файлов с заданными критериями поиска, путём и типам"
				L"и файлов. \r\n                        Зобнин Илья гр. 485\r\n                       "
				L"         Версия 1.1";
			// 
			// About
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 77);
			this->Controls->Add(this->ab);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"About";
			this->Text = L"О программе";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
