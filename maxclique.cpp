#include <bits/stdc++.h>
using namespace std;

struct Node {
public:
    int color;
    int lambda;
    bool visited;
    vector<int> edges;
};


Node G[600];
bool processed[600];

vector<int> ordering(Node G[600],int n){

    for(int i=0;i<n;i++){
        processed[i]=false;
    }
    int idx=0;
    int maximum=0;
    vector<int> ordered_vertices;
    ordered_vertices.push_back(1);

    for(int i=0;i<n-1;i++){
        int m=G[idx].edges.size();
        for(int k=0;k<m;k++){
            if(processed[G[idx].edges[k]-1]==false){
                G[G[idx].edges[k]-1].lambda+=1;
            }
        }
        processed[idx]=true;
        idx=-1;
        maximum=-1;
        for(int j=0;j<n;j++){
            if(processed[j]==false){
                if(G[j].lambda>maximum){
                    maximum=G[j].lambda;
                    idx=j;
                }
            }
        }
        ordered_vertices.push_back(idx+1);
    }
    return ordered_vertices;
}
int maxcliquesize(Node G[600],int n){
    vector<int> ordered_vertices=ordering(G,n);
    G[ordered_vertices[0]-1].color=0;

    int used_colors=1;
    bool available[n];
    for(int i=0;i<n;i++){
        available[i]=true;
    }
    for(int i=1;i<n;i++){

        int n=G[ordered_vertices[i]-1].edges.size();
        for(int j=0;j<n;j++){
            if(G[G[ordered_vertices[i]-1].edges[j]-1].color!=-1){
                available[G[G[ordered_vertices[i]-1].edges[j]-1].color]=false;
            }
        }

        int k=0;
        while(available[k]==false){
            k+=1;
        }
        G[ordered_vertices[i]-1].color=k;
        if(k+1>used_colors){
            used_colors=k+1;
        }
        for(int j=0;j<n;j++){
            if(G[G[ordered_vertices[i]-1].edges[j]-1].color!=-1){
                available[G[G[ordered_vertices[i]-1].edges[j]-1].color]=true;
            }
        }
    }
    return used_colors;
}
int main(){
    int T;
    cin >> T;
    for(int i=0;i<T;i++){

        int N,M;
        cin>>N>>M;
        for(int i=0;i<N;i++){
            G[i].lambda=0;
            G[i].color=-1;
            G[i].edges.clear();
        }
        for(int i=0;i<M;i++){
            int a,b;
            cin>>a>>b;
            G[a-1].edges.push_back(b);
            G[b-1].edges.push_back(a);
        }
        int result=maxcliquesize(G,N);
        if(result!=2){
            result-=1;
        }
        cout<<result<<endl;
    }
}
