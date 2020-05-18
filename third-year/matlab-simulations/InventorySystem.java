import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.concurrent.ThreadLocalRandom;

public class InventorySystem {
    public static void main(String[] args) {
        int minLevel, maxLevel, orderSize = 0, currentLevel, n = 120, k = 32, h = 1, s = 5, itemCost = 3, TESTS = 100;
        int[][] sSPolicies = { { 20, 40 }, { 20, 60 }, { 20, 80 }, { 20, 100 }, { 40, 60 }, { 40, 80 }, { 40, 100 },
                { 60, 80 }, { 60, 100 }, { 80, 100 } };
        Double minCost = Double.MAX_VALUE;
        double[] totalCosts = new double[sSPolicies.length];
        int[] answer = new int[2];
        for (int t = 0; t < TESTS; t++) {
            ArrayList<ArrayList<Double>> demandTimes = new ArrayList<ArrayList<Double>>();
            int index = 0;
            for (int i = 0; i < n; i++) {
                int numberOfDemands = ThreadLocalRandom.current().nextInt(20);
                for (int j = 0; j < numberOfDemands; j++) {
                    ArrayList<Double> entry = new ArrayList<>();
                    double time = ThreadLocalRandom.current().nextDouble();
                    double size = ThreadLocalRandom.current().nextInt(1, 100);
                    entry.add(time + i);
                    entry.add(size);
                    demandTimes.add(entry);
                }
            }
            Collections.sort(demandTimes, new Sort());
            for (int[] row : sSPolicies) {
                double holdingCost = 0.0, orderCost = 0.0, netOrderCost = 0.0, shortageCost = 0.0;
                minLevel = row[0];
                maxLevel = row[1];
                currentLevel = maxLevel;
                boolean isMonthChange = false, orderPlaced = false;
                Double lastTime = 0.0, positiveArea = 0.0, negativeArea = 0.0, orderTime = 0.0;
                for (ArrayList<Double> entries : demandTimes) {
                    if (currentLevel > 0)
                        positiveArea += currentLevel * (entries.get(0) - lastTime);
                    else
                        negativeArea += currentLevel * (lastTime - entries.get(0));
                    isMonthChange = isMonthChange(entries.get(0), lastTime);
                    if (orderPlaced && entries.get(0) > orderTime) {
                        currentLevel += orderSize;
                        orderSize = 0;
                        orderTime = 0.0;
                        orderPlaced = false;
                    } else if (isMonthChange && currentLevel < minLevel) {
                        orderSize = maxLevel - currentLevel;
                        orderCost = k + orderSize * itemCost;
                        netOrderCost += orderCost;
                        int month = (int) Math.floor(entries.get(0));
                        orderTime = ThreadLocalRandom.current().nextDouble(month + 0.5, month + 1);
                        orderPlaced = true;
                    }
                    currentLevel -= entries.get(1);
                    lastTime = entries.get(0);
                }
                if (orderPlaced) {
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
        System.out.println("The total costs of (s,S) policies are: ");
        for (int i = 0; i < sSPolicies.length; i++) {
            System.out.println("(" + sSPolicies[i][0] + "," + sSPolicies[i][1] + ") -> " + (totalCosts[i] / TESTS));
            minCost = Math.min(minCost, (totalCosts[i] / TESTS));
        }
        for (int i = 0; i < sSPolicies.length; i++) {
            if (minCost == totalCosts[i] / TESTS) {
                answer = sSPolicies[i];
                break;
            }
        }
        System.out.println(
                "The minimum cost is: " + minCost + " and the policy is: (" + answer[0] + "," + answer[1] + ")");
    }

    private static boolean isMonthChange(Double month1, Double month2) {
        if (month2 == 0) // if first month
            return false;
        return Math.floor(month1) - Math.floor(month2) > 0;
    }

    static final class Sort implements Comparator<ArrayList<Double>> {
        @Override
        public int compare(ArrayList<Double> o1, ArrayList<Double> o2) {
            return o1.get(0).compareTo(o2.get(0));
        }
    }
}