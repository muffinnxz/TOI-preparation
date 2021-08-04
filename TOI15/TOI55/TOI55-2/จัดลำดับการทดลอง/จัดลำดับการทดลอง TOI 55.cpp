#include<iostream>
#include<list>
#include<queue>
#include<math.h>
using namespace std;

int allpos(int x,int n,int N)
{
	int i,v;
	int worka=N,workb=N;
	list<unsigned long long int> pos;
	for(i=0;i<n;i++)
	{
		v=(x&(1<<i))!=0;
		if(v==1)
		{
			if(worka>0)
			{
				pos.push_back(1);
				worka--;
			}
			else if(workb>0)
			{
				pos.push_back(2);
				workb--;
			}
			else break;
		}
		else
		{
			if(workb>0)
			{
				pos.push_back(2);
				workb--;
			}
			else if(worka>0)
			{
				pos.push_back(1);
				worka--;
			}
			else break;
		}
		if(worka<=0&&workb<=0) break;
	}
	
	int posn=pos.size();
	unsigned long long int result=0;
	
	for(i=0;i<posn;i++)
	{
		result+=(pos.front()*pow(10,i));
		pos.pop_front();
	}
	
	return result;
}

main()
{
	int M,N,i,j;
	cin>>M;
	cin>>N;
	
	list<unsigned long long int> worka_w,workb_w;
	for(i=0;i<N;i++)
	{
		int temp;
		cin>>temp;
		worka_w.push_back(temp);
	}
	for(i=0;i<N;i++)
	{
		int temp;
		cin>>temp;
		workb_w.push_back(temp);
	}
	
	list<unsigned long long int> psb;
	int alln=pow(2,2*N);
	for(i=0;i<alln;i++)
		psb.push_back(allpos(i,2*N,N));
	
	psb.sort();
	psb.unique();
	
	list<unsigned long long int>::iterator it,itp;
	int fastest_alg=9999999;
	int algcount[psb.size()];
	int count=0,ualg;
	for(it=psb.begin();it!=psb.end();it++)
	{
		list<unsigned long long int> worka_temp,workb_temp;
		for(itp=worka_w.begin();itp!=worka_w.end();itp++)
			worka_temp.push_back(*itp);
		for(itp=workb_w.begin();itp!=workb_w.end();itp++)
			workb_temp.push_back(*itp);
			
		int temp=*it;
		int worka_n=N,workb_n=N;
		int workpd=0,dayc=0;
		for(i=0;i<2*N;i++)
		{
			int p=temp%10;
			if(p==1)
			{
				if(workpd+worka_temp.front()<=M)
				{
					workpd+=worka_temp.front();
					worka_temp.pop_front();	
				}
				else
				{
					dayc++;
					workpd=worka_temp.front();
					worka_temp.pop_front();	
				}
			}
			else
			{
				if(workpd+workb_temp.front()<=M)
				{
					workpd+=workb_temp.front();
					workb_temp.pop_front();	
				}
				else
				{
					dayc++;
					workpd=workb_temp.front();
					workb_temp.pop_front();	
				}
			}
			temp/=10;	
		}	
		if(dayc+1<=fastest_alg) 
		{
			fastest_alg=dayc+1;
			ualg=count;
		}
		algcount[count]=workpd;
		count++;
	}
	cout<<fastest_alg<<endl<<algcount[ualg];
}
