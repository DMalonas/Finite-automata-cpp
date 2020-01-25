#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

#include "../HeaderFiles/Utilities.hpp"


//int Utilities::sockets(int n, vector<int> ar) {
//	vector<bool> visited = {false};
//	//vector<int> pairs;
//	int pairs;
//
//	for(int i = 0; i < n; i++) {
//		if(visited[i] == true)
//			continue;
//		visited[i] = true;
//		int count = 1;
//		for(int j = i + 1; j < n; j++) {
//			if(ar[i] == ar[j]) {
//				count++;
//				visited[j] = true;
//				break;
//			}
//		}
//		if(count > 1)
//			pairs++;
//	}
//	return pairs;
//}

vector<string> Utilities:: tokeniseString(string line) {

    // Vector of string to save tokens
    vector <string> actions;

    // stringstream class check1
    stringstream check1(line);

    string intermediate;

    // Tokenizing w.r.t. space ' '
    while(getline(check1, intermediate, ' '))
    {
    	actions.push_back(intermediate);
    }

    // Printing the actions vector
//		    for(int i = 0; i < actions.size(); i++) {
//		        cout << actions[i] << " ";
//		    }
    return actions;
}


int Utilities::getNumOfLines(string filename) {
	ifstream f (filename);
	string line;
	if (!f.is_open())
		perror("error while opening file");
	int cnt = 0;
	while(getline(f, line)) {
		cnt++;
	}
	return cnt;

}

vector<vector<string>> Utilities::generateRulesFromFile() {
	//Read file contents
	string line;
	file = "dfa.txt";
	ifstream f (file);
	numOfLines = getNumOfLines(file);
	numOfRules = numOfLines - 4;
	int cnt = 0;
	rule;
	vector<vector<string>> rules(numOfRules);
	if (!f.is_open())
		perror("error while opening file");

	while(getline(f, line)) {
		//cout << line << "\n";
		if (cnt == 0) {
			states = line[0] - 48;
		} else if (cnt == 1) {
			actions = tokeniseString(line);

		} else if (cnt == 2) {
			startingState = line[0];
			//cout << startingState << " " << endl;
		} else if (cnt == 3) {
			finalStates = tokeniseString(line);
		} else {
//			cout << "num of actions : "  << numOfRules << endl;
			rules[cnt - 4] = tokeniseString(line);
		}


		cnt++;
	}
//	for (int i = 0; i < numOfRules; i++) {
//		for (int j = 0; j < 3; j++) {
//			cout << rules[i][j] << " ";
//		}
//		cout << endl;
//	}
	if (f.bad())
		perror("error while reading file");
	return rules;
}


int Utilities::getNumOfRules() {
	return Utilities::numOfRules;
}

string Utilities::getCurrentState() {
	return Utilities::startingState;
}

int Utilities::getNumOfStates() {
	return Utilities::states;
}


vector<string> Utilities::getActions() {
	return Utilities::actions;
}

vector<string> Utilities::getFinalStates() {
	return Utilities::finalStates;
}


vector<string> Utilities::getPossibleActions(string currentState, vector<vector<string>> rules) {
	vector<string> nextActions;
//	cout << "current state " << currentState << endl;
	for (int i = 0; i < numOfRules; i++) {
		//cout << i << " here  " <<  rules[i][0] << endl;
		if (rules[i][0].compare(currentState) == 0) {
			nextActions.push_back(rules[i][1]);
		}
	}
//	for (int i = 0; i < nextActions.size(); i++) {
//		cout << nextActions[i] << endl;
//	}
	return nextActions;

}








void Utilities::printPossibleActions(vector<string> nextPossibleActions) {
	for (int i = 0; i < nextPossibleActions.size(); i++) {
		cout << nextPossibleActions.at(i) + " ";
	}
}


string Utilities::getInputForNextAction(vector<string> nextPossibleActions) {
	printPossibleActions(nextPossibleActions);
	string input;
	while (true) {
		getline(cin, input);
		//cout << "You entered: " << input << endl << endl;
		if (checkActionIsValid(input, nextPossibleActions)) {
			return input;
		}
	}
}

bool Utilities::checkActionIsValid(string input, vector<string> nextPossibleActions) {
	for (int i = 0; i < nextPossibleActions.size(); i++) {
		if (input.compare(nextPossibleActions.at(i)) == 0) {
			//cout << input << " " << nextPossibleActions.at(i) << endl;
			return true;
		}
	}
	return false;
}


void Utilities::updateState(vector<vector<string>> rules, string currentState, string chosenAction) {
	for (int i = 0; i < numOfRules; i++) {
		if (rules[i][0].compare(currentState) == 0) {
			if (rules[i][1].compare(chosenAction) == 0) {
				startingState = rules[i][2];
				break;
			}
		}
	}
//	cout << "now state is " << startingState << endl;
}


bool Utilities::isTerminationState(string currentState) {
	for (int i = 0; i < finalStates.size(); i++) {
		if (currentState.compare(finalStates[i]) == 0) {
			return true;
		}
	}
}
