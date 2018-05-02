/*
Author: Cody Potter
Date:	2018-05-01
File:	main.cpp
Desc:	This file holds the entry point for the program. 
*/
#include "PriorityQueue.h"
#include "Process.h"

using namespace std;

/*
Function:	Main
Desc:		Entry point, outputs author name and creates a priority queue
Parameters:	void
Return:		Int 0 when complete
*/
int main(void) {
	cout << "Author: Cody Potter" << endl << endl;
	PriorityQueue priorityQueue("sim.data");

	return 0;
}