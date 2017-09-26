from queue import heappush,heappop
def check(travel):
	if(vis[travel[0]][travel[1]] == -1 and travel[0] >= 0 and travel[0] < dim[0] and travel[1] >= 0 and travel[1] < dim[1]):
		if(grid[travel[0]][travel[1]] == '-' or grid[travel[0]][travel[1]] == '.'):
			return True
		else:
			return False
	else:
		return False
def ucs(s,d) :
	l = []
	parent = [[(-1,-1)]*dim[1] for i in range(dim[0])]
	heappush(l,(0,s))
	row = [0,1,-1,0]
	col = [1,0,0,-1]
	vis[s[0]][s[1]] = 0
	while(len(l) != 0) :
		curr = heappop(l)
		if(curr[1] == d) :
			result = curr[0]
			break
		for i in range(4) :
			v = col[i] + curr[1][1]
			u = row[i] + curr[1][0]
			if(check([u,v])) :
				vis[u][v] = 1 + curr[0]
				heappush(l,(vis[u][v],[u,v]))
				parent[u][v] = tuple(curr[1])
	return (result,parent)


source = list(map(int,input().split()))
destination = list(map(int,input().split()))
dim = list(map(int,input().split()))
grid = [input() for i in range(dim[0])]
vis = [[-1]*dim[1] for i in range(dim[0])]
(result,parent) = ucs(source,destination)
temp = destination
path = []
while(parent[temp[0]][temp[1]] != (-1,-1)) :
	path.append((temp[0],temp[1]))
	temp = parent[temp[0]][temp[1]]
path.append(source)
path.reverse()
print(result)
for i in path:
	print(i[0],i[1])
