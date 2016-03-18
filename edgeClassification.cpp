#include <iostream>
#include <vector>

struct Edge {
	int u;
	int v;
	Edge(int uu, int vv) : u(uu), v(vv) { };
};

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;
int nNode, nEdge, time;
int graph[100][100];
int color[100];
int discover[100];
int finish[100];

std::vector<Edge> treeEdge;
std::vector<Edge> backEdge;
std::vector<Edge> forwardEdge;
std::vector<Edge> crossEdge;


void DFS_Visit(int u) {
	color[u] = GRAY;
	time++;
	discover[u] = time;

	for (int v = 0; v < nNode; v++)
		if (graph[u][v]) {
			if (color[v] == WHITE) {
				treeEdge.push_back(Edge(u, v));
				color[v] = GRAY;
				DFS_Visit(v);
			}
			else if (color[v] == GRAY) {
				backEdge.push_back(Edge(u, v));
			}

			else if (color[v] == BLACK) {
				if (discover[u] < discover[v])
					forwardEdge.push_back(Edge(u, v));
				else if (discover[u] > discover[v])
					crossEdge.push_back(Edge(u, v));
			}
		}
	color[u] = BLACK;
	time++;
	finish[u] = time;
}

void DFS() {
	time = 0;
	for (int u = 0; u < nNode; u++)
		if(color[u] == WHITE)
			DFS_Visit(u);
}

int main()
{
	int u, v;
	std::cout << "Enter the number of node: ";
	std::cin >> nNode;
	std::cout << "Enter the number of edge: ";
	std::cin >> nEdge;

	std::cout << "Enter edge connections: " << std::endl;

	for (int i = 0; i < nEdge; i++) {
		std::cin >> u >> v;
		u--, v--;
		graph[u][v] = 1;
	}

	DFS();

	std::cout << "Tree edges are: " << std::endl;
	for (std::vector<Edge>::iterator it = treeEdge.begin(); it != treeEdge.end(); it++)
		std::cout << it->u + 1 << "-" << it->v + 1 << std::endl;

	std::cout << "Back edges are: " << std::endl;
	for (std::vector<Edge>::iterator it = backEdge.begin(); it != backEdge.end(); it++)
		std::cout << it->u + 1 << "-" << it->v + 1 << std::endl;

	std::cout << "Forward edges are: " << std::endl;
	for (std::vector<Edge>::iterator it = forwardEdge.begin(); it != forwardEdge.end(); it++)
		std::cout << it->u + 1 << "-" << it->v + 1 << std::endl;

	std::cout << "Cross edges are: " << std::endl;
	for (std::vector<Edge>::iterator it = crossEdge.begin(); it != crossEdge.end(); it++)
		std::cout << it->u + 1 << "-" << it-> v + 1 << std::endl;

	return 0;
}

