#include <bits/stdc++.h>
typedef long long ll;

const ll INF = 9'000'000'000'000'000'000;

template<typename T>
bool assign_max(T& a, T b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_min(T& a, T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

using namespace std;

void solve() {
	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	set<pair<ll, pair<ll, ll>>> s;
	s.insert(make_pair(n, make_pair(0, n)));
	vector<ll> ans(n, 0);
	ll a = 0;
	for (ll i = 0; i < n; i++) {
		auto[d, lr] = *s.rbegin();
		s.erase(s.find(make_pair(d, lr)));
		ll mid = (lr.first + lr.second) / 2;
		ans[mid] = arr[i];
		a += (mid - lr.first + 1) * (lr.second - mid) * arr[i];
		if (lr.second - lr.first > 1) {
			if (mid != lr.first) {
				s.insert(make_pair(mid - lr.first, make_pair(lr.first, mid)));
			}
			mid++;
			if (mid != lr.second) {
				s.insert(make_pair(lr.second - mid, make_pair(mid, lr.second)));
			}
		}
	}
	cout << a << '\n';
	for (auto i : ans) {
		cout << i << ' ';
	}
	cout << '\n';
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		solve();
	}
}
