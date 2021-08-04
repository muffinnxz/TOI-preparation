// CPP program to find all subsets by backtracking. 
#include <bits/stdc++.h> 
#include <vector>
using namespace std; 
void subsetsUtil(vector<int>& A, vector<vector<int> >& res, 
				vector<int>& subset, int index) 
{ 
	res.push_back(subset); 
	for (int i = index; i < A.size(); i++) { 
 
		subset.push_back(A[i]); 
 
		subsetsUtil(A, res, subset, i + 1); 

		subset.pop_back(); 
	} 

	return; 
} 

vector<vector<int> > subsets(vector<int>& A) 
{ 
	vector<int> subset; 
	vector<vector<int> > res; 
 
	int index = 0; 
	subsetsUtil(A, res, subset, index); 

	return res; 
} 

int main() 
{ 
	vector<int> array;
	for(int i=1;i<=20;i++)
		array.push_back(i); 

	vector<vector<int> > res = subsets(array); 

			
	int i=256200;
		for (int j = 0; j < res[i].size(); j++) 
			cout << res[i][j] << " "; 
		cout << endl; 

	return 0; 
} 

