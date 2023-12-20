#include<iostream>
using namespace std;
struct RoundRobin{
    int id;
    int arrivalTime;
    int burstTime;
    int turnAroundTime;
    int completionTime;
    int waitingTime;
    int responseTime;
};
void calculateTimes(struct RoundRobin a[],int n,int quantum)
{
    int reamaingTime[n];
    for(int i=0;i<n;i++)
    {
        reamaingTime[i]=a[i].burstTime;
    }
    int currentTime=0;
    bool allDone=false;
    while (!allDone)
    {
        allDone=true;
        for(int i=0;i<n;i++)
        {
            if(reamaingTime[i]>0)
            {
                allDone=false;
            }
            if(reamaingTime[i]>quantum)
            {
                currentTime=currentTime+quantum;
                reamaingTime[i]-=quantum;

            }
            else{
                currentTime+=reamaingTime[i];
                a[i].completionTime=currentTime;
                reamaingTime[i]=0;
            }
        }
    }
    
}
void calculateTurnAroundTime(struct RoundRobin a[],int n)
{
    for(int i=0;i<n;i++)
    {
        a[i].turnAroundTime=a[i].completionTime-a[i].arrivalTime;
    }
}
void calculateWaitingTime(struct RoundRobin a[],int n)
{
    for(int i=0;i<n;i++)
    {
        a[i].waitingTime=a[i].turnAroundTime-a[i].burstTime;
    }
}
void printTable(struct RoundRobin a[],int n)
{
            cout<<"process  arrivaltime   bursttime  competiontime  turnaround   waitingtime"<<endl;

    for(int i=0;i<n;i++){
        cout<<a[i].id<<"  \t  "<<a[i].arrivalTime<<"  \t  "<<a[i].burstTime<<"  \t  "<<a[i].completionTime<<"  \t  "<<a[i].turnAroundTime<<"  \t  "<<a[i].waitingTime<<endl;
    }
}
int main()
{
    int n,quantum;
    cout<<"enter no.of process"  ;
    cin>>n;
    cout<<"enter quantum ";
    cin>>quantum;
    struct RoundRobin a[n];
    for(int i=0;i<n;i++)
    {
        cout<<"processs"<<i+1<<endl;
        cout<<"enter arival time ";
        a[i].id=i+1;
        cin>>a[i].arrivalTime;
        cout<<"enter burst time ";
        cin>>a[i].burstTime;
    }
    calculateTimes(a,n,quantum);
    calculateTurnAroundTime(a,n);
    calculateWaitingTime(a,n);

    printTable(a,n);
}