#include "Global.h"
#include "game.h"

int getAIdir(int dif)
{
	int *player;
	int *wumpus;
	{
		int a = e_Player.getEntPos();
		int b = e_Wumpus.getEntPos();
		player = &a;
		wumpus = &b;
	}

	switch (dif)
	{
	case 1: //Normal
	case 2: //Hard
	default: //Easy
		srand(time(NULL));
		int rand;
		switch(*wumpus)
		{
		case 0:
			rand = std::rand() % 2;
			if (rand == 1) { return 0; }
			else { return 3; }
		case 1:
			rand = std::rand() % 3;
			if (rand == 2) { return 0; }
			else if (rand == 1 ){ return 3; }
			else { return 2; }
		case 2:
			rand = std::rand() % 2;
			if (rand == 1) { return 0; }
			else { return 2; }
		case 3:
			rand = std::rand() % 3;
			if (rand == 0) { return 0; }
			else if (rand == 1) { return 1; }
			else { return 3; }
		case 4:
			rand = std::rand() % 4;
			if (rand == 0) { return 0; }
			else if (rand == 1) { return 1; }
			else if (rand == 2) { return 2; }
			else { return 3; }
		case 5:
			rand = std::rand() % 3;
			if (rand == 0) { return 0; }
			else if (rand == 1) { return 1; }
			else { return 2; }
		case 6:
			rand = std::rand() % 2;
			if (rand == 0) { return 1; }
			else { return 3; }
		case 7:
			rand = std::rand() % 3;
			if (rand == 0) { return 1; }
			else if (rand == 1) { return 2; }
			else { return 3; }
		case 8:
			rand = std::rand() % 3;
			if (rand == 0) { return 1; }
			else { return 2; }
		}
	}
}