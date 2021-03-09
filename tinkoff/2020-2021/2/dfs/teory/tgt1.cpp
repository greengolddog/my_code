#include <bits/stdc++.h>
#define ll int64_t
#define elif else if
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, x, y;
    cin >> n >> m;
    vector<vector<ll>> arr(n, vector<ll>(n, 0));
    for (ll i = 0; i < m; i++) {
        cin >> x >> y;
        arr[x-1][y-1] = 1;
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}
