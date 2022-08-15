#include<bits/stdc++.h>
using namespace std;
#define WHITE 1
#define GRAY 2
#define BLACK 3
int color[100];
int adj[100][100];
int dist[100];
int parent[100];
int node, edge;


void bfs(int startingNode){
 for(int i = 0; i < node; i++){
    color[i] = WHITE;
    dist[i] = INT_MIN;
    parent[i] = -1;
 }

 dist[startingNode] = 0;
 parent[startingNode] = - 1;

 queue<int> q;
 q.push(startingNode);

 while(!q.empty()){
    int x;
    x = q.front();
    q.pop();
    color[x] = GRAY;

    for(int i = 0; i < node; i++){
        if(adj[x][i] == 1){
            if(color[i] == WHITE){
                    // x er neighbor i
                    // x node is parent of i node
                    dist[i] = dist[x] + 1;
                    parent[i] = x;
                 q.push(i);
            }
        }
    }


    color[x] = BLACK;
 }
}

int main(){

cout << "Enter number of node : ";
cin >> node;
cout << "Enter number of edge : ";
cin >> edge;

int n1,  n2;

for(int i = 0; i < edge; i++){
    cin >> n1 >> n2;
    adj[n1][n2] = 1;
    adj[n2][n1] = 1;
}

return 0;
}
