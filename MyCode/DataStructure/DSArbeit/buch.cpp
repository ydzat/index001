// buch.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"			//若使用vc6.0或老版的vs，那么需要将此注释掉
#include"iostream"
#include"string"
using namespace std;
#define M 10

template<class T>
class SqList;

template<class T>
class Buchdata;

template<class T>
class Reader;

template<class T>
class BuchOper;



//================================================class Buchoper

int IDS;
int BN;
template<class T>
class BuchOper//:public SqList<T>
{
private:
	Reader <T>*id;		//读者指针
	SqList <T>b;
	int menschen;		//已借书人数
	int menschensize;	//可容纳用户数量
public:
	BuchOper()
	{
		id=new Reader<int>[M];
		menschen=0;
		menschensize=M;
	};

	~BuchOper()
	{
		delete[]id;		//释放顺序表占用的内存空间
		menschen=0;
		menschensize=0;
	};

	void ID_Eintragung()			//注册新用户
	{
		if(menschensize!=0)
		{
			int i;
			cout<<"空余名额还有："<<menschensize<<"来得早不如来得巧，恭喜你还有机会注册"<<endl;
			cout<<"来吧签下契约和我成为马猴烧……啊不对，请输入你的用户ID（纯数字）：";
			cin>>i;
			id[menschen].neu_ID(i);
			cout<<endl;
			menschen++;
			menschensize--;
		}
	};

	int ID_Gelandet(int i)		//登陆
	{
		if(IDS==-1)
		{
			for(int j=0;j<menschen;j++)
			{
				if(i==id[j].returnID())
				{
					IDS=j;
					return j;		//返回用户id编号（非id）
				}
			}
			IDS=-1;
			return -1;			//若返回-1，则说明需要注册
		}
		else
		{
			cout<<"您已经告诉伦家您的ID了，您忘记了吗？不需要再次登陆了哟~"<<endl;
			return IDS;			//返回用户id编号（非id）
		}
		
	};

	void Zurueck_Buch()		//还书
	{
		if(IDS==-1)
		{
			cout<<"您还没有告诉伦家你的id呢，怎么还书啊！返回去登陆吧~"<<endl;
		}
		else
		{
			int bn;
			cout<<"请告诉伦家你要归还的书的书号：";
			cin>>bn;
			cout<<endl;
			id[IDS].buchen(bn,&b);
		}
	};

	void Mieten_Buch()		//借书
	{
		if(IDS==-1)
		{
			cout<<"您还没有告诉伦家你的id呢，怎么借书啊！返回去登陆吧~"<<endl;
		}
		else
		{
			int bn;
			cout<<"请告诉伦家你要借出的书的书号：";
			cin>>bn;
		//	cout<<endl;
			id[IDS].bibliothek(bn,&b);
		}
	};

	void Anfrage_Reader_Info()		//读者个人信息查询
		{
			if(IDS==-1)
			{
				cout<<"您还没有告诉伦家你的id呢，怎么查您的信息啊！返回去登陆吧~"<<endl;
			}
			else
			{
				id[IDS].readerdata();
			}
		};

	void Anfrage_Buch_Info()			//书籍信息查询
		{
			int e1;
			int t1;
			string t2,t3;
			cout<<"请问您希望根据什么来查找书籍？（编号1，作者2，书名3）：";
			cin>>e1;
			switch(e1)
			{
			case 1:
				{
					cout<<"请告诉我书籍的编号：";
					cin>>t1;
					cout<<endl;
					b.Buch_Buchnum(t1);
					break;
				}
			case 2:
				{
					cout<<"请告诉我你要查找的作者：";
					cin>>t2;
					cout<<endl;
					b.Buch_Autor(t2);
					break;
				}
			case 3:
				{
					cout<<"请告诉我你要查找的书名：";
					cin>>t3;
					cout<<endl;
					b.Buch_Titel(t3);
					break;
				}
			}
		};

