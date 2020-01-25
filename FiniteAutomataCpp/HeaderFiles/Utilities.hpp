#pragma once


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <memory>

#include <cmath>


using std::string;

class Utilities
{
private:
	int numOfLines;
	int numOfRules;
	string file;
	vector<string> rule;
	string startingState;
	int states;
	vector<string> actions;
	vector<string> finalStates;


public:
	void updateState(vector<vector<string>> rules, string currentState, string chosenAction);
	bool checkActionIsValid(string input, vector<string> nextPossibleActions);
	string getInputForNextAction(vector<string> nextPossibleActions);
	void printPossibleActions(vector<string> nextPossibleActions);
	vector<string> tokeniseString(string line);
	int getNumOfLines(string filename);
	vector<vector<string>> generateRulesFromFile();
	int getNumOfRules();
	string getCurrentState();
	int getNumOfStates();
	vector<string> getActions();
	vector<string> getFinalStates();
	vector<string> getPossibleActions(string currentState, vector<vector<string>> rules);
	bool isTerminationState(string currentState);
	//int sockets(int n, vector<int> arr);
};


