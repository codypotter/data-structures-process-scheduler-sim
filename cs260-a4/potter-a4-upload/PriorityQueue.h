/*
Author: Cody Potter
Date:	2018-05-01
File:	PriorityQueue.h
Desc:	This is a header for the priority queue class.
*/
#pragma once
#include "Process.h"
#include<queue>
#include<fstream>
#include<sstream>
#include<iostream>
#include<string>

using namespace std;

class PriorityQueue {
private:
	queue<Process> processQueues[5];
	string fileName;
	int currentTime;
public:
	PriorityQueue(string fileName);
	bool getDataFromFile();
	void addNewProcess(Process newProcess);
	bool runSimulation();
	void printHeader();
};

