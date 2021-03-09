#include <bits/stdc++.h>
#define ll int64_t
#define elif else if
using namespace std;

ll dfs(vector<ll>& b, vector<vector<ll>>& arr, ll v, vector<ll>& b2) {
    b2[v] = 1;
    b[v] = 1;
    for (auto i : arr[v]) {
	if (b[i] == 0) {
	    if (dfs(b, arr, i, b2) == 1) {
		b2[v] = 0;
		return 1;
	    }
	} elif(b2[i] == 1) {
	    b2[v] = 0;
	    return 1;
	}
    }
    b2[v] = 0;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, x, y, ye = 0;
    cin >> n >> m;
    vector<vector<ll>> arr(n, vector<ll>(0, 0));
    vector<ll> b(n, 0);
    for (ll i = 0; i < m; i++) {
	cin >> x >> y;
	arr[x - 1].push_back(y - 1);
    }
    for (ll i = 0; i < n; i++) {
	if (b[i] == 0) {
	    vector<ll> b2(n, 0);
	    if (dfs(b, arr, i, b2) == 1) {
		cout << 1;
		ye = 1;
		break;
	    }
	}
    }
    if (ye == 0) {
	cout << 0;
    }
}
