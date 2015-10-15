/* Holds menu drawing functions */

#include "Global.h"
#include "menu.h"
#include "fnct.h"

float SCREEN_X = 500;
float SCREEN_Y = 500;

char fuckingHell[] = "'";

float setScreenWidth()
{
	return (screenWidth[0] * 1000) + (screenWidth[1] * 100) + (screenWidth[2] * 10) + screenWidth[3];
}

float setScreenHeight()
{
	return (screenHeight[0] * 1000) + (screenHeight[1] * 100) + (screenHeight[2] * 10) + screenHeight[3];
}

/* Allows for scaling positions/sizes for the UI on the X-Axis */
float xSpace(float num, float den)
{
	float space = ((SCREEN_X / den) * num);
	return space;
}

/* Allows for scaling positions/sizes for the UI on the Y-Axis */
float ySpace(float num, float den)
{
	float space = ((SCREEN_Y / den) * num);
	return space;
}

/*******************************************************************
* IMPORTTANT NOTE:                                                *
*                                                                 *
*  This function was desined to print at a 3:1 h/w ratio!         *
*  While it CAN print other ratios, they might not look as good!  *
*******************************************************************/
void drawChar(char a, float x, float y, float h, float w)
{
	if (a == fuckingHell[0]) { a = '"'; }

	switch (a)
	{
	case 'A':
		drawLine(x, y + h, x + (w / 2), y); //Left Diag
		drawLine(x + w, y + h, x + (w / 2), y); //Right diag
		drawLine(x + (w / 4), y + (h / 2), x + ((w / 4) * 3), y + (h / 2)); //Center Line
		break;
	case 'B':
		drawLine(x, y, x, y + h); //spine
		drawLine(x, y, x + (w / 4), y); //Top-Top flat
		drawLine(x + (w / 4), y, x + w, y + (h / 6)); //Top-Top Diag
		drawLine(x + w, y + (h / 6), x + w, y + ((h / 6) * 2)); //Top-Left flat
		drawLine(x + w, y + ((h / 6) * 2), x + (w / 4), y + ((h / 6) * 3));//Top-Bot diag
		drawLine(x, y + (h / 2), x + (w / 4), y + (h / 2)); //Mid Flat
		drawLine(x + (w / 4), y + ((h / 6) * 3), x + w, y + ((h / 6) * 4)); //Bot-Top diag
		drawLine(x + w, y + ((h / 6) * 4), x + w, y + ((h / 6) * 5)); //Bot-Left flat
		drawLine(x + w, y + ((h / 6) * 5), x + (w / 4), y + ((h / 6) * 6)); //Bot-Bot diag
		drawLine(x, y + h, x + (w / 4), y + h); //Bot-Bot flat
		break;
	case 'C':
		drawLine(x + w, y, x + ((w / 3) * 2), y); // 2/3 -> 1/3 //Top flat
		drawLine(x, y + (h / 3), x + ((w / 3) * 2), y); //top-spine connector
		drawLine(x, y + (h / 3), x, y + ((h / 3) * 2)); //Spine
		drawLine(x, y + ((h / 3) * 2), x + ((w / 3) * 2), y + h); //spine-bot connector
		drawLine(x + ((w / 3) * 2), y + h, x + w, y + h); //Bot flat
		break;
	case 'D':
		drawLine(x, y, x, y + h); //spine
		drawLine(x, y, x + (w / 4), y); //Top flat
		drawLine(x + (w / 4), y, x + w, y + ((h / 7) * 2)); //Top-Sode connector
		drawLine(x + w, y + ((h / 7) * 2), x + w, y + ((h / 7) * 5)); //right side
		drawLine(x + w, y + ((h / 7) * 5), x + (w / 4), y + h); //bot- Side connector
		drawLine(x, y + h, x + (w / 4), y + h); //bot flat
		break;
	case 'E':
		drawLine(x, y, x + w, y); //Top flat
		drawLine(x, y, x, y + h - 1); //Spine
		drawLine(x, y + (h / 2), x + (w / 2), y + (h / 2)); //Mid flat
		drawLine(x, y + h - 1, x + w, y + h - 1); //bot flat
		break;
	case 'F':
		drawLine(x, y, x + w, y); //Top flat
		drawLine(x, y, x, y + h); //spine
		drawLine(x, y + (h / 2), x + ((w / 3) * 2), y + (h / 2)); //Mid Flat
		break;
	case 'G': //Note to self: ,ake it fancier
		drawLine(x, y, x + w, y); //top flat
		drawLine(x, y, x, y + h); //Spine
		drawLine(x, y + h - 1, x + w, y + h - 1); //bot flat
		drawLine(x + w, y + h - 1, x + w, y + (h / 2)); //right side
		drawLine(x + w, y + (h / 2), x + (w / 2), y + (h / 2)); //Center "G-line"
		break;
	case 'H':
		drawLine(x, y, x, y + h); //Left side
		drawLine(x + w, y, x + w, y + h); //Right side
		drawLine(x, y + (h / 2), x + w, y + (h / 2)); //Center flat
		break;
	case 'I':
		drawLine(x, y, x + w, y); //Top flat
		drawLine(x + (w / 2), y, x + (w / 2), y + h); //Spine
		drawLine(x, y + h, x + w, y + h); //bot flat
		break;
	case 'J':
		drawLine(x + w, y, x + w, y + ((h / 4) * 3)); //Spine
		drawLine(x + w, y + ((h / 4) * 3), x + ((w / 3) * 2), y + h); //spine-bot connecotr
		drawLine(x + ((w / 3) * 2), y + h, x + (w / 3), y + h); //Bot flat
		drawLine(x, y + ((h / 4) * 3), x + (w / 3), y + h); //Hook
		break;
	case 'K':
		drawLine(x, y, x, y + h); //Spine
		drawLine(x, y + (h / 2), x + w, y); //Top diag
		drawLine(x, y + (h / 2), x + w, y + h); //Bot diag
		break;
	case 'L':
		drawLine(x, y, x, y + h); //Spine
		drawLine(x, y + h - 1, x + w, y + h - 1); //bot Flat
		break;
	case 'M':
		drawLine(x, y, x, y + h); //Left side
		drawLine(x + w, y, x + w, y + h); //Left-Mid diag
		drawLine(x, y, x + (w / 2), y + (h / 2));//Right-Mid Diag
		drawLine(x + (w / 2), y + (h / 2), x + w, y); //Right side
		break;
	case 'N':
		drawLine(x, y, x, y + h); //Left side
		drawLine(x + w, y, x + w, y + h);//Left-Right diag
		drawLine(x, y, x + w, y + h);//Right diag
		break;
	case 'O':
		drawLine(x + (w / 3) + 1, y, x + ((w / 3) * 2), y); //Top flat
		drawLine(x, y + (h / 3), x, y + ((h / 3) * 2)); //Left flat
		drawLine(x + w, y + (h / 3), x + w, y + ((h / 3) * 2)); //right flat
		drawLine(x + (w / 3), y + h, x + ((w / 3) * 2), y + h); // bot flat
		drawLine(x + (w / 3), y + 1, x, y + (h / 3)); //T-L connector
		drawLine(x, y + ((h / 3) * 2), x + (w / 3), y + h); //L-B Connector
		drawLine(x + ((w / 3) * 2), y + 1, x + w, y + (h / 3)); //T-R Connector
		drawLine(x + w, y + ((h / 3) * 2), x + ((w / 3) * 2), y + h); //R-B Connector
		break;
	case 'P': //Note to self: make it fancier
		drawLine(x, y, x, y + h); //Spine
		drawLine(x, y, x + w, y); //top flat
		drawLine(x + w, y, x + w, y + (h / 3)); //right side
		drawLine(x + w, y + (h / 3), x, y + (h / 3)); //Mid flat
		break;
	case 'Q':
		drawChar('O', x, y, h, w);//lel
		drawLine(x + (w / 2), y + ((h / 3) * 2), x + w, y + h); //Slicer diag
		break;
	case 'R':
		drawChar('P', x, y, h, w); //lel
		drawLine(x + ((w / 3) * 2), y + (h / 3), x + w, y + h); //Mid-Bot diag
		break;
	case 'S':
		drawLine(x + (w / 3), y, x + w, y); //Top flat
		drawLine(x + (w / 3), y, x, y + (h / 4)); //T-L connector
		drawLine(x, y + (h / 4), x, y + (h / 3)); //Left side
		drawLine(x, y + (h / 3), x + (w / 3), y + (h / 2) + 1); //L-M Connector
		drawLine(x + (w / 3), y + (h / 2), x + ((w / 3) * 2), y + (h / 2)); //mid flat
		drawLine(x + ((w / 3) * 2), y + (h / 2), x + w, y + ((h / 4) * 3) - 1); //M-R Connector
		drawLine(x + w, y + ((h / 4) * 3), x + w, y + ((h / 3) * 2)); //Right side
		drawLine(x + w, y + ((h / 4) * 3), x + ((w / 3) * 2), y + h); //R-B Connector
		drawLine(x + ((w / 3) * 2), y + h, x, y + h); //Bot flat
		break;
	case 'T':
		drawLine(x, y, x + w, y); //Top flat
		drawLine(x + (w / 2), y, x + (w / 2), y + h); //Spine
		break;
	case 'U':
		drawLine(x, y, x, y + ((h / 3) * 2)); //left side
		drawLine(x, y + ((h / 3) * 2), x + (w / 3) - 1, y + h); //L-B Connector
		drawLine(x + (w / 3), y + h, x + ((w / 3) * 2) + 1, y + h); //Bot flat
		drawLine(x + w, y + ((h / 3) * 2), x + ((w / 3) * 2) + 1, y + h);//R-B connector
		drawLine(x + w, y, x + w, y + ((h / 3) * 2)); //Right side
		break;
	case 'V':
		drawLine(x, y, x + (w / 2), y + h);//Left diag
		drawLine(x + w, y, x + (w / 2), y + h); //Right Diag
		break;
	case 'W':
		drawLine(x, y, x, y + h);//Left side
		drawLine(x, y + h, x + (w / 2), y + (h / 2)); //left diag
		drawLine(x + w, y + h, x + (w / 2), y + (h / 2));//Right diag
		drawLine(x + w, y, x + w, y + h);//Right side
		break;
	case 'X':
		drawLine(x, y, x + w, y + h); //Left diag
		drawLine(x + w, y, x, y + h); //Right diag
		break;
	case 'Y':
		drawLine(x, y, x + (w / 2), y + (h / 2));//Left diag
		drawLine(x + w, y, x + (w / 2), y + (h / 2));//Right diag
		drawLine(x + (w / 2), y + (h / 2), x + (w / 2), y + h); //Spine
		break;
	case 'Z':
		drawLine(x, y, x + w, y);//Top flat
		drawLine(x + w, y, x, y + h);//Diag
		drawLine(x, y + h - 1, x + w, y + h - 1);//bot flat
		break;
	case '0':
		drawChar('O', x, y, h, w); //Lel
		drawLine(x + w, y + (h / 3), x, y + ((h / 3) * 2)); //Diag
		break;
	case '1':
		drawLine(x + (w / 2), y, x + (w / 2), y + h); //Spine
		drawLine(x + (w / 5), y + h, x + ((w / 5) * 4), y + h); //Bot flat
		drawLine(x + (w / 2), y, x + (w / 6), y + (w / 4)); //Diag tip
		break;
	case '2':
		drawLine(x, y + (h / 5), x + ((w / 5) * 2), y);//Left-Top diag
		drawLine(x + ((w / 5) * 2), y, x + ((w / 5) * 4), y); //Top flat
		drawLine(x + ((w / 5) * 4), y, x + w, y + (h / 5)); //Right flat
		drawLine(x + w, y + (h / 5), x, y + h); //Right-Bot diag
		drawLine(x, y + h, x + w, y + h);//Bot flat
		break;
	case '3':
		drawLine(x, y, x + ((w / 5) * 3), y);//Top Flat
		drawLine(x + ((w / 5) * 3), y, x + w, y + (h / 4)); //Top-down diag 1
		drawLine(x + w, y + (h / 4), x + ((w / 5) * 2), y + (h / 2)); //Top-Down diag 2
		drawLine(x + ((w / 5) * 2), y + (h / 2), x + w, y + ((h / 4) * 3)); //Top-Down diag 3
		drawLine(x + w, y + ((h / 4) * 3), x + ((w / 5) * 3), y + h); //Top-Down 3 diag
		drawLine(x, y + h, x + ((w / 5) * 3), y + h);
		break;
	case '4':
		drawLine(x, y + (h / 2), x + w, y + (h / 2));//Middle flat
		drawLine(x, y + (h / 2), x + ((w / 5) * 4), y); //Mid-Top diag
		drawLine(x + ((w / 5) * 4), y, x + ((w / 5) * 4), y + h);//Spine
		break;
	case '5':
		drawLine(x, y, x + w, y); //top flat
		drawLine(x, y, x, y + (h / 2));//Left side;
		drawLine(x, y + (h / 2), x + w, y + (h / 2));//Mid flat
		drawLine(x + w, y + (h / 2), x + w, y + ((h / 5) * 3));//Right side;
		drawLine(x + w, y + ((h / 5) * 4), x + ((w / 3) * 2), y + h);//Right-Bot diag
		drawLine(x + ((w / 3) * 2), y + h, x + (w / 3), y + h);//Bot flat
		drawLine(x + w, y + ((h / 5) * 3), x + w, y + ((h / 5) * 4));
		drawLine(x + (w / 3), y + h, x, y + ((h / 5) * 4));//Bot-Left diag
		break;
	case '6':
		drawChar('O', x, y + ((h / 3)), ((h / 3) * 2), w); //Lel
		drawLine(x + (w / 3) + 1, y + ((h / 3)), x + w, y);//Top diag
		break;
	case '7':
		drawLine(x, y, x + w, y);//Top flat
		drawLine(x + w, y, x + (w / 3), y + h);//Diag
		break;
	case '8':
		drawChar('O', x, y + ((h / 2)), (h / 2), w); //Lel
		drawChar('O', x, y, (h / 2), w); //Double Lel
		break;
	case '9':
		drawChar('O', x, y, ((h / 3) * 2), w); //Lel
		drawLine(x + ((w / 3) * 2), y + ((h / 3) * 2), x + (w / 4), y + h); //Diag
		break;
	case '(':
		drawLine(x + (w / 2), y, x, y + (h / 3)); //Mid-Left diag
		drawLine(x, y + (h / 3), x, y + ((h / 3) * 2)); //left side
		drawLine(x, y + ((h / 3) * 2), x + (w / 2), y + h); //Mid-Right diag
		break;
	case ')':
		drawLine(x + (w / 2), y, x + w, y + (h / 3)); //Mid-Left diag
		drawLine(x + w, y + (h / 3), x + w, y + ((h / 3) * 2)); //left side
		drawLine(x + w, y + ((h / 3) * 2), x + (w / 2), y + h); //Mid-Right diag
		break;
	case '-':
		drawLine(x + (w / 4), y + ((h / 7) * 3), x + ((w / 4) * 3), y + ((h / 7) * 3)); //Top
		drawLine(x + (w / 4), y + ((h / 7) * 3), x + (w / 4), y + ((h / 7) * 4)); //Left
		drawLine(x + ((w / 4) * 3), y + ((h / 7) * 3), x + ((w / 4) * 3), y + ((h / 7) * 4)); //Right
		drawLine(x + (w / 4), y + ((h / 7) * 4), x + ((w / 4) * 3), y + ((h / 7) * 4)); //Bot
		break;
	case '#':
		drawLine(x, y, x + w, y);
		drawLine(x, y, x, y + h);
		drawLine(x + w, y, x + w, y + h);
		drawLine(x, y + h, x + w, y + h);
		break;
	case '?':
		drawLine(x, y, x + (w / 2), y + (h / 3)); //Diag
		drawLine(x + (w / 2), y + (h / 3), x + (w / 2), y + (h / 2)); //Spine
		drawLine(x + (w / 2), y + (h / 2), x + (w / 4), y + ((h / 3) * 2)); //Diag 2
		drawLine(x + (w / 4), y + ((h / 3) * 2), x + (w / 4), y + ((h / 5) * 4));//straight
		drawLine(x + (w / 5), y + ((h / 10) * 9), x + (w / 5), y + h); //Left
		drawLine(x + ((w / 5) * 2.5), y + ((h / 10) * 9), x + ((w / 5) * 2.5), y + h); //Right
		drawLine(x + (w / 5), y + ((h / 10) * 9), x + ((w / 5) * 2.5), y + ((h / 10) * 9)); //Top
		drawLine(x + ((w / 5) * 2.5), y + h, x + (w / 5), y + h); //Bot
		break;
	case ':':
		drawChar('O', x + (w / 3), y, h / 3, w / 3); //Lel
		drawChar('O', x + (w / 3), y + ((h / 3) * 2), h / 3, w / 3); //Double lel
		break;
	case '"':
		drawLine(x + (w / 3), y, x + ((w / 3) * 2), y);
		drawLine(x + ((w / 3) * 2), y, x, y + (h / 4));
		drawLine(x + (w / 3), y, x, y + (h / 4));
		break;
	case '|':
		drawLine(x, y, x + w, y + h);
		break;
	default: //Any unrecognized character or space print a blank, well, space.
		break;
	}
}

