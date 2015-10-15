#include "Global.h"
#include "menu.h"

void drawSelBoxP(int choice)
{
	switch (choice)
	{
	case 0:
		drawBox(xSpace(33, 100), ySpace(49, 100), ySpace(8, 100), xSpace(34, 100));
		break;
	case 1:
		drawBox(xSpace(31.75, 100), ySpace(59, 100), ySpace(8, 100), xSpace(36.75, 100));
		break;
	case 2:
		drawBox(xSpace(31.75, 100), ySpace(69, 100), ySpace(8, 100), xSpace(36.75, 100));
		break;
	case 3:
		drawBox(xSpace(37.5, 100), ySpace(79, 100), ySpace(8, 100), xSpace(24.75, 100));
		break;
	case 4:
		drawBox(xSpace(43.5, 100), ySpace(89, 100), ySpace(8, 100), xSpace(13, 100));
		break;
	}
}

int drawPlayMenu(bool pSel)
{
	int select;
	int choice = menuChoice(5, true);

	drawStringHor("PLAY", xSpace(44.5 , 100), ySpace(33.33, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("9-ROOM GAME", xSpace(34, 100), ySpace(50, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("16-ROOM GAME", xSpace(32.5, 100), ySpace(60, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("25-ROOM GAME", xSpace(32.5, 100), ySpace(70, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("TUTORIAL", xSpace(38.5, 100), ySpace(80, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("BACK", xSpace(44.5, 100), ySpace(90, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));

	drawSelBoxP(choice);

	if (pSel)
	{
		select = choice;
	}
	else
	{
		select = -1;
	}

	cout << "Choice: " << select << "; ";
	return select;
}