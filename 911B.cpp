#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n,a,b;
    cin >> n >> a >> b;
    int max = 0;
    for(int x = 1; x <= n-1; x++){
       if(max < min(a/x,b/(n-x))) max = min(a/x,b/(n-x));
    } 
    cout << max << endl;
}

