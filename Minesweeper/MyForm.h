#pragma once

#include "Tile.h"

namespace Minesweeper {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	const int TILE_WIDTH = 37;
	const int TILE_HEIGHT = 36;
	const int FIELD_WIDTH = 8;
	const int FIELD_HEIGHT = 8;
	const int SPACE = 2;

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
				delete[] tiles;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;



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
		Tile* tiles;

		void CreateTiles(){
			tiles = new Tile[FIELD_WIDTH * FIELD_HEIGHT];
			for (int i = 0; i < FIELD_WIDTH; i++){
				for (int j = 0; j < FIELD_HEIGHT; j++){
					tiles[(i * FIELD_WIDTH) + j].setPosition(i, j);
					tiles[(i * FIELD_WIDTH) + j].setBomb(false);
				}
			}
		}

		void DrawTiles(Graphics^ g){
			for (int i = 0; i < FIELD_WIDTH; i++){
				for (int j = 0; j < FIELD_HEIGHT; j++){
					Tile currentTile = tiles[(i * FIELD_WIDTH) + j];
					g->DrawImage(bmp1, currentTile.getX() * (TILE_WIDTH + SPACE), currentTile.getY() * (TILE_HEIGHT + SPACE), 37, 36);
				}
			}
		}
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
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
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
				 g = panel1->CreateGraphics();
				 CreateTiles();
	}
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				// g->DrawImage(bmp2, 0, 0, 37, 36);
				 DrawTiles(g);
	}
	};
}