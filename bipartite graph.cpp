class Solution {


private:

//performing simple bfs 
bool bfs(int src, int n, vector<vector<int>> &adj, int color[]  ){
        queue<int>q;
        q.push(src);
        color[src]=0;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto itr:adj[node]){
                //if node is not coloured, color it and push it
                if(color[itr]==-1)
                {
                 color[itr]=!color[node];
                 q.push(itr);
                    
                }
                //check if it is already visited and whether its color is same to its adjacent node
                else if(color[itr]==color[node])
                return false;
            }
        }
        return true;
}
   

public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n= adj.size();
        
        int color[n];   //color array initialized with -1,  0-for node not coloured, 1-for node is coloured
        for(int i=0;i<n;i++){
            color[i]=-1;
        }


	    for(int i=0;i<n;i++){
	        if(color[i]==-1)
	        if(bfs(i,n,adj,color)==false)
	        return false;
	        
	    }

	    return true; 
    }
};
