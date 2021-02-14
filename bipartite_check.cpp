vi adj[1000001];
bool vis[100001];
bool col[1000001];
vi ans[2];
bool bad;
bool dfs(int v,int c) {
    vis[v] = 1;
    col[v] = c;
    ans[c].pb(v);
    for(int child:adj[v]) {
        if(!vis[child]) {
            if(!dfs(child,c^1)) {
                bad = 1;return false;
            }
        }
        else {
            if(col[v]==col[child]) {
                bad=1;return false;
            }
        }
    }
    return true;

}
