#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int a, b, s;
    cin >> a >> b;
    vector<int> arr(b + 4, 1);
    vector<int> arr2;
    s = 0;
    for (int i = 2; i <= (b + 3); i++) {
	if (arr[i] == 1) {
	    for (int j = i*2; j <= b + 3; j += i) {
		arr[j] = 0;
	    }
	    arr2.push_back(i);
	}
    }
    arr2.push_back(10);
    for (int i = 1; i < (arr2.size() - 1); i++) {
	if ((arr2[i] - arr2[i - 1] == 2) || (arr2[i + 1] - arr2[i] == 2)) {
	    if ((arr2[i] >= a) && (arr2[i] <= b)) {
		s += 1;
	    }
	}
    }
    cout << s;
}