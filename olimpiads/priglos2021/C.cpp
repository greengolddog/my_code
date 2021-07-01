#include <bits/stdc++.h>
#define elif else if
using namespace std;
typedef long long ll;
typedef string str;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll k, m, a, b;
	cin >> k >> m >> a >> b;
	cout << (b/k-(a+k-1)/k)-(b/m-(a+m-1)/m);
}
