#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n;
    string x;
    vector<string> arr;
    n = 0;
    while (cin >> x) {
	arr.push_back(x);
	n++;
    }
    for (int i = n - 1; i > -1; i--) {
	for (int j = 0; j < i; j++) {
	    if ((arr[j]+arr[j+1]) < (arr[j+1]+arr[j])) {
		swap(arr[j], arr[j+1]);
	    }
	}
    }
    for (int i = 0; i < n; i++) {
	cout << arr[i];
    }
}