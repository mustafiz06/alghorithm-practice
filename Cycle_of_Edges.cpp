#include <bits/stdc++.h>
using namespace std;

int parent[100005];
int huntParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = huntParent(parent[x]);
}

int main(){
    int n,e;
    cin >> n >> e;
    for(int i=1;i<=n;i++)
        parent[i] = i;

    int cycle = 0;
    while(e--){
        int x,y;
        cin >> x >> y;
        int px = huntParent(x);
        int py = huntParent(y);

        if(px == py) cycle++;
        else parent[px] = py;
    }
    cout << cycle;
}