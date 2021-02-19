#include "Graph.h"

//Constructeur
Graph::Graph(int v) {
	//On associe le nombre de sommets
	V = v;

	//Nouvelle liste pour stocker les sommet adjacents
	adj = new list<int>[V];
}

//Fonction d'ajout d'arrete
void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

//Parcours BFS à partir du sommet donné
void Graph::BFS(int s)
{
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}

	//Création de la queue des sommet visités
	list<int> queue;

	//On visite la base du parcours
	visited[s] = true;

	//On actualise la queue
	queue.push_back(s);

	while (!queue.empty()) {
		s = queue.front();
		queue.pop_front();

		//On récupère les voisins de ce sommet
		for (auto i = adj[s].begin(); i != adj[s].end(); i++) {
			//On s'intéresse aux sommets non visités
			if (!visited[*i]) {
				//On les marques comme visités
				visited[*i] = true;
				//On les ajoutes à la liste des sommets visités
				queue.push_back(*i);
			}
		}
	}
}