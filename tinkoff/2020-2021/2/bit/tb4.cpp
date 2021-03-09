#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll a, summ = 0;
        cin >> a;
        for (ll i = 30; i >= 0; i--) {
            if ((a >> i) & 1) {
                summ++;
            }
        }
        cout << setprecision(20) << pow(2, summ) << endl;
    }
}