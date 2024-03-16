#pragma once

class LinkedList;

class Agent {
private: 
	LinkedList* history; 
	int action;
	int reward;

public:
	Agent();
	~Agent();
	virtual void act(const LinkedList*) = 0;
	int get_action() const;
	int get_reward() const;
	LinkedList* get_history() const;
	void set_action(int act);
	void set_reward(int re);
	void set_history_action(int act);
	void reset_history();
	void print_action();
};


