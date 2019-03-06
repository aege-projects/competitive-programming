#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	if ((a==d && a!= 0) || (a==d && a==0 && c==0)) {
		cout << 1 << "\n";
	} else {
		cout << 0 << "\n";
	}
	return 0;
}
