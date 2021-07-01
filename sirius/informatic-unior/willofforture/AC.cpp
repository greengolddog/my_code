#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll x11, x12, x21, x22, y11, y12, y22, y21;
	cin >> x11 >> y11 >> x12 >> y12 >> x21 >> y21 >> x22 >> y22;
	cout << ((((x11 >= x21) && (x11 <= x22) && (y11 >= y21) && (y11 <= y22)) || ((x12 >= x21) && (x12 <= x22) && (y12 >= y21) && (y12 <= y22)) || ((x21 >= x11) && (x21 <= x12) && (y21 >= y11) && (y21 <= y12)) || ((x22 >= x11) && (x22 <= x12) && (y22 >= y11) && (y22 <= y12))) ? "YES" : "NO");
}
