#include <iostream>
#include <vector>
using namespace std;

// Logic is yet to be figured out.
int main(){
    int n;
    cin >> n;
    vector<int> perm(n);
    for(int i = 0; i < n; i++){
        cin >> perm[i];
    }
    int inv_count = 0;
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            if(perm[j] < perm[i]) inv_count = inv_count ^ 1;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int r,l;
        cin >> l >> r;
        int swaps = (r-l+1)/2;
        if(swaps % 2 == 1) inv_count = inv_count ^ 1;
        if(inv_count == 1) cout << "odd" << endl;
        else cout << "even" << endl;
    }
    return 0;
}

