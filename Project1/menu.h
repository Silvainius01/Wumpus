/* Holds the externs directly related to menus or other graphics */
#pragma once

//In menuDraw.cpp
extern float xSpace(float num, float den);
extern float ySpace(float num, float den);

extern void drawChar(char a, float x, float y, float h, float w);
extern void drawStringHor(char text[], float x, float y, float h, float w, float spcX);
extern void drawStringVer(char text[], float x, float y, float h, float w, float spcY);
extern void drawBox(float x, float y, float h, float w);
extern void drawFrameRate(float x, float y, float h, float w, float xSPC);
extern void restartScreen();
extern void drawTestMenu();

//in menuSel.cpp
extern int sel;
extern int menuChoice(int opts, bool isVertical);
extern int getMoveKeys();

extern bool checkSel();

extern char key[15];
extern char getNumInput();
extern char getLetInput();

//In menuMain.cpp
extern int drawMainMenu(bool pSel);

//in menuPlay.cpp
extern int drawPlayMenu(bool pSel);

//in menuOpt.cpp
extern int drawOptnMenu(bool pSel);
extern int drawDiffMenu(bool pSel);
extern int drawScrnMenu(bool pSel);
extern int drawContMenu(bool pSel);
extern int drawConfMenu(bool pSel, int menu);

extern float screenHeight[4];
extern float screenWidth[4];

extern bool drawScrnHMenu(bool pSel);
extern bool drawScrnWMenu(bool pSel);
extern bool drawContMMenu(bool pSel);
extern bool drawContSMenu(bool pSel);

//In menuGame.cpp
extern int drawGame();
extern bool frst[8];
extern bool drawCreateMenu();
extern bool drawGameMoveMenu(int dir);
extern bool drawGameLookMenu(bool pSel);
extern bool drawLookConfMenu(bool pSel);
extern bool drawGameShootMenu(bool pSel);
extern bool drawGameShootConf(bool pSel, int room1, int room2);
extern bool drawGameSaveMenu(bool pSel);
extern void drawEntSpriteReDir(int e);