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
	s += '#';
	ll n = s.size();
	ll c;
	cin >> c;
	deque<ll> arr;
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
	n--;
	arr.pop_back();
	vector<pair<ll, ll>> ts(n);
	for (ll i = 0; i < n; i++) {
		arr[i]--;
		ts[i] = {arr[i], i};
	}
	sort(ts.begin(), ts.end());
	vector<ll> suf;
	for (auto[_, i] : ts) {
		suf.push_back(i);
	}
	vector<ll> lcp(n);
	ll k = 0;
	for (ll i = 0; i < n; i++) {
		if (k > 0) {
			k--;
		}
		if (arr[i] == n - 1) {
			k = 0;
		} else {
			ll j = suf[arr[i] + 1];
			while (max(j, i) + k < n && s[j + k] == s[i + k]) {
				k++;
			}
		}
		lcp[arr[i]] = k;
	}
	k = c;
	for (ll i = n - 1; i > 0; i--) {
		lcp[i] = lcp[i - 1];
	}
	lcp[0] = 0;
	ll a = 0;
	for (; a < n && k > (n - suf[a] - lcp[a]); k -= (n - suf[a] - lcp[a]), a++) {}
	if (a == n) {
		a--;
		k = INF;
	}
	for (ll i = suf[a]; i < min(n, suf[a] + k + lcp[a]); i++) {
		cout << s[i];
	}
}
