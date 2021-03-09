#include <bits/stdc++.h>
#define ll long long
#define elif else if
#define vecotr vector
using namespace std;

struct pu{
    ll x;
    ll y;
    ll v;
    ll p;
    pu(ll x = 0, ll y = 0, ll v = 0, ll p = 0): x(x), y(y), v(v), p(p) {
    }
  friend istream& operator>> (istream& inp, pu& p);
};

istream& operator>> (istream& inp, pu& p) {
  inp >> p.x >> p.v >> p.y >> p.p;
  return inp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, d, v, r;
    pu p;
    cin >> n >> d >> v >> r;
    vector<pu> arr(0, pu());
    for (ll i = 0; i < r; i++) {
        cin >> p;
        arr.push_back(p);
    }
    vector<ll> da(n + 1, -1);
    da[d] = 0;
    for (ll i = 0; i < n; i++) {
        for (auto j : arr) {
            // cout << da[j.x] << ' ' << j.x << ' ' << j.v << ' ' << da[j.y] << ' ' << j.y << ' ' << j.p << endl;
            if (da[j.x] != -1) {
                if (da[j.x] <= j.v) {
                    if (da[j.y] == -1) {
                        da[j.y] = j.p;
                    } else {
                        da[j.y] = min(da[j.y], j.p);
                    }
                    // cout << j.y << ' ' << da[j.y] << endl;
                }
            }
        }
    }
    cout << da[v];
}
