#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> a(n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	sort(a.begin(), a.end());

	int m;
	cin >> m;
	for (int cp = 0; cp < m; cp++) {
		int q;
		cin >> q;
		cout << sum - a[n-q] << endl;
	}

	return 0;
}

