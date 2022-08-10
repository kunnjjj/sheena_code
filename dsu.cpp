#include <bits/stdc++.h>
using namespace std;

class dsu
{
    vector<int> par;
    vector<int> sz;
    int cc;
    int n;
public:
    dsu(int N)
    {
        n=N;
        par=vector<int> (n);
        sz=vector<int> (n,1);
        for(int i=0;i<n;i++) par[i]=i;
        cc=n;      
    }

    int get_par(int i)
    {
        if(par[i]==i) return i;  //If I am pointing to myself then i am the super parent
        return par[i]=get_par(par[i]); // call the parent for my parent
        // change my parent to super parent
    }
    void add_edge(int a,int b)
    {
        int par_a=get_par(a);
        int par_b=get_par(b);

        if(par_a!=par_b) // they are in different cc
        {
            if(sz[par_a] < sz[par_b])
            {
                swap(par_a,par_b);
            }
            par[par_b]=par_a;
            sz[par_a]+=sz[par_b];
            cc--;
        }
    }
    int number_of_component()
    {
        return cc;
    }
    int size_of_component(int i)
    {
        int par_i=get_par(i);
        return sz[par_i];
    }
};

int main()
{

    int n; cin>>n;
    n*=2;
    dsu d(n);
    
    for(int i=0;i<n/2;i++)
    {
        int a,b; cin>>a>>b;
        a--;
        b--;
        d.add_edge(a,b);
    }
    vector<int> sz;
    for(int i=0;i<n;i++)
    {
        int z=d.size_of_component(i);
        if(z!=1)
        sz.push_back(z);
    }
    
    sort(sz.begin(),sz.end());
    cout<<sz[0]<<" "<<sz.back()<<endl;

    

    return 0;
}