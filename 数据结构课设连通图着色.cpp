#include<iostream>
#include<iomanip>
using namespace std;
typedef struct Node//�ڵ�
{
	int v;//�ڵ��
	int deg;//��
	int color;//��ɫ��0Ϊ��ɫ��
	bool flag;//�Ƿ���ɫ
}Node;
Node node[50];
typedef struct Edge//��
{
	int e0;//�ߺ�
	Node e1;//��ʼ��
	Node e2;//��ֹ��
}Edge;
Edge edge[50];
int node_edge[50][50]={0};//��������
int downnote[50];//����Ǳ�
int draw_color=1;//��ʼ��ɫ
int count_1=0;//ͳ����ɫ
void inite(int m,int n);//��ʼ���ߺͽڵ�
void memset(int m,int n);//���ù������󼰸��ڵ�Ķ�
void sort(int m,int n);//��������
void brush_color(int m,int n);//�����ڵ�Ķ���ɫ
void inite(int m,int n)
{
	int a,b;
	for(int i=0;i<m;i++)
	{
		node[i].v=i;
		node[i].deg=0;
		node[i].color=0;
		node[i].flag=false;
	}
	for(int j=0;j<n;j++)
	{
		cout<<"�����"<<j<<"����"<<endl;
		cin>>a>>b;
		cout<<"��e"<<j<<"��Ϊ:(v"<<a<<",v"<<b<<")"<<endl;
		edge[j].e0=j;
		edge[j].e1.v=a;
		edge[j].e2.v=b;
	}
}
void memset(int m,int n)	
{
	int i,j,s,t;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if((node[i].v==edge[j].e1.v)||(node[i].v==edge[j].e2.v))
			{
				node[i].deg++;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		s=edge[i].e1.v;
		t=edge[i].e2.v;
		node_edge[s][t]=1;
		node_edge[t][s]=1;
	}
	cout<<"���������ʾ����:"<<endl;
	for(i=0;i<m;i++)
	{
		cout<<setw(3);
		for(j=0;j<m;j++)
		{
			cout<<node_edge[i][j]<<setw(3);
		}
		cout<<endl;
	}
	for(i=0;i<m;i++)
	{
		cout<<"��v"<<i<<"���ڵ�Ķ�Ϊ��"<<node[i].deg<<endl;
	}
}
void sort(int m,int n)
{
	int i,j=0,temp;
	for(i=0;i<m;i++)
	{
		downnote[i]=0;
		node[i].flag=true;
	}
	while(j<m)
	{
		for(temp=0;temp<m;temp++)
		{
			if(node[temp].flag)
				break;
		}
		for(i=0;i<m;i++)
		{
			if((node[temp].deg<=node[i].deg)&&node[i].flag)
			{
				temp=i;
			}
		}
		node[temp].flag=false;
		downnote[j]=temp;
		j++;
	}
	cout<<"�����������гʵݼ�˳��"<<endl;
	for(j=0;j<m;j++)
	{
		cout<<"��v"<<downnote[j]<<"���ڵ�Ķ�������"<<node[downnote[j]].deg<<endl;
	}
}
void brush_color(int m,int n)
{
	int i,j,k,p,q,t;
  	for(i=0;i<m;i++)
	{
		node[i].flag=true;
	}
	for(i=0;i<m;i++)
	{
		j=downnote[i];
		if(!node[j].color)
		{
			node[j].color=draw_color;
			for(k=0;k<n;k++)
			{
				if(node[j].v==edge[k].e1.v)
				{
					q=edge[k].e2.v;
					node[q].flag=false;
				}
				else if(node[j].v==edge[k].e2.v)
				{
					q=edge[k].e1.v;
					node[q].flag=false;
				}
			}
			for(p=i;p<m;p++)
			{
				k=downnote[p];
				if(node[k].flag&&!node[k].color)
				{
					node[k].color=draw_color;
					for(t=0;t<n;t++)
					{
						if(node[k].v==edge[t].e1.v)
						{
							q=edge[t].e2.v;
							if(node[q].flag)
							{
								node[q].flag=false;
							}
						}
						if(node[k].v==edge[t].e2.v)
						{
							q=edge[t].e1.v;
							if(node[q].flag)
							{node[q].flag=false;}
						}
					}
				}
			}
			draw_color++;
			count_1++;
		}
		for(p=0;p<m;p++)
		{
			node[p].flag=true;
		}
	}
	cout<<"��ͼ����"<<count_1<<"����ɫ������"<<count_1<<"ɫ������ͨͼ"<<endl;
	cout<<"���ڵ��Ӧ����ɫ�ǣ�"<<endl;
	for(i=0;i<m;i++)
	{
		cout<<"��v"<<i<<"��������ɫ��:";
		switch(node[i].color)
		{
			case 1:
				cout<<setw(2)<<"1--��ɫ"<<endl;
				break;
			case 2:
				cout<<setw(2)<<"2--��ɫ"<<endl;
				break;
			case 3:
				cout<<setw(2)<<"3--��ɫ"<<endl;
				break;
			case 4:
				cout<<setw(2)<<"4--��ɫ"<<endl;
				break;
			case 5:
				cout<<setw(2)<<"5--��ɫ"<<endl;
				break;
		}
	}
}
void main()
{
	int m,n;//�ڵ�ͱ�
	cout<<"����ڵ����"<<endl;
	cin>>m;
	cout<<"����ߵĸ���"<<endl;
	cin>>n;
	inite(m,n);
	memset(m,n);
	sort(m,n);
	brush_color(m,n);
	char c;
	bool note=true;
	while(note)
	{
		cout<<"�Ƿ��������(Y)/��(N)"<<endl;
		cin>>c;
		draw_color=1;
        count_1=0;
		switch(c)
		{
			case 'Y':
				cout<<"����ڵ����"<<endl;
				cin>>m;
				cout<<"����ߵĸ���"<<endl;
				cin>>n;
				inite(m,n);
				memset(m,n);
				sort(m,n);
				brush_color(m,n);
				break;
			case 'N':
				note=false;
				break;
		}
	}
}
