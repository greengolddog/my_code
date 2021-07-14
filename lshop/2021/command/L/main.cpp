#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    int q = 1000000009, p = 179;
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<int> pow(n), h(n);
    pow[0] = 1;
    for (int i = 1; i < n; ++i)
        pow[i] = (pow[i-1]*p)%q;
    h[0] = s[0]-'a'+1;
    for (int i = 1;i<n;++i){
        h[i] = (h[i - 1]*p+s[i]-'a'+1)%q;
    }
    int ans = 1;
    for (int i = 1;i<n;++i) {
        int h1 = (q*q+h[n-1]-(h[i - 1]*pow[n-1])%q)%q;
        int h2 = h[n-i-1]%q;
        if (h1 == h2 && n%i==0) {
            ans = n / i;
            break;
        }
    }
    if (ans == 1) {
        cout << 1 << '\n' << 1;
    }
    else if(ans == 2)
        cout << 2 << '\n' << n-1;
    else if(ans == n)
        cout << n << '\n' << 1;
    else
        cout << 2 << '\n' << ans * (n/ans-1);
}

