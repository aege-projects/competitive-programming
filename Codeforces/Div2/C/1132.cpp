#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;


void print(vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
		if (i < v.size()-1) {
			cout << " ";
		} else {
			cout << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	vector<pii> p(q);
	vector<int> sum(n+1, 0);
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		p[i] = pii(l, r);	
		
		sum[l]++;
		if (r < n)
			sum[r+1]--;
	}

	for (int i = 1; i <= n; i++) {
		sum[i] += sum[i-1];
	}

	
	sort(p.begin(), p.end());
	vector<int> z, o, t;
	z = o = t = vector<int> (n+1, 0);

	for (int i = 1; i <= n; i++) {
		z[i] += (z[i-1] + (sum[i]==0));
		o[i] += (o[i-1] + (sum[i]==1));
		t[i] += (t[i-1] + (sum[i]==2));
	}
	
	int non_painted = INT_MAX;
	for (int i = 0; i < q; i++) {
		int a = p[i].first, b = p[i].second;
	
		for (int j = i+1; j < q; j++) {
			int u = p[j].first, v = p[j].second;

			if (v <= b) {
				non_painted = min(non_painted, o[b]-o[a-1] + t[v]-t[u-1]);
			} else if (u <= b && v > b) {
				non_painted = min(non_painted, o[v]-o[a-1] + t[b]-t[u-1]);
			} else {
				non_painted = min(non_painted, o[b]-o[a-1] + o[v]-o[u-1]);
			}
		}
	}
	cout << n-z[n]-non_painted << "\n";

	return 0;
}
