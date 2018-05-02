/*
Author: Cody Potter
Date:	2018-05-01
File:	Process.h
Desc:	This is a header for the process class.
*/
#pragma once
#include<iostream>
class Process {
private:
	int processID;
	int initialPriority;
	int initialNeededRuntime;
	int totalRunTime;
	int remainingRunTime;
	int currentPriority;
	int startTime;
public:
	Process(int processID, int initialPriority, int remainingRunTime);
	int getInitialPriority();
	int getRemainingRunTime();
	int getInitialNeededRuntime();
	int setRemainingRunTime(int runTime);
	int setCurrentPriority(int priority);
	int setTotalRunTime(int currentTime);
	int setStartTime(int currentTime);
	void outputStats(int currentTime);
};

