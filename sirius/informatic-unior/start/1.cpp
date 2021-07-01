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
	}
	ll ans = 0, summ = 0;
	for (ll i = 0; i < min(n, 2*m+1); i++) {
		summ += arr[i];
	}
	ans = summ;
	for (ll i = 2*m+1; i < n; i++) {
		summ += arr[i];
		summ -= arr[i-2*m-1];
		ans = max(ans, summ);
	}
	cout << ans;
}
