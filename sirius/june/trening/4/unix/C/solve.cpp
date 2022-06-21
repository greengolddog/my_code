#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll INF32 = 2'000'000'000, INF64 = 9'000'000'000'000'000'000;

mt19937 rnd32(time(0));
mt19937_64 rnd64(time(0));

template<typename T>
bool assign_min(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_max(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

void solve(vector<ll>& arr) {
	set<pair<ll, ll>> s;
	for (ll i = 0; i < arr.size(); i++) {
		s.insert(make_pair(arr[i], i));
	}
	vector<ll> sb(arr.size(), -1);
	ll co = arr.size();
	while (s.size() > 1) {
		auto[a, b] = *s.rbegin();
		auto[c, d] = *s.begin();
		s.erase(s.find(make_pair(a, b)));
		s.erase(s.find(make_pair(c, d)));
		if (sb[d] != -1) {
			cout << sb[d] << '\n';
			return;
		}
		sb[b] = co;
		co--;
		a -= c;
		s.insert(make_pair(a, b));
	}
	cout << 1 << '\n';
}

void solve() {
	ll Q;
	cin >> Q;
	ll n;
	cin >> n;
	vector<ll> arr(n);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	solve(arr);
	for (ll j = 1; j < Q; j++) {
		ll k;
		cin >> k;
		for (ll i = 0; i < k; i++) {
			ll a, b;
			cin >> a >> b;
			a--;
			arr[a] = b;
		}
		solve(arr);
	}
}

int main() {
	freopen("003", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
