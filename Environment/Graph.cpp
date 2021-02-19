#include "Graph.h"

//Constructeur
Graph::Graph(Grid grid) {
	//On associe le nombre de sommets
	V = 25;

	//Nouvelle liste pour stocker les sommet adjacents
	adj = new list<int>[V];

	int i = 0;
	for (int x = 0; x < 5; x++) 
		for (int y = 0; y < 5; y++){
			Node node;
			node.x = x;
			node.y = y;
			node.value = grid.getCell(x, y);
			nodes[i] = node;

			if (x != 0) addEdge(i, i - 5);
			if (x != 4) addEdge(i, i + 5);
			if (y != 0) addEdge(i, i - 1);
			if (y != 4) addEdge(i, i + 1);

			i++;
		}
}

//Fonction d'ajout d'arrete
void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

//Parcours BFS à partir du sommet donné
pair<int, int> Graph::BFS(int x, int y)
{
	int s = 5 * x + y;

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
		
		Node node = nodes[s];
		if (node.value != 0) {
			return make_pair(node.x, node.y);
		}

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
	return make_pair(-1, -1);
}