#include "player.h"
#include <iostream>

Player::Player(const string& name, const string& word)
	: name(name), word(word), attempts(0), guessedLetters(), wrongLetters() {}

void Player::guessLetter(char letter) {
	if (word.find(letter) != string::npos) {
		guessedLetters.push_back(letter);
	}
	else {
		wrongLetters.push_back(letter);
		attempts++;
	}
}

bool Player::hasWon() const {
	for (char c : word) {
		if (find(guessedLetters.begin(), guessedLetters.end(), c) == guessedLetters.end()) {
			return false;
		}
	}
	return true;
}

bool Player::hasLost() const {
	return attempts >= 6;
}

void Player::printStatus() const {
	cout << "  " << getWordToGuess() << endl;
	cout << endl;
}

string Player::getWord() const {
	return word;
}

string Player::getWordToGuess() const {
	string result;
	for (char c : word) {
		if (find(guessedLetters.begin(), guessedLetters.end(), c) != guessedLetters.end()) {
			result += c;
		}
		else {
			result += "_";
		}
		result += " ";
	}
	return result;
}

string Player::getName() const {
	return name;
}

string Player::getGuessedLetters() const {
	string result;
	for (char c : guessedLetters) {
		result += c;
		result += " ";
	}
	return result;
}

string Player::getWrongLetters() const {
	string result;
	for (char c : wrongLetters) {
		result += c;
		result += " ";
	}
	return result;
}

int Player::getAttempts() const {
	return attempts;
}