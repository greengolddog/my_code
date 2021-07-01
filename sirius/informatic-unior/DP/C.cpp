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
	vector<ll> arr(n+1, 0), all(n, 0);
	for (ll i = 1; i <= min(9ll, n); i++) {
		ll no;
		cin >> no;
		arr[i] = arr[i-1]+no;
		all[i-1] = no;
	}
	for (ll i = 10; i <= n; i++) {
		ll now;
		cin >> now;
		arr[i] = arr[i-1]+now;
		ll nn = now, summ = now;
		for (ll j = i-9; j < i; j++) {
			nn = min(nn, all[j-1]);
			summ += all[j-1];
		}
		all[i-1] = now;
		arr[i] = min(arr[i], arr[i-10]+summ-nn);
	}
	cout << arr[n];
}
