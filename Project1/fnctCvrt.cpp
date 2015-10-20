#include "Global.h"
#include "fnct.h"

/* Will only return the number from the one's place */
char getCharFromInt(int a)
{
	a %= 10;

	switch (a)
	{
	case 0:
		return '0';
		break;
	case 1:
		return '1';
		break;
	case 2:
		return '2';
		break;
	case 3:
		return '3';
		break;
	case 4:
		return '4';
		break;
	case 5:
		return '5';
		break;
	case 6:
		return '6';
		break;
	case 7:
		return '7';
		break;
	case 8:
		return '8';
		break;
	case 9:
		return '9';
		break;
	default:
		return '0';
	}
}

//only returns a 0-9 value, defaults to 0
int getIntFromChar(char a)
{
	switch (a)
	{
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	case'0':default:
		return 0;
	}
}