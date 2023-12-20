#include<bits/stdc++.h>
using namespace std;
struct SJF{
	int at,bt,ct,tat,wt,rt;
	int completed=0;
};
int findMinArrivalTime(struct SJF a[],int n,int time){
	int ind=-1;
	int mini=1000;
	for(int i=0;i<n;i++)
	{
		if(a[i].at<=mini&&a[i].at<=time&&a[i].completed==0)
		{
			mini=a[i].at;
			ind=i;
		}
	}
	return ind;
}
/*
int findMinBurstTime(struct SJF a[],int n,int time)
{
	int ind=-1;
	int mini=1000;
	for(int i=0;i<n;i++){
		if(a[i].bt<=mini&&a[i].at<=time&&a[i].completed==0)
		{
			mini=a[i].bt;
			ind=i;
		}
	}
	return ind;
}
*/
int main()
{
	int n;
	cout<<"enter no.of process"<<endl;
	cin>>n;
	struct SJF a[n];
	for(int i=0;i<n;i++)
	{
		cout<<"enter arrival time of process:";
		cin>>a[i].at;
		cout<<"enter burst time ";
		cin>>a[i].bt;
	
	}
	int completedTime=0;
	int index=0;
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			index=findMinArrivalTime(a,n,completedTime);
			completedTime=a[index].at;
		}
		index=findMinArrivalTime(a,n,completedTime);
		while(index==-1)
		{
			completedTime++;
			index=findMinArrivalTime(a,n,completedTime);
		}
		
		completedTime+=a[index].bt;
		a[index].ct=completedTime;
		a[index].tat=a[index].ct-a[index].at;
		a[index].wt=a[index].tat-a[index].bt;
		a[index].rt=(completedTime-a[index].bt)-a[index].at;
		a[index].completed=1;
	}
	cout<<"at bt ct tat wt rt"<<endl;
	int avgwt=0,avgtat=0;
	for(int i=0;i<n;i++)
	{
		avgwt+=a[i].wt;
		avgtat+=a[i].tat;
		cout<<a[i].at<<"  "<<a[i].bt<<"  "<<a[i].ct<<"  "<<a[i].tat<<"  "<<a[i].wt<<"  "<<a[i].rt<<endl;
	}
	cout<<"average wating time is "<<avgwt/n<<endl<<"average turnaround time is "<<avgtat/n;
}
