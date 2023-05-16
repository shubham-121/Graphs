
class Solution {
    
    private:
    bool bfs(int src, int vist[], vector<int> adj[] )
    {
        queue<pair<int,int>>q;
        vist[src]=1;
       // int initial=-1;
        q.push({src,-1});
        
        while(!q.empty())
        {
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto x:adj[node])
            {
                if(vist[x]==0)
                {
                    vist[x]=1;
                    q.push({x,node});
                    
                }
                else if(parent!=x)
                return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        int vist[v]={0};
        for(int i=0;i<v;i++)
        {
            if(!vist[i]){
                    if(bfs(i,vist,adj))
                    return true;
                }
            }
        return false;
        }
    
};

