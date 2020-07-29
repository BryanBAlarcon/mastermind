#pragma once
#ifndef MMclass_H
#define MMclass_H

#include <string>
#include <iostream>

using namespace std;

class MMclass {

	public:

		// the below class function outputs the instructions to the console.
		void OutputInstructions() {

			cout << "Welcome to MasterMind" << endl << endl;
			cout << "OBJECTIVE: " << endl;
			cout << "The computer has selected a secret combination of 4 colored pegs and you have to guess that combination in 10 or fewer \ntries to win." << endl << endl;
			cout << "INSTRUCTIONS: " << endl;
			cout << "Guess a combination of colors, the colors are R (Red), (B) Blue, (Y) Yellow, (P) Purple, (W) White, and (O) Orange. \nColors can be repeated. COLORS ARE CASE SENSITIVE SO PLEASE USE CAPS" << endl;
			cout << "Then press enter to confirm your guess" << endl;
			cout << "Each time you submit a guess the computer will reply with B or W or X to let you know how close that guess is." << endl;
			cout << "For each guess a B indicates that one of your pegs is the right color in the right position. A W indicates that one of \nyour pegs is the right color in the wrong position." << endl;
			cout << "A X means that your guess is the wrong color and is not in the sequence." << endl;
			cout << "Use the score to guide your next guess. If your guess scores 4 black score pegs within 10 tries, you win." << endl;
			cout << "Good luck!" << endl;
			cout << endl << endl;

		}






};
#endif

