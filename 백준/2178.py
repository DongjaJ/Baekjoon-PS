from collections import deque
import sys

dx=[-1,1,0,0]
dy=[0,0,-1,1]

n,m=map(int,sys.stdin.readline().split())
a=[]
visit=[[False]* m for _ in range(n)]
for _ in range(n):
    a.append(list(map(int,sys.stdin.readline().rstrip())))

def bfs(x,y):
    q=deque()
    q.append([x,y])
    visit[x][y]=True
    while q:
        tmp=q.popleft()
        for i in range(4):
            x1=tmp[0]+dx[i]
            y1=tmp[1]+dy[i]
            if x1 >=0 and y1 >=0 and x1 < n and y1<m:
                if not visit[x1][y1] and a[x1][y1]==1:
                    a[x1][y1]=a[tmp[0]][tmp[1]]+1
                    visit[x1][y1]=True
                    q.append([x1,y1])

bfs(0,0)
print(a[n-1][m-1])
