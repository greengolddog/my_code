#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int a, in, musor, len;
    cin >> a;
    vector<int> arr(a, 2000000000);
    for (int i = 0; i < a; i++) {
        cin >> len;
        for (int j = 0; j < len; j++) {
            cin >> in >> musor;
            arr[i] = min(in, arr[i]);
	}
    }
    for (int i = 0; i < a; i++) {
        int sum = 0;
        for (int j = 0; j < a; j++) {
            if (arr[j] < arr[i]) {
		sum++;
	    }
	}
	cout << sum << ' ';
    }
}

