


#=========课程3

#print("hallo world")
#temp = input("猜一个数字：")
#guess = int(temp)
#if guess == 8:
#    print("对啦")
#    print("恭喜")
#else:
#    print("错啦")
#print("游戏结束")


#==========课程4

#str = r'C:\now'        #str本身是关键词，因此最好不要这么写

#print(str)


#str2 = """我爱鱼c,
#正如我爱小甲鱼，
#他那呱唧呱唧
#呱唧呱唧
#呱唧呱唧的声音，
#总萦绕于我的脑海，
#久久不肯散去"""
#print(str2)


#============课程5，6

#import random

##temp = input("猜一个数字：")
#sc = random.randint(1,10)

#while 1:
#    temp = input("请输入一个数1-10：")
#    if temp.isdigit==False:
#        print("输入错误，请输入整数！")
#        #temp = input("猜一个数1-10:")
#    else:
#        break
#guess = int(temp)

#while guess:
    
#    if guess == sc:
#        print("对啦")
#        print("恭喜")
#        break
#    else:
#      if guess >sc:
#         print("大了")
#      else:
#         print("小了")
#    temp = input("猜错了继续猜：")
#    guess = int(temp)  

#print("游戏结束")


#==============课程10
#temp = '金金'
#mem = ['张三','里斯','王五']
#for wsuowei in mem:
#    print(wsuowei,len(wsuowei))



#===========课程11
#mem = ['张三','里斯','王五']
#mem.append('马六')        #从尾部添加一个元素 马六，该函数只有一个参数，因此一次只能添加一个元素
#print(mem)
#mem.extend(['小七','腊八'])
#print(mem)
#mem.insert(1,'牡丹')
#print(mem)

#list0 = [123,456]
#list00 = list0*3
#print(list00)
#print(list00.index(123,1,3))


#==============课程16
#str1 = "{0} love {1}.{2}".format("I","FishC","com")
#print(str1)
##用大括号的参数是 位置参数， love （左右带空格）被插入到位置0和位置1之间，点‘.’被插入到位置1和位置2之间
##若将0，1，2换为字符，则表示关键字参数
#str2 = "{a} love {b}.{c}".format(a="I",b="FishC",c="com")
#print(str2)

##位置参数与关键字参数可以同时使用，但当同时使用时，位置参数必须位于关键字参数之前

#num1 = '%5.1f' % 27.658 
#print(num1)     #结果是：  27.7
#                #前面有两个空格，使整个长度等于5

#===================课程17
#b = 'I love FishC.com'
#b = list(b)
#print(b)
##输出结果为：['I', ' ', 'l', 'o', 'v', 'e', ' ', 'F', 'i', 's', 'h', 'C', '.', 'c', 'o', 'm']

#c = (1,1,2,3,5,8,13,21,34)
#c = list(c)
#print(c)
##结果为：[1, 1, 2, 3, 5, 8, 13, 21, 34]
##元组被转换为列表了

#num2 = (1,18,35,98,10,-1,-30,128)
#print(list(enumerate(num2)))
##结果为：[(0, 1), (1, 18), (2, 35), (3, 98), (4, 10), (5, -1), (6, -30), (7, 128)]

#a = [1,2,3,4,5,6,7,8]
#b = [4,5,6,7,8]
#print(list(zip(a,b)))
##结果为：[(1, 4), (2, 5), (3, 6), (4, 7), (5, 8)]

#=====================课程18
#def MyFirstFunction():
#    print('函数1')

#MyFirstFunction()

#def fuc(name):
#    print(name + '啊哈哈')
#na = '不可说'
#fuc(na)

#def fuc1(name):
#    '这是函数的文档，类似于注释'
#    return name + '啊哈哈'
#print(fuc1(na))

#print(fuc1.__doc__)     #打印函数的文档
#help(fuc1)      #同上

#def fuc2(words='让编程改变世界',name = '小甲鱼'):
#    return name + '->' + words
#print(fuc2())
#print(fuc2(name='张三', words='吃饼'))      #以这行代码来看，原始的'让编程改变世界'和'小甲鱼'就是默认参数

##收集参数
#def test(*para):
#    print('参数的长度是：', len(para));
#    print('第二个参数使：', para[1]);
#test(1,'小甲鱼',3.14,5,6,7,8)

#=============================课程22
#def ds(x):
#    return 2*x +1
#g = lambda x:2*x+1
#print(ds(2))
#print(g(2))
##结果是相同的

#def add(x,y):
#    return x+y
#g = lambda x,y:x + y
#print(add(2,3))
#print(g(2,3))
##结果相同，lambda可以使用多参数

#print(list(filter(None,[1,0,False,True])))
##结果为：[1,True]
##默认过滤掉非True数据

#def odd(x):
#    return x%2
#temp = range(10)
#show = filter(odd,temp)
#print(list(show))
##输出结果为：[1, 3, 5, 7, 9]
##意思是，按照odd函数的规则来对temp内的数据进行过滤
##以上代码可以化简为：
#print(list(filter(lambda x:x%2, range(10))))

#print(list(map(lambda x:x*2,range(10))))
##结果为：[0, 2, 4, 6, 8, 10, 12, 14, 16, 18]

#==========================
#递归
#def rec(x):
 
#    if(x==1):
#        return 1
#    else:
#        return x * rec(x-1)
#    return 0

#print(rec(5))
#=============================
#斐波那契数列 a(n+2)=a(n+1)+a(n)
#def febo(x):
#    if(x == 1):
#        return 1
#    if(x==2):
#        return 1
#    else:
        
