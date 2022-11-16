import random
test=10000 #操作次數
operation=['s','d','i']
f=open('input.txt','w')
n=random.randrange(10000)
f.write(str(n)+'\n')
for i in range(n):
    f.write(str(i)+' ')
f.write('\n'+str(test)+'\n')
for i in range(test):
    f.write(operation[random.randrange(3)]+
            ' '+str(random.randrange(10000000000))+' ')
