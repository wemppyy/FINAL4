#pragma once
#include <iostream>
#include <string>
#include "player.h"

class Ui {
private:
	Player player;
public:
	Ui(const Player player);

	void printHangman(int attempts) const;
	void printWelcome() const;
	void printGoodbye(const Player& player, const int time) const;

};