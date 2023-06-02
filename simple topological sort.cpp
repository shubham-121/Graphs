class Solution
{
    private:
    void topoSort(vector<int> adj[], int vist[], int node, stack<int>&st){
        
        vist[node]=1;
        for(auto itr:adj[node]){
            if(!vist[itr]){
                topoSort(adj, vist, itr, st);
            }
        }
        st.push(node);
        
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    // code here
	    int vist[n]={0};
	    
	    stack<int>st;
	    for(int i=0;i<n;i++){
	        if(!vist[i]){
	            topoSort(adj,vist,i,st);
	        }
	    }
	    
	    vector<int>ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};
