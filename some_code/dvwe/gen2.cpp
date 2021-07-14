#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	srand(time(0));
	ll kmax = 1000000000000000;
	cout << (ll)(((__int128)rand()*rand()*rand()+rand()*rand()+rand())%(kmax+1)) << ' ' << (ll)(((__int128)rand()*rand()*rand()+rand()*rand()+rand())%(kmax+1));
}
