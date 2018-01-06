#include <iostream>
#include <string>

using namespace std;

int main(){
    string first,last;
    cin >> first >> last;
    int i;
    for(i = 1; i < first.size(); i++){
        if(first[i] >= last[0]) break;
    }
    cout << first.substr(0,i) << last[0] << endl;
    return 0;
}

