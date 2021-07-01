#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, k;
	cin >> n >> k;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	pair<ll, ll> m = {arr[0], 0};
	pair<ll, pair<ll, ll>> ans = {0, {0, 0}};
	for (ll i = k+1; i < n; i++) {
		ans = max(ans, {m.first+arr[i], {m.second, -i}});
		m = max(m, {arr[i-k], -(i-k)});
	}
	cout << -ans.second.first+1 << ' ' << -ans.second.second+1;
}
