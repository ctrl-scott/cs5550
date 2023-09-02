#include<stdio.h>

// Function to find the waiting time for all processes
void WaitingTime(int process_ids[], int num_processes, 
                     int burst_times[], int waiting_times[])
{
  
    waiting_times[0] = 0;
   

    for (int i = 1; i < num_processes; i++)
        waiting_times[i] =  burst_times[i-1] + waiting_times[i-1];
}

void TurnAroundTime(int process_ids[], int num_processes, 
                        int burst_times[], int waiting_times[], int turn_around_times[])
{

    for (int i = 0; i < num_processes; i++)
        turn_around_times[i] = burst_times[i] + waiting_times[i];
}
   

void avgTime(int process_ids[], int num_processes, int burst_times[])
{
    int waiting_times[num_processes], turn_around_times[num_processes];
    int total_waiting_time = 0, total_turn_around_time = 0;
   

    WaitingTime(process_ids, num_processes, burst_times, waiting_times);
   

    TurnAroundTime(process_ids, num_processes, burst_times, waiting_times, turn_around_times);
   
    printf("Processes   Burst time   Waiting time   Turn around time\n");
  
    for (int i = 0; i < num_processes; i++)
    {
        total_waiting_time += waiting_times[i];
        total_turn_around_time += turn_around_times[i];
        printf("   %d ", (i+1));
        printf("       %d ", burst_times[i]);
        printf("       %d", waiting_times[i]);
        printf("       %d\n", turn_around_times[i]);
    }
    int avg_waiting_time = (float)total_waiting_time / (float)num_processes;
    int avg_turn_around_time = (float)total_turn_around_time / (float)num_processes;
    printf("Average waiting time = %d", avg_waiting_time);
    printf("\n");
    printf("Average turn around time = %d ", avg_turn_around_time);
}
   

int main()
{

    int process_ids[] = {1, 2, 3};
    int num_processes = sizeof process_ids / sizeof process_ids[0];
   

    int burst_time[] = {5,6,2};
    avgTime(process_ids, num_processes,  burst_time);
    return 0;
}