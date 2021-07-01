#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll a, b, c;
	cin >> a >> b >> c;
	if ((a + b + c) % 2 == 1) {
		cout << "NO";
		return 0;
	}
	ll col = (a+b+c)/2;
	if ((a >= col/2) && (b >= col/2) && (c >= col/2)) {
		cout << "YES";
		return 0;
	}
	cout << "NO";
}
