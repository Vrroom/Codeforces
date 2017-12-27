#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll cycle_length(vector<int> &p, vector<bool> &marked, int source){
    ll len = 0;
    while(!marked[p[source]]){
        len++;
        marked[p[source]] = true;
        source = p[source];
    }
    return len;
}

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
        p[i] = p[i] - 1;
    }
    vector<bool> marked(n,false);
    ll sum = 0;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    vector<ll> nlen;
    for(int i = 0; i < n;i++){
        if(!marked[i]){
            ll len = cycle_length(p,marked,i);
            nlen.push_back(len);
            sum += len*len;
        }
    }
    if(nlen.size() == 1){
        cout << sum << endl;
    }else{
        ll max = nlen[0], smax = 0;
        for(int i = 1; i < nlen.size(); i++){ 
            if(nlen[i] >= smax){
                smax = nlen[i];
            }
            if(nlen[i] >= max){
                smax = max;
                max = nlen[i];
            }
        }
        cout << sum + 2*smax*max << endl;
    }
}

