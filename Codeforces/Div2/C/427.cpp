#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int>> graph, rgraph;
vector<ll> cost;
vector<vector<int>> component;
vector<bool> visited;
stack<int> s;
int n, m;

void fdfs(int u) {
	visited[u] = true;
	for (int v : graph[u]) {
		if (!visited[v]) {
			fdfs(v);
		}
	}
	s.push(u);
	return;
}

void sdfs(int u, int c) {
	visited[u] = true;
	component[c].push_back(u);
	for (int v : rgraph[u]) {
		if (!visited[v]) {
			sdfs(v, c);
		}
	}
}

void kosaraju() {
	visited = vector<bool> (n, false);
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			fdfs(i);
		}
	}

	visited = vector<bool> (n, false);
	component = vector<vector<int>> (0);
	int c = 0;
	while (!s.empty()) {
		int u = s.top();
		s.pop();

		if (!visited[u]) {
			component.push_back(vector<int> ());
			sdfs(u, c++);
		}
	}
}

int main() {
	cin >> n;
	cost = vector<ll> (n);
	graph = rgraph = vector<vector<int>> (n);
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		rgraph[v].push_back(u);
	}
	
	kosaraju();

ll sum = 0;
	ll ways = 1;
	const ll MOD = 1e9 + 7;
	for (int i = 0; i < component.size(); i++) {
		ll min_checkpost = LLONG_MAX;
		for (int u : component[i]) {
			min_checkpost = min(min_checkpost, cost[u]);
		}

		sum += min_checkpost;
		int count = 0;
		for (int u : component[i]) {
			if (cost[u] == min_checkpost) {
				count++;
			}
		}
		
		ways = ((ways%MOD)*(count%MOD))%MOD;
	}

	cout << sum << " " << ways << endl;

	return 0;
}
