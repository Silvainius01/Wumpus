/* Holds all in game graphical elements */
/*****************************************************************\
 *  The game elements and graphical elements linked so closely   *
 *  That it was really just easier to do some core GP functions  *
 *  in here as well. I plan on fixing this as soon as I can,     *
 *  so that I can quickly make the other three map sizes with no *
 *  problems.                                                    *
\*****************************************************************/

#include "Global.h"
#include "menu.h"
#include "game.h"
#include "fnct.h"
#include <cmath>;

const int BLERG = 5;

bool frst[8] = { 1, 1, 1, 1, 1, 1, 0, 1 };
bool see[BLERG] = { 0,0,0,0,0 };

float h;
float w;
float x;
float y;

char input;
char cN[16] = "###############";

/**********************************************\
 *  Every box has the following four points:  *
 *  TL: (baseX[], baseY[])                    *
 *  TR: (baseX[] + 26, baseY[])               *
 *  BL: (baseX[], baseY[] + 26)               *
 *  BR: (basex[] + 26, baseY[] + 26)          *
\**********************************************/

float getX(int a, int b)
{
	int baseX[3] = { 10, 37, 64 };
	switch (a)
	{
	case 0: //Player
		switch (b)
		{
		case 0: case 3: case 6:
			return xSpace(baseX[0] + 13, 100);
		case 1: case 4: case 7:
			return xSpace(baseX[1] + 13, 100);
		case 2: case 5: case 8:
			return xSpace(baseX[2] + 13, 100);
		}
		break;
	case 1:
		switch (b)
		{
		case 0: case 3: case 6:
			return xSpace(baseX[0] + 13, 100);
		case 1: case 4: case 7:
			return xSpace(baseX[1] + 13, 100);
		case 2: case 5: case 8:
			return xSpace(baseX[2] + 13, 100);
		}
		break;
	case 2:
		switch (b)
		{
		case 0: case 3: case 6:
			return xSpace(baseX[0] + 13, 100);
		case 1: case 4: case 7:
			return xSpace(baseX[1] + 13, 100);
		case 2: case 5: case 8:
			return xSpace(baseX[2] + 13, 100);
		}
		break;
	case 3: //torch
		switch (b)
		{
		case 0: case 3: case 6:
			return xSpace(baseX[0] + 25, 100);
		case 1: case 4: case 7:
			return xSpace(baseX[1] + 25, 100);
		case 2: case 5: case 8:
			return xSpace(baseX[2] + 25, 100);
		}
		break;
	case 4:
		switch (b)
		{
		case 0: case 3: case 6:
			return xSpace(baseX[0] + 13, 100);
		case 1: case 4: case 7:
			return xSpace(baseX[1] + 13, 100);
		case 2: case 5: case 8:
			return xSpace(baseX[2] + 13, 100);
		}
		break;
	default:
		break;
	}
}
float getY(int a, int b)
{
	int baseY[3] = { 8, 35, 62 };

	switch (a)
	{
	case 0: //Player
		switch (b)
		{
		case 0: case 1: case 2:
			return ySpace(baseY[2] + 13, 100);
		case 3: case 4: case 5:
			return ySpace(baseY[1] + 13, 100);
		case 6: case 7: case 8:
			return ySpace(baseY[0] + 13, 100);
		}
		break;
	case 1: //Wumpus
		switch (b)
		{
		case 0: case 1: case 2:
			return ySpace(baseY[2] + 13, 100);
		case 3: case 4: case 5:
			return ySpace(baseY[1] + 13, 100);
		case 6: case 7: case 8:
			return ySpace(baseY[0] + 13, 100);
		}
		break;
	case 2: //Chest
		switch (b)
		{
		case 0: case 1: case 2:
			return ySpace(baseY[2] + 13, 100);
		case 3: case 4: case 5:
			return ySpace(baseY[1] + 13, 100);
		case 6: case 7: case 8:
			return ySpace(baseY[0] + 13, 100);
		}
		break;
	case 3: //Torch
		switch (b)
		{
		case 0: case 1: case 2:
			return ySpace(baseY[2] + 25, 100);
		case 3: case 4: case 5:
			return ySpace(baseY[1] + 25, 100);
		case 6: case 7: case 8:
			return ySpace(baseY[0] + 25, 100);
		}
		break;
	case 4: //Mirror
		switch (b)
		{
		case 0: case 1: case 2:
			return ySpace(baseY[2] + 13, 100);
		case 3: case 4: case 5:
			return ySpace(baseY[1] + 13, 100);
		case 6: case 7: case 8:
			return ySpace(baseY[0] + 13, 100);
		}
		break;
	}
}
void drawEntSprite(Entity e)
{
	int sprite = e.getEntSprite();
	x = getX(e.getEntID(), e.getEntPos());
	y = getY(e.getEntID(), e.getEntPos());

	switch (sprite)
	{
	case 0: //Sword
		h = ySpace(6, 100);
		w = xSpace(3, 100);
		x -= w / 2;
		y -= h / 2;
		drawLine(x + (w / 2), y, x + (w / 3), y + (w / 5)); // Point - Left
		drawLine(x + (w / 3), y + (w / 5), x + (w / 3), y + ((h / 3) * 2)); //Left side, blade
		drawLine(x + (w / 2), y, x + ((w / 3) * 2), y + (w / 5)); //Point - Right
		drawLine(x + ((w / 3) * 2), y + (w / 5), x + ((w / 3) * 2), y + ((h / 3) * 2));//Right side, blade
		drawLine(x, y + ((h / 3) * 2), x + w, y + ((h / 3) * 2));//Guard
		drawLine(x + ((w / 5) * 2), y + ((h / 3) * 2), x + ((w / 5) * 2), y + h);//Left side, handle
		drawLine(x + ((w / 5) * 3), y + ((h / 3) * 2), x + ((w / 5) * 3), y + h);//Right side, handle
		drawLine(x + ((w / 5) * 2), y + h, x + ((w / 5) * 3) + 1, y + h);//Bot, handle
		break;
	case 1: //Wand (Looks bad, fix later [if at all, lol])
		h = ySpace(6, 100);
		w = xSpace(8, 100);
		x -= w / 2;
		y -= h / 2;
		drawLine(x, y + frac(h, 5, 6), x + frac(w, 50, 100), y + frac(h, 1, 2)); //Stick, top diag
		drawLine(x + frac(w, 15.67, 100), y + h, x + frac(w, 64, 100), y + frac(h, 62.33, 100)); //Stick, bot diag
		drawLine(x, y + frac(h, 5, 6), x + frac(w, 15.67, 100), y + h);//Stick, left diag
		drawChar('O', x + frac(w, 8.5, 17), y + frac(h, 3, 13), frac(h, 2, 5), frac(w, 2, 5));
		break;
	case 2: //Bow
		h = ySpace(5, 100);
		w = xSpace(5, 100);
		x -= w / 2;
		y -= h / 2;
		drawLine(x, y, x + frac(w, 1, 3), y); //top flat
		drawLine(x + frac(w, 1, 3), y, x + w, y + frac(h, 2, 3)); //Body
		drawLine(x + w, y + frac(h, 2, 3), x + w, y + h); //Right flat
		drawLine(x, y, x + w, y + h);//String
		drawLine(x + frac(w, 1, 5), y + frac(h, 4, 5), x + w, y); //Arrow shaft
		drawLine(x + w, y, x + frac(w, 4, 5), y); //Arrow tip top
		drawLine(x + w, y, x + w, y + frac(h, 1, 5)); //Arrow tip right
		drawLine(x + frac(w, 1, 5), y + frac(h, 4, 5), x, y + frac(h, 4, 5));//Fletching
		drawLine(x + frac(w, 1, 4), y + frac(h, 3, 4), x + frac(w, 1, 20), y + frac(h, 3, 4));//Fletching
		drawLine(x + frac(w, 1, 5), y + frac(h, 4, 5), x + frac(w, 1, 4), y + h);//Fletching
		drawLine(x + frac(w, 1, 4), y + frac(h, 3, 4), x + frac(w, 6, 20), y + frac(h, 19, 20));//Fletching
		break;
	case 3: //Wumpus
		h = ySpace(7, 100);
		w = xSpace(50, 100);
		x = xSpace(50, 100);
		y = ySpace(50, 100);
		//drawLine(x + w, y + h, x + (w / 2), y + h);
		//drawLine(x + w, y + h, x + w, y + frac(h, 1, 10));
		for (int a = 0; a < 180; a++)
		{
			drawLine(x, y, x + (a * (PI/180)) * 5, y + (a * (PI/180)) * 5);
		}
		break;
	case 4: //Chest
		break;
	case 5: //Torch
		h = ySpace(5, 100);
		w = xSpace(1, 100);
		x -= w;
		y -= h;
		drawBox(x, y + frac(h, 1, 5), frac(h, 4, 5), w);
		drawCircle(x + frac(w, 1, 2), y + frac(h, 1, 10), frac(h, 1, 10));
		break;
	case 6: //Mirror
		break;
	}
}
void drawEntSpriteReDir(int a)
{ //This was neccesary so I could have the draw in "menu.h" without redundant headers, or headers where they don't belong.
	switch (a)
	{
	case -1:
		drawEntSprite(e_Test);
		break;
	case 0:
		drawEntSprite(e_Player);
		break;
	case 1:
		drawEntSprite(e_Wumpus);
		break;
	case 2:
		drawEntSprite(e_Chest);
		break;
	}
}

