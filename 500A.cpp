#include <vector>
#include <iostream>

using namespace std;
//To define weights between each pair of vertices.
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

    void addDirectedEdge(int u, int v, int w){
        Vertex v2(v,w);
        adj[u].push_back(v2);
    }
};

int main(){
    int n,t;
    cin >> n >> t;
    Graph G(n);
    for(int i = 0; i < n-1; i++){
        int a_i;
        cin >> a_i;
        G.addDirectedEdge(i,i+a_i,1);
    }
    int station = 0;
    while(station <= t-1){
        if(station == t-1){
            cout << "YES" << endl;
            return 0;
        }
        station = G.adj[station][0].V;
    }
    cout << "NO" << endl;
} 
