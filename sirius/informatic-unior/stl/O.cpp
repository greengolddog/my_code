#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	ll mini = 1000000000000;
	vector<pair<ll, ll>> arr(n, {0, 0});
	for (ll i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		arr[i] = {a, b};
	}
	set<pair<char, ll>> s;
	sort(arr.begin(), arr.end());
	for (ll i = 1; i < n; i++) {
		if (arr[i].first != arr[i-1].first) {
			s.insert({'x', arr[i].first});
		} else {
			if (arr[i].second != arr[i-1].second) {
				s.insert({'y', arr[i].second});
			}
		}
	}
	cout << s.size() << '\n';
	for (auto i : s) {
		cout << i.first << ' ' << i.second << '\n';
	}
}
