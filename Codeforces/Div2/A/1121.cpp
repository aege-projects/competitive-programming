#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> power(n), school(n);
	for (int i = 0; i < n; i++) {
		cin >> power[i];
		power[i]--;
	}

	for (int i = 0; i < n; i++) {
		cin >> school[i];
		school[i]--;
	}
	
	vector<int> chosen(k);
	for (int i = 0; i < k; i++) {
		cin >> chosen[i];
		chosen[i]--;
	}

	vector<int> strongest(m, -1);
	for (int i = 0; i < n; i++) {
		if (strongest[school[i]] < power[i]) {
			strongest[school[i]] = power[i];
		}
	}

	vector<bool> used(m, 0);
	int count = 0;
	for (int i = 0; i < k; i++) {
		if (power[chosen[i]] == strongest[school[chosen[i]]]) {
			if (!used[school[chosen[i]]]) {
				used[school[chosen[i]]] = true;
			} else {
				count++;
			}
		} else {
			count++;
		}
	}

	cout << count << endl;
	return 0;
}
