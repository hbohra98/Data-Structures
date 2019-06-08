//BFS of a graph complexity o(V+E) 
#include<bits/stdc++.h>
using namespace std;
//Adjacency list and visited list
vector<vector<int>> grp;
vector<bool> visi;
// add edge in the graph
void edge(int a ,int b){
     grp[a].push_back(b);
}
// Breadth first search
void bfs(int n){
     queue<int>q;
     q.push(n);
     visi[n]=true;
     while(!q.empty()){
          int f=q.front();
          cout<<f<<" ";
          q.pop();
          for(int w:grp[n]){
               if(!visi[w])
          {
               q.push(w);visi[w]=true;

          }
     }}
}
int main(){
     int n,e;
     cin>>n>>e;
     grp.assign(n,vector<int>());
     visi.assign(n,false);
     //here the grpah input begin
     for(int i=0;i<e;i++){
          int a,b;
          cin>>a>>b;
          edge(a,b);
     }
     //here the bfs begins
     for(int i=0;i<n;i++){
          if(!visi[i]){
               bfs(i);
          }
     }
}
