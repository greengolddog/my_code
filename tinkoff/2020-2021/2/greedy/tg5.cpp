#include <bits/stdc++.h>
#define ll int64_t
#define elif else if

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll r, n, s = 0, k, pz = 0;
    cin >> r >> k >> n;
    vector<ll> arr(n + 1, r);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (ll i = 0; i < n; i++) {
        if (arr[i] - pz <= k) {
            if (arr[i + 1] - pz > k) {
                s++;
                pz = arr[i];
            }
        } else {
            cout << -1;
            return 0;
        }
    }
    if (r - pz <= k) {
        cout << s;
    } else {
        cout << -1;
    }
}
