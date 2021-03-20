#include <bits/stdc++.h>
#define ll int64_t
#define elif else if

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n1, n2, n3, n4, no, uk = 0, minn = 1000000000000, min1, min2, min3, min4;
    cin >> n1;
    vector<pair<ll, ll>> arr;
    vector<multiset<ll>> vs(4);
    for (ll i = 0; i < n1; i++) {
        cin >> no;
        arr.push_back({no, 0});
    }
    cin >> n2;
    for (ll i = 0; i < n2; i++) {
        cin >> no;
        arr.push_back({no, 1});
    }
    cin >> n3;
    for (ll i = 0; i < n3; i++) {
        cin >> no;
        arr.push_back({no, 2});
    }
    cin >> n4;
    for (ll i = 0; i < n4; i++) {
        cin >> no;
        arr.push_back({no, 3});
    }
    vs[0].insert(10000000000000);
    vs[1].insert(10000000000000);
    vs[2].insert(10000000000000);
    vs[3].insert(10000000000000);
    sort(arr.begin(), arr.end());
    for (auto i : arr) {
        vs[i.second].insert(i.first);
    }
    for (ll i = 0; i < arr.size(); i++) {
        // while ((uk < (arr.size() - 1)) and ((vs[0].size() == 1) or (vs[1].size() == 1) or (vs[2].size() == 1) or (vs[3].size() == 1))) {
        //     uk++;
        //     vs[arr[uk].second].insert(arr[uk].first);
        // }
        // if ((uk == (arr.size() - 1)) and ((vs[0].size() == 1) or (vs[1].size() == 1) or (vs[2].size() == 1) or (vs[3].size() == 1))) {
        //     break;
        // }
        if (minn > (max(max(*vs[0].begin(), *vs[1].begin()), max(*vs[2].begin(), *vs[3].begin())) -
        min(min(*vs[0].begin(), *vs[1].begin()), min(*vs[2].begin(), *vs[3].begin())))) {
            min1 = *vs[0].begin();
            min2 = *vs[1].begin();
            min3 = *vs[2].begin();
            min4 = *vs[3].begin();
        }
        minn = min(minn, max(max(*vs[0].begin(), *vs[1].begin()), max(*vs[2].begin(), *vs[3].begin())) -
        min(min(*vs[0].begin(), *vs[1].begin()), min(*vs[2].begin(), *vs[3].begin())));
        vs[arr[i].second].erase(vs[arr[i].second].begin());
    }
    cout << min1 << ' ' << min2 << ' ' << min3 << ' ' << min4;
}