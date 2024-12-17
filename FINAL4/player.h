#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
private:
	string name;
	string word;
	vector<char> guessedLetters;
	vector<char> wrongLetters;
	int attempts;
public:
	Player(const string& name, const string& word);

	void guessLetter(char letter);
	void printStatus() const;

	bool hasWon() const;
	bool hasLost() const;

	string getWord() const;
	string getName() const;
	string getGuessedLetters() const;
	string getWrongLetters() const;
	string getWordToGuess() const;

	int getAttempts() const;
};