#pragma once

class Population;

class Game {

private:
	int Command;

public:
	Game();
	~Game();
	void print_menuscreen();
	int play_game();
	void Decide_Populatoin(Population* p);
};