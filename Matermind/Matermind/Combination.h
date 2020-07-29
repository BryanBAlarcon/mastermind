#pragma once
#ifndef Combination_H
#define Combination_H

#include <string>
#include <iostream>
#include <ctime>

using namespace std;

class Combination {

public:

	// the below class function creates a solution array 
	void create(char* outColors) {

		srand(randomtt); 

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

	int Getrandomtt() {
		return randomtt;
	}

	void Setrandomtt(int x) {
		randomtt = x; 
	}


private: 

	long int randomtt = time(0); // sets randomtt to time(0) so we can use it later
};
#endif
