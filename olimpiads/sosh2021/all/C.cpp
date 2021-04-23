#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, inp, mm = 0;
    cin >> n;
    multiset<ll> arr;
    for (ll i = 0; i < n; i++) {
        cin >> inp;
        arr.insert(inp);
    }
    while(! arr.empty()) {
        auto i = arr.begin();
        i++;
        if (*i == *(arr.begin())) {
            arr.insert(*i + *(arr.begin()));
            arr.erase(i);
            arr.erase(arr.begin());
        } else {
            mm = max(mm, *(arr.begin()));
            arr.erase(arr.begin());
        }
    }
    cout << mm;
}