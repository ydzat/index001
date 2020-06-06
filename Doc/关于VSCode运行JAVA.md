1. 正常在VSCODE里下载好必备的那几个插件
2. 下载好JAVA SE，此处有多种选择：
  a. 官方版本，当前由于最新的Java Runtime Evn 是Ver.8的，因此JDK和JRE都必须下载Ver.8的；
  b. 第三方版本。我用的是RedHat版本，最新的为Ver.14，因此JDK和JRE下载的都是第三方Ver.14版本的。
3. 理论上，系统变量会被自动设置。如果没有，记得手动调整为你安装版本的路径。

4. VSCODE中用的是Code Runner的话，在运行时请参考如下代码：

`PS C:\Users\ydzat\OneDrive\Workspace\Eclipse IDE Workspace\Datenstruktur\src> cd "C:\Users\ydzat\OneDrive\Workspace\Eclipse IDE Workspace\Datenstruktur\src\" ; if ($?) { javac -encoding utf-8 *.java } ; if ($?) { java PVL6.Test }`

在上述代码中，我的.java源文件位于"...\src\PVL6\"中，但你需要回到上一级文件夹，然后运行`java <包名>.<文件名/主类名>`

如果没有包，那大概不需要这么麻烦。
