#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	ll ans = 0;
	for (auto i : arr) {
		ans += i;
	}
	cout << ans << '\n';
}
