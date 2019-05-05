#在以一定转向角行驶一定距离后，计算行驶车的位置和方向。
#输入：轮距，距离，转向角度（3个浮点型数据）
#输出：x,y,新方向（3个浮点型数据，四舍五入）
#x,y,位置相对于开始位置
#新方向为 0~360
#初始x,y为(0,0)，方向为0°

#输入：轮距 n{距离 转向角度}
#例如：1.00 3 1.00 15.00 1.00 0.00 1.00 -15.00
#输出：x y 新方向
import math
while 1:

    n = input("input daten")
    print(n)
    n = n.split()
    
    for i in range(len(n)):
        n[i] = float(n[i])


    #print("n切片后：",n)
    DS = n[2:]
    #print("DS = n[3:]",DS)
    #DS = DS.split()
    D = []
    S = []
    #print("n[2]",n[2])
    
    
    for i in range(len(DS)):
        if i%2 ==0:
            D.append(float(DS[i]))
        if i%2 !=0:
            S.append(float(DS[i]))
        DS[i] = float(DS[i])
    #for i in range(len(D)):
    #    D[i]=math.radians(D[i])
    #    S[i] = math.radians(S[i])
    print("DS",DS)
    print("D",D)
    print("S",S)
    
    #WheelBase = float( input("input Wheel Base:"))
    #Distance = float(input("input Distance:"))
    #SteeringAngle = float( input("input Steering Angle:"))

    #if SteeringAngle ==0:
    #    print(0.00,Distance,0.00)
    #    break

    #获取半径
    def getRadius(WheelBase, SteeringAngle,f):
        if SteeringAngle == 0.0:
            return 0
        sinx = float(math.sin(SteeringAngle*math.pi/180.0))
        Radius = WheelBase / sinx
        
        if f=='2':
            return '%.2f' % Radius
        if f=='9':
            return Radius
    #Radius = float(getRadius(WheelBase, SteeringAngle,'2'))
    #Radius2 = float(getRadius(WheelBase, SteeringAngle,'9'))
    #print("Radius:",Radius,"\nRadius2:",Radius2)


    #获取x,y
    def getPosition(Distance,Radius):
        
        if Radius == 0.0:
            return (0.0,Distance,0.0)


        Angle = Distance * 360.0 / (2.0 * Radius * math.pi)
        #Angle = float('%.2f' % Angle)
        rad = Angle * math.pi / 180.0
        #rad = float('%.2f' % rad)
        y = float('%.2f' % (math.sin(rad) * Radius))
        x = Radius - float((math.cos(rad) * Radius))
        x = float('%.2f' % x)

        newDirection =float(Angle)
        #print(newDirection)
        while newDirection < 0:
            newDirection = newDirection + 360.0
        newDirection = float('%.2f' % newDirection)


        Position = (float(x),float(y),float(newDirection))
        return Position
    #print("Position:",getPosition(Distance,Radius2))
    Radius2 = float(getRadius(float(n[0]), S[0],'9'))
    PositionStart = getPosition(D[1],Radius2)
    x = float(PositionStart[0])
    y = float(PositionStart[1])
    newDirection = float(PositionStart[2])

    print("第1次",PositionStart)

    l = int(n[1])

    def getNewPosition(x,y,d,l,S):
        Position = []



        for i in range(l):
         #第1次
            if i == 0:
                
                continue
            Radius2 = float(getRadius(n[0], S[i],'9'))
            PositionT = getPosition(D[i],Radius2)
            #x = math.cos(math.radians(S[i]))*x + math.sin(math.radians(S[i]))*y
            #y = -math.sin(math.radians(S[i]))*x + math.cos(math.radians(S[i]))*y
            print(PositionT)
            xT = PositionT[0]
            yT = PositionT[1]
            dT = PositionT[2]
            
            lT = math.sqrt(xT*xT + yT *yT)
            print("lT=",lT)
            
            #if (d + dT == 180) or (d + dT == 270):
            #    x = x + Radius2
            #    y = lT * math.cos(math.radians(d/2 + S[i])) + y
            #    print("y=",y)
            #if d + dT == 0 or d +dT == 360:
            #    y = y + Radius2
            #    x = lT * math.sin(math.radians(d/2 + S[i])) + x
            #else:
            x = lT * math.sin(math.radians(d/2 + S[i])) + x
            y = lT * math.cos(math.radians(d/2 + S[i])) + y

            d = d + dT
            print("第",i+1,"次：x=",x," y=",y," d=",d)
        Position.append(x)
        Position.append(y)
        Position.append(d)
        return Position
    print(getNewPosition(x,y,newDirection,l,S))
    




    c = input("Weiter？(n to exit)")
    if c == 'n':
        break

