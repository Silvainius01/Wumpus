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
bool launchedFromLoad = false;

void main()
{
	initContext(SCREEN_X, SCREEN_Y, "RTS");
	if (!launchedFromLoad)
	{
		initEnts();
		for (int a = 0; a != MENU; a++) { menu[a] = false; }
		menu[0] = true;
		bTemp = false;
		//Comment this in/out to turn on/off the test screen.
		//menu[6] = true;
	}
	else { launchedFromLoad = false; }

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
								switch (drawGameSaveMenu(checkSel()))
								{
								case true:
									bTemp = false;
									break;
								case false:
									break;
								}
								break;
							case 4:
								for (int a = 0; a != MENU; a++) { menu[a] = false; }
								menu[0] = true;
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
							loadGame();
							break;
						case 5:
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
		}

		cout << endl; for (int a = 0; a < MENU; a++) { cout << menu[a]; } cout << endl;
		for (int a = 0; a < 8; a++) { cout << frst[a]; } cout << endl;
		cout << SCREEN_X << "; " << SCREEN_Y << endl;
		cout << key << endl;
		for (int a = 0; a < 15; a++) { cout << e_Player.getEntName(a); }
		cout << endl << e_Player.getEntPos() << endl;
		cout << e_Wumpus.getEntPos() << endl;
		cout << e_Torch.getEntPos() << endl;
		drawFrameRate(xSpace(1, 100), ySpace(1, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
		cout << endl << endl;
	}
}

int saveGame()
{
	fstream save;
	save.open("save.txt", ios_base::out);
	if (save.is_open())
	{
		save << e_Player.getEntID() << " ";
		for (int a = 0; a < 15; a++) { save << e_Player.getEntName(a); }
		save << " " << e_Player.getEntPos() << " " << e_Player.getEntSprite() << endl;

		save << e_Wumpus.getEntID() << " " << e_Wumpus.getEntPos() << endl;

		save << e_Torch.getEntID() << " " << e_Torch.getEntPos() << endl;

		for (int a = 0; a < 8; a++) { save << frst[a]; } save << endl;

		for (int a = 0; a < MENU; a++) { save << menu[a]; } save << endl;

		if (cTemp == '\0') { cTemp = 'n'; }
		save << fTemp << " " << bTemp << " " << cTemp << " " << iTemp << " " << sel << endl;

		save << SCREEN_X << " " << SCREEN_Y << endl;

		for (int a = 0; a < 5; a++) { save << key[a + 10]; } save << endl;
		save.close();
	}
	else { cout << "Failed to create save file"; return -1; }
}
void loadGame()
{
	fstream load;

	load.open("save.txt", ios_base::in);
	if(load.is_open()) 
	{

	   /**************************************\
		*	PLAYER DATA:                     *
		*		temp[0] = ID,                *
		*		temp[2] - temp[16] = name,   *
		*		temp[18] = pos,              *
		*		temp[20] = sprite            *
		*	WUMPUS DATA:                     *
		*		temp[0] = ID                 *
		*		temp[2] = pos                *
		*	TORCH DATA:                      *
		*		temp[0] = ID                 *
		*		temp[2] = pos                *
		*	IN-GAME STATE DATA:              *
		*		temp[0] - temp[7];           *
		*	MENU STATE DATA:                 *
		*		temp[0] - temp[21];          *
		*	SCREEN SETTINGS:                 *
		*		temp[0] - temp[2] = X        *
		*		temp[4] - temp[6] = Y        *
		*	CONTROLS:                        *
		*		temp[0] = up                 *
		*		temp[1] = down               *
		*		temp[3] = left               *
		*		temp[4] = right              *
		*		temp[5] = select             *
	   \**************************************/

		char data[23];

		//Player 
		load.getline(data, 23);
		char a[15];
		for (int b = 0; data[b + 2] != ' '; b++)
		{
			a[b] = data[b + 2];
			if (b == 14) { e_Player.setEntName(a); }
		}
		e_Player.setEntPos(getIntFromChar(data[18]));
		e_Player.setEntSprite(getIntFromChar(data[20]));

		//Wumpus
		load.getline(data, 23);
		e_Wumpus.setEntPos(getIntFromChar(data[2]));

		//Torch
		load.getline(data, 23);
		e_Torch.setEntPos(getIntFromChar(data[2]));

		//In Game States
		load.getline(data, 23);
		for (int a = 0; a < 8; a++) { frst[a] = getIntFromChar(data[a]); }

		//Menu States
		load.getline(data, 23);
		for (int a = 0; a < 23; a++) { menu[a] = getIntFromChar(data[a]); }

		//temp vars
		load.getline(data, 23);
		cout << data << endl;
		fTemp = getIntFromChar(data[1]);
		bTemp = getIntFromChar(data[3]);
		cTemp = data[5];
		iTemp = getIntFromChar(data[7]);
		sel = getIntFromChar(data[9]);

		//Screen Settings
		load.getline(data, 23);
		char x[4], y[4];
		

		//Controls
		load.getline(data, 23);
		for (int a = 0; a < 5; a++) { key[a + 10] = data[a]; }

		termContext();
		launchedFromLoad = true;
		runMain();
	}
}

void runMain()
{
	main();
}