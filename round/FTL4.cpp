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

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> arr(1, 0);
	vector<ll> pref(2, 0), bn(1, 0);
	for (ll i = 0; i < n; i++) {
		char c;
		ll l, r, x;
		cin >> c >> l >> r >> x;
		if (c == '+') {
			set<ll> s;
			l = lower_bound(bn.begin(), bn.end(), l) - bn.begin();
			r = lower_bound(bn.begin(), bn.end(), r) - bn.begin();
			vector<bool> be(n + 1, false);
			for (ll i = l; i <= r; i++) {
				be[arr[i]] = true;
			}
			ll ans = 0;
			for (; be[ans]; ans++) {}
			arr.push_back(ans);
			if (x % 2 == 1) {
				pref.push_back(pref.back() ^ ans);
			} else {
				pref.push_back(pref.back());
			}
			bn.push_back(bn.back() + x);
		} else {
			if (x % 2 == 0) {
				cout << "SECOND\n";
				continue;
			}
			ll nl = lower_bound(bn.begin(), bn.end(), l) - bn.begin(), nr = lower_bound(bn.begin(), bn.end(), r) - bn.begin();
			ll ans = 0;
			if (nl != nr) {
				ans ^= pref[nr] ^ pref[nl + 1];
				if ((bn[nl] - l) % 2 == 0) {
					ans ^= arr[nl];
				}
				if ((r - bn[nr - 1]) % 2 == 1) {
					ans ^= arr[nr];
				}
			} else {
				if ((r - l) % 2 == 0) {
					ans ^= arr[nl];
				}
			}
			cout << (ans == 0 ? "SECOND" : "FIRST") << '\n';
		}
	}
}
