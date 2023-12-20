#include<bits/stdc++.h>
using namespace std;
int main()
{
	cout<<"enter the number of process "<<endl;
	int n,m;
	cin>>n;
	cout<<"enter the columns "<<endl;
	cin>>m;
	int Allocation[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int x;
			cin>>x;
			Allocation[i][j]=x;
		}
	}
	int Maximum[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int x;
			cin>>x;
			Maximum[i][j]=x;
		}
	}
	int Need[m][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			Need[i][j]=Maximum[i][j]-Allocation[i][j];
		}
	}
	int aval[m],vis[n],ans[n];
	int ind=0;
	cout<<"enter available resoureces"<<endl;
	for(int i=0;i<m;i++)
	{
		cin>>aval[i];
	}
	for(int i=0;i<n;i++)
	{
		vis[i]=0;
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			int flag=1;
			if(vis[i]==0)
			{
				for(int j=0;j<m;j++)	
				{
					if(aval[j]<Need[i][j])
					{
						flag=0;
						break;
					}
				}
				if(flag==1)
				{
					ans[ind++]=i;
					for(int y=0;y<m;y++)
					{
						aval[y]=aval[y]+Allocation[i][y];
					}	
					vis[i]=1;
				}
			}
//			vis[i]=1;
		}
	}
	int flag=1;
	for(int i=0;i<n;i++)	
	{
		if(vis[i]==0)
		{
			flag=0;
			break;
		}
	}
	if(flag)
	{
		cout<<"safe sequence"<<endl;
		for(int i=0;i<n ;i++)
		{
			cout<<"p"<<ans[i]+1;
		}
		
	}
	else
	{
		cout<<"not a safe sequence";
	}
	return 0;
}

