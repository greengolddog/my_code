#include <bits/stdc++.h>
#define ll long long
#define elif else if
#define endl '\n'
#define ull unsigned long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s, t, st;
    cin >> s >> t;
    st = t+"@"+s;
    vector<ll> pref(st.size(), 0);
    for (ll i = 1; i < st.size(); i++) {
        ll d = pref[i - 1];
        while ((d > 0) && (st[i] != st[d])) {
            d = pref[d - 1];
        }
        if (st[i] == st[d]) {
            pref[i] = d + 1;
        }
    }
    for (ll i = 1; i < st.size(); i++) {
        if (pref[i] == t.size()) {
            cout << i - t.size()*2 << ' ';
        }
    }
}
