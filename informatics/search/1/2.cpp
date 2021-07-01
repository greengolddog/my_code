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
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		if (arr[i] == x) {
			ans++;
		}
	}
	cout << (ans ? "YES" : "NO");
}
