#include <bits/stdc++.h>
typedef long long ll;

const ll INF = 9'000'000'000'000'000'000;

template<typename T>
bool assign_max(T& a, T b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_min(T& a, T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

using namespace std;

ll ask(ll x) {
	cout << 'X' << ' ' << x << endl;
	ll c;
	cin >> c;
	if (c == -1) {
		exit(0);
	}
	ll c2;
	cin >> c2;
	c *= x / c2;
	return c;
}

void solve() {
	ll l = 1, r = INF;
	ll col = ask(r);
	l = r / (col + 1);
	r /= col;
	r++;
	while (r - l > 1) {
		ll mid = (l + r) / 2;
		ll x = ask(mid - 1);
		if (x == 0) {
			l = mid;
		} else {
			r = mid;
		}
	}
	cout << 'N' << l << endl;
	string s;
	cin >> s;
	if (s[0] != 'C') {
		exit(0);
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}
