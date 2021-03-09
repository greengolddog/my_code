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
    ll n, m, x, y, c, iz;
    cin >> n >> m;
    vector<point> sv;
    for (ll i = 0; i < m; i++) {
        cin >> x >> y >> c;
        sv.push_back(point(x - 1, y - 1, 0 - c));
    }
    vector<ll> dist(n, 100000);
    dist[0] = 0;
    for (ll i = 0; i < n; i++) {
        iz = 0;
        for (ll j = 0; j < m; j++) {
            if (dist[sv[j].x] != 100000) {
                if (dist[sv[j].y] > (dist[sv[j].x]+sv[j].c)) {
                    iz = 1;
                }
                dist[sv[j].y] = min(dist[sv[j].y], dist[sv[j].x]+sv[j].c);
            }
        }
        if (iz == 0) {
            break;
        }
    }
    for (ll i = 0; i < n; i++) {
        iz = 0;
        for (ll j = 0; j < m; j++) {
            if (dist[sv[j].x] != 100000) {
                if (dist[sv[j].y] > (dist[sv[j].x]+sv[j].c)) {
                    iz = 1;
                    if (sv[j].y == (n - 1)) {
                        cout << ":)";
                        return 0;
                    }
                }
                dist[sv[j].y] = min(dist[sv[j].y], dist[sv[j].x]+sv[j].c);
            }
        }
        if (iz == 0) {
            break;
        }
    }
    if (dist[n - 1] == 100000) {
        cout << ":(";
    } else {
        cout << 0-dist[n - 1];
    }
}
