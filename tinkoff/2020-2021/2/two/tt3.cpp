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
    ll i = 0, n2 = 1, n3 = 0;
    while (true) {
        n3++;
        i++;
        if (i == n) {
            cout << n3*n3*n3;
            break;
        }
        while ((n2+1)*(n2+1) <= (n3+1)*(n3+1)*(n3+1)) {
            n2++;
            if (n2*n2 != (n3+1)*(n3+1)*(n3+1)) {
                i++;
                if (i == n) {
                    cout << n2*n2;
                    break;
                }
            }
        }
        if (n == i) {
            break;
        }
    }
}