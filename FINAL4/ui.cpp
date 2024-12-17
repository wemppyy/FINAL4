#include "ui.h"

Ui::Ui(const Player player) : player(player) {}

void Ui::printHangman(int attempts) const {
    switch (attempts) {
    case 0:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 1:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 2:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << "  |   |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 3:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << " /|   |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 4:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << " /|\\  |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 5:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << " /|\\  |" << endl;
        cout << " /    |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 6:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << " /|\\  |" << endl;
        cout << " / \\  |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    }
}

void Ui::printWelcome() const {
    cout << "Welcome to Hangman, " << player.getName() << "!" << endl;
    cout << "You have 6 attempts to guess the word." << endl;
    cout << "Guess one letter at a time." << endl;
    cout << "Good luck!" << endl;
	system("pause");
	system("cls");
}

void Ui::printGoodbye(const Player& player, const int time) const {
    if (player.hasWon()) {
        cout << "Congratulations, " << player.getName() << "! You won!" << endl;
    }
    else {
        cout << "Sorry, " << player.getName() << ". You lost." << endl;
    }
    cout << endl;

    // Виводимо результати
    cout << "Results:"
        << "\n  -Word: " << player.getWord()
		<< "\n  -Time: " << time << " seconds"
        << "\n  -Attempts: " << player.getAttempts()
        << "\n  -Guessed letters: " << player.getGuessedLetters()
        << "\n  -Wrong letters: " << player.getWrongLetters()
        << endl;

    system("pause");
}