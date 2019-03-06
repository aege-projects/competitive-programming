#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<string> graph;
vector<vector<int>> component;
void mark(int i, int j, int k) {
	if (graph[i][j] == '1' || component[i][j] == k) {
		return;
	}
	component[i][j] = k;
	mark(i+1, j, k);
	mark(i-1, j, k);
	mark(i, j+1, k);
	mark(i, j-1, k);
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	int ri, ci, rf, cf;
	cin >> ri >> ci >> rf >> cf;

	graph = vector<string> (n+2, "1");
	component = vector<vector<int>> (n+2, vector<int> (n+2, 0));
	graph[0] = graph[n+1] = string(n+2, '1');
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		graph[i] += (s + "1");
	}

	int components = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] == '0' && component[i][j] == 0) {
				mark(i, j, ++components);
			}
		}
	}
	
	if (components == 1) {
		cout << "0\n";
		return 0;
	}

	int comi = component[ri][ci], comf = component[rf][cf];
	vector<pii> pcomi, pcomf;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (component[i][j] == comi) {
				pcomi.push_back(pii(i, j));
			}

			if (component[i][j] == comf) {
				pcomf.push_back(pii(i, j));
			}
		}
	}

	int ans = INT_MAX;
	for (pii u : pcomi) {
		for (pii v : pcomf) {
			ans = min(ans, (v.first-u.first)*(v.first-u.first)+(v.second-u.second)*(v.second-u.second));
		}
	}
	cout << ans << endl;
	return 0;
}
