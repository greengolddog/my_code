#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int b, s;
    cin >> b;
    vector<int> arr(b + 1, 1);
    vector<int> arr2;
    s = 0;
    for (int i = 2; i <= b; i++) {
	if (arr[i] == 1) {
	    for (int j = i*2; j <= b; j += i) {
		arr[j] = 0;
	    }
	    arr2.push_back(i);
	    for (int j = 0; j < arr2.size(); j++) {
		if (i + arr2[j] == b) {
		    cout << i << ' ' << arr2[j];
		    s = 1;
		    break;
	        }
	    }
	}
	if (s == 1) {
	    break;
	}
    }
}