#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	vector<ll> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}

	ll ans = 1 + min(a[0], b[0]);
	for (int i = 1; i < n; i++) {
		if (a[i-1] == b[i-1]) {
			ans += min(a[i], b[i])-a[i-1];
		}

		if (a[i-1] < b[i-1] && a[i] >= b[i-1]) {
			ans++;

			if (a[i] >= b[i]) {
				ans += b[i]-b[i-1];
			}
		}

		if (a[i-1] > b[i-1] && b[i] >= a[i-1]) {
			ans++;

			if (b[i] >= a[i]) {
				ans += a[i]-a[i-1];
			}
		}
	}

	cout << ans << endl;
	return 0;
}
