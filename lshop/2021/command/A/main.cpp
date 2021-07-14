#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
		ll n;
		cin >> n;
		vector<ll> v1(n), v2(n);
		vector<pair<ll, ll>> coms;
		for (ll i = 0; i < n; i++) {
			cin >> v1[i];
			v1[i]--;
		}
		for (ll i = 0; i < n; i++) {
			cin >> v2[i];
			v2[i]--;
		}
		map<ll, ll> m1, m2;
		for(int i = 0; i < n; i++) {
            m1[v1[i]]++;
            m2[v2[i]]++;
            if(m1[v1[i]]==2){
                coms.push_back({i, i});
                m1[v1[i]]--;
                m2[v2[i]]--;
                m1[v2[i]]++;
                m2[v1[i]]++;
                swap(v1[i], v2[i]);
            }
            if(m2[v2[i]]==2){
                coms.push_back({i, i});
                m1[v1[i]]--;
                m2[v2[i]]--;
                m1[v2[i]]++;
                m2[v1[i]]++;
                swap(v1[i], v2[i]);
            }
		}
		vector<ll> c1(n), c2(n);
		for(int i=0;i<n;i++){
            c1[v1[i]]=i;
            c2[v2[i]]=i;
		}
		for(int i=0;i<n;i++) {
            if(v1[i]!=i){
                ll now=v1[i], it=c1[i];
                coms.push_back({c1[i], i});
                coms.push_back({i, i});
                coms.push_back({c1[i], i});
                swap(v1[i], v1[c1[i]]);
                c1[i] = i;
                c1[now] = it;
            }
            if(v2[i] != i){
                ll now = v2[i], it = c2[i];
                coms.push_back({i, c2[i]});
                coms.push_back({i, i});
                coms.push_back({i, c2[i]});
                swap(v2[i], v2[c2[i]]);
                c2[i]=i;
                c2[now]=it;
            }
		}
		cout<<coms.size()<<endl;
		for(int i=0;i<coms.size(); i++){
            cout<<coms[i].first + 1<<" "<< coms[i].second + 1<<endl;
		}
}

