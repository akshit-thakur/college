#include <bits/stdc++.h>
using namespace std;
bool checkMonthChange(double month1, double month2)
{
    if (month2 == 0)
        return false;
    return floor(month1) - floor(month2) > 0;
}
int main()
{
    int minLevel, maxLevel, orderSize = 0, currentLevel, n = 120, k = 32, h = 1, s = 5, itemCost = 3, TESTS = 100;
    int sSPolicies[][2] = {{20, 40}, {20, 60}, {20, 80}, {20, 100}, {40, 60}, {40, 80}, {40, 100}, {60, 80}, {60, 100}, {80, 100}};
    double minCost = 10000000000.0;
    int N = 10; //Number of policies
    double totalCosts[N];
    for (int i = 0; i < N; i++)
        totalCosts[i] = 0.0;
    int answer[2] = {0, 0};
    srand(time(0));
    for (int t = 0; t < TESTS; t++)
    {
        vector<vector<double>> demandTimes;
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            int numberOfDemands = (rand() % (20 - 1 + 1)) + 1;
            for (int j = 0; j < numberOfDemands; j++)
            {
                vector<double> entry;
                double time = (double)rand() / RAND_MAX;
                double size = (rand() % (100 - 1 + 1)) + 1;
                entry.push_back(time + i);
                entry.push_back(size);
                demandTimes.push_back(entry);
            }
        }
        sort(demandTimes.begin(), demandTimes.end());
        for (int i = 0; i < N; i++)
        {
            minLevel = sSPolicies[i][0];
            maxLevel = sSPolicies[i][1];
            double holdingCost = 0.0, orderCost = 0.0, netOrderCost = 0.0, shortageCost = 0.0;
            currentLevel = maxLevel;
            bool isMonthChange = false, orderPlaced = false;
            double lastTime = 0.0, positiveArea = 0.0, negativeArea = 0.0, orderTime = 0.0;
            for (vector<double> entries : demandTimes)
            {
                if (currentLevel > 0)
                    positiveArea += currentLevel * (entries.at(0) - lastTime);
                else
                    negativeArea += currentLevel * (lastTime - entries.at(0));
                isMonthChange = checkMonthChange(entries.at(0), lastTime);
                if (orderPlaced && entries.at(0) > orderTime)
                {
                    currentLevel += orderSize;
                    orderSize = 0;
                    orderTime = 0.0;
                    orderPlaced = false;
                }
                else if (isMonthChange && currentLevel < minLevel)
                {
                    orderSize = maxLevel - currentLevel;
                    orderCost = k + orderSize * itemCost;
                    netOrderCost += orderCost;
                    int month = floor(entries.at(0));
                    orderTime = (rand() % (int)((month + 1) - (month + 0.5) + 1) + (month + 0.5));
                    orderPlaced = true;
                }
                currentLevel -= entries.at(1);
                lastTime = entries.at(0);
            }
            if (orderPlaced)
            {
                if (currentLevel > 0)
                    positiveArea += (currentLevel + orderSize) * (n - lastTime);
                else
                    negativeArea += (currentLevel) * (n - lastTime);
            }
            netOrderCost /= n;
            holdingCost = (positiveArea * h) / n;
            shortageCost = (negativeArea * s) / n;
            totalCosts[index++] += netOrderCost + holdingCost + shortageCost;
        }
    }
    cout << "The total costs of (s,S) policies are:\n";
    for (int i = 0; i < N; i++)
    {
        cout << "(" << sSPolicies[i][0] << "," << sSPolicies[i][1] << ") -> " << (totalCosts[i] / TESTS) << "\n";
        minCost = ((minCost < (totalCosts[i] / TESTS))) ? minCost : (totalCosts[i] < 0 ? minCost : (totalCosts[i] / TESTS));
    }
    for (int i = 0; i < N; i++)
    {
        if (minCost == (totalCosts[i] / TESTS))
        {
            answer[0] = sSPolicies[i][0];
            answer[1] = sSPolicies[i][1];
            break;
        }
    }
    cout << "The minimum cost is: " << minCost << " and the policy is: (" << answer[0] << "," << answer[1] << ")\n";
    return 0;
}