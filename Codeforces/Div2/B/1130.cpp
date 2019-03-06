#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pii> pos(n+1, pii(-1, -1));	
	
	for (int i = 1; i <= 2*n; i++) {
		int tier;
		cin >> tier;
		if (pos[tier].first == -1) {
			pos[tier].first = i;
		} else {
			pos[tier].second = i;
		}	
	}

	ll dist = 0;
	int dima = 1;
	int sasha = 1;
	for (int i = 1; i <= n; i++) {
		int op1 = pos[i].first;
		int op2 = pos[i].second;
		if (abs(op1-dima) + abs(op2-sasha) < abs(op2-dima) + abs(op1-sasha)) {
			dist += abs(op1-dima) + abs(op2-sasha);
			dima = op1;
			sasha = op2;
		} else {
			dist += abs(op2-dima) + abs(op1-sasha);
			dima  = op2;
			sasha = op1;
		}
	}	

	cout << dist << endl;
	

	return 0;
}
