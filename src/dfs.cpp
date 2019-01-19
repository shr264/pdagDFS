#include <Rcpp.h>
using namespace Rcpp;

void dfs_visit2(NumericMatrix G,int u, int *color,int &found_cycle, int size){
  if(found_cycle==1){
    return;
  }
  color[u] = 1;
  for(int v = 0;v<size;v++){
    if(G(v,u)==1){
      if(color[v]==1){
        found_cycle = 1;
        return;
      }
      if(color[v]==0){
        dfs_visit2(G,v,color,found_cycle,size);
      }
    }
  }
  color[u] = 2;
}

// [[Rcpp::export]]
int dfs2(NumericMatrix G, int size){
  int color[size];
  for (int u = 0; u<size; u++){
    color[u] = 0;
  }
  int found_cycle = 0;
  for (int u = 0; u<size; u++){
    if(color[u]==0){
      dfs_visit2(G,u,color,found_cycle,size);
    }
    if(found_cycle){
      break;
    }
  }
  return found_cycle;
}