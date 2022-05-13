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
	vector<ll> a(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<ll> need(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> need[i];
	}
	ll k = 300;
	vector<ll> ans(n, -1);
	for (ll i = 0; i < n; i++) {
		if (a[i] >= need[i]) {
			ans[i] = 0;
		}
	}
	ll m;
	cin >> m;
	for (ll ii = 0; ii <= m / k; ii++) {
		vector<tuple<ll, ll, ll, ll>> arr(min(k, m - ii * k));
		vector<ll> new_arr = a;
		vector<ll> add(n + 1, 0), add_p(n + 1, 0);
		for (auto&[l, r, x, y] : arr) {
			cin >> l >> r >> x >> y;
			l--;
			r--;
			add[l] += x;
			add[r + 1] -= x;
			add_p[l] += y;
			add_p[r] -= y;
			add[r + 1] -= (r - l) * y;
		}
		ll now = 0, now_p = 0;
		vector<ll> check;
		for (ll i = 0; i < n; i++) {
			now += now_p;
			now += add[i];
			now_p += add_p[i];
			new_arr[i] += now;
			if (ans[i] == -1 && (new_arr[i] >= need[i])) {
				check.push_back(i);
			}
		}
		for (auto i : check) {
			ll now = a[i];
			for (ll j = 0; j < min(k, m - ii * k); j++) {
				auto[l, r, x, y] = arr[j];
				if (l <= i && i <= r) {
					now += x + y * (i - l);
				}
				if (now >= need[i]) {
					ans[i] = ii * k + j + 1;
					break;
				}
			}
		}
		a = new_arr;
	}
	for (auto i : ans) {
		cout << i << ' ';
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
