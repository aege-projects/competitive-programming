#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());
	vector<int> u, v;
	for (int i = 0; i < n; i += 2) {
		u.push_back(a[i]);
	}

	for (int i = 1; i < n; i += 2) {
		v.push_back(a[i]);
	}

	for (int i = 0; i < u.size(); i++) {
		cout << u[i] << " ";
	}

	for (int i = v.size()-1; i >= 0; i--) {
		cout << v[i];
		cout << (i ? " " : "\n");
	}
	return 0;
}
