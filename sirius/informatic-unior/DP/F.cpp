#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MAXN = 1000000000000;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, k, b, m, ans = 0;
	cin >> n;
	vector<ll> arr(n, 0);
	cin >> arr[0] >> k >> b >> m;
	for (ll i = 1; i < n; i++) {
		arr[i] = (k*arr[i-1]+b)%m;
	}
	vector<ll> dp(n+1, MAXN);
	dp[0] = -MAXN;
	for (auto i : arr) {
		ll now = upper_bound(dp.begin(), dp.end(), i) - dp.begin();
		if (dp[now-1] < i) {
			dp[now] = i;
			ans = max(ans, now);
		}
	}
	cout << ans;
}
