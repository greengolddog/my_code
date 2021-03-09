#include <bits/stdc++.h>
#define ll int64_t
#define elif else if

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    char ch;
    ll n, s = 0, cg = 0;
    cin >> n;
    vector<vector<ll>> arr(n, vector<ll>(n, 2)), arr2(n, vector<ll>(n, 0));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> ch;
            if (ch == 'C') {
                arr2[i][j] = 1;
                cg++;
            }
        }
    }
    cg = cg / 2;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            arr[i][j] = 1;
            if (arr2[i][j] == 1) {
                s++;
                if (s == cg) {
                    break;
                }
            }
        }
        if (s == cg) {
            break;
        }
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
}
