#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef int ll;

const ll INF = 1'000'000'000;

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
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	ll s;
	cin >> s;
	ll ans = INF, nu = 0;
	vector<ll> vost(n, 1);
	for (ll num = 0; num < s; num++) {
		ll kl, kr, ml, mr;
		cin >> kl >> kr >> ml >> mr;
		vector<ll> dp1(n + 1, INF), dp2(n + 1, INF);
		map<pair<ll, ll>, ll> pred;
		dp1[0] = 0;
		dp2[0] = 0;
		for (ll i = 1; i < n; i++) {
			vector<ll> ndp1(n + 1, INF), ndp2(n + 1, INF);
			for (ll j = 0; j < i; j++) {
				if (j == 0) {
					if (assign_min(ndp1[i], dp2[j])) {
						pred[make_pair(i + 1, i)] = j;
					}
					if (assign_min(ndp2[i], dp1[j])) {
						pred[make_pair(i, i + 1)] = j;
					}
				} else {
					if (arr[i] - arr[j - 1] >= kl && arr[i] - arr[j - 1] <= kr) {
						if (assign_min(ndp1[i], dp2[j])) {
							pred[make_pair(i + 1, i)] = j;
						}
					}
					if (arr[i] - arr[j - 1] >= ml && arr[i] - arr[j - 1] <= mr) {
						if (assign_min(ndp2[i], dp1[j])) {
							pred[make_pair(i, i + 1)] = j;
						}
					}
				}
				if (arr[i] - arr[i - 1] >= kl && arr[i] - arr[i - 1] <= kr) {
					assign_min(ndp1[j], dp1[j] + 1);
				}
				if (arr[i] - arr[i - 1] >= ml && arr[i] - arr[i - 1] <= mr) {
					assign_min(ndp2[j], dp2[j] + 1);
				}
			}
			dp1 = ndp1;
			dp2 = ndp2;
		}
		ll x = 0, y = 0;
		for (ll i = 0; i < n; i++) {
			if (assign_min(ans, dp1[i])) {
				x = n;
				y = i;
				nu = num;
			}
			if (assign_min(ans, dp2[i])) {
				x = i;
				y = n;
				nu = num;
			}
		}
		while (x != 0 || y != 0) {
			if (x > y) {
				vost[x - 1] = 1;
				if (x - 1 == y) {
					x = pred[make_pair(x, y)];
				} else {
					x--;
				}
			} else {
				vost[y - 1] = 2;
				if (x == y - 1) {
					y = pred[make_pair(x, y)];
				} else {
					y--;
				}
			}
		}
	}
	if (ans == INF) {
		cout << 0;
		return 0;
	}
	cout << nu + 1 << ' ' << ans << '\n';
	for (auto i : vost) {
		cout << i;
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
