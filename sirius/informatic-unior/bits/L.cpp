#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	const ll MAXN = 10000000000000000;
	cin >> n;
	vector<vector<ll>> arr(n, vector<ll>(n, 0));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	vector<vector<ll>> dp(1 << n, vector<ll>(n, MAXN)), pred(1 << n, vector<ll>(n, -1));
	for (ll i = 0; i < n; i++) {
		dp[0][i] = 0;
	}
	for (ll i = 0; i < (1 << n); i++) {
		for (ll j = 0; j < n; j++) {
			for (ll k = 0; k < n; k++) {
				if (((i >> k) & 1) == 0 && k != j) {
					if (dp[i][j] + arr[j][k] < dp[i | (1 << j)][k]) {
						pred[i | (1 << j)][k] = j;
						dp[i | (1 << j)][k] = dp[i][j] + arr[j][k];
					}
				}
			}
		}
	}
	ll ans = -1, min = MAXN;
	for (ll i = 0; i < n; i++) {
		if (dp[((1 << n)-1) & (~(1 << i))][i] < min) {
			ans = i;
			min = dp[((1 << n)-1) & (~(1 << i))][i];
		}
	}
	cout << min << '\n';
	ll now =(((1 << n)-1) & (~(1 << ans)));
	vector<ll> a;
	while (now != 0) {
		a.push_back(ans);
		ans = pred[now][ans];
		now = now & (~(1 << ans));
	}
	a.push_back(ans);
	reverse(a.begin(), a.end());
	for (auto i : a) {
		cout << i + 1 << ' ';
	}
}
