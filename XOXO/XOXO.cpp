#include <iostream>

using namespace std;

//Function declerations
int drawB (char XOXO[6][6]);
int ili (char temp1, int temp11, int temp2, int move, int error, int run, char XOXO[6][6]);
int win (char XOXO[6][6], int turn, int winID);

//'drawB' function for drawing the board in the begining, each move and end of the game
int drawB (char XOXO[6][6]) {

	for (int i = 0; i < 6; i++) {

		cout << " " << XOXO[i][0] << "   " << XOXO[i][1] << "   " << XOXO[i][2] << "   " << XOXO[i][3] << "   " << XOXO[i][4] << "   " << XOXO[i][5] << endl<< endl;
	}

	return 1;
}


//'ili' function checks each move for validity (taken space?)
int ili (char temp1, int temp11, int temp2, int move, int error, int run, char XOXO[6][6]) {

	int illeg = 9;
	
	// letter check and conversion
	if ((run == 1) || (run == 2)) {

		if (run == 1) {

			if ((temp1 != 'A') && (temp1 != 'B') && (temp1 != 'C')) {

				cout << "Please choose a correct character (A || B || C):" << endl;
					move--;
					error = 1;
					
			}
			else {

				if (temp1 == 'A') {

					temp11 = 1;
					
				}
				else if (temp1 == 'B') {

					temp11 = 3;
					
				}
				else if (temp1 == 'C') {

					temp11 = 5;
					
				}
				return temp11;
			}
		
	    } // number check and conversion
		else if (run == 2) {

			if (temp2 == 2) {

				temp2 = 3;
				return temp2;
			}
			else if (temp2 == 3) {

				temp2 = 5;
				return temp2;
			}
			else if (temp2 == 1) {

				return temp2;
			}
			else {

				cout << "Please choose a correct number for " << temp1 << " + " << "(1 || 2 || 3):" << endl;

				if (error == 0) {

					move--;
					
				}

				illeg = 0;
				return illeg;
			}


		}
		}		
		else if (run == 3) {
		if ((XOXO[temp11][temp2] != ' ')) {

			illeg = 0;
			return illeg;
		}
		else {

			if (temp11 == 1) {

				if ((temp2 != 1) && (temp2 != 3) && (temp2 != 5)) {

					illeg = 0;

				}
				
			}
			else if (temp11 == 3) {

				if ((temp2 != 1) && (temp2 != 3) && (temp2 != 5)) {

					illeg = 0;

				}
				
			}
			else if (temp11 == 5) {

				if ((temp2 != 1) && (temp2 != 3) && (temp2 != 5)) {

					illeg = 0;

				}
				
			}
			return illeg;
		}
	}
	
}

//'win' function checks after every move if there's a winner
int win(char XOXO[6][6], int turn, int winID) {




























	// loop for across checking
	for (int z = 1; z < 6; z += 2) {

		// left to right
		if (((XOXO[z][1] != ' ')) && ((XOXO[z][1]) == (XOXO[z][3])) && (XOXO[z][3]) == (XOXO[z][5])) {

			if (turn == 1) {

				winID = 1;

			}
			else {

				winID = 2;

			}
			XOXO[z][4] = XOXO[z][2] = '-';
			XOXO[0][0] = '*';
		}

		// top to bottom
		if (((XOXO[1][z] != ' ')) && ((XOXO[1][z]) == (XOXO[3][z])) && (XOXO[3][z]) == (XOXO[5][z])) {

			if (turn == 1) {  

				winID = 1;

			}
			else {

				winID = 2;

			}
			XOXO[2][z] = XOXO[4][z] = '|';
			XOXO[0][0] = '*';
		}
	}

	// middle descending
	if (((XOXO[1][1] != ' ')) && ((XOXO[1][1]) == (XOXO[3][3])) && (XOXO[3][3]) == (XOXO[5][5])) {

		if (turn == 1) {

			winID = 1;
		}
		else {


			winID = 2;
		}

		XOXO[2][2] = XOXO[4][4] = '\'';
		XOXO[0][0] = '*';

	} // middle ascending
	else if (((XOXO[5][1] != ' ')) && ((XOXO[5][1]) == (XOXO[3][3])) && (XOXO[3][3]) == (XOXO[1][5])) {

		if (turn == 1) {

			winID = 1;
		}
		else {


			winID = 2;
		}

		XOXO[4][2] = XOXO[2][4] = '/';
		XOXO[0][0] = '*';

	}

	return winID;
}



