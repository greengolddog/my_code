#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    vector<ll> arr(3, a);
    arr[1] = b;
    arr[2] = c;
    sort(arr.begin(), arr.end());
    cout << max(0ll, max(arr[1] - arr[0] - 1, arr[2] - arr[1] - 1));
}