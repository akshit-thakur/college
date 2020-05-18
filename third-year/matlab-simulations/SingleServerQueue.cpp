#include <bits/stdc++.h>
using namespace std;

int main()
{
    const int TESTS = 1000;
    double queue[TESTS];
    double customerDelay[TESTS];
    double server[TESTS];
    for (int test = 0; test < TESTS; test++)
    {
        const int CUSTOMER = 100;
        int i = 0, j = 0;
        vector<double> arrival;
        vector<double> departure;
        srand(time(0));
        while (j < CUSTOMER)
        {
            double time;
            bool isArrival = rand() > RAND_MAX / 2;
            if (isArrival)
            {
                time = ((rand() % (100 - 0 + 1) + 0)) / 1.0;
                arrival.push_back(time);
                i++;
            }
            else
            {
                if (arrival.size() == 0)
                    continue;
                double min = *min_element(arrival.begin(), arrival.end());
                double max = *max_element(arrival.begin(), arrival.end());
                time = ((rand() % (int)((min + 10) - min + 1)) + min) / 1.0;
                departure.push_back(time);
                j++;
            }
        }
        for (; i < j; i++)
            arrival.push_back(0);
        double t[arrival.size()];
        sort(arrival.begin(), arrival.end());
        copy(arrival.begin(), arrival.end(), t);
        double d[departure.size()];
        sort(departure.begin(), departure.end());
        copy(departure.begin(), departure.end(), d);
        for (i = 0; i < departure.size(); i++)
        {
            if (t[i] > d[i])
                swap(t[i], d[i]);
            else if (t[i] == d[i])
                d[i] += 10.0;
        }
        i = 0;
        j = 0;
        double **events;
        events = new double *[2];
        for (int i = 0; i < 2; i++)
            events[i] = new double[arrival.size() + departure.size()];

        int k = 0;
        while (i < arrival.size() && j < departure.size())
        {
            if (t[i] < d[j])
            {
                events[0][k] = 0;
                events[1][k++] = t[i++];
            }
            else
            {
                events[0][k] = 1;
                events[1][k++] = d[j++];
            }
        }
        while (i < arrival.size())
        {
            events[0][k] = 0;
            events[1][k++] = t[i++];
        }
        while (j < departure.size())
        {
            events[0][k] = 1;
            events[1][k++] = d[j++];
        }
        k = 0;
        int queueLength = 0;
        double area = 0;
        bool serverBusy = false;
        double lastFree = 0;
        double delay[departure.size()];
        double utilization = 0;

        for (i = 0; i < arrival.size() + departure.size(); i++)
        {
            if (events[0][i] == 0)
            { //arrival
                if (queueLength > 0)
                    area += ((events[1][i] - events[1][i - 1]) * queueLength);
                if (serverBusy == false)
                {
                    serverBusy = true;
                    lastFree = events[1][i];
                    delay[k++] = 0;
                }
                else
                {
                    queueLength += 1;
                }
            }
            else
            {
                if (queueLength == 0)
                { // last customer gone
                    serverBusy = false;
                    utilization += (events[1][i] - lastFree);
                }
                if (queueLength > 0)
                {
                    area += ((events[1][i] - events[1][i - 1]) * queueLength);
                    queueLength -= 1;
                    if (k < departure.size()) //k<delay.length
                    {                         // in the end,k = customer served
                        delay[k] = d[k - 1] - t[k];
                        k += 1;
                    }
                }
            }
        }
        if (queueLength > 0)
            utilization += (events[1][arrival.size() + departure.size() - 1] - lastFree);
        server[test] = utilization / events[1][arrival.size() + departure.size() - 1];
        double totalDelay = 0.0;
        for (double z : delay)
            totalDelay += z;
        customerDelay[test] = totalDelay / k;
        queue[test] = area / events[1][arrival.size() + departure.size() - 1];
    }
    cout << "After " << TESTS << " runs on single server queueing system:\n";
    cout << "Avg queue length is:\n";
    double sum = 0.0;
    for (double i : queue)
        sum = sum + (double)i;
    cout << sum / TESTS << "\n";
    sum = 0.0;
    cout << "Avg server utilization is:\n";
    for (double i : server)
        sum = sum + (double)i;
    cout << sum / TESTS << "\n";
    cout << "Avg delay per customer is:\n";
    for (double i : customerDelay)
        sum = sum + (double)i;
    cout << sum / TESTS << "\n";
    return 0;
}
