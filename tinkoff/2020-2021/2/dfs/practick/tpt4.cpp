#include <bits/stdc++.h>
#define ll int64_t
using namespace std;
vector<vector<ll>> arr2;

void dfs(vector<ll>& b, vector<vector<ll>>& arr, ll v) {
    b[v] = 1;
    for (auto i : arr[v]) {
	if (b[i] == 0) {
	    arr2[v].push_back(i);
	    dfs(b, arr, i);
	}
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, x, y;
    char a;
    cin >> n >> m;
    vector<vector<ll>> arr(n, vector<ll>(0, 0));
    vector<ll> b(n, 0);
    arr2 = vector<vector<ll>>(n, vector<ll>(0, 0));
    for (ll i = 0; i < m; i++) {
	cin >> x >> y;
	arr[x - 1].push_back(y - 1);
	arr[y - 1].push_back(x - 1);
    }
    dfs(b, arr, 0);
    for (ll i = 0; i < n; i++) {
	for (ll j = 0; j < arr2[i].size(); j++) {
	    cout << i + 1 << ' ' << arr2[i][j] + 1 << endl;
	}
    }
}
