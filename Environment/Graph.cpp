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

//Parcours BFS � partir du sommet donn�
void Graph::BFS(int s)
{
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}

	//Cr�ation de la queue des sommet visit�s
	list<int> queue;

	//On visite la base du parcours
	visited[s] = true;

	//On actualise la queue
	queue.push_back(s);

	while (!queue.empty()) {
		s = queue.front();
		queue.pop_front();

		//On r�cup�re les voisins de ce sommet
		for (auto i = adj[s].begin(); i != adj[s].end(); i++) {
			//On s'int�resse aux sommets non visit�s
			if (!visited[*i]) {
				//On les marques comme visit�s
				visited[*i] = true;
				//On les ajoutes � la liste des sommets visit�s
				queue.push_back(*i);
			}
		}
	}
}