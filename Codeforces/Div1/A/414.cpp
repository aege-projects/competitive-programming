#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<bool> is_prime;
vector<int> prime;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	
	int n, k;
	cin >> n >> k;
	if ((n==1 && k>=1) || n/2 > k) {
		cout << -1 << endl;
		return 0;
	}
	
	if (n==1 && k ==0) {
		cout << 1 << endl;
		return 0;
	}

	int x = k - (n-2)/2;
	cout << x << " " << 2*x << " ";
	int i = 1;
	int count = 0;
	while (count < (n-2)/2) {
		if (i==x || (i+1)==x || i==(2*x) || (i+1)==(2*x)) {
			i += 2;
			continue;
		}
		cout << i << " " << i+1 << " ";
		i += 2;
		count++;
	}

	if (n%2 == 1) {
		while (i==x || i==2*x)
			i++;
		cout << i;
	}
	cout << endl;



	return 0;
}
