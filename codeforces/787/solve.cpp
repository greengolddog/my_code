#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>

typedef int_fast64_t ll;

#define print(a) for (auto& _ : a) cout << _ << " ";
#define input(a) for (auto& _ : a) cin >> _;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

//#define int ll

using namespace std;

const ll INF = 4e18, MOD = 1e9 + 7, MOD2 = 998244353, LOG = 30;
const long double EPS = 1e-9, PI = acos(-1);

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

void dfs1(ll v, ll p, vector<vector<ll>>& arr, vector<bool>& be) {
	for (auto i : arr[v]) {
		if (i != p) {
			dfs1(i, v, arr, be);
			be[v] = be[i] || be[v];
		}
	}
}

ll dfs2(ll v, ll p, vector<vector<ll>>& arr, ll y, ll d) {
	if (v == y) {
		return d;
	}
	for (auto i : arr[v]) {
		if (i != p) {
			if (dfs2(i, v, arr, y, d + 1) != -1) {
				return dfs2(i, v, arr, y, d + 1);
			}
		}
	}
	return -1;
}

void solve() {
	ll n, k;
	cin >> n >> k;
	ll x, y;
	cin >> x >> y;
	x--;
	y--;
	vector<bool> be(n, false);
	be[x] = true;
	be[y] = true;
	for (ll i = 0; i < k; i++) {
		ll a;
		cin >> a;
		a--;
		be[a] = true;
	}
	vector<vector<ll>> arr(n);
	for (ll i = 1; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	dfs1(x, x, arr, be);
	vector<vector<ll>> narr(n);
	ll col = 0;
	for (ll i = 0; i < n; i++) {
		if (be[i]) {
			for (auto j : arr[i]) {
				if (be[j]) {
					narr[i].push_back(j);
					col++;
				}
			}
		}
	}
	cout << col - dfs2(x, x, arr, y, 0) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
