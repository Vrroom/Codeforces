#include <iostream>
using namespace std;
typedef long long ll;
ll digits(ll);
ll pow(ll,ll);
int main(){
    ll n,k;
    cin >> n >> k;
    if(k == 1){
        cout << n << endl;
    }else{
        ll out = pow(2,digits(n)) - 1;
        cout << (out) << endl;
    }
    return 0;
}

ll pow(ll a, ll b){
    ll t = a;
    if(b == 0) return 1;
    while(b > 1){
        a *= t;
        b--;
    }
    return a;
}

ll digits(ll num){
    ll count = 0;
    while(num != 0){
        num = num/2;
        count++;
    }
    return count;
}

