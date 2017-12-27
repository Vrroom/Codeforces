#include <iostream>
#include <vector>

using namespace std;

int main(){
    int h1,a1,c1;
    cin >> h1 >> a1 >> c1;
    int h2,a2;
    cin >> h2 >> a2;
    vector<bool> moves(10000);
    int count = 0;
    while(h2 > 0){
        if(h1 <= a2 && h2 > a1){
            moves[count] = false;
            h1 = h1 + c1 - a2;
        }else{
            moves[count] = true;
            h2 = h2 - a1;
            h1 = h1 - a2;
        }
        count++;
    }
    cout << count << endl;
    for(int i = 0; i < count; i++){
        if(!moves[i]){
            cout << "HEAL" << endl;
        }else{
            cout << "STRIKE" << endl;
        }
    }
    return 0;
}


