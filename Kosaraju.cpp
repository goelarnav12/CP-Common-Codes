const int N = 1e5+5;
vector<int> g[N],rg[N];

void dfs1(int u,vector<bool> &vis,stack<int> &st){
    vis[u] = true;
    for(auto x:g[u]){
        if(!vis[x]){
            dfs1(x,vis,st);
        }
    }
    st.push(u);
}

void dfs2(int u,vector<int> &comp,int cnt){
    comp[u] = cnt;
    for(auto x:rg[u]){
        if(comp[x] == 0){
            dfs2(x,comp,cnt);
        }
    }
}

void kosaraju(int n){
    stack<int> st;
    vector<bool> vis(n+1,false);
    rep(i,1,n+1){
        if(!vis[i]){
            dfs1(i,vis,st);
        }
    }
    vector<int> comp(n+1);
    int cnt = 0;
    while(!st.empty()){
        int x = st.top();
        st.pop();
        if(comp[x] == 0){
            cnt++;
            dfs2(x,comp,cnt);
        }
    }
    //condensed graph
    vector<int> cg[cnt+1];
    rep(i,1,n+1){
        for(auto x:g[i]){
            if(comp[i] != comp[x]){
                cg[comp[i]].pb(comp[x]);
            }
        }
    }
    vector<int> indeg(cnt+1,0);
    rep(i,1,cnt+1){
        for(auto x:cg[i]){
            indeg[x]++;
        }
    }
}
