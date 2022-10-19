'''隨機產生100000個點'''
import random
f=open('input.txt','w')
f.write('100000\n')
for i in range(300000):
    f.write(str(random.randrange(100000)-50000)+' ')
f.close()