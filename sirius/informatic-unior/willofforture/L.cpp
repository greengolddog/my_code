#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll l, m;
	cin >> l >> m;
	cout << min(m, (l == 1 ? 0 : l));
}
