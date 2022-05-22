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

void count(vector<ll>& dist, vector<vector<ll>>& arr, ll c) {
	set<pair<ll, ll>> d;
	for (ll i = 0; i < dist.size(); i++) {
		d.insert(make_pair(dist[i], i));
	}
	while (!d.empty()) {
		ll x = d.begin()->second;
		d.erase(d.begin());
		for (auto i : arr[x]) {
			ll old = dist[i];
			if (assign_min(dist[i], dist[x] + c)) {
				d.erase(make_pair(old, i));
				d.insert(make_pair(dist[i], i));
			}
		}
	}
}

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> arr(n), aarr(n);
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr[a].push_back(b);
		aarr[a].push_back(b);
		aarr[b].push_back(a);
	}
	vector<ll> dist(n, INF64);
	dist[0] = 0;
	count(dist, aarr, 1);
	count(dist, arr, 0);
	count(dist, aarr, 1);
	cout << (dist.back() == INF64 ? -1 : dist.back());
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
