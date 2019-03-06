#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	vector<int> x(n);
	unordered_map<int, int> cnt;
	int max_x = INT_MIN;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		max_x = max(max_x, x[i]);
		cnt[x[i]]++;
	}

	max_x++;
	vector<int> spf(max_x, 1);
	for (int i = 2; i < max_x; i++) {
		if (i%2 == 0) {
			spf[i] = 2;
		} else {
			spf[i] = i;
		}
	}

	for (int i = 3; i*i < max_x; i += 2) {
		if (spf[i] == i) {
			for (int j = i*i; j < max_x; j += i) {
				if (spf[j] == j) {
					spf[j] = i;
				}
			}
		}
	}

	vector<ll> sum(max_x, 0);
	for (pii p : cnt) {
		int key = p.first;
		int occ = p.second;
		unordered_set<int> divisors;
		while (key != 1) {
			divisors.insert(spf[key]);
			key /= spf[key];
		}
		for (int divisor : divisors) {
			sum[divisor] += occ;
		}
	}
	
	for (int i = 2; i < max_x; i++) {
		sum[i] += sum[i-1];
	}

	int m;
	cin >> m;
	while(m--) {
		int l, r;
		cin >> l >> r;
		if (l >= max_x) {
			cout << 0 << endl; 
			continue;
		}
		r = min(max_x-1, r);
		cout << sum[r]-sum[l-1] << endl;
	}
	return 0;
}
