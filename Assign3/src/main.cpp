#include"Game.h"

int main() {
	
	int continue_decision;
	Game g;
	do {
		g.print_menuscreen();
		continue_decision = g.play_game();
	} while (continue_decision != 0);
	return 0;
}