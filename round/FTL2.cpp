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
	vector<ll> pref(2, 0);
	for (ll i = 0; i < n; i++) {
		char c;
		ll l, r, x;
		cin >> c >> l >> r >> x;
		if (c == '+') {
			set<ll> s;
			for (ll i = l; i <= r; i++) {
				s.insert(arr[i]);
			}
			ll ans = 0;
			for (; s.find(ans) != s.end(); ans++) {}
			for (ll i = 0; i < x; i++) {
				arr.push_back(ans);
				pref.push_back(pref.back() ^ ans);
			}
		} else {
			if (x % 2 == 0) {
				cout << "SECOND\n";
				continue;
			}
			ll ans = pref[r + 1] ^ pref[l];
			cout << (ans == 0 ? "SECOND" : "FIRST") << '\n';
		}
	}
}