bool drawGameMoveMenu(int dir)
{
	drawStringHor("PRESS A MOVE KEY", xSpace(26.5, 100), ySpace(91, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	if (dir != -1) { e_Player.entMove(dir); return true; }
	else { return false; }
}

void drawSeenEnts()
{
	if (see[0]) { drawEntSprite(e_Player); }
	if (see[1]) { drawEntSprite(e_Wumpus); }
	if (see[2]) { drawEntSprite(e_Chest); }
	if (see[3]) { drawEntSprite(e_Torch); }
	if (see[4]) { drawEntSprite(e_Mirror); }
}
void drawSelRoom(int choice)
{
	h = ySpace(10, 100);
	w = xSpace(10, 100);
	x = getX(0, choice);
	y = getY(0, choice);
	drawChar('X', x - (w / 2), y - (h / 2), h, w);
}

bool drawLookConfMenu(bool pSel)
{
	Entity e;

	drawStringHor("DONE", xSpace(44.5, 100), ySpace(91, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawBox(xSpace(43.5, 100), ySpace(90, 100), ySpace(8, 100), xSpace(13, 100));
	for (int a = 1; a < BLERG; a++)
	{
		e = getRefEnt(a);
		if (e.getEntPos() == e_Torch.getEntPos() || e.getEntPos() == e_Test.getEntPos()) { see[a] = true; }
	}

	drawSeenEnts();
	if (pSel) { return true; }
	else { return false; }
}
bool drawGameLookMenu(bool pSel)
{
	if (frst[2]) { frst[2] = false; sel = -1; }

	int room = e_Player.getEntPos();
	int choice = getMoveKeys(); //0123 || udlr

	drawStringHor("CHOOSE A ROOM", xSpace(31, 100), ySpace(91, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	
	switch (choice)
	{
	case 0:
		room += 3;
		if (room > 8) { room -= 3; }
		if (room == e_Player.getEntPos()) { room = sel; }
		sel = room;
		break;
	case 1:
		room -= 3;
		if (room < 0) { room += 3; }
		if (room == e_Player.getEntPos()) { room = sel; }
		sel = room;
		break;
	case 2:
		room--;
		if (room < 0 || room == 2 || room == 5) { room++; }
		if (room == e_Player.getEntPos()) { room = sel; }
		sel = room;
		break;
	case 3:
		room++;
		if (room == 3 || room == 6 || room > 8) { room--; }
		if (room == e_Player.getEntPos()) { room = sel; }
		sel = room;
		break;
	}

	drawSelRoom(sel);
	
	if (pSel) { e_Test.setEntPos(sel); return true; }
	else { return false; }
}

bool drawGameShootConf(bool pSel, int room1, int room2)
{
	if (frst[7]) { frst[7] = false, pSel = false; }

	bool won = false;
	bool loss = false;

	if (e_Wumpus.getEntPos() == room1 || e_Wumpus.getEntPos() == room2) { drawStringHor("YOU KILLED THE WUMPUS!   OKAY", xSpace(7, 100), ySpace(91, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100)); won = true; }
	else { drawStringHor("YOU MISSED THE WUMPUS!   OKAY", xSpace(7, 100), ySpace(91, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100)); loss = true; }
	drawBox(xSpace(81, 100), ySpace(90, 100), ySpace(8, 100), xSpace(13, 100));

	if (pSel && won) 
	{ 
		sel = 0;
		for (int a = 0; a < 8; a++) { frst[a] = true; }
		frst[6] = false;
		initEnts();
		bTemp = false;
		return true; 
	}
	if (pSel && loss) 
	{
		loss = false;
		sel = 0;
		frst[7] = true;
		frst[6] = false;
		frst[4] = true;
		frst[3] = true;
		return true; 
	}
	else { return false; }
}
bool drawGameShootMenu(bool pSel)
{
	if (frst[3]) { frst[3] = false; sel = -1; e_Test.setEntSprite(-1); }

	int room;
	int torch = e_Test.getEntSprite();
	int choice = getMoveKeys(); //0123 || udlr

	if (frst[4]) { room = e_Player.getEntPos(); }
	else { room = e_Test.getEntSprite(); }

	switch (choice)
	{
	case 0:
		room += 3;
		if (room > 8) { room -= 3; }
		if (room == e_Player.getEntPos()) { room = sel; }
		if (room == torch && torch != 1) { room = sel; }
		sel = room;
		break;
	case 1:
		room -= 3;
		if (room < 0) { room += 3; }
		if (room == e_Player.getEntPos()) { room = sel; }
		if (room == torch && torch != 1) { room = sel; }
		sel = room;
		break;
	case 2:
		room--;
		if (room < 0 || room == 2 || room == 5) { room++; }
		if (room == e_Player.getEntPos()) { room = sel; }
		if (room == torch && torch != 1) { room = sel; }
		sel = room;
		break;
	case 3:
		room++;
		if (room == 3 || room == 6 || room > 8) { room--; }
		if (room == e_Player.getEntPos()) { room = sel; }
		if (room == torch && torch != 1) { room = sel; }
		sel = room;
		break;
	}

	drawSelRoom(sel);
	if(!frst[4]) { drawSelRoom(torch); }

	if (frst[6]) { return drawGameShootConf(pSel, sel, torch); }

	if(frst[4]) { drawStringHor("CHOOSE A ROOM", xSpace(31, 100), ySpace(91, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100)); }
	else { drawStringHor("CHOOSE A SECOND ROOM", xSpace(20.5, 100), ySpace(91, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100)); }


	if (pSel) 
	{
		if (frst[4]) { frst[4] = false; e_Test.setEntSprite(sel); /*cout << e_Test.getEntSprite() << "(sprite); "; system("pause");*/ }
		else { e_Torch.setEntPos(sel); iTemp2 = torch; iTemp3 = sel; frst[6] = true; }
	}
	else { return false; }
}

bool drawCreateMenu()
{
	input = getLetInput();

	if (frst[0])
	{
		iTemp = 0;
		for (int a = 0; cN[a] != '\0'; a++) { cN[a] = '#'; }
		frst[0] = false;
	}

	drawStringHor("PLEASE ENTER YOUR NAME:", xSpace(1, 100), ySpace(8, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawChar('(', xSpace(1, 100), ySpace(14.5, 100), ySpace(14, 100), xSpace(2, 100));
	drawStringHor(" PRESS '|' TO HAVE A NAME", xSpace(4, 100), ySpace(15, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("SHORTER THAN 15 CHARACTERS", xSpace(4, 100), ySpace(22, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawChar(')', xSpace(81, 100), ySpace(14.5, 100), ySpace(14, 100), xSpace(2, 100));

	if (input == '|')
	{
		for (; cN[iTemp] != '\0'; iTemp++) { cN[iTemp] = ' '; }
	}
	else if (iTemp != 15)
	{
		cN[iTemp] = input;
		if (input != '#')
		{
			++iTemp;
		}
	}

	for (int a = 0, b = 1; cN[a] != '\0'; a++)
	{
		if (a != 0)
		{
			b += 3;
		}

		drawChar(cN[a], xSpace(b, 100), ySpace(30, 100), ySpace(6, 100), xSpace(2, 100));
	}

	if (cN[14] != '#')
	{
		e_Player.setEntName(cN);
		e_Player.setEntPos(4);
		e_Player.setEntSprite(2);
		return true;
	}

	return false;
}
void drawSelBoxTurn(int choice)
{
	switch (choice)
	{
	case 0:
		drawBox(xSpace(4, 100), ySpace(90, 100), ySpace(8, 100), xSpace(13, 100));
		break;
	case 1:
		drawBox(xSpace(25, 100), ySpace(90, 100), ySpace(8, 100), xSpace(16, 100));
		break;
	case 2:
		drawBox(xSpace(47, 100), ySpace(90, 100), ySpace(8, 100), xSpace(13, 100));
		break;
	case 3:
		drawBox(xSpace(67, 100), ySpace(90, 100), ySpace(8, 100), xSpace(28, 100));
		break;
	}
}
int drawTurnMenu(bool pSel)
{
	int choice = menuChoice(4, false);

	drawStringHor("MOVE", xSpace(5, 100), ySpace(91, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("SHOOT", xSpace(26, 100), ySpace(91, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("LOOK", xSpace(48, 100), ySpace(91, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawStringHor("INVENTORY", xSpace(68, 100), ySpace(91, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	drawSelBoxTurn(choice);

	if (pSel) { return choice; }
	else { return -1; }
}
void roomChecker()
{ //The purpose of this function is to draw the entities the player can see in their room.
	Entity e;

	for (int a = 0; a < BLERG; a++)
	{
		e = getRefEnt(a);
		if (e.getEntPos() == e_Player.getEntPos()) { see[a] = true; }
		else { see[a] = false; }
	}
}
int drawGame()
{
	int choice;

	roomChecker();
   /**********************************************\
	*  These three for loops draw the room boxes *
   \**********************************************/
	for (int a = 0, b = 10; a < 3; a++)
	{
		if (a != 0) { b += 27; } //(10, 27) || (37, 27) || (64, 27)
		drawBox(xSpace(b, 100), ySpace(8, 100), ySpace(26, 100), xSpace(26, 100));
	}
	for (int a = 0, b = 10; a < 3; a++)
	{
		if (a != 0) { b += 27; }
		drawBox(xSpace(b, 100), ySpace(35, 100), ySpace(26, 100), xSpace(26, 100));
	}
	for (int a = 0, b = 10; a < 3; a++)
	{
		if (a != 0) { b += 27; }
		drawBox(xSpace(b, 100), ySpace(62, 100), ySpace(26, 100), xSpace(26, 100));
	}
	drawSeenEnts();
	if (bTemp) { return iTemp; }
	choice = drawTurnMenu(checkSel());

	if (choice != -1 && !frst[1]) {	bTemp = true; iTemp = choice; }
	else if (frst[1]) { frst[1] = false; }

	if (!frst[2]) { frst[2] = true; }

	return choice;
}