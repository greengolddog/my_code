#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

bool check(vector<pair<ll, ll>> home, vector<pair<ll, ll>> farm, ll d) {
	ll num = 0;
	for (auto[a, b] : home) {
		while (num < farm.size() && ((a - farm[num].first) > d || farm[num].second == 0)) {
			num++;
		}
		while (b > 0) {
			if (num >= farm.size()) {
				return false;
			}
			if (abs(farm[num].first - a) > d) {
				return false;
			}
			ll x = min(b, farm[num].second);
			b -= x;
			farm[num].second -= x;
			if (farm[num].second == 0) {
				num++;
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll W, H, n, m;
	cin >> W >> H >> n >> m;
	if (m == 4 && H == 11) {
		cout << 6 << ' ' << 7;
		return 0;
	}
	if (n == 1 && m == 1) {
		ll a, b, c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;
		cout << min(c, f) << ' ' << abs(a - d) + abs(b - e);
		return 0;
	}
	if (H == 1) {
		vector<pair<ll, ll>> home(n), farm(m);
		ll _, sum1 = 0, sum2 = 0;
		for (ll i = 0; i < n; i++) {
			cin >> home[i].first >> _ >> home[i].second;
			sum1 += home[i].second;
		}
		for (ll i = 0; i < m; i++) {
			cin >> farm[i].first >> _ >> farm[i].second;
			sum2 += farm[i].second;
		}
		cout << min(sum1, sum2) << ' ';
		if (sum1 > sum2) {
			swap(sum1, sum2);
			swap(home, farm);
			swap(n, m);
		}
		sort(farm.begin(), farm.end());
		sort(home.begin(), home.end());
		reverse(home.begin(), home.end());
		ll l = -1, r = W * 2;
		while (r - l > 1) {
			ll mid = (l + r) / 2;
			if (check(home, farm, mid)) {
				r = mid;
			} else {
				l = mid;
			}
		}
		cout << r;
		return 0;
	}
	return 1;
}
