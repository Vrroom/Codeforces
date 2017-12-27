#include <vector>
#include <iostream>

using namespace std;

class Graph{
    public:
        vector<vector<int> > adj;
        int N;
        Graph(int N){
            this->N = N;
            adj.resize(N);
            for(int i = 0; i < N;i++){
                adj[i].resize(0);
            }
        }    

        void addEdge(int u, int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

};

void DFS(Graph &G, vector<bool> &marked, int &moves, vector<int> &colors, int parent, int source){
    marked[source] = true;
    if(parent == -1){
        moves++;
    }else{
        if(colors[source] != colors[parent]){
            moves++;
        }
    }
    for(int i = 0; i < G.adj[source].size(); i++){
        if(!marked[G.adj[source][i]]){
            DFS(G,marked,moves,colors,source,G.adj[source][i]);
        }
    }

}

int main(){
    int N;
    cin >> N;
    Graph G(N);
    for(int i = 1; i < N;i++){
        int p_i;
        cin >> p_i;
        G.addEdge(i,p_i-1);
    }
    vector<int> colors(N);
    for(int i = 0; i < N; i++){
        cin >> colors[i];
    }
    vector<bool> marked(N,false);
    int moves = 0;
    DFS(G,marked,moves,colors,-1,0);
    cout << moves << endl;
}
