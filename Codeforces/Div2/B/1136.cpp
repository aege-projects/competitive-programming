#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	if (k == 1 || k == n) {
		cout <<  3*n << "\n";
	} else {
		if (n-k < k) {
			cout << 4*(1+n-k) + 3*(k-1) << "\n";

		} else {
			cout <<  3*(1+n-k) + 4*(k-1) << "\n";

		}

	}
	
	return 0;
}
