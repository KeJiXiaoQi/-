#include<iostream>
#include<iomanip>
using namespace std;
typedef struct Node//节点
{
	int v;//节点号
	int deg;//度
	int color;//颜色（0为无色）
	bool flag;//是否着色
}Node;
Node node[50];
typedef struct Edge//边
{
	int e0;//边号
	Node e1;//起始点
	Node e2;//终止点
}Edge;
Edge edge[50];
int node_edge[50][50]={0};//关联矩阵
int downnote[50];//排序角标
int draw_color=1;//初始颜色
int count_1=0;//统计颜色
void inite(int m,int n);//初始化边和节点
void memset(int m,int n);//设置关联矩阵及各节点的度
void sort(int m,int n);//度数排序
void brush_color(int m,int n);//按各节点的度着色
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
		cout<<"输入第"<<j<<"条边"<<endl;
		cin>>a>>b;
		cout<<"第e"<<j<<"边为:(v"<<a<<",v"<<b<<")"<<endl;
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
	cout<<"关联矩阵表示如下:"<<endl;
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
		cout<<"第v"<<i<<"个节点的度为："<<node[i].deg<<endl;
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
	cout<<"度数重新排列呈递减顺序"<<endl;
	for(j=0;j<m;j++)
	{
		cout<<"第v"<<downnote[j]<<"个节点的度数排序"<<node[downnote[j]].deg<<endl;
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
	cout<<"此图共有"<<count_1<<"种颜色，即是"<<count_1<<"色无向连通图"<<endl;
	cout<<"各节点对应的颜色是："<<endl;
	for(i=0;i<m;i++)
	{
		cout<<"第v"<<i<<"个结点的颜色是:";
		switch(node[i].color)
		{
			case 1:
				cout<<setw(2)<<"1--红色"<<endl;
				break;
			case 2:
				cout<<setw(2)<<"2--黄色"<<endl;
				break;
			case 3:
				cout<<setw(2)<<"3--蓝色"<<endl;
				break;
			case 4:
				cout<<setw(2)<<"4--绿色"<<endl;
				break;
			case 5:
				cout<<setw(2)<<"5--黑色"<<endl;
				break;
		}
	}
}
void main()
{
	int m,n;//节点和边
	cout<<"输入节点个数"<<endl;
	cin>>m;
	cout<<"输入边的个数"<<endl;
	cin>>n;
	inite(m,n);
	memset(m,n);
	sort(m,n);
	brush_color(m,n);
	char c;
	bool note=true;
	while(note)
	{
		cout<<"是否继续？是(Y)/否(N)"<<endl;
		cin>>c;
		draw_color=1;
        count_1=0;
		switch(c)
		{
			case 'Y':
				cout<<"输入节点个数"<<endl;
				cin>>m;
				cout<<"输入边的个数"<<endl;
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
