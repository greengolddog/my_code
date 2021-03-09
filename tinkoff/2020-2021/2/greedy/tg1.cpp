#include <bits/stdc++.h>
#define ll int64_t
#define elif else if

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, s = 0, dn = 0;
    cin >> n;
    vector<pair<ll, ll>> arr(n, {0, 0});
    for (ll i = 0; i < n; i++) {
        cin >> arr[i].second >> arr[i].first;
    }
    sort(arr.begin(), arr.end());
    for (ll i = 0; i < n; i++) {
        if (dn <= arr[i].second) {
            dn = arr[i].first;
            s++;
        }
    }
    cout << s;
}
