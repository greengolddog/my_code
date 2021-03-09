#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, b, s, f;
    cin >> n >> s >> f;
    vector<vector<pair<ll, ll>>> sv(n, vector<pair<ll, ll>>(0, {0, 0}));
    s--;
    f--;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> b;
            if (b > 0) {
                sv[i].push_back({j, b});
            }
        }
    }
    vector<ll> dist(n, 10000000000000);
    vector<ll> used(n, 0);
    dist[s] = 0;
    for (ll i = 0; i < n; ++i) {
        ll v = -1;
        for (ll j = 0; j < n; ++j) {
            if (used[j] != 0) continue;
            if (v == -1 || dist[v] > dist[j]) {
                v = j;
            }
        }
        used[v] = 1;
        for (auto j : sv[v]) {
            if (dist[j.first] > dist[v] + j.second) {
                dist[j.first] = dist[v] + j.second;
            }
        }
    }
    if (dist[f] == 10000000000000) {
        cout << -1;
    } else {
        cout << dist[f];
    }
}