#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;
ll maxx = 0;

void dfs(vector<ll>& used, vector<vector<ll>>& arr, ll v, ll cp, vector<ll>& cv) {
    used[v] = cp;
    for (auto i : arr[v]) {
        if (used[i] == -1) {
            if (arr[v].size() == 1) {
                dfs(used, arr, i, cp, cv);
            } else {
                maxx++;
                cv.push_back(v);
                dfs(used, arr, i, maxx, cv);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, pr, nv, t, a, b, ca, cn;
    cin >> n;
    vector<vector<ll>> arr(n, vector<ll>(0, 0));
    vector<ll> used(n, -1), cv(1, -1);
    for (ll i = 0; i < n; i++) {
        cin >> pr;
        if (pr == 0) {
            nv = i;
        } else {
            arr[pr - 1].push_back(i);
        }
    }
    dfs(used, arr, nv, 0, cv);
    // for (ll i = 0; i < n; i++) {
    //     cout << i << ' ' << used[i] << ' ' << cv[used[i]] << endl;
    // }
    cin >> t;
    for (ll i = 0; i < t; i++) {
        cin >> a >> b;
        ca = used[a - 1];
        cn = used[b - 1];
        while ((cn != ca) && (cn != -1)) {
            cn = cv[cn];
        }
        if (cn == -1)  {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
    }
}