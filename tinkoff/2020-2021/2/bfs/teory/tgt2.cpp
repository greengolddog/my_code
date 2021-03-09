#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

struct point {
    ll x;
    ll y;
    ll c;
    point(ll x, ll y, ll c): x(x), y(y), c(c) {}
};

int main() {
    freopen("distance.in", "r", stdin);
    freopen("distance.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, x, y, c, s, f, m, now;
    cin >> n >> m >> s >> f;
    vector<point> sv;
    s--;
    f--;
    for (ll i = 0; i < m; i++) {
        cin >> x >> y >> c;
        sv.push_back(point(x - 1, y - 1, c));
        sv.push_back(point(y - 1, x - 1, c));
    }
    vector<ll> st(n, 100000);
    vector<ll> p(n, -1);
    st[s] = 0;
    for (ll i = 0; i < (n - 1); i++) {
        for (auto j : sv) {
            if (st[j.x] != 100000) {
                if ((st[j.x] + j.c) < st[j.y]) {
                    st[j.y] = st[j.x] + j.c;
                    p[j.y] = j.x;
                }
            }
        }
    }
    if (st[f] != 100000) {
        cout << st[f] << endl;
        vector<ll> ob(1, f);
        now = f;
        while (p[now] > -1) {
            ob.push_back(p[now]);
            now = p[now];
        }
        reverse(ob.begin(), ob.end());
        for (auto i : ob) {
            cout << i + 1 << ' ';
        }
    } else {
        cout << -1;
    }
}
