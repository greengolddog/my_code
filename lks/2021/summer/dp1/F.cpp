#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    freopen("trader.in", "r", stdin);
    freopen("trader.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	ll n;
	const ll MAXN = 1'000'000'000'000'000;
	cin >> n;
	vector<vector<ll>> arr(n, vector<ll>(n, 0));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	vector<vector<ll>> dp(1 << n, vector<ll>(n, MAXN)), pred(1 << n, vector<ll>(n, -1));
	dp[0][0] = 0;
	for (ll i = 0; i < (1 << n); i++) {
		for (ll j = 0; j < n; j++) {
			for (ll k = 0; k < n; k++) {
				if (((i >> k) & 1) == 0 && arr[j][k] != 0) {
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
		if (dp[((1 << n) - 1) & (~(1 << i))][i] < min) {
			ans = i;
			min = dp[((1 << n) - 1) & (~(1 << i))][i];
		}
	}
    if (min == MAXN) {
        cout << -1;
        return 0;
    }
	cout << min << '\n';
	ll now =(((1 << n) - 1) & (~(1 << ans)));
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
