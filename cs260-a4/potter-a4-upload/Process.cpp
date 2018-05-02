/*
Author: Cody Potter
Date:	2018-05-01
File:	Process.cpp
Desc:	This file holds the logic for the process class.
*/
#include "Process.h"

using namespace std;

/*
Function:	Process Constructor
Desc:		Outputs a tab-delineated header
Parameters:	void
Return:		void
*/
Process::Process(int processID, int initialPriority, int remainingRunTime) {
	this->processID = processID;
	this->initialPriority = initialPriority;
	this->initialNeededRuntime = remainingRunTime;
	this->totalRunTime = 0;
	this->remainingRunTime = remainingRunTime;
	this->currentPriority = initialPriority;
}

/*
Function:	Get Initial Priority
Desc:		Getter for member initial priority
Parameters:	void
Return:		Int initial Priority
*/
int Process::getInitialPriority() {
	return this->initialPriority;
}

/*
Function:	Get Remaining Run Time
Desc:		Getter for member remaining run time
Parameters:	void
Return:		Int remaining run time
*/
int Process::getRemainingRunTime(){
	return this->remainingRunTime;
}

/*
Function:	Get Initial Needed Run Time
Desc:		Getter for member initial needed run time
Parameters:	void
Return:		Int initial needed run time
*/
int Process::getInitialNeededRuntime() {
	return this->initialNeededRuntime;
}

/*
Function:	Set Remaining Run Time
Desc:		Setter for member remaining run time
Parameters:	Int run time to set
Return:		Int remaining run time (not used in my program)
*/
int Process::setRemainingRunTime(int runTime) {
	this->remainingRunTime = runTime;
	return this->remainingRunTime;
}

/*
Function:	Set Current Priority
Desc:		Setter for member current priority
Parameters:	Int priority to set
Return:		Int current priority
*/
int Process::setCurrentPriority(int priority) {
	this->currentPriority = priority;
	return this->currentPriority;
}

/*
Function:	Set Total Run Time
Desc:		Setter for total run time using some simple math
Parameters:	Int current time
Return:		Int total run time
*/
int Process::setTotalRunTime(int currentTime) {
	this->totalRunTime = this->totalRunTime + currentTime - this->startTime;
	return this->totalRunTime;
}

/*
Function:	Set start time
Desc:		Setter for start time
Parameters:	Int current time
Return:		Int start time
*/
int Process::setStartTime(int currentTime) {
	this->startTime = currentTime;
	return this->startTime;
}

/*
Function:	Output Stats
Desc:		Outputs some formatted data
Parameters:	Int current time
Return:		void
*/
void Process::outputStats(int currentTime) {
	cout << this->processID << "	";
	cout << this->initialPriority << "			";
	cout << this->totalRunTime << "ms		";
	cout << this->startTime << "ms		";
	cout << currentTime << "ms		";
	cout << currentTime - this->startTime  << "ms		";
	cout << this->currentPriority << "		" << endl;
}
