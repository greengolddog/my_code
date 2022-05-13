#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct Sparse_Table {
	vector<vector<ll>> bin;
	vector<ll> pow, t;
	ll max_pow = 30, size;
	Sparse_Table(vector<ll> arr) {
		size = arr.size();
		pow.push_back(1);
		for (ll i = 1; i < max_pow; i++) {
			pow.push_back(pow.back() * 2);
		}
		t.resize(size + 1, 0);
		for (ll i = 1; i <= size; i++) {
			if (pow[t[i - 1] + 1] == i) {
				t[i] = t[i - 1] + 1;
			} else {
				t[i] = t[i - 1];
			}
		}
		bin.resize(max_pow, vector<ll>(size, 0));
		for (ll i = 0; i < size; i++) {
			bin[0][i] = arr[i];
		}
		for (ll s = 1; s < max_pow; s++) {
			for (ll i = 0; i <= (size-pow[s]); i++) {
				bin[s][i] = min(bin[s - 1][i], bin[s - 1][i + pow[s - 1]]);
			}
		}
	}
	ll get(ll l, ll r) {
		return min(bin[t[r - l]][l], bin[t[r - l]][r - pow[t[r - l]]]);
	}
};

ll next_arr(ll now) {
	return (23 * now + 21563) % 16714589;
}

ll next_u(ll u, ll r, ll i, ll n) {
	return ((17 * u + 751 + r + 2 * i) % n) + 1;
}

ll next_v(ll v, ll r, ll i, ll n) {
	return ((13 * v + 593 + r + 5 * i) % n) + 1;
}

int main() {
	freopen("sparse.in", "r", stdin);
	freopen("sparse.out", "w", stdout);
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<ll> arr(n, 0);
	cin >> arr[0];
	for (ll i = 1; i < n; i++) {
		arr[i] = next_arr(arr[i - 1]);
	}
	Sparse_Table s(arr);
	ll u, v, r;
	cin >> u >> v;
	r = s.get(min(u, v)-1, max(u, v));
	for (ll i = 1; i < m; i++) {
		u = next_u(u, r, i, n);
		v = next_v(v, r, i, n);
		r = s.get(min(u, v) - 1, max(u, v));
	}
	cout << u << ' ' << v << ' ' << r;
}
