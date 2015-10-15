/* Holds the stuff for entities */

#include "Global.h"
#include "game.h"

int Entity::getEntPos() { return room; }
int Entity::getEntSprite() { return sprite; }
int Entity::getEntID() { return ID; }
void Entity::setEntName(char n[15]) { for (int a = 0; a < 16; a++) { nom[a] = n[a]; } }
void Entity::setEntPos(int r) { room = r; }
void Entity::setEntSprite(int s) { sprite = s; }
void Entity::getEntName()
{
	for (int a = 0; a < 15; a++) { cout << nom[a]; }
	cout << "; ";
}
void Entity::entMove(int dir)
{
	switch (dir)
	{
	case 0:
		room += 3;
		if (room == 9) { room = 6; }
		else if (room == 10) { room = 7; }
		else if (room == 11) { room = 8; }
		break;
	case 1:
		room -= 3;
		if (room == -3) { room = 0; }
		else if (room == -2) { room = 1; }
		else if (room == -1) { room = 2; }
		break;
	case 2:
		room--;
		if (room == -1) { room = 0; }
		else if (room == 5) { room = 6; }
		else if (room == 2) { room = 3; }
		break;
	case 3:
		room++;
		if (room == 3) { room = 2; }
		else if (room == 6) { room = 5; }
		else if (room == 9) { room = 8; }
		break;
	default:
		break;
	}
}
void Entity::setEntID(int id) { ID = id; }

Entity e_Player;
Entity e_Wumpus;
Entity e_Chest;
Entity e_Torch;
Entity e_Mirror;
Entity e_Test;

void initEnts()
{
	e_Player.setEntID(0);
	e_Player.setEntSprite(2);
	e_Player.setEntName("DEFAULT");

	e_Wumpus.setEntID(1);
	e_Wumpus.setEntSprite(3);
	e_Wumpus.setEntPos(3);
	e_Wumpus.setEntName("Wumpus");

	e_Chest.setEntID(2);
	e_Chest.setEntSprite(4);
	e_Chest.setEntName("CHEST");

	e_Torch.setEntID(3);
	e_Torch.setEntSprite(5);
	e_Torch.setEntPos(4);
	e_Torch.setEntName("Torch");

	e_Mirror.setEntID(4);
	e_Mirror.setEntSprite(6);
	e_Mirror.setEntName("Mirror");
}

Entity getRefEnt(int id)
{
	switch (id)
	{
	case 0:
		return e_Player;
	case 1:
		return e_Wumpus;
	case 2:
		return e_Chest;
	case 3:
		return e_Torch;
	case 4:
		return e_Mirror;
	default:
		return e_Test;
	}
}