class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int>adj[n];
	    
    
    //simply create an andjacency list
	    for(auto itr:prerequisites){
	        adj[itr.first].push_back(itr.second);
	    }
    
	    //perform topo sort using bfs (can also do using dfs)
	     int indg[n]={0};
	    
	    for(int i=0;i<n;i++){
	        for(auto x:adj[i]){
	        indg[x]++;
	    }
	    }
	    
	    queue<int>q;
	    vector<int>topo;
	    
	    for(int i=0;i<n;i++){
	        if(indg[i]==0)
	        q.push(i);
	    }
	    
	    while(!q.empty()){
	        auto x=q.front();
	        q.pop();
	        topo.push_back(x);
	        
	        for(auto itr:adj[x]){
	            indg[itr]--;
	            if(indg[itr]==0)
	            q.push(itr);
	        }
	    }
       if(topo.size()==n)
       return true;
       else
       return false;
	}
};
