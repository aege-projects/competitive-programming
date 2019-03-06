#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t, n;
	int pc, nc;
	
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		cin >> n;

		pc = nc = 0;
		for (int i = 0; i < n; i++) {
			ll x;
			cin >> x;
			if (x >= 0) {
				pc++;
			} else {
				nc++;
			}

		}

		cout << max(pc, nc) << " " << (min(pc, nc) > 0 ? min(pc, nc) : max(pc, nc)) << "\n"; 
	}

}
