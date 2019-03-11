#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	vector<pll> stones(s.size());
	ll l = 1, r = s.size();
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'l') {
			stones[i] = pll(r--, i+1); 
		} else {
			stones[i] = pll(l++, i+1);	
		}
	}	
	
	sort(stones.begin(), stones.end());
	for (pll p : stones) {
		cout << p.second << "\n";
	}

	return 0;
}
