#include "Graph.h"

//Constructeur
Graph::Graph(const Grid& grid) {
	//On associe le nombre de sommets
	V = 25;

	//Nouvelle liste pour stocker les sommet adjacents
	adj = new list<int>[V];

	unsigned short i = 0;
    Node node{0, 0, 0};
	for (unsigned short x = 0; x < 5; x++) {
        for (unsigned short y = 0; y < 5; y++){
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
}

//Fonction d'ajout d'arrete
void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

//Parcours BFS � partir du sommet donn�
pair<int, int> Graph::BFS(int x, int y)
{
	int s = 5 * x + y;

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
		
		Node node = nodes[s];
		if (node.value != 0) {
			return make_pair(node.x, node.y);
		}

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
	return make_pair(-1, -1);
}