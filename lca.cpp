void dfs(int v,int p,vector<int> g[],int depth[],int parent[][22]){
    f(i,0,g[v].size()){
        int c = g[v][i];
        if(c==p) continue;
        depth[c] = depth[v]+1;
        parent[c][0] = v;
        f(i,1,22){
            parent[c][i] = parent[parent[c][i-1]][i-1];
        }
        dfs(c,v,g,depth,parent);
    }
}

int lca(int u,int v,int depth[],int parent[][22]){
    if(depth[u]<depth[v]) swap(u,v);
    int diff = depth[u]-depth[v];
    // get same depth
    fr(i,21,0){
        if(diff&(1<<i)){
            u = parent[u][i];
        }
    }
    // if v is ancestor of u
    if(u==v) return u;
    // move both u and v with powers of two
    fr(i,21,0){
        if(parent[u][i]!=parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

// important
mem(depth,0);
mem(parent,0);
