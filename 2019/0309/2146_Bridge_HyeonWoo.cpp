/*#include<bits/stdc++.h>
using namespace std;
int marking(vector<vector<int>> &graph,vector<vector<int>> &isVisit, int x,int y,int cnt){
    if(x<0 || y<0 || x>=graph.size() || y>=graph.size())
        return 0;
    if(isVisit[x][y]!=0)
        return 0;
    if(graph[x][y]!=0){
        isVisit[x][y]=1;
        graph[x][y]=cnt+1;
        marking(graph,isVisit,x+1,y,cnt);
        marking(graph,isVisit,x,y+1,cnt);
        marking(graph,isVisit,x-1,y,cnt);
        marking(graph,isVisit,x,y-1,cnt);
    }
}
int searching(vector<vector<int>> &graph,vector<vector<int>> &isVisit, int x,int y,int depth,int cnt){
    //cout<<"x : "<<x<<" , y : "<<y<<endl;
    //cout<<depth<<endl;
    if(x<0 || y<0 || x>=graph.size() || y>=graph.size() || isVisit[x][y]!=0)
        return 1000000000;
    if(graph[x][y]==cnt)
        isVisit[x][y]=1;
    if(graph[x][y]!=0 && graph[x][y]!=cnt){
        return depth;
    }
    else{
        if(graph[x][y] ==0 ){
            return min(min(searching(graph,isVisit,x+1,y,depth+1,cnt),searching(graph,isVisit,x,y+1,depth+1,cnt)),min(searching(graph,isVisit,x-1,y,depth+1,cnt),searching(graph,isVisit,x,y-1,depth+1,cnt)));
        }
        else{
            return min(min(searching(graph,isVisit,x+1,y,depth,cnt),searching(graph,isVisit,x,y+1,depth,cnt)),min(searching(graph,isVisit,x-1,y,depth,cnt),searching(graph,isVisit,x,y-1,depth,cnt)));
        }
    }
}
int main(){
    int N;
    cin>>N;
    vector< vector<int> > graph(N,vector<int>(N));
    vector<vector<int>> isVisit(N,vector<int>(N,0));
    vector<vector<int>> isVisit2(N,vector<int>(N,0));
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cin>>graph[i][j];
        }
    }
    int cnt=1;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(isVisit[i][j]==0){
                marking(graph,isVisit,i,j,cnt);
                cnt++;
            }
        }
    }

    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cout<<graph[i][j]<<' ';
        }
        cout<<endl;
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cout<<searching(graph,isVisit2,i,j,0,graph[i][j])<<endl;
            cnt++;
        }
    }



}
*/
#include <iostream>
#include <algorithm>
using namespace std;
int n, num; // num : 현재 단지 번호
int d[26][26] = { 0, };
int isVisit[26][26] = { 0, };
int home[169] = { 0, };//25인 경우 13*13이 최대 단지 수.
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
void go(int x, int y) {
	//방문한 곳은 재방문하지 않는다. , 지도 안에 들어와야 한다.
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (isVisit[nx][ny] == 0 && d[nx][ny] == 1 && nx > 0 && nx <= n && ny > 0 && ny <= n)
		{
			isVisit[nx][ny] = 1;
			home[num] += 1;
			go(nx, ny);
		}
	}

	return;
}
int main() {

	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%1d", &d[i][j]);

	num = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (d[i][j] == 1 && isVisit[i][j] == 0)
			{
				isVisit[i][j] = 1;
				num += 1;
				home[num] += 1;
				go(i, j);
			}
		}

	for (int i = 0; i <= sizeof(home); i++)
		cout << home[i] << endl;
		cout<<endl;
	cout << num << endl;
	sort(home, home+num);
	for (int i = 1; i <= num; i++)
		cout << home[i] << endl;

	return 0;
}
