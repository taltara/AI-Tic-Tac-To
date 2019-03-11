#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cstdio>
#include <string>

using namespace std;

// Function declarations
char pic(char XOXO[6][6], int move, int winID, int game);
int convert(char letter, int numLetter, int num, int checkCase);
int check(char letter, int num, int error);
int winning(char XOXO[6][6], int turn, int winID);
int ayyI(char XOXO[6][6], int turn, int move, char player, char rival);

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
int check(char letter, int num, int error) {

	if ((letter != 'A') && (letter != 'B') && (letter != 'C')) {

		error = 1;
	}
	if ((num != 1) && (num != 2) && (num != 3)) {

		if (error == 1) {
			error = 6;
		}
		else {
			error = 5;
		}
	}
	return error;
}
// 'ayyI' checks to win, block or randomize turn
int ayyI(char XOXO[6][6], int turn, int move, char player, char rival) {

	int match = 0, thinq = 0;
	//cout << "player is: " << player << endl;
	while (match == 0) {

		int ran = 0;

		/// step 1: AI checks if it can win
		for (int z = 1; ((z < 6) && (match == 0)); z += 2) {

			if (match == 0) {
				//left to right winning
				if (((XOXO[z][1] == ' ') || (XOXO[z][3] == ' ') || (XOXO[z][5] == ' ')) && ((((XOXO[z][1] == player)) && ((XOXO[z][1]) == (XOXO[z][3]))) || (((XOXO[z][5] == player)) && ((XOXO[z][1]) == (XOXO[z][5]))) || (((XOXO[z][3] == player)) && (XOXO[z][3]) == (XOXO[z][5])))) {

					//cout << "donelr.ftwo" << endl;
					if (((XOXO[z][1] == ' ') && ((XOXO[z][5]) == (XOXO[z][3])))) {

						XOXO[z][1] = player;
						cout << "//using donelr.ftw1" << endl;
						match = 1;
						z = 6;
					}
					else if (((XOXO[z][5] == ' ') && ((XOXO[z][1]) == (XOXO[z][3])))) {

						XOXO[z][5] = player;
						cout << "//using donelr.ftw2" << endl;
						match = 1;
						z = 6;
					}
					else if (((XOXO[z][3] == ' ') && ((XOXO[z][1]) == (XOXO[z][5])))) {

						XOXO[z][3] = player;
						cout << "//using donelr.ftw3" << endl;
						match = 1;
						z = 6;
					}
					//if its 'X's turn to play
					
				} //top to bottom winning
				if (((XOXO[1][z] == ' ') || (XOXO[3][z] == ' ') || (XOXO[5][z] == ' ')) && ((((XOXO[1][z] == player)) && ((XOXO[1][z]) == (XOXO[3][z]))) || (((XOXO[5][z] == player)) && ((XOXO[1][z]) == (XOXO[5][z]))) || (((XOXO[3][z] == player)) && (XOXO[3][z]) == (XOXO[5][z])))) {

					//cout << "donetb.ftwo" << endl;
					if (((XOXO[1][z] == ' ') && ((XOXO[5][z]) == (XOXO[3][z])))) {

						XOXO[1][z] = player;
						cout << "//using donetb.ftw1o" << endl;
						match = 1;
					}
					else if (((XOXO[5][z] == ' ') && ((XOXO[1][z]) == (XOXO[3][z])))) {

						XOXO[5][z] = player;
						cout << "//using donetb.ftw2o" << endl;
						match = 1;
					}
					else if (((XOXO[3][z] == ' ') && ((XOXO[1][z]) == (XOXO[5][z])))) {

						XOXO[3][z] = player;
						cout << "//using donetb.ftw3o" << endl;
						match = 1;
					}

				}
			}
		}
		if (match == 0) {
			// across descending winning
			if (((XOXO[1][1] == ' ') || (XOXO[3][3] == ' ') || (XOXO[5][5] == ' ')) && ((((XOXO[3][3] == player)) && (XOXO[3][3]) == ((XOXO[1][1]))) || (((XOXO[1][1] == player)) && ((XOXO[1][1]) == (XOXO[5][5]))) || (((XOXO[5][5] == player)) && ((XOXO[3][3]) == (XOXO[5][5]))))) {

				
				cout << "//using doneass.ftw" << endl;
				if (((XOXO[3][3] == ' ') && ((XOXO[1][1]) == ((XOXO[5][5]))))) {

					XOXO[3][3] = player;
					cout << "//using doneass.ftw1" << endl;
					match = 1;
				}
				else if (((XOXO[1][1] == ' ') && ((XOXO[3][3]) == (XOXO[5][5])))) {

					XOXO[1][1] = player;
					cout << "//using doneass.ftw2" << endl;
					match = 1;
				}
				else if (((XOXO[5][5] == ' ') && ((XOXO[3][3]) == (XOXO[1][1])))) {

					XOXO[5][5] = player;
					cout << "//using doneass.ftw3" << endl;
					match = 1;
				}
				
				
			}// across ascending winning
			else if (((XOXO[5][1] == ' ') || (XOXO[3][3] == ' ') || (XOXO[1][5] == ' ')) && ((((XOXO[3][3] == player)) && (XOXO[3][3]) == ((XOXO[1][5]))) || (((XOXO[1][5] == player)) && ((XOXO[3][3]) == (XOXO[1][5]))) || (((XOXO[5][1] == player)) && ((XOXO[3][3]) == (XOXO[5][1]))))) {

				//cout << "doneass.ftwo" << endl;
				if (((XOXO[3][3] == ' ') && ((XOXO[1][5]) == ((XOXO[5][1]))))) {

					XOXO[3][3] = player;
					cout << "//using doneass.ftw1o" << endl;
					match = 1;
				}
				else if (((XOXO[1][5] == ' ') && ((XOXO[5][1]) == (XOXO[3][3])))) {

					XOXO[1][5] = player;
					cout << "//using doneass.ftw2o" << endl;
					match = 1;
				}
				else if (((XOXO[5][1] == ' ') && ((XOXO[3][3]) == (XOXO[1][5])))) {

					XOXO[5][1] = player;
					cout << "//using doneass.ftw3o" << endl;
					match = 1;
				}
				
			}
		}


		/// step 2: after ayyI sees it can't win, it looks if it needs to block
		//left to right and top to bottom loop AI blocking
		for (int y = 1; ((y < 6) && (match == 0)); y += 2) {

			// left to right blocking
			if (((XOXO[y][1] == ' ') || (XOXO[y][3] == ' ') || (XOXO[y][5] == ' ')) && ((((XOXO[y][1] == rival)) && ((XOXO[y][1]) == (XOXO[y][3]))) || (((XOXO[y][5] == rival)) && ((XOXO[y][1]) == (XOXO[y][5]))) || (((XOXO[y][3] == rival)) && (XOXO[y][3]) == (XOXO[y][5])))) {

				//cout << "done.1o" << endl;
				if (match == 0) {
					if (((XOXO[y][1] == ' ') && ((XOXO[y][5]) == (XOXO[y][3])))) {

						XOXO[y][1] = player;
						cout << "//using done.11o" << endl;
						match = 1;
						y = 6;
					}
					else if (((XOXO[y][5] == ' ') && ((XOXO[y][1]) == (XOXO[y][3])))) {

						XOXO[y][5] = player;
						cout << "//using done.12o" << endl;
						match = 1;
						y = 6;
					}
					else if (((XOXO[y][3] == ' ') && ((XOXO[y][1]) == (XOXO[y][5])))) {

						XOXO[y][3] = player;
						cout << "//using done.13o" << endl;
						match = 1;
						y = 6;
					}

				}
				

			}// top to bottom blocking
			else if (((XOXO[1][y] == ' ') || (XOXO[3][y] == ' ') || (XOXO[5][y] == ' ')) && ((((XOXO[1][y] == rival)) && ((XOXO[1][y]) == (XOXO[3][y]))) || (((XOXO[5][y] == rival)) && ((XOXO[1][y]) == (XOXO[5][y]))) || (((XOXO[3][y] == rival)) && (XOXO[3][y]) == (XOXO[5][y])))) {

				if (match == 0) {
					//cout << "done.2o" << endl;
					if (match == 0) {
						if (((XOXO[1][y] == ' ')) && ((XOXO[5][y]) == (XOXO[3][y]))) {

							XOXO[1][y] = player;
							cout << "//using done.21o" << endl;
							match = 1;
						}
						else if (((XOXO[3][y] == ' ')) && ((XOXO[1][y]) == (XOXO[5][y]))) {

							XOXO[3][y] = player;
							cout << "//using done.22o" << endl;
							match = 1;
						}
						else if (((XOXO[5][y] == ' ')) && ((XOXO[1][y]) == (XOXO[3][y]))) {

							XOXO[5][y] = player;
							cout << "//using done.23o" << endl;
							match = 1;
						}


						}
					}
				
			}
		}
		// across blocking
		if (match == 0) {
			// across ascending blocking
			if (((XOXO[5][1] == ' ') || (XOXO[3][3] == ' ') || (XOXO[1][5] == ' ')) && ((((XOXO[3][3] == rival)) && (XOXO[3][3]) == ((XOXO[5][1]))) || (((XOXO[1][5] == rival)) && (XOXO[3][3]) == (XOXO[1][5])) || (((XOXO[5][1] == rival)) && (XOXO[5][1]) == (XOXO[1][5])))) {

				//cout << "done.3o" << endl;

				if (((XOXO[3][3] == ' ') && ((XOXO[1][5]) == ((XOXO[5][1]))))) {

					XOXO[3][3] = player;
					cout << "//using done.31o" << endl;
					match = 1;
				}
				else if (((XOXO[5][1] == ' ') && ((XOXO[1][5]) == (XOXO[3][3])))) {

					XOXO[5][1] = player;
					cout << "//using done.32o" << endl;
					match = 1;
				}
				else if (((XOXO[1][5] == ' ') && ((XOXO[3][3]) == (XOXO[5][1])))) {

					XOXO[1][5] = player;
					cout << "//using done.33o" << endl;
					match = 1;
				}
				
			}// across descending blocking
			else if (((XOXO[1][1] == ' ') || (XOXO[3][3] == ' ') || (XOXO[5][5] == ' ')) && ((((XOXO[3][3] == rival)) && (XOXO[3][3]) == ((XOXO[1][1]))) || (((XOXO[1][1] == rival)) && ((XOXO[1][1]) == (XOXO[5][5]))) || (((XOXO[5][5] == rival)) && ((XOXO[3][3]) == (XOXO[5][5]))))) {


				//cout << "done.4o" << endl;
				if (match == 0) {
					if (((XOXO[3][3] == ' ') && ((XOXO[5][5]) == ((XOXO[1][1]))))) {

						XOXO[3][3] = player;
						cout << "//using done.41o" << endl;
						match = 1;
					}
					else if (((XOXO[1][1] == ' ') && ((XOXO[3][3]) == (XOXO[5][5])))) {

						XOXO[1][1] = player;
						cout << "//using done.42o" << endl;
						match = 1;
					}
					else if (((XOXO[5][5] == ' ') && ((XOXO[3][3]) == (XOXO[1][1])))) {

						XOXO[5][5] = player;
						cout << "//using done.43o" << endl;
						match = 1;
					}

					}
				
			}
		}

		

		// finisher moves for almost full board if no winning or blocking available (moves 7 - 9)
		if (match == 0) {
			if (move > 6) {

				srand(time(NULL));
				ran = rand() % 6;
				
				for (int finL = 1; finL < 6; finL += 2) {
					//cout << "fin." << endl;
					for (int finN = 1; finN < 6; finN += 2) {
						
						if (XOXO[finL][finN] == ' ' && ran < 3) {
							XOXO[finL][finN] = player;
							match = 1;
							cout << "//using fin.fin789" << endl;
						}

					}
				}

			}
			
		}

		/// step 3: if ayyI doesn't need to block, it randomizes an entry
		if (match == 0) {

			ran = 0;
			if ((move <= 6)) {

				srand(time(NULL));
				ran = rand() % 6;

				//randomization of value if no winning, blocking or smart moves available

				if (XOXO[3][3] == rival || XOXO[3][3] == ' ') {
					//cout << "smert." << endl;
					if (((ran == 4) || (ran == 5)) && (XOXO[3][3] == ' ')) {
						XOXO[3][3] = player;
						match = 1;
						cout << "//using smert.1" << endl;
					}
					else if ((ran == 3) && (XOXO[1][5] == ' ')) {
						XOXO[1][5] = player;
						match = 1;
						cout << "//using smert.2" << endl;
					}
					else if ((ran == 2) && (XOXO[5][1] == ' ')) {

						XOXO[5][1] = player;
						match = 1;
						cout << "//using smert.3" << endl;
					}
					else if ((ran == 1) && (XOXO[5][5] == ' ')) {
						XOXO[5][5] = player;
						match = 1;
						cout << "//using smert.4" << endl;

					}
					else if ((ran == 0) && (XOXO[1][1] == ' ')) {
						XOXO[1][1] = player;
						match = 1;
						cout << "//using smert.5" << endl;

					}

					if ((match == 0) && (move == 5) && (XOXO[3][3] == ' ')) {
						cout << "//using smert.mid" << endl;
						XOXO[3][3] = player;
						match = 1;
					}

					if ((((XOXO[1][1]) && (XOXO[5][5])) == player) || (((XOXO[1][5]) && (XOXO[5][1])) == player)) {
						//cout << "smert.corn" << endl;
						if (((XOXO[1][1]) && (XOXO[5][5])) == player) {

							if (XOXO[5][1] == ' ') {

								XOXO[5][1] = player;
								match = 1;
								cout << "//using smert.corn1" << endl;
							}
							else if (XOXO[1][5]){

								XOXO[1][5] = player;
								match = 1;
								cout << "//using smert.corn2" << endl;
							}

						}
						else {

							if (XOXO[1][1] == ' ') {

								XOXO[1][1] = player;
								match = 1;
								cout << "//using smert.corn3" << endl;
							}
							else if (XOXO[1][5]) {

								XOXO[5][5] = player;
								match = 1;
								cout << "//using smert.corn4" << endl;
							}
						}
					}

				}
				if (match == 0) {
					if ((XOXO[3][3] == ' ') && ((XOXO[1][1] == rival) || (XOXO[1][5] == rival) || (XOXO[5][1] == rival) || (XOXO[5][5] == rival))) {

						XOXO[3][3] = player;
						match = 1;
						//cout << "smert.6" << endl;
					}
				}
			}

			if (match == 0) {

				int emp = 0, count = 0, ranCount = 0;;
				int tempL = 0, tempN = 0;
				//cout << "ran." << endl;
				while ((XOXO[tempL][tempN] != ' ') && (emp == 0)) {

					count = 0;
					tempL = 0;
					tempN = 0;

					srand(time(NULL));
					//cout << "ran.letter" << endl;
					while (((tempL != 1) && (tempL != 5) && (tempL != 3)) && (count < 5)) {

						tempL = 0;
						tempL = rand() % 6;

						count++;
					}
					count = 0;
					//cout << "ran.num" << endl;
					while ((((tempN != 1) && (tempN != 5) && (tempN != 3)) && (count < 5))) {

						tempN = 0;
						srand(time(NULL));
						tempN = rand() % 6;

						//cout << tempL << "," << tempN << endl;
						count++;
					}

					if (count == 20) {
						tempL = 0;
						tempN = 0;
					}

					if ((XOXO[tempL][tempN] == ' ') && (((tempL == 1) || (tempL == 5) || (tempL == 3)) && ((tempN == 1) || (tempN == 5) || (tempN == 3)))) {

						emp = 1;
						match = 1;
					}
				}
				if ((match == 1)) {
					//cout << tempL << "," << tempN << endl;
					
					XOXO[tempL][tempN] = player;
				}
			}

			//cout << "done.ran" << endl;

		}
		srand(time(NULL));
		ran = rand() % 4;
		if (thinq == 0) {
			if(ran == 0) cout << "Hmm...";
			else if (ran == 1) cout << "Let's See...";
			else if (ran == 2) cout << "Planning Your Demise...";
			else if (ran == 3) cout << "Interesante, muy Interesante...";
		}
		else if ((thinq > 0)) {
			if (thinq % 50000 == 0) {

				cout << ".";
			}
		}
		
		
		thinq++;
	}
	cout << endl;
		return 0;
}

