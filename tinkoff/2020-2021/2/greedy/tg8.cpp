#include <bits/stdc++.h>
#define ll long long
#define elif else if

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> arr(n, 0), ac(n, 0);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    set<pair<ll, ll>> col;
    for (ll i = 0; i < n; i++) {
        auto it = col.lower_bound({arr[i], 0});
        if (it == col.begin()) {
            col.insert({arr[i], col.size()+1});
            // cout << arr[i] << ' ' << col.size() << endl;
            ac[i] = col.size();
        } else {
            it--;
            auto n2 = *it;
            col.erase(it);
            // cout << '-' << n2.first << ' ' << n2.second << endl;
            col.insert({arr[i], n2.second});
            // cout << arr[i] << ' ' << n2.second << endl;
            ac[i] = n2.second;
        }
    }
    cout << col.size() << endl;
    for (ll i = 0; i < n; i++) {
        cout << ac[i] << ' ';
    }
}
