Group Members:
1) Anis Zahirah Binti Ahmad Madani (1818060)
2) Nurul Fadhillah Binti Ismail (1811722)
3) Nur Syifa’ Aina Binti Zahaimi (1817794)
4) Nur Asimah Binti Che Mamat (1813212)

Section: 4

# Introduction

In this project, we were assigned to find the optimum class scheduling using 3 algorithms. To find the optimum class, we chose 3 non-preemptive algorithms which are FCFS algorithm, SJF algorithm and Priority Scheduling. Non-preemptive means we cannot stop a class from running to allow another process to run.
First Come First Serve (FCFS) is an operating system scheduling algorithm that automatically executes queued requests and processes in order of their arrival. It is the easiest and simplest CPU scheduling algorithm. In this type of algorithm, processes which requests the CPU first get the CPU allocation first. This is managed with a FIFO queue. The full form of FCFS is First Come First Serve.As the process enters the ready queue, its PCB (Process Control Block) is linked with the tail of the queue and, when the CPU becomes free, it should be assigned to the process at the beginning of the queue.

Shortest Job First (SJF) is an algorithm in which the process having the smallest execution time is chosen for the next execution. This scheduling method can be preemptive or non-preemptive. It significantly reduces the average waiting time for other processes awaiting execution. It is associated with each job as a unit of time to complete.This algorithm method is helpful for batch-type processing, where waiting for jobs to complete is not critical.It can improve process throughput by making sure that shorter jobs are executed first, hence possibly have a short turnaround time.It improves job output by offering shorter jobs, which should be executed first, which mostly have a shorter turnaround time.

Priority Scheduling is a method of scheduling processes that is based on priority. In this algorithm, the scheduler selects the tasks to work as per the priority.The processes with higher priority should be carried out first, whereas jobs with equal priorities are carried out on a round-robin or FCFS basis. Priority depends upon memory requirements, time requirements,etc.A CPU algorithm that schedules processes based on priority.It used in Operating systems for performing batch processes.If two jobs having the same priority are ready it works on a first come,first served basis.In priority scheduling, a number is assigned to each process that indicates its priority level.Lower the number, higher is the priority.In this type of scheduling algorithm, if a newer process arrives, that is having a higher priority than the currently running process, then the currently running process is preempted.


# Consideration

To find the best class scheduling solution, three non-preemptive scheduling algorithms are compared. The algorithms involved in the analysis is First Come First Serve (FCFS), Shortest Job First (SJF) and Priority Scheduling. Similar data is used in arrival time, burst time(duration) and priority to calculate the average waiting time and average turnaround time.

# Analysis

The input for analysis are as below:

|Course Code|Duration|Priority|Arrival Time|
|---|---|---|---|
|2201|3|2|1|
|3401|2|3|2|
|1103|1|1|3|

## FCFS

Give an analysis of your algo and compare it with the other two

Output :
|Course Code|Duration|Waiting Time|Turnaround Time|
|---|---|---|---|
|2201|3|0|3|
|3401|2|3|5|
|1103|1|5|6|

Order of scheduling =

Average waiting time = 2.66667

Average turnaround time = 4.66667

## SJF

Give an analysis of your algo and compare it with the other two

Output : 
|Course Code|Duration|Waiting Time|Turnaround Time|
|---|---|---|---|
|2201|3|3|6|
|3401|2|1|3|
|1103|1|0|1|

Order of scheduling =

Average Waiting Time = 1.33333

Average Turnaround Time = 3.33333

## Priority Scheduling

Give an analysis of your algo and compare it with the other two

Output : 
|Course Code|Duration|Waiting Time|Turnaround Time|
|---|---|---|---|
|2201|3|0|3|
|3401|2|2|4|
|1103|1|3|4|

Order of scheduling =	2201	3401	1103

Average waiting time = 1.66667

Average turnaround time = 3.66667

