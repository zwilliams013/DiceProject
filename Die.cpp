#include <iostream>
using namespace std;

#include "Die.h"

int Die::RollDie() {                                          //rolls a die, numbers from 1-6
	roll = (rand() % 6) + 1;

	return roll;
}
