#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MAXN = 1000000000000;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, now = 0, maxx = 1;
	cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<ll> dp(n, 1);
	vector<ll> pred(n, 0);
	for (ll i = 1; i < n; i++) {
		pred[i] = i;
		for (ll j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				if (dp[j]+1 > dp[i]) {
					pred[i] = j;
					dp[i] = max(dp[i], dp[j]+1);
				}
			}
		}
		if (dp[i] > maxx) {
			maxx = dp[i];
			now = i;
		}
	}
	vector<ll> ans(1, arr[now]);
	while (pred[now] != now) {
		now = pred[now];
		ans.push_back(arr[now]);
	}
	reverse(ans.begin(), ans.end());
	for (auto i : ans) {
		cout << i << ' ';
	}
}
