#pragma once

#include "Tile.h"
#include "ResetButton.h"
#include <random>
#include <ctime>
#include <cassert>

namespace Minesweeper {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	const int TILE_WIDTH = 21;
	const int TILE_HEIGHT = 20;
	const int FIELD_WIDTH = 25;
	const int FIELD_HEIGHT = 25;
	const int SPACE = 2;
	const int TOTAL_BOMBS = 120;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		int panelWidth;
		int panelHeight;
		int numBombs;
		int spaceLeft;
		int spaceRight;
		int startX;
		int tileArrayHeight;
		bool mouseDown;
		bool firstClick;
		bool gameOver;

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
		Bitmap^ bmpTile = gcnew Bitmap("updatedgraphics/notclickedredo.png");
		Bitmap^ bmp0 = gcnew Bitmap("updatedgraphics/clickedblankredo.png");
		Bitmap^ bmp1 = gcnew Bitmap("updatedgraphics/1redo.png");
		Bitmap^ bmp2 = gcnew Bitmap("updatedgraphics/2redo.png");
		Bitmap^ bmp3 = gcnew Bitmap("updatedgraphics/3redo.png");
		Bitmap^ bmp4 = gcnew Bitmap("updatedgraphics/4redo.png");
		Bitmap^ bmp5 = gcnew Bitmap("updatedgraphics/5redo.png");
		Bitmap^ bmp6 = gcnew Bitmap("updatedgraphics/6redo.png");
		Bitmap^ bmp7 = gcnew Bitmap("updatedgraphics/7redo.png");
		Bitmap^ bmp8 = gcnew Bitmap("updatedgraphics/8redo.png");
		Bitmap^ bmpFlag = gcnew Bitmap("updatedgraphics/flagredo.png");
		Bitmap^ mine = gcnew Bitmap("updatedgraphics/mine.png");
		Bitmap^ mineClicked = gcnew Bitmap("updatedgraphics/mineclicked.png");
		Bitmap^ resetButton = gcnew Bitmap("graphicsformine/resetbutton/resetunclicked.png");
		Bitmap^ resetButtonClicked = gcnew Bitmap("graphicsformine/resetbutton/resetclicked.png");
		Tile* tiles;
		ResetButton* myResetButton;
		SoundPlayer ^player;
		
		//Resets the tile field for when the user restarts the game
		void ResetField(){
			firstClick = true;
			gameOver = false;
			numBombs = 0;
			for (int i = 0; i < FIELD_WIDTH * FIELD_HEIGHT; i++){
				Tile *tile = &tiles[i];
				tile->ResetTile();
			}
		}

		//Return index of tile in tile array when the mouse is clicked
		int TileIndex(int mouseX, int mouseY){
			int totalWidth = (FIELD_WIDTH * TILE_WIDTH) + (SPACE * (FIELD_WIDTH - 1));
			int startX = (panelWidth / 2) - (totalWidth / 2);
			int tileX = startX;
			int tileY = 0;
			int indexX = 0;
			int indexY = 0;
			while (tileX + (TILE_WIDTH + SPACE) < mouseX){
				tileX += (TILE_WIDTH + SPACE);
				indexX++;
			}
			while (tileY + (TILE_HEIGHT + SPACE) < mouseY){
				tileY += (TILE_HEIGHT + SPACE);
				indexY++;
			}
			int tileIndex = (FIELD_WIDTH * indexY) + indexX;
			return tileIndex;
		}

		void RemoveMine(Tile *clickedTile){
			if (clickedTile != nullptr){
				clickedTile->setMine(false);
			}
		}

		void PlaceMines(Tile *clickedTile){
			while (numBombs < TOTAL_BOMBS){
				for (int i = 0; i < FIELD_WIDTH; i++){
					for (int j = 0; j < FIELD_HEIGHT; j++){
						Tile *currentTile = &tiles[(i * FIELD_WIDTH) + j];
						if (rand() % 10 == 0 && numBombs < TOTAL_BOMBS && !currentTile->getMine()){
							//Does not prevent clusters of 9 mines from being created,
							//Does not set a mine if current mine is surrounded
							//		if (!currentTile->isSurrounded()){
							currentTile->setMine(true);
							numBombs++;
							//		}
						}
					}
				}
				if (clickedTile->getMine()){
					clickedTile->setMine(false);
				}
				if (clickedTile->getAdjacentMines() != 0){
					RemoveMine(clickedTile->aboveLeftTile);
					RemoveMine(clickedTile->aboveTile);
					RemoveMine(clickedTile->aboveRightTile);
					RemoveMine(clickedTile->leftTile);
					RemoveMine(clickedTile->rightTile);
					RemoveMine(clickedTile->belowLeftTile);
					RemoveMine(clickedTile->belowTile);
					RemoveMine(clickedTile->belowRightTile);
				}
			}
		}

