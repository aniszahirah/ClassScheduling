/* Simple C++ program for implementation 
of Priority(non-preemptive version scheduling */
/*1. sort the processes according to arrival time  
2. if arrival time is same the acc to priority 
3. apply fcfs 
*/
  
#include<iostream> 
#include <bits/stdc++.h>
using namespace std; 
  
#define totalprocess 3 
  
// Making a struct to hold the given input  
  
struct process 
{ 
int arrival_time,burst_time,priority_,course_code; 
}; 
  
process proc[50];

/* 
Writing comparator function to sort according to priority if  
arrival time is same  
*/
  
bool comp(process a,process b) 
{ 
if(a.arrival_time == b.arrival_time) 
{ 
return a.priority_<b.priority_; 
} 
else
{ 
    return a.arrival_time<b.arrival_time; 
} 
} 
  
// Using FCFS Algorithm to find Waiting time 
void get_wt_time(int wt[]) 
{ 
// declaring service array that stores cumulative burst time  
int service[50]; 
  
// Initilising initial elements of the arrays 
service[0] = proc[0].arrival_time; 
wt[0]=0;

for(int i=1;i<totalprocess;i++) 
{ 
service[i]=proc[i-1].burst_time+service[i-1]; 
  
wt[i]=service[i]-proc[i].arrival_time; 
  
// If waiting time is negative, change it into zero 
      
    if(wt[i]<0) 
    { 
    wt[i]=0; 
    } 
} 
  
} 
  
void get_tat_time(int tat[],int wt[]) 
{ 
// Filling turnaroundtime array 
  
for(int i=0;i<totalprocess;i++) 
{ 
    tat[i]=proc[i].burst_time+wt[i]; 
} 
      
}

void findgc() 
{ 
//Declare waiting time and turnaround time array 
int wt[50],tat[50]; 
  
double wavg=0,tavg=0; 
  
// Function call to find waiting time array 
get_wt_time(wt); 
//Function call to find turnaround time 
get_tat_time(tat,wt); 
      
int start_time[50],complete_time[50]; 
  
start_time[0] = proc[0].arrival_time; 
complete_time[0]=start_time[0]+tat[0]; 
  
// calculating starting and ending time 
for(int i=1;i<totalprocess;i++) 
    { 
        start_time[i]=complete_time[i-1]; 
        complete_time[i]=start_time[i]+tat[i]-wt[i]; 
    } 
      
cout<<"\nCourse code\tStart time\tComplete time\tTurnaround Time\t  Waiting Time"<<endl; 
      
    // display the process details
    
for(int i=0;i<totalprocess;i++) 
    { 
        wavg += wt[i]; 
        tavg += tat[i]; 
          
        cout<<proc[i].course_code<<"\t\t"<< 
            start_time[i]<<"\t\t"<<complete_time[i]<<"\t\t"<< 
            tat[i]<<"\t\t\t"<<wt[i]<<endl; 
    } 
      
        // display the average waiting time 
        //and average turn around time 
    cout<< "\n\nOrder of scheduling : ";
   	for (int i = 0 ; i < 3; i++)
      cout << proc[i].course_code <<" " ;
    cout<<"\n\nAverage waiting time : "; 
    cout<<wavg/(float)totalprocess<<endl; 
    cout<<"\nAverage turnaround time : "; 
    cout<<tavg/(float)totalprocess<<endl; 
  
} 

int main() 
{ 
int coursecode[] = {2201, 3401, 1103};
int arrivaltime[] = {1, 2, 3}; 
int bursttime[] = {3, 2, 1}; 
int priority[] = {2, 3, 1}; 
      
for(int i=0;i<totalprocess;i++) 
{ 
    proc[i].arrival_time=arrivaltime[i]; 
    proc[i].burst_time=bursttime[i]; 
    proc[i].priority_=priority[i]; 
    proc[i].course_code=coursecode[i]; 
    }  
      
    //Using inbuilt sort function 
      
    sort(proc,proc+totalprocess,comp); 
      
    //Calling function findgc for finding Gantt Chart 
      
    findgc();  
  
    return 0; 
}
