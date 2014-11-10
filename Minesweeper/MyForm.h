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
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;

	protected:

	private:
		Graphics^ g;
		Bitmap^ bmp1 = gcnew Bitmap("graphicsformine/1.png");
		Bitmap^ bmp2 = gcnew Bitmap("graphicsformine/2.png");
		Bitmap^ bmp3 = gcnew Bitmap("graphicsformine/3.png");
		Bitmap^ bmp4 = gcnew Bitmap("graphicsformine/4.png");
		Bitmap^ bmp5 = gcnew Bitmap("graphicsformine/5.png");
		Bitmap^ bmp6 = gcnew Bitmap("graphicsformine/6.png");
		Bitmap^ bmp7 = gcnew Bitmap("graphicsformine/7.png");
		Bitmap^ bmp8 = gcnew Bitmap("graphicsformine/8.png");
		Bitmap^ resetButton = gcnew Bitmap("graphicsformine/resetbutton/resetunclicked.png");
		Bitmap^ resetButtonClicked = gcnew Bitmap("graphicsformine/resetbutton/resetclicked.png");
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->pictureBox2);
			this->panel1->Location = System::Drawing::Point(12, 63);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(600, 367);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(522, 30);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(90, 27);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(3, 3);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(37, 36);
			this->pictureBox2->TabIndex = 0;
			this->pictureBox2->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(624, 442);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->panel1);
			this->MaximumSize = System::Drawing::Size(640, 480);
			this->MinimumSize = System::Drawing::Size(640, 480);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 g = panel1->CreateGraphics();
	}
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 g->DrawImage(bmp2, 0, 0, 37, 36);
	}
	};
}