int main() {

	int game = 1;

	for (int winner = 0; winner == 0;) {

		int round = 0, winID = 0, illeg = 1, error = 0, temp11 = 0, temp2 = 0, run = 1;
		char temp1 = ' ';

		// 6X6 XO board
		char XOXO[6][6] = {  /*0,0*/' ' , /*0,1*/'1' , /*0,2*/' ' , /*0,3*/'2' , /*0,4*/' ' , /*0,5*/'3' , 

							 /*1,0*/'A' , /*1,1*/' ' , /*1,2*/' ' , /*1,3*/' ' , /*1,4*/' ' , /*1,5*/' ' , 

							 /*2,0*/' ' , /*2,1*/' ' , /*2,2*/' ' , /*2,3*/' ' , /*2,4*/' ' , /*2,5*/' ' ,  

							 /*3,0*/'B' , /*3,1*/' ' , /*3,2*/' ' , /*3,3*/' ' , /*3,4*/' ' , /*3,5*/' ' , 

						     /*4,0*/' ' , /*4,1*/' ' , /*4,2*/' ' , /*4,3*/' ' , /*4,4*/' ' , /*4,5*/' ' ,  

							 /*5,0*/'C' , /*5,1*/' ' , /*5,2*/' ' , /*5,3*/' ' , /*5,4*/' ' , /*5,5*/' ' 
		};

		char winCheck[9] = { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' };



		if (game == 1) {

			cout << "Hi! & welcome to X || O." << endl;
		}
		else if (game > 1) {

			cout << "Game #" << game << ":" << endl;
		}

		cout << "Lets play." << endl << endl;


		//XO for loop for moves 1 to 10 = max moves on 3x3
		for (int move = 1; move < 10; move++) {

			
			int turn = 0;

			if (move % 2 != 0) {
				turn = 1;
			}
			else if (move % 2 == 0) {
				turn = 2;
			}


			if (turn == 1) {

				cout << endl;
				drawB(XOXO);
				cout << endl;
				cout << "Player 1 'X' (A/B/C + 1/2/3):" << endl;
			}
			else if (turn == 2) {

				
				cout << endl;
				drawB(XOXO);
				cout << endl;
				cout << "Player 2 'O' (A/B/C + 1/2/3):" << endl;
			}



			int succ = 0;
			while (succ == 0) {

				// clearing cin buffer to avoid long nights
				std::cin.clear();

				// letter input
				cin >> temp1;

				temp11 = ili(temp1, temp11, temp2, move, error, run, XOXO);

				if (temp11 != 0) {

					succ = 1;
					run = 2;

				}
				else {

					
				}
			}
			
			run = 2;
			
			succ = 0;
			while (succ == 0) {

				// clearing cin buffer to avoid long nights
				std::cin.clear();

				temp2 = 0;

				// number input
				cin >> temp2;

				temp2 = ili(temp1, temp11, temp2, move, error, run, XOXO);

				if (temp2 != 0) {

					succ = 1;
				}
				else {


				}
			}
			
			run = 3;

			succ = 0;
			while (succ != 1) {

				illeg = ili(temp1, temp11, temp2, move, error, run, XOXO);
				

				if (illeg != 0) {

					if (turn == 1) {

						XOXO[temp11][temp2] = 'X';
					}
					else if (turn == 2) {

						XOXO[temp11][temp2] = 'O';

					}

					
				}
				else if (illeg == 0) {

					cout << "Illegl. Try again:" << endl;

					if (error == 0) {

						move--;
					}
					
				}

				succ = 1;
			}
			run = 1;
			
			
			winID = win(XOXO, turn, winID);
			
			cout << "hi" << endl;

			if (winID == 1) {

				drawB(XOXO);
				cout << "Player 1 Wins!" << endl << endl;
				winner = 1;
				move = 10;
			}
			else if (winID == 2) {

				drawB(XOXO);
				cout << "Player 2 Wins!" << endl;
				winner = 2;
				move = 10;
			}
			else if ((winID == 0) && (move == 9)) {

				drawB(XOXO);
				cout << "Stalemate. You both suck." << endl << endl << endl;
				
			}

			
		}
		game++;
	}
	
	cout << "It was fun, really." << endl << "Please come again. That's what she said." << endl << "I must go." << endl;

	return 1;
}