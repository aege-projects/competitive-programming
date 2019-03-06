#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	bool increasing = true, decreasing = true;
	for (int i = 0; i < n-1; i++) {
		if (a[i] > a[i+1]) {
			increasing = false;
			break;
		}

		if (a[i] < a[i+1]) {
			decreasing = false;
			break;
		}
	}

	if ((increasing && decreasing) || n < 3) {
		for (int i = 0; i < m; i++) {
			int dummy;
			cin >> dummy >> dummy;
			cout << "Yes\n";
		}
		return 0;
	}

	vector<bool> inc(n, false);
	vector<int> prev(n, false);
	prev[0] = prev[1] = 0;
	if (increasing) {
		inc[0] = inc[1] = true;
	}

	for (int i = 0; i < n-1; i++) {
		if (inc[i]) {
			if (a[i+1] < a[i]) {
				prev[i+1] = i+1;
				inc[i+1] = false;
			} else {
				prev[i+1] = prev[i];
				inc[i+1] = true;
			}
		} else {
			if (a[i+1] > a[i]) {
				prev[i+1] = i+1;
				inc[i+1] = true;
			} else {
				prev[i+1] = prev[i];
				inc[i+1] = false;
			}
		}
	}

	for (int query = 0; query < m; query++) {
		int l, r;
		cin >> l >> r;
	
		l--; r--;
		if (r-l <= 1) {
			cout << "Yes\n";
			continue;
		}
		
		if (inc[r]) {
			if (prev[r] <= l) {
				cout << "Yes\n";
				continue;
			} 
			
			int p = prev[r];
			if (p > 0 && prev[p-1] <= l && a[p-1] == a[l]) {
				cout << "Yes\n";
				continue;
			}
				
			

		} else {
			if (prev[r] <= l) {
				cout << "Yes\n";
				continue;
			} 
			
			int p = prev[r];
			if (p > 0) {
				int pp = prev[p-1];
				if (pp <= l) {
					cout << "Yes\n";
					continue;
				}
				
				if (pp > 0 && prev[pp-1] <= l && a[pp-1] == a[l]) {
					cout << "Yes\n";
					continue;
				}
			}
		}
		cout << "No\n";

	}

	

	return 0;
}
