#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

int main() {
	ll n, t,l,r,k,maxi;
	cin >> n;
	vector<pair<ll,ll>> arr(n,{0,0});
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	cin >> t;
	for (ll i = 0; i < t; i++) {
		cin >> l >> r >> k;
		maxi = arr[l-1].first+(arr[l-1].second*(k-1));
		for (ll j = l; j < r; j++) {
			maxi = min(maxi, (arr[j].first+(arr[j].second*(k-1)))/1);
		}
		cout << maxi << endl;
	}
}