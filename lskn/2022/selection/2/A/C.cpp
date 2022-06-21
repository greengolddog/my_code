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

typedef int_fast32_t ll;
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

void solve() {
	ll n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<ll, ll>>> arr(n);
	for (ll i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		arr[a].push_back(make_pair(b, c));
		arr[b].push_back(make_pair(a, c));
	}
	vector<vector<vector<ll>>> d(k, vector<vector<ll>>(n));
	ll cd, T;
	cin >> cd >> T;
	for (ll i = 0; i < cd; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		d[a][b].push_back(c);
	}
	ll s1, s2;
	cin >> s1 >> s2;
	s1--;
	s2--;
	priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> md1, md2;
	md1.push(make_pair(0, make_pair(s1, 0)));
	md2.push(make_pair(0, make_pair(s2, 0)));
	vector<vector<ll>> dist1(n, vector<ll>((1 << k), INF32)), dist2(n, vector<ll>((1 << k), INF32));
	dist1[s1][0] = 0;
	dist2[s2][0] = 0;
	while (!md1.empty()) {
		auto[y, x] = md1.top();
		ll i = x.first, j = x.second;
		md1.pop();
		if (y > dist1[i][j]) {
			continue;
		}
		for (auto[v, c] : arr[i]) {
			if (assign_min(dist1[v][j], dist1[i][j] + c)) {
				md1.push(make_pair(dist1[v][j], make_pair(v, j)));
			}
		}
		for (ll nk = 0; nk < k; nk++) {
			for (auto l : d[nk][i]) {
				if (l >= dist1[i][j] && !((j >> nk) & 1)) {
					j += (1 << nk);
					if (assign_min(dist1[i][j], l)) {
						md1.push(make_pair(dist1[i][j], make_pair(i, j)));
					}
					j -= (1 << nk);
				}
			}
		}
	}
	while (!md2.empty()) {
		auto[y, x] = md2.top();
		ll i = x.first, j = x.second;
		md2.pop();
		if (y > dist2[i][j]) {
			continue;
		}
		for (auto[v, c] : arr[i]) {
			if (assign_min(dist2[v][j], dist2[i][j] + c)) {
				md2.push(make_pair(dist2[v][j], make_pair(v, j)));
			}
		}
		for (ll nk = 0; nk < k; nk++) {
			for (auto l : d[nk][i]) {
				if (l >= dist2[i][j] && !((j >> nk) & 1)) {
					j += (1 << nk);
					if (assign_min(dist2[i][j], l)) {
						md2.push(make_pair(dist2[i][j], make_pair(i, j)));
					}
					j -= (1 << nk);
				}
			}
		}
	}
	ll ans = INF32;
	for (ll i = 0; i < (1 << k); i++) {
		ll i1 = 0, i2 = 0;
		for (ll j = 0; j < k; j++) {
			if ((i >> j) & 1) {
				i1 += (1 << j);
			} else {
				i2 += (1 << j);
			}
		}
		ll na1 = INF32, na2 = INF32;
		for (ll j = 0; j < n; j++) {
			assign_min(na1, dist1[j][i1]);
		}
		for (ll j = 0; j < n; j++) {
			assign_min(na2, dist2[j][i2]);
		}
		assign_min(ans, max(na1, na2));
	}
	cout << (ans == INF32 ? -1 : ans) << '\n';
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}
