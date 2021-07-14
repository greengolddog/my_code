#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	ll a, b, ans = 1;
	cin >> a >> b;
	const ll mod = 1000000007;
	for (ll i = a+b; i > b; i++) {
		ans = (ans*i)%mod;
	}
}
