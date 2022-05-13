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
	ll n, m;
	cin >> n >> m;
	deque<ll> s(n), arr(n);
	for (ll i = 0; i < n; i++) {
		cin >> s[i];
		arr[i] = s[i];
	}
	s.push_back(-1);
	arr.push_back(-1);
	n++;
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
	ll a = n, d = n, st = 0;
	for (ll i = 0; i < n; i++) {
		ll nst = 0;
		for (ll j = 0; j < (n - 1); j++) {
			if (assign_max(a, i * (j - nst + 1))) {
				d = i;
				st = nst;
			}
			if (lcp[j] < i) {
				nst = j + 1;
			}
		}
	}
	cout << a << '\n' << d << '\n';
	for (ll i = st; i < (st + d); i++) {
		cout << s[i] << ' ';
	}
}
