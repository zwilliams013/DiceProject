//********************************************************************************************************************************************
//Zackary Williams
//Project 1
//Dice Histogram
//********************************************************************************************************************************************
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ios>
#include <iomanip>
using namespace std;

#include "Die.h"

int main() {

	int seed = 0;
	int i = 0;
	int j = 0;
	int roll = 0;
	int tally = 0;
	int dieRolls = 0;
	int numDie = 0;
	vector<int> dieOutcome(1);

	Die die1;													//die object 

	cout << "Please enter a seed: ";							//ask user for seed
	cin >> seed;
	srand(seed);

	numDie = 1;													//rolling 1 dice

	cout << "How many rolls? ";						//ask user for number of rolls
	cin >> dieRolls;
	cout << endl;

	dieOutcome.resize(6 * numDie);								//resize vector to fit die vals

	for (i = 0; i < 6 * numDie; ++i) {                         //making all vector values 0 to start with
		dieOutcome.at(i) = 0;
	}

	for (i = 0; i < dieRolls; ++i) {
		int tally = 0;										   //resetting tally to 0 after every iteration

		for (j = 0; j < numDie; ++j) {						   //rolls numDie times and adds them together
			tally += die1.RollDie();
		}

		dieOutcome.at(tally - 1)++;                              //subtract 1 from tally, tally goes from 1-6, array is from 0-5
	}

	for (i = 0; i < 6 * numDie; ++i) {													//output values of array
		cout << setw(2) << left << i + 1 << " ---- " << dieOutcome.at(i) << endl;
	}
	cout << endl;
	
	//Find max occurance of tallies
	int maxOccurance = 0;
	int dieOutcomeSize = dieOutcome.size();
	for (i = 1; i < dieOutcomeSize; ++i) {
		if (dieOutcome.at(i) > dieOutcome.at(maxOccurance)) {
			maxOccurance = i;
		}
	}

	int scale =  dieOutcome.at(maxOccurance) / 60 + 1;							//find scale by dividing highest num by 60, adding 1 to round up

	//Print out histogram
	for (i = 0; i < dieOutcomeSize; ++i) {
		cout << setw(3) << i + 1 << "";
		for (int j = 0; j * scale < dieOutcome.at(i); ++j) {
			cout << "x";
		}
		cout << endl;
	}

	

	//****************************************************************************************************************
	//Second roll
	//****************************************************************************************************************
	cout << endl;
	cout << endl;
	cout << "Rolling twice: " << endl;
	cout << endl;

	numDie = 2;													//change number of die to 2 
    	dieOutcome.resize(6 * numDie);								//resize vector
		
	for (i = 0; i < 6 * numDie; ++i) {                          //making all vector values 0 to start with
		dieOutcome.at(i) = 0;
	}
	
	for (i = 0; i < dieRolls; ++i) {
		tally = 0;

		for (j = 0; j < numDie; ++j) {
			tally += die1.RollDie();
		}

		dieOutcome.at(tally - 1)++;                             //subtract 1 from tally, tally goes from 1- 12, array is from 0-11
	}

	for (i = 1; i < 6 * numDie; ++i) {
		cout << setw(2) << left << i+1 << " ---- " << dieOutcome.at(i) << endl;
	}
	cout << endl;

	//Find the max occurance again
	maxOccurance = 0;
	dieOutcomeSize = dieOutcome.size();
	for (int i = 1; i < dieOutcomeSize; ++i) {
		if (dieOutcome.at(i) > dieOutcome.at(maxOccurance)) {
			maxOccurance = i;
		}
	}

	scale = dieOutcome.at(maxOccurance) / 60 + 1;										//update scale
	
	for (int i = 1; i < dieOutcomeSize; ++i) {
		cout << setw(3) << i + 1 << " ";
		for (int j = 0; j * scale < dieOutcome.at(i); ++j) {
			cout << "x";
		}
		cout << endl;
	}

	char c;
	cout << "Press any key to exit: ";
	cin >> c;

	return 0;
}
