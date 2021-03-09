#include <bits/stdc++.h>
#define ll long long
#define elif else if

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll s = 0;
    double n;
    cin >> n;
    vector<pair<ll, ll>> arr(31, {0, 1});
    cin >> arr[0].first;
    for (ll i = 1; i < 31; i++) {
        cin >> arr[i].first;
        arr[i].second = arr[i - 1].second*2;
        arr[i].first = max(arr[i].first, arr[i - 1].first*2);
    }
    for (ll i = 30; i > 0; i--) {
        // cout << i << ' ' << arr[i].first << ' ' << n << ' ' << n/arr[i].first << endl;
        s += floor(n/arr[i].first)*arr[i].second;
        n = n-floor(n/arr[i].first)*arr[i].first;
        if (floor(n/arr[i - 1].first) >= 2) {
            s += arr[i].second;
            n = 0;
        }
    }
    s += floor(n/arr[0].first)*arr[0].second;
    n = n-floor(n/arr[0].first)*arr[0].first;
    if (n > 0) {
        s += 1;
    }
    cout << s;
}
