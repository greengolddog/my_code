#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		ll n;
		cin >> n;
		vector<pair<ll, ll>> arr(n, {0, 0});
		for (ll i = 0; i < n; i++) {
			cin >> arr[i].first;
			arr[i].second = i;
		}
		vector<pair<ll, ll>> narr = arr;
		sort(narr.begin(), narr.end());
		vector<pair<ll, ll>> col(1, {0, 0});
		for (ll i = 0; i < n; i++) {
			auto[num, j] = narr[i];
			if (num != col.back().first) {
				col.push_back(make_pair(num, 0));
			}
			col.back().second += abs(j-i);
		}
		bool f = false;
		for (auto[_, c] : col) {
			if (c % 2 == 1) {
				cout << "NO\n";
				f = true;
				break;
			}
		}
		if (!f) {
			cout << "YES\n";
		}
	}
}
