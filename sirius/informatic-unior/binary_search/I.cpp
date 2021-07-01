#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i] -= i;
	}
	sort(arr.begin(), arr.end());
	ll cc = 0, ch = 0;
	for (ll i = 0; i < m; i++) {
		ll c;
		cin >> c;
		c -= i;
		cc += lower_bound(arr.begin(), arr.end(), c)-arr.begin();
		ch += arr.end()-upper_bound(arr.begin(), arr.end(), c);
	}
	cout << ch << ' ' << cc;
}
