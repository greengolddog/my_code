#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

struct apple {
    ll x;
    ll y;
    ll z;
    ll r;
    apple(ll x = 0, ll y = 0, ll z = 0, ll r = 0): x(x), y(y), z(z), r(r) {
    }
    bool per(apple a) {
        return ((z > a.z) && (((x - a.x) * (x - a.x)) + ((y - a.y) * (y - a.y)) <= (r*r + a.r*a.r + r*a.r*2)));
    }
    friend istream& operator>> (istream& inp, apple& a);
};

istream& operator>> (istream& inp, apple& a) {
    inp >> a.x >> a.y >> a.z >> a.r;
    a.z -= a.r;
    return inp;
}

void dfs(vector<ll>& b, vector<vector<ll>>& arr, ll v) {
    b[v] = 1;
    for (auto i : arr[v]) {
        if (b[i] == 0) {
            dfs(b, arr, i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, stc = 0;
    cin >> n;
    vector<vector<ll>> arr(n, vector<ll>(0, 0));
    vector<apple> apples(n, apple());
    for (ll i = 0; i < n; i++) {
        cin >> apples[i];
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (apples[i].per(apples[j])) {
                arr[i].push_back(j);
                // cout << i << ' ' << j << endl;
            }
        }
    }
    vector<ll> used(n, 0);
    dfs(used, arr, 0);
    for (ll i = 0; i < n; i++) {
        if (used[i]) {
            stc++;
        }
    }
    cout << stc << endl;
    for (ll i = 0; i < n; i++) {
        if (used[i]) {
            cout << i + 1 << ' ';
        }
    }
}
