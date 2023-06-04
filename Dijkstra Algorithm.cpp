typedef pair<int,int>pi;
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)
    {
        // Code here
        priority_queue<pi, vector<pi>, greater<pi>>pq;
        
        vector<int>dist(V);
        for(int i=0;i<V;i++){
            dist[i]=1e9;
        }
        //Important note:
        //storing the adjNode in queue in form of  {weight, node}.
        //but in the adjList the the node is given first, weight is given second.
        dist[src]=0;
        pq.push({dist[src], src});
        
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            
            pq.pop();
            
            //NOTE- in the adj list, the node is given first, weight is given second.
            for(auto itr:adj[node]){
                int edgeWeight=itr[1];
                int adjNode=itr[0];
                
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode]=dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
            return dist;
    }
};
