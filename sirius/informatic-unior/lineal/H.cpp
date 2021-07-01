#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	vector<pair<ll, ll>> arr;
	ll n;
	cin >> n;
	for (ll i = 0; i < n; i++) {
		ll a;
		cin >> a;
		arr.push_back({a, 0});
	}
	cin >> n;
	for (ll i = 0; i < n; i++) {
		ll a;
		cin >> a;
		arr.push_back({a, 1});
	}
	cin >> n;
	for (ll i = 0; i < n; i++) {
		ll a;
		cin >> a;
		arr.push_back({a, 2});
	}
	cin >> n;
	for (ll i = 0; i < n; i++) {
		ll a;
		cin >> a;
		arr.push_back({a, 3});
	}
	vector<queue<ll>> col(4);
	sort(arr.begin(), arr.end());
	ll e = 0;
	pair<ll, pair<pair<ll, ll>, pair<ll, ll>>> ans = {1000000000000, {{0, 0}, {0, 0}}};
	for (ll i = 0; i <= arr.size(); i++) {
		if (i != 0) {
			col[arr[i-1].second].pop();
		}
		while (e < arr.size() && (col[0].size() == 0 || col[1].size() == 0 || col[2].size() == 0 || col[3].size() == 0)) {
			col[arr[e].second].push(arr[e].first);
			e++;
		}
		if (col[0].size() == 0 || col[1].size() == 0 || col[2].size() == 0 || col[3].size() == 0) {
			break;
		}
		ans = min(ans, make_pair(arr[e-1].first-arr[i].first, make_pair(make_pair(col[0].front(), col[1].front()), make_pair(col[2].front(), col[3].front()))));
	}
	cout << ans.second.first.first << ' ' << ans.second.first.second << ' ' << ans.second.second.first << ' ' << ans.second.second.second;
}
