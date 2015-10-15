/* Holds game loop and core functions */

#include "Global.h"
#include "menu.h"
#include "game.h"
#include "fnct.h"

const int MENU = 22;
/* 
* [0]  = Main Menu  
* [1]  = Play Menu  
* [2]  = Optn Menu
* [3]  = Diff Menu  
* [4]  = Scrn Menu  
* [5]  = Cont Menu
* [6]  = Test Menu 
* [7]  = ScrH Menu  
* [8]  = ScrW Menu
* [9]  = sConf Menu
* [10] = Move Menu
* [11] = Slct Menu
* [12] = mConf Menu
* [13] = selConf Menu
* [14] = Create Menu
* [15] = 9 Game
* [16] = 16 Game
* [17] = 25 Game
* [18] = Tutorial
* [19] = Game Move
* [20] = Look conf
* [21] = shoot conf
*/
bool menu[MENU];

void main()
{
	initContext(SCREEN_X, SCREEN_Y, "RTS");
	initEnts();
	for (int a = 0; a != MENU; a++) { menu[a] = false; }
	menu[0] = true;
	bTemp = false;
	//Comment this in/out to turn on/off the test screen.
	//menu[6] = true;

	while (stepContext())
	{
		//Comment this in to align grpahics with center of the screen if desired.
		//drawBox(xSpace(50, 100), ySpace(0, 100), SCREEN_Y, 0);
		
		if (!menu[6])
		{
			if (menu[0])
			{
				switch (drawMainMenu(checkSel()))
				{
				case -1:
					break;
				case 0:
					menu[0] = false;
					menu[1] = true;
					sel = 0;
					break;
				case 1:
					menu[0] = false;
					menu[2] = true;
					sel = 0;
					break;
				case 2:
					termContext();
					break;
				}
			}
			else
			{
				if (menu[1])
				{
					if (menu[15])
					{
						if (menu[14])
						{
							switch (drawCreateMenu())
							{
							case true:
								menu[14] = false;
								break;
							case false:
								break;
							}
						}
						else
						{
							switch (drawGame())
							{
							case -1:
								break;
							case 0:
								switch (drawGameMoveMenu(getMoveKeys()))
								{
								case true:
									bTemp = false;
									break;
								case false:
									break;
								}
								break;
							case 1:
								if (menu[21])
								{
									switch (drawGameShootConf(checkSel(), iTemp3, iTemp2))
									{
									case true:
										if (!bTemp)
										{
											for (int a = 0; a != MENU; a++) { menu[a] = false; }
											menu[0] = true;
										}
										else
										{
											menu[21] = false;
											bTemp = false;
										}
										break;
									case false:
										break;
									}
								}
								else
								{
									switch (drawGameShootMenu(checkSel()))
									{
									case true:
										menu[21] = true;
										break;
									case false:
										break;
									}
								}
								break;
							case 2:
								if (menu[20])
								{
									switch (drawLookConfMenu(checkSel()))
									{
									case true:
										menu[20] = false;
										bTemp = false;
										break;
									case false:
										break;
									}
								}
								else
								{
									switch (drawGameLookMenu(checkSel()))
									{
									case true:
										menu[20] = true;
										break;
									case false:
										break;
									}
								}
								break;
							case 3:
								break;
							}
						}
					}
					else
					{
						switch (drawPlayMenu(checkSel()))
						{
						case -1:
							break;
						case 0:
							menu[15] = true;
							menu[14] = true;
							break;
						case 1:
							break;
						case 2:
							break;
						case 3:
							break;
						case 4:
							menu[1] = false;
							menu[0] = true;
							sel = 0;
							break;
						}
					}
				}
				else if (menu[2])
				{
					if (menu[3])
					{
						switch (drawDiffMenu(checkSel()))
						{
						case -1:
							break;
						case 0:
							break;
						case 1:
							break;
						case 2:
							break;
						case 3:
							menu[3] = false;
							sel = 0;
							break;
						}
					}
					else if (menu[4])
					{
						if (menu[7])
						{
							switch (drawScrnHMenu(checkSel()))
							{
							case true:
								menu[7] = false;
								break;
							case false:
								break;
							}
						}
						else if (menu[8])
						{
							switch (drawScrnWMenu(checkSel()))
							{
							case true:
								menu[8] = false;
								break;
							case false:
								break;
							}
						}
						else if (menu[9])
						{
							switch (drawConfMenu(checkSel(), 0))
							{
							case -1:
								break;
							case 0:
								menu[9] = false;
								restartScreen();
								break;
							case 1:
								menu[9] = false;
								break;
							}
						}
						else
						{
							switch (drawScrnMenu(checkSel()))
							{
							case -1:
								break;
							case 0:
								menu[8] = true;
								sel = 0;
								break;
							case 1:
								menu[7] = true;
								sel = 0;
								break;
							case 2:
								menu[9] = true;
								sel = 0;
								break;
							case 3:
								menu[4] = false;
								sel = 1;
								break;
							}
						}
					}
					else if (menu[5])
					{
						if (menu[10])
						{
							if (menu[12])
							{
								switch (drawConfMenu(checkSel(), 1))
								{
								case -1:
									break;
								case 0:
									menu[10] = false;
									menu[12] = false;
									break;
								case 1:
									menu[12] = false;
									menu[10] = false;
									break;
								}
							}
							else
							{
								switch (drawContMMenu(checkSel()))
								{
								case true:
									menu[12] = true;
									break;
								case false:
									break;
								}
							}
						}
						else if (menu[11])
						{
							if (menu[13])
							{
								switch (drawConfMenu(checkSel(), 1))
								{
								case -1:
									break;
								case 0:
									menu[13] = false;
									menu[11] = false;
									break;
								case 1:
									menu[13] = false;
									menu[11] = false;
									break;
								}
							}
							else
							{
								switch (drawContSMenu(checkSel()))
								{
								case true:
									menu[13] = true;
									break;
								case false:
									break;
								}
							}
						}
						else
						{
							switch (drawContMenu(checkSel()))
							{
							case -1:
								break;
							case 0:
								menu[10] = true;
								break;
							case 1:
								menu[11] = true;
								break;
							case 2:
								menu[5] = false;
								break;
							}
						}
					}
					else
					{
						switch (drawOptnMenu(checkSel()))
						{
						case -1:
							break;
						case 0:
							menu[3] = true;
							sel = 0;
							break;
						case 1:
							menu[4] = true;
							sel = 0;
							break;
						case 2:
							menu[5] = true;
							sel = 0;
							break;
						case 3:
							menu[3] = false;
							menu[0] = true;
							sel = 1;
							break;
						}
					}
				}
			}
		}
		else
		{
			//x = cx + r * cos(a)
			//y = cy + r * sin(a)
			//drawEntSpriteReDir(1);
			/*float sx = xSpace(1, 2);
			float sy = ySpace(0, 2);
			float x = 0;
			for (float a = 0; a < 100; a += 1)
			{
				float blerg;
				if (a != 0) { x += 0.1f; sx++; }
				graph(x + 10 * (PI / 180), sx, sy);
			}*/

			float coef[4] = { 0,0,0.05f,0 };
			//x^3 + x^2 + 0x + 0
			graphPoly(3, coef, 100, 0, 40);
		}

		drawFrameRate(xSpace(1, 100), ySpace(1, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
		cout << endl << endl;
	}
}

void saveGame();
void loadGame();

void runMain()
{
	main();
}