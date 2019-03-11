#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pii> ch(n);
	for (int i = 0; i < n; i++) {
		cin >> ch[i].first >> ch[i].second;
	}

	int k;
	cin >> k;
	
	for (int i = 0; i < n; i++) {
		if (ch[i].first <= k && ch[i].second >= k) {
			cout << n-i << endl;
			break;
		}
	}

	return 0;
}
