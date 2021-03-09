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
    ll n, x, y, c, max_dist = 0;
    cin >> n;
    vector<point> sv;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n ; j++) {
            cin >> c;
            if ((c > -1) && (i != j)) {
                sv.push_back(point(i, j, c));
            }
        }
    }
    for (ll k = 0; k < n; k++) {
        vector<ll> dist(n, -1);
        dist[k] = 0;
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < sv.size(); j++) {
                if (dist[sv[j].x] != -1) {
                    if (dist[sv[j].y] == -1) {
                        dist[sv[j].y] = dist[sv[j].x]+sv[j].c;
                    } else {
                        dist[sv[j].y] = min(dist[sv[j].y], dist[sv[j].x]+sv[j].c);
                    }
                }
            }
        }
        for (ll i = 0; i < n; i++) {
            if (i != k) {
                max_dist = max(max_dist, dist[i]);
            }
        }
    }
    cout << max_dist;
}
