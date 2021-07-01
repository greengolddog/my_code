#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void dfs(ll v, vector<vector<ll>>& arr, vector<ll>& tin, vector<ll>& tout, ll& in, ll& out, vector<ll>& used) {
	tin[v] = in;
	in++;
	used[v] = 1;
	for (auto i : arr[v]) {
		if (!used[i]) {
			dfs(i, arr, tin, tout, in, out, used);
		}
	}
	tout[v] = out;
	out++;
}

bool is_p(ll v, ll u, vector<ll>& tin, vector<ll>& tout) {
	return ((tin[u] >= tin[v]) && (tout[u] <= tout[v]));
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, c = -1;
	cin >> n;
	vector<ll> tin(n, 0), tout(n, 0);
	ll in = 0, out = 0;
	vector<vector<ll>> arr(n, vector<ll>(0, 0));
	for (ll i = 0; i < n; i++) {
		ll p;
		cin >> p;
		p--;
		if (p == -1) {
			c = i;
			continue;
		}
		arr[p].push_back(i);
	}
	vector<ll> used(n, 0);
	dfs(c, arr, tin, tout, in, out, used);
	ll m;
	cin >> m;
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		cout << is_p(a, b, tin, tout) << '\n';
	}
}
