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
    ll n, x, y, c;
    cin >> n;
    vector<point> sv;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n ; j++) {
            cin >> c;
            if (c != 0) {
                sv.push_back(point(i, j, c));
            }
        }
    }
    for (ll k = 0; k < n; k++) {
        vector<ll> dist(n, 10000000000);
        vector<ll> krat(n, 0);
        dist[k] = 0;
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < sv.size(); j++) {
                if (dist[sv[j].x] != 10000000000) {
                    if (dist[sv[j].y] == 10000000000) {
                        dist[sv[j].y] = dist[sv[j].x]+sv[j].c;
                    } else {
                        dist[sv[j].y] = min(dist[sv[j].y], dist[sv[j].x]+sv[j].c);
                    }
                }
            }
        }
        for (ll i = 0; i < n; i++) {
            if (dist[i] != 10000000000) {
                krat[i] = 1;
            }
        }
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < sv.size(); j++) {
                if (dist[sv[j].x] != 10000000000) {
                    if (dist[sv[j].y] == 10000000000) {
                        dist[sv[j].y] = dist[sv[j].x]+sv[j].c;
                    } else {
                        if (dist[sv[j].y] > (dist[sv[j].x]+sv[j].c)) {
                            krat[sv[j].y] = 2;
                        }
                        dist[sv[j].y] = min(dist[sv[j].y], dist[sv[j].x]+sv[j].c);
                    }
                }
            }
        }
        for (ll i = 0; i < n; i++) {
            cout << krat[i] << ' ';
        }
        cout << endl;
    }
}