		//Create tile array, afterward randomly place mines
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
		//	PlaceMines();
		}

		//Draw the tiles onto the panel
		void DrawTiles(){
			int totalWidth = (FIELD_WIDTH * TILE_WIDTH) + (SPACE * (FIELD_WIDTH - 1));
			startX = (panelWidth / 2) - (totalWidth / 2);
			spaceLeft = startX;
			spaceRight = panelWidth - (((FIELD_WIDTH - 1) * (TILE_WIDTH + SPACE) + startX) + TILE_WIDTH);
			tileArrayHeight = (FIELD_HEIGHT - 1) * (TILE_HEIGHT + SPACE) + TILE_HEIGHT;
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

					currentTile->drawTile(gbmp, bmpTile, tileBitmap, bmpFlag, mine, mineClicked, currentTile->getX() * (TILE_WIDTH + SPACE) + startX, currentTile->getY() * (TILE_HEIGHT + SPACE));
				}
			}
		}

		//Reveal a tile when another tile is clicked if certain conditions are met
		void Iteration(Tile *tile){
			if (tile != NULL){
				if (!tile->getMine() && !tile->getFlag() && !tile->getRevealed()){
					tile->setRevealed(true);
					if (tile->getAdjacentMines() == 0){
						RevealTiles(tile);
					}
				}
			}
		}

		//Call Iteration function on tiles above, below, and to the left and right of the tile
		//When completed, a click should reveal an empty space surrounded by numbers
		void RevealTiles(Tile *tile){
			Iteration(tile->aboveTile);
			Iteration(tile->leftTile);
			Iteration(tile->rightTile);
			Iteration(tile->belowTile);

			Iteration(tile->aboveLeftTile);
			Iteration(tile->aboveRightTile);
			Iteration(tile->belowLeftTile);
			Iteration(tile->belowRightTile);

		}

		//When a mine is clicked and the game ends
		void RevealMines(){
			for (int i = 0; i < FIELD_WIDTH * FIELD_HEIGHT; i++){
				if (tiles[i].getMine()){
					tiles[i].setRevealed(true);
				}
			}
		}
		
		//Draw the reset button
		void DrawResetButton(){
			if (myResetButton->getToggled()){
				gbmp->DrawImage(resetButtonClicked, myResetButton->getX(), myResetButton->getY());
			}
			else{
				gbmp->DrawImage(resetButton, myResetButton->getX(), myResetButton->getY());
			}
		}

		//Show Dialog box
		void ShowDialogBox(){
			System::Windows::Forms::DialogResult result = MessageBox::Show(this, "Play again?", "Minesweeper", MessageBoxButtons::YesNoCancel);
			if (result == System::Windows::Forms::DialogResult::Yes){
				ResetField();
			}
			else if (result == System::Windows::Forms::DialogResult::No){
				exit(0);
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
				 firstClick = true;
				 gameOver = false;
				 CreateTiles();
				 myResetButton = new ResetButton((panelWidth / 2) - (resetButton->Width / 2), (panelHeight - resetButton->Height));
				 player = gcnew System::Media::SoundPlayer();
				 player->SoundLocation = "jeopardy.wav"; // Enables sound player
				 player->Play(); // Plays music
				 player->PlayLooping(); // Loops the music
				 
	}
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				// g->DrawImage(bmp2, 0, 0, 37, 36);
				 DrawTiles();
				 DrawResetButton();
				 g->DrawImage(view, Point(0, 0));
	}
	private: System::Void panel1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 mouseDown = true;
				 int mouseX = e->X;
				 int mouseY = e->Y;
				 
				 //Click Reset Button
				 if (e->Button == System::Windows::Forms::MouseButtons::Left){
					 if (myResetButton->getMouseHovering(mouseX, mouseY, resetButton->Width, resetButton->Height)){
						 myResetButton->setClicked(true);
						 myResetButton->setToggled(true);
						 panel1->Refresh();
					 }
				 }

				 //Click Tiles
				 if (e->Button == System::Windows::Forms::MouseButtons::Left){
					 if (!gameOver && mouseX >= spaceLeft && mouseY >= 0 && mouseX <= panelWidth - spaceRight && mouseY <= tileArrayHeight){
						 int tileIndex = TileIndex(mouseX, mouseY);
						 Tile *clickedTile = tiles + tileIndex;
						 if (!clickedTile->getRevealed() && !clickedTile->getFlag()){
							 if (!clickedTile->getMine()){
								 if (firstClick){
									 PlaceMines(clickedTile);
									 firstClick = false;
								 }
								 clickedTile->setRevealed(true);
								 //Reveal adjacent empty tiles ONLY if clicked tile has no surrounding mines
								 if (clickedTile->getAdjacentMines() == 0){
									 RevealTiles(clickedTile);
								 }
							 }
							 else{
								 clickedTile->setMineClicked(true);
								 RevealMines();
								 gameOver = true;
							 }
							 panel1->Refresh();
						 }
					 }
				 }
				 else if (e->Button == System::Windows::Forms::MouseButtons::Right){
					 if (!gameOver && mouseX >= spaceLeft && mouseY >= 0 && mouseX <= panelWidth - spaceRight && mouseY <= tileArrayHeight){
						 int tileIndex = TileIndex(mouseX, mouseY);
						 Tile *clickedTile = tiles + tileIndex;
						 if (!clickedTile->getRevealed()){
							 if (clickedTile->getFlag()){
								 clickedTile->setFlag(false);
							 }
							 else if (!clickedTile->getFlag()){
								 clickedTile->setFlag(true);
							 }
							 panel1->Refresh();
						 }
					 }
				 }
	}
private: System::Void panel1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 mouseDown = false;
	//		 if (myResetButton->getClicked()){
	//			 myResetButton->setClicked(false);
	//			 panel1->Refresh();
	//		 }
			 if (myResetButton->getToggled() || myResetButton->getClicked()){
				 myResetButton->setClicked(false);
				 myResetButton->setToggled(false);
				 ShowDialogBox();
				 panel1->Refresh();
			 }
}
private: System::Void panel1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 int mouseX = e->X;
			 int mouseY = e->Y;
			 if (mouseDown){
				 if (myResetButton->getMouseHovering(mouseX, mouseY, resetButton) && myResetButton->getClicked()){
					 if (!myResetButton->getToggled()){
						 myResetButton->setToggled(true);
						 panel1->Refresh();
					 }
				 }
				 else if (!myResetButton->getMouseHovering(mouseX, mouseY, resetButton) && myResetButton->getClicked()){
					 if (myResetButton->getToggled()){
						 myResetButton->setToggled(false);
						 panel1->Refresh();
					 }
				 }
			 }
}
};
}