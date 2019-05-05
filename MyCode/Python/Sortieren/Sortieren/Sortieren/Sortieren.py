#1.Counting sort计数排序
#2.Radix sort
#3.Bucket sort
import random

#=============================Counting sort计数排序===============================
#生成随机列表
def random_int_list(start, stop, length):
    start, stop = (int(start), int(stop)) if start <=stop else (int(stop),int(start))
    length = int(abs(length)) if length else 0
    random_list = []
    for i in range(length):
        random_list.append(random.randint(start,stop))
    return random_list

a = random_int_list(1,10,10)
print('生成的原始序列A的数据为：',a)

#扫描列表，找到最大值和最小值
def scan(arr,Gross,length):
    max = arr[0]
    min = arr[0]
    for i in range(length):
        if max == arr[i] or min ==arr[i]:
            continue
        if max<arr[i]:
            max = arr[i]
        if min > arr[i]:
            min = arr[i]
        
    if Gross == 'max':
        return max
    if Gross == 'min':
        return min

max = scan(a,'max',len(a))
min = scan(a,'min',len(a))

print('最大值为：',max,' 最小值为：',min)

#生成排序列表C,length=max-min+1
def sort_counting_list(length,arr):
    sort_list = [0] * length
    
    for i in range(length):
        #这个位置要在index上-1，因为序号是从0开始的
        sort_list[arr[i]-1] = sort_list[arr[i]-1] + 1
            
    return sort_list

sort_list = sort_counting_list(len(a),a)
print('计数排序序列',sort_list)

temp = []
for i in range(len(a)):
    if sort_list[i]!=0:
        for j in range(sort_list[i]):
            #这个位置需要给index+1，因为要补回在生成排序列表C时减去的1
            temp.append(i+1)
    
print('Counting sort: ',temp)





#============================Bucket sort桶排序============================
#根据函数划分原始数据，形成一个大致范围的有序
#例如根据f(k)=k/10

b = random_int_list(1,100,10)

for i in range(10):
    x = random.random()
    
    if x!=0:
        b[i] = b[i] * x

b = [("%.3f" % i) for i in b]
b = list(map(float,b))

print('\n浮点化的B序列为：' , b)
def sort_bucket_list(arr):
    #建立5个桶
    bucket_alle = [[],[],[],[],[]]
    
    #建立最终表
    erfolg = []
    #建立映射关系存储表f(k)=0.1x
    bucket_list = [0.1]*len(arr)
    #print('bucket_list 函数中：',bucket_list)
    #建立映射关系f(k)=0.1x
    for i in range(len(arr)):
        bucket_list[i] = '%.3f' % (bucket_list[i] * arr[i])
    #bucket_list = [('%.3f' % i)for i in bucket_list]
    bucket_list = list(map(float,bucket_list))
    
    #根据映射关系开始分桶
    for i in range(len(arr)):
        if 0<=bucket_list[i]<2:
            bucket_alle[0].append(arr[i])
        elif 2<=bucket_list[i]<4:
            bucket_alle[1].append(arr[i])
        elif 4<=bucket_list[i]<6:
            bucket_alle[2].append(arr[i])
        elif 6<=bucket_list[i]<8:
            bucket_alle[3].append(arr[i])
        elif 8<=bucket_list[i]:
            bucket_alle[4].append(arr[i])
        else:
            print('数据错误！')

    print('分桶后：',bucket_alle)
    for i in range(5):
        if bucket_alle[i]!= None:
            bucket_alle[i].sort()

    for i in range(5):
        if bucket_alle[i]!=None:
            erfolg.extend(bucket_alle[i])

    return erfolg

bucket_list = sort_bucket_list(b)
print('桶排序后：',bucket_list)




#====================================Radix sort基数排序===========================
#先排低位，后排高位

c = random_int_list(1,99,10)
print('\n生成随机正整数序列C(1-99)：',c)

def sort_radix_list(arr):
    radix_list = [[],[],[],[],[],[],[],[],[],[]]
    arrTemp = []
    print(radix_list)
    #判断个位值，根据个位数值k放到radix_list中index为k的桶中
    for i in range(len(arr)):
        radix_list[arr[i]%10].append(arr[i])
    print('个位分桶：',radix_list)
    #有元素的桶内进行第一次排序
    for i in range(len(arr)):
        if radix_list[i]!=None:
            radix_list[i].sort()
            arrTemp.extend(radix_list[i])
    print('第一次桶内排序后生成一个新的中间序列：',arrTemp)
    
    #判断十位值，根据十位数值k放到radix_list中index为k的桶中
    #首先初始化radix_list
    for i in range(len(arrTemp)):
        del radix_list[i][:]
    for i in range(len(arrTemp)):
        radix_list[arrTemp[i]%100//10].append(arrTemp[i])
    print('十位分桶：',radix_list)
    #有元素的桶内进行第二次排序
    #arrTemp初始化
    del arrTemp[:]
    for i in range(len(arr)):
        if radix_list[i]!=None:
            radix_list[i].sort()
            arrTemp.extend(radix_list[i])

    return arrTemp

    

radix_list = sort_radix_list(c)
print('基数排序后：',radix_list)