#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    long double l, r;
    l = 0;
    r = 10;
    for (int i = 0; i < 100; i++) {
        double mid = (l + r) / 2;
        if ((mid*mid*14)+(149*(0-mid))+226 >= 0) {
                l = mid;
        } else {
            r = mid;
        }
    }
    long double x = l;
    cout << x << 7*(x-8*(2*x-3)+5)-6*x << 2*(5*(x-1)-8)+3;
}
