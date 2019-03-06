#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {
	int k1[10][10], k2[10][10];
	for (int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			k1[i][j] = 0;
			k2[i][j] = 1;
		}
	}

	for (int i = 0; i < 10; i ++) {
		for (int j = (i%2 == 0? 0 : 1); j < 10; j += 2) {
			k1[i][j] = 1;
			k2[i][j] = 0;
		}
	}
	
	for (int i = 1; i < 10; i++) {
		k1[0][i] += k1[0][i-1];
		k1[i][0] += k1[i-1][0];
		k2[0][i] += k2[0][i-1];
		k2[i][0] += k2[i-1][0];
	}

	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			k1[i][j] += k1[i-1][j] + k1[i][j-1] - k1[i-1][j-1];
			k2[i][j] += k2[i-1][j] + k2[i][j-1] - k2[i-1][j-2];
		}
	}

	int K[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			K[i][j] = 0;
		}
	}

	for (int i = 0; i < 10; i += 2) {
		for (int j = 0; j < 10; j += 2) {
			K[i][j] = 1;
		}
	}

	for (int i = 1; i < 10; i++) {
		K[0][i] += K[0][i-1];
		K[i][0] += K[i-1][0];
	}

	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			K[i][j] += K[i-1][j] + K[i][j-1] - K[i-1][j-1];
		}
	}

	int t;
	cin >> t;
	while (t--) {
		char piece;
		cin >> piece;
		
		int m, n;
		cin >> m >> n;
		if (piece == 'r') {
			cout << min(m, n) << "\n";

		} else if (piece == 'k') {
			m--; n--;
			cout << max(k1[m][n], k2[m][n]) << "\n";
		
		} else if (piece == 'K') {
			m--; n--;
			cout << K[m][n] << "\n";
		
		} else {
			cout << min(m, n) << "\n";
		}
	}

	return 0;
}
