#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll a, b, c;
	cin >> a >> b >> c;
	if ((c % a)/(b - a) > c / a) {
		cout << c - (c % a - (c / a * (b - a)));
		return 0;
	}
	cout << c - (c % a % (b - a));
}
