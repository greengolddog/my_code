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

void dfs(ll v, ll p, vector<vector<ll>>& arr, vector<ll>& dist) {
	dist[v] = dist[p] + 1;
	for (auto i : arr[v]) {
		if (i != p) {
			dfs(i, v, arr, dist);
		}
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<vector<ll>> arr1(n), arr2(n);
	for (ll i = 1; i < n; i++) {
		ll p;
		cin >> p;
		p--;
		arr1[i].push_back(p);
		arr1[p].push_back(i);
	}
	for (ll i = 1; i < n; i++) {
		ll p;
		cin >> p;
		p--;
		arr2[i].push_back(p);
		arr2[p].push_back(i);
	}
	ll x = -1;
	for (ll i = 0; i < n; i++) {
		if (arr1[i].size() == n - 1) {
			x = i;
			break;
		}
	}
	if (x != -1) {
		cout << 2 << '\n';
		cout << x + 1 << ' ' << arr2[x].back() + 1 << '\n';
		return 0;
	}
	ll ans = INF;
	ll a1 = 0, a2 = 0;
	for (ll i = 0; i < n; i++) {
		vector<ll> dist1(n, -1), dist2(n, -1);
		dfs(i, i, arr1, dist1);
		dfs(i, i, arr2, dist2);
		for (ll j = 0; j < n; j++) {
			if (j != i) {
				if (assign_min(ans, dist1[j] + dist2[j])) {
					a1 = i;
					a2 = j;
				}
			}
		}
	}
	cout << ans << '\n' << a1 + 1 << ' ' << a2 + 1 << '\n';
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
