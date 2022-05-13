#include <bits/stdc++.h>
typedef long long ll;

const ll INF = 9'000'000'000'000'000'000;

template<typename T>
bool assign_max(T& a, T b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_min(T& a, T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

using namespace std;

void dfs(ll v, ll p, vector<vector<ll>>& arr, vector<ll>& dp, vector<bool>& used, ll hn, vector<pair<ll, ll>>& ans, vector<ll>& h) {
        used[v] = true;
        dp[v] = hn;
        h[v] = hn;
	sort(arr[v].begin(), arr[v].end());
	ll x = 1;
        for (auto i : arr[v]) {
                if ((i == p && (x == arr[v].size() || arr[v][x] != i)) || i == v) continue;
                if (used[i]) {
                        dp[v] = min(dp[v], h[i]);
                } else {
                        dfs(i, v, arr, dp, used, hn + 1, ans, h);
                        if (dp[i] > h[v]) {
                                ans.push_back({v, i});
                        }
                        dp[v] = min(dp[v], dp[i]);
                }
		x++;
        }
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	if (m > 2*n) {
		cout << "! No" << endl;
		return 0;
	}
	vector<vector<ll>> arr(n);
	for (ll i = 0; i < n; i++) {
		ll x = -1;
		do {
			if (x == -3) {
				return 0;
			}
			if (x != -1) {
				arr[i].push_back(x);
				arr[x].push_back(i);
			}
			cout << "? " << i + 1 << endl;
			cin >> x;
			x--;
		} while (x != -2);
	}
	vector<bool> used(n, false);
	vector<ll> dp(n), h(n);
	vector<pair<ll, ll>> ans;
	for (ll i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i, i, arr, dp, used, 0, ans, h);
		}
	}
	if (ans.size() < (m + 1) / 2) {
		cout << "! No" << endl;
		return 0;
	}
	cout << "! Yes" << endl;
	for (ll i = 0; i < (m + 1) / 2; i++) {
		cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
	}
}
