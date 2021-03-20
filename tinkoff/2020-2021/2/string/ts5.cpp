#include <bits/stdc++.h>
#define ll long long
#define elif else if
#define endl '\n'
#define ull unsigned long long

using namespace std;

ll mod = 1000000009;

ll add(ll a, ll b) {
    ll ans = a + b;
    if (ans >= mod) {
        ans -= mod;
    }
    if (ans < 0) {
        ans += mod;
    }
    return ans;
}

ll sub(ll a, ll b) {
    ll ans = a - b;
    if (ans >= mod) {
        ans -= mod;
    }
    if (ans < 0) {
        ans += mod;
    }
    return ans;
}

ll mul(ll a, ll b) {
    return (a * b) % mod;
}

ll vh(vector<ll>& hash, ll l, ll r, vector<ll>& step_p) {
    return sub(hash[r], mul(hash[l - 1], step_p[r - l + 1]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s, t;
    cin >> s >> t;
    ll p = 67;
    vector<ll> step_p(s.size() + 1, 1), hashs(s.size() + 1, 0), hasht(t.size() + 1, 0);
    // cout << 1 << ' ' << 0 << ' ' << 0 << endl;
    for (ll i = 1; i <= s.size(); ++i) {
        step_p[i] = mul(step_p[i - 1], p);
        hashs[i] = add(mul(hashs[i - 1], p), s[i - 1]-'a'+1);
        hasht[i] = add(mul(hasht[i - 1], p), t[i - 1]-'a'+1);
        // cout << step_p[i] << ' ' << hashs[i] << ' ' << hasht[i] << endl;
    }
    // cout << vh(hashs, 2, s.size(), step_p) << endl;
    for (ll i = t.size(); i >= 0; --i) {
        if (vh(hashs, 1, i, step_p) == vh(hasht, t.size()-i+1, t.size(), step_p)) {
            if (vh(hasht, 1, t.size()-i, step_p) == vh(hashs, i+1, t.size(), step_p)) {
                cout << t.size()-i;
                return 0;
            }
        }
    }
    cout << -1;
}