	void Neu_Buch()		//新书入库
		{
			int n=0,bn,a=0;
			string nt;
			string na;
			char c;
			while(a==0)
			{
				cout<<"请输入书编号：";
				cin>>bn;
				
				if(b.Leben_Buch_Num(bn)==1)
				{
					b.Buch_Plus(BN);
					b.ku_Buch_Plus(BN);
					continue;
				}
				
				cout<<"请输入书籍名称：";
				cin>>nt;
				if(b.Leben_Buch_Titel(nt)==1)
				{
					b.Buch_Plus(BN);
					b.ku_Buch_Plus(BN);
					continue;
				}
				cout<<"请输入书籍作者：";
				cin>>na;
				if(b.Leben_Buch_Autor(na)==1)
				{
					
					b.Buch_Plus(BN);
					b.ku_Buch_Plus(BN);
					continue;
				}
				a=1;
			}
			while(b.Listsize()!=0)
			{
				
				if(b.Insert(b.Length(),bn,nt,na)!=0)
				{
					cout<<"入库成功！"<<endl;
					cout<<"现在拥有书籍"<<b.Length()<<"部"<<"    仓库剩余空间："<<b.Listsize()<<endl;
					n++;
				}
				else
				{
					cout<<"入库失败！"<<endl;
				}
				cout<<"希望继续入库吧？（y/n）:";
				cin>>c;
				if(c=='n'||c=='N')
				{
					cout<<"入库完成"<<endl;
					cout<<"现在拥有书籍"<<b.Length()<<"部"<<"    仓库剩余空间："<<b.Listsize()<<endl;
					cout<<"此次您共录入"<<n<<"部书籍"<<endl;
					break;
				}
				a=0;
				while(a==0)
				{
					cout<<"请输入书编号：";
					cin>>bn;
					
					if(b.Leben_Buch_Num(bn)==1)
					{
						b.Buch_Plus(BN);
						b.ku_Buch_Plus(BN);
						continue;
					}
					
					cout<<"请输入书籍名称：";
					cin>>nt;
					if(b.Leben_Buch_Titel(nt)==1)
					{
						b.Buch_Plus(BN);
						b.ku_Buch_Plus(BN);
						continue;
					}
					cout<<"请输入书籍作者：";
					cin>>na;
					if(b.Leben_Buch_Autor(na)==1)
					{
						b.Buch_Plus(BN);
						b.ku_Buch_Plus(BN);
						continue;
					}
					a=1;

				}
				a=1;
				cin.clear();
				cin.ignore();
			}
		};
};



//================================================class SqList
template<class T>
class SqList
{
private:
//	T * elem;				//表基地址
	Buchdata <T>*buch_num;		//书类数组，用于存储未借书的信息
	int length;				//表长
	
	int listsize;			//表容量
public:
//	SqList(){};
	SqList();			//构造函数，创建容量为m的空表
	~SqList();				//析构函数，删除表空间
	void CreateList(int n);	//创建具有n个元素的线性表
	int Insert(int i,int bn, string neu_titel, string neu_autor);	//在表中第i个位置插入元素e（插入）
	T Delete(int i);		//删除表中第i个元素（删除）
	T GetElem(int i);		//获取第i个元素的值（查找）
	int Locate(int e);		//元素定位（返回位置）
	void Clear();			//清空表
	int Empty();			//判断表是否为空
	int Full();				//判断表是否为满
	int Length(){return length;};			//测量表长度
	int Listsize(){return listsize;};
	void ListDisp();		//输出表元素
	int Buch_Num(int bn);
	
	int Buch_weniger(int bn);		//现存量+-
	int Buch_Plus(int bn);

	int ku_Buch_weniger(int bn);		//现存量+-
	int ku_Buch_Plus(int bn);

	int Buch_Autor(string ba);
	int Buch_Titel(string ba);
	int	Buch_Buchnum(int ba);

	string Get_Buch_Titel(int bn1)
	{
		for(int i=0;i<length;i++)
		{
			if(bn1==buch_num[i].holen_buchnum())
			{
				return buch_num[i].holen_titel();
			}
		}
		
	};
	string Get_Buch_Autor(int bn1)
	{
	//	cout<<"length:::::"<<length<<endl;
		for(int i=0;i<length;i++)
		{
			if(bn1==buch_num[i].holen_buchnum())
			{
				return buch_num[i].holen_autor();
			}
		}
	
	};
	int Get_Buch_Num(int bn1){return buch_num[bn1].holen_buchnum();};

	int Leben_Buch_Titel(string bn2)
	{
		if(Length()==0)
		{
			return 0;
		}
		for(int i=0;i<length;i++)
		{
			if(bn2==buch_num[i].holen_titel())
			{
				BN=i;
				return 1;
			}
		}
		return 0;
	};
	int Leben_Buch_Autor(string bn2)
	{
		if(Length()==0)
		{
			return 0;
		}
		for(int i=0;i<length;i++)
		{
			if(bn2==buch_num[i].holen_autor())
			{
				
				BN=i;
				return 1;
			}
		}
		return 0;
	};
	int Leben_Buch_Num(int bn2)
	{
		if(Length()==0)
		{
			return 0;
		}
		for(int i=0;i<length;i++)
		{
			if(bn2==buch_num[i].holen_buchnum())
			{
				BN=i;
				return 1;
			}
		}
		return 0;
	};
};

