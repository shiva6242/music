#include<bits/stdc++.h>
using namespace std;
int d=0;
int main()
{
	int n;
	cout<<"enter no.of process"	<<endl;
	cin>>n;
	vector<int>arr;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		arr.push_back(x);
	}
	
	cout<<"enter head"<<endl;
	int head;
	cin>>head;
	arr.push_back(199);
	vector<int>left,right;
	for(int i=0;i<arr.size();i++)
	{
		if(arr[i]<head)
		{
			left.push_back(arr[i]);
		}
		else
		{
			right.push_back(arr[i]);
		}
	}
	sort(left.begin(),left.end());
	sort(right.begin(),right.end());
	d=abs(head-right[right.size()-1]);
	d=d+abs(right[right.size()-1]-left[0]);
	cout<<d;
	
}
