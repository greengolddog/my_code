#pragma GCC opptimize("Ofast")
#include <bits/stdc++.h>
typedef int_fast32_t ll;

const ll INF = 1'000'000'000;

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

ll sum(ll a, ll b, ll m) {
	if (a + b >= m) {
		return a + b - m;
	}
	return a + b;
}

ll sub(ll a, ll b, ll m) {
	if (b > a) {
		return a - b + m;
	}
	return a - b;
}

ll mul(long long a, long long b, ll m) {
	return a * b % m;
}

struct hash_string {
	vector<long long> h, pow;
	ll mod, p;
	hash_string(string s, ll mod = 1'000'000'007, ll p = 31): mod(mod), p(p) {
		pow.push_back(1);
		h.push_back(0);
		for (auto i : s) {
			pow.push_back(mul(pow.back(), p, mod));
			h.push_back(sum(mul(h.back(), p, mod), i - 'a' + 1, mod));
		}
	}
	ll get(ll l, ll r) {
		return sub(h[r], mul(h[l], pow[r - l], mod), mod);
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<string> arr(n);
	vector<hash_string> hs1;
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		hs1.push_back(hash_string(arr[i]));
	}
	vector<vector<ll>> g(n);
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<ll> dist(n, INF);
	dist[0] = arr[0].size();
	vector<bool> used(n, false);
	vector<ll> nums;
	for (ll i = 0; i < n; i++) {
		ll x = 0, nl = INF;
		for (ll j = 0; j < n; j++) {
			if (used[j]) {
				continue;
			}
			if (assign_min(nl, dist[j])) {
				x = j;
			}
		}
		used[x] = true;
		nums.push_back(x);
		for (auto j : g[x]) {
			assign_min(dist[j], dist[x] + (ll)arr[j].size());
		}
	}
	vector<vector<ll>> ans(n), pref(n);
	vector<vector<long long>> prefh(n);
	vector<ll> pred(n, -1);
	pred[0] = 0;
	prefh[0].push_back(0);
	pref[0].push_back(0);
	for (auto i : nums) {
		ans[i] = ans[pred[i]];
		ans[i].push_back(i);
		prefh[i] = prefh[pred[i]];
		prefh[i].push_back(sum(mul(prefh[i].back(), hs1[i].pow.back(), hs1[i].mod), hs1[i].h.back(), hs1[i].mod));
		pref[i] = pref[pred[i]];
		pref[i].push_back(pref[i].back() + arr[i].size());
		for (auto k : g[i]) {
			if (pred[k] == -1) {
				if (dist[k] == dist[i] + arr[k].size()) {
					pred[k] = i;
				}
			} else {
				if (dist[k] == dist[i] + arr[k].size()) {
					ll j = pred[k];
					ll l = 0, r = dist[j];
					while (r - l > 1) {
						ll mid = (l + r) / 2;
						ll x = lower_bound(pref[i].begin(), pref[i].end(), mid) - pref[i].begin();
						ll y = lower_bound(pref[j].begin(), pref[j].end(), mid) - pref[j].begin();
						x--;
						y--;
						if (sum(mul(prefh[i][x], hs1[ans[i][x]].pow[mid - pref[i][x]], hs1[ans[i][x]].mod), hs1[ans[i][x]].get(0, mid - pref[i][x]), hs1[ans[i][x]].mod) == sum(mul(prefh[j][y], hs1[ans[j][y]].pow[mid - pref[j][y]], hs1[ans[j][y]].mod), hs1[ans[j][y]].get(0, mid - pref[j][y]), hs1[ans[j][y]].mod)) {
							l = mid;
						} else {
							r = mid;
						}
					}
					l++;
					ll x = lower_bound(pref[i].begin(), pref[i].end(), l) - pref[i].begin();
					ll y = lower_bound(pref[j].begin(), pref[j].end(), l) - pref[j].begin();
					x--;
					y--;
					if (arr[ans[i][x]][l - pref[i][x] - 1] < arr[ans[j][y]][l - pref[j][y] - 1]) {
						pred[k] = i;
					}
				}
			}
		}
	}
	for (auto i : ans.back()) {
		cout << arr[i];
	}
}
