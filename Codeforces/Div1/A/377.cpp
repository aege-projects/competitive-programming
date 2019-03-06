#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<string> a;
vector<vector<bool>> visited;

int dim;
void dfs(int i, int j) {
	if (dim==0 || a[i][j] != '.' || visited[i][j]) {
		return;
	}

	visited[i][j] = true;
	dim--;
	dfs(i+1, j);
	dfs(i-1, j);
	dfs(i, j+1);
	dfs(i, j-1);
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	a = vector<string>(n+2, "#");
	a[0] = a[n+1] = string(m+2, '#');
	
	visited = vector<vector<bool>> (n+2, vector<bool> (m+2, false));

	string s;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		a[i] += (s+"#");
	}

	pii initial(0, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j]=='.') {
				dim++;
				if (initial.first==0 && initial.second==0) {
					initial = pii(i, j);
				}
			}
		}
	}
	
	dim -= k;
	dfs(initial.first, initial.second);
	

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j]=='.' && !visited[i][j]) {
				a[i][j] = 'X';
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << a[i][j];
		}
		cout << "\n";
	}
	return 0;
}
