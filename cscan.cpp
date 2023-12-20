#include<bits/stdc++.h>
#include<vector>
using namespace std;
int d=0;


int main()
{
	int n;
	cin>>n;
	vector<int> track;
	vector<bool> v(n,false);
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		track.push_back(x);
	}
	int head;
	cin>>head;
	track.push_back(0);
	track.push_back(199);
	vector<int>right,left;
	for(int i=0;i<track.size();i++)
	{
		if(track[i]<head)
		{
			left.push_back(track[i]);
		}
		else
		{
			right.push_back(track[i]);
		}
	}
	sort(right.begin(),right.end());
	sort(left.begin(),left.end());
	int max=0;
	int max2=10000;
	
	for(int i=0;i<right.size();i++)
	{
		if(abs(head-right[i])<max2)
		{
			max2=abs(head-right[i]);
		}
	}
	d+=max2;
	
	for(int i=0;i<right.size();i++)
	{
		if(right[i]>max)
		{
			max=right[i];
		}
	}
	int min=0;
		for(int i=0;i<left.size();i++)
	{
		if(left[i]>min)
		{
			min=left[i];
		}
	}
	
	int rightd=abs(max-right[0]);
	int middled=abs(max-left[0]);
	int leftd=abs(left[0]-min);
	
	int result=leftd+rightd+middled;
	d+=result;
	cout<<d;
	
}
