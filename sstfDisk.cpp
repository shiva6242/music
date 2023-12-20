#include<bits/stdc++.h>
using namespace std;
int d=0;

void SSTF(int arr[],int vis[],int index,int n)
{
	int value=arr[index];
	int max=INT_MAX;
	int min_index=-1;
	if(vis[index]==1)
		return;
	vis[index]=1;
	for(int i=0;i<n;i++)
	{
		if(i!=index&&!vis[i])
		{
			int temp=abs(value-arr[i]);
			if(temp<max)
			{
				max=temp;
				min_index=i;
			}
		}
	}
	if(min_index!=-1)
	{
				cout<<arr[index]<<" ";

		d=d+max;
		SSTF(arr,vis,min_index,n);
	}
	
}
int main()
{
	int n;
	cout<<"enter no.of process"	<<endl;
	cin>>n;
		int arr[n];

	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"enter head"<<endl;
	int head;
	cin>>head;
	int index=-1;
	int max=INT_MAX;
	int vis[n];
	for(int i=0;i<n;i++)
	{
		vis[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		int temp=abs(head-arr[i]);
		if(temp<max)
		{
			max=temp;
			index=i;
		}
	}
	if(index!=-1)
	{
		d+=max;
		cout<<arr[index]<<" ";
		SSTF(arr,vis,index,n);
	}
	cout<<d;
}
