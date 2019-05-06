// buch.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"			//��ʹ��vc6.0���ϰ��vs����ô��Ҫ����ע�͵�
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
	Reader <T>*id;		//����ָ��
	SqList <T>b;
	int menschen;		//�ѽ�������
	int menschensize;	//�������û�����
public:
	BuchOper()
	{
		id=new Reader<int>[M];
		menschen=0;
		menschensize=M;
	};

	~BuchOper()
	{
		delete[]id;		//�ͷ�˳���ռ�õ��ڴ�ռ�
		menschen=0;
		menschensize=0;
	};

	void ID_Eintragung()			//ע�����û�
	{
		if(menschensize!=0)
		{
			int i;
			cout<<"��������У�"<<menschensize<<"�����粻�������ɣ���ϲ�㻹�л���ע��"<<endl;
			cout<<"����ǩ����Լ���ҳ�Ϊ����ա��������ԣ�����������û�ID�������֣���";
			cin>>i;
			id[menschen].neu_ID(i);
			cout<<endl;
			menschen++;
			menschensize--;
		}
	};

	int ID_Gelandet(int i)		//��½
	{
		if(IDS==-1)
		{
			for(int j=0;j<menschen;j++)
			{
				if(i==id[j].returnID())
				{
					IDS=j;
					return j;		//�����û�id��ţ���id��
				}
			}
			IDS=-1;
			return -1;			//������-1����˵����Ҫע��
		}
		else
		{
			cout<<"���Ѿ������׼�����ID�ˣ����������𣿲���Ҫ�ٴε�½��Ӵ~"<<endl;
			return IDS;			//�����û�id��ţ���id��
		}
		
	};

	void Zurueck_Buch()		//����
	{
		if(IDS==-1)
		{
			cout<<"����û�и����׼����id�أ���ô���鰡������ȥ��½��~"<<endl;
		}
		else
		{
			int bn;
			cout<<"������׼���Ҫ�黹�������ţ�";
			cin>>bn;
			cout<<endl;
			id[IDS].buchen(bn,&b);
		}
	};

	void Mieten_Buch()		//����
	{
		if(IDS==-1)
		{
			cout<<"����û�и����׼����id�أ���ô���鰡������ȥ��½��~"<<endl;
		}
		else
		{
			int bn;
			cout<<"������׼���Ҫ����������ţ�";
			cin>>bn;
		//	cout<<endl;
			id[IDS].bibliothek(bn,&b);
		}
	};

	void Anfrage_Reader_Info()		//���߸�����Ϣ��ѯ
		{
			if(IDS==-1)
			{
				cout<<"����û�и����׼����id�أ���ô��������Ϣ��������ȥ��½��~"<<endl;
			}
			else
			{
				id[IDS].readerdata();
			}
		};

	void Anfrage_Buch_Info()			//�鼮��Ϣ��ѯ
		{
			int e1;
			int t1;
			string t2,t3;
			cout<<"������ϣ������ʲô�������鼮�������1������2������3����";
			cin>>e1;
			switch(e1)
			{
			case 1:
				{
					cout<<"��������鼮�ı�ţ�";
					cin>>t1;
					cout<<endl;
					b.Buch_Buchnum(t1);
					break;
				}
			case 2:
				{
					cout<<"���������Ҫ���ҵ����ߣ�";
					cin>>t2;
					cout<<endl;
					b.Buch_Autor(t2);
					break;
				}
			case 3:
				{
					cout<<"���������Ҫ���ҵ�������";
					cin>>t3;
					cout<<endl;
					b.Buch_Titel(t3);
					break;
				}
			}
		};

	void Neu_Buch()		//�������
		{
			int n=0,bn,a=0;
			string nt;
			string na;
			char c;
			while(a==0)
			{
				cout<<"���������ţ�";
				cin>>bn;
				
				if(b.Leben_Buch_Num(bn)==1)
				{
					b.Buch_Plus(BN);
					b.ku_Buch_Plus(BN);
					continue;
				}
				
				cout<<"�������鼮���ƣ�";
				cin>>nt;
				if(b.Leben_Buch_Titel(nt)==1)
				{
					b.Buch_Plus(BN);
					b.ku_Buch_Plus(BN);
					continue;
				}
				cout<<"�������鼮���ߣ�";
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
					cout<<"���ɹ���"<<endl;
					cout<<"����ӵ���鼮"<<b.Length()<<"��"<<"    �ֿ�ʣ��ռ䣺"<<b.Listsize()<<endl;
					n++;
				}
				else
				{
					cout<<"���ʧ�ܣ�"<<endl;
				}
				cout<<"ϣ���������ɣ���y/n��:";
				cin>>c;
				if(c=='n'||c=='N')
				{
					cout<<"������"<<endl;
					cout<<"����ӵ���鼮"<<b.Length()<<"��"<<"    �ֿ�ʣ��ռ䣺"<<b.Listsize()<<endl;
					cout<<"�˴�����¼��"<<n<<"���鼮"<<endl;
					break;
				}
				a=0;
				while(a==0)
				{
					cout<<"���������ţ�";
					cin>>bn;
					
					if(b.Leben_Buch_Num(bn)==1)
					{
						b.Buch_Plus(BN);
						b.ku_Buch_Plus(BN);
						continue;
					}
					
					cout<<"�������鼮���ƣ�";
					cin>>nt;
					if(b.Leben_Buch_Titel(nt)==1)
					{
						b.Buch_Plus(BN);
						b.ku_Buch_Plus(BN);
						continue;
					}
					cout<<"�������鼮���ߣ�";
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
//	T * elem;				//�����ַ
	Buchdata <T>*buch_num;		//�������飬���ڴ洢δ�������Ϣ
	int length;				//��
	
	int listsize;			//������
public:
//	SqList(){};
	SqList();			//���캯������������Ϊm�Ŀձ�
	~SqList();				//����������ɾ����ռ�
	void CreateList(int n);	//��������n��Ԫ�ص����Ա�
	int Insert(int i,int bn, string neu_titel, string neu_autor);	//�ڱ��е�i��λ�ò���Ԫ��e�����룩
	T Delete(int i);		//ɾ�����е�i��Ԫ�أ�ɾ����
	T GetElem(int i);		//��ȡ��i��Ԫ�ص�ֵ�����ң�
	int Locate(int e);		//Ԫ�ض�λ������λ�ã�
	void Clear();			//��ձ�
	int Empty();			//�жϱ��Ƿ�Ϊ��
	int Full();				//�жϱ��Ƿ�Ϊ��
	int Length(){return length;};			//��������
	int Listsize(){return listsize;};
	void ListDisp();		//�����Ԫ��
	int Buch_Num(int bn);
	
	int Buch_weniger(int bn);		//�ִ���+-
	int Buch_Plus(int bn);

	int ku_Buch_weniger(int bn);		//�ִ���+-
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
//	elem=new T[m];					//����һ�������Ŀռ��ڴ棬��Ϊ��ռ�
	buch_num=new Buchdata<int>[M];
//	if(!elem)throw"�ڴ����ʧ��";	//������ɹ��������Գ�ʼ��������Ϊ0������Ϊ������Ĵ���ռ�����
//	if(!buch_num)throw"�ڴ����ʧ��";
	length=0;
	listsize=M;
}

template<class T>
SqList<T>::~SqList()             //O(1)
{
	delete[]buch_num;		//�ͷ�˳���ռ�õ��ڴ�ռ�
	length=0;
	listsize=0;			//������
}

template<class T>
int SqList<T>::Buch_Num(int bn)			//��ѯ���ʣ����
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
int SqList<T>::Buch_weniger(int bn)			//�ִ���-1
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
		//�ִ���+1
//	return 0;
}

