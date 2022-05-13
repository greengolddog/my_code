#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000, MAXLN = 30;

struct sparse_table {
	vector<vector<pair<ll, ll>>> arr;
	vector<ll> pow, log;
	ll size;
	sparse_table(vector<pair<ll, ll>> a) {
		size = a.size();
		pow.push_back(1);
		for (ll i = 0; i < MAXLN; i++) {
			pow.push_back(pow.back() * 2);
		}
		log.resize(size + 1, 0);
		for (ll i = 2; i <= size; i++) {
			log[i] = log[i - 1];
			if (i == pow[log[i] + 1]) {
				log[i]++;
			}
		}
		arr.resize(MAXLN, vector<pair<ll, ll>>(size, {0, 0}));
		for (ll i = 0; i < size; i++) {
			arr[0][i] = a[i];
		}
		for (ll i = 1; i < MAXLN; i++) {
			for (ll j = 0; j <= (size - pow[i]); j++) {
				arr[i][j] = min(arr[i - 1][j], arr[i - 1][j + pow[i - 1]]);
			}
		}
	}
	pair<ll, ll> get(ll l, ll r) {
		return min(arr[log[r - l]][l], arr[log[r - l]][r - pow[log[r - l]]]);
	}
};

void dfs(ll v, ll p, vector<vector<ll>>& arr, vector<pair<ll, ll>>& ans, ll h = 0) {
	ans.push_back({h, v});
	for (auto i : arr[v]) {
		if (i != p) {
			dfs(i, v, arr, ans, h + 1);
			ans.push_back({h, v});
		}
	}
}

int main() {
	freopen("lca2.in", "r", stdin);
	freopen("lca2.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> arr(n, vector<ll>(0, 0));
	for (ll i = 1; i < n; i++) {
		ll v;
		cin >> v;
		arr[i].push_back(v);
		arr[v].push_back(i);
	}
	vector<pair<ll, ll>> a;
	dfs(0, -1, arr, a);
	sparse_table st(a);
	vector<ll> num(n, 0);
	for (ll i = 0; i < a.size(); i++) {
		num[a[i].second] = i;
	}
	ll a1, a2;
	cin >> a1 >> a2;
	ll x, y, z;
	cin >> x >> y >> z;
	ll ans = 0, last = 0;
	for (ll i = 0; i < m; i++) {
		ll a1n = (a1 + last) % n;
		last = st.get(min(num[a1n], num[a2]), max(num[a1n], num[a2]) + 1).second;
		ans += last;
		ll a2n = a2;
		a2 = (x * a1 + y * a2 + z) % n;
		a1 = a2n;
		a2n = a2;
		a2 = (x * a1 + y * a2 + z) % n;
		a1 = a2n;
	}
	cout << ans;
}
