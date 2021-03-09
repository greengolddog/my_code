#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

void dfs(vector<ll>& b, vector<vector<ll>>& arr, ll v) {
    b[v] = 1;
    for (auto i : arr[v]) {
	if (b[i] == 0) {
	    dfs(b, arr, i);
	}
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, summ = 0, size = 0;
    char a;
    cin >> n >> m;
    vector<vector<ll>> arr(n + 2, vector<ll>(m + 2, 0)), arr3(n + 2, vector<ll>(m + 2, 0)), arr2(0, vector<ll>(0, 0));
    vector<ll> b;
    for (ll i = 1; i <= n; i++) {
	for (ll j = 1; j <= m; j++) {
	    cin >> a;
	    if (a == '#') {
		arr3[i][j] = size;
		size++;
		arr[i][j] = 1;
	    } else {
		arr[i][j] = 0;
	    }
	}
    }
    for (ll i = 1; i <= n; i++) {
	for (ll j = 1; j <= m; j++) {
	    if (arr[i][j] == 1) {
		b.push_back(0);
		vector<ll> c;
		if (arr[i - 1][j] == 1) {
			c.push_back(arr3[i - 1][j]);
		}
		if (arr[i][j - 1] == 1) {
			c.push_back(arr3[i][j - 1]);
		}
		if (arr[i + 1][j] == 1) {
			c.push_back(arr3[i + 1][j]);
		}
		if (arr[i][j + 1] == 1) {
			c.push_back(arr3[i][j + 1]);
		}
		arr2.push_back(c);
	    }
	}
    }
    for (ll i = 0; i < arr2.size(); i++) {
	if (b[i] == 0) {
	    summ++;
	    dfs(b, arr2, i);
	}
    }
    cout << summ;
}
