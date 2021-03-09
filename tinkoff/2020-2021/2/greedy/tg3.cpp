#include <bits/stdc++.h>
#define ll int64_t
#define elif else if

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, s2 = 0, inp;
    cin >> n;
    multiset<ll> s;
    for (ll i = 0; i < n; i++) {
        cin >> inp;
        s.insert(inp);
    }
    while (s.size() > 1) {
        auto it = s.begin();
        it++;
        ll now = *it+*(s.begin());
        s.erase(it);
        s.erase(s.begin());
        s.insert(now);
        s2 += now;
        // cout << now << ' ' << s.size() << endl;
    }
    cout << s2;
}
