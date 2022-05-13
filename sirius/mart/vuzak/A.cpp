#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

mt19937 rnd(time(0));

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<pair<ll, ll>> arr(n * 2);
	vector<ll> ot(n * 2, 0), vp(n * 2, 0);
	for (auto&[a, b] : arr) {
		cin >> a >> b;
	}
	ll num = 0;
	ll ans = 0;
	for (ll i = 0; i < m; i++) {
		ll l, r;
		cin >> l >> r;
		while (num < n * 2 && l > arr[num].second) {
			num++;
		}
		if (r < arr[num].first || l > arr[num].second) {
			ans++;
			continue;
		}
		if (num % 2 == 0) {
			if (r >= arr[num + 1].first && arr[num + 1].second >= l) {
				continue;
			}
		} else {
			if (num + 2 < n * 2) {
				if (r >= arr[num + 2].first && arr[num + 2].second >= l) {
					continue;
				}
			}
		}
		bool b = false;
		if (num + 1 < n * 2) {
			if (r >= arr[num + 1].first && arr[num + 1].second >= l) {
				vp[num + 1]++;
				b = true;
			}
		}
		if (!b) {
			ot[num]++;
		}
	}
	vector<ll> dpv(n * 2, 0), dpnv(n * 2, 0);
	dpnv[0] = ot[0];
	ll mx = ot[0];
	for (ll i = 1; i < n * 2; i++) {
		if (i % 2 == 0) {
			dpnv[i] = max(max(dpnv[i - 1], dpv[i - 1]) + ot[i], dpnv[i - 1] + vp[i] + ot[i]);
			dpv[i] = max(dpnv[i - 1], dpv[i - 1]);
		} else {
			dpnv[i] = dpv[i - 1] + ot[i];
			dpv[i] = max(dpnv[i - 1], dpv[i - 1]);
		}
		if (mx < dpv[i]) {
			mx = dpv[i];
		}
		if (mx < dpnv[i]) {
			mx = dpnv[i];
		}
	}
	vector<ll> dpv2(n * 2, 0), dpnv2(n * 2, 0);
	dpnv2[0] = ot[0];
	ll mx2 = ot[0];
	for (ll i = 1; i < n * 2; i++) {
		if (i % 2 == 0) {
			dpnv2[i] = max(max(dpnv2[i - 1], dpv2[i - 1]) + ot[i], dpnv2[i - 1] + vp[i]);
			dpv2[i] = max(dpnv2[i - 1], dpv2[i - 1]);
		} else {
			dpnv2[i] = dpv2[i - 1] + ot[i];
			dpv2[i] = max(dpnv2[i - 1], dpv2[i - 1]);
		}
		if (mx2 < dpv2[i]) {
			mx2 = dpv2[i];
		}
		if (mx2 < dpnv2[i]) {
			mx2 = dpnv2[i];
		}
	}
	cout << mx + ans;
}
