#pragma once
#include<iostream>
#include<list>
#include "Grid.h"

struct Node {
	int x;
	int y;
	int value;
};

using namespace std;
class Graph {
private:
	//Nombre de sommets
	int V;

	//Pointeur vers les noeud adjacents
	list<int>* adj;

	//liste des noeuds
	Node nodes[25];
public:
	//Constructeur
	Graph(Grid grid);

	//Ajout d'une liaison
	void addEdge(int v, int w);

	//Le parcours BFS à partir du noeud x y
	pair<int, int> BFS(int x, int y);
};