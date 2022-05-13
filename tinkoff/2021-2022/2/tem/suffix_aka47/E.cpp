#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("vpt")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize(3)
#pragma GCC optimize("O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>

using namespace std;

typedef int ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007;
ll COLC = 11;
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

struct node {
	map<ll, ll> g;
	ll p, suf;
	node() {
		p = -1;
		suf = -1;
	}
	ll go(ll x) {
		if (g.find(x) == g.end()) {
			return -1;
		}
		return g[x];
	}
};

struct suffix_aka47 {
	vector<node> arr;
	vector<bool> t, used;
	vector<ll> dist, col;
	ll root;
	suffix_aka47() {
		root = 0;
		arr.resize(1, node());
	}
	suffix_aka47(vector<ll> aa) {
		root = 0;
		arr.reserve(aa.size() * 2);
		arr.resize(1, node());
		for (auto i : aa) {
			add(i);
		}
		t.resize(arr.size());
		ll a = root;
		for (; a >= 0; a = arr[a].suf) {
			t[a] = true;
		}
		dist.resize(arr.size(), 0);
		for (ll i = 1; i < arr.size(); i++) {
			dist[i] = dist[arr[i].p] + 1;
		}
		used.resize(arr.size(), false);
		col.resize(arr.size(), 0);
		dfs(0);
	}
	void dfs(ll v) {
		used[v] = true;
		col[v] = t[v];
		for (auto[_, i] : arr[v].g) {
			if (!used[i]) {
				dfs(i);
			}
			col[v] += col[i];
		}
	}
	void add(ll x) {
		ll a = root;
		ll b = arr.size();
		arr.push_back(node());
		arr[b].p = a;
		arr[b].suf = 0;
		root = b;
		for (; a >= 0; a = arr[a].suf) {
			if (arr[a].go(x) == -1) {
				arr[a].g[x] = b;
				continue;
			}
			ll c = arr[a].g[x];
			if (arr[c].p == a) {
				arr[b].suf = c;
				break;
			}
			ll d = arr.size();
			arr.push_back(node());
			arr[d].suf = arr[c].suf;
			arr[c].suf = d;
			arr[d].p = a;
			arr[b].suf = d;
			for (auto[i, j] : arr[c].g) {
				arr[d].g[i] = j;
			}
			for (; a >= 0 && arr[a].go(x) == c; a = arr[a].suf) {
				arr[a].g[x] = d;
			}
			break;
		}
	}
	void way(ll v) {
		if (v == 0) {
			return;
		}
		way(arr[v].p);
		for (auto[i, j] : arr[arr[v].p].g) {
			if (j == v) {
				cout << i + 1 << ' ';
			}
		}
	}
};

void solve() {
	ll n, m;
	cin >> n >> COLC;
	COLC--;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i]--;
	}
	suffix_aka47 sa(arr);
	long long mx = 0;
	ll ans = 0;
	for (ll i = 0; i < sa.arr.size(); i++) {
		if (assign_max(mx, (long long)sa.dist[i] * sa.col[i])) {
			ans = i;
		}
	}
	cout << mx << '\n' << sa.dist[ans] << '\n';
	sa.way(ans);
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
