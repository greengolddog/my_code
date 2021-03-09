#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, k, sum;
    string st;
    cin >> n >> k;
    sum = n;
    cin >> st;
    vector<ll> arr(n, 0);
    vector<ll> arr2(n, 0);
    vector<ll> arr3(n, 0);
    for (ll i = 2; i <= n; i++) {
	for (ll j = 0; j < (n - i + 1); j++) {
	    if (st[j] == st[j + i - 1]) {
		arr3[j] = arr[j + 1];
	    } else {
		arr3[j] = arr[j + 1] + 1;
	    }
	    if (arr3[j] <= k) {
		sum++;
	    }
	}
	arr = arr2;
	arr2 = arr3;
    }
    cout << sum;
}
