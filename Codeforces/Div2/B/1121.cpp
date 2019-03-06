#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	unordered_map<int, int> count;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			count[a[i]+a[j]]++;
		}
	}
	
	int max_p = 0;
	for (pair<int, int> p : count) {
		max_p = max(max_p, p.second); 
	}	

	cout << max_p << "\n";
	return 0;
}
