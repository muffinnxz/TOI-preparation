#include<bits/stdc++.h>
#define endll "\n"
using namespace std;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	
	list<int> train;
	train.push_back(999);
	
	string cmd;
	list<int>::iterator it = train.begin();
	for(int i=0;i<n;i++){
		cin >> cmd;
		if(cmd == "head"){
			it = train.begin();
		}else if(cmd == "next"){
			it++;
			if(it == train.end()) it--;
		}else if(cmd == "tail"){
			it = --train.end();
		}else if(cmd == "add"){
			int num;
			cin >> num;
			list<int>::iterator it2 = it;
			train.insert(++it, num);
			it = it2;
		}else if(cmd == "remove"){
			list<int>::iterator it2 = it;
			if(it != --train.end()) 
				train.erase(++it);
			it = it2;
		}else if(cmd == "call"){
			cout << *it << endll;
		}else{
			while(it != train.end())
				cout << *it++ << " ";
			cout << endll;
			it = --train.end();
		}
	}
}
