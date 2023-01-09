import random
nodeCount = 10
vertexCount = random.randrange(int(nodeCount*(nodeCount-1)/2))
vertices = {}
f=open('input.txt','w')
f.write(str(nodeCount)+' '+str(vertexCount)+'\n')
while len(vertices) < vertexCount:
    x = random.randint (1, nodeCount)
    y = random.randint (1, nodeCount)
    if x == y: continue
    #comment the following line if the graph is directed
    if y < x: x, y = y, x
    w = random.randrange (40000000)+1
    vertices [x, y] = w

#just for debug
for (x, y), w in vertices.items ():
    f.write(str(x)+' '+str(y)+' '+str(w)+'\n')
f.write('0 0')