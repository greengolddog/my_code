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

void dfs(ll v, ll p, vector<ll>& pv, vector<ll>& md, vector<vector<ll>>& arr) {
	multiset<ll> ms;
	for (auto i : arr[v]) {
		if (i != p) {
			dfs(i, v, pv, md, arr);
			ms.insert(pv[i] + 1);
			assign_max(md[v], md[i]);
			assign_max(md[v], pv[i] + 1);
			assign_max(pv[v], pv[i] + 1);
		}
	}
	if (ms.size() > 1) {
		ll x = *ms.rbegin();
		ms.erase(ms.find(x));
		assign_max(md[v], x + *ms.rbegin());
	}
}

pair<ll, pair<ll, ll>> dfs2(ll v, ll p, ll uv, ll ud, vector<ll>& pv, vector<ll>& md, vector<vector<ll>>& arr, vector<ll>& uva, vector<ll>& uda) {
	uva[v] = uv + 1;
	uda[v] = ud;
	multiset<ll> mmd, mpv;
	mmd.insert(ud);
	mpv.insert(uv + 1);
	for (auto i : arr[v]) {
		if (i != p) {
			mmd.insert(md[i]);
			mpv.insert(pv[i] + 1);
		}
	}
	pair<ll, pair<ll, ll>> ans = make_pair(INF32, make_pair(0, 0));
	for (auto i : arr[v]) {
		if (i != p) {
			mpv.erase(mpv.find(pv[i] + 1));
			mmd.erase(mmd.find(md[i]));
			ll x = *mpv.rbegin();
			mpv.erase(mpv.find(x));
			ll y = x;
			if (!mpv.empty()) {
				y += *mpv.rbegin();
			}
			assign_max(y, *mmd.rbegin());
			mpv.insert(x);
			assign_min(ans, dfs2(i, v, x, y, pv, md, arr, uva, uda));
			mpv.insert(pv[i] + 1);
			mmd.insert(md[i]);
			assign_min(ans, make_pair(max((y + 1) / 2 + 1, (md[i] + 1) / 2), make_pair(i, v)));
			assign_min(ans, make_pair(max((y + 1) / 2, (md[i] + 1) / 2 + 1), make_pair(v, i)));
		}
	}
	return ans;
}

ll dfs3(ll v, ll p, vector<vector<ll>>& arr, ll x, vector<ll>& pv, vector<ll>& md, vector<ll>& uva, vector<ll>& uda) {
	bool b = uva[v] <= x;
	for (auto i : arr[v]) {
		if (i != p) {
			if (pv[i] + 1 > x) {
				b = false;
			}
			ll y = dfs3(i, v, arr, x, pv, md, uva, uda);
		       	if (y != -1) {
				return y;
			}
		}
	}
	if (b) {
		return v;
	}
	return -1;
}

ll solve(ll n, vector<vector<ll>> arr) {
	vector<ll> pv(n, 0), md(n, 0), uva(n), uda(n);
	dfs(0, 0, pv, md, arr);
	auto[a, fs] = dfs2(0, 0, -1, 0, pv, md, arr, uva, uda);
	auto[f, s] = fs;
	vector<ll> nf, ns;
	for (auto i : arr[f]) {
		if (i != s) {
			nf.push_back(i);
		}
	}
	arr[f] = nf;
	for (auto i : arr[s]) {
		if (i != f) {
			ns.push_back(i);
		}
	}
	arr[s] = ns;
	pv.clear();
	pv.resize(n, 0);
	md.clear();
	md.resize(n, 0);
	uva.clear();
	uva.resize(n, 0);
	uda.clear();
	uda.resize(n, 0);
	dfs(f, f, pv, md, arr);
	dfs(s, s, pv, md, arr);
	dfs2(f, f, -1, 0, pv, md, arr, uva, uda);
	dfs2(s, s, -1, 0, pv, md, arr, uva, uda);
	ll ff = dfs3(f, f, arr, a, pv, md, uva, uda);
	ll ss = dfs3(s, s, arr, a - 1, pv, md, uva, uda);
	cout << ff + 1 << ' ' << ss + 1 << '\n' << ff + 1 << '\n';
	return a;
}

ll stupid(ll n, vector<vector<ll>>& arr) {
	ll ans = INF32, f = 0, s = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			arr[i].push_back(j);
			arr[j].push_back(i);
			vector<ll> dist(n, INF32);
			dist[i] = 0;
			queue<ll> q;
			q.push(i);
			while (!q.empty()) {
				ll x = q.front();
				q.pop();
				for (auto v : arr[x]) {
					if (assign_min(dist[v], dist[x] + 1)) {
						q.push(v);
					}
				}
			}
			ll md = 0;
			for (auto i : dist) {
				assign_max(md, i);
			}
			if (assign_min(ans, md)) {
				f = i;
				s = j;
			}
			arr[i].pop_back();
			arr[j].pop_back();
		}
	}
	cout << f + 1 << ' ' << s + 1 << '\n' << f + 1 << '\n';
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bool b = true;
	if (b) {
		ll n;
		cin >> n;
		vector<vector<ll>> arr(n);
		for (ll i = 1; i < n; i++) {
			ll a, b;
			cin >> a >> b;
			a--;
			b--;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		solve(n, arr);
	} else {
		ll n;
		cin >> n;
		vector<vector<ll>> arr(n);
		for (ll i = 1; i < n; i++) {
			ll a, b;
			cin >> a >> b;
			a--;
			b--;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		if (stupid(n, arr) != solve(n, arr)) {
			cout << "NO";
			return 1;
		} else {
			cout << "YES";
		}
	}
}
