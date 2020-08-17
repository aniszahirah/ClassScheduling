/* Simple C++ program for implementation 
of SJF scheduling */

#include<iostream> 
using namespace std; 

struct Process
{
   int ccode;     // course code
   int duration;      // class duration or burst time
   int priority;  //priority
   int arrival_time;   //prefered arrival time
};

void findWaitingTime(Process p[], int wt[], int n)
{
    wt[0] = 0;            //waiting time for first process is zero
    //calculate waiting time
    for (int i = 1; i < n; i++)
    {
        wt[i] = p[i-1].duration + wt[i-1];
    }
}

void findTurnaroundTime(Process p[], int wt[], int tat[], int n)
{
	//calculate turnaround time
	for(int i = 0; i < n; i++) 
    { 
    	tat[i] = p[i].duration + wt[i];  
    }	
}

void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  
void arrangeArrival(int num, Process p[]) 
{ 
    for(int i = 0; i < num; i++) 
    { 
        for(int j = 0; j < num - i - 1; j++) 
        { 
            if(p[j].arrival_time > p[j + 1].arrival_time) 
            {   	
                swap(p[j].ccode, p[j + 1].ccode);
                swap(p[j].duration, p[j + 1].duration); 
                swap(p[j].priority, p[j + 1].priority); 
                swap(p[j].arrival_time, p[j + 1].arrival_time); 
            } 
        } 
    } 
} 

void completionTime(int num, Process p[]) 
{ 
    int temp, val; 
    int s[num];
	
    s[0] = p[0].arrival_time + p[0].duration;
      
    for(int i = 1; i < num; i++) 
    { 
        temp = s[i-1]; 
        int low = p[i].duration; 
    	
        for(int j = i; j < num; j++) 
        { 
            if(temp >= p[j].arrival_time && low >= p[j].duration) 
            { 
                low = p[j].duration; 
                val = j; 
            }
    		
       	 	swap(p[val].ccode, p[i].ccode);
        	swap(p[val].duration, p[i].duration); 
        	swap(p[val].priority, p[i].priority); 
        	swap(p[val].arrival_time, p[i].arrival_time); 
        }  
    } 
} 
  
int main() 
{ 
    Process proc[] = {{2201,3,2,1}, {3401, 2, 3,2}, {1103, 1,1,3}}; 
	
    int n = sizeof proc / sizeof proc[0];
    int twt = 0, ttat = 0; 
    int wt[n], tat[n]; 
    
    cout<<"Before Arrange...\n"; 
    cout<<"Process ID\tArrival Time\tPriority\tClass Duration\n"; 
    for(int i = 0; i < n; i++) 
    { 
        cout << proc[i].ccode << "\t\t" << proc[i].arrival_time << "\t\t" << proc[i].priority <<"\t\t" << proc[i].duration << "\n"; 
    } 
    
    arrangeArrival(n, proc);
    completionTime(n, proc); 
    findWaitingTime(proc, wt, n);
    findTurnaroundTime(proc, wt, tat, n);
    
    cout<<"\nFinal Result...\n"; 
    cout<<"Process ID\tArrival Time\tPriority\tClass Duration\tWaiting Time\tTurnaround Time\n"; 
    for(int i = 0; i < n; i++) 
    { 
    	twt += wt[i];
        ttat += tat[i];
    	cout << proc[i].ccode << "\t\t" << proc[i].arrival_time << "\t\t" << proc[i].priority <<"\t\t" << proc[i].duration << "\t\t" << wt[i] << "\t\t" << tat[i] << "\n"; 
    }  
    
    cout << "\n\nAverage Waiting Time = " << (float)twt / (float)n;     //average waiting time
    cout << "\nAverage Turnaround Time = " << (float)ttat / (float)n;     //average turnaround time;
     
    return 0;
} 

