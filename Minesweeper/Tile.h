//Tile.h
//Tile declaration file

#ifndef TILE_H
#define TILE_H

#include <iostream>
using namespace System::Drawing;

class Tile{
private:
	bool hasMine;
	bool hasFlag;
	bool hasBeenRevealed;
	bool mineClicked;
	int adjacentBombs;
	int x;
	int y;

public:
	Tile();
	Tile(bool hasMine, int x, int y);
	void setMine(bool set);
	void setFlag(bool set);
	void setPosition(int x, int y);
	void drawTile(Graphics^ g, Bitmap^ notClickedImg, Bitmap^ img, Bitmap^ flagImg, Bitmap^ mineImg, Bitmap^ mineClickedImg, int x, int y) const;
	void setRevealed(bool hasBeenRevealed);
	void setMineClicked(bool mineClicked);
	void ResetTile();
	bool getMine() const;
	bool getFlag() const;
	bool isSurrounded() const;
	bool getRevealed() const;
	int getAdjacentTiles() const;
	int getAdjacentMines() const;
	int getX() const;
	int getY() const;
	Tile *leftTile;
	Tile *rightTile;
	Tile *aboveTile;
	Tile *belowTile;
	Tile *aboveLeftTile;
	Tile *aboveRightTile;
	Tile *belowLeftTile;
	Tile *belowRightTile;
};

#endif