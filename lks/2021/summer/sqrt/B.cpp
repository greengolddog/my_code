#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1000000000000000;

int main() {
	freopen("jam.in", "r", stdin);
	freopen("jam.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> arr(n, 0), ans(n, -1);
	vector<bool> old(n, false);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		arr[i] = x - arr[i];
		if (arr[i] < 1) {
			old[i] = true;
			ans[i] = 0;
		}
	}
	ll m;
	cin >> m;
	vector<tuple<ll, ll, ll, ll>> q;
	for (ll i = 0; i < m; i++) {
		ll l, r, x, y;
		cin >> l >> r >> x >> y;
		l--;
		r--;
		q.push_back(tie(l, r, x, y));
	}
	ll k = 600, nn = 0;
	vector<tuple<ll, ll, ll, ll, ll, ll>> nq;
	for (auto&[l, r, x, y] : q) {
		nq.push_back(make_tuple(l, 0, l, r, x, y));
		nq.push_back(make_tuple(r, 1, l, r, x, y));
		nn++;
		if (nq.size() == k || nn == m) {
			nq.push_back(make_tuple(INF, INF, INF, INF, INF, INF));
			sort(nq.begin(), nq.end());
			ll now = 0, na = 0, last = 0;
			vector<bool> new_old(n, false);
			vector<ll> old_arr = arr;
			for (ll i = 0; i < n; i++) {
				now += na;
				arr[i] -= now;
				while (get<0>(nq[last]) == i) {
					if (!get<1>(nq[last])) {
						now += get<4>(nq[last]);
						na += get<5>(nq[last]);
						arr[i] -= get<4>(nq[last]);
					} else {
						now -= get<4>(nq[last]);
						na -= get<5>(nq[last]);
						now -= get<5>(nq[last]) * (get<3>(nq[last]) - get<2>(nq[last]));
					}
					last++;
				}
				if (arr[i] < 1) {
					new_old[i] = true;
				}
			}
			for (ll i = 0; i < n; i++) {
				if (old[i] != new_old[i]) {
					old[i] = true;
					for (ll j = nn - nq.size() / 2; j < nn; j++) {
						auto[l2, r2, x2, y2] = q[j];
						if (l2 <= i && i <= r2) {
							old_arr[i] -= x2;
							old_arr[i] -= (i - l2) * y2;
						}
						if (old_arr[i] < 1) {
							ans[i] = j + 1;
							break;
						}
					}
				}
			}
			nq.resize(0);
		}
	}
	for (auto i : ans) {
		cout << i << ' ';
	}
}
