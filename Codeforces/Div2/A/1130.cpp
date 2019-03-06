#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<double> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int d = -1000; d <= 1000; d++) {
		if (d == 0) {
			continue;
		}
		int count = 0;
		for (int i = 0; i < n; i++) {
			double x = a[i]/d;
			if (x > 0) {
				count++;
			}
		}
		if (count >= ceil(n/2.0)) {
			cout << d << endl;
			return 0;
		}
	}
	cout << 0 << endl;
	return 0;
}
