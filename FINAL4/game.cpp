#include "game.h"
#define LOG 0

Game::Game() {}

using namespace std;

string Game::decryptAndReturnRandomWord(const string& filePath) {
	ifstream file(filePath);
	if (!file.is_open()) {
		cout << "Error opening file." << endl;
		return "";
	}

	vector<string> words;

	while (!file.eof()) {
		string word;
		getline(file, word);
		words.push_back(word);
	}

	file.close();

	srand(time(0));
	string word = words[rand() % words.size()];
	string result;

#if LOG
	cout << "No decrypted word: " << word << endl;
#endif
	// decryption
	for (char c : word) {
		if (isalpha(c)) {
			char base = islower(c) ? 'a' : 'A';
			c = (c - base - 5 + 26) % 26 + base;
		}
		result += c;
	}
#if LOG
	cout << "Decrypted word: " << result << endl;
#endif

	return result;
}

void Game::run() {
	string name;
	string word;

	cout << "Enter your name: ";
	cin >> name;
	system("cls");

	cout << "Select the word difficulty:" << endl;
	cout << "1. Easy" << endl;
	cout << "2. Medium" << endl;
	cout << "3. Hard" << endl;

	int choice;
	cin >> choice;

	switch (choice) {
	case 1:
		word = decryptAndReturnRandomWord("easy.txt");
		break;
	case 2:
		word = decryptAndReturnRandomWord("medium.txt");
		break;
	case 3:
		word = decryptAndReturnRandomWord("hard.txt");
		break;
	default:
		cout << "Invalid choice. Exiting..." << endl;
		system("pause");
		return;
	}
	system("cls");

	Player player(name, word);
	Ui ui(player);

	ui.printWelcome();

	auto start = high_resolution_clock::now();

	while (!player.hasWon() && !player.hasLost()) {
		ui.printHangman(player.getAttempts());
		player.printStatus();

		char letter;
		cout << "Enter a letter: ";
		cin >> letter;
		player.guessLetter(letter);
		system("cls");
	}

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	ui.printGoodbye(player, duration.count() / 1e6);
}