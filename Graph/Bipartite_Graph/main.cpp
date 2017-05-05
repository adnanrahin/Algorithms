#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

const int n = 100;
int node;
vector < int > G[n];
bool visited[n];
int level[n];
int match[n];
int parent[n];

bool bfs(int src){
	for(int i=0; i<=node; i++){
		level[i] = 0;
		parent[i] = 0;
		match[i] = -1;
		visited[i] = false;
	}
	queue < int > q;
	visited[src] = true;
	level[src] = 0;
	match[src] = 1;
	bool temp = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i=0; i<G[u].size(); i++){
			int v = G[u][i];
			if(visited[v] == false and match[v] == -1){
				visited[v] = true;
				match[v] = 1 - match[u];
				//match[v] = u;
				q.push(v);
			}
			else if(visited[v] == true and match[u] == match[u]) return false;
		}
	}
	return true;
}

int main(){
	freopen("input.txt","r",stdin);
	int edge,n1,n2;
	cin >> node >> edge;
	
	for(int i=1; i<=edge; i++){
		cin >> n1 >> n2;
		G[n2].push_back(n1);
		G[n1].push_back(n2);
	}
	
	if(bfs(1)) cout << "This is Bipartite Graph: " << endl;
	else cout << "This is not a Bipartite Gprah: " << endl;
	
	return 0;
}









