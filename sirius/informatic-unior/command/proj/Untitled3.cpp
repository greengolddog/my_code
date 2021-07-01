#include <bits/stdc++.h>
typedef long long ll;

using namespace std;


int gcd(int a,int b)
{
    if(a == 0 || b == 0)
        return max(a,b);
    if(a > b)
        swap(a,b);
    return gcd(a,b%a);
}

vector<int64_t> segTree;

vector<int64_t> a;

void build(int indV,int l,int r)
{
    if(l == r)
    {
        segTree[indV] = a[l];
        return ;
    }
    int m = (l+r)/2;
    build(indV*2+1,l,m);
    build(indV*2+2,m+1,r);
    segTree[indV] = gcd(segTree[indV*2+1],segTree[indV*2+2]);
    return ;
}

int get(int lx,int rx,int l,int r,int indV)
{
    if(l > rx || r < lx)
        return 0;
    else if(l >= lx && r <= rx)
        return segTree[indV];
    int m = (l+r)/2;
    int sl =get(lx,rx,l,m,indV*2+1);
    int sr =get(lx,rx,m+1,r,indV*2+2);
    return gcd(sl,sr);
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;++i)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    map<int64_t,int64_t> el;
    segTree.resize(4*n);
    build(0,0,n-1);
    int64_t l = 0;
    vector<int64_t> res;
    int64_t mrl = 0;
    for(int r = 0;r < n;++r)
    {
        el[a[r]] ++;
        while((*el.begin()).first != get(l,r,0,n-1,0))
        {

            el[a[l]] --;
            if(el[a[l]] == 0)
                el.erase(a[l]);
            l++;
        }
        if(r-l == mrl)
            res.push_back(l);
        else if(r-l > mrl)
        {
            mrl = r-l;
            res.clear();
            res.push_back(l);
        }

    }
    cout << res.size() << ' ' << mrl << "\n";
    for(int i = 0;i < res.size();++i)
    {
        cout << res[i]+1 << ' ';
    }
    return 0;
}

