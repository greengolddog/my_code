#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<pair<ll, ll>> arr;
	vector<pair<ll, ll>> indexs;
	vector<ll> ans(m, 0);
	for (ll i = 0; i < n; i++) {
		ll l, r;
		cin >> l >> r;
		arr.push_back({min(l, r), 0});
		arr.push_back({max(r, l), 2});
	}
	for (ll i = 0; i < m; i++) {
		ll l;
		cin >> l;
		arr.push_back({l, 1});
		indexs.push_back({l, i});
	}
	sort(indexs.begin(), indexs.end());
	sort(arr.begin(), arr.end());
	ll cnt = 0, l = 0;
	for (auto&[n, o] : arr) {
		if (o == 0) {
			cnt++;
		}
		if (o == 1) {
			ans[indexs[l].second] = cnt;
			l++;
		}
		if (o == 2) {
			cnt--;
		}
	}
	for (auto i : ans) {
		cout << i << ' ';
	}
}
