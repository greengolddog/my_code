#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll mod = 1'000'000'007;

ll get(string x) {
	vector<vector<ll>> arr(x.size(), vector<ll>(10));
	bool b = true;
	for (ll i = x[0] - '0' - 1; i >= 0; i--) {
		arr[0][i] = 1;
	}
	for (ll i = 1; i < x.size(); i++) {
		for (ll j = x[i] - '0' - 1; j >= x[i - 1] - '0'; j--) {
			arr[i][j] += b;
			arr[i][j] = arr[i][j] % mod;
		}
		for (ll j = 0; j < 10; j++) {
			for (ll k = 0; k <= j; k++) {
				arr[i][j] += arr[i - 1][k];
				arr[i][j] = arr[i][j] % mod;
			}
		}
		if (x[i - 1] > x[i]) {
			b = false;
		}
	}
	ll ans = 0;
	for (ll i = 1; i < 10; i++) {
		ans += arr[x.size() - 1][i];
		ans = ans % mod;
	}
	return (ans + 1 + b) % mod;
}

ll sub(ll a, ll b) {
	if (a - b < 0) {
		return a - b + mod;
	}
	return a - b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string l, r;
	cin >> l >> r;
	bool be = false, f = true;
	char last;
	for (auto i : l) {
		if (be) {
			if (i < last) {
				f = !f;
				break;
			} else {
				last = i;
			}
		} else {
			if (i != '0') {
				last = i;
				be = !be;
			}
		}
	}
	cout << (sub(get(r), get(l)) + f) % mod;
}
