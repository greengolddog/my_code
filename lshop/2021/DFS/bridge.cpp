#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void dfs(ll v, ll p, vector<vector<ll>>& arr, vector<ll>& dp, vector<bool>& used, ll hn, vector<pair<ll, ll>>& ans, vector<ll>& h) {
	used[v] = true;
	dp[v] = hn;
	h[v] = hn;
	for (auto i : arr[v]) {
		if (i == p) continue;
		if (used[v]) {
			dp[v] = min(dp[v], h[i]);
		} else {
			dfs(i, v, arr, dp, used, hn+1, ans, h);
			if (dp[i] > h[v]) {
				ans.push_back({v, i});
			}
			dp[v] = min(dp[v], dp[u]);
		}
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
}