template<class T>
SqList<T>::SqList()         //O(1)
{
//	elem=new T[m];					//申请一组连续的空间内存，作为表空间
	buch_num=new Buchdata<int>[M];
//	if(!elem)throw"内存分配失败";	//若申请成功，表属性初始化，长度为0，容量为已申请的储存空间容量
//	if(!buch_num)throw"内存分配失败";
	length=0;
	listsize=M;
}

template<class T>
SqList<T>::~SqList()             //O(1)
{
	delete[]buch_num;		//释放顺序表占用的内存空间
	length=0;
	listsize=0;			//表不存在
}

template<class T>
int SqList<T>::Buch_Num(int bn)			//查询书的剩余量
{
	for(int i=0;i<length;i++)
	{
		if(buch_num[i].holen_buchnum()==bn)
		{
			return buch_num[i].holen_halm();
		}
	}
	
}

template<class T>
int SqList<T>::Buch_weniger(int bn)			//现存量-1
{
	for(int i=0;i<length;i++)
	{
		if(buch_num[i].holen_buchnum()==bn)
		{
			buch_num[i].aindern_halm_weniger();
			return 0;
		}
		
	}
}

template<class T>
int SqList<T>::Buch_Plus(int bn)
{
	for(int i=0;i<length;i++)
	{
		if(buch_num[i].holen_buchnum()==bn)
		{
			buch_num[i].aindern_halm_plus();
			return 0;
		}
	}
		//现存量+1
//	return 0;
}

template<class T>
int SqList<T>::ku_Buch_Plus(int bn)
{
	for(int i=0;i<length;i++)
	{
		if(buch_num[i].holen_buchnum()==bn)
		{
			buch_num[i].aindern_inventar_plus();		//库存量+1
			return 0;
		}
		
	}
}

template<class T>
int SqList<T>::ku_Buch_weniger(int bn)
{
	for(int i=0;i<length;i++)
	{
		if(buch_num[i].holen_buchnum()==bn)
		{
			buch_num[i].aindern_inventar_weniger();		//库存量-1
			return 0;
		}
		
	}
}


template<class T>
int SqList<T>::Buch_Autor(string ba)		//根据书作者查找书信息
{
	for(int i=0;i<Length();i++)
	{
		if(ba==buch_num[i].holen_autor())
		{
			cout<<"书编号为："<<buch_num[i].holen_buchnum()<<"     书名为："<<buch_num[i].holen_titel()<<"     书作者为："<<buch_num[i].holen_autor()<<endl;
			cout<<"现存量为："<<buch_num[i].holen_halm()<<"     库存量为："<<buch_num[i].holen_inventar()<<endl;
			return 0;
		}

	}
	cout<<"未找到该作者，请确认作者！"<<endl;
	return 0;
}

template<class T>
int SqList<T>::Buch_Titel(string ba)		//根据书名查找书信息
{
	for(int i=0;i<Length();i++)
	{
		if(ba==buch_num[i].holen_titel())
		{
			cout<<"书编号为："<<buch_num[i].holen_buchnum()<<"     书名为："<<buch_num[i].holen_titel()<<"     书作者为："<<buch_num[i].holen_autor()<<endl;
			cout<<"现存量为："<<buch_num[i].holen_halm()<<"     库存量为："<<buch_num[i].holen_inventar()<<endl;
			return 0;
		}

	}
	cout<<"未找到该书，请确认书名！"<<endl;
	return 0;
}

template<class T>
int	SqList<T>::Buch_Buchnum(int ba)		//根据书编号查找书信息
{
	for(int i=0;i<Length();i++)
	{
		if(ba==buch_num[i].holen_buchnum())
		{
	//		cout<<"i:"<<i<<"    Length"<<Length()<<endl;
			cout<<"书编号为："<<buch_num[i].holen_buchnum()<<"     书名为："<<buch_num[i].holen_titel()<<"     书作者为："<<buch_num[i].holen_autor()<<endl;
			cout<<"现存量为："<<buch_num[i].holen_halm()<<"     库存量为："<<buch_num[i].holen_inventar()<<endl;
			return 0;
		}

	}
	cout<<"未找到该编号，请确认编号！"<<endl;
	return 0;
}


