#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, a, b;
    cin >> n >> m;
    vector<vector<ll>> arr(n, vector<ll>(0, 0));
    for (ll i = 0; i < m; i++) {
        cin >> a >> b;
        arr[b - 1].push_back(a - 1);
    }
    vector<ll> was(n, 0);
    for (ll i = 0; i < n; i++) {
        cin >> a;
        a--;
        for (auto j : arr[a]) {
            if (was[j] == 0) {
                cout << "NO";
                return 0;
            }
        }
        was[a] = 1;
    }
    cout << "YES";
}
