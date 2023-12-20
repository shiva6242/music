#include<iostream>
using namespace std;
int main()
{
    int npage,nframe,pos=0,flag,pageFault=0;
    cout<<"enter no.of pagereference strings";
    cin>>npage;
    cout<<"enter no.of frames";
    cin>>nframe;
    int pages[npage];
    int frames[nframe];
    cout<<"enter those page reference strings";
    for(int i=0;i<npage;i++)
    {
        cin>>pages[i];
    }
    for(int i=0;i<nframe;i++)
    {
        frames[i]=-1;
    }
    for(int i=0;i<npage;i++)
    {
        flag=0;
        for(int j=0;j<nframe;j++)
        {
            if(pages[i]==frames[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            if(pos<nframe)
            frames[pos]=pages[i];
            pageFault++;
            pos++;
            if(pos>=nframe)
            {
                pos=0;
            }
        }
        cout<<"frames\t";
        for(int k=0;k<nframe;k++)
        {
            
            if(frames[k]==-1)
            {
                cout<<"  -  ";
            }
            else{
                cout<<"  "<<frames[k]<<"  ";
            }
        }
        cout<<endl;
    }
    cout<<"Total page faults are "<<pageFault;
}