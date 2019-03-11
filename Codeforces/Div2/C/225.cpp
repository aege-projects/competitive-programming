#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	
	vector<string> b(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	vector<int> cb(m, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (b[i][j] == '#') {
				cb[j]++;
			}
		}
	}

	vector<int> dl(m, INT_MAX), dr(m, INT_MAX);
	dl[0] = 0;
	dr[m-1] = 0;
	int l = -1;
	for (int i = 1; i < m; i++) {
		if (cb[i]) {
			if (l != -1) {
				dl[i] = l;
			}
			l = i;
		}
	}

	int r = -1;
	for (int i = m-2; i >= 0; i++) {
		if (cb[i]) {
			if (l != -1) {
				dr[i] = r;
			}
			l = i;
		}
	}

	vector<int> len(m, 0);
	len[0] = (cb[0] > 0);
	for (int i = 1; i < m; i++) {
		if (cb[i]) {
			len[i] = 1 + len[i-1]; 
		}
	}

	for (int i = m-2; i >= 0; i--) {
		if (cb[i]) {
			len[i] = max(len[i+1], len[i]);
		}
	}

	return 0;
}
