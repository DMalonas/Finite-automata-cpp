//============================================================================
// Name        : .cpp
// Author      : Malonas
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;
#include "../HeaderFiles/Utilities.hpp" // https://stackoverflow.com/questions/13298550/eclipse-c-including-header-file-from-my-source-folder


int main(){
	Utilities ut;
//
//	int n = 9;
//	vector<int> ar3 = {10, 20, 20, 10, 10, 30, 50, 10, 20};
//	cout << "pairs : " << ut.sockets(n, ar3) << endl;

	/*
	 * Get states | actions | starting state | final state(s) | rules
	 */
	vector<vector<string>> rules = ut.generateRulesFromFile();
	int numOfStates = ut.getNumOfStates();
	vector<string> actions = ut.getActions();
	string currentState = ut.getCurrentState();
	vector<string> finalStates = ut.getFinalStates();

	bool terminationFlag = false;

	while(!terminationFlag) {
		cout << "Current state: " << currentState  << "\t|Possible Actions: ";
		ut.updateState(rules, currentState, ut.getInputForNextAction(ut.getPossibleActions(currentState, rules)));
		currentState = ut.getCurrentState();
		if (ut.isTerminationState(currentState)) {
			cout << "State " << currentState << " is a final state so the program will now exit" << endl;
			break;
		}

	}

//	}




}



