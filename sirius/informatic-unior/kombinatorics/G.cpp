#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll cnt = 0;

void gen(ll n, vector<ll>& used, vector<ll>& used1, vector<ll>& used2, ll p) {
	if (p == n) {
		cnt++;
		return;
	}
	for (ll i = 0; i < n; i++) {
		if ((!used[i]) && (!used1[i+p]) && (!used2[i-p+n])) {
			used[i] = 1;
			used1[i+p] = 1;
			used2[i-p+n] = 1;
			gen(n, used, used1, used2, p+1);
			used[i] = 0;
			used1[i+p] = 0;
			used2[i-p+n] = 0;
		}
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> used(n*5+1, 0), used1(n*5+1, 0), used2(n*5+1, 0);
	gen(n, used, used1, used2, 0);
	cout << cnt;
}