template<class T>
int SqList<T>::ku_Buch_Plus(int bn)
{
	for(int i=0;i<length;i++)
	{
		if(buch_num[i].holen_buchnum()==bn)
		{
			buch_num[i].aindern_inventar_plus();		//�����+1
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
			buch_num[i].aindern_inventar_weniger();		//�����-1
			return 0;
		}
		
	}
}


template<class T>
int SqList<T>::Buch_Autor(string ba)		//���������߲�������Ϣ
{
	for(int i=0;i<Length();i++)
	{
		if(ba==buch_num[i].holen_autor())
		{
			cout<<"����Ϊ��"<<buch_num[i].holen_buchnum()<<"     ����Ϊ��"<<buch_num[i].holen_titel()<<"     ������Ϊ��"<<buch_num[i].holen_autor()<<endl;
			cout<<"�ִ���Ϊ��"<<buch_num[i].holen_halm()<<"     �����Ϊ��"<<buch_num[i].holen_inventar()<<endl;
			return 0;
		}

	}
	cout<<"δ�ҵ������ߣ���ȷ�����ߣ�"<<endl;
	return 0;
}

template<class T>
int SqList<T>::Buch_Titel(string ba)		//����������������Ϣ
{
	for(int i=0;i<Length();i++)
	{
		if(ba==buch_num[i].holen_titel())
		{
			cout<<"����Ϊ��"<<buch_num[i].holen_buchnum()<<"     ����Ϊ��"<<buch_num[i].holen_titel()<<"     ������Ϊ��"<<buch_num[i].holen_autor()<<endl;
			cout<<"�ִ���Ϊ��"<<buch_num[i].holen_halm()<<"     �����Ϊ��"<<buch_num[i].holen_inventar()<<endl;
			return 0;
		}

	}
	cout<<"δ�ҵ����飬��ȷ��������"<<endl;
	return 0;
}

