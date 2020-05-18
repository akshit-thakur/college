#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <time.h>
using namespace std;

const int TESTS = 1000;

class Event
{
public:
    int serviceTime;
    int queueLength;
    bool status;
};
class Customer
{
public:
    int arrival, departure, serviceStart, serverNumber;
    float delay;
};
class Server
{
public:
    int queueLength;
    deque<Customer> customerQueue;
    bool isFree;
    Event e[30];
    int i;
};
int main()
{
    srand(time(0));
    float delaySum = 0, utilizationSum = 0, queueSum = 0;
    for (int test = 0; test < TESTS; test++)
    {
        int arrival[31], departure[31], interarrival[31], serviceTime[31];
        int i;
        float delay = 0;
        for (i = 1; i <= 30; i++)
        {
            interarrival[i] = (rand() % (5 - 1 + 1)) + 1;
            serviceTime[i] = (rand() % (20 - 5 + 1)) + 5;
        }
        arrival[1] = interarrival[1];
        for (i = 2; i <= 30; i++)
        {
            arrival[i] = arrival[i - 1] + interarrival[i];
        }
        queue<Customer> c, cf;
        Customer customer, ctp;
        for (i = 1; i <= 30; i++)
        {
            customer.arrival = arrival[i];
            customer.serviceStart = serviceTime[i];
            c.push(customer);
        }
        Server server[6];
        for (i = 1; i <= 5; i++)
        {
            server[i].isFree = false;
            server[i].queueLength = 0;
            server[i].i = 0;
        }
        for (i = 1; i <= 5; i++)
        {
            server[i].e[server[i].i].serviceTime = 0;
            server[i].e[server[i].i].queueLength = server[i].queueLength;
            server[i].e[server[i].i].status = server[i].isFree;
        }
        int simulationClock = 0, o, serverMin, j;
        while (simulationClock <= 70)
        {
            serverMin = 1;
            for (i = 1; i <= 5; i++)
            {
                if (server[i].queueLength < server[serverMin].queueLength)
                    serverMin = i;
            }
            if (server[serverMin].queueLength == 0)
                server[serverMin].isFree = false;
            customer = c.front();
            if (simulationClock == customer.arrival)
            {
                if (server[serverMin].isFree == false)
                {
                    customer.serverNumber = serverMin;
                    customer.departure = customer.serviceStart + simulationClock;
                    customer.delay = 0;
                    delay += customer.delay;
                    server[serverMin].queueLength++;
                    server[serverMin].customerQueue.push_back(customer);
                    server[serverMin].isFree = true;
                    c.pop();
                    o = server[serverMin].i + 1;
                    server[serverMin].e[o].serviceTime = simulationClock;
                    server[serverMin].e[o].queueLength = server[serverMin].queueLength;
                    server[serverMin].e[o].status = server[serverMin].isFree;
                    server[serverMin].i = o;
                }
                else
                {
                    server[serverMin].isFree = true;
                    customer.serverNumber = serverMin;
                    server[serverMin].customerQueue.push_back(customer);
                    server[serverMin].queueLength++;
                    o = server[serverMin].i + 1;
                    server[serverMin].e[o].serviceTime = simulationClock;
                    server[serverMin].e[o].queueLength = server[serverMin].queueLength;
                    server[serverMin].e[o].status = server[serverMin].isFree;
                    server[serverMin].i = o;
                    c.pop();
                }
            }
            for (i = 1; i <= 5; i++)
            {
                if (server[i].queueLength == 0)
                    server[i].isFree = false;
                else if (server[i].queueLength == 1)
                {
                    if (simulationClock == server[i].customerQueue.front().departure)
                    {
                        cf.push(server[i].customerQueue.front());
                        server[i].customerQueue.pop_front();
                        server[i].queueLength = 0;
                        server[i].isFree = false;
                        o = server[i].i + 1;
                        server[i].e[o].serviceTime = simulationClock;
                        server[i].e[o].queueLength = server[i].queueLength;
                        server[i].e[o].status = server[i].isFree;
                        server[i].i = o;
                    }
                }
                else
                {
                    if (simulationClock == server[i].customerQueue.front().departure)
                    {
                        server[i].queueLength--;
                        server[i].isFree = true;
                        o = server[i].i + 1;
                        server[i].e[o].serviceTime = simulationClock;
                        server[i].e[o].queueLength = server[i].queueLength;
                        server[i].e[o].status = server[i].isFree;
                        server[i].i = o;
                        cf.push(server[i].customerQueue.front());
                        server[i].customerQueue.pop_front();
                        customer = server[i].customerQueue.front();
                        server[i].customerQueue.pop_front();
                        customer.delay = simulationClock - customer.arrival;
                        delay += customer.delay;
                        customer.departure = simulationClock + customer.serviceStart;
                        server[i].customerQueue.push_front(customer);
                    }
                }
            }
            simulationClock++;
        }
        int count = 0;
        for (i = 1; i <= 30; i++)
        {
            if (arrival[i] <= 70)
                count++;
        }
        delay /= count;
        float queueLen[6], utilization[6];
        for (i = 1; i <= 5; i++)
        {
            queueLen[i] = 0;
            utilization[i] = 0;
        }
        for (i = 1; i <= 5; i++)
        {
            j = (server[i].i) + 1;
            server[i].e[j].serviceTime = 70;
            server[i].e[j].queueLength = server[i].e[server[i].i].queueLength;
            server[i].e[j].status = server[i].e[server[i].i].status;
            server[i].i = j;
        }
        for (i = 1; i <= 5; i++)
        {
            for (j = 0; j <= server[i].i; j++)
            {
                if (server[i].e[j].status == false)
                    server[i].e[j].queueLength = 0;
                else
                    server[i].e[j].queueLength -= 1;
            }
        }
        for (i = 1; i <= 5; i++)
        {
            for (j = 0; j < server[i].i; j++)
            {
                queueLen[i] += ((server[i].e[j + 1].serviceTime - server[i].e[j].serviceTime) * (server[i].e[j].queueLength));
                if (server[i].e[j].status == true)
                    utilization[i] += ((server[i].e[j + 1].serviceTime - server[i].e[j].serviceTime) * 1);
                else
                    utilization[i] += ((server[i].e[j + 1].serviceTime - server[i].e[j].serviceTime) * 0);
            }
            queueLen[i] /= 70;
            utilization[i] /= 70;
        }
        float queueLenTemp = 0, utilizationTemp = 0;
        for (i = 1; i <= 5; i++)
        {
            queueLenTemp += queueLen[i];
            utilizationTemp += utilization[i];
        }
        delaySum += delay;
        queueSum += queueLenTemp / 5;
        utilizationSum += utilizationTemp / 5;
    }
    cout << "After " << TESTS << " runs:\n";
    cout << "Average delay per customer is " << delaySum / TESTS << "\n";
    cout << "Average queue length for all 5 servers combined is " << queueSum / TESTS << "\n";
    cout << "Average utilisation is " << (utilizationSum / TESTS) * 100 << "%\n";
    return 0;
}
