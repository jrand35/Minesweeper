//Tile.h
//Tile declaration file

#ifndef TILE_H
#define TILE_H
using namespace System::Drawing;

class Tile{
private:
	bool hasBomb;
	bool hasFlag;
	bool hasBeenClicked;
	int adjacentBombs;
	int x;
	int y;

public:
	Tile();
	Tile(bool hasBomb, int x, int y);
	void setBomb(bool set);
	void setFlag(bool set);
	void setPosition(int x, int y);
	void drawTile(Graphics^ g, Bitmap^ b, Bitmap^ bombImg, int x, int y) const;
	bool getBomb() const;
	int getAdjacentBombs() const;
	int getX() const;
	int getY() const;
	void setClick(bool hasBeenClicked);
};

#endif