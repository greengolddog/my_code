#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MAXN = 1000000000000;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n;
	vector<ll> arr1(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	cin >> m;
	vector<ll> arr2(m, 0);
	for (ll i = 0; i < m; i++) {
		cin >> arr2[i];
	}
	vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0)), pred(n+1, vector<ll>(m+1, 0));
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			if (arr1[i-1] == arr2[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
				pred[i][j] = 0;
			} else {
				if (dp[i-1][j] >= dp[i][j-1]) {
					pred[i][j] = 1;
				} else {
					pred[i][j] = -1;
				}
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	vector<ll> ans;
	ll x = n, y = m;
	while (x != 0 && y != 0) {
		if (pred[x][y] == 0) {
			ans.push_back(arr1[x-1]);
			x--;
			y--;
		} else {
			x -= pred[x][y] == 1;
			y -= pred[x][y] == -1;
		}
	}
	reverse(ans.begin(), ans.end());
	for(auto i : ans) {
		cout << i << ' ';
	}
}
