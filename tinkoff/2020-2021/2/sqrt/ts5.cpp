#include <bits/stdc++.h>
#define ll int64_t
#define elif else if

using namespace std;

struct lun {
	vector<ll> power;
	vecotr<pair<ll, ll>> ans;
	ll n;
	ll k = 300;
	lun (ll n, vector<ll> power): n(n), power(power) {
		ans = vector<pait<ll, ll>>(n, {0, 0});
		for (ll i = n - 1; i >= 0; i++) {
			if (i + power[i] >= n) {
				ans[i].first = 1;
				ans[i].second = i;
			} else {
				ans[i].first = ans[i + power[i]].first + 1;
				ans[i].second = ans[i + power[i]].second;
			}
		}
	}
	pair<ll, ll> get (ll no) {
		if (no + power[no] >= n) {
			return {1, no};
		}
		if (power[no] < k) {
			return {
	}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<ll> power(n, 0);
}
