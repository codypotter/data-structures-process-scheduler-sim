/*
Author: Cody Potter
Date:	2018-05-01
File:	PriorityQueue.cpp
Desc:	This file holds the logic for the priority queue class.
*/
#include "PriorityQueue.h"
#include "Process.h"

using namespace std;

const int TIME_SLICE = 20;

/*
Function:	Priority Queue Constructor
Desc:		Constructor for Priority Queue, stores critical info
			and begins simulation
Parameters:	File name to queue
Return:		void
*/
PriorityQueue::PriorityQueue(string fileName) {
	this->currentTime = 0;
	this->fileName = fileName;
	this->runSimulation();
}

/*
Function:	Get Data From File
Desc:		Gets data from file and builds queue
Parameters:	void
Return:		If successful
*/
bool PriorityQueue::getDataFromFile() {
	ifstream fileStream(this->fileName);
	string line;

	cout << "File Name: " << fileName << endl;
	if (fileStream.is_open()) {
		int i = 0;
		while (getline(fileStream, line)) {

			// construct processes from each line
			stringstream stringStream(line);

			int initialPriority;
			stringStream >> initialPriority;
			int remainingRunTime;
			stringStream >> remainingRunTime;

			Process newProcess(i, initialPriority, remainingRunTime);
			this->addNewProcess(newProcess);
			i++;
		}
		fileStream.close();
		return true;
	} else {
		cerr << "Unable to open file";
		return false;
	}
}

/*
Function:	Add New Process
Desc:		Push new process onto appropriate queue
Parameters:	Process to push
Return:		void
*/
void PriorityQueue::addNewProcess(Process newProcess) {
	processQueues[newProcess.getInitialPriority()].push(newProcess);
}

/*
Function:	Run Simulation
Desc:		Push new process onto appropriate queue
Parameters:	void
Return:		If successful
*/
bool PriorityQueue::runSimulation() {
	if (!this->getDataFromFile()) { return false; }
	this->printHeader();

	// iterate over each process queue. 
	for (int i = 0; i < 5; i++) {
		// go until process queue is empty. 
		while (!processQueues[i].empty()) {
			int remainingTime = processQueues[i].front().getRemainingRunTime();
			if (remainingTime == processQueues[i].front().getInitialNeededRuntime()) {
				// its the first time we're processing, lets mark the start time
				processQueues[i].front().setStartTime(currentTime);
			}
			if (remainingTime <= TIME_SLICE) {
				if (remainingTime < TIME_SLICE) {
					currentTime += remainingTime;
				} else {
					currentTime += TIME_SLICE;
				}
				// only process it for remaining run time 
				processQueues[i].front().setRemainingRunTime(0);
				processQueues[i].front().setTotalRunTime(currentTime);
				// print it
				processQueues[i].front().outputStats(currentTime);
				// pop it
				processQueues[i].pop();
			} else {
				currentTime += 20;
				// 20ms won't be enough, just subtract 20 from remaining time
				processQueues[i].front().setRemainingRunTime(remainingTime - TIME_SLICE);
				processQueues[i].front().setTotalRunTime(currentTime);
				// and push onto next queue, unless we're already in last queue
				int nextQueue = i;
				if (i < 4) { 
					nextQueue= i+1;
					processQueues[i].front().setCurrentPriority(nextQueue);
				} 
				processQueues[nextQueue].push(processQueues[i].front());
				processQueues[i].pop();
			}
		}
	}
	return true;
}

/*
Function:	Print Header
Desc:		Outputs a tab-delineated header
Parameters:	void
Return:		void
*/
void PriorityQueue::printHeader() {
	cout << "PID	Initial Priority	Time Needed	Start Time	End Time	Elapsed Time	Final Priority" << endl;
}

