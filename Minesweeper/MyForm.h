#pragma once

namespace Minesweeper {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void DrawPanel(){
			;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(600, 418);
			this->panel1->TabIndex = 0;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(624, 442);
			this->Controls->Add(this->panel1);
			this->MaximumSize = System::Drawing::Size(640, 480);
			this->MinimumSize = System::Drawing::Size(640, 480);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 Graphics^ g;
				 Bitmap^ bmp1 = gcnew Bitmap("graphicsformine/1.png");
				 Bitmap^ bmp2 = gcnew Bitmap("graphicsformine/2.png");
				 Bitmap^ bmp3 = gcnew Bitmap("graphicsformine/3.png");
				 Bitmap^ bmp4 = gcnew Bitmap("graphicsformine/4.png");
				 Bitmap^ bmp5 = gcnew Bitmap("graphicsformine/5.png");
				 Bitmap^ bmp6 = gcnew Bitmap("graphicsformine/6.png");
				 Bitmap^ bmp7 = gcnew Bitmap("graphicsformine/7.png");
				 Bitmap^ bmp8 = gcnew Bitmap("graphicsformine/8.png");
				 Bitmap^ bmp9 = gcnew Bitmap("graphicsformine/9.png");
				 g = this->CreateGraphics();
	}
	};
}
