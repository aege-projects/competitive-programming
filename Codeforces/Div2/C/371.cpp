#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll b, s, c, nb, ns, nc, pb, ps, pc;
ll f(ll x) {
	return max((ll)0, x*b-nb)*pb+max((ll)0, x*s-ns)*ps+max((ll)0, x*c-nc)*pc;
}

int main() {
	string str;
	cin >> str;
	
	b = 0, s = 0, c = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'B')
			b++;

		if (str[i] == 'S')
			s++;

		if (str[i] == 'C')
			c++;
	}
	
	cin >> nb >> ns >> nc;
	cin >> pb >> ps >> pc;

	ll r;
	cin >> r;
	
	ll am = 0, bm = 1e12+1000;
	ll mid, price;
	while (am < bm) {
		mid = am + (bm-am+1)/2;
		price = f(mid);
		if (price > r) {
			bm = mid-1;
		} else {
			am = mid;
		}
	}
	cout << am << endl;
	return 0;
}
