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

	bool sorted = true;
	for (int i = 0; i < n-1; i++) {
		if (a[i] > a[i+1]) {
			sorted = false;
			break;
		}
	}

	if (sorted) {
		cout << "YES\n";
		return 0;
	}

	int count = 0;
	vector<ll> b = a;
	sort(b.begin(), b.end());
	for (int i = 0; i < n; i++) {
		count += (a[i] != b[i]);
	}
	
	cout << (count > 2 ? "NO\n" : "YES\n");

	return 0;
}
