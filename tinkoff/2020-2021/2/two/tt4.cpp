#include <bits/stdc++.h>
#define ll int64_t
#define elif else if

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, s, kol = 0, mt = 0;
    double l;
    cin >> n >> l;
    set<double> arr;
    for (ll i = 0; i < n; i++) {
        cin >> s;
	arr.upper_bound(i+l/s);
    }
}
