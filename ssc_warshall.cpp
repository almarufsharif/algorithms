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
int visit[10];

void floydWarshall() {
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (graph[i][k] && graph[k][j]) graph[i][j] = 1;

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
	}

	std::cout << std::endl << std::endl;
	floydWarshall();
	int f;

	for (int i = 0; i < N; i++) {
		f = 0;
		for (int j = 0; j < N; j++)
			if (!visit[j] && graph[i][j] && graph[j][i]) {
				std::cout << (char)(j + 'a');
				f = 1;
				visit[j] = 1;
			}
		if(f)
			std::cout << std::endl;
	}
	std::cout << std::endl;


	return 0;
}


