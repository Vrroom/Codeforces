#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int a_i, b_i;
    cin >> a_i >> b_i;
    if(a_i != 0){
        cout << "NO" << endl;
        return 0;
    }else{
        int bmax = b_i;
        for(int i = 0; i < n-1; i++){
            int a_j, b_j;
            cin >> a_j >> b_j;
            if(a_j > bmax){
                cout << "NO" << endl;
                return 0;
            }
            if(b_j > bmax) bmax = b_j;
            a_i = a_j;
        }
        if(m <= bmax){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
