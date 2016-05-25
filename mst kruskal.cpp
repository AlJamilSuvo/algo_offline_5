#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }

struct Edge {
	int u, v, w;
};



int N;
int edgeNo;
vector<Edge> MST;
struct Edge E[100];
int parent[100];

inline int find_set(int s) { return parent[s]; }
inline void make_set(int s, int p) { parent[s] = p; }
void make_union(int u,int v) {
	int x, y;
	x = min(u, v);
	y = max(u, v);
	int px, py;
	px = find_set(x);
	py = find_set(y);
	for (int i = 1; i <= N; i++) {
		if (find_set(i) == py) make_set(i, px);
	}

}

void sort_edge() {
	for (int i = 0; i < edgeNo-1; i++) {
		for (int j = i; j < edgeNo; j++) {
			if (E[i].w > E[j].w) {
				Edge temp = E[i];
				E[i] = E[j];
				E[j] = temp;
			}
		}
	}
}


void mst_kruskal() {
	MST.clear();
	for (int i = 1; i <= N; i++) make_set(i, i);
	sort_edge();
	for (int i = 0; i < edgeNo; i++) {
		if (find_set(E[i].u) != find_set(E[i].v)) {
			MST.push_back(E[i]);
			make_union(E[i].u, E[i].v);
		}
	}

	for (int i = 0; i < MST.size(); i++) {
		cout << MST[i].u << "-----(" << MST[i].w << ")-----" << MST[i].v << endl;
	}
}

int main(){
    cin>>N>>edgeNo;
    for(int i=0;i<edgeNo;i++){
        int u,v,w;
        cin>>u>>v>>w;
        E[i].u=u;
        E[i].v=v;
        E[i].w=w;
    }
    mst_kruskal();
}
