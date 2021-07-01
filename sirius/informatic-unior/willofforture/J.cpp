#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	cout << m-1 << '\n';
	for (ll i = 0; i < n; i++) {
		for (ll j = 1; j < m; j++) {
			cout << "-1 ";
		}
		cout << "1000\n";
	}
}
