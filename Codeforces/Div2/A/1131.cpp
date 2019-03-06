#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll w1, h1, w2, h2;
	cin >> w1 >> h1 >> w2 >> h2;
	
	ll ans = (w1+2)+(2*h1)+(w2+2)+(2*h2)+(w1-w2);	
	cout << ans << endl;
	return 0;
}