#        return febo(x-2) + febo(x-1)
#print(febo(10))
#p = list(map(febo,range(1,21)))
#print(p)

#=================
#汉诺塔，将在X的塔移动到Z
#def hanoi(n,x,y,z):
#    if n==1:
#        print(x,'->',z)
#    else:
#        hanoi(n-1,x,z,y)#将n-1个盘子从x移动到y上
#        print(x,'->',z) #将最底下的最后一个盘子从x移动到z上
#        hanoi(n-1,y,x,z)#将y上的n-1个盘子移动到z上
#n = int(input('输入层数：'))
#hanoi(n,'X','Y','Z')

#==========字典，课程26
#a = ['李宁','耐克','阿迪达斯','鱼C']
#b = ['一切皆有可能','just do it','impossible is nothing','让编程改变世界']
#print('鱼C-->', b[a.index('鱼C')])        #非字典方式

##建立字典，映射关系
#dict1 = {'李宁':'一切皆有可能' ,'耐克':'just do it','阿迪达斯':'impossible is nothing','鱼C':'让编程改变世界'}
#print('鱼C-->', dict1['鱼C'])     #字典方式

#dict3 = dict((('F',70),('i',105),('s',115),('h',104),('C',67)))
#print(dict3)
##结果为：{'F': 70, 'i': 105, 's': 115, 'h': 104, 'C': 67}
#dict4 = dict(小甲鱼='让编程改变世界',苍井空='让AV征服所有宅男')     #关键字排序
#print(dict4)
##结果为：{'小甲鱼': '让编程改变世界', '苍井空': '让AV征服所有宅男'}

##通过键修改值
#dict4['苍井空']='所有AV从业者都要通过编程来提高职业技能'
#print(dict4)

##添加新键值对
#dict4['爱迪生']='天才就是九十九份汗水加一份灵感但这一份灵感恰恰是最重要的'
#print(dict4)

#===============字典，课程27
#dict1 ={}
#p = dict1.fromkeys((1,2,3))
#print(p)
##结果为：{1: None, 2: None, 3: None}
#p=dict1.fromkeys((1,2,3),'Number')
#print(p)
##结果为：{1: 'Number', 2: 'Number', 3: 'Number'}

#dict1 = dict1.fromkeys(range(32),'赞')
#print(dict1)

##打印32个键
#for eachKey in dict1.keys():
#    print(eachKey)

##打印32个值
#for eachValue in dict1.values():
#    print(eachValue)

##打印32个项
#for eachItem in dict1.items():
#    print(eachItem)

##----
#a = {1:'one',2:'two',3:'three'}
#b = a.copy()
#c = a
#print(a,'\n',b,'\n',c)
#print('a id = ',id(a),'\nb id = ',id(b),'\nc id = ',id(c))  #id()是取地址

##若对c操作，a和c的值都会变化，但b的不会变化
#c[4] = 'four'
#print(a,'\n',b,'\n',c)

##----
#a = {1:'one',2:'two',3:'three'}
#b = {'小白':'狗'}
#a.update(b)
#print(a)
##输出结果为：{1: 'one', 2: 'two', 3: 'three', '小白': '狗'}

#====================课程28
#set1 = set([1,2,3,4,5,5,3,1,0])
#print(set1)
##结果为：{0, 1, 2, 3, 4, 5}
##这个函数会自动排序


#===============课程29
#f = open('D:\\MyCode\\Python\\ersteProgramm\\temp.txt','r')
#print(f.read(3))
#print(f.tell())
#print(list(f))
#f.seek(0,0)
#print(list(f))
##输出结果为：
##锟斤拷

##6

##['烫烫烫']

##['锟斤拷烫烫烫']


#=========================课程30
#f1 = open('D:\\MyCode\\Python\\ersteProgramm\\record.txt')

#fb = open('D:\\MyCode\\Python\\ersteProgramm\\boy.txt','w')
#fg = open('D:\\MyCode\\Python\\ersteProgramm\\girl.txt','w')

#for each_line in f1:
#    print(each_line)
#print('读取完毕')
#maxOffset = f1.tell()
#f1.seek(0,0)

#def getSp(name,file,g):
#    Sp = []
#    while 1:
#        if(file.tell != g):
#            str1 = file.read(3)
#            print('读取开头3个字符的数据：',str1)
        
#        if (str1 == name):
#            file.read(1)
#            Sp.append(file.readline())
           
#        elif(file.tell() == g):
#            file.seek(0,0)
#            break
#        else:
#            file.readline()
#    return Sp


#fb.writelines(getSp('小甲鱼',f1,maxOffset))
#fg.writelines(getSp('小客服',f1,maxOffset))
#fb.close()
#fg.close()


#=======================================课程32
#import pickle
#my_list = [123,3.14,'小甲鱼',['inner list']]
#pickle_file = open('my_list.pkl','wb')      #这个.pkl随意，就是个提示
#pickle.dump(my_list,pickle_file)
#pickle_file.close()
#pickle_file = open('my_list.pkl','rb')
#my_list2 = pickle.load(pickle_file)
#print(my_list2)

#===========================课程35
#try:
#    f = open('data.txt','w')
#    for each_line in f:
#        print(each_line)
#except OSError as reason:
#    print('出错啦:'+str(reason))
#finally:
#    f.close()
##这个程序在试图打开data.txt时会出错，因为没有data.txt这个文件
##这个代码等效于↓
#try:
#    with open('data.txt','w') as f:
#        for each_line in f:
#            print(each_line)
#except OSError as reason:
#    print('出错啦:'+str(reason))
##这个with语句会使编译器关注其对应的对象，当对象不再需要调用时，自动关闭对象





