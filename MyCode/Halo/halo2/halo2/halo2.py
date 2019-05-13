#row 是行数
#cols是列数
#位置为： 1<=Position<=rows*cols
#位置表示：(6,4)表示第6行第4列

#L1:
#输入：行 列 数字个数 查找的数字1 查找的数字2
#例如：6 4 3 1 11 24
#其中6 4 表示棋盘大小
#输出：行 列 行 列 行 行列
#例如1 1 3 3 6 4

import math
#对输入数据的处理
n = input("input Data：")
n = n.split()

numberOfPaths = 0
Path = []
color = 0
sp = 0
length = 0


for i in range(len(n)):
    if i -2 <= int(n[2])*2:
        n[i] = int(n[i])
        continue
    if i== int(n[2])*2+3:
        numberOfPaths = n[i]
        color = int(n[i+1])
        sp = int(n[i+2])
        length = int(n[i+3])
        continue
    if n[i].isnumeric() == False:
        Path.append(n[i])

#print("n=",n)
#print("Path=",Path)
#print("color=",color)
#print("sp=",sp)
#print("length=",length)

data = n[3:2*n[2]+3]

#生成棋盘：maper[n[0]][n[1]]
mapper = []
mapper_rc = []
for i in range(n[0]*n[1]):
    mapper.append(i+1)
count = 0
for i in range(n[0]):
    mapper_rc.append([])
    for j in range(n[1]):
        
        mapper_rc[i].append(mapper[count])
        count += 1
#print(mapper)
#print(mapper_rc)

#find x in mapper_rc
Position = []

data1 = data[::2]

for i in data1:
    
    for x in range(n[0]):
        for y in range(n[1]):
            
            if mapper_rc[x][y] == i:
               #print(mapper_rc[x][y])
               #print(i,"位于",x+1," ",y+1)
               Position.append(x+1)
               Position.append(y+1)
               
               break
#for i in Position:
    #print(i,end=" ")

#data中存的是数据，data[i],i从0开始，i,i+1为一对，i每次+2
#对应Position中的位置为Position[i*2]与Position[i*2+1]

#L2
#输入：行n[0] 列n[1] 点个数n[2] 点的值 点的颜色
#输出：曼哈顿距离：蓝 黄 绿 红
#设定：蓝1，黄2，绿3，红4
#曼哈顿距离： MD = abs(r1-r2)+abs(c1-c2)
Manh_D = []
Gleich_P = []

def getManhattanDistance(x1,y1,x2,y2):
    MD = abs(x1-x2)+abs(y1-y2)
    return MD
#print(data)

#get ballnum
ballnum = []
for i in range(n[2]*2):
    if i % 2 == 0:
        continue
    else:
        ballnum.append(data[i])
ballnum = max(ballnum)

#set Gleich_Point
for i in range(ballnum):
    Gleich_P.append([i])

#print(type(data[1]))
for i in range(n[2]):
    #Gleich_P[data[i*2+1]-1].append(data[i*2])
    
    Gleich_P[data[i*2+1]-1].append(i)
#print(data)
#print(data1)
#print(Gleich_P)

#get MD
for i in range(len(Gleich_P)):
    #print(getManhattanDistance(Position[Gleich_P[i][1]*2],Position[Gleich_P[i][1]*2+1],Position[Gleich_P[i][2]*2],Position[Gleich_P[i][2]*2+1]))
    #t = getManhattanDistance(Position[Gleich_P[i][1]*2],Position[Gleich_P[i][1]*2+1],Position[Gleich_P[i][2]*2],Position[Gleich_P[i][2]*2+1])
    #Manh_D.append(t)
    Manh_D.append(getManhattanDistance(Position[Gleich_P[i][1]*2],Position[Gleich_P[i][1]*2+1],Position[Gleich_P[i][2]*2],Position[Gleich_P[i][2]*2+1]))
    
    
#for i in range(len(Manh_D)):
#    print(Manh_D[i],end=" ")


