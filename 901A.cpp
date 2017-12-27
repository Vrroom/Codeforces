#include <iostream>
#include <string>
#include <vector>

using namespace std;

void commonTree(int parent,vector<int> &seq, int index){
    for(int i = index; i < seq.size(); i++){
        for(int j = 0; j < seq[i]; j++){
            cout << parent << " ";
        }
        parent += seq[i];
    }
}

int main(){
    int h;
    cin >> h;
    vector<int> seq(h+1);
    for(int i = 0; i < h+1; i++){
        cin >> seq[i];
    }
    bool flag = true;
    for(int i = 0; i < h; i+=1){
        if(seq[i] != 1 && seq[i+1] != 1){
            flag = false;
            break;
        }
    }
    if(flag){
        cout << "perfect" << endl;
    }else{
        cout << "ambiguous" << endl;
        int parent = 1;
        cout << "0 ";
        for(int i = 1; i < seq.size(); i++){
            if(seq[i-1] == 1){
                for(int j = 0; j < seq[i];j++){
                    cout << to_string(parent) << " "; 
                } 
                parent += seq[i];
            }else{
                if(seq[i] == 1){
                    cout << to_string(parent) << " ";
                    parent += seq[i];
                }else{
                    for(int j = 0; j < seq[i]-1; j++){
                        cout << to_string(parent-seq[i-1]+1) << " ";
                    }
                    cout <<  to_string(parent) << " ";
                    commonTree(parent+seq[i],seq,i+1);
                    cout << "\n";
                    break;
                }
            }
        }
        parent = 1;
        cout << "0 ";
        for(int i = 1; i < seq.size(); i++){
            if(seq[i-1] == 1){
                for(int j = 0; j < seq[i];j++){
                    cout << to_string(parent) << " "; 
                } 
                parent += seq[i];
            }else{
                if(seq[i] == 1){
                    cout << to_string(parent) << " ";
                    parent += seq[i];
                }else{
                    for(int j = 0; j < seq[i]-1; j++){
                        cout << to_string(parent-seq[i-1]+1) << " ";
                    }
                    cout << to_string(parent-seq[i-1]+1) << " ";
                    commonTree(parent+seq[i],seq,i+1);
                    cout << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}
