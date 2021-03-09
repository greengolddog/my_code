#include <bits/stdc++.h>
#define ll int64_t
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, mn, pr, nm, mm, k;
    cin >> n >> k;
    m = 0;
    vector<ll> arr2(k + 1);
    for (ll i = 1; i < k; i++) {
	
    }
    vector<pair<ll, ll>> arr(n + 1, {0, 0});
    for (ll i = 1; i < (n + 1); i++) {
	mn = 1;
	pr = 0;
	for (ll j = 1; j < i; j++) {
	    if (arr2[i] > arr2[j]) {
		if (mn < (arr[j].first + 1)) {
		    mn = arr[j].first + 1;
		    pr = j;
		}
	    }
	}
	arr[i] = {mn, pr};
	
    }
    cout << m << endl;
}
