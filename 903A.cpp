#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x >= 12){
            cout << "YES" << endl;
        }else if(x < 3 || (x > 3 && x < 7 && x!=6) || x == 8 || x == 11){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
}
