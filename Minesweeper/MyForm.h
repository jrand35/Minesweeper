#pragma once

#include "Tile.h"
#include "ResetButton.h"
#include <random>
#include <ctime>

namespace Minesweeper {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	const int TILE_WIDTH = 21;
	const int TILE_HEIGHT = 20;
	const int FIELD_WIDTH = 15;
	const int FIELD_HEIGHT = 15;
	const int SPACE = 2;
	const int TOTAL_BOMBS = 75;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		int panelWidth;
		int panelHeight;
		int numBombs;
		bool mouseDown;

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
		Graphics^ gbmp;
		Bitmap^ view;
		Bitmap^ bmpTile = gcnew Bitmap("graphicsformine/notclicked.png");
		Bitmap^ bmp0 = gcnew Bitmap("graphicsformine/clickedblank.png");
		Bitmap^ bmp1 = gcnew Bitmap("graphicsformine/1.png");
		Bitmap^ bmp2 = gcnew Bitmap("graphicsformine/2.png");
		Bitmap^ bmp3 = gcnew Bitmap("graphicsformine/3.png");
		Bitmap^ bmp4 = gcnew Bitmap("graphicsformine/4.png");
		Bitmap^ bmp5 = gcnew Bitmap("graphicsformine/5.png");
		Bitmap^ bmp6 = gcnew Bitmap("graphicsformine/6.png");
		Bitmap^ bmp7 = gcnew Bitmap("graphicsformine/7.png");
		Bitmap^ bmp8 = gcnew Bitmap("graphicsformine/8.png");
		Bitmap^ bomb = gcnew Bitmap("graphicsformine/bomb.png");
		Bitmap^ resetButton = gcnew Bitmap("graphicsformine/resetbutton/resetunclicked.png");
		Bitmap^ resetButtonClicked = gcnew Bitmap("graphicsformine/resetbutton/resetclicked.png");
		Tile* tiles;
		ResetButton* myResetButton;

		void CreateTiles(){
			//i = row, j = column
			tiles = new Tile[FIELD_WIDTH * FIELD_HEIGHT];
			for (int i = 0; i < FIELD_WIDTH; i++){
				for (int j = 0; j < FIELD_HEIGHT; j++){
					Tile *currentTile = &tiles[(i * FIELD_WIDTH) + j];
					currentTile->setPosition(j, i);
					currentTile->setMine(false);

					//Set nodes of tiles
					if (j > 0){	//If not at left side
						currentTile->leftTile = (currentTile - 1);	//Set node to left tile
						if (i > 0){	//If not at top side
							currentTile->aboveLeftTile = (currentTile - FIELD_WIDTH - 1);	//Set node to upper-left tile
							currentTile->aboveTile = (currentTile - FIELD_WIDTH);			//Set node to upper tile
						}
						if (i < FIELD_HEIGHT - 1){	//If not at bottom side
							currentTile->belowLeftTile = (currentTile + FIELD_WIDTH - 1);	//Set node to lower-left tile
							currentTile->belowTile = (currentTile + FIELD_WIDTH);			//Set node to lower tile
						}
					}
					if (j < FIELD_WIDTH - 1){	//If not at right side
						currentTile->rightTile = (currentTile + 1);	//Set node to right tile
						if (i > 0){	//If not at top side
							currentTile->aboveRightTile = (currentTile - FIELD_WIDTH + 1);	//Set node to upper-right tile
							currentTile->aboveTile = (currentTile - FIELD_WIDTH);			//Set node to upper tile (if not already set)
						}
						if (i < FIELD_HEIGHT - 1){	//If not at bottom side
							currentTile->belowRightTile = (currentTile + FIELD_WIDTH + 1);	//Set node to lower-right tile
							currentTile->belowTile = (currentTile + FIELD_WIDTH);			//Set node to lower tile (if not already set)
						}
					}
				}
			}
			while (numBombs < TOTAL_BOMBS){
				for (int i = 0; i < FIELD_WIDTH; i++){
					for (int j = 0; j < FIELD_HEIGHT; j++){
						Tile *currentTile = &tiles[(i * FIELD_WIDTH) + j];
						if (rand() % 10 == 0 && numBombs < TOTAL_BOMBS && !currentTile->getMine()){
							currentTile->setMine(true);
							numBombs++;
						}
					}
				}
			}
		}

