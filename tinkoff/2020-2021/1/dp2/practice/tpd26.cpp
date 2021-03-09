#include <bits/stdc++.h>
#define ll int64_t
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    cout << ((n / 9) * (9 * 9)) + ((n % 9) * (n % 9));
}
