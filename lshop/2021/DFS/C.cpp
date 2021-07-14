#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void dfs(ll v, vector<vector<ll>>& arr, vector<bool>& used, vector<ll>& topsort, vector<bool>& here) {
	used[v] = true;
	here[v] = true;
	for (auto i : arr[v]) {
		if (here[i]) {
			cout << -1;
			exit(0);
		}
		if (!used[i]) {
			dfs(i, arr, used, topsort, here);
		}
	}
	topsort.push_back(v);
	here[v] = false;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> arr(n, vector<ll>(0, 0));
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr[a].push_back(b);
	}
	vector<ll> topsort;
	vector<bool> used(n, false), here(n, false);
	for (ll i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i, arr, used, topsort, here);
		}
	}
	reverse(topsort.begin(), topsort.end());
	for (auto i : topsort) {
		cout << i+1 << ' ';
	}
}
