#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    long long a, b;
    cin >> a >> b;
    vector<double> arr(a, 0);
    for (int i = 0; i < a; i++) {
        cin >> arr[i];
    }
    vector<double> arr2(b, 0);
    for (int i = 0; i < b; i++) {
        cin >> arr2[i];
    }
    long long l, r;
    for (int i = 0; i < b; i++) {
        l = 0;
        r = a;
        if (a > 2) {
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (arr[mid] <= arr2[i]) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            if (r == a) {
                cout << arr[l] << endl;
            } else {
                if (abs(arr2[i] - arr[l]) <= abs(arr2[i] - arr[r])) {
                    cout << arr[l] << endl;
                } else {
                    cout << arr[r] << endl;
                }
            }
        } else {
            if (a == 2) {
                if (abs(arr2[i] - arr[0]) <= abs(arr2[i] - arr[1])) {
                    cout << arr[0] << endl;
                } else {
                    cout << arr[1] << endl;
                }
            } else {
                cout << arr[0] << endl;
            }
        }
    }
}