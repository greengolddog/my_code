#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int main() {
    double a;
    long long inp;
    cin >> a;
    vector<long long> arr;
    for (long long i = 0; i < a; i++) {
	cin >> inp;
	arr.push_back(inp);
    }
    sort(arr.begin(), arr.end());
    cout << arr[floor(a/2)];
}

