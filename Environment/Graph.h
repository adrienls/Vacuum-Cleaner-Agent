#pragma once
#include<iostream>
#include<list>

class Graph {
private:
	//Nombre de sommets
	int V;

	//Pointeur vers les noeud adjacents
	list<int>* adj;
public:
	//Constructeur
	Graph(int v);

	//Ajout d'une liaison
	void addEdge(int v, int w);

	//Le parcours BFS à partir du noeud s
	void BFS(int s);
};