template<class T>
int	SqList<T>::Buch_Buchnum(int ba)		//�������Ų�������Ϣ
{
	for(int i=0;i<Length();i++)
	{
		if(ba==buch_num[i].holen_buchnum())
		{
	//		cout<<"i:"<<i<<"    Length"<<Length()<<endl;
			cout<<"����Ϊ��"<<buch_num[i].holen_buchnum()<<"     ����Ϊ��"<<buch_num[i].holen_titel()<<"     ������Ϊ��"<<buch_num[i].holen_autor()<<endl;
			cout<<"�ִ���Ϊ��"<<buch_num[i].holen_halm()<<"     �����Ϊ��"<<buch_num[i].holen_inventar()<<endl;
			return 0;
		}

	}
	cout<<"δ�ҵ��ñ�ţ���ȷ�ϱ�ţ�"<<endl;
	return 0;
}


template<class T>
int SqList<T>::Insert(int i,int bn, string neu_titel, string neu_autor)				 //O(n)����������
{
	if(length>=listsize)
	{
		cout<<"������ˣ�װ������%>_<%"<<endl;
		return 0;
	}
	
//	if(i<1||i>length+1)throw"����λ���쳣";
/*	for(int j=length;j>=;j--)						//an~ai���κ���
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
		cout<<"������տյģ�ʲôҲɾ����Ѿ(��o��)��"<<endl;
		return 0;
	}
//	if(i<1||i>length)throw"ɾ��λ���쳣";
//	e=buch_num[i-1];
	for(j=i;j<length;j++)				//ai~an������ǰ�ƶ�һ��Ԫ��λ��
	{
		buch_num[j-1]=buch_num[j];
	}
	length--;							//����1
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
			return i;				//�ҵ������ظ�Ԫ����˳����е����(�����λ��)
		}
	}
	return -1;					//δ�ҵ�������-1
}

template<class T>
int SqList<T>::Empty()			//�жϱ��Ƿ�Ϊ��
{
	if(length==0)
	{
		cout<<"û���飡"<<endl;
		return true;
	}

}

template<class T>
int SqList<T>::Full()				//�жϱ��Ƿ�Ϊ��
{
	if(length>=listsize)
	{
		cout<<"��װ������װ��������%>_<%"<<end;
		return true;
	}
}



template<class T>
void SqList<T>::ListDisp()		//�����Ԫ��
{
	
}

//============================================================class Buchdata
template<class T>
class Buchdata//:public BuchOper<T>
{
private:
	int buchnum;		//����
	string titel;		//����
	string autor;		//����
	int halm;			//�ִ���
	int inventar;		//�����
public:
	Buchdata()
	{
		halm=0;
		inventar=0;
		titel="NoneTitel";
		autor="NoneAutor";
	};
	~Buchdata(){};
	int holen_buchnum(){return buchnum;};	//ȡ����
	string holen_titel(){return titel;};	//ȡ����
	string holen_autor(){return autor;};	//ȡ����

	int holen_halm(){return halm;};			//ȡ�ִ���
	int holen_inventar(){return inventar;};	//ȡ�����

	void eintrag_titel(string t){titel=t;};
	void eintrag_autor(string a){autor=a;};
	void eintrag_buchnum(int b){buchnum=b;};

	void eintrag_halm(int h){halm=h;};
	void eintrag_inventar(int i){inventar=i;};

	void aindern_halm_plus(){halm++;};			//�ִ���+1
	void aindern_halm_weniger(){halm--;};			//�ִ���-1
	void aindern_inventar_plus(){inventar++;};		//�����+1
	void aindern_inventar_weniger(){inventar--;};		//�����-1

};

//============================================================class Reader
template<class T>
class Reader:public SqList<T>
{
private:
	
	int id2;//���߱��
	int geliehen;				//�ѽ�����������
	Buchdata <T>*buch;				//ָ�������ָ�룬���ڴ洢�ѽ������Ϣ
	int buchsize;
public:
	Reader()
	{
		
		buch=new Buchdata<int>[M];
	//	if(!elem)throw"�ڴ����ʧ��";	//������ɹ��������Գ�ʼ��������Ϊ0������Ϊ������Ĵ���ռ�����
		geliehen=0;
		buchsize=10;
	};


	~Reader()             //O(1)
	{
		delete[]buch;		//�ͷ�˳���ռ�õ��ڴ�ռ�
		geliehen=0;
	};

	int returnID(){return id2;};

	void neu_ID(int i){id2=i;};


	int bibliothek(int buchnum1,SqList *b)		//����
	{
		int buchnum1_1;
		buchnum1_1=b->Locate(buchnum1);
		//cout<<"buchnum1_1:"<<buchnum1_1<<"     buchnum1:"<<buchnum1<<endl;
		if(buchnum1_1!=-1)		//������ﶨλ�������ţ�����Ϊ-1����˵����λ�����飬���ҳɹ�
		{
			if(b->Buch_Num(buchnum1)!=0)		//��ѯ����ʣ����������Ϊ�������
			{
				if(buchsize!=0)			//�����߿ɽ���������Ϊ�㣬�����
				{
					cout<<"����ɹ�������Ϊ��"<<buchnum1<<endl;
					b->Buch_weniger(buchnum1);			//�ִ�����һ
					buch[geliehen].eintrag_buchnum(buchnum1);		//�ڶ����ѽ���ָ���м������
					buch[geliehen].eintrag_autor(b->Get_Buch_Autor(buchnum1));
					buch[geliehen].eintrag_titel(b->Get_Buch_Titel(buchnum1));
					geliehen++;					//�ѽ�������+1
//					SqList::buch_num.aindern_halm_weniger(buchnum1);
					return 0;
				}
			}
			else
				cout<<"�ܱ�Ǹ����������ʣ�����ʧ�ܣ�"<<endl;
			return 0;
			
		}
		else
		{
			cout<<"δ�鵽���飬��ȷ�����ţ�"<<endl;
			return 0;
		}


	};

	int buchen(int buchnum2,SqList *b)		//����
	{
		int buchnum2_1;
		buchnum2_1=b->Locate(buchnum2);
		if(buchnum2_1!=-1)		//��λ�����������ƥ�䣬�����
		{
			b->Buch_Plus(buchnum2);		//��Ӧ��ŵ�������+1
			cout<<"����ɹ�������Ϊ��"<<buchnum2<<endl;
			for(int j=0;j<geliehen;j++)			//���Ҹ����ڶ����ѽ���ָ���е�λ��
			{
				if(buch[j].holen_buchnum()==buchnum2)		//�����ҵ�
				{		
					geliehen--;							//�ѽ�������-1
					if(j==geliehen-1)
						delete [j]buch;
					else
					{
						for(int k=j+1;k<geliehen;k++)				//ai~an������ǰ�ƶ�һ��Ԫ��λ�ã����Ǵ���λ�ã�
							buch[k-1]=buch[k];
					}
				}


			}
			return true;
		}
		else
		{
			cout<<"����ʧ�ܣ���ȷ�����ţ�"<<endl;
			return false;
		}

	};

	int readerdata()			//������Ϣ
	{
		cout<<"���߱�ţ�"<<id2<<endl;
		cout<<"�ѽ���������"<<geliehen<<endl;
		cout<<"�ѽ�����Ϣ��"<<endl;
		for(int j=0;j<geliehen;j++)
		{
			if(buch[j].holen_buchnum()==NULL)
				return 0;
			cout<<"���"<<buch[j].holen_buchnum()<<"    ������"<<buch[j].holen_titel()<<"     ���ߣ�"<<buch[j].holen_autor()<<endl;

		}
		return 0;
	}



};

//============================================================Main
int main()
{
	BuchOper <int>MenschenEin;

	int e1,e2,id1;
	cout<<"��ӭ����ͼ�����ϵͳ��"<<endl;
	do
	{
		cout<<"0.��½"<<endl;
		cout<<"1.�������"<<endl;
		cout<<"2.����"<<endl;
		cout<<"3.�黹"<<endl;
		cout<<"4.��ѯ"<<endl;
		cout<<"5.ע��"<<endl;
		cin>>e1;
		cout<<endl;
		switch(e1)
		{
		case 0:				//��½
			{
				cout<<"����������ID�ţ�";
				cin>>id1;
				cout<<endl;
				MenschenEin.ID_Gelandet(id1);

				break;
			}
		case 1:				//�������
			{
				MenschenEin.Neu_Buch();
				break;	
			}
		case 2:
			{
				MenschenEin.Mieten_Buch();
				break;
			}
		case 3:				//�黹
			{
				MenschenEin.Zurueck_Buch();
				break;
			}
		case 4:				//��ѯ
			{
				cout<<"41.��ѯͼ����Ϣ"<<endl;
				cout<<"42.��ѯ������Ϣ"<<endl;
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

