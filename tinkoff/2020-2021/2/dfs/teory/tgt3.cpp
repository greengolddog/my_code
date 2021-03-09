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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, b2;
    cin >> n >> m;
    vector<vector<ll>> arr(n, vector<ll>(0, 0));
    vector<ll> b(n, 0);
    for (ll i = 0; i < n; i++) {
	for (ll j = 0; j < n; j++) {
	    cin >> b2;
	    if (b2 == 1) {
		arr[i].push_back(j);
	    }
	}
    }
    cout << dfs(b, arr, m-1);
}
