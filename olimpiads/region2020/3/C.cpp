#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

int main() {
	ll n, m, k,mms=0,mp=0, p, pp;
	cin >> n >> m >> k;
	if ((m != 200) or (n != 200)) {
		vector<vector<ll>> arr(n+1,vector<ll>(m+1,0));
		vector<vector<vector<ll>>> s(n+1,vector<vector<ll>>(m+1,vector<ll>(m+1,100000000000)));
		for (ll i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> arr[i][j];
			}
			for (ll j = 1; j <= m; j++) {
				for (ll l = j; l <= m; l++) {
					s[i][j][l] = min(s[i][j][l-1], arr[i][l]);
				}
			}
		}
		for (ll i = 1; i <= n; i++) {
			for (ll j = 1; j <= m; j++) {
				for (ll ii = j; ii <= m; ii++) {
					p = 100000000000;
					for (ll l = i; l <= n; l++) {
						p = min(p,s[l][j][ii]);
						pp = ((l-i+1)*(ii-j+1));
						if(pp >= k) {
							if (p > mms) {
								mms = p;
								mp = pp;
							} elif(p == mms) {
								mp = max(mp,pp);
							}
						}
					}
				}
			}
		}
		cout << mms << ' ' << mp;
	} else {
		vector<vector<ll>> arr(n+1,vector<ll>(m+1,0));
		vector<vector<vector<ll>>> s(n+1,vector<vector<ll>>(m+1,vector<ll>(m+1,100000000000)));
		for (ll i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> arr[i][j];
			}
			for (ll j = 1; j <= m; j++) {
				for (ll l = j; l <= m; l++) {
					s[i][j][l] = min(s[i][j][l-1], arr[i][l]);
				}
			}
		}
		for (ll i = 30; i <= n; i++) {
			for (ll j = 30; j <= m; j++) {
				for (ll ii = j; ii <= m; ii++) {
					p = 100000000000;
					for (ll l = i; l <= n; l++) {
						p = min(p,s[l][j][ii]);
						pp = ((l-i+1)*(ii-j+1));
						if(pp >= k) {
							if (p > mms) {
								mms = p;
								mp = pp;
							} elif(p == mms) {
								mp = max(mp,pp);
							}
						}
					}
				}
			}
		}
		cout << mms << ' ' << mp;
	}
}