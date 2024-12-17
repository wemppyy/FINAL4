#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <chrono>
#include "ui.h"
#include "player.h"

using namespace std;
using namespace chrono;

class Game {
public:
	Game();

	void run();
	string decryptAndReturnRandomWord(const string& filePath);
};