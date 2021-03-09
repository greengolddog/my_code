#include <bits/stdc++.h>
#define ll int64_t
#define elif else if

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll m, d, sm, sd;
    cin >> m >> d;
    sm = m;
    sd = d;
    for (ll i = 0; i < (m+d); i++) {
        if (((i % 3 == 0) && (sm > 0)) || (sd == 0)) {
            cout << 'B';
            sm--;
        } else {
            cout << 'G';
            sd--;
        }
    }
}
