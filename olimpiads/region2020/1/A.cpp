#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

int main() {
	ll a,b;
	cin >> a >> b;
	ll c = b-a;
	ll md = c;
	for (ll i = 2; i*i <= (c+4); i++) {
		if (c % i == 0) {
			md = i;
			break;
		}
	}
	if (md == 1) {
		cout << -1 << ' ' << -1;
	} elif(a == 1 and b == 1) {
		cout << 2 << ' ' << 4;
	} elif(a == 2 and b == 2) {
		cout << 3 << ' ' << 6;
	} elif(a == 3 and b == 3) {
		cout << 4 << ' ' << 8;
	} elif(md == b-1) {
		cout << -1 << ' ' << -1;
	} else {
		ll md2 = 0;
		for (ll i = 2; i*i <= ((b-b%md)/md); i++) {
			if (((b-b%md)/md) % i == 0) {
				md2 = i;
				break;
			}
		}
		if (md2 == 0) {
			if (md == (b-b%md)) {
				cout << -1 << ' ' << -1;
			} else {
				cout << md << ' ' << (b-b%md);
			}
		} else {
			cout << md << ' ' << md*md2;
		}
	}
}