#L3
#输入rows cols numberOfPoints Point1 Point2... PointN numberOfPaths Path1 Path2 ... PathN
#numberOfPath =1
#输出code index
#例如：
#输入：5 5 8 7 1 9 1 10 2 16 3 17 2 19 4 20 3 25 4 1 3 16 8 S E E N N E E S
#输出：1 8

#for i in range(len(data)):
#    if data[i] == sp:
        

#        break

#重新处理xy定位
#data1 = data[::2]

#def getPosition(data):
#    Position = []
#    for i in data:
#        for x in range(n[0]):
#            for y in range(n[1]):
#                if mapper_rc[x][y] == i:
#                    Position.append(x+1)
#                    Position.append(y+1)
#                    break
#    return Position
#newPosition = getPosition(data1)

#设置ep，pt_x,pt_y
if sp == data1[Gleich_P[color-1][1]]:
    ep = Gleich_P[color-1][2]
    ep_x = Position[Gleich_P[color-1][2]*2]
    ep_y = Position[Gleich_P[color-1][2]*2+1]
    pt_x = Position[Gleich_P[color-1][1]*2]
    pt_y = Position[Gleich_P[color-1][1]*2+1]

else:
    ep = Gleich_P[color-1][1]
    ep_x = Position[Gleich_P[color-1][1]*2]
    ep_y = Position[Gleich_P[color-1][1]*2+1]
    pt_x = Position[Gleich_P[color-1][2]*2]
    pt_y = Position[Gleich_P[color-1][2]*2+1]

#返回结果
ergb = {'code':0,'index':0}


#设置刨除了sp和ep的点的集合
andereP = Gleich_P[:]
del andereP[color-1]

#运动并判定
#设置中间点pt
pt = sp
pt_xy_stack = []
pt_xy_stack.append([pt_x,pt_y])
pt_xy_stack.append([ep_x,ep_y])

for i in range(length):
    #先判定
    
    
    
    

    #移动操作
    if Path[i] == 'N':
        pt_x = pt_x -1
    if Path[i] == 'E':
        pt_y = pt_y +1
    if Path[i] == 'S':
        pt_x = pt_x +1
    if Path[i] == 'W':
        pt_y = pt_y-1

    #判断是否经过其他点
    flag1 = 0
    for j in range(len(data1)):
        if (pt_x == Position[j*2]) and (pt_y == Position[j*2+1]):
            ergb['code'] = -1
            ergb['index'] = i+1
            
            flag1 = 1
            
            break
    if flag1 == 1:
        
        break
     #判断是否重复路线
    #if pt in pt_xy_stack:
    #    ergb[code] = -1
    #    ergb[index] = i+1
    #    print("123123123")
    #    break
    #else:
    #    pt_stack.append(pt)
    flag = 0
    
    for j in range(1,len(pt_xy_stack)):

        if (pt_x == pt_xy_stack[1][0]) and (pt_y == pt_xy_stack[1][1] and i == length -1):
            break
        if (pt_x == pt_xy_stack[j][0]) and (pt_y == pt_xy_stack[j][1]):
            
            flag = 4
            ergb['code'] = -1
            ergb['index'] = i+1
            
            break
    if flag==4:
        
        break

    pt_xy_stack.append([pt_x,pt_y])



    #移动后，判断移动后是否超出边界
    #判断(pt_x.pt_y)是否在边界内
    if pt_x>n[0] or pt_x<0:
        ergb['code'] = -1
        ergb['index'] = i+1
        
        break
    if pt_y>n[1] or pt_y<0:
        
        ergb['code'] = -1
        ergb['index'] = i+1
        
        break
    if i == length-1:
        if pt_x == ep_x and pt_y == ep_y:
            ergb['code'] = 1
            ergb['index'] = i+1
            
        else:
            ergb['code'] = -1
            ergb['index'] = i+1
    
print(ergb['code'],end=" ")
print(ergb['index'],end=" ")