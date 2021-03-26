#include <iostream>
#include <cstdlib>
using namespace std;

void displayMaze(char maze[11][11]) {

	int i = 0;
	int j = 0;


	for (i = 0; i < 11; ++i) {
		for (j = 0; j < 11; ++j) {

			cout << maze[i][j];

			if (j == 10) {
				cout << endl;
			}
		}
	}
}

char playersMoves(char playerPosition, char maze[11][11]) {
	int i = 0;
	int j = 0;
	int coins = 0;
	system("CLS");

	//Moving 'P' or checking if wall
	for (i = 0; i < 11; ++i) {
		for (j = 0; j < 11; ++j) {

			if (maze[i][j] == 'P') {
				if (playerPosition == 'N') {

					if (maze[i - 1][j] == '_' || maze[i - 1][j] == '|') {
						system("CLS");
						cout << "You can't move there, there's a wall there." << endl;
						j++;
					}
					//Coin collecting
					else if (maze[i - 1][j] == '0') {
						maze[i][j] = ' ';
						maze[i - 1][j] = 'P';
						++coins;
						j++;
						return coins;
					}
					else {
						maze[i][j] = ' ';
						maze[i - 1][j] = 'P';
						j++;
					}
				}
				//S command - issues
				else if (playerPosition == 'S') {

					if (maze[i + 1][j] == '_' || maze[i + 1][j] == '|') {
						system("CLS");
						cout << "You can't move there, there's a wall there." << endl;

					}
					//Coin collecting
					else if (maze[i + 1][j] == '0') {
						maze[i][j] = ' ';
						maze[i + 1][j] = 'P';
						++coins;
						j++;
						return coins;
					}
					else {
						maze[i][j] = ' ';
						maze[i + 1][j] = 'P';
						j++;
						return maze[11][11];
					}
				}
				else if (playerPosition == 'E') {

					if (maze[i][j + 1] == '_' || maze[i][j + 1] == '|') {
						system("CLS");
						cout << "You can't move there, there's a wall there." << endl;

					}
					//Coin collecting
					else if (maze[i][j + 1] == '0') {
						maze[i][j] = ' ';
						maze[i][j + 1] = 'P';
						++coins;
						j++;
						return coins;
					}
					else {
						maze[i][j] = ' ';
						maze[i][j + 1] = 'P';
						j++;
					}
				}
				else if (playerPosition == 'W') {

					if (maze[i][j - 1] == '_' || maze[i][j - 1] == '|') {
						system("CLS");
						cout << "You can't move there, there's a wall there." << endl;

					}
					//Coin collecting
					else if (maze[i][j - 1] == '0') {
						maze[i][j] = ' ';
						maze[i][j - 1] = 'P';
						++coins;
						j++;
						return coins;
					}
					else {
						maze[i][j] = ' ';
						maze[i][j - 1] = 'P';
						j++;
					}
				}

			}
		
		}

	}
	return maze[11][11];
}
void endOfMaze(int coins, char playerPosition, char maze[11][11]) {
	int i = 0;
	int j = 0;
	//Moving 'P' or checking if wall
	for (i = 0; i < 11; ++i) {

		for (j = 0; j < 11; ++j) {

			if (maze[i][j] == 'P') {

				if (playerPosition == 'N') {
					//checking if player finish the maze
					if (maze[i - 1][j] == 'F') {
						if (coins == 5) {
							system("CLS");
							cout << "Congratulation!\nYou have collected all the coins and have perfectly beaten the game!" << endl;
							system("pause");
							exit(0);
						}
						else if (maze[i - 1][j] == 'F') {
							system("CLS");
							cout << "Congratulation you have beaten the maze!" << endl;
							system("pause");
							exit(0);

						}
						else {
						}
					}
				}
				else if (playerPosition == 'S') {

					//checking if player finish the maze
					if (maze[i + 1][j] == 'F') {
						if (coins == 5) {
							system("CLS");
							cout << "Congratulation!\nYou have collected all the coins and have perfectly beaten the game!" << endl;
							system("pause");
							exit(0);
						}
						else if (maze[i + 1][j] == 'F') {
							system("CLS");
							cout << "Congratulation you have beaten the maze!" << endl;
							system("pause");
							exit(0);

						}
						else {
						}
					}
				}
				else if (playerPosition == 'E') {

					//checking if player finish the maze
					if (maze[i][j + 1] == 'F') {
						if (coins == 5) {
							system("CLS");
							cout << "Congratulation!\nYou have collected all the coins and have perfectly beaten the game!" << endl;
							system("pause");
							exit(0);
						}
						else if (maze[i][j + 1] == 'F') {
							system("CLS");
							cout << "Congratulation you have beaten the maze!" << endl;
							system("pause");
							exit(0);

						}
					}
				}
				else if (playerPosition == 'W') {

					//checking if player finish the maze
					if (maze[i][j - 1] == 'F') {
						if (coins == 5) {
							system("CLS");
							cout << "Congratulation!\nYou have collected all the coins and have perfectly beaten the game!" << endl;
							system("pause");
							exit(0);
						}
						else if (maze[i][j - 1] == 'F') {
							system("CLS");
							cout << "Congratulation you have beaten the maze!" << endl;
							system("pause");
							exit(0);

						}
					}
				}

			}

		}

	}
}

