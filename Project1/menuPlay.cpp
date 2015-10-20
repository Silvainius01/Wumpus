#include "Global.h"
#include "menu.h"

void drawSelBoxP(int choice)
{
	switch (choice)
	{
	case 0:
		drawBox(xSpace(33, 100), ySpace(42, 100), ySpace(8, 100), xSpace(34, 100));
		break;
	case 1:
		drawBox(xSpace(31.75, 100), ySpace(52, 100), ySpace(8, 100), xSpace(36.75, 100));
		break;
	case 2:
		drawBox(xSpace(31.75, 100), ySpace(62, 100), ySpace(8, 100), xSpace(36.75, 100));
		break;
	case 3:
		drawBox(xSpace(37.5, 100), ySpace(72, 100), ySpace(8, 100), xSpace(24.75, 100));
		break;
	case 4:
		drawBox(xSpace(43.5, 100), ySpace(82, 100), ySpace(8, 100), xSpace(13, 100));
		break;
	case 5:
		drawBox(xSpace(43.5, 100), ySpace(92, 100), ySpace(8, 100), xSpace(13, 100));
		break;
	}
}

int drawPlayMenu(bool pSel)
{
	int select;
	int choice = menuChoice(5, true);

	drawStringHor("PLAY", xSpace(44.5 , 100), ySpace(33.33, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("9-ROOM GAME", xSpace(34, 100), ySpace(43, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("16-ROOM GAME", xSpace(32.5, 100), ySpace(53, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("25-ROOM GAME", xSpace(32.5, 100), ySpace(63, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("TUTORIAL", xSpace(38.5, 100), ySpace(73, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("LOAD", xSpace(44.5, 100), ySpace(83, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("BACK", xSpace(44.5, 100), ySpace(93, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));

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