#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<pair<pair<ll, ll>, pair<ll, ll>>> arr(n, {{0, 0}, {0, 0}});
	for (ll i = 0; i < n; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		arr[i] = {{a, b}, {c, i+1}};
	}
	pair<ll, pair<ll, ll>> ans = {0, {0, 0}};
	sort(arr.begin(), arr.end());
	if (n == 0) {
		cout << 0;
		return 0;
	}
	ans = min(make_pair(arr[0].second.first+abs(arr[1].first.first-arr[0].first.first), make_pair(arr[0].first.second, arr[0].second.second)), make_pair(arr[n-1].second.first+abs(arr[n-1].first.first-arr[n-1].first.first), make_pair(arr[n-1].first.second, arr[n-1].second.second)));
	for (ll i = 1; i < n-1; i++) {
		if (ans > make_pair(arr[i].second.first, make_pair(arr[i].first.second, arr[i].second.second))) {
			ans = make_pair(arr[i].second.first, make_pair(arr[i].first.second, arr[i].second.second));
		}
	}
	cout << ans.second.second;
}

