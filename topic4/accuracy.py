import os
# generate_data='python -u "d:\程式檔案\Special-Topics-on-Computer-Programming\topic4\data.py"'
run_flow='.\flow'
run_karger='.\karger'
os.system(run_flow)
f=open('flow.txt','r')
ans=[]
accuracy=[0,0,0,0,0,0,0,0,0,0]
for line in f.readlines():
    ans.append(int(line))
t=10000 #跑10000遍
k=t
while t:
    t-=1
    os.system(run_karger)
    kf=open('karger.txt','r')
    karger=[]
    for line in kf.readlines():
        karger.append(int(line))
    for i in range(10):
        if ans[i]==karger[i]:
            accuracy[i]+=1
acc=open('accuracy.txt','w')
acc.write('run '+str(k)+' times\n\n')
for i in range(10):
    acc.write(str((accuracy[i]/k*100))+'%\n')
kf.close()
f.close()
acc.close()