//ResetButton.cpp
//ResetButton definition file

#include "ResetButton.h"

//Default constructor sets x and y position to 0
ResetButton::ResetButton() : x(0), y(0), isClicked(false) {
	;
}

ResetButton::ResetButton(int x, int y){
	ResetButton::x = x;
	ResetButton::y = y;
	isClicked = false;
}

int ResetButton::getX() const{
	return x;
}

int ResetButton::getY() const{
	return y;
}

bool ResetButton::getClicked() const{
	return isClicked;
}

void ResetButton::setClicked(bool isClicked){
	ResetButton::isClicked = isClicked;
}