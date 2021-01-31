#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

class Graph {
public:
	int movement[200] = {0};
	unordered_map <int, list<int>> m;

	void addEdge(int u, int v) {
		m[u].push_back(v);
	}

	int SnakeLadder(int src, int destination) {
		int distance[101];
		int i;
		for(i=0; i<= 100; i++)
			distance[i] = INT_MAX;
		distance[src] = 0;
		vector<int> parent;

		queue<int> q;
		q.push(src);
		parent.push_back(src);

		while(!q.empty())	{
			int current = q.front();
			q.pop();

			for(auto n = m[current].begin(); n != m[current].end(); n++) {
				if(distance[*n] == INT_MAX) {
					q.push(*n);
					distance[*n] = distance[current] + 1;
				}
			}
		}
		return distance[destination] == INT_MAX ? -1 : distance[destination];
	}

};



int main() {
	int t, i;
	cin>>t;
	for(int i=0;i<t;i++) {
		Graph* g = new Graph();
		int N;
		cin>>N;
		int start, end;
		for(i=0; i<N; i++) {
			cin>>start>>end;
			g->movement[start] = end;
		}

		int M;
		cin>>M;
		for(i=0; i<M; i++) {
			cin>>start>>end;
			g->movement[start] = end;
		}

		int u, dice, v;
		for(u=1; u<=100; u++)	{
			for(dice = 1; dice <= 6; dice++) {
			    if(g->movement[u+dice]==0)
				    v = u + dice;
				else
				    v=g->movement[u+dice];
				g->addEdge(u, v);
			}
		}

		cout<<g->SnakeLadder(1, 100)<<endl;
		delete g;
	}
}
