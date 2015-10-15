#pragma once

//In gameEnt.cpp
class Entity
{
private:
	char nom[15];
	int room;
	int sprite;
	int ID;
public:
	Entity()
	{
		setEntName("ERROR");
		setEntID(-1);
		setEntSprite(0);
	}

	int getEntPos();
	int getEntSprite();
	int getEntID();
	void setEntName(char n[15]);
	void setEntPos(int r);
	void setEntSprite(int s);
	void getEntName();
	void entMove(int dir);
	void setEntID(int id);
};
extern Entity e_Player;
extern Entity e_Wumpus;
extern Entity e_Chest;
extern Entity e_Torch;
extern Entity e_Mirror;
extern Entity e_Test;
extern Entity getRefEnt(int id);

extern void initEnts();

//In gameAI.cpp
extern int getAIdir();

//In gamePlay.cpp
struct Item { int ID; };
extern Item i_Torch;
extern Item i_Mirror;
extern Item i_Weapon;


/*
* 678
* 345
* 012
*/