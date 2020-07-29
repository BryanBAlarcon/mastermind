#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include "MMclass.h"
#include "Combination.h"
#include "LoadSol.h"
 
using namespace std;

int main() {

	string loadgame; 
	cout << "Do you want to load a previous game? Please answer Yes or No" << endl; // ask the user if they want to load a previous game that
																					// that they have saved. 
	
	cin >> loadgame; // take user input as a string 
	cout << endl;

	if (loadgame == "Yes") { // if the user wants to load a previous game and asnwers yes 

		int turncounterfile; // declare variables
		int seedvaluefile; 

		ifstream LoadedFile; // create an object for the file we will use to load previous game. 

		LoadedFile.open("LoadFile.txt"); // open up the file 
		if (!LoadedFile.is_open()) { // check to make sure that the file exists and it is open. Exit if there is a problem. 
			cout << "Could not open file: " << "LoadFile.txt" << endl;
			cout << "Please make sure this file exists in the directory and try again" << endl;

			system("PAUSE");
			return 1;
		}

		LoadedFile >> turncounterfile; // take input from the file for the turn counter from the saved game. The loaded game will start from here
		LoadedFile >> seedvaluefile; // load in the time(0) value from the previous saved game. This will help us recreate the solution array. 

		LoadedFile.close(); // close file as we have no use for it now. 


		MMclass Game; //Declare an object of type MMclass which we will use later to output instructions to the console. 


		char answer[4]; // create the soltuion array of type char with length 4 
		char x;

		LoadSol solution2; // Declare an object of type LoadSol which will recreate the previous solution that the user was playing
		
		solution2.Setrandomtt(seedvaluefile); // we use the value we got from the save file so that our randomization has the same seed. 
											// this is key as this will let us recreate the solution without the user knowing what the array is. 
											// only the computer and program know how to use the number. 

		
 

		solution2.create(answer); // create the previous solution array from the "saved" game. 
								// The class will have more information. 

		

		Game.OutputInstructions(); // Outputs the instructions to the console

		char usercolors[4]; // create an array of type char of length 4 that stores the users input. 


		// uncomment this is you want to see the solution 
		
		for (int i = 0; i < 4; i++) {  

			cout << answer[i];
		}
		cout << endl;
		


		// int turncounter = 0;
		int black; // count the occurences that we get the right color in the right spot 
		int white; // count the occurences that we get the right color but it is not in the right spot. 
		bool winner = false; // variable declaration that changes when the user enters the correct guess. 

		string quit = "No"; // initialize quit to No so the while loop runs. 


		ofstream myfile; // create a new text file which will save user guesses which can be accessed by user later. 
		myfile.open("Mastermind.txt");

		// make sure the output file is open and working. 

		// Exception handling
		try {

			if (!myfile.is_open()) {

				throw runtime_error("Output file failed to open, program is exiting");

			}

		}
		catch (runtime_error& e) {

			cout << e.what() << endl;
		}


		// Output headers to the output file 
		myfile << "Try:  "; 
		myfile << "Your Guess:  ";
		myfile << "Checker/Verifier:  ";
		myfile << endl;


		// Beginning of while loop that runs the main portion of code. 
		// while loop will run until turncounterfile reaches 10 or the user wants to save and quit 
		while (turncounterfile != 10 && quit != "Yes") {
			turncounterfile++;



			// Tells the user the current try and tell them how to input their guess 
			cout << "Current try: " << turncounterfile << endl;
			cout << "Enter color combination by typing first letter of colors (R,B,Y,P,W,O): (Example:YBRR)" << endl;

			
			//output the current try to the output file 
			myfile << turncounterfile << "--     ";


			//User input for colors is stored with this for loop 
			for (int i = 0; i < 4; i++) {
				black = 0;							// set black and white at 0 so it resets everytime the while loop loops 
				white = 0;
				cin >> usercolors[i];


				
				myfile << usercolors[i] << " "; // output the user guess to the output file 


				// exception handling for if the user enters an invalid character, including a number. 
				try {
					if (usercolors[i] != 'R' && usercolors[i] != 'B' && usercolors[i] != 'Y' && usercolors[i] != 'P' && usercolors[i] != 'W' && usercolors[i] != 'O') {

						throw usercolors[i];
					}
				}
				catch (char x) {

					cout << x << " is not a valid color, please input a valid character from the instructions" << endl;

				}


			}


			// this for loop checks the user array to the solution array. 
			// Black and white are incremented depending color and position

			for (int i = 0; i < 4; i++) {
				if (usercolors[i] == answer[i]) //right color and position
					black = black + 1;
			
				else if (usercolors[i] == answer[0] || //right color wrong position
					usercolors[i] == answer[1] ||
					usercolors[i] == answer[2] ||
					usercolors[i] == answer[3]) {
					
						white = white + 1;
				
					}

				cout << " "; // add whitespace
			}


			myfile << "       "; // add whitespace to file 


			// this for loop outputs the total amount of black pegs to the console and the file 
			for (int i = 0; i < black; i++) {

				cout << "B "; 
				myfile << "B ";

			}

			// this for loop outputs the total amount of white pegs to the console and the file 
			for (int i = 0; i < white; i++) {
				cout << "W ";
				myfile << "W ";
			}

			// this for loop outputs the total amount of X, or blank pegs, to the console and the file 
			for (int i = 0; i < 4 - black - white; i++) {
				cout << "X ";
				myfile << "X ";
			}
			myfile << "        ";
			myfile << endl;
			cout << endl;


			// the below checks if the users' guess is  correct and if it is then it changes the condition to break out of the while loop
			if (usercolors[0] == answer[0] && //correct guess
				usercolors[1] == answer[1] &&
				usercolors[2] == answer[2] &&
				usercolors[3] == answer[3])
			{
				cout << "You win! Number of tries: " << turncounterfile << endl;
				turncounterfile = 10; // breaks out of while loop by changing condition
				winner = true; // breaks out of while loop by changing condition
			}
			else {
				cout << "Nope. Incorrect guess." << endl << endl; // Output to the user their guess is incorrect
			}

			cout << endl; // white space 
			myfile << endl;


			// while the user doesn't win, ask them after every turn if they would like to quit 
			if (winner == false && turncounterfile != 10) {
				cout << "Would you like to quit and save your game? Type Yes or No" << endl;
				cin >> quit;
				cout << endl;
			}

			// if the user wants to quit
			if (quit == "Yes") {

				cout << "Saving and quitting game. Run program again and choose to load game if you wish to continue" << endl;

				ofstream quitfile; // create a new file that will be used to load the game if the user wishes 
				quitfile.open("LoadFile.txt"); // name of the load file 

				quitfile << turncounterfile << endl; // outputs to the file at which point the user quit
				quitfile << seedvaluefile << endl; // outputs the seedvalue used so we can create the solution array again using
													// srand(seedvaluefile) 
				quitfile.close(); // close the file after using

			}

			// if the user wins, output this to the file. 
			if (winner == true) {
				myfile << "               YOU WON!!         ";
			}


		}

		myfile.close(); // close the main mastermind output file 


		// if the user gets to 10 guesses and doesn't win then the below outputs. 
		if (turncounterfile == 10 && winner == false) {
			cout << "You lost. Secret Combination is: " << endl;
			for (int i = 0; i < 4; i++) {
				cout << answer[i];
			}
			cout << endl;
		}

	}

	else if (loadgame == "No") { // if the user does not want to/does not have a file to load 


		MMclass Game; //Declare an object of type MMclass which we will use later to output instructions to the console. 


		char answer[4]; // initialize the solution array 
		char x;

		Combination solution; // create a class of type combination that will be used
							  // to create the solution array 

		solution.create(answer); // create the array for the solution


		// uncomment below to see the solution 
		for (int i = 0; i < 4; i++) {

			cout << answer[i];

		}
		

		cout << endl;

		int randomt = solution.Getrandomtt(); // store the time(0) value from Combination class
											  // if the user wants to quit and save, we will use this value to recreate
											  // the solution array when we load the game 

		

		Game.OutputInstructions(); // Outputs the instructions to the console

		char usercolors[4]; // create an array for the user guess

		// Uncomment below to see answer 
		
		for (int i = 0; i < 4; i++) { 

			cout << answer[i];
		}
		
		cout << endl;

		int turncounter = 0; // set turn counter = 0 
		int black; // initialize black pegs
		int white; // initialize white pegs 
		bool winner = false; // variable declaration that changes when the user enters the correct guess. 

		string quit = "No"; // initialize quit to No so the while loop runs. 


		ofstream myfile; // create a new text file which will save user guesses which can be accessed by user later.
		myfile.open("Mastermind.txt");

		// make sure the output file is open and working. 

		// Exception handling

		try {

			if (!myfile.is_open()) {

				throw runtime_error("Output file failed to open, program is exiting");

			}

		}
		catch (runtime_error& e) {

			cout << e.what() << endl;
		}


		// Output headers to the output file 
		myfile << "Try:  ";
		myfile << "Your Guess:  ";
		myfile << "Checker/Verifier:  ";
		myfile << endl;


		// Beginning of while loop that runs the main portion of code. 
		// while loop will run until turncounterfile reaches 10 or the user wants to save and quit 
		while (turncounter != 10 && quit != "Yes") {
			
			turncounter++; // increment the turn counter 

			// Tells the user the current try and tell them how to input their guess 
			cout << "Current try: " << turncounter << endl;
			cout << "Enter color combination by typing first letter of colors (R,B,Y,P,W,O): (Example:YBRR)" << endl;

			//output the current try to the output file 
			myfile << turncounter << "--     ";

			//User input for colors is stored with this for loop 
			for (int i = 0; i < 4; i++) {
				black = 0;			// set black and white at 0 so it resets everytime the while loop loops
				white = 0;
				cin >> usercolors[i];


				myfile << usercolors[i] << " "; // output the user guess to the output file


				// exception handling for if the user enters an invalid character, including a number. 
				try {
					if (usercolors[i] != 'R' && usercolors[i] != 'B' && usercolors[i] != 'Y' && usercolors[i] != 'P' && usercolors[i] != 'W' && usercolors[i] != 'O') {

						throw usercolors[i];
					}
				}
				catch (char x) {

					cout << x << " is not a valid color, please input a valid character from the instructions" << endl;

				}


			}


			// this for loop checks the user array to the solution array. 
			// Black and white are incremented depending color and position
			for (int i = 0; i < 4; i++) {
				if (usercolors[i] == answer[i]) //right color and position
					black = black + 1;

				else if (usercolors[i] == answer[0] || //right color wrong position
					usercolors[i] == answer[1] ||
					usercolors[i] == answer[2] ||
					usercolors[i] == answer[3]) {
					white = white + 1;
				}

				cout << " "; // add whitespace
			}


			myfile << "       "; // add whitespace


			// this for loop outputs the total amount of black pegs to the console and the file
			for (int i = 0; i < black; i++) {

				cout << "B ";
				myfile << "B ";

			}
			// this for loop outputs the total amount of white pegs to the console and the file 
			for (int i = 0; i < white; i++) {
				cout << "W ";
				myfile << "W ";
			}
			// this for loop outputs the total amount of X, or blank pegs, to the console and the file 
			for (int i = 0; i < 4 - black - white; i++) {
				cout << "X ";
				myfile << "X ";
			}

			myfile << "        ";
			myfile << endl;
			cout << endl;

			// the below checks if the users' guess is  correct and if it is then it changes the condition to break out of the while loop
			if (usercolors[0] == answer[0] && //correct guess
				usercolors[1] == answer[1] &&
				usercolors[2] == answer[2] &&
				usercolors[3] == answer[3])
			{
				cout << "You win! Number of tries: " << turncounter << endl;
				turncounter = 10; // breaks out of while loop by changing condition
				winner = true; // breaks out of while loop by changing condition
			}
			else {
				cout << "Nope. Incorrect guess." << endl << endl; // Output to the user their guess is incorrect
			}
			cout << endl;



			myfile << endl;

			// while the user doesn't win, ask them after every turn if they would like to quit 
			if (winner == false && turncounter != 10) {
				cout << "Would you like to quit and save your game? Type Yes or No" << endl;
				cin >> quit;
				cout << endl;
			}

			// If the user would like to quit 
			if (quit == "Yes") {

				cout << "Saving and quitting game. Run program again and choose to load game if you wish to continue" << endl;

				ofstream quitfile; // create a new file that will be used to load the game if the user wishes
				quitfile.open("LoadFile.txt"); /// Name of the load file 

				quitfile << turncounter << endl; // outputs to the file at which point the user quit
				quitfile << randomt << endl; // outputs the seedvalue used so we can create the solution array again using
											// srand(seedvaluefile)
				quitfile.close(); // close the file after we're done using

			}

			// if the user wins, output this to the file.
			if (winner == true) {
				myfile << "               YOU WON!!         ";
			}


		}

		myfile.close(); // close the main mastermind output file 


		// if the user gets to 10 guesses and doesn't win then the below outputs. 
		if (turncounter == 10 && winner == false) {
			cout << "You lost. Secret Combination is: " << endl;
			for (int i = 0; i < 4; i++) {
				cout << answer[i];
			}
			cout << endl;
		}

	}

	system("PAUSE");
	return 0;
}