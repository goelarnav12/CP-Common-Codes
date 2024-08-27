int n,m;
cin>>n>>m;
vector<pii> g[n+1];
for(int i=0;i<m;i++)
{
    int x,y,w;
    cin>>x>>y>>w;
    g[x].pb(mp(y,w));   
    // g[y].pb(mp(x,w));
}
priority_queue<pii , vector<pii >, greater<pii > > pq;
vector<int> dist(n+1, 1e9+2);
pq.push(mp(0, 1));
dist[1] = 0;
while (!pq.empty()) {
int u = pq.top().ss;
pq.pop();
for (int i=0;i<g[u].size();i++) {
  int v = g[u][i].ff;
  int weight = g[u][i].ss;
  if (dist[v] > dist[u] + weight) {
    dist[v] = dist[u] + weight;
    pq.push(make_pair(dist[v], v));
  }
}
}
for(int i=1;i<=n;i++)
{
    cout<<dist[i]<<" ";
}
cout<<endl;
