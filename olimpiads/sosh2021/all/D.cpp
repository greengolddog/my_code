#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, k, ms;
    cin >> n >> m >> k;
    m++;
    vector<ll> ch(n, -1);
    for (ll i = 0; i < n; i++) {
        cin >> ch[i];
    }
    ll lg = 1, m2 = m, ns = k, mm, no, pu;
    while (m2 >= k) {
        lg++;
        m2 = m2/k;
    }
    mm = lg;
    vector<ll> arr(lg + 1, 1), ts(lg + 1, 1), arr2(lg + 1, 1), arr3(lg + 1, 0), arr4(lg + 1, 0), bp(lg + 1, 0);
    ts[0] = 1;
    for (ll i = 1; i <= lg; i++) {
        ts[i] = ns;
        arr[i] = (min(m, ns) - (ns / k)) % 1000000007;
        ns = ns * k;
    }
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    for (ll i = 1; i <= n; i++) {
        ll cpn = 0, nc = 0;
        for (ll j = 1; j <= min(i, mm); j++) {
            nc *= k;
            if (j < mm) {
                if (ch[i - j] == -1) {
                    cpn++;
                    dp[i] += (dp[i - j] * arr[cpn]) % 1000000007;
                    // cout << i << ' ' << j << ' ' << (dp[i - j] * arr[cpn]) << ' ' << cpn << ' ' << ch[i - j] << endl;
                } else {
                    if (ch[i - j] != 0) {
                        nc += ch[i - j];
                        if (nc <= m) {
                            dp[i] += (dp[i - j] * ts[cpn]) % 1000000007;
                        }
                        // cout << i << ' ' << j << ' ' << (dp[i - j] * arr[cpn]) << ' ' << cpn << ' ' << ch[i - j] << ' ' << nc << endl;
                    }
                }
            } else {
                if (ch[i - j] == -1) {
                    cpn++;
                }
                        nc += ch[i - j];
                        if (nc <= m) {
                            dp[i] += (dp[i - j] * arr[j] / ts[j - cpn]) % 1000000007;
                        }
            }
        }
        // cout << dp[i] << endl;
    }
    cout << dp[n] % 1000000007;
}