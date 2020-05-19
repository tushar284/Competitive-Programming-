/*user -> tushar284*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
# define inf 500

int dis[200][200],n,m;
void bfs(int s){
	int x,y; // pos in matrix
	x = (s-1) / m; 
	y = (s-1) % m; 

	dis[x][y]=0;
	queue<int>Q;
	Q.push(s);
	while(!Q.empty()){
		int s=Q.front();
		Q.pop();
		x = (s-1) / m; 
		y = (s-1) % m; 
		int d = dis[x][y]+1;
		if(y+1<m and dis[x][y+1]>d)Q.push(s+1),dis[x][y+1]=d; //going right
		if(y>0 && dis[x][y-1]>d)Q.push(s-1),dis[x][y-1]=d; //going left
		if(x>0 && dis[x-1][y]>d)Q.push(s-m),dis[x-1][y]=d; //going upward
		if(x+1<n && dis[x+1][y]>d)Q.push(s+m),dis[x+1][y]=d; // going downward
	}
	
}

int main() {
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)dis[i][j]=inf;
		}
		vector<int> ver;
		string s;
		for(int i=0;i<n;i++){
			cin>>s;
			for(int j=0;j<m;j++){
				int x = (m*i)+j+1,val; // converting pos into number from 1 to (n*m) 
				val = s[j]-'0';
				if(val)dis[i][j]=0,ver.push_back(x); //storing the position of 1
			}
		}
		for(auto i:ver){
			bfs(i);		
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				cout<<dis[i][j]<<" ";
			cout<<"\n";
		}


	}
	return 0;
}	