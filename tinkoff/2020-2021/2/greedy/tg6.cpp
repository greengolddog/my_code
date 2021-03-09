#include <bits/stdc++.h>
#define ll long long
#define elif else if

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, p, inp, np = 0, na1 = 0, na2 = 0;
    double s = 0;
    cin >> n;
    vector<ll> arr(n, 0), a1, a2;
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        s += arr[i];
    }
    cin >> m;
    for (ll i = 0; i < m; i++) {
        cin >> p >> inp;
        if (p == 1) {
            a1.push_back(inp);
        } else {
            a2.push_back(inp);
        }
    }
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    sort(a1.begin(), a1.end());
    reverse(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    reverse(a2.begin(), a2.end());
    a1.push_back(0);
    a2.push_back(0);
    for (ll i = 0; i < n; i++) {
        // cout << np << ' ' << na1 << ' ' << na2 << ' ' << (arr[np]*a1[na1]/100.0) << ' ' << a2[na2] << endl;
        if ((arr[np]*a1[min((ll)a1.size(), na1)]/100.0) > a2[min((ll)a2.size(), na2)]) {
            s += arr[np]*a1[min((ll)a1.size(), na1)]/100.0;
            na1++;
            np++;
        } else {
            s += a2[min((ll)a2.size(), na2)];
            na2++;
        }
    }
    cout << s;
}
