#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

int main() {
	ll n, mins, minz, ns;
	cin >> n;
	map<ll,ll> ma;
	vector<pair<ll,ll>> arr(n, {0,0});
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].first;
		ma[arr[i].first] = 0;
	}
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].second;
	}
	for (ll i = 0; i < n; i++) {
		ma[arr[i].first] += arr[i].second;
	}
	mins = -1;
	minz = 0;
	for (auto i : ma) {
		ns = 0;
		for (auto j : ma) {
			ns += abs(i.first-j.first)*j.second;
		}
		if (mins == -1) {
			mins = ns;
			minz = i.first;
		} else {
			if (ns < mins) {
				mins = ns;
				minz = i.first;
			} elif (ns == mins) {
				minz = min(minz,i.first);
			}
		}
	}
	cout << minz << ' ' << mins;
}