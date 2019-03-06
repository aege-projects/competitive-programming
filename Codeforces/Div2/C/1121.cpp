#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int p = min(n, k)+1;
	unordered_map<int, pii> t;
	for (int i = 0; i < min(n, k); i++) {
		t[i] = pii(0, a[i]);
	}
	
	int idx = min(n, k)+1;
	vector<bool> special(n, false);

	int m = 0;
	while (!t.empty()) {
		int ttn = INT_MAX;
		for (pair<int, pii> p : t) {
			ttn = min(ttn, p.second.second-p.second.first);	
		}

		for (pair<int, pii> p : t) {
			int rem = p.second.second - p.second.first;
			if (rem == ttn) {
				m++;
				t.erase(p.first);
			}
		}
		
		int nextttn = INT_MAX-1e3;
		for (pair<int, pii> p : t) {
			nextttn = min(nextttn, p.second.second-p.second.first);
		}

		int d = round((100.0*m)/n);
		for (pair<int, pii> p : t) {
			p.second.first += ttn;
			int curr = p.second.first;
			int tot = p.second.second;
			cout << curr << " ";
			if (curr <= d && curr+nextttn >= d) {
				special[p.first] = true;
			}

		}

		while (idx < n && t.size() < k) {
			t[idx] = pii(0, a[idx]);
			idx++;
		}

	}
	
	int count = 0;
	for (int i = 0; i < n; i++) {
		count += special[i];
	}

	cout << count << "\n";

	return 0;
}
