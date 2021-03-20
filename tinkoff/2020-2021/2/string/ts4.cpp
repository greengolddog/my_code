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
    ll n;
    cin >> n;
    string s, st;
    cin >> s;
    st = s;
    reverse(st.begin(), st.end());
    ll p = 67;
    vector<ll> step_p(s.size() + 1, 1), hash(s.size() + 1, 0), hashr(s.size() + 1, 0);
    // cout << 1 << ' ' << 0 << ' ' << 0 << endl;
    for (ll i = 1; i <= s.size(); ++i) {
        step_p[i] = mul(step_p[i - 1], p);
        hash[i] = add(mul(hash[i - 1], p), s[i - 1]-'A'+1);
        hashr[i] = add(mul(hashr[i - 1], p), st[i - 1]-'A'+1);
        // cout << step_p[i] << ' ' << hash[i] << ' ' << hashr[i] << endl;
    }
    // cout << hash[4] << endl;
    for (ll i = 0; i < s.size(); ++i) {
        ll l = -1, r = i;
        while (r - l > 1) {
            ll mid = (l + r)/2;
            if (vh(hash, 1, mid + 1, step_p) == vh(hashr, s.size() - i, s.size()-(i-mid), step_p)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (s[i] == s[0]) {
            cout << i - r + 1 << ' ';
        } else {
            cout << 0 << ' ';
        }
    }
}
