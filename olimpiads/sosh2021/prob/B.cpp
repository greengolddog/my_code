#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, l, r;
    string s;
    cin >> n;
    l = 0;
    r = n + 1;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        cout << mid << endl;
        fflush(stdout);
        cin >> s;
        if (s == "<") {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << "! " << l << endl;
    fflush(stdout);
}