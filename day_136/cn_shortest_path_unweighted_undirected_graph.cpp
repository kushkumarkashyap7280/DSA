// Problem - Shortest Path in an Unweighted Undirected Graph

//link -https://www.naukri.com/code360/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTabValue=PROBLEM

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t) {
   vector<vector<int>> adj(n+1);

   for(auto &p :  edges){
       adj[p.first].push_back(p.second);
       adj[p.second].push_back(p.first);
   }

   vector<int> isVisted(n+1 , 0), parent(n+1 , -1);

   queue<int> q;

   q.push(s);
   isVisted[s]=1;
   parent[s] = -1;

   while(!q.empty()){
       int curr = q.front();
       q.pop();
       if(curr == t) break;
      for(int neighbour : adj[curr]){
          if(!isVisted[neighbour]){
              q.push(neighbour);
              isVisted[neighbour] = 1;
              parent[neighbour] = curr;
          }
      }

   }

   vector<int> sp;

   int curr = t;

   while(curr != -1){
       sp.push_back(curr);
       curr = parent[curr];
   }

   reverse(sp.begin(),sp.end());

   if(sp.front() == s){
       return sp;
   }
  
  return {};

}