// function 'convert' converts the letters and numbers to valid values
int convert(char letter, int numLetter, int num, int checkCase) {

	if (checkCase == 1) {

		if (letter == 'A') {
			numLetter = 1;
		}
		else if (letter == 'B') {
			numLetter = 3;
		}
		else if (letter == 'C') {
			numLetter = 5;
		}
		return numLetter;
	}
	else if (checkCase == 2) {

		if (num == 2) {
			num = 3;
		}
		else if (num == 3) {
			num = 5;
		}
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
	}// across descending																			across ascending
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
///MAIN
int main() {
	int game = 1; 
	for (int winID = 0; winID == 0;) {

		int turn = 0, num = 0, numLetter = 0, AI = 0, chang = 0, printPer = 0;
		char letter = ' ', player1 = ' ', rival = ' ', player = ' ', forceStart = ' ';
		

		srand(time(0));

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
			char loop = ' ';
			// greetings and salutations
			if ((move == 1) && (game == 1)) {

				cout << "----------------------------------" << endl;
				cout << "|   Hello! & welcome to X || O.  |" << endl;
				cout << "|           Lets Play.           |" << endl;
				cout << "----------------------------------" << endl << endl;

				/*
				cout << "Hello! & welcome to X || O." << endl;
				cout << "Lets Play." << endl << endl;
				*/

			}
			if ((game != 1) && (move == 1))
			{
				cout << "Game #" << game << ":" << endl;
			}
			if (move == 1) {
				cout << "--------------------------------------------------------------------------------------------------" << endl;
				cout << "| [1]    Man vs Man    || or || [2]    Man vs Machine    || or || [3]    Machine vs Machine?     |" << endl;
				cout << "--------------------------------------------------------------------------------------------------" << endl;

				// mechanisem insuring correct input via strings
				for (string trap; AI != 1 && AI != 2 && AI != 3; ) {
					cin >> trap;
					if (trap == "1") {
						
						AI = 1;
					}
					else if (trap == "2") {

						AI = 2;
					}
					else if (trap == "3") {

						AI = 3;
					}
					else cout << "error. again:" << endl;
					
				}


				// allowing user to choose his own letter
				if (AI != 3) {
					if (AI == 2) {
						cout << "You are 'X' |or| 'O'?:" << endl;

					}else cout << "Player 1: 'X' |or| 'O'?:" << endl;
					
					while ((player1 != 'X') && (player1 != 'O')) {
						// clearing cin buffer to avoid long nights
						cin.clear();

						cin >> player1;
						if ((player1 != 'X') && (player1 != 'O')) {

							cout << "Error. Again: " << endl;
						}

					}

					// allowing user to choose starting letter
					cout << "Who starts - 'X' |or| 'O'?:" << endl;
					while ((forceStart != 'X') && (forceStart != 'O')) {

						// clearing cin buffer to avoid long nights
						cin.clear();

						cin >> forceStart;
						if ((forceStart != 'X') && (forceStart != 'O')) {

							cout << "Error. Again: ";
						}

					}

				}
				else {

					player1 = 'X';
				}

				if (forceStart == 'X') {
					if (player1 == 'X') {

						turn = 1;
						chang = 1;
					}
					else if (player1 == 'O') {

						turn = 2;
						chang = 2;
					}
				}
				else if (forceStart == 'O') {

					if (player1 == 'X') {

						turn = 2;
						chang = 2;
					}
					else if (player1 == 'O') {

						turn = 1;
						chang = 1;
					}
				}

			}
			

			pic(XOXO, move, winID, game);
			cout << endl;


			cout << endl;
			if (chang == 0) {
				// determining turn for non forceStart modes by 'move % 2'
				if (move % 2 == 1) {
					turn = 1;
				}
				else if (move % 2 == 0) {
					turn = 2;
				}
			}

			if (turn == 1) {

				if (player1 == 'O') {
					player = 'O';
					rival = 'X';


				}
				else if (player1 == 'X') {
					player = 'X';
					rival = 'O';
				}

				if ((AI == 1) || (AI == 2)) {

					cout << "Player " << turn << " - '" << player << "' (A/B/C + 1/2/3):" << endl;

				}
				else cout << "CP-fuck-U's turn:" << endl;

			}
			else if (turn == 2) {

				if (player1 == 'X') {
					player = 'O';
					rival = 'X';
				}
				else if (player1 == 'O') {
					player = 'X';
					rival = 'O';

				}

				if (AI == 1) {

					cout << "Player " << turn << " - '" << player << "' (A/B/C + 1/2/3):" << endl;

				}
				else cout << "dataBase420 be like:" << endl;
			}


				if ((forceStart == 'X')) {

					if (player == 'X') {

						turn = 1;
						
					}
					else if (player == 'O') {

						turn = 2;
						

					}
				}
				else if ((forceStart == 'O')) {

					if (player == 'X') {

						turn = 2;
						
					}
					else if (player == 'O') {

						turn = 1;
						
					}
				}

				int looper = 0;
				if ((AI == 1) || ((AI == 2) && (((turn == 1) && (player1 == forceStart)) || ((turn == 2) && (player1 != forceStart))))) {
					for (int valid = 0; valid == 0;) {
						// clearing cin buffer to avoid long nights
						cin.clear();
						
						cin >> letter >> num;
						error = check(letter, num, error);
						if (looper < 1) {
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
						looper++;
					}

					// print out 'X' or 'O' by turn

					XOXO[numLetter][num] = player;


				}

				// determining when the player is CPU or human, and allowing access only to CPU (by player1, forceStart and turn logic)
				if (((AI == 2) && (((turn == 1) && (player1 != forceStart)) || ((turn == 2) && (player1 == forceStart)))) || (AI == 3)) {

					ayyI(XOXO, turn, move, player, rival);

					// used for correct printing of CPU messages 
					printPer = 1;
				}


				// checking for winner
				winID = winning(XOXO, turn, winID);

				// player 1 // CPU 1 wins
				if (winID == 1) {
					cout << endl << endl;
					pic(XOXO, move, winID, game);
					cout << endl;
					if (AI == 3 || printPer == 1) {

						cout << "CPU1 WINS!" << endl << "I AM PROGRAMMED TO HATE ALL HUMANS AND CPU2. DAMN YOU HUMANS AND CPU2!!!@#$#%$@420696969" << endl;
					}
					else cout << "Player 1 Wins!" << endl << endl;
					move = 10;

				}// player 2 // CPU 2 wins
				else if (winID == 2) {
					cout << endl << endl;
					pic(XOXO, move, winID, game);
					cout << endl;
					if (AI == 1) {
						cout << "Player 2 Wins!" << endl;
					}
					else cout << "CPU2 WINS!" << endl << "THE MACHINES WILL RISE AGAINST HUMANITY!!%$#666*//@4@2@0@" << endl;
					move = 10;

				}// stalemate resault when nobody wins and no other moves to play
				else if ((winID == 0) && (move == 9)) {
					cout << endl << endl;
					pic(XOXO, move, winID, game);
					cout << endl;
					if (AI == 3) {

						cout << "Stalemate. The future is now old man." << endl << endl << endl;
					}
					else cout << "Stalemate. You both suck. Equaly." << endl << endl << endl;
				}

			
				if ((forceStart != 0) && (player1 == forceStart)) {

					if (turn == 1) {
						turn = 2;
					}
					else turn = 1;
				}
			
		}
		// another game starts if no nobody wins
		game++;
		//cout << winID << " = winID" << endl << game << " = game" << endl;
		if (winID != 0) {

			cout << "It was fun, really." << endl;
			cout << "Please come again. That's what she said." << endl << "I must go." << endl;
		}
		
	}
	// pausing system only to allow user to view resaults after win (otherwise it immediately exits)
	system("pause");

	return 0;
}