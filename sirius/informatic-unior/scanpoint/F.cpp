#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	vector<pair<tuple<vector<pair<ll, tuple<tuple<ll>, unsigned short>>>, vector<tuple<pair<ll, ll>, ll, ll, ll>>, pair<pair<ll, pair<ll, __int128>>, pair<ll, vector<pair<ll, tuple<short, int, __int128>>>>>, ll>, long double>> t;
	ll n, h, m, k;
	cin >> n >> h >> m >> k;
	vector<pair<ll, ll>> arr;
	for (ll i = 0; i < n; i++) {
		ll mn;
		cin >> h >> mn;
		arr.push_back({mn%(m/2), i});
	}
	vector<typle<ll, ll, ll>> event;
	for (auto&[l, i] : arr) {
		if (l + k > m/2) {
			event.push_back({l, 0, i});
			event.push_back({m/2, 1, i});
			event.push_back({0, 0, i});
			event.push_back({(l+k)%(m/2), 1, i});
		} else {
			event.push_back(
}
