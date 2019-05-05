#import easygui
#easygui.msgbox('第一个窗口！')

#from easygui import *
#msgbox('呀哈喽')

import easygui as g


while 1:
    g.msgbox('我是一个程序')
    msg = "请问你希望选哪个？"
    title = "小游戏互动"
    choices = ["恋爱","编程","吃饭","睡觉","打豆豆",]

    choice = g.choicebox(msg,title,choices)

    g.msgbox("你的选择是:" + str(choice),"结果")

    msg = "再选择一次？"
    title = "那选吧"

    if g.ccbox(msg, title):
        pass
    else:
        sys.exit(0)