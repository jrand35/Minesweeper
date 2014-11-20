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
	bool hasBeenClicked;
	int adjacentBombs;
	int x;
	int y;

public:
	Tile();
	Tile(bool hasMine, int x, int y);
	void setMine(bool set);
	void setFlag(bool set);
	void setPosition(int x, int y);
	void drawTile(Graphics^ g, Bitmap^ b, Bitmap^ mineImg, int x, int y) const;
	bool getMine() const;
	bool isSurrounded() const;
	int getAdjacentMines() const;
	int getX() const;
	int getY() const;
	void setClick(bool hasBeenClicked);
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