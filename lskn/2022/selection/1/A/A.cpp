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

void solve() {
	ll n, k;
	cin >> n >> k;
	vector<pair<ll, ll>> all(n + 1, make_pair(0, 0));
	vector<vector<vector<vector<ll>>>> dp(n, vector<vector<vector<ll>>>(k + 1, vector<vector<ll>>(2, vector<ll>(2, -INF64))));
	ll a, b;
	cin >> a >> b;
	all[0] = make_pair(a, b);
	dp[0][0][0][0] = 0;
	if (k != 0) {
		dp[0][1][0][0] = a + b;
		dp[0][1][1][0] = a;
		dp[0][1][0][1] = b;
	}
	if (k > 1) {
		dp[0][2][1][1] = a + b;
	}
	for (ll i = 1; i < n; i++) {
		cin >> a >> b;
		all[i] = make_pair(a, b);
		dp[i][0][0][0] = 0;
		for (ll j = 0; j <= k; j++) {
			dp[i - 1][j][1][0] += a;
		}
		for (ll j = 0; j <= k; j++) {
			dp[i - 1][j][1][1] += a + b;
		}
		for (ll j = 0; j <= k; j++) {
			dp[i - 1][j][0][1] += b;
		}
		for (ll j = 0; j <= k; j++) {
			dp[i][j][0][0] = max({dp[i - 1][j][0][0], dp[i - 1][j][1][0], dp[i - 1][j][0][1], dp[i - 1][j][1][1]});
		}
		for (ll j = 1; j <= k; j++) {
			assign_max(dp[i][j][0][0], dp[i - 1][j - 1][0][0] + a + b);
		}
		for (ll j = 1; j <= k; j++) {
			dp[i][j][1][0] = max({dp[i - 1][j - 1][0][0], dp[i - 1][j - 1][0][1]}) + a;
		}
		for (ll j = 1; j <= k; j++) {
			dp[i][j][0][1] = max({dp[i - 1][j - 1][0][0], dp[i - 1][j - 1][1][0]}) + b;
		}
		for (ll j = 2; j <= k; j++) {
			dp[i][j][1][1] = dp[i - 1][j - 2][0][0] + b + a;
		}
	}
	vector<pair<ll, ll>> ans(n, pair<ll, ll>(0, 0));
	ll nn = n - 1, nk = k, nv1 = 0, nv2 = 0, c1 = 0, c2 = 0, last = 1;
	while (nn != 0) {
		if (nk == 0) {
			break;
		}
		if (nv1 == 1) {
			ans[nn].first = c1;
		}
		if (nv2 == 1) {
			ans[nn].second = c2;
		}
		ll nm = -1, pa = 0, pb = 0;
		for (ll i = 0; i < 2; i++) {
			for (ll j = 0; j < 2; j++) {
				if (i + nv1 != 2 && j + nv2 != 2 && nk - nv1 - nv2 - j - i >= 0) {
					if (dp[nn][nk][nv1][nv2] == dp[nn - 1][nk - nv1 - nv2][i][j] + (all[nn].first + all[nn + 1].first) * nv1 + (all[nn].second + all[nn + 1].second) * nv2) {
						pa = i;
						pb = j;
					}
				}
			}
		}
		if (nv1 == 0 && nv2 == 0) {
			if (dp[nn][nk][nv1][nv2] == dp[nn - 1][nk - 1][0][0] + all[nn].first + all[nn].second) {
				nk--;
				pa = 0;
				pb = 0;
				ans[nn].first = last;
				ans[nn].second = last;
				last++;
			}
		}
		nk -= nv1 + nv2;
		nv1 = pa;
		nv2 = pb;
		if (nv1 == 1) {
			c1 = last;
			last++;
			ans[nn].first = c1;
		}
		if (nv2 == 1) {
			c2 = last;
			last++;
			ans[nn].second = c2;
		}
		nn--;
	}
	if (nk == 1 && nv1 == 0 && nv2 == 0) {
		ans[nn].first = last;
		ans[nn].second = last;
	}
	if (nv1 == 1) {
		ans[nn].first = c1;
	}
	if (nv2 == 1) {
		ans[nn].second = c2;
	}
	for (auto[a, b] : ans) {
		cout << a << ' ' << b << '\n';
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
