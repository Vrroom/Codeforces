#include <iostream>
using namespace std;

typedef long long ll;

void bString(ll n, ll k){
    if(n==0) cout << "";
    else if(k >= n-1){
        cout << "(";
        bString(n-1, k-(n-1));
        cout << ")";
    }else{
        cout << "()"; 
        bString(n-1,k);
    }
}

int main(){
    ll n, k;
    cin >> n >> k;
    if(k > ((n-1)*n)/2){
        cout << "Impossible" << endl;
    }else{
        bString(n,k);
        cout << endl;
    }
    return 0;
}
    
