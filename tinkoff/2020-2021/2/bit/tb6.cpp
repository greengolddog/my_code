#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<pair<ll, ll>> arr(100001, {-1, -1});
    ll a, k, summ = 0;
    cin >> a;
    for (ll i = 0; i < a; i++) {
        cin >> k;
        if (arr[k].first < 0) {
            summ++;
        }
        arr[k].first = i;
        arr[k].second = k;
    }
    sort(arr.begin(), arr.end());
    cout << summ << "\n";
    for (ll i = 0; i < 100001; i++) {
        if (arr[i].first > -1) {
            cout << arr[i].second << ' ';
        }
    }
}