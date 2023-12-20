#include<bits/stdc++.h>
using namespace std;
void bestfit(vector<int>blocks,vector<int>process)
{
	vector<int>allocation(process.size(),-1);
	for(int i=0;i<process.size();i++)
	{
		int bestInd=-1;
		for(int j=0;j<blocks.size();j++)
		{
			if(blocks[j]>=process[i])
			{
				if(bestInd==-1)
				{
					bestInd=j;
				}
				else if(blocks[bestInd]<blocks[j])
				{
					bestInd=j;
				}
			}
		}
		if(bestInd!=-1)
		{
			allocation[i]=bestInd;
			blocks[bestInd]-=process[i];
		}	
	}
	cout<<"process_no:\t process_size:\t block_no:"<<endl;
	for(int i=0;i<process.size();i++)	
	{
		cout<<" "<<i+1<<" \t"<<process[i]<<"\t";
		if(allocation[i]!=-1)
		{
			cout<<allocation[i]+1<<endl;
		}
		else
			cout<<"not allocated"<<endl;
	}
}
int main()
{
	int m,n;
	cout<<"enter no.of blocks"<<endl;
	cin>>n;
	cout<<"enter no.of process"<<endl;
	cin>>m;
	vector<int>block,process;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		block.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		process.push_back(x);
	}
	bestfit(block,process);
}
