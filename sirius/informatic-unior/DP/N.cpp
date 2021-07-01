#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MAXN = 100000000000000ll;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll l, n, sum = 0;
	cin >> l >> n;
	vector<ll> arr(n+1, 0), pref(n+2, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		pref[i+1] = arr[i];
		arr[i] -= sum;
		sum += arr[i];
	}
	arr[n] = l - sum;
	pref[n+1] = l;
	vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j <= n-i; j++) {
			dp[j][j+i] = MAXN;
			for (ll k = j; k < j+i; k++) {
				dp[j][j+i] = min(dp[j][j+i], pref[i+j+1]-pref[j]+dp[j][k]+dp[k+1][j+i]);
			}
		}
	}
	cout << dp[0][n];
}
