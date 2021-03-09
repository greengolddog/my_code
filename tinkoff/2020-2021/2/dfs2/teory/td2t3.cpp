#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

void dfs(vector<ll>& b, vector<vector<ll>>& arr, ll v, vector<ll>& topsort, ll cp) {
    b[v] = cp;
    for (auto i : arr[v]) {
        if (b[i] == 0) {
            dfs(b, arr, i, topsort, cp);
        }
    }
    topsort.push_back(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, b2, a2, a, cc = 1, summ = 0;
    cin >> n >> m;
    vector<ll> topsort;
    vector<vector<ll>> arr(n, vector<ll>(0, 0)), arr2(n, vector<ll>(0, 0));
    vector<ll> b(n, 0);
    for (ll i = 0; i < m; i++) {
        cin >> b2 >> a2;
        arr[b2 - 1].push_back(a2 - 1);
        arr2[a2 - 1].push_back(b2 - 1);
    }
    for (ll i = 0; i < n; i++) {
        if (b[i] == 0) {
            dfs(b, arr, i, topsort, 1);
        }
    }
    reverse(topsort.begin(), topsort.end());
    b.assign(n, 0);
    for (ll i = 0; i < n; i++) {
        if (!b[topsort[i]]) {
            vector<ll> component;
            dfs(b, arr2, topsort[i], component, cc);
            cc++;
        }
    }
    vector<set<ll>> arrs(cc);
    for (ll i = 0; i < n; i++) {
        for (auto j : arr[i]) {
            if (b[i] != b[j]) {
                arrs[b[i] - 1].insert(b[j] - 1);
            }
        }
    }
    for (ll i = 0; i < cc; i++) {
        summ += arrs[i].size();
    }
    cout << summ;
}