template<class T>
int SqList<T>::Insert(int i,int bn, string neu_titel, string neu_autor)				 //O(n)，插入新书
{
	if(length>=listsize)
	{
		cout<<"库存满了！装不下了%>_<%"<<endl;
		return 0;
	}
	
//	if(i<1||i>length+1)throw"插入位置异常";
/*	for(int j=length;j>=;j--)						//an~ai依次后移
	{
		buch_num[j].eintrag_titel(buch_num[j-1].holen_titel());
		buch_num[j].eintrag_autor(buch_num[j-1].holen_autor());
		buch_num[j].eintrag_buchnum(buch_num[j-1].holen_buchnum());
		buch_num[j].eintrag_halm(buch_num[j-1].holen_halm());
		buch_num[j].eintrag_inventar(buch_num[j-1].holen_inventar());

	}*/
	
	buch_num[i].eintrag_titel(neu_titel);
	buch_num[i].eintrag_autor(neu_autor);
	buch_num[i].eintrag_buchnum(bn);
	buch_num[i].eintrag_inventar(1);
	buch_num[i].eintrag_halm(1);
	length=length+1;
	listsize--;
	return 1;
}

template<class T>
T SqList<T>::Delete(int i)					 //O(n)
{
	if(length==0)
	{
		cout<<"肚子里空空的，什么也删不了丫(⊙o⊙)…"<<endl;
		return 0;
	}
//	if(i<1||i>length)throw"删除位置异常";
//	e=buch_num[i-1];
	for(j=i;j<length;j++)				//ai~an依次向前移动一个元素位置
	{
		buch_num[j-1]=buch_num[j];
	}
	length--;							//表长减1
	return 0;
}

template<class T>
int SqList<T>::Locate(int e)				//O(n)
{			
//	cout<<"   Length"<<length<<endl;
	for(int i=0;i<Length();i++)
	{
		if(e==buch_num[i].holen_buchnum())
		{
			return i;				//找到，返回该元素在顺序表中的序号(即书的位序)
		}
	}
	return -1;					//未找到，返回-1
}

template<class T>
int SqList<T>::Empty()			//判断表是否为空
{
	if(length==0)
	{
		cout<<"没有书！"<<endl;
		return true;
	}

}

template<class T>
int SqList<T>::Full()				//判断表是否为满
{
	if(length>=listsize)
	{
		cout<<"书装满啦！装不下啦！%>_<%"<<end;
		return true;
	}
}



template<class T>
void SqList<T>::ListDisp()		//输出表元素
{
	
}

//============================================================class Buchdata
template<class T>
class Buchdata//:public BuchOper<T>
{
private:
	int buchnum;		//书编号
	string titel;		//书名
	string autor;		//作者
	int halm;			//现存量
	int inventar;		//库存量
public:
	Buchdata()
	{
		halm=0;
		inventar=0;
		titel="NoneTitel";
		autor="NoneAutor";
	};
	~Buchdata(){};
	int holen_buchnum(){return buchnum;};	//取书编号
	string holen_titel(){return titel;};	//取书名
	string holen_autor(){return autor;};	//取作者

	int holen_halm(){return halm;};			//取现存量
	int holen_inventar(){return inventar;};	//取库存量

	void eintrag_titel(string t){titel=t;};
	void eintrag_autor(string a){autor=a;};
	void eintrag_buchnum(int b){buchnum=b;};

	void eintrag_halm(int h){halm=h;};
	void eintrag_inventar(int i){inventar=i;};

	void aindern_halm_plus(){halm++;};			//现存量+1
	void aindern_halm_weniger(){halm--;};			//现存量-1
	void aindern_inventar_plus(){inventar++;};		//库存量+1
	void aindern_inventar_weniger(){inventar--;};		//库存量-1

};

//============================================================class Reader
template<class T>
class Reader:public SqList<T>
{
private:
	
	int id2;//读者编号
	int geliehen;				//已借的书的总数量
	Buchdata <T>*buch;				//指向书类的指针，用于存储已借书的信息
	int buchsize;
public:
	Reader()
	{
		
		buch=new Buchdata<int>[M];
	//	if(!elem)throw"内存分配失败";	//若申请成功，表属性初始化，长度为0，容量为已申请的储存空间容量
		geliehen=0;
		buchsize=10;
	};


	~Reader()             //O(1)
	{
		delete[]buch;		//释放顺序表占用的内存空间
		geliehen=0;
	};

	int returnID(){return id2;};

	void neu_ID(int i){id2=i;};


