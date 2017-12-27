#include <vector>
#include <iostream>
#include <set>
#include <queue>

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

//For the MIN-PQ going to be used in Kruskal
struct Edge{
    int U;
    int V;
    int w;
    int id;
    Edge(int U, int V, int w,int id){
        this->U = U;
        this->V = V;
        this->w = w;
        this->id = id;
    }
    Edge(){
        U = -1;
        V = -1;
        w = -1;
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

struct compareWeight{
    bool operator() (const Edge &e1, const Edge &e2) const{
        return e1.w > e2.w;
    }
};

int main(){
    int N, M;
    cin >> N >> M;
    Graph G(N);
    priority_queue<Edge, vector<Edge>, compareWeight> pq; 
    vector<bool> partOfMST(M,false);
    vector<Edge> edges(M);
    UnionFind conn(N);
    for(int i = 0; i < M; i++){
        int u,v,w;
        cin >> u >> v >> w;
        Edge e(u-1,v-1,w,i);
        edges.push_back(e);
        pq.push(e);
        G.addEdge(u-1,v-1,w);
    }
    int weightSum = 0;
    while(!pq.empty()){
        Edge e = pq.top();
        pq.pop();
        if(!conn.connected(e.U,e.V)){
            weightSum += e.w;
            conn.merge(e.U,e.V);
            if(conn.count() == 1) break;
        }
    }
    cout << weightSum << endl; 
    return 0;
}     
