#include<bits/stdc++.h>
#include "perm.h"
typedef long long ll;
using namespace std;

std::vector<int> construct_permutation(long long k)
{
	k--;
	vector<ll> sk;
	while (k > 0) {
		sk.push_back(k % 2);
		k /= 2;
	}
	reverse(sk.begin(), sk.end());
	deque<ll> d;
	bool b = false, bn = false;
	ll cole = 0;
	for (ll i = 0; i < sk.size() - 1; i++) {
		if (sk[i] == 1) {
			cole++;
			if (sk[i + 1] == 1 || (i != 0 && sk[i - 1] == 1)) {
				if (bn) {
					d.push_front(d.size());
				}
				bn = false;
				d.push_back(d.size());
				if (sk[i + 1] == 1) {
					d.push_front(d.size());
				}
				b = false;
			} else {
				d.push_front(d.size());
				if (cole > 1) {
					d.push_back(d.size());
				} 
				b = true;
			}
		} else {
			d.push_back(d.size());
			bn = true;
		}
	}
	if (sk.back() == 1) {
		if (sk[sk.size() - 2] == 0) {
			if (b && cole > 1) {
				d.push_front(d.size());
				d.push_front(d.size());
			} else {
				d.push_front(d.size());
				d.push_front(d.size());
			}
		} else {
			d.push_front(d.size());
		}
	} else {
		//d.push_back(d.size());
		if (b && cole == 0) {
			d.push_back(d.size());
			d.push_front(d.size());
		} else {
			d.push_front(d.size());
		}
	}
	vector<int> ans;
	for (auto i : d) {
		ans.push_back(i);
	}
	return ans;
}
