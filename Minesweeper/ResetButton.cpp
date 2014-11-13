//ResetButton.cpp
//ResetButton definition file

#include "ResetButton.h"
using namespace System::Drawing;

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

bool ResetButton::getMouseHovering(int mouseX, int mouseY, int bitmapWidth, int bitmapHeight) const{
	return (mouseX >= getX() && mouseX <= getX() + bitmapWidth &&
		mouseY >= getY() && mouseY <= getY() + bitmapHeight);
}

bool ResetButton::getMouseHovering(int mouseX, int mouseY, Bitmap^ bitmap) const{
	return (mouseX >= getX() && mouseX <= getX() + bitmap->Width &&
		mouseY >= getY() && mouseY <= getY() + bitmap->Height);
}

void ResetButton::setClicked(bool isClicked){
	ResetButton::isClicked = isClicked;
}