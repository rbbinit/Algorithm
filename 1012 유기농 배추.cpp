#include <string.h>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int t; //테스트케이스
int m, n; //1~50
int k; //배추 위치 개수
int a[51][51]; //배추위치 
int vis[51][51];
int ans;
queue <pair<int, int> > q;
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

		for (int i = 0; i < 4; i++)
		{
			int x1 = xx + dr[i];
			int y1 = yy + dc[i];

			if (x1 < 0 || y1 < 0 || x1 >= m || y1 >= n) continue;
			if (vis[x1][y1]) continue;
			if (a[x1][y1] == 0) continue;

			q.push(make_pair(x1, y1));
			vis[x1][y1] = 1;


		}
	}
}

int main()
{
	cin >> t;
	for (int ii = 0; ii < t; ii++)
	{
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++)
		{
			int aa, bb;
			cin >> aa >> bb;
			a[aa][bb] = 1;
		}


		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!vis[i][j] && a[i][j] == 1)
				{
					++ans;
					bfs(i, j);
				}
			}
		}

		cout << ans << '\n';
		memset(vis, 0, sizeof(vis));
		memset(a, 0, sizeof(a));
		ans = 0;
	}
}