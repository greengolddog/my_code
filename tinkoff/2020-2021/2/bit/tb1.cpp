#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll a;
    cin >> a;
    for (ll i = 7; i >= 0; i--) {
        cout << ((a >> i) & 1);
    }
}