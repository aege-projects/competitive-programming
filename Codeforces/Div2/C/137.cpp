#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}

	sort(a.begin(), a.end());

	int count = 0;
	ll last = a[0].second;
	for (int i = 1; i < n; i++) {
		if (last > a[i].second) {
			count++;
		} else {
			last = a[i].second;
		}
	}
	cout << count << endl;

	return 0;
}
