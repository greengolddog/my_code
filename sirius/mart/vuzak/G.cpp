#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
typedef int_fast64_t ll;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, k, a, maxc = 126;
	cin >> n >> k >> a;
	string s;
	cin >> s;
	vector<string> arr(n);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<ll> pow(k, 1);
	for (ll i = 1; i < k; i++) {
		pow[i] = pow[i - 1] * maxc;
	}
	unordered_map<ll, ll> all;
	all.reserve(n * k * a * 2);
	for (ll j = 0; j < n; j++) {
		ll x = 0;
		for (ll i = 0; i < k; i++) {
			x += arr[j][i] * pow[i];
		}
		for (ll i = 0; i < k; i++) {
			for (auto cc : s) {
				char c = arr[j][i];
				x -= c * pow[i];
				x += cc * pow[i];
				all[x]++;
				x -= cc * pow[i];
				x += c * pow[i];
			}
		}
		all[x] -= k - 1;
	}
	for (ll j = 0; j < n; j++) {
		ll col = 0;
		string ans;
		ll x = 0;
		for (ll i = 0; i < k; i++) {
			x += arr[j][i] * pow[i];
		}
		for (ll i = 0; i < k; i++) {
			for (auto cc : s) {
				char c = arr[j][i];
				x -= c * pow[i];
				x += cc * pow[i];
				if (all[x] == 1) {
					if (col == 0) {
						ans = arr[j];
						ans[i] = cc;
					}
					col++;
				}
				x -= cc * pow[i];
				x += c * pow[i];
			}
		}
		if (all[x] == 1) {
			col -= k - 1;
		}
		cout << col;
		if (col > 0) {
			cout << ' ' << ans;
		}
		cout << '\n';
	}
}
