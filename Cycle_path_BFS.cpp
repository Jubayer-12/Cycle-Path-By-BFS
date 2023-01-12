#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj_lst[N];
int visited[N];
int visited2[N];
int parent[N];
vector<int> Cycle_Path;



bool Cycle_Print_DFS(int node){

    visited2[node] = 1;

    for(int adj_node: adj_lst[node]){

        if(!visited2[adj_node]){
            parent[adj_node] = node;
            bool got_cycle = Cycle_Print_DFS(adj_node);
            
            if(got_cycle){

                Cycle_Path.push_back(adj_node);
                return true;
            }
        }

        else if(visited2[adj_node] && parent[node] != adj_node){
            Cycle_Path.push_back(adj_node);
            return true;
        }

    }


    return false;
    
}




bool Cycle_find_BFS(int src){

    visited[src] = 1;
    queue<int> q;
    q.push(src);


    while(!q.empty()){

        int head = q.front();
        q.pop();

        for(int adj_node: adj_lst[head]){

            if(!visited[adj_node]){

                visited[adj_node] = 1;
                q.push(adj_node);
            }
            else if(visited[adj_node] == 1){
                Cycle_Print_DFS(adj_node);
                return true;
            }
        }

        visited[head] = 2;
    }


    return false;
}



int main(){

    int nodes,edges;
    cin>>nodes>>edges;

    for(int i=0; i<edges; i++){

        int u,v;
        cin>>u>>v;

        adj_lst[u].push_back(v);
        adj_lst[v].push_back(u);
    }

    int src = 1;
    parent[src] = -1;

    bool cycle_exist = Cycle_find_BFS(src);
    
    if(cycle_exist) cout<<"Cycle Exist"<<endl;
    else{
        cout<<"No CYcle"<<endl;
        return 0;
    }


    cout<<Cycle_Path.size()<<endl;

    for(int path: Cycle_Path){

        cout<<path<<" ";
    }



    return 0;
}