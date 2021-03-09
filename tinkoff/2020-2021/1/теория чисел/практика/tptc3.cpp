#include <bits/stdc++.h>
using namespace std;
int main() {
    long long prosx, prosy, perx, pery, x, nowx, nowy, num, summ, b, a;
    cin >> num >> perx >> pery;
    prosx = perx;
    prosy = pery;
    summ = 0;
    for (int i = 1; i < num; i++) {
	cin >> nowx >> nowy;
	a = abs(nowx-prosx);
	b = abs(nowy-prosy);
	x = a;
	a = max(a, b);
	b = min(b, x);
	if (b > 0) {
	    summ += __gcd(a, b);
	} else {
	    summ += a;
	}
	prosx = nowx;
	prosy = nowy;
    }
    a = abs(nowx-perx);
    b = abs(nowy-pery);
    x = a;
    a = max(a, b);
    b = min(b, x);
    if (b > 0) {
	summ += __gcd(a, b);
    } else {
	summ += a;
    }
    cout << summ;
}
