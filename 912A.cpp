#include <iostream>
using namespace std;
typedef long long ll;
int main(){
    ll a,b,x,y,z;
    cin >> a >> b >> x >> y >> z;
    ll yellow = 2*x + y;
    ll blue = y + 3*z;
    ll yl = yellow - a;
    ll bl = blue - b;
    if(yl < 0) yl = 0;
    if(bl < 0) bl = 0;
    cout << bl + yl << endl;
    return 0;
}

