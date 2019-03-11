#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	vector<pii> a(n);
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		a[i] = pii(t, i+1);
	}

	sort(a.begin(), a.end());

	vector<pii> p, q;
	p = q = vector<pii> (n, pii(-1, -1));
	int u = 0, v = 0;
	for (int i = 0; i < n; i++) {
		if (i%2 == 0) {
			p[u++] = a[i];
		} else {
			q[v++] = a[i];
		}
	}

	cout << u << "\n";
	for (int i = 0; i < n && p[i].first != -1; i++) {
		cout <<  p[i].second << " ";
	}

	cout << "\n";
	cout << v << "\n";
	for (int i = 0; i < n && q[i].first != -1; i++) {
		cout << q[i].second << " ";
	}
	cout << "\n";
	return 0;
}
