#include <bits/stdc++.h>
#define ll int64_t
#define elif else if

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, r;
    cin >> n >> r;
    vector<ll> arr(n, 0);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll l = 0, summ = 0;
    for (ll i = 0; i < n; i++) {
        while ((l < (n - 1)) && ((arr[l] - arr[i]) <= r)) {
            l++;
        }
        if ((arr[l] - arr[i]) > r) {
            summ += n - l;
        }
        // cout << i << ' ' << l << ' ' << (arr[l] - arr[i]) << ' ' << summ << endl;
    }
    cout << summ;
}