#include <bits/stdc++.h>
typedef long long ll;

const ll INF = 1'000'000'000'000'000;

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

ll dfs(ll v, vector<vector<ll>>& arr, vector<ll>& nums, vector<ll>& mins, vector<ll>& maxs) {
	if (arr[v].size() == 0) {
		mins[v] = nums[v];
		maxs[v] = nums[v];
		return 0;
	}
	ll l = arr[v][0], r = arr[v][1];
	ll ans = 0;
	ans += dfs(l, arr, nums, mins, maxs);
	ans += dfs(r, arr, nums, mins, maxs);
	if (mins[l] < mins[r] && maxs[l] < mins[r]) {
		mins[v] = mins[l];
		maxs[v] = maxs[r];
		return ans;
	}
	swap(l, r);
	ans++;
	if (mins[l] < mins[r] && maxs[l] < mins[r]) {
		mins[v] = mins[l];
		maxs[v] = maxs[r];
		return ans;
	}
	return INF;
}

void solve() {
	ll n;
	cin >> n;
	vector<vector<ll>> arr(n);
	vector<ll> nums(n);
	for (ll i = 0; i < n; i++) {
		ll l, r;
		cin >> l >> r;
		if (l == -1) {
			nums[i] = r;
		} else {
			l--;
			r--;
			arr[i].push_back(l);
			arr[i].push_back(r);
		}
	}
	vector<ll> mins(n, INF), maxs(n, -INF);
	ll ans = dfs(0, arr, nums, mins, maxs);
	cout << (ans >= INF ? -1 : ans) << '\n';
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		solve();
	}
}
