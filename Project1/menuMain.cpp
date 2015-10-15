/* Holds the main menu */

#include "Global.h"
#include "menu.h"

void drawSelBoxM(int choice)
{
	switch (choice)
	{
	case 0:
		drawBox(xSpace(43.5, 100), ySpace(49, 100), ySpace(8, 100), xSpace(13, 100));
		break;
	case 1:
		drawBox(xSpace(39, 100), ySpace(59, 100), ySpace(8, 100), xSpace(22, 100));
		break;
	case 2:
		drawBox(xSpace(43.5, 100), ySpace(69, 100), ySpace(8, 100), xSpace(13, 100));
		break;
	}
}

int drawMainMenu(bool pSel)
{
	int select;
	int choice = menuChoice(3, true);

	drawStringHor("WUMPUS", xSpace(25, 100), ySpace(33.33, 100), ySpace(6, 100), xSpace(2, 100), xSpace(8, 100));
	drawStringHor("REBORN", xSpace(25, 100), ySpace(40.33, 100), ySpace(6, 100), xSpace(2, 100), xSpace(8, 100));
	drawStringHor("PLAY", xSpace(44.5, 100), ySpace(50, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("OPTIONS", xSpace(40, 100), ySpace(60, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("EXIT", xSpace(44.5, 100), ySpace(70, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));

	drawSelBoxM(choice);

	if (pSel)
	{
		select = choice;
	}
	else
	{
		select = -1;
	}

	return select;
}