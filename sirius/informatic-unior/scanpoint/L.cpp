#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<tuple<ll, ll, ll>> arr;
	vector<pair<ll, ll>> last(n, {0, 0});
	for (ll i = 0; i < n; i++) {
		ll l, r;
		cin >> l >> r >> last[i].second;
		arr.push_back({l, 1, i});
		arr.push_back({l+r, 0, i});
	}
	sort(arr.begin(), arr.end());
	vector<ll> dp(arr.size()+1, 0), pred(arr.size()+1, 0), ji(arr.size()+1, 0), f(arr.size()+1, 0);
	for (ll j = 0; j < arr.size(); j++) {
		auto&[_, o, i] = arr[j];
		if (o == 1) {
			last[i].first = j+1;
			dp[j+1] = dp[j];
			pred[j+1] = j;
		} else {
			dp[j+1] = max(dp[j], dp[last[i].first]+last[i].second);
			if (dp[j+1] == dp[last[i].first]+last[i].second) {
				pred[j+1] = last[i].first;
				f[j+1] = 1;
			} else {
				pred[j+1] = j;
			}
		}
		ji[j+1] = i;
	}
	cout << dp[arr.size()] << '\n';
	vector<ll> ans;
	ll now = arr.size();
	while (now != 0) {
		if (f[now]) {
			ans.push_back(ji[now]);
		}
		now = pred[now];
	}
	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for (auto i : ans) {
		cout << i+1 << ' ';
	}
}
