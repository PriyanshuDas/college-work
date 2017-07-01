#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter total number of processes:";
	cin>>n;
	cout<<"Enter the burst time:"<<endl;
	
	int bt[20],wt[20],tat[20],avwt=0,avtat=0;
	for(int i=0;i<n; i++)
	{
		cout<<"P("<<"i"<<"):";
		cin>>bt[i];
	}
	wt[0]=0;
	// Calculating waiting time
	    cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time"; 
	for(int i=1;i<n; i++)
		wt[i]=wt[i-1]+bt[i-1];
	for (int i=0; i<n; i++)
	{
		tat[i]=wt[i]+bt[i];
		avwt+=wt[i];
		avtat+=tat[i];
		cout<<"\nP["<<i+1<<"]"<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];

	}
	avwt/=n;
    avtat/=n;
    cout<<"\n\nAverage Waiting Time:"<<avwt;
    cout<<"\nAverage Turnaround Time:"<<avtat<<endl;
    return 0;
}    
