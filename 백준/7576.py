import sys
from collections import deque

dy=[0,0,-1,1]
dx=[-1,1,0,0]
q=deque()
def bfs():
    while q:
        tmp=q.popleft()
        d=tmp[2]
        #print("tmp",tmp)
        for i in range(4):
            x1=dx[i]+tmp[0]
            y1=dy[i]+tmp[1]
            if x1>=0 and y1>=0 and x1< n and y1< m:
                if a[x1][y1]==0 or a[x1][y1] > a[tmp[0]][tmp[1]]+1:
                    a[x1][y1]=a[tmp[0]][tmp[1]]+1
                    q.append([x1,y1,tmp[2]+1])
    flag=False
    for i in a:
        if flag: break
        for j in i:
            if j==0:
                flag=True
                break
    print(-1 if flag else d)


m,n=map(int,sys.stdin.readline().split())
a=[]
for _ in range(n):
    a.append(list(map(int,sys.stdin.readline().split())))
visit=[[False] * m for _ in range(n)]

for i in range(n):
    for j in range(m):
        if a[i][j]==1:
            q.append([i,j,0])
bfs()

#print(a)