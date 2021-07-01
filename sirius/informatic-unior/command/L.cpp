#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	ll n, k;
	cin >> n >> k;
	vector<pair<ll, pair<ll, ll>>> arr(n, {0, {0, 0}});
	vector<ll> ans(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].first;
		arr[i].second.second = i;
	}
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].second.first;
		ans[i] = arr[i].second.first;
	}
	sort(arr.begin(), arr.end());
	multiset<ll> s;
	ll now = 0;
	for (auto&[_, ci] : arr) {
		auto[c, i] = ci;
		ans[i] += now;
		if (s.size() >= k) {
			if ((s.size() > 0) && (c > *s.begin())) {
				now -= *s.begin();
				s.erase(s.begin());
				s.insert(c);
				now += c;
			}
		} else {
			s.insert(c);
			now += c;
		}
	}
	for (auto i : ans) {
		cout << i << ' ';
	}
}