void drawStringHor(char text[], float x, float y, float h, float w, float spcX)
{
	fTemp = spcX;

	for (int i = 0; text[i] != '\0'; ++i)
	{
		if (!i) { spcX = 0; }
		else { spcX += fTemp + w; }
		drawChar(text[i], x + spcX, y, h, w);
	}
}

void drawStringVer(char text[], float x, float y, float h, float w, float spcY)
{
	fTemp = spcY;

	for (int i = 0; text[i] != '\0'; ++i)
	{
		if (!i) { spcY = 0; }
		else { spcY += fTemp + h; }
		drawChar(text[i], x, y + spcY, h, w);
	}
}

void drawBox(float x, float y, float h, float w)
{
	drawLine(x, y, x + w, y); //Top
	drawLine(x, y + h, x + w, y + h); //Bot
	drawLine(x, y, x, y + h); //Left
	drawLine(x + w, y, x + w, y + h); //Right
}

void drawFrameRate(float x, float y, float h, float w, float xSPC)
{
	int iFPS;
	int num[4];
	float fFPS = (1 / getDeltaTime());
	char plc[4];

	for (iFPS = 0; iFPS < fFPS; ++iFPS);
	iFPS -= 1;

	num[0] = (iFPS / 1000) % 10; //(1234 / 1000) = 1.234 % 10 = 1
	num[1] = (iFPS / 100) % 10; // (267 / 100) = 2.67 % 10 = 2
	num[2] = extractTensPlace(iFPS);
	num[3] = iFPS % 10; // 267 % 10 = 7;

	for (int a = 0; a < 4; ++a) 
	{ 
		float b;
		float c;

		plc[a] = getCharFromInt(num[a]); 

		if (a == 0) { b = 0, c = 0; }
		else { b += w, c += xSPC; }

		drawChar(plc[a], x + b + c, y, h, w);
	}

	cout << "FPS: " << iFPS << "/" << fFPS << "; ";
}

void restartScreen()
{
	termContext();
	SCREEN_X = setScreenWidth();
	SCREEN_Y = setScreenHeight();
	runMain();
}