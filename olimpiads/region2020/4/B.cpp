#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

double loga(ll b, ll a) {   
   double res = 0;
   res = log(a) / log(b);
   return res;
}

int main() {
	ll t,c,m, mid, sum, bp, step,maxx;
	cin >> t;
	vector<ll> pr;
	for (ll i = 2; i < 1000; i++) {
		c = 0;
		for (ll j = 2; j*j <= i; j++) {
			if (i % j == 0) {
				c = 1;
				break;
			}
		}
		if (c == 0) {
			pr.push_back(i);

		}
	}
	for (ll i = 0; i < t; i++) {
		cin >> m;
		maxx = 1;
		vector<ll> v(m+1, -1);
		for (ll j = 0; j < m; j++) {
			cin >> v[j];
		}
		for (ll j = 0; j < m; j++) {
			if (v[j] > v[j+1]) {
				sum = 0;
				while(v[j] > 0) {
					bp = pow(pr[j],floor(loga(v[j]+pr[j]-1,pr[j])));
					sum += bp;
					bp = bp/pr[j];
					v[j] = bp;
					while (bp / pr[j] >= 1) {
						bp = bp/pr[j];
						v[j] += bp;
					}
				}
				maxx = max(maxx, sum);
			}
		}
		cout << maxx << endl;
	}
}