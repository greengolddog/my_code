#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<vector<ll>> arr(n, vector<ll>(12, 0));
	for (ll i = 2; i < 11; i++) {
		arr[0][i] = 1;
	}
	for (ll i = 1; i < n; i++) {
		for (ll j = 1; j < 11; j++) {
			arr[i][j] = arr[i-1][j-1]+arr[i-1][j]+arr[i-1][j+1];
		}
	}
	ll ans = 0;
	for (ll i = 1; i < 11; i++) {
		ans += arr[n-1][i];
	}
	cout << ans;
}
