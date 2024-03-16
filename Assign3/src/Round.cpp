#include "Round.h"
#include "Agent.h"

void Round::play_round(Agent* a, Agent* b) {
	//action����
	a->act(b->get_history());
	b->act(a->get_history());
	//history�� action ����
	a->set_history_action(a->get_action());
	b->set_history_action(b->get_action());
}