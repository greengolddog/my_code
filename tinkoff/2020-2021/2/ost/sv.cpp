#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

ll dfs(vector<ll>& b, vector<vector<ll>>& arr, ll v) {
    ll stc = 1;
    b[v] = 1;
    for (auto i : arr[v]) {
	if (b[i] == 0) {
		stc += dfs(b, arr, i);
	}
    }
    return stc;
}

vector<ll> dfs2(vector<ll>& b, vector<vector<ll>>& arr, ll v) {
    vector<ll> ve(1, v + 1);
    b[v] = 1;
    for (auto i : arr[v]) {
	if (b[i] == 0) {
	    for (auto j : dfs2(b, arr, i)) {
		ve.push_back(j);
	    }
	}
    }
    return ve;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, x, y, summ = 0;
    cin >> n >> m;
    vector<vector<ll>> arr(n, vector<ll>(0, 0));
    vector<ll> b(n, 0), b2(n, 0), b3(n, 0), ans;
    for (ll i = 0; i < m; i++) {
	ll a;
	cin >> x >> y >> a;
	arr[x - 1].push_back(y - 1);
	arr[y - 1].push_back(x - 1);
    }
    for (ll i = 0; i < n; i++) {
	if (b[i] == 0) {
	    summ++;
	    dfs(b, arr, i);
	}
    }
    cout << summ << endl;
}
