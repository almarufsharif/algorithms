#include <iostream>
#include <stack>

/* Sample input:
8
13
a b
b c
b e
b f
c d
c g
d c
d h
e a
e f
f g
g f
g h


Sample output:
abe
cd
fg h
*/

int N, mConnection;
int graph[10][10];
int tGraph[10][10];
int visit[10];
std::stack<int> S;

void dfs_visit(int u) {
	for (int v = 0; v < N; v++)
		if (!visit[v] && tGraph[u][v]) {
			visit[v] = 1;
			dfs_visit(v);
		}
	S.push(u);
}

void dfs_visit_t(int u) {
	std::cout << (char)(97 + u);
	for (int v = 0; v < N; v++)
		if (!visit[v] && graph[u][v]) {
			visit[v] = 1;
			dfs_visit_t(v);
		}
	S.pop();
}
void ssc() {
	for (int i = 0; i < N; i++)
		visit[i] = 0;
	for (int i = 0; i < N; i++)
		if (!visit[i]) {
			visit[i] = 1;
			dfs_visit(i);
		}

	for (int i = 0; i < N; i++)
		visit[i] = 0;

	while (!S.empty()) {
		int u = S.top();
		visit[u] = 1;
		dfs_visit_t(u);
		std::cout << std::endl;
	}
}

int main() {
	char u, v;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			if (i == j) graph[i][j] = 1;
			else graph[i][j] = 0;
	}

	std::cin >> mConnection;

	for (int i = 0; i < mConnection; i++) {
		std::cin >> u >> v;
		graph[u - 'a'][v - 'a'] = 1;
		tGraph[v - 'a'][u - 'a'] = 1;
	}

	std::cout << std::endl << std::endl;
	ssc();

	return 0;
}


