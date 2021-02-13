<<<<<<< HEAD
#pragma once
#include"Environnement.h"
#include"States.h"
#include<vector>

enum Mouve {
	GAUCHE = 0,
	HAUT = 1,
	DROITE = 2,
	BAS = 3
};

class Problem {
	
public:
	bool goalAchieved();
	std::vector<std::pair<Mouve,States>> Succession();
	Problem(std::vector<int> initial, std::vector<Mouve> mouvesAvaliable, int cost, Environnement env);
private:
	std::vector<int> initialState;
	std::vector<Mouve> mouvesAvaliable;
	int actionCost;
	Environnement* environnement;
};
=======
#ifndef VACUUM_CLEANER_AGENT_PROBLEM_H
#define VACUUM_CLEANER_AGENT_PROBLEM_H

#include"Environment.h"
#include<vector>

using std::vector;

class Problem {
private:
    vector<unsigned int> initialState;
    vector<unsigned int> movesAvailable;
    unsigned int actionCost;
    Environment environment;

public:
	bool goalAchieved(){
	    return false;
	}
	vector<int> path(){
        vector<int> p;
        p[0] = 1;
        return p;
	}

    Problem(const vector<int> &initialState, const vector<int> &movesAvailable, int actionCost,
            const Environment &environment) : initialState(initialState), movesAvailable(movesAvailable),
                                              actionCost(actionCost), environment(environment) {}
    virtual ~Problem() = default;
};

#endif //VACUUM_CLEANER_AGENT_PROBLEM_H
>>>>>>> 06e9bc93da3e1a9e1fa70a8ba97b7eb5887a2a5b
