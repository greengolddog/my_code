#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MAXN = 1000000000000;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> arr(n+3, 0);
	ll a1 = MAXN, b1 = MAXN, c1 = MAXN, b2 = MAXN, c2 = MAXN, c3 = MAXN;
	for (ll i = 3; i < n+3; i++) {
		b2 = b1;
		c3 = c2;
		c2 = c1;
		cin >> a1 >> b1 >> c1;
		arr[i] = min(arr[i-1]+a1, min(arr[i-2]+b2, arr[i-3]+c3));
	}
	cout << arr[n+2];
}