		void DrawTiles(){
			int totalWidth = (FIELD_WIDTH * TILE_WIDTH) + (SPACE * (FIELD_WIDTH - 1));
			int startX = (panelWidth / 2) - (totalWidth / 2);
			for (int i = 0; i < FIELD_WIDTH; i++){
				for (int j = 0; j < FIELD_HEIGHT; j++){
					Tile *currentTile = &tiles[(i * FIELD_WIDTH) + j];
					Bitmap^ tileBitmap = bmp0;

					int numTiles = currentTile->getAdjacentMines();
					switch (numTiles){
					case 0:
						tileBitmap = bmp0;
						break;

					case 1:
						tileBitmap = bmp1;
						break;

					case 2:
						tileBitmap = bmp2;
						break;

					case 3:
						tileBitmap = bmp3;
						break;

					case 4:
						tileBitmap = bmp4;
						break;

					case 5:
						tileBitmap = bmp5;
						break;

					case 6:
						tileBitmap = bmp6;
						break;

					case 7:
						tileBitmap = bmp7;
						break;

					case 8:
						tileBitmap = bmp8;
						break;

					default:
						tileBitmap = bmp0;
						break;
					}

					currentTile->drawTile(g, tileBitmap, bomb, currentTile->getX() * (TILE_WIDTH + SPACE) + startX, currentTile->getY() * (TILE_HEIGHT + SPACE));
				}
			}
		}

		void DrawResetButton(){
			if (myResetButton->getClicked()){
				g->DrawImage(resetButtonClicked, myResetButton->getX(), myResetButton->getY());
			}
			else{
				g->DrawImage(resetButton, myResetButton->getX(), myResetButton->getY());
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(600, 578);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			this->panel1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseDown);
			this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseMove);
			this->panel1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseUp);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(624, 602);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(640, 640);
			this->MinimumSize = System::Drawing::Size(640, 640);
			this->Name = L"MyForm";
			this->Text = L"Minesweeper";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 panelWidth = (int)(this->panel1->Width);
				 panelHeight = (int)(this->panel1->Height);
				 numBombs = 0;
				 srand(time(0));
				 g = panel1->CreateGraphics();
				 view = gcnew Bitmap(panelWidth, panelHeight, System::Drawing::Imaging::PixelFormat::Format32bppArgb);
				 gbmp = Graphics::FromImage(view);
				 mouseDown = false;
				 CreateTiles();
				 myResetButton = new ResetButton((panelWidth / 2) - (resetButton->Width / 2), 100);
	}
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				// g->DrawImage(bmp2, 0, 0, 37, 36);
				 DrawTiles();
				 DrawResetButton();
	}
	private: System::Void panel1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 mouseDown = true;
				 int mouseX = e->X;
				 int mouseY = e->Y;
				 if (myResetButton->getMouseHovering(mouseX, mouseY, resetButton->Width, resetButton->Height)){
					 myResetButton->setClicked(true);
					 panel1->Refresh();
				 }
	}
private: System::Void panel1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 mouseDown = false;
			 if (myResetButton->getClicked()){
				 myResetButton->setClicked(false);
				 panel1->Refresh();
			 }
}
private: System::Void panel1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 int mouseX = e->X;
			 int mouseY = e->Y;
			 if (mouseDown){
				 if (myResetButton->getMouseHovering(mouseX, mouseY, resetButton) && !myResetButton->getClicked()){
					 myResetButton->setClicked(true);
					 panel1->Refresh();
				 }
				 else if (!myResetButton->getMouseHovering(mouseX, mouseY, resetButton) && myResetButton->getClicked()){
					 myResetButton->setClicked(false);
					 panel1->Refresh();
				 }
			 }
}
};
}