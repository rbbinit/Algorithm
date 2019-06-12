#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

//그림 개수, 가장 넓은것
int n, m; //가로세로
int a[501][501];
int vis[501][501];
int ans;
int dr[4] = { 1,0,-1,0 };
int dc[4] = { 0,-1,0,1 };
queue <pair<int, int>> q;
int ans_sum = -1e9;

void bfs(int x, int y)
{
	vis[x][y] = 1;
	q.push(make_pair(x, y));
	int sum = 0;

	while (!q.empty())
	{
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int x1 = xx + dr[i];
			int y1 = yy + dc[i];
			if (x1 < 0 || y1 < 0 || x1 >= n || y1 >= m) continue;
			if (vis[x1][y1]) continue;
			if (a[x1][y1] == 0) continue;

			vis[x1][y1] = 1;
			q.push(make_pair(x1, y1));
			++sum;
		}

	
		
	}

	ans_sum = max(sum, ans_sum);
	
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!vis[i][j] && a[i][j])
			{
				++ans;
				bfs(i, j);
			}
		}
	}

	if (ans_sum < 0) ans_sum = 0;
	cout << ans << '\n' << ans_sum+1;
}