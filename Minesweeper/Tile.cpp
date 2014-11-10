//Tile.cpp
//Tile definition file

#include "Tile.h"

//Default constructor
Tile::Tile(){
	Tile::hasBomb = false;
	Tile::hasFlag = false;
	Tile::hasBeenClicked = false;
	Tile::adjacentBombs = 0;
	Tile::x = 0;
	Tile::y = 0;
}

//Constructor sets hasBomb, x, y
Tile::Tile(bool hasBomb, int x, int y){
	Tile::hasBomb = hasBomb;
	Tile::hasFlag = false;
	Tile::hasBeenClicked = false;
	Tile::adjacentBombs = 0;
	Tile::x = x;
	Tile::y = y;
}
void Tile::setBomb(bool hasBomb){
	Tile::hasBomb = hasBomb;
}
void Tile::setFlag(bool hasFlag){
	Tile::hasFlag = hasFlag;
}
void Tile::setPosition(int x, int y){
	Tile::x = x;
	Tile::y = y;
}
int Tile::getAdjacentBombs() const{
	int numBombs = 0;
	return numBombs;
}
int Tile::getX() const{
	return Tile::x;
}
int Tile::getY() const{
	return Tile::y;
}
void Tile::setClick(bool hasBeenClicked){
	Tile::hasBeenClicked = hasBeenClicked;
}