#include <iostream>
using namespace std;

// Function declarations
char pic (char XOXO[6][6], int move, int winID, int game);
int convert (char letter, int numLetter, int num, int checkCase);
int check (char letter, int num, int error);
int winning (char XOXO[6][6], int turn, int winID);

// Functions:
// function 'pic' draws the 6x6 board
char pic(char XOXO[6][6], int move, int winID, int game) {
	cout << "Game #" << game << "_________________________" << endl << endl;
	for (int i = 0; i < 6; i++) {

		if (i == 0) {
			if (winID == 0) cout << XOXO[i][0] << move << "|  " << XOXO[i][1] << "   " << XOXO[i][2] << "   " << XOXO[i][3] << "   " << XOXO[i][4] << "   " << XOXO[i][5] << endl << endl;

			else cout << "|" << XOXO[i][0] << "|  " << XOXO[i][1] << "   " << XOXO[i][2] << "   " << XOXO[i][3] << "   " << XOXO[i][4] << "   " << XOXO[i][5] << endl << endl;
		}
		else cout << " " << XOXO[i][0] << "   " << XOXO[i][1] << "   " << XOXO[i][2] << "   " << XOXO[i][3] << "   " << XOXO[i][4] << "   " << XOXO[i][5] << endl << endl;
	}
	return 1;
}
// function 'check' checks for valid input of letter and number
int check (char letter, int num, int error) {
	// letter error = 1
		if ((letter != 'A') && (letter != 'B') && (letter != 'C')) error = 1;
		// num error = 5, both = 6
		if ((num != 1) && (num != 2) && num != 3) {
			if (error == 1)										   error = 6;
			else												   error = 5;
		}
	return error;
}
// function 'convert' converts the letters and numbers to valid values
int convert (char letter, int numLetter, int num, int checkCase) {

	if (checkCase == 1) {
		//converting 'A' to 1, 'B' to 3 and 'C' to 5
		if		(letter == 'A')	numLetter = 1;
		else if (letter == 'B') numLetter = 3;
		else if (letter == 'C') numLetter = 5;
		return numLetter;
	}
	else if (checkCase == 2) {
		// converting 2 to 3, 3 to 5
		if		(num == 2) num = 3;
		else if (num == 3) num = 5;
		return num;
	}
}
// 'win' function checks after every move if there's a winner
int winning(char XOXO[6][6], int turn, int winID) {

	// loop for across checking
	for (int z = 1; z < 6; z += 2) {

		// left to right                                                                                 top to bottom
		if ((((XOXO[z][1] != ' ')) && ((XOXO[z][1]) == (XOXO[z][3])) && (XOXO[z][3]) == (XOXO[z][5])) || (((XOXO[1][z] != ' ')) && ((XOXO[1][z]) == (XOXO[3][z])) && (XOXO[3][z]) == (XOXO[5][z]))) {
			if (turn == 1) {
				winID = 1;
			}
			else {
				winID = 2;
			}// unique winning ui for appearance
			if ((((XOXO[z][1] != ' ')) && ((XOXO[z][1]) == (XOXO[z][3])) && (XOXO[z][3]) == (XOXO[z][5]))) {
				XOXO[z][4] = XOXO[z][2] = '-';
				XOXO[0][0] = '*';
			}
			else {
				XOXO[2][z] = XOXO[4][z] = '|';
				XOXO[0][0] = '*';
			}
		}
	}// across checking
	if (((XOXO[3][3] != ' ')) && ((XOXO[3][3]) == ((XOXO[1][1])) && (XOXO[1][1]) == (XOXO[5][5]) || (((XOXO[3][3]) == (XOXO[5][1])) && (XOXO[5][1]) == (XOXO[1][5])))) {
		if (turn == 1) winID = 1;
		else winID = 2;

		if (((XOXO[3][3] != ' ')) && (((XOXO[3][3]) == (XOXO[1][1])) && (XOXO[1][1]) == (XOXO[5][5]))) 
			XOXO[2][2] = XOXO[4][4] = '\'';
		else XOXO[4][2] = XOXO[2][4] = '/';

		XOXO[0][0] = '*';

	}
	return winID;
}

