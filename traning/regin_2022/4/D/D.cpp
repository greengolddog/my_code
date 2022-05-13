#include <bits/stdc++.h>
typedef int_fast32_t ll;

const ll INF = 9'000'000'000'000'000'000, mod = 1'000'000'007;

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

ll sub(ll a, ll b) {
	if (b > a) {
		return a - b + mod;
	}
	return a - b;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m, q;
	cin >> n >> m >> q;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<tuple<ll, ll, ll>> arr(m + 1, make_tuple(0ll, 0ll, 0ll));
	for (ll i = 1; i <= m; i++) {
		cin >> get<0>(arr[i]) >> get<1>(arr[i]) >> get<2>(arr[i]);
	}
	ll k = 400;
	vector<vector<ll>> all;
	vector<vector<ll>> save;
	for (ll i = 0; i <= m; i++) {
		for (ll j = get<0>(arr[i]) - 1; j < get<1>(arr[i]); j++) {
			a[j] += get<2>(arr[i]);
		}
		vector<ll> now(1, 0);
		for (auto j : a) {
			now.push_back(now.back() + ((__int128)j * j % mod) % mod);
		}
		if (i % k == 0) {
			all.push_back(vector<ll>(n + 1, 0));
			save.push_back(a);
		}
		for (ll j = 0; j <= n; j++) {
			all.back()[j] += now[j];
			all.back()[j] %= mod;
		}
	}
	for (ll _ = 0; _ < q; _++) {
		ll l, r, x, y;
		cin >> l >> r >> x >> y;
		l--;
		ll ans = 0;
		bool b = false;
		for (ll j = (x + k - 1) / k; j < (y + 1) / k; j++) {
			ans += sub(all[j][r], all[j][l]);
			ans %= mod;
			b = true;
		}
		if (x / k != (x + k - 1) / k || !b) {
			vector<ll> a = save[x / k];
			for (ll i = x / k * k + 1; i < min(m + 1, x / k * k + k); i++) {
				for (ll j = get<0>(arr[i]) - 1; j < get<1>(arr[i]); j++) {
					a[j] += get<2>(arr[i]);
				}
				if (x <= i && i <= y) {
					for (ll j = l; j < r; j++) {
						ans += (__int128)(a[j] * a[j]) % mod;
						ans %= mod;
					}
				}
			}
		}
		if ((y + 1) / k != (y + k) / k && ((y + 1) / k != x / k)) {
			vector<ll> a = save[y / k];
			if (x <= y / k * k && y / k * k <= y) {
				for (ll j = l; j < r; j++) {
					ans += (__int128)(a[j] * a[j]) % mod;
					ans %= mod;
				}
			}
			for (ll i = y / k * k + 1; i < min(m + 1, y / k * k + k); i++) {
				for (ll j = get<0>(arr[i]) - 1; j < get<1>(arr[i]); j++) {
					a[j] += get<2>(arr[i]);
				}
				if (x <= i && i <= y) {
					for (ll j = l; j < r; j++) {
						ans += (__int128)(a[j] * a[j]) % mod;
						ans %= mod;
					}
				}
			}
		}
		cout << ans << '\n';
	}
}
/*
⣿⣿⣿⣿⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣵⣿⣿⣿⠿⡟⣛⣧⣿⣯⣿⣝⡻⢿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⠋⠁⣴⣶⣿⣿⣿⣿⣿⣿⣿⣦⣍⢿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⢷⠄⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣏⢼⣿⣿⣿⣿
⢹⣿⣿⢻⠎⠔⣛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⣿⣿⣿⣿
⢸⣿⣿⠇⡶⠄⣿⣿⠿⠟⡛⠛⠻⣿⡿⠿⠿⣿⣗⢣⣿⣿⣿⣿
⠐⣿⣿⡿⣷⣾⣿⣿⣿⣾⣶⣶⣶⣿⣁⣔⣤⣀⣼⢲⣿⣿⣿⣿
⠄⣿⣿⣿⣿⣾⣟⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⢟⣾⣿⣿⣿⣿
⠄⣟⣿⣿⣿⡷⣿⣿⣿⣿⣿⣮⣽⠛⢻⣽⣿⡇⣾⣿⣿⣿⣿⣿
⠄⢻⣿⣿⣿⡷⠻⢻⡻⣯⣝⢿⣟⣛⣛⣛⠝⢻⣿⣿⣿⣿⣿⣿
⠄⠸⣿⣿⡟⣹⣦⠄⠋⠻⢿⣶⣶⣶⡾⠃⡂⢾⣿⣿⣿⣿⣿⣿
⠄⠄⠟⠋⠄⢻⣿⣧⣲⡀⡀⠄⠉⠱⣠⣾⡇⠄⠉⠛⢿⣿⣿⣿
⠄⠄⠄⠄⠄⠈⣿⣿⣿⣷⣿⣿⢾⣾⣿⣿⣇⠄⠄⠄⠄⠄⠉⠉
⠄⠄⠄⠄⠄⠄⠸⣿⣿⠟⠃⠄⠄⢈⣻⣿⣿⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⢿⣿⣾⣷⡄⠄⢾⣿⣿⣿⡄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠸⣿⣿⣿⠃⠄⠈⢿⣿⣿⠄⠄⠄⠄⠄⠄⠄
*/
