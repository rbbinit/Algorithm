#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int n, m; // 2~100
char a[101][101];
int dis[101][101];
// (1,1)~ (n, m) 지나야하는최소칸
queue <pair<int, int> > q;
int vis[101][101];
int dr[4] = { 1,0,-1,0 };
int dc[4] = { 0,-1,0,1 };

void bfs(int x, int y)
{
	vis[x][y] = 1;
	q.push(make_pair(x, y));

	while (!q.empty())
	{
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();

		for (int i = 0; i <4; i++)
		{
			int x1 = xx + dr[i];
			int y1 = yy + dc[i];

			if (a[x1][y1] == '0') continue;
			if (x1 < 0 || y1 < 0 || x1 >= n || y1 >= m) continue;
			if (vis[x1][y1]) continue;

			if (x1 == n-1 && y1 == m-1)
			{
				dis[x1][y1] = dis[xx][yy] + 1;
				return;
			}

			vis[x1][y1] = 1;
			q.push(make_pair(x1, y1));
			dis[x1][y1] = dis[xx][yy] + 1;
		}
		
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	bfs(0, 0);
	cout << dis[n-1][m-1]+1;

	/*cout << '\n';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << dis[i][j];
		}cout << '\n';
	}*/
	
	
}