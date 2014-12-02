//Tile.cpp
//Tile definition file

#include "Tile.h"
using namespace System::Drawing;

//Default constructor
Tile::Tile(){
	Tile::hasMine = false;
	Tile::hasFlag = false;
	Tile::hasBeenRevealed = false;
	Tile::mineClicked = false;
	Tile::adjacentBombs = 0;
	Tile::x = 0;
	Tile::y = 0;

	leftTile = NULL;
	rightTile = NULL;
	aboveTile = NULL;
	belowTile = NULL;
	aboveLeftTile = NULL;
	aboveRightTile = NULL;
	belowLeftTile = NULL;
	belowRightTile = NULL;
}

//Constructor sets hasBomb, x, y
Tile::Tile(bool hasMine, int x, int y){
	Tile::hasMine = hasMine;
	Tile::hasFlag = false;
	Tile::hasBeenRevealed = false;
	Tile::mineClicked = false;
	Tile::adjacentBombs = 0;
	Tile::x = x;
	Tile::y = y;

	leftTile = NULL;
	rightTile = NULL;
	aboveTile = NULL;
	belowTile = NULL;
	aboveLeftTile = NULL;
	aboveRightTile = NULL;
	belowLeftTile = NULL;
	belowRightTile = NULL;
}

void Tile::setMine(bool hasMine){
	Tile::hasMine = hasMine;
}

void Tile::setFlag(bool hasFlag){
	Tile::hasFlag = hasFlag;
}

void Tile::setPosition(int x, int y){
	Tile::x = x;
	Tile::y = y;
}

void Tile::drawTile(Graphics^ g, Bitmap^ notClickedImg, Bitmap^ img, Bitmap^ flagImg, Bitmap^ mineImg, Bitmap^ mineClickedImg, int x, int y) const{
	//Post: Should draw tile graphic OR mine graphic
	if (!hasBeenRevealed){
		if (hasFlag){
			g->DrawImage(flagImg, x, y);
		}
		else{
			g->DrawImage(notClickedImg, x, y);
		}
	}
	else{
		if (hasMine){
			if (mineClicked){
				g->DrawImage(mineClickedImg, x, y);
			}
			else{
				g->DrawImage(mineImg, x, y);
			}
		}
		else{
			g->DrawImage(img, x, y);
		}
	}
}

void Tile::setRevealed(bool hasBeenRevealed){
	Tile::hasBeenRevealed = hasBeenRevealed;
}

void Tile::setMineClicked(bool mineClicked){
	Tile::mineClicked = mineClicked;
}

bool Tile::getMine() const{
	return hasMine;
}

bool Tile::getFlag() const{
	return hasFlag;
}

bool Tile::isSurrounded() const{
	return (getAdjacentMines() == getAdjacentTiles());
}

bool Tile::getRevealed() const{
	return hasBeenRevealed;
}

int Tile::getAdjacentTiles() const{
	int numTiles = 0;

	if (leftTile != NULL)
		numTiles++;
	if (rightTile != NULL)
		numTiles++;
	if (aboveTile != NULL)
		numTiles++;
	if (belowTile != NULL)
		numTiles++;
	if (aboveLeftTile != NULL)
		numTiles++;
	if (aboveRightTile != NULL)
		numTiles++;
	if (belowLeftTile != NULL)
		numTiles++;
	if (belowRightTile != NULL)
		numTiles++;

	return numTiles;
}

int Tile::getAdjacentMines() const{
	int numBombs = 0;
	if (aboveLeftTile != NULL){	//Top-left of base
		if (aboveLeftTile->getMine()){
			numBombs++;
		}
	}

	if (aboveTile != NULL){	//Top of base
		if (aboveTile->getMine()){
			numBombs++;
		}
	}

	if (aboveRightTile != NULL){	//Top-right of base
		if (aboveRightTile->getMine()){
			numBombs++;
		}
	}

	if (leftTile != NULL){	//Left of base
		if (leftTile->getMine()){
			numBombs++;
		}
	}

	if (rightTile != NULL){	//Right of base
		if (rightTile->getMine()){
			numBombs++;
		}
	}

	if (belowLeftTile != NULL){	//Bottom-left of base
		if (belowLeftTile->getMine()){
			numBombs++;
		}
	}

	if (belowTile != NULL){	//Bottom of base
		if (belowTile->getMine()){
			numBombs++;
		}
	}

	if (belowRightTile != NULL){	//Bottom-right of base
		if (belowRightTile->getMine()){
			numBombs++;
		}
	}
	return numBombs;
}

int Tile::getX() const{
	return Tile::x;
}

int Tile::getY() const{
	return Tile::y;
}