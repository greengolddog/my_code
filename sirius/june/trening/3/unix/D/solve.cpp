#pragma GCC optimize("Ofast")
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

struct bit {
	vector<ll> arr;
	ll n;
	bit(ll n): n(n) {
		arr.resize(n + 1, 0);
	}
	ll get(ll x) {
		x++;
		ll ans = 0;
		for (; x > 0; x -= x & -x) {
			ans += arr[x];
		}
		return ans;
	}
	void change(ll x) {
		x++;
		for (; x <= n; x += x & -x) {
			arr[x]++;
		}
	}
};

void solve() {
	ll n, e;
	cin >> n >> e;
	vector<ll> a(n), arr;
	ll c = 1;
	vector<pair<ll, ll>> v;
	bit b(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		v.push_back(make_pair(a[i], i));
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (auto[a, bb] : v) {
		arr.push_back(b.get(bb));
		b.change(bb);
	}
	ll ans = 0, me = 0, ms = 0;
	priority_queue<tuple<ll, ll, ll>> q;
	for (ll j = 0; j < n; j++) {
		ll i = arr[j];
		if (i != 0) {
			ans++;
			ms += i;
			me += i * i;
			ll x = i / 2;
			ll y = i - x;
			if (i != 1) {
				q.push(make_tuple(i * i - x * x - y * y, j, 1));
			}
		}
	}
	if (ms > e) {
		cout << -1 << '\n';
		return;
	}
	while (!q.empty() && me > e) {
		auto[c, i, nd] = q.top();
		q.pop();
		nd++;
		ans++;
		ll j = arr[i];
		me -= c;
		ll ox = j / nd, ost = j % nd;
		ll cox = nd - ost, cob = ost;
		if (nd == j) {
			continue;
		}
		ll x = j / (nd + 1), st = j % (nd + 1);
		ll cx = nd + 1 - st, cb = st;
		q.push(make_tuple(ox * ox * cox + (ox + 1) * (ox + 1) * cob - x * x * cx - (x + 1) * (x + 1) * cb, i, nd));
	}
	if (me > e) {
		cout << -1 << '\n';
		return;
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
