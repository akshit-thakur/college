#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <time.h>
#include <vector>
using namespace std;
class Job
{
public:
    double arrivalTime;
    double serviceTime;
    int terminal;
    Job()
    {
        arrivalTime = 0.0;
        serviceTime = 0.0;
        terminal = 0;
    }
    Job(int terminal, double arrivalTime, double serviceTime)
    {
        this->terminal = terminal;
        this->arrivalTime = arrivalTime;
        this->serviceTime = serviceTime;
    }
};

const int TESTS = 1000;
const int TERMINALS = 80;
const int JOBS = 1000;
const double Q = 3; //time quantum on CPU
const double SWAP_TIME = 0;
double *thinkTimes = new double[TERMINALS];
bool *terminalFree = new bool[TERMINALS];

double findMinThinkTime()
{
    double min = 100000000.0;
    for (int i = 0; i < TERMINALS; i++)
    {
        if (terminalFree[i] && thinkTimes[i] < min)
            min = thinkTimes[i];
    }
    return min;
}
int main()
{
    srand(time(0));
    double queueLengthTotal = 0, utilizationTotal = 0, responseTimeTotal = 0;
    for (int test = 0; test < TESTS; test++)
    {
        vector<Job> queue;
        int jobsDone = 0;
        double elapsedTime = 0;   //simulation clock
        double utilization = 0.0; //of CPU
        double lastFree = 0.0;    //CPU stats
        double queueArea = 0.0;   //area of Queue-time graph

        bool isCPUidle = true;     //cpu stat
        double responseTime = 0.0; //for process(sum)
        double queueTime = 0.0;    //x axis of QueueTime graph
        double lastQueueTime = 0.0;

        for (int i = 0; i < TERMINALS; i++)
        {
            thinkTimes[i] = ((rand() % (10 - 1 + 1)) + 1); //between 1 and 10
            terminalFree[i] = true;
        }
        while (jobsDone < JOBS)
        {
            int minThinkTime = findMinThinkTime(); //the minimum think time (not the terminal with mininum think time)
            if (elapsedTime < minThinkTime)
            {
                //do nothing
            }
            else
            {
                int queueSizeBefore = queue.size(); //the y-axis of area graph before arrival.
                //arrivals....................
                //can have same think time
                for (int i = 0; i < TERMINALS; i++)
                { //for every free terminal having thinkTime = minThinkTime, schedule a job from that terminal
                    if (terminalFree[i] && thinkTimes[i] == minThinkTime)
                    {
                        Job job(i, elapsedTime, (double)(rand() % (30 - 1 + 1) + 1)); //service time is between zero to thirty seconds.
                        queue.push_back(job);
                        terminalFree[i] = false; //terminal is now busy
                    }
                }
                int queueSizeAfter = queue.size(); //the y-axis of area graph after arrival.
                if (queueSizeAfter == queueSizeBefore)
                {
                    //nothing is to added if no new arrivals.
                }
                else
                {
                    queueTime = (elapsedTime - 1) + minThinkTime; // -1 to compensate for +1 done on job exit.
                    queueArea += (double)(queueSizeBefore * (queueTime - lastQueueTime));
                    lastQueueTime = queueTime; //update the x axis to the point where the change occured.
                }
                if (isCPUidle)
                {
                    isCPUidle = false;
                    utilization += elapsedTime - lastFree;
                }
            }
            elapsedTime += 1;        //after arrival,simulation clock runs only 1 second.
            Job nextJob(-1, -1, -1); //default job (in case zero jobs in queue)
            //start CPU Run
            if (queue.size() > 0) //follow the flowchart.
            {
                nextJob = queue.at(0);
                queue.erase(queue.begin());
                double cpuTime = min(Q, nextJob.serviceTime);
                nextJob.serviceTime -= cpuTime;
                elapsedTime += (cpuTime + SWAP_TIME);
            }
            else //if no job to process,update cpu status
            {
                isCPUidle = true;
                lastFree = elapsedTime;
            }
            //end CPU Run
            if (nextJob.serviceTime > 0)
            {
                queue.push_back(nextJob); //put it back to queue
                elapsedTime += 1;
            }
            else if (nextJob.serviceTime != -1) //if not default job
            {
                terminalFree[nextJob.terminal] = true; //the terminal is now free to schedule next process.
                jobsDone += 1;
                responseTime += (elapsedTime - nextJob.arrivalTime);               //the response time of the job just completed
                queueArea += ((queue.size() + 1) * (elapsedTime - lastQueueTime)); //area under the queue-time graph
                lastQueueTime = elapsedTime;
                elapsedTime += 1;
            }
        }
        utilization += elapsedTime - lastFree; //in case CPU not free after simulation over
        queueLengthTotal += (queueArea / queueTime);
        utilizationTotal += (utilization / elapsedTime);
        responseTimeTotal += (responseTime / JOBS);
    }
    cout << "After " << TESTS << " tests on " << TERMINALS << " terminals having random think time on each run for " << JOBS << " number of jobs\n";
    cout << "The utilization of CPU is: " << (utilizationTotal / TESTS) * 100 << "%\n";
    cout << "Average response time per job is: " << (responseTimeTotal / TESTS) << " units of time.\n";
    cout << "Average queue length: " << (queueLengthTotal / TESTS) << " processes.\n";
    return 0;
}
