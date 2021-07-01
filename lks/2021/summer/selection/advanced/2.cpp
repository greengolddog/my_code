#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void dfs(vector<vector<ll>>& arr, ll now, vector<ll>& used) {
	used[now] = 1;
	for (auto i : arr[now]) {
		if (!used[i]) {
			dfs(arr, i, used);
		}
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll ans = 0;
	ll n, k;
	cin >> n >> k;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i]--;
	}
	if (arr[0] != 0) {
		arr[0] = 0;
		ans++;
	}
	vector<vector<ll>> rev(n, vector<ll>(0, 0));
	for (ll i = 0; i < n; i++) {
		rev[arr[i]].push_back(i);
	}
	vector<ll> dist(n, 0);
	vector<ll> used(n, 0);
	used[0] = 1;
	queue<ll> q;
	q.push(0);
	while(!q.empty()) {
		ll now = q.front();
		q.pop();
		for (auto i : rev[now]) {
			if (!used[i]) {
				dist[i] = dist[now]+1;
				q.push(i);
				used[i] = 1;
			}
		}
	}
	set<pair<ll, ll>> s;
	for (ll i = 0; i < n; i++) {
		s.insert({10000000000-dist[i], i});
	}
	used = vector<ll>(n, 0);
	while (!s.empty()) {
		ll now = s.begin()->second;
		s.erase(s.begin());
		if (!used[now]) {
			if (dist[now] <= k) {
				break;
			}
			for (ll i = 1; i < k; i++) {
				now = arr[now];
			}
			arr[now] = 0;
			ans++;
			dfs(rev, now, used);
		}
	}
	cout << ans;
}
