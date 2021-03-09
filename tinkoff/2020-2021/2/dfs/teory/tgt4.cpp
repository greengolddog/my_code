#include <bits/stdc++.h>
#define ll int64_t
#define elif else if
using namespace std;

ll dfs2(vector<ll>& b, vector<vector<ll>>& arr, ll v) {
    ll stc = 1;
    b[v] = 1;
    for (auto i : arr[v]) {
	if (b[i] == 0) {
		stc += dfs2(b, arr, i);
	}
    }
    return stc;
}

ll dfs(vector<ll>& b, vector<vector<ll>>& arr, ll v, ll p) {
    b[v] = 1;
    for (auto i : arr[v]) {
	if (b[i] == 0) {
	    if (dfs(b, arr, i, v) == 1) {
		return 1;
	    }
	} elif(i != p) {
	    return 1;
	}
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, x, y, ye = 0;
    cin >> n >> m;
    vector<vector<ll>> arr(n, vector<ll>(0, 0));
    vector<ll> b(n, 0), b2(n, 0);
    for (ll i = 0; i < m; i++) {
	cin >> x >> y;
	arr[x - 1].push_back(y - 1);
	arr[y - 1].push_back(x - 1);
    }
    if (dfs2(b2, arr, 0) == n) {
	for (ll i = 0; i < n; i++) {
	    if (b[i] == 0) {
		if (dfs(b, arr, i, -1) == 1) {
		    cout << "NO";
		    ye = 1;
		    break;
		}
	    }
	}
	if (ye == 0) {
	    cout << "YES";
	}
    } else {
	cout << "NO";
    }
}
