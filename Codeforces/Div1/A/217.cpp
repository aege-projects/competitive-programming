#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<pii> a;
unordered_map<int, unordered_map<int, int>> visited;

void dfs(pii coord, int k) {
	visited[coord.first][coord.second] = k;
	for (int i = 0; i < a.size(); i++) {
		if (!visited[a[i].first][a[i].second] && (a[i].first == coord.first || a[i].second == coord.second)) {
			dfs(a[i], k);
		}
	}
	return;
}

int main() {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	
	a = vector<pii> (n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	
	int c = 1;
	for (int i = 0; i < n; i++) {
		if (!visited[a[i].first][a[i].second]) {
			dfs(a[i], c);
			c++;
		}
	}
	c -= 2;
	cout << c << endl;

	return 0;
}
