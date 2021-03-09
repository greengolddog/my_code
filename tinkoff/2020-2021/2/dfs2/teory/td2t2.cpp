#include <bits/stdc++.h>
#define ll long long
#define elif else if
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
    freopen("topsort.in", "r", stdin);
    freopen("topsort.out", "w", stdout);
    ll n, m, b2, a2, a;
    cin >> n >> m;
    vector<vector<ll>> arr(n, vector<ll>(0, 0)), arr2(n, vector<ll>(0, 0));
    vector<ll> b(n, 0);
    for (ll i = 0; i < m; i++) {
        cin >> b2 >> a2;
        arr[b2 - 1].push_back(a2 - 1);
        arr2[a2 - 1].push_back(b2 - 1);
    }
    for (ll i = 0; i < n; i++) {
        if (b[i] == 0) {
            dfs(b, arr, i);
        }
    }
    reverse(topsort.begin(), topsort.end());
    vector<ll> was(n, 0);
    for (ll i = 0; i < n; i++) {
        a = topsort[i];
        for (auto j : arr2[a]) {
            if (was[j] == 0) {
                cout << -1;
                return 0;
            }
        }
        was[a] = 1;
    }
    for (auto i : topsort) {
        cout << i + 1 << ' ';
    }
}
