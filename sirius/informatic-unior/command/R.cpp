#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	ll w, m, k;
	cin >> w >> m >> k;
	w = w/k;
	ll ans = 0;
	ll s10 = 1, col = 0;
	while (s10 <= m) {
		s10 *= 10;
		col++;
	}
	while (w - (s10 - m)*col >= 0) {
		ans += s10-m;
		w -= (s10-m)*col;
		m = s10;
		s10 *= 10;
		col++;
	}
	ans += w/col;
	cout << ans;
}
