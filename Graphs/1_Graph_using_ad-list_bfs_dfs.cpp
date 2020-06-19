#include <bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	vector<int> *adj;
public:
	Graph(int vertices){
		this->V = vertices;
		adj = new vector<int>[V];
	}

	void addEdge(int u, int v){
		adj[u].push_back(v);
}
	bool bfs(int root){
		queue<int> q; // stores the next node to visit
		set<int> s; // stores visited nodes
		
		q.push(root);
		s.insert(root);
	
		while(!q.empty()){
			int temp = q.front();
			
			q.pop();
			cout<<temp<<" ";
			for(vector<int>::iterator x = adj[temp].begin(); x!=adj[temp].end();x++)
			{
				if(s.find(*x)==s.end()){
				
					q.push(*x);
					s.insert(*x);
			}
		}	
    }

}




	void dfsUtil(int root,vector<bool>& arr){
		//s.insert(root);
		arr[root] = true;
		//res.push_back(root);
		cout<<root<<" ";
		for(vector<int>::iterator x = adj[root].begin(); x!=adj[root].end();x++)
			{
				if(arr[*x]==false){
					arr[root] = true;
					dfsUtil(*x,arr);
				}
			}
		
	}
	
	void dfs(){
		vector<bool> arr (V,false);
		dfsUtil(0,arr);
	}

};

int main(){
	int T;
	cin>>T;
	while(T--){
		int V,E,i;
		cin>>V>>E;
		Graph g(V);
		for(i=0;i<E;i++){
			int x,y;
			cin>>x>>y;
			g.addEdge(x,y);
		}
		cout<<"DFS: ";
		g.dfs();
		cout<<endl;
		cout<<"BFS: ";
		g.bfs();
		cout<<endl;
	
	}	
	return 0;
}
