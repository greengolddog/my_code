#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, x;
	cin >> n >> x;
	vector<ll> a(n, 0), b(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (ll i = 0; i < n; i++) {
		cin >> b[i];
	}
	pair<ll, ll> m = {a[0], 0};
	pair<ll, pair<ll, ll>> ans = {0, {-2, -2}};
	for (ll i = 1; i < n; i++) {
		ans = max(ans, {x/m.first*b[i] - x/m.first*m.first, {m.second, i}});
		m = min(m, {a[i], i});
	}
	cout << x+ans.first << '\n' << ans.second.first+1 << ' ' << ans.second.second+1;
}
