#include <bits/stdc++.h>
using namespace std;

int main() {
	int k1[500][500], k2[500][500];
	for (int i = 0; i < 500; i++) {
		for (int j = 0; j < 500; j++) {
			k1[i][j] = 0;
			k2[i][j] = 1;
		}
	}

	for (int i = 0; i < 500; i++) {
		for (int j = (i%2 == 0 ? 0 : 1); j < 500; j += 2) {
			k1[i][j] = 1;
			k2[i][j] = 0;
		}
	}
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << k1[i][j] << " ";
		}	
		cout << "\n";
	}
	cout << "\n";

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << k2[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 1; i < 500; i++) {
		k1[i][0] = k1[i-1][0];
		k1[0][i] = k1[0][i-1];
		k2[i][0] = k2[i-1][0];
		k2[0][i] = k2[0][i-1];
	}

	for (int i = 1; i < 500; i++) {
		for (int j = 1; j < 500; j++) {
			k1[i][j] += k1[i-1][j]+k1[i][j-1]-k1[i-1][j-1];
			k2[i][j] += k2[i-1][j]+k2[i][j-1]-k2[i-1][j-1];
		}
	}

	int u, v;
	while (true) {
		cin >> u >> v;
		if (u == 0 && v == 0) {
			break;
		}

		cout << max(k1[u-1][v-1], k2[u-1][v-1]) << " knights may be placed on a " << u << " row " << v << " column board.\n";

	}

	return 0;
}
