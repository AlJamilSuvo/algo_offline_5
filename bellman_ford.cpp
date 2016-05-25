#include <algorithm>
#include <iostream>
#include <vector>
#define INF 10000000

using namespace std;

int parent[100];
int dis[100];
struct Edge {
	int u, v, w;
};
struct Edge E[1000];
int N;
int edgeNo;

void initialize_single_sorce(int s) {
	for (int i = 1; i <=N; i++) {
		dis[i] = INF;
		parent[i] = -1;
	}
	dis[s] = 0;
}

void relax(int u, int v, int w) {
	if (dis[v] > dis[u] + w) {
		dis[v] = dis[u] + w;
		parent[v] = u;
	}
}

bool bellman_ford(int s) {
	initialize_single_sorce(s);
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < edgeNo; j++) {
			relax(E[j].u, E[j].v, E[j].w);
		}
	}

	for (int i = 0; i < edgeNo; i++) {
		if (dis[E[i].v]>dis[E[i].u] + E[i].w) return false;
	}
	return true;
}


int main() {

	cin >> N >> edgeNo;
	for (int i = 0; i < edgeNo; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		E[i].u = u;
		E[i].v = v;
		E[i].w = w;

	}
	int source;
	cin >> source;
	if (bellman_ford(source)) {
		for (int i = 1; i <= N; i++) {
			cout << i << " dis=" << dis[i] << " parent=" << parent[i] << endl;
		}
	}
	else {
		cout << "Negative Cycle Detected" << endl;
	}
}
