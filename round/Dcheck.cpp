#include <bits/stdc++.h>
#include "testlib.h"
typedef long long ll;

const ll INF = 9'000'000'000'000'000'000;

template<typename T>
bool assign_max(T& a, T b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_min(T& a, T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

using namespace std;

int main(int argc, char* argv[]) {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	registerTestlibCmd(argc, argv);
	quitf(_ok, "OK");
}
