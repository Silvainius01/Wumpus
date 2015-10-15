/* holds menu selction processing */

#include "Global.h"
#include "menu.h"

int sel;

char bindings[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789`-=[]|;',./"; //Holds a value that "getKey()" can use for every valid key
bool bindPress[48] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }; //I really wanted to only add one more value to "keyPress[]" but it was causing detection issues.

const int BOOLEANS = 15; //This was done so I could edit the size of "keyPress[]" without hunting down every "array out of access" crash in this file. Granted in this completed state it is no longer neccesary.
char key[15] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'W', 'S', 'A', 'D', ' ' }; //Holds a value for every BOUND key. I should remove numbers from this array, but I'm lazy.
bool keyPress[BOOLEANS] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; //I tried only using one boolean for every key, but that caused detection issues. 

//This functon makes it so that a key will only return a value the frame it was pressed, and not WHILE it's pressed.
void resetKeys()
{
	for (int a = 0; a < 15; ++a)
	{
		if (!getKey(key[a]) && keyPress[a])
		{
			keyPress[a] = false;
		}
	}

	for (int a = 0; bindings[a] != '\0'; ++a)
	{
		if (!getKey(bindings[a]) && bindPress[a])
		{
			bindPress[a] = false;
		}
	}

	if (!getKey(' ') && bindPress[26]) 
	{ 
		bindPress[26] = false; 
	}
}
//Checks if the selection key was pressed
bool checkSel()
{
	if (getKey(key[14]) && !keyPress[14])
	{
		keyPress[14] = true;
		if (key[14] == ' ') { bindPress[26] = true; }
		else 
		{ 
			for (int a = 0; bindings[a] != '\0'; a++)
			{ 
				if (key[14] == bindings[a]) { bindPress[a] = true; }
			} 
		}

		return true;
	}
	else
	{
		resetKeys();
		return false;
	}
}
//Checks if any number key was pressed
char getNumInput()
{
	char input = 'n';

	for (int a = 0; a < 10; ++a)
	{
		if (getKey(key[a]) && !keyPress[a])
		{
			input = key[a];
			fTemp = a;
			keyPress[a] = true;
		}
	}

	resetKeys();
	return input;
}
//Checks if ANY key was pressed
char getLetInput()
{
	char bindTo = '#';

	for (int a = 0; bindings[a] != '\0'; ++a)
	{
		if (!bindPress[a] && getKey(bindings[a]))
		{
			bindTo = bindings[a];
			bindPress[a] = true;
		}
	}

	if (bindTo == bindings[44]) { bindTo = '"'; }
	resetKeys();
	return bindTo;
}
//Checks if any of the move keys was pressed
int getMoveKeys()
{
	for (int a = 0; key[a + 10] != key[14]; a++)
	{
		if (getKey(key[a + 10]) && !keyPress[a + 10])
		{
			keyPress[a + 10] = true;
			return a;
		}
	}
	resetKeys();
	return -1;
}
//Returns which menu option should be highlighted
int menuChoice(int opts, bool isVertical)
{
	opts -= 1;

	if (isVertical)
	{
	   /********************************************************\
		* This isn't one switch becasue that would allow the   *
		* "sideways" keys to function in vertical menus, which *
		* I find undesireable.                                 *
	   \*******************************************************/
		switch (getMoveKeys())
		{
		case 0:
			sel--;
			break;
		case 1:
			sel++;
			break;
		}
	}
	else if (!isVertical)
	{
		switch (getMoveKeys())
		{
		case 2:
			sel--;
			break;
		case 3:
			sel++;
			break;
		}
	}

	if (sel > opts) { sel = 0; }
	else if (sel < 0) { sel = opts; }

	resetKeys();
	return sel;
}