int main() {
	int game = 1; // main 'for' loop whith 'chickenDinner' checker for 
	for (int winID = 0; winID == 0;) {

		int turn = 0, num = 0, numLetter = 0;
		char letter = ' ';

		// 6X6 XO board
		char XOXO[6][6] = { /*0,0*/'|' , /*0,1*/'1' , /*0,2*/' ' , /*0,3*/'2' , /*0,4*/' ' , /*0,5*/'3' ,

							/*1,0*/'A' , /*1,1*/' ' , /*1,2*/' ' , /*1,3*/' ' , /*1,4*/' ' , /*1,5*/' ' ,

							/*2,0*/' ' , /*2,1*/' ' , /*2,2*/' ' , /*2,3*/' ' , /*2,4*/' ' , /*2,5*/' ' ,

							/*3,0*/'B' , /*3,1*/' ' , /*3,2*/' ' , /*3,3*/' ' , /*3,4*/' ' , /*3,5*/' ' ,

							/*4,0*/' ' , /*4,1*/' ' , /*4,2*/' ' , /*4,3*/' ' , /*4,4*/' ' , /*4,5*/' ' ,

							/*5,0*/'C' , /*5,1*/' ' , /*5,2*/' ' , /*5,3*/' ' , /*5,4*/' ' , /*5,5*/' '
		};

		for (int move = 1; move < 10; move++) {

			int checkCase = 1, error = 0;
			// greetings and salutations
			if ((move == 1) && (game == 1)) {
				cout << "----------------------------------" << endl;
				cout << "|   Hello! & welcome to X || O.  |" << endl;
				cout << "|           Lets Play.           |" << endl;
				cout << "----------------------------------" << endl << endl;
			}
			if (game != 1){
			 cout << "----------------" << endl;
			 cout << "|   Game #" << game << ":   |" << endl;
			 cout << "----------------" << endl << endl;
			}

			cout << endl;
			pic(XOXO, move, winID, game);

			// determining turn by 'move % 2'
			if (move % 2 == 1) {
				turn = 1;
				cout << endl;
				cout << "Player 1 - 'X' (A/B/C + 1/2/3):" << endl;
			}
			else if (move % 2 == 0) {
				turn = 2;
				cout << endl;
				cout << "Player 2 - 'O' (A/B/C + 1/2/3):" << endl;
			}

			for (int valid = 0; valid == 0;) {
				// clearing cin buffer to avoid long nights
				std::cin.clear();

				cin >> letter >> num;
				error = check(letter, num, error);
				
				// unique error codes for nice user interactions
				if (error == 6) {
					cout << "Incorrect Letter & Number P" << turn << ". Try Again (A/B/C + 1/2/3):" << endl;
				}
				else if (error == 1) {
					cout << "Incorrect Letter P" << turn << ". Try Again (A/B/C + 1/2/3):" << endl;
				}
				else if (error == 5) {
					cout << "Incorrect number P" << turn << ". Try Again (A/B/C + 1/2/3):" << endl;
				}
				
				if (error == 0) {
					// after checking for correct input, input is converted to 6x6 board
					checkCase = 1;
					numLetter = convert(letter, numLetter, num, checkCase);
					checkCase = 2;
					num = convert(letter, numLetter, num, checkCase);
					
					if (XOXO[numLetter][num] != ' ') {
						cout << "Can't steal P" << turn << ". Try Again (A/B/C + 1/2/3):" << endl;
					}
					else { // exit loop when input is correct
						valid = 1;
					}
				}
				error = 0;
			}
			// print out 'X' or 'O' by turn
			if (turn == 1) {
				XOXO[numLetter][num] = 'X';
			}
			else if (turn == 2) {
				XOXO[numLetter][num] = 'O';
			}
			// checking for winner
			winID = winning (XOXO, turn, winID);

			// player 1 wins
			if (winID == 1) {
				cout << endl << endl;
				pic(XOXO, move, winID, game);
				cout << endl;
				cout << "Player 1 Wins!" << endl << endl;
				move = 10;

			}// player 2 wins
			else if (winID == 2) {
				cout << endl << endl;
				pic(XOXO, move, winID, game);
				cout << endl;
				cout << "Player 2 Wins!" << endl;
				move = 10;

			}// stalemate resault when nobody wins and no other moves to play
			else if ((winID == 0) && (move == 9)) {
				cout << endl << endl;
				pic(XOXO, move, winID, game);
				cout << endl;
				cout << "Stalemate. You both suck. Equaly." << endl << endl << endl;
			}
		}
		// another game starts if no nobody wins
		game++;
	}// sad farewells
	cout << "It was fun, really." << endl;
	cout << "Please come again. That's what she said." << endl << "I must go." << endl;
	return 0;
}