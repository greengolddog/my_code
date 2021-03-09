#include <bits/stdc++.h>
#define ll int64_t
#define elif else if

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll v, n, s = 0;
    cin >> v >> n;
    vector<ll> arr(n, 0);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (ll i = 0; i < n; i++) {
        if (v >= arr[i]) {
            v -= arr[i];
            s++;
        }
    }
    cout << s;
}