	int bibliothek(int buchnum1,SqList *b)		//借书
	{
		int buchnum1_1;
		buchnum1_1=b->Locate(buchnum1);
		//cout<<"buchnum1_1:"<<buchnum1_1<<"     buchnum1:"<<buchnum1<<endl;
		if(buchnum1_1!=-1)		//在书库里定位到此书编号，若不为-1，则说明定位到此书，查找成功
		{
			if(b->Buch_Num(buchnum1)!=0)		//查询此书剩余量，若不为零则继续
			{
				if(buchsize!=0)			//若读者可借书余量不为零，则继续
				{
					cout<<"借书成功！书编号为："<<buchnum1<<endl;
					b->Buch_weniger(buchnum1);			//现存量减一
					buch[geliehen].eintrag_buchnum(buchnum1);		//在读者已借书指针中加入此书
					buch[geliehen].eintrag_autor(b->Get_Buch_Autor(buchnum1));
					buch[geliehen].eintrag_titel(b->Get_Buch_Titel(buchnum1));
					geliehen++;					//已借书数量+1
//					SqList::buch_num.aindern_halm_weniger(buchnum1);
					return 0;
				}
			}
			else
				cout<<"很抱歉，此书以无剩余借书失败！"<<endl;
			return 0;
			
		}
		else
		{
			cout<<"未查到此书，请确认书编号！"<<endl;
			return 0;
		}


	};

	int buchen(int buchnum2,SqList *b)		//还书
	{
		int buchnum2_1;
		buchnum2_1=b->Locate(buchnum2);
		if(buchnum2_1!=-1)		//定位此书后，若书编号匹配，则继续
		{
			b->Buch_Plus(buchnum2);		//对应书号的书数量+1
			cout<<"还书成功！书编号为："<<buchnum2<<endl;
			for(int j=0;j<geliehen;j++)			//查找该书在读者已借书指针中的位置
			{
				if(buch[j].holen_buchnum()==buchnum2)		//若查找到
				{		
					geliehen--;							//已借书数量-1
					if(j==geliehen-1)
						delete [j]buch;
					else
					{
						for(int k=j+1;k<geliehen;k++)				//ai~an依次向前移动一个元素位置（覆盖此书位置）
							buch[k-1]=buch[k];
					}
				}


			}
			return true;
		}
		else
		{
			cout<<"还书失败！请确认书编号！"<<endl;
			return false;
		}

	};

	int readerdata()			//读者信息
	{
		cout<<"读者编号："<<id2<<endl;
		cout<<"已借书数量："<<geliehen<<endl;
		cout<<"已借书信息："<<endl;
		for(int j=0;j<geliehen;j++)
		{
			if(buch[j].holen_buchnum()==NULL)
				return 0;
			cout<<"编号"<<buch[j].holen_buchnum()<<"    书名："<<buch[j].holen_titel()<<"     作者："<<buch[j].holen_autor()<<endl;

		}
		return 0;
	}



};

//============================================================Main
int main()
{
	BuchOper <int>MenschenEin;

	int e1,e2,id1;
	cout<<"欢迎进入图书管理系统！"<<endl;
	do
	{
		cout<<"0.登陆"<<endl;
		cout<<"1.新书入库"<<endl;
		cout<<"2.借阅"<<endl;
		cout<<"3.归还"<<endl;
		cout<<"4.查询"<<endl;
		cout<<"5.注册"<<endl;
		cin>>e1;
		cout<<endl;
		switch(e1)
		{
		case 0:				//登陆
			{
				cout<<"请输入您的ID号：";
				cin>>id1;
				cout<<endl;
				MenschenEin.ID_Gelandet(id1);

				break;
			}
		case 1:				//新书入库
			{
				MenschenEin.Neu_Buch();
				break;	
			}
		case 2:
			{
				MenschenEin.Mieten_Buch();
				break;
			}
		case 3:				//归还
			{
				MenschenEin.Zurueck_Buch();
				break;
			}
		case 4:				//查询
			{
				cout<<"41.查询图书信息"<<endl;
				cout<<"42.查询借阅信息"<<endl;
				cin>>e2;
				switch(e2)
				{
				case 41:
					{
						MenschenEin.Anfrage_Buch_Info();
						break;
					}

				case 42:
					{
						MenschenEin.Anfrage_Reader_Info();
						break;
					}
				
				}
				cout<<endl;
				break;
			}
		case 5:
			{
				MenschenEin.ID_Eintragung();
				break;
			}
		
		}
		cout<<endl;
	}while(e1);





	return 0;
}

