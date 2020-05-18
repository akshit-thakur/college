#include <bits/stdc++.h>
using namespace std;

int simulationClock = 0;
class Job
{
public:
    int id;
    int totalTime;
    int timeLeft;
    int waitingTime;
    int arrivalTime;
    int departureTime;
    int currentState;
    vector<pair<int, int>> sequenceMachine;
    Job() {}
    bool initializeJob()
    {
        if (currentState >= sequenceMachine.size())
            return true;
        if (currentState == 0)
        {
            currentState++;
            this->arrivalTime = simulationClock;
        }
        this->timeLeft = sequenceMachine[currentState].second;
        return false;
    }
    int getMachineNumber()
    {
        if (currentState == 0 || currentState >= sequenceMachine.size())
            return -1;
        return this->sequenceMachine[this->currentState].first;
    }
    void computeStats(int id)
    {
        this->totalTime += departureTime;
        cout << "job id = " << id << " "
             << "Total time = " << totalTime << " waiting time = " << waitingTime << "\n";
    }
    Job(vector<pair<int, int>> sequenceMachine, int id)
    {
        totalTime = 0;
        this->sequenceMachine = sequenceMachine;
        timeLeft = 0;
        totalTime = 0;
        waitingTime = 0;
        arrivalTime = 0;
        departureTime = 0;
        currentState = 0;
        this->id = id;
    }
};

class Machine
{
public:
    int currentJob;
    queue<int> jobQueue;
    bool isIdle;
    int idleTime;
    int totalTime;
    Machine()
    {
        currentJob = -1;
        isIdle = true;
        idleTime = 0;
        totalTime = 0;
    }
    void insertJob(Job &j)
    {
        if (isIdle)
        {
            this->currentJob = j.id;
            j.waitingTime = 0;
            this->isIdle = false;
        }
        else
            jobQueue.push(j.id);
        if (j.currentState == 0)
            j.arrivalTime = simulationClock;
    }

    void departJob(Job j[], int n)
    {
        j[currentJob].departureTime = simulationClock;
        j[currentJob].currentState++;
        j[currentJob].totalTime += (simulationClock - j[currentJob].arrivalTime);
        if (jobQueue.empty() == true)
        {
            this->isIdle = true;
            return;
        }
        else
        {
            this->currentJob = this->jobQueue.front();
            j[currentJob].waitingTime += (simulationClock - j[currentJob].arrivalTime);
            jobQueue.pop();
        }
    }

    void printCurrentStats(int id)
    {
        cout << "Machine number = " << id << " Working on Job = " << currentJob << " Current Queue Size = " << jobQueue.size() << "\n";
    }

    bool run(Job j[], int n, int id)
    {
        if (this->isIdle)
        {
            this->idleTime++;
            return false;
        }
        else
        {
            if (j[this->currentJob].timeLeft == 0)
            {
                this->departJob(j, n);
                return true;
            }
            else
                j[this->currentJob].timeLeft -= 1;
        }
        printCurrentStats(id);
        return false;
    }
};

void run(int n, int m, pair<int, int> **seq)
{
    Job jobs[n + 1];
    int jobsCompleted = 0;
    Machine machines[m + 1];
    for (int i = 1; i <= n; i++)
    {
        vector<pair<int, int>> sequences(m + 1);
        for (int j = 1; j <= m; j++)
            sequences[j] = seq[i][j];
        jobs[i] = Job(sequences, i);
    }
    for (int i = 1; i <= n; i++)
    {
        jobs[i].initializeJob();
        machines[jobs[i].getMachineNumber()].insertJob(jobs[i]);
    }
    while (jobsCompleted != n)
    {
        for (int i = 1; i <= m; i++)
        {
            bool ans = machines[i].run(jobs, n, i);
            if (ans == true)
            {
                int j = machines[i].currentJob;
                bool a = jobs[j].initializeJob();
                if (!a)
                    machines[jobs[j].getMachineNumber()].insertJob(jobs[j]);
                else
                    jobsCompleted++;
            }
        }
        simulationClock++;
    }
    cout << "======================================================================\n";
    cout << "Simulation completed\n";
    int totalTimeSum = 0, waitingTimeSum = 0;
    for (int j = 1; j <= n; j++)
    {
        jobs[j].computeStats(j);
        totalTimeSum += jobs[j].totalTime;
        waitingTimeSum += jobs[j].waitingTime;
    }
    cout << "Averages:\n";
    cout << "Total time " << ((double)totalTimeSum / n) << " units.\n";
    cout << "Waiting time " << ((double)waitingTimeSum / n) << " units.\n";
}

int main()
{
    int numberOfJobs, numberOfMachines; // machines;

    cout << "Enter number of jobs and number of machines\n";
    cin >> numberOfJobs >> numberOfMachines;
    cout << "Enter sequence of machine and time taken for each job eg 1 5 means machine 1 and time = 5 \n";
    pair<int, int> **seq = new pair<int, int> *[numberOfJobs + 1];
    for (int i = 1; i <= numberOfJobs; i++)
    {
        seq[i] = new pair<int, int>[numberOfMachines + 1];
        for (int j = 1; j <= numberOfMachines; j++)
        {
            int machine, time;
            cin >> machine >> time;
            seq[i][j] = {machine, time};
        }
    }
    run(numberOfJobs, numberOfMachines, seq);
    return 0;
}

/*
6 3
1 2 2 3 3 4
2 3 1 2 3 1
1 2 3 1 2 1
3 1 2 1 1 1
3 5 2 4 1 2
1 2 2 1 3 1
*/
