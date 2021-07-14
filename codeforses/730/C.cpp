#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll x(ll f, ll s, ll k) {
	vector<ll> arr1, arr2;
	while (f != 0) {
		arr1.push_back(f % k);
		f = f/k;
	}
	while (s != 0) {
		arr2.push_back(s % k);
		s = s/k;
	}
	while (arr2.size() > arr1.size()) {
		arr1.push_back(0);
	}
	while (arr1.size() > arr2.size()) {
		arr2.push_back(0);
	}
	for (ll i = 0; i < arr1.size(); i++) {
		arr1[i] = (arr1[i]+arr2[i])%k;
	}
	ll ans = 0, pow = 1;
	for (auto i : arr1) {
		ans += i*pow;
		pow *= k;
	}
	return ans;
}

ll x2(ll f, ll s, ll k) {
	vector<ll> arr1, arr2;
	while (f != 0) {
		arr1.push_back(f % k);
		f = f/k;
	}
	while (s != 0) {
		arr2.push_back(s % k);
		s = s/k;
	}
	while (arr2.size() > arr1.size()) {
		arr1.push_back(0);
	}
	while (arr1.size() > arr2.size()) {
		arr2.push_back(0);
	}
	for (ll i = 0; i < arr1.size(); i++) {
		if (arr1[i] >= arr2[i]) {
			arr1[i] = arr1[i]-arr2[i];
		} else {
			arr1[i] = k-arr2[i]+arr1[i];
		}
	}
	ll ans = 0, pow = 1;
	for (auto i : arr1) {
		ans += i*pow;
		pow *= k;
	}
	return ans;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		ll n, k, uk = 0;
		cin >> n >> k;
		for (ll i = 0; i < n; i++) {
			cout << x2(uk, i, k) << endl;
			ll ans;
			cin >> ans;
			if (ans) {
				break;
			}
			cout << i << ' ' << uk << ' ' << x2(uk, i, k) << ' ' << x2(uk, x2(uk, i, k), k) << endl;
			uk = x2(uk, x2(uk, i, k), k);
		
	}
}
