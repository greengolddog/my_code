#include <bits/stdc++.h>
#define ll int64_t
using namespace std;
vector<ll> topsort;

void dfs(vector<ll>& b, vector<vector<ll>>& arr, ll v) {
    b[v] = 1;
    for (auto i : arr[v]) {
	if (b[i] == 0) {
		dfs(b, arr, i);
	}
    }
    topsort.push_back(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, b2, summ = 0;
    cin >> n;
    vector<vector<ll>> arr(n, vector<ll>(0, 0));
    vector<int> arr2(n, 0);
    vector<ll> b(n, 0), b3(n, 0);
    for (ll i = 0; i < n; i++) {
	cin >> b2;
	arr2[i] = b2 - 1;
	arr[b2 - 1].push_back(i);
    }
    for (ll i = 0; i < n; i++) {
	if (b[i] == 0) {
	    dfs(b, arr, i);
	}
    }
    for (ll i = n - 1; i >= 0; i--) {
	if (b3[arr2[topsort[i]]] == 0) {
	    summ++;
	}
	b3[topsort[i]] = 1;
    }
    cout << summ;
}
