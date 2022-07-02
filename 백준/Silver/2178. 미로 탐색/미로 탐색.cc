#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

//map
int a[101][101];

int n, m;

//방문처리
int visit[101][101];

//위,왼,아래,오
int vx[4] = {-1,0,1,0};
int vy[4] = {0,-1,0,1};

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(pair<int, int>(x, y));
	visit[x][y]=1;

	while (!q.empty())
	{
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = xx + vx[i];
			int ny = yy + vy[i];

			if ( nx > 0 && nx <= n && ny > 0 && ny <=m)
			{
				if (a[nx][ny] == 1 && !visit[nx][ny])
				{
					q.push(pair<int, int>(nx, ny));
					visit[nx][ny] = visit[xx][yy] + 1;
				}
			}
		}
	}

}


int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) 
			scanf("%1d",&a[i][j]);
	}

	bfs(1, 1);

	printf("%d", visit[n][m]);

}