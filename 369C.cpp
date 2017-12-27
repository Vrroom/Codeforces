#include <vector>
#include <iostream>
#include <utility>
using namespace std;
struct Vertex{
    int V;
    int w;
    Vertex(){
        V = -1;
        w = -1;
    }
    Vertex(int V, int w){
        this->V = V;
        this->w = w;
    }
};

class Graph{
    public:
        vector<vector<Vertex> > adj;
        int N;
        Graph(int N){
            this->N = N;
            vector<vector<Vertex> > ini(N);
            adj = ini;
            for(int i = 0; i < N; i++){
                vector<Vertex> init;
                adj[i] = init ;
            }
        }    

        void addEdge(int u, int v, int w){
            Vertex v1(u,w);
            Vertex v2(v,w);
            adj[u].push_back(v2);
            adj[v].push_back(v1);
        }
};

bool DFS(int s, Graph &G, vector<bool> &marked, vector<bool> &subset){
    marked[s] = true;
    if(G.adj[s].size() == 1 && marked[G.adj[s][0].V]){
        if(G.adj[s][0].w == 2){
            subset[s] = true;
            return true;
        }else{
            return false;
        } 
    }
    bool extraRequired = false;
    for(int i = 0; i < G.adj[s].size(); i++){
        if(!marked[G.adj[s][i].V]){
            bool flag = DFS(G.adj[s][i].V,G,marked,subset);
            if(!flag){
                if(G.adj[s][i].w == 2){
                    subset[G.adj[s][i].V] = true;
                    extraRequired = extraRequired || true;
                }else{
                    extraRequired = extraRequired || false;
                }
            }else{
                extraRequired = flag;
            }
        }
    }
    return extraRequired;
}

int main(){
    int n;
    cin >> n;
    Graph G(n);
    for(int i = 0; i < n-1; i++){
        int u,v,t;
        cin >> u >> v >> t;
        G.addEdge(u-1,v-1,t);
    }
    vector<bool> marked(n,false);
    vector<bool> subset(n,false);
    DFS(0,G,marked,subset);
    int count = 0;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        if(subset[i]){
            count++;
            nums.push_back(i+1);
        }
    }
    cout << count << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
