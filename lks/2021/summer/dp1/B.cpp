#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	ll sum = 0;
	vector<ll> arr1, arr2;
	for (ll i = 0; i < n / 2; i++) {
		ll x;
		cin >> x;
		arr1.push_back(x);
		sum += x;
	}
	for (ll i = n / 2; i < n; i++) {
		ll x;
		cin >> x;
		arr2.push_back(x);
		sum += x;
	}
	vector<ll> a1, a2;
	for (ll i = 0; i < (1 << arr1.size()); i++) {
		ll ans = 0;
		for (ll j = 0; j < arr1.size(); j++) {
			if (i >> j & 1) {
				ans += arr1[j];
			}
		}
		a1.push_back(ans);
	}
	for (ll i = 0; i < (1 << arr2.size()); i++) {
		ll ans = 0;
		for (ll j = 0; j < arr2.size(); j++) {
			if (i >> j & 1) {
				ans += arr2[j];
			}
		}
		a2.push_back(ans);
	}
	sort(a1.begin(), a1.end());
	sort(a2.begin(), a2.end());
	ll u = a2.size() - 1;
	ll m = 0, ideal = sum / 2;
	for (auto i : a1) {
		while (u > 0 && a2[u] + i > ideal) {
			u--;
		}
		if (a2[u] + i > ideal) {
			break;
		}
		m = max(m, a2[u] + i);
	}
	cout << (sum - m) - m;
}
