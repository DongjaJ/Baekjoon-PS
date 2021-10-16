from collections import deque
import sys
n=input()
a=[]
visit=[[False]*n for _ in range(n)]
for _ in range(n):
    a.append(list(map(int,sys.stdin.readline().split())))
q=deque()

dx=[-1,1,0,0]
dy=[0,0,-1,1]

def bfs(x,y):
    global cnt
    a[x][y]=cnt
    q.append([x,y])
    visit[x][y]=True
    while q:
        tmp=q.popleft()
        for i in range(4):
            x1=tmp[0]+dx[i]
            y1=tmp[1]+dy[i]
            if x1 >=0 and y1 >=0 and x1< n and y1 < n:
                if not visit[x1][y1] and a[x1][y1]==1:
                    q.append([x1,y1])
                    a[x1][y1]=cnt
                    visit[x1][y1]=True



def bfs2(x):
    d=[[-1]*n for _ in range(n)]
    global answer
    q=deque()
    for i in range(n):
        for j in range(n):
            if a[i][j]==x: 
                q.append([i,j])
                d[i][j]=0
    while q:
        tmp=q.popleft()
        for i in range(4):
            x1=tmp[0]+dx[i]
            y1=tmp[1]+dy[i]
            if 0<=x1<n and 0<=y1<n:
                #land
                if a[x1][y1]>0 and a[x1][y1]!=x:
                    answer=min(answer,d[tmp[0]][tmp[1]])
                    return
                #sea
                if a[x1][y1]==0 and d[x1][y1]==-1:
                    d[x1][y1]=d[tmp[0]][tmp[1]]+1
                    q.append([x1,y1])
    return

cnt=1
for i in range(n):
    for j in range(n):
        if a[i][j]==1 and not visit[i][j]: 
            bfs(i,j)
            cnt+=1
            
answer=sys.maxsize
for i in range(1,cnt):
    bfs2(i)

print(answer)