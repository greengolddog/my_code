#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct DSU {
	vector<ll> pred, rang;
	ll size;
	DSU(ll n) {
		pred.resize(n, 0);
		rang.resize(n, 1);
		for (ll i = 0; i < n; i++) {
			pred[i] = i;
		}
		size = n;
	}
	ll get(ll v) {
		if (pred[v] == v) {
			return v;
		}
		return pred[v] = get(pred[v]);
	}
	void unite(ll a, ll b) {
		a = get(a);
		b = get(b);
		if (a == b) {
			return;
		}
		if (rang[a] < rang[b]) {
			swap(a, b);
		}
		pred[b] = a;
		rang[a] += rang[b];
	}
	bool in_one(ll a, ll b) {
		return get(a) == get(b);
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m, ans = 0;
	cin >> n >> m;
	DSU d(n);
	vector<tuple<ll, ll, ll, ll>> arr;
	for (ll i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		arr.push_back(make_tuple(c, a, b, i));
	}
	sort(arr.begin(), arr.end());
	vector<ll> ar;
	for (auto[c, a, b, num] : arr) {
		if (d.in_one(a, b)) {
			continue;
		}
		ans += c;
		ar.push_back(num);
		d.unite(a, b);
	}
	ll p5, q5, p6, q6, f = 0;
	cin >> p5 >> q5 >> p6 >> q6;
	if (p6 < p5) {
		swap(p6, p5);
		swap(q5, q6);
		f = 1;
	}
	vector<vector<bool>> dp(ar.size()+1, vector<bool>(q5+1, false));
	dp[0][0] = true;
	for (ll i = 1; i <= ar.size(); i++) {
		auto[c, a, b, now] = arr[ar[i-1]];
		cout << c << ' ' << a << ' ' << b << ' ' << now << endl;
		for (ll j = c; j <= q5; j++) {
			dp[i][j] = dp[i-1][j-c] | dp[i-1][j];
		}
	}
	ll aa = 0;
	for (ll i = 0; i <= q5; i++) {
		if (dp[ar.size()][i]) {
			aa = max(aa, i);
		}
	}
	cout << p5*aa+(ans-aa)*p6;
}
