#include<bits/stdc++.h>
using namespace std;
void FCFS(int arr[],int head,int n)
{
	int seekCount=0;
	int dist,curr;
	for(int i=0;i<n;i++)
	{
		curr=arr[i];
		dist=abs(curr-head);
		seekCount+=dist;
		head=curr;
		
	}
	cout<<"seekcount is "<<seekCount;
	cout<<"seek sequence is"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
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
	FCFS(arr,head,n);
}
