#pragma once
#ifndef LoadSol_H
#define LoadSol_H

#include <string>
#include <iostream>
#include <ctime>

using namespace std;

class LoadSol {

public:
	void create(char* outColors) {

		srand(randomttt); // Use randomtt to set srand() to our own value so our array 
						  // makes the same solution array as the game the user initially started

		int randomint = (rand() % 6) + 1;

		for (int i = 0; i < 4; i++) {
			randomint = (rand() % 6) + 1;

			switch (randomint) {
			case 1:
				outColors[i] = 'R';
				break;
			case 2:
				outColors[i] = 'B';
				break;
			case 3:
				outColors[i] = 'Y';
				break;
			case 4:
				outColors[i] = 'P';
				break;
			case 5:
				outColors[i] = 'W';
				break;
			case 6:
				outColors[i] = 'O';
				break;
			}
		}

	}

	// function to get randomtt to use later and output to file
	int Getrandomtt() { 
		return randomttt;
	}

	// function to set randomtt to our seed value from load file 
	void Setrandomtt(int x) {
		randomttt = x;
	}

private:

	long int randomttt;
};

#endif
