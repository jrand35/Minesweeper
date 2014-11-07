//Tile.h
//Tile declaration file

#ifndef TILE_H
#define TILE_H

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
	int getAdjacentBombs() const;
	void setClick(bool hasBeenClicked);
};

#endif