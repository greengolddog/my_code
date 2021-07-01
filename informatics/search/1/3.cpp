#include <bits/stdc++.h>
typedef long long ll;

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
	ll x;
	cin >> x;
	ll ans = arr[0];
	for (ll i = 1; i < n; i++) {
		if (abs(ans-x) > abs(arr[i]-x)) {
			ans = arr[i];
		}
	}
	cout << ans;
}
