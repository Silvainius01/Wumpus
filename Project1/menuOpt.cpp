#include "Global.h"
#include "menu.h"

float screenHeight[4] = { 0, 5, 0, 0 };
float screenWidth[4] = { 0, 5, 0, 0 };

char hA = '0', hB = '5', hC = '0', hD = '0';
char wA = '0', wB = '5', wC = '0', wD = '0';

bool aHeight = false, bHeight = false, cHeight = false, dHeight = false;
bool aWidth = false, bWidth = false, cWidth = false, dWidth = false;
bool first[4] = { 1,1,1,1 };

char cMove[5] = { 'W', 'S', 'A', 'D', ' ' };
bool bMove[5] = { 0, 0, 0, 0, 0 };

void drawSelBoxO(int choice)
{
	switch (choice)
	{
	case 0:
		drawBox(xSpace(34.5, 100), ySpace(49, 100), ySpace(8, 100), xSpace(31, 100));
		break;
	case 1:
		drawBox(xSpace(28.54, 100), ySpace(59, 100), ySpace(8, 100), xSpace(42.75, 100));
		break;
	case 2:
		drawBox(xSpace(37.5, 100), ySpace(69, 100), ySpace(8, 100), xSpace(24.75, 100));
		break;
	case 3:
		drawBox(xSpace(43.5, 100), ySpace(79, 100), ySpace(8, 100), xSpace(13, 100));
		break;
	}
}
int drawOptnMenu(bool pSel)
{
	int select;
	int choice = menuChoice(4, true);

	drawStringHor("OPTIONS", xSpace(25, 100), ySpace(33.33, 100), ySpace(6, 100), xSpace(2, 100), xSpace(6, 100));
	drawStringHor("DIFFICULTY", xSpace(35.5, 100), ySpace(50, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("RE-SIZE SCREEN", xSpace(29.54, 100), ySpace(60, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("CONTROLS", xSpace(38.5, 100), ySpace(70, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("BACK", xSpace(44.5, 100), ySpace(80, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));

	drawSelBoxO(choice);

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

void drawSelBoxDiff(int choice)
{
	switch (choice)
	{
	case 0:
		drawBox(xSpace(43.5, 100), ySpace(44, 100), ySpace(8, 100), xSpace(13, 100));
		break;
	case 1:
		drawBox(xSpace(40.5, 100), ySpace(54, 100), ySpace(8, 100), xSpace(19, 100));
		break;
	case 2:
		drawBox(xSpace(43.5, 100), ySpace(64, 100), ySpace(8, 100), xSpace(13, 100));
		break;
	case 3:
		drawBox(xSpace(43.5, 100), ySpace(74, 100), ySpace(8, 100), xSpace(13, 100));
		break;
	}
}
int drawDiffMenu(bool pSel)
{
	int select;
	int choice = menuChoice(4, true);

	drawStringHor("DIFFICULTY", xSpace(17.5, 100), ySpace(33.33, 100), ySpace(6, 100), xSpace(2, 100), xSpace(5, 100));
	drawStringHor("EASY", xSpace(44.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("NORMAL", xSpace(41.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("HARD", xSpace(44.5, 100), ySpace(65, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("BACK", xSpace(44.5, 100), ySpace(75, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));

	drawSelBoxDiff(choice);

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

void drawSelBoxScrn(int choice)
{
	switch (choice)
	{
	case 0:
		drawBox(xSpace(31.5, 100), ySpace(44, 100), ySpace(8, 100), xSpace(37, 100));
		break;
	case 1:
		drawBox(xSpace(31.5, 100), ySpace(54, 100), ySpace(8, 100), xSpace(37, 100));
		break;
	case 2:
		drawBox(xSpace(39, 100), ySpace(64, 100), ySpace(8, 100), xSpace(22, 100));
		break;
	case 3:
		drawBox(xSpace(43.5, 100), ySpace(74, 100), ySpace(8, 100), xSpace(13, 100));
		break;
	}
}
int drawScrnMenu(bool pSel)
{
	int select;
	int choice = menuChoice(4, true);

	drawStringHor("SCREEN SETTINGS", xSpace(28, 100), ySpace(33.33, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("WIDTH:", xSpace(32.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawChar(wA, xSpace(56.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));
	drawChar(wB, xSpace(59.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));
	drawChar(wC, xSpace(62.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));
	drawChar(wD, xSpace(65.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));
	drawStringHor("HEIGHT:", xSpace(32.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawChar(hA, xSpace(56.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100));
	drawChar(hB, xSpace(59.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100));
	drawChar(hC, xSpace(62.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100));
	drawChar(hD, xSpace(65.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100));
	drawStringHor("RE-SIZE", xSpace(40, 100), ySpace(65, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("BACK", xSpace(44.5, 100), ySpace(75, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawSelBoxScrn(choice);

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

void drawSelBoxScrnHW(int choice)
{
	switch (choice)
	{
	case 0:
		drawBox(xSpace(31.5, 100), ySpace(64, 100), ySpace(8, 100), xSpace(13, 100));
		break;
	case 1:
		drawBox(xSpace(50, 100), ySpace(64, 100), ySpace(8, 100), xSpace(25, 100));
		break;
	}
}

char setScreenHeight(int a)
{
	char cInput = getNumInput();
	if (cInput == 'n') { cInput = cTemp; }
	else { screenHeight[a] = fTemp; }
	return cInput;
}
bool drawScrnHMenu(bool pSel)
{
	if (first[0])
	{
		hA = '#';
		hB = '#';
		hC = '#';
		hD = '#';
		first[0] = false;
	}

	drawStringHor("SCREEN SETTINGS", xSpace(28, 100), ySpace(33.33, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("WIDTH:", xSpace(32.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("HEIGHT:", xSpace(32.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("OKAY", xSpace(32.5, 100), ySpace(65, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("RE-ENTER", xSpace(51, 100), ySpace(65, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("BACK", xSpace(44.5, 100), ySpace(75, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawBox(xSpace(31.5, 100), ySpace(54, 100), ySpace(8, 100), xSpace(37, 100));
	drawChar(wA, xSpace(56.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));
	drawChar(wB, xSpace(59.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));
	drawChar(wC, xSpace(62.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));
	drawChar(wD, xSpace(65.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));

	if (!aHeight)
	{
		cTemp = hA;
		hA = setScreenHeight(0);

		if (cTemp != hA)
		{
			aHeight = true;
		}

		drawChar(hA, xSpace(56.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(hB, xSpace(59.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(hC, xSpace(62.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(hD, xSpace(65.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100));
		return false;
	}
	else if (!bHeight)
	{
		cTemp = hB;
		hB = setScreenHeight(1);

		if (cTemp != hB)
		{
			bHeight = true;
		}

		drawChar(hA, xSpace(56.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(hB, xSpace(59.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(hC, xSpace(62.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(hD, xSpace(65.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100));
		return false;
	}
	else if (!cHeight)
	{
		cTemp = hC;
		hC = setScreenHeight(2);

		if (cTemp != hC)
		{
			cHeight = true;
		}

		drawChar(hA, xSpace(56.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(hB, xSpace(59.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(hC, xSpace(62.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(hD, xSpace(65.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100));
		return false;
	}
	else if (!dHeight)
	{
		cTemp = hD;
		hD = setScreenHeight(3);

		if (cTemp != hD)
		{
			dHeight = true;
		}

		drawChar(hA, xSpace(56.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(hB, xSpace(59.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(hC, xSpace(62.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(hD, xSpace(65.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100));
		return false;
	}
	else if (aHeight && bHeight && cHeight && dHeight)
	{
		drawSelBoxScrnHW(menuChoice(2, false));
		drawChar(hA, xSpace(56.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(hB, xSpace(59.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(hC, xSpace(62.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(hD, xSpace(65.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100));

		if (pSel && sel == 0)
		{
			aHeight = false;
			bHeight = false;
			cHeight = false;
			dHeight = false;
			first[0] = true;
			return true;
		}
		else if (pSel && sel == 1)
		{
			aHeight = false;
			bHeight = false;
			cHeight = false;
			dHeight = false;
			first[0] = true;
			return false;
		}
		else { return false; }
	}
}

char setScreenWidth(int a)
{
	char cInput = getNumInput();
	if (cInput == 'n') { cInput = cTemp; }
	else { screenWidth[a] = fTemp; }
	return cInput;
}
bool drawScrnWMenu(bool pSel)
{
	if (first[1])
	{
		wA = '#';
		wB = '#';
		wC = '#';
		wD = '#';
		first[1] = false;
	}

	drawStringHor("SCREEN SETTINGS", xSpace(28, 100), ySpace(33.33, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("WIDTH:", xSpace(32.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("HEIGHT:", xSpace(32.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("OKAY", xSpace(32.5, 100), ySpace(65, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("RE-ENTER", xSpace(51, 100), ySpace(65, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("BACK", xSpace(44.5, 100), ySpace(75, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawBox(xSpace(31.5, 100), ySpace(44, 100), ySpace(8, 100), xSpace(37, 100));
	drawChar(hA, xSpace(56.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100));
	drawChar(hB, xSpace(59.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100));
	drawChar(hC, xSpace(62.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100));
	drawChar(hD, xSpace(65.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100));

	if (!aWidth)
	{
		cTemp = wA;
		wA = setScreenWidth(0);

		if (cTemp != wA)
		{
			aWidth = true;
		}

		drawChar(wA, xSpace(56.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(wB, xSpace(59.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(wC, xSpace(62.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(wD, xSpace(65.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));
		return false;
	}
	else if (!bWidth)
	{
		cTemp = wB;
		wB = setScreenWidth(1);

		if (cTemp != wB)
		{
			bWidth = true;
		}

		drawChar(wA, xSpace(56.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(wB, xSpace(59.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(wC, xSpace(62.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(wD, xSpace(65.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));
		return false;
	}
	else if (!cWidth)
	{
		cTemp = wC;
		wC = setScreenWidth(2);

		if (cTemp != wC)
		{
			cWidth = true;
		}

		drawChar(wA, xSpace(56.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(wB, xSpace(59.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(wC, xSpace(62.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(wD, xSpace(65.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));
		return false;
	}
	else if (!dWidth)
	{
		cTemp = wD;
		wD = setScreenWidth(3);

		if (cTemp != wD)
		{
			dWidth = true;
		}

		drawChar(wA, xSpace(56.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(wB, xSpace(59.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(wC, xSpace(62.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(wD, xSpace(65.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));
		return false;
	}
	else if (aWidth && bWidth && cWidth && dWidth)
	{
		drawSelBoxScrnHW(menuChoice(2, false));
		drawChar(wA, xSpace(56.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(wB, xSpace(59.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(wC, xSpace(62.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));
		drawChar(wD, xSpace(65.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));

		if (pSel && sel == 0)
		{
			aWidth = false;
			bWidth = false;
			cWidth = false;
			dWidth = false;
			first[1] = true;
			return true;
		}
		else if (pSel && sel == 1)
		{
			aWidth = false;
			bWidth = false;
			cWidth = false;
			dWidth = false;
			first[1] = true;
			return false;
		}
		else { return false; }
	}
}

void resetChars()
{
	for (int a = 0; a < 5; a++) { cMove[a] = key[a + 10]; }
}
void setKeys()
{
	for (int a = 0; a < 5; a++) { key[a + 10] = cMove[a]; }
}
void drawSelBoxCont(int choice)
{
	switch (choice)
	{
	case 0:
		drawBox(xSpace(31.5, 100), ySpace(44, 100), ySpace(8, 100), xSpace(41.5, 100));
		break;
	case 1:
		drawBox(xSpace(31.5, 100), ySpace(54, 100), ySpace(8, 100), xSpace(38, 100));
		break;
	case 2:
		drawBox(xSpace(43.5, 100), ySpace(74, 100), ySpace(8, 100), xSpace(13, 100));
		break;
	}
}
int drawContMenu(bool pSel)
{
	int select;
	int choice = menuChoice(3, true);

	drawStringHor("CONTROLS", xSpace(38.5, 100), ySpace(33.33, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("MOVEMENT:", xSpace(32.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("SELECT:", xSpace(32.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("BACK", xSpace(44.5, 100), ySpace(75, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	for (int a = 0, b = 61.5; a < 4; ++a)
	{
		if (a != 0) { b += 3; }
		drawChar(cMove[a], xSpace(b, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));
	}
	if (cMove[4] == ' ') { drawStringHor("SPACE", xSpace(54.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100)); }
	else { drawChar(cMove[4], xSpace(66.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100)); }

	drawSelBoxCont(choice);

	if (pSel)
	{
		select = choice;
		if (choice == 2) { resetChars(); }
	}
	else
	{
		select = -1;
	}

	cout << "Choice: " << select << "; ";
	return select;
}

void resetMoveBools()
{
	first[2] = true;
	first[3] = true;
	for (int a = 0; a < 5; ++a) { bMove[a] = false; }
}
void drawSelBoxMove(int choice)
{
	switch (choice)
	{
	case 0:
		drawBox(xSpace(33.5, 100), ySpace(64, 100), ySpace(8, 100), xSpace(13, 100));
		break;
	case 1:
		drawBox(xSpace(54.5, 100), ySpace(64, 100), ySpace(8, 100), xSpace(25, 100));
		break;
	}
}
bool drawContMMenu(bool pSel)
{
	if (first[2])
	{
		for (int a = 0; a < 4; ++a)
		{
			cMove[a] = '#';
		}

		first[2] = false;
	}

	drawStringHor("CONTROLS", xSpace(34, 100), ySpace(33.33, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("MOVEMENT:", xSpace(32.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("SELECT:", xSpace(32.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("OKAY   RE-ENTER", xSpace(34.5, 100), ySpace(65, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("BACK", xSpace(44.5, 100), ySpace(75, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("U-D-L-R", xSpace(75, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawBox(xSpace(31.5, 100), ySpace(44, 100), ySpace(8, 100), xSpace(41.5, 100));
	if (cMove[4] == ' ') { drawStringHor("SPACE", xSpace(54.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100)); }
	else { drawChar(cMove[4], xSpace(66.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100)); }

	if (!bMove[0])
	{
		cMove[0] = getLetInput();
		if (cMove[0] != '#') { bMove[0] = true; }
	}
	else if (!bMove[1])
	{
		cMove[1] = getLetInput();
		if (cMove[1] != '#') { bMove[1] = true; }
	}
	else if (!bMove[2])
	{
		cMove[2] = getLetInput();
		if (cMove[2] != '#') { bMove[2] = true; }
	}
	else if (!bMove[3])
	{
		cMove[3] = getLetInput();
		if (cMove[3] != '#') { bMove[3] = true; }
	}
	else if (bMove[0] && bMove[1] && bMove[2] && bMove[3])
	{
		drawSelBoxMove(menuChoice(2, false));

		if (pSel && sel == 0)
		{
			return true;
		}
		else if(pSel && sel == 1)
		{
			resetMoveBools();
		}
	}

	for (int a = 0, b = 61.5; a < 4; ++a)
	{
		if (a != 0) { b += 3; }
		drawChar(cMove[a], xSpace(b, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));
	}

	return false;
}
bool drawContSMenu(bool pSel)
{
	if (first[3])
	{
		cMove[4] = '#';
		first[3] = false;
	}

	drawStringHor("CONTROLS", xSpace(34, 100), ySpace(33.33, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("MOVEMENT:", xSpace(32.5, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("SELECT:", xSpace(32.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("OKAY   RE-ENTER", xSpace(34.5, 100), ySpace(65, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("BACK", xSpace(44.5, 100), ySpace(75, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawBox(xSpace(31.5, 100), ySpace(54, 100), ySpace(8, 100), xSpace(38, 100));
	for (int a = 0, b = 61.5; a < 4; ++a)
	{
		if (a != 0) { b += 3; }
		drawChar(cMove[a], xSpace(b, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100));
	}

	if (!bMove[4])
	{
		cMove[4] = getLetInput();
		if (cMove[4] != '#') { bMove[4] = true; }
	}
	else
	{
		drawSelBoxMove(menuChoice(2, false));

		if (pSel && sel == 0)
		{
			return true;
		}
		else if (pSel && sel == 1)
		{
			resetMoveBools();
		}
	}

	if (cMove[4] == ' ') { drawStringHor("SPACE", xSpace(54.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100)); }
	else { drawChar(cMove[4], xSpace(66.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100)); }
	return false;
}

void drawSelBoxConf(int choice)
{
	switch (choice)
	{
	case 0:
		drawBox(xSpace(45, 100), ySpace(44, 100), ySpace(8, 100), xSpace(10, 100));
		break;
	case 1:
		drawBox(xSpace(46.5, 100), ySpace(54, 100), ySpace(8, 100), xSpace(7, 100));
		break;
	}
}
int drawConfMenu(bool pSel, int menu)
{
	int select;
	int choice = menuChoice(2, true);

	drawStringHor("ARE YOU SURE?", xSpace(31, 100), ySpace(33.33, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("YES", xSpace(46, 100), ySpace(45, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("NO", xSpace(47.5, 100), ySpace(55, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawSelBoxConf(choice);

	if (pSel)
	{
		select = choice;

		if (select == 0)
		{
			switch(menu)
			{
			case 0:
				break;
			case 1:
				setKeys();
				resetMoveBools();
				break;
			}
		}
		else
		{
			if(menu == 1)
			{
				resetMoveBools();
				resetChars();
			}
		}
	}
	else { select = -1; }

	return select;
}