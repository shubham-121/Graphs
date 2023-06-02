
#include <bits/stdc++.h>
using namespace std;


class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    // code here
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
	return topo;
	}
};

