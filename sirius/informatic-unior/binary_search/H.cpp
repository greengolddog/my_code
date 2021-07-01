#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    int vp, vf;
    double a, l, r;
    cin >> vf >> vp >> a;
    l = 0;
    r = 1;
    for (int i; i < 100; i++) {
        double mid1 = l + ((r - l) / 3);
        double mid2 = l + ((r - l) / 3 * 2);
        double sum1 = sqrt((mid1*mid1)+((1-a)*(1-a)))*vp+sqrt(((1-mid1)*(1-mid1))+(a*a))*vf;
        double sum2 = sqrt((mid2*mid2)+((1-a)*(1-a)))*vp+sqrt(((1-mid2)*(1-mid2))+(a*a))*vf;
        if (sum1 >= sum2) {
            l = mid1;
        } else {
            r = mid2;
        }
    }
    cout << l;
}
