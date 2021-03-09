#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    long long a, b;
    int now;
    cin >> a >> b;
    vector<long long> arr(a, 0);
    for (long long i = 0; i < a; i++) {
	cin >> arr[i];
    }
    for (long long i = 0; i < b; i++) {
	cin >> now;
	int l = 0;
	int r = a - 1;
	while (r - l > 1) {
	    int mid = (r + l) / 2;
	    if (arr[mid] <= now) {
		l = mid;
	    } else {
		r = mid;
	    }
	}
	if (abs(now - arr[l]) <= abs(arr[r] - now)) {
	    cout << arr[l] << endl;
	} else {
	    cout << arr[r] << endl;
	}
    }
}