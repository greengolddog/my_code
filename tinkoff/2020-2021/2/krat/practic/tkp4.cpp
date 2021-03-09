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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, x, y, c, a, minn = 3000000000000;
    cin >> n >> m;
    vector<point> sv;
    vector<ll> dist(n, 3000000000000), c2;
    for (ll i = 0; i < n; i++) {
        cin >> a;
        if (a == 1) {
            dist[i] = 0;
        } elif(a == 2) {
            c2.push_back(i);
        }
    }
    for (ll i = 0; i < m; i++) {
        cin >> x >> y >> c;
        sv.push_back(point(x - 1, y - 1, c));
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (dist[sv[j].x] != 3000000000000) {
                dist[sv[j].y] = min(dist[sv[j].y], dist[sv[j].x]+sv[j].c);
            }
        }
    }
    for (ll i = 0; i < c2.size(); i++) {
        minn = min(minn, dist[c2[i]]);
    }
    cout << minn;
}
