#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll nod(ll a, ll b) {
	if (min(a, b) == 0) {
		return max(a, b);
	}
	return nod(max(a, b)%min(a, b), min(a, b));
}

ll nok(ll a, ll b) {
	return a*b/nod(a, b);
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	ll ans;
	cin >> ans;
	for (ll i = 1; i < n; i++) {
}
