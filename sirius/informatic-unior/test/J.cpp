#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<pair<ll, ll>> s;
	vector<pair<ll, ll>> all;
	for (ll i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		all.push_back({a, b});
		s.push_back({a, 0});
		s.push_back({b, i+1});
		s.push_back({b, n+1});
	}
	vector<ll> ans(n, 0);
	ll now = 0;
	vector<ll> arr;
	sort(s.begin(), s.end());
	for (auto[d, c] : s) {
		if (c == 0) {
			now++;
		} else {
			if (c == n+1) {
				arr.push_back(d);
				now--;
			} else {
				ans[c-1] = now-1+(arr.end()-lower_bound(arr.begin(), arr.end(), all[c-1].first));
			}
		}
	}
	for (auto i : ans) {
		cout << i << '\n';
	}
}
