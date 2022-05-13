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

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
	return a.first == b.first;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	string s;
	cin >> s;
	ll n = s.size();
	ll k;
	cin >> k;
	k--;
	vector<ll> arr;
	for (auto i : s) {
		arr.push_back(i);
	}
	for (ll x = 1; x < n; x *= 2) {
		vector<pair<pair<ll, ll>, ll>> sa(n);
		for (ll i = 0; i < n; i++) {
			sa[i] = make_pair(make_pair(arr[i], arr[(i + x) % n]), i);
		}
		sort(sa.begin(), sa.end());
		ll now = 0;
		arr[sa[0].second] = now;
		for (ll i = 1; i < n; i++) {
			if (sa[i].first != sa[i - 1].first) {
				now++;
			}
			arr[sa[i].second] = now;
		}
	}
	deque<pair<ll, ll>> ans(n);
	for (ll i = 0; i < n; i++) {
		ans[i] = {arr[i], i};
	}
	sort(ans.begin(), ans.end());
	ans.resize(unique(ans.begin(), ans.end(), cmp) - ans.begin());
	if (k >= ans.size()) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	ll a = ans[k].second;
	for (ll i = a; i < n; i++) {
		cout << s[i];
	}
	for (ll i = 0; i < a; i++) {
		cout << s[i];
	}
}
