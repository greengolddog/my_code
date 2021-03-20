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
    string s;
    cin >> s;
    string sr = s;
    reverse(sr.begin(), sr.end());
    ll p = 67, summ = 0, ss = s.size();
    vector<ll> step_p(s.size() + 1, 1), hash(s.size() + 1, 0), hashr(s.size() + 1, 0);
    // cout << 1 << ' ' << 0 << ' ' << 0 << endl;
    for (ll i = 1; i <= s.size(); ++i) {
        step_p[i] = mul(step_p[i - 1], p);
        hash[i] = add(mul(hash[i - 1], p), s[i - 1]-'A'+1);
        hashr[i] = add(mul(hashr[i - 1], p), sr[i - 1]-'A'+1);
        // cout << step_p[i] << ' ' << hashs[i] << ' ' << hasht[i] << endl;
    }
    // cout << vh(hashs, 2, s.size(), step_p) << endl;
    for (ll i = 0; i < s.size(); ++i) {
        ll l = i, r = min(ss - 1, i*2);
        while (l - r > 1) {
            ll mid = (l + r) / 2;
            if (vh(hash, i - (mid - i), mid + 1, step_p) == vh(hashr, s.size() - mid, s.size() - i + (mid - i), step_p)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (vh(hash, i - (r - i), r + 1, step_p) == vh(hashr, s.size() - r, s.size() - i + (r - i), step_p)) {
            summ += r - i + 1;
        } else {
            summ += l - i + 1;
        }
        // cout << i << ' ' << summ << endl;
    }
    for (ll i = 1; i < s.size(); ++i) {
        ll l = i, r = min(ss - 1, i*2 - 1);
        while (l - r > 1) {
            ll mid = (l + r) / 2;
            if (vh(hash, i - (mid - i), mid + 1, step_p) == vh(hashr, s.size() - mid, s.size() - i + (mid - i), step_p)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (vh(hash, i - (l - i), l + 1, step_p) == vh(hashr, s.size() - l, s.size() - i + (l - i), step_p)) {
            if (vh(hash, i - (r - i), r + 1, step_p) == vh(hashr, s.size() - r, s.size() - i + (r - i), step_p)) {
                summ += r - i + 1;
            } else {
                summ += l - i + 1;
            }
        }
        // cout << i << ' ' << summ << endl;
    }
    cout << summ;
}
