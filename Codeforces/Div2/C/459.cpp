#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k, d;
	cin >> n >> k >> d;
	
	ll kd = 1;
	for (int i = 0; i < d; i++) {
		if (kd >= n) {
			break;
		}
		kd *= k;
	}

	if (kd < n) {
		cout << "-1\n";
	} else {
		vector<vector<int>> a(n, vector<int> (d, 0));
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < d; j++) {
				a[i][j] = a[i-1][j];
			}
			
			for (int j = d-1; j >= 0; j--) {
				a[i][j] = (a[i][j]+1)%k;
				if (a[i][j]) {
					break;
				}
			}
		}

		for (int j = 0; j < d; j++) {
			for (int i = 0; i < n; i++) {
				cout << 1+a[i][j] << " ";
			}
			cout << endl;
		}

	}

	return 0;
}
