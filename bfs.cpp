#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5;
vector<int> gr[maxN + 3];
vector<int> vis(maxN + 3, 0);
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int nbr : gr[node])
        {
            if (!vis[nbr])
            {
                vis[nbr] = 1;
                q.push(nbr);
            }
        }
    }
}
int main()
{
    // int n, m;
    // cin >> n >> m;

    // vector<int> A[5];


    // for(int i=0;i<5;i++)
    // {
    //     A[i]=vector<int> (3);
    //     for(int j=0;j<3;j++) cout<<A[i][j]<<" ";
    // }


    // for (int i = 0; i < n; i++)
    // {
    //     int a, b;
    //     cin >> a >> b;
    //     gr[a].push_back(b);
    //     gr[b].push_back(a);
    // }
    // int cc = 0;
    // for (int node = 1; node <= n; node++)
    // {
    //     if (!vis[node])
    //     {
    //         bfs(node);
    //         cc++;
    //     }
    // }
    // cout << cc << endl;
    cout<<5<<endl;
    return 0;
}