#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];

        int l = 0, r = n-1;
        int mx = -1, x = 0, y = 0;

        while(l < r){
            int h = min(a[l], a[r]);
            if(h > mx){
                mx = h;
                x = l;
                y = r;
            }
            if(a[l] < a[r]) l++;
            else r--;
        }
        cout << x << " " << y << endl;
    }
}