#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	ll n;
	cin >> n;
	ll ans = 0;
	while (n != 0) {
		string s = to_string(n);
		ll now = pow(10, s.size() - 1);
		bool b = false;
		for (ll i = 0; i < s.size(); i++) {
			if (!b) {
				if ((s[i] - '0') % 2 == 1) {
					b = true;
				}
			} else {
				ans += now * ((s[i] - '0') + 1);
				n -= now * ((s[i] - '0') + 1);
			}
			now /= 10;
		}
		if (b) {
			n--;
			ans++;
		}
		if (n != 0) {
			n /= 2;
			ans++;
		}
	}
	cout << ans;
}

int main() {
	ll t = 1;
	//cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}
