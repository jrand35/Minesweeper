//ResetButton.h
//ResetButton declaration file

#ifndef RESETBUTTON_H
#define RESETBUTTON_H
using namespace System::Drawing;

class ResetButton{
private:
	int x;
	int y;
	bool isClicked;
	bool isToggled;

public:
	ResetButton();
	ResetButton(int x, int y);
	int getX() const;
	int getY() const;
	bool getClicked() const;
	bool getToggled() const;
	bool getMouseHovering(int mouseX, int mouseY, int bitmapWidth, int bitmapHeight) const;
	bool getMouseHovering(int mouseX, int mouseY, Bitmap^ bitmap) const;
	void setClicked(bool isClicked);
	void setToggled(bool isToggled);
};

#endif