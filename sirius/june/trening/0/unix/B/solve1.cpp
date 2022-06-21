#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007;
const db PI = acos(-1);

mt19937 rnd32(time(0));
mt19937_64 rnd64(time(0));

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

template<typename T>
T square(T a) {
	return a * a;
}

template<>
struct std::hash<pair<ll, ll>> {
	ll operator() (pair<ll, ll> p) {
		return ((__int128)p.first * MOD + p.second) % INF64;
	}
};

void dfs(ll v, vector<ll>& h, vector<ll>& tin, vector<ll>& tout, ll& t, ll nh, vector<vector<ll>>& arr) {
	tin[v] = t;
	t++;
	h[v] = nh;
	for (auto i : arr[v]) {
		dfs(i, h, tin, tout, t, nh + 1, arr);
	}
	tout[v] = t;
	t++;
}

void solve() {
	ll n, q;
	cin >> n >> q;
	vector<pair<ll, ll>> arr(n);
	set<pair<ll, ll>> ss;
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
		ss.insert(arr[i]);
	}
	vector<vector<ll>> gf(n);
	vector<bool> is_root(n, true);
	set<pair<ll, pair<ll, ll>>> s;
	for (ll i = 0; i < n; i++) {
		s.insert(make_pair(arr[i].second, make_pair(i, arr[i].first)));
	}
	for (ll i = 0; i < n; i++) {
		auto it = s.lower_bound(make_pair(arr[i].first, make_pair(0, 0)));
		while (it != s.end() && it->first <= arr[i].second) {
			if (it->second.first != i) {
				if (it->first != arr[i].second || it->second.second > arr[i].first) {
					gf[i].push_back(it->second.first);
					is_root[it->second.first] = false;
				}
			}
			it++;
		}
	}
	vector<ll> h(n), tin(n), tout(n);
	ll t = 0;
	for (ll i = 0; i < n; i++) {
		if (is_root[i]) {
			dfs(i, h, tin, tout, t, 0, gf);
		}
	}
	for (ll i = 0; i < q; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		if (tin[a] > tin[b] && tout[b] > tout[a]) {
			cout << h[a] - h[b] << '\n';
		} else {
			cout << "impossible" << '\n';
		}
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	//cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}
