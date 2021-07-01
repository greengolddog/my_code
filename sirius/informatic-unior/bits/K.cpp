#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, sum = 0;
	cin >> n;
	vector<ll> arr(n, 0), summs(1, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	ll ans = 0;
	for (ll i = 1; i < (1 << n); i++) {
		ll now = 0;
		for (ll j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				now += arr[j];
			}
		}
		summs.push_back(now);
	}
	for (ll i = 1; i < (1 << n); i++) {
		for (ll j = i; j > 0; j = (j-1)&i) {
			ans += summs[i] % summs[j];
		}
	}
	cout << ans;
}
