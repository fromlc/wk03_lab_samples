//------------------------------------------------------------------------------
// cmd_util.h
//------------------------------------------------------------------------------

#include <iostream>
using std::cin;
using std::cout;

//------------------------------------------------------------------------------
//  local function prototypes
//------------------------------------------------------------------------------
char getMenuOption();
bool goNorth();
bool goSouth();
bool goEast();
bool goWest();
bool goUp();
bool goDown();
bool goQuit();

//------------------------------------------------------------------------------
//  - assumes cmd is lower case
//  - returns true if cmd is a valid command, false otherwise
//------------------------------------------------------------------------------

bool doCommand(char cmd) {

	switch (cmd) {
	case 'n': return goNorth();
	case 's': return goSouth();
	case 'e': return goEast();
	case 'w': return goWest();
	case 'u': return goUp();
	case 'd': return goDown();
	case 'q': return goQuit();

	default:
		return false;
	}
}

//------------------------------------------------------------------------------
//  - display menu and prompt
//  - get user input
//  - return lower case user command
//------------------------------------------------------------------------------
char getMenuOption() {

	// display menu
	cout << "\nN)orth, S)outh, E)ast, W)est, U)p, D)own, Q)uit ? ";

	// get user command
	char cmd;
	cin >> cmd;
	return tolower(cmd);
}

//------------------------------------------------------------------------------
//  - display menu
//  - execute each user command
//  - exit loop on execute user commands
//------------------------------------------------------------------------------
void commandLoop() {

	char cmd;
	do {
		cmd = getMenuOption();

		while (!doCommand(cmd)) {
			cout << "I don't know that command, try again\n";
		}

	} while (cmd != 'q');
}

//------------------------------------------------------------------------------
//  execute commands
//------------------------------------------------------------------------------
bool goNorth() { cout << "North\n"; return true; }
bool goSouth() { cout << "South\n"; return true; }
bool goEast() { cout << "East\n"; return true; }
bool goWest() { cout << "West\n"; return true; }
bool goUp() { cout << "Up\n"; return true; }
bool goDown() { cout << "Down\n"; return true; }
bool goQuit() { cout << "Goodbye!\n"; return true; }