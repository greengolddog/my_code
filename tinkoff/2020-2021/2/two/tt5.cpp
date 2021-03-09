#include <bits/stdc++.h>
#define ll int64_t
#define elif else if

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> arr(n, 0), prev(n + 1, 0);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        prev[i + 1] = prev[i] + arr[i];
    }
    ll maxx = -100000000000, min_prev = 0, summ = 0, max_n = 0, max_k = 0, n_min = 0;
    for (ll i = 0; i < n; i++) {
        summ += arr[i];
        if (summ - min_prev > maxx) {
            max_n = n_min;
            max_k = i;
        }
        maxx = max(maxx, summ - min_prev);
        if (min_prev > prev[i + 1]) {
            n_min = i + 1;
        }
        min_prev = min(prev[i + 1], min_prev);
    }
    cout << max_n + 1 << ' ' << max_k + 1 << ' ' << maxx;
}