#include<iostream>
#include<list>
#include<stdio.h>
using namespace std;

main()
{
	int i=0;
	list<int> A;
	list<int>::iterator it;
	while(i!=1)
	{
		cout<<"Choice :\n1.Create Node\n2.Add at Begin\n3.Insert after\n4.Delete\n5.Display\n6.Count\n7.Reverse\n8.Quit";
		cout<<"\nEnter your choice : ";
		int c,e;
		cin>>c;
		if(c==1)
		{
					cout<<"Enter element : ";
					cin>>e;
					A.push_back(e);
					cout<<endl;
		}
		else if(c==2)
		{
					cout<<"Enter element : ";
					cin>>e;
					A.push_front(e);
					cout<<endl;
		}
		else if(c==3)
		{ 
			cout<<"Enter location : ";
			int l;
			it=A.begin();
			cin>>l;
			for(int n=0;n<l;n++)
				it++;
			cout<<"Enter element : ";
			cin>>e;
			A.insert(it,e);
			cout<<endl;
		}
		else if(c==4)
		{
			cout<<"Enter location : ";
			int l;
			it=A.begin();
			cin>>l;
			for(int n=0;n<l-1;n++)
				it++;
			A.erase(it);
			cout<<endl;
		}
		else if(c==5)
		{
			int count=A.size();
			it=A.begin();
			for(int n=0;n<count;n++)
			{
				cout<<*it<<"<->";
				it++;
			}
			cout<<"NULL";
			cout<<endl;
		}
		else if(c==6)
		{
			cout<<"Size = "<<A.size();
			cout<<endl;
		}
		else if(c==7)
		{
			A.reverse();
			cout<<endl;
		}
		else if(c==8)
		{
			i=1;
			cout<<endl;
		}
		else cout<<"Error!";
	}
}
