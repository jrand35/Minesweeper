//ResetButton.h
//ResetButton declaration file

#ifndef RESETBUTTON_H
#define RESETBUTTON_H

class ResetButton{
private:
	int x;
	int y;
	bool isClicked;

public:
	ResetButton();
	ResetButton(int x, int y);
	int getX() const;
	int getY() const;
	bool getClicked() const;
	void setClicked(bool isClicked);
};

#endif