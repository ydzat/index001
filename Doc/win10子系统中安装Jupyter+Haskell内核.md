在win10 的 Linux 子系统上安装Jupyter
+ Haskell

(使用环境：Ubentu，若使用其他发行版，请查阅相对应的指令)
（引用来源：https://github.com/gibiansky/IHaskell
        https://github.com/jupyter/notebook/issues/4050
        https://blog.csdn.net/qq_34496674/article/details/102550674
        https://blog.csdn.net/jenyzhang/article/details/73275232）
-------------------------------------------------------------------------------
1. 安装win10的linux子系统
    自己搜怎么装
2. 设置好子系统后，开始安装Jupyter Notebook
(1)更新及升级


```python
sudo apt-get update
sudo apt-get upgrade
```

（2）安装pip
当前版本的Linux一般都自带Python，然后现在的Python一般都自带pip，Python2就是pip2，Python3就是pip3。
在之后使用pip的命令中，根据你系统中的pip版本使用，比如有的得用pip2，有的得用pip3。
不过有时候就没有，很神秘，所以以防万一，手动安装一下：


```python
sudo apt-get install python-pip
```

3.安装Jupyter
(1)升级pip


```python
sudo pip install --upgrade pip
```

(2)安装Jupyter


```python
sudo pip install jupyter
```

此时应该可以运行了：


```python
jupyter notebook
```

运行后会给出几个网址，复制后在你的win10的任意浏览器中粘贴，就能够使用了。

4. 安装Haskell环境


```python
sudo apt-get install -y python3-pip git libtinfo-dev libzmq3-dev libcairo2-dev libpango1.0-dev libmagic-dev libblas-dev liblapack-dev
curl -sSL https://get.haskellstack.org/ | sh
git clone https://github.com/gibiansky/IHaskell
cd IHaskell
pip3 install -r requirements.txt
# stack install gtk2hs-buildtools # Disabled for now because gtk2hs-buildtools doesn't work with lts-13 yet
stack install --fast
ihaskell install --stack
```

一般来说，装好stack后会提示你将一个路径加入到PATH中，具体是哪个你看安装好最后的提示。


```python
export PATH=路径:$PATH
```

这个时候，还需要安装几个东西：


```python
pip install --upgrade jupyter-client jupyter-core
pip install 'ipykernel<5.0.0'
```

至此，安装完毕！
开始愉快滴使用吧！
运行指令：


```python
stack exec jupyter -- notebook
```