char playerActions() {
	char action;
	do {
		cout << "You are 'P' get to 'F' to finish the maze\nand collect coins(0) along the way!" << endl;
		cout << "Move (N, S, E, W) " << endl;
		cout << "Other commands: Q = 'Quit',\n		I = 'Inventory',\n		M = 'Monologue'." << endl;
		cin >> action;
	} while (action != 'N' && action != 'S' && action != 'E' && action != 'W' && action != 'Q' && action != 'I' && action != 'M');
	return action;
}
void story() {
	cout << "You are a mercenary that took on the quest for exploring\nthe newly discoverd cave.";
	cout << "The small reward will be enough \nfor you to get by in your life as a new mercenary.";
	cout << "Before \ncoming to the cave you have heard that the cave might \nhave treasures.\n";
}

void inventory(int coins) {
	cout << "The current coins you have are: " << coins << endl;
}
int main() {
	char action;
	char mazeNonGameZone[11][11];
	int totalCoins = 0;

	//first row
	mazeNonGameZone[0][0] = '_';
	mazeNonGameZone[0][1] = '_';
	mazeNonGameZone[0][2] = '_';
	mazeNonGameZone[0][3] = '_';
	mazeNonGameZone[0][4] = '_';
	mazeNonGameZone[0][5] = '_';
	mazeNonGameZone[0][6] = '_';
	mazeNonGameZone[0][7] = '_';
	mazeNonGameZone[0][8] = '_';
	mazeNonGameZone[0][9] = '_';
	mazeNonGameZone[0][10] = '_';
	//second row
	mazeNonGameZone[1][0] = '|';
	mazeNonGameZone[1][1] = 'P';
	mazeNonGameZone[1][2] = ' ';
	mazeNonGameZone[1][3] = ' ';
	mazeNonGameZone[1][4] = ' ';
	mazeNonGameZone[1][5] = '0';
	mazeNonGameZone[1][6] = '|';
	mazeNonGameZone[1][7] = ' ';
	mazeNonGameZone[1][8] = ' ';
	mazeNonGameZone[1][9] = '0';
	mazeNonGameZone[1][10] = '|';
	//third row
	mazeNonGameZone[2][0] = '|';
	mazeNonGameZone[2][1] = '_';
	mazeNonGameZone[2][2] = '_';
	mazeNonGameZone[2][3] = '_';
	mazeNonGameZone[2][4] = '_';
	mazeNonGameZone[2][5] = ' ';
	mazeNonGameZone[2][6] = '|';
	mazeNonGameZone[2][7] = ' ';
	mazeNonGameZone[2][8] = '|';
	mazeNonGameZone[2][9] = ' ';
	mazeNonGameZone[2][10] = '|';
	//fourth row
	mazeNonGameZone[3][0] = '|';
	mazeNonGameZone[3][1] = ' ';
	mazeNonGameZone[3][2] = ' ';
	mazeNonGameZone[3][3] = ' ';
	mazeNonGameZone[3][4] = ' ';
	mazeNonGameZone[3][5] = ' ';
	mazeNonGameZone[3][6] = '|';
	mazeNonGameZone[3][7] = ' ';
	mazeNonGameZone[3][8] = '|';
	mazeNonGameZone[3][9] = ' ';
	mazeNonGameZone[3][10] = '|';
	//fifth row
	mazeNonGameZone[4][0] = '|';
	mazeNonGameZone[4][1] = '0';
	mazeNonGameZone[4][2] = '_';
	mazeNonGameZone[4][3] = '_';
	mazeNonGameZone[4][4] = '_';
	mazeNonGameZone[4][5] = '_';
	mazeNonGameZone[4][6] = '|';
	mazeNonGameZone[4][7] = ' ';
	mazeNonGameZone[4][8] = '|';
	mazeNonGameZone[4][9] = ' ';
	mazeNonGameZone[4][10] = '|';
	//sixth row
	mazeNonGameZone[5][0] = '|';
	mazeNonGameZone[5][1] = ' ';
	mazeNonGameZone[5][2] = '|';
	mazeNonGameZone[5][3] = ' ';
	mazeNonGameZone[5][4] = ' ';
	mazeNonGameZone[5][5] = '0';
	mazeNonGameZone[5][6] = ' ';
	mazeNonGameZone[5][7] = ' ';
	mazeNonGameZone[5][8] = '|';
	mazeNonGameZone[5][9] = ' ';
	mazeNonGameZone[5][10] = '|';
	//seventh row
	mazeNonGameZone[6][0] = '|';
	mazeNonGameZone[6][1] = ' ';
	mazeNonGameZone[6][2] = '|';
	mazeNonGameZone[6][3] = ' ';
	mazeNonGameZone[6][4] = '_';
	mazeNonGameZone[6][5] = '_';
	mazeNonGameZone[6][6] = '_';
	mazeNonGameZone[6][7] = '_';
	mazeNonGameZone[6][8] = '|';
	mazeNonGameZone[6][9] = ' ';
	mazeNonGameZone[6][10] = '|';
	//eighth row
	mazeNonGameZone[7][0] = '|';
	mazeNonGameZone[7][1] = ' ';
	mazeNonGameZone[7][2] = ' ';
	mazeNonGameZone[7][3] = ' ';
	mazeNonGameZone[7][4] = '|';
	mazeNonGameZone[7][5] = ' ';
	mazeNonGameZone[7][6] = ' ';
	mazeNonGameZone[7][7] = ' ';
	mazeNonGameZone[7][8] = ' ';
	mazeNonGameZone[7][9] = ' ';
	mazeNonGameZone[7][10] = '|';
	//ninth row
	mazeNonGameZone[8][0] = '|';
	mazeNonGameZone[8][1] = '_';
	mazeNonGameZone[8][2] = '_';
	mazeNonGameZone[8][3] = '_';
	mazeNonGameZone[8][4] = '|';
	mazeNonGameZone[8][5] = ' ';
	mazeNonGameZone[8][6] = '_';
	mazeNonGameZone[8][7] = '_';
	mazeNonGameZone[8][8] = '_';
	mazeNonGameZone[8][9] = ' ';
	mazeNonGameZone[8][10] = '|';
	//tenth row
	mazeNonGameZone[9][0] = '|';
	mazeNonGameZone[9][1] = '0';
	mazeNonGameZone[9][2] = ' ';
	mazeNonGameZone[9][3] = ' ';
	mazeNonGameZone[9][4] = ' ';
	mazeNonGameZone[9][5] = ' ';
	mazeNonGameZone[9][6] = '|';
	mazeNonGameZone[9][7] = 'F';
	mazeNonGameZone[9][8] = ' ';
	mazeNonGameZone[9][9] = ' ';
	mazeNonGameZone[9][10] = '|';
	//Eleventh row
	mazeNonGameZone[10][0] = '|';
	mazeNonGameZone[10][1] = '_';
	mazeNonGameZone[10][2] = '_';
	mazeNonGameZone[10][3] = '_';
	mazeNonGameZone[10][4] = '_';
	mazeNonGameZone[10][5] = '_';
	mazeNonGameZone[10][6] = '|';
	mazeNonGameZone[10][7] = '_';
	mazeNonGameZone[10][8] = '_';
	mazeNonGameZone[10][9] = '_';
	mazeNonGameZone[10][10] = '|';

	displayMaze(mazeNonGameZone);
	action = playerActions();

	while (action != 'Q') {
		if (action == 'I') {
			system("CLS");
			inventory(totalCoins);
			cout << endl;
			displayMaze(mazeNonGameZone);
			action = playerActions();
		}
		else if (action == 'M') {
			system("CLS");
			story();
			cout << endl;
			displayMaze(mazeNonGameZone);
			action = playerActions();
		}
		else if (action == 'N' || action == 'S' || action == 'E' || action == 'W') {
			endOfMaze(totalCoins, action, mazeNonGameZone);
			mazeNonGameZone[11][11] = playersMoves(action, mazeNonGameZone);
			if (mazeNonGameZone[11][11] == 1) {
				totalCoins += mazeNonGameZone[11][11];
				mazeNonGameZone[11][11] -= 1;
			}
			displayMaze(mazeNonGameZone);
			action = playerActions();
			
			}
		}

	return 0;
}


