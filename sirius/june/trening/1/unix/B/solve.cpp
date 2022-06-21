#pragma GCC target("avx, avx2, sse, sse2, ssse")
#include<bits/stdc++.h>

typedef int ll;

using namespace std;

mt19937 rnd32(time(0));
mt19937_64 rnd64(time(0));

const ll INF32 = 2'000'000'000, INF64 = 9'000'000'000'000'000'000, LOGN = 19;
ll colp = 0;

template<typename T>
bool assign_max(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_min(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

struct LCA {
	vector<vector<ll>> binup;
	vector<ll> h;
	ll root = 0;
	LCA(vector<vector<ll>> arr) {
		h.resize(arr.size());
		binup.resize(arr.size(), vector<ll>(LOGN));
		h[0] = 0;
		dfs(0, 0, arr);
	}
	void dfs(ll v, ll p, vector<vector<ll>>& arr) {
		h[v] = h[p] + 1;
		binup[v][0] = p;
		for (ll i = 1; i < LOGN; i++) {
			binup[v][i] = binup[binup[v][i - 1]][i - 1];
		}
		for (auto i : arr[v]) {
			if (i != p) {
				dfs(i, v, arr);
			}
		}
	}
	ll get_LA(ll v, ll x) {
		for (ll i = LOGN - 1; i >= 0; i--) {
			if (x >= (1 << i)) {
				x -= 1 << i;
				v = binup[v][i];
			}
		}
		return v;
	}
	tuple<ll, ll, ll, ll> get_LCA(ll a, ll b) {
		if (h[a] < h[b]) {
			swap(a, b);
		}
		ll oa = a, ob = b;
		if (h[a] != h[b]) {
			a = get_LA(a, h[a] - h[b] - 1);
			if (binup[a][0] == b) {
				return make_tuple(oa, ob, a, -1);
			}
			a = binup[a][0];
		}
		for (ll i = LOGN - 1; i >= 0; i--) {
			if (binup[a][i] != binup[b][i]) {
				a = binup[a][i];
				b = binup[b][i];
			}
		}
		return make_tuple(oa, ob, a, b);
	}
	ll get_h(ll v) {
		return h[v];
	}
};

void dfs(ll v, ll p, vector<vector<ll>>& arr, vector<vector<ll>>& on, vector<vector<ll>>& en, vector<vector<ll>>& g, vector<set<ll>*>& open) {
	for (auto i : arr[v]) {
		if (i != p) {
			dfs(i, v, arr, on, en, g, open);
		}
	}
	vector<pair<ll, ll>> rs;
	for (auto i : arr[v]) {
		if (i != p) {
			rs.emplace_back(open[i]->size(), i);
		}
	}
	sort(rs.begin(), rs.end());
	if (rs.size() > 0) {
		open[v] = open[rs.back().second];
		rs.pop_back();
	}
	for (auto[_, i] : rs) {
		for (auto j : *open[i]) {
			open[v]->insert(j);
		}
		open[i]->clear();
	}
	for (auto i : on[v]) {
		open[v]->insert(i);
	}
	if (open[v]->size() > 0) {
		g[*open[v]->begin()].push_back(v);
	}
	for (auto i : en[v]) {
		open[v]->erase(i);
	}
}

void solve() {
	ll n, e;
	cin >> n >> e;
	vector<pair<ll, ll>> a(e);
	map<pair<ll, ll>, ll> m;
	for (ll i = 0; i < e; i++) {
		cin >> a[i].first >> a[i].second;
		a[i].first--;
		a[i].second--;
		m[make_pair(a[i].first, a[i].second)] = i;
		m[make_pair(a[i].second, a[i].first)] = i;
	}
	vector<vector<ll>> on(n), en(n);
	set<ll> s;
	vector<vector<ll>> arr(n);
	for (ll i = 1; i < n; i++) {
		ll x;
		cin >> x;
		x--;
		arr[a[x].first].push_back(a[x].second);
		arr[a[x].second].push_back(a[x].first);
		s.insert(x);
	}
	LCA l(arr);
	vector<ll> ans(e, -1);
	vector<pair<bool, ll>> qs;
	ll nc = 0;
	for (ll i = 0; i < e; i++) {
		if (s.find(i) == s.end()) {
			auto[oa, ob, na, nb] = l.get_LCA(a[i].first, a[i].second);
			on[oa].push_back(nc);
			en[na].push_back(nc);
			if (nb != -1) {
				on[ob].push_back(nc);
				en[nb].push_back(nc);
			}
			qs.emplace_back(true, nc);
			nc++;
		}
		qs.emplace_back(false, i);
	}
	vector<vector<ll>> g(nc);
	vector<set<ll>*> open;
	for (ll i = 0; i < n; i++) {
		open.push_back(new set<ll>);
	}
	dfs(0, 0, arr, on, en, g, open);
	ll last = 1;
	for (auto[b, i] : qs) {
		if (b) {
			vector<ll> sm;
			for (auto i : g[i]) {
				sm.push_back(m[make_pair(i, l.binup[i][0])]);
			}
			sort(sm.begin(), sm.end());
			for (auto i : sm) {
				if (ans[i] == -1) {
					ans[i] = last;
					last++;
				}
			}
		} else {
			if (ans[i] == -1) {
				ans[i] = last;
				last++;
			}
		}
	}
	for (auto i : ans) {
		cout << i << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
