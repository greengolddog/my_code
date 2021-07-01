#include <bits/stdc++.h>
#define elif else if
using namespace std;
typedef long long ll;
typedef string str;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	if (c == a) {
		if (d) {
			cout << 1;
		} else {
			cout << b;
		}
		return 0;
	}
	if (c == b) {
		if (d) {
			cout << 1;
		} else {
			cout << a;
		}
		return 0;
	}
	if (a == b) {
		if (d) {
			cout << a+1-c;
		} else {
			cout << c;
		}
		return 0;
	}
	if (c > b) {
		if (d) {
			cout << a-c+1;
		} else {
			cout << c-1;
		}
		return 0;
	}
	if (c > a) {
		if (d) {
			cout << b-c+1;
		} else {
			cout << c-1;
		}
		return 0;
	}
	if (d) {
		cout << min(a, b)-c+1;
	} else {
		cout << max(a, b)-min(a, b)+c;
	}
}
