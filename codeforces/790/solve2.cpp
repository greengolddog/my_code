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

void dfs(ll v, ll p, vector<vector<ll>>& arr, vector<ll>& colW, vector<ll>& colB) {
	for (auto i : arr[v]) {
		if (i != p) {
			dfs(i, v, arr, colW, colB);
			colW[v] += colW[i];
			colB[v] += colB[i];
		}
	}
}

void solve() {
	ll n;
	cin >> n;
	vector<vector<ll>> arr(n);
	for (ll i = 1; i < n; i++) {
		ll x;
		cin >> x;
		x--;
		arr[x].push_back(i);
		arr[i].push_back(x);
	}
	string s;
	cin >> s;
	vector<ll> colW(n, 0), colB(n, 0);
	for (ll i = 0; i < n; i++) {
		colW[i] += s[i] == 'W';
		colB[i] += s[i] == 'B';
	}
	dfs(0, 0, arr, colW, colB);
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		ans += colW[i] == colB[i];
	}
	cout << ans << '\n';
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
