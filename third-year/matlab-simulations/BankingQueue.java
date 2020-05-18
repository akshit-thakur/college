import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.concurrent.ThreadLocalRandom;

public class BankingQueue {
    private static double getAvg(Double[] arr) {
        double sum = 0;
        for (double z : arr)
            sum += z;
        return (sum / arr.length);
    }

    public static void main(String[] args) {
        final int TESTS = 100;
        Double[] queue = new Double[TESTS];
        Double[] customerDelay = new Double[TESTS];
        Double[] server = new Double[TESTS];
        for (int test = 0; test < TESTS; test++) {
            final int CUSTOMER = 1000;
            int i = 0, j = 0;
            ArrayList<Double> arrival = new ArrayList<>();
            ArrayList<Double> departure = new ArrayList<>();
            while (j < CUSTOMER) {
                double time;
                boolean isArrival = ThreadLocalRandom.current().nextBoolean();
                if (isArrival) {
                    time = ThreadLocalRandom.current().nextDouble();
                    arrival.add(time);
                    i++;
                } else {
                    if (arrival.size() == 0)
                        continue;
                    Double min = Collections.min(arrival);
                    Double max = Collections.max(arrival) + 1;
                    time = ThreadLocalRandom.current().nextDouble(min, max);
                    departure.add(time);
                    j++;
                }
            }
            for (; i < j; i++)// if more departures than arrivals
                arrival.add(0.0); // assume all the remaining customers arrived at zero.
            Double[] t = arrival.stream().toArray(Double[]::new);
            Double[] d = departure.stream().toArray(Double[]::new);// d.length = number of customers served
            Arrays.sort(t);
            Arrays.sort(d);
            double[] delay = new double[j]; // delay of k-th customer.
            double totalDelay = 0, lastFree = 0.0, utilization = 0.0, area = 0; // last time server was free.
                                                                                // utilization = time
            // betweeen being free. totalDelay = sum of all delays. totalDelay/number of
            // customers = avg delay per customer
            int numberOfEvents = t.length + d.length;
            double[][] events = new double[2][numberOfEvents]; // t.length+d.length = number of events
            boolean serverBusy = false;
            int k = 0;
            i = 0;
            j = 0;
            int queueLength = 0;
            /* merging t and d to get the sorted list of events */
            while (i < t.length && j < d.length) {
                if (t[i] < d[j]) {
                    events[0][k] = 0;
                    events[1][k++] = t[i++];
                } else {
                    events[0][k] = 1;
                    events[1][k++] = d[j++];
                }
            }
            while (i < t.length) {
                events[0][k] = 0;
                events[1][k++] = t[i++];
            }
            while (j < d.length) {
                events[0][k] = 1;
                events[1][k++] = d[j++];
            }
            k = 0; // for delay array
            for (i = 0; i < numberOfEvents; i++) {
                if (events[0][i] == 0.0) { // arrival
                    if (queueLength > 0)
                        area += ((events[1][i] - events[1][i - 1]) * queueLength);
                    if (!serverBusy) {
                        serverBusy = true;
                        lastFree = events[1][i];
                        delay[k++] = 0;
                    } else
                        queueLength += 1;
                } else { // departure
                    if (queueLength == 0) { // last customer gone
                        serverBusy = false;
                        utilization += (events[1][i] - lastFree);
                    }
                    if (queueLength > 0) {
                        area += ((events[1][i] - events[1][i - 1]) * queueLength);
                        queueLength -= 1;
                        if (k < delay.length) { // in the end,k = customer served
                            delay[k] = d[k - 1] - t[k];
                            k += 1;
                        }
                    }
                }
            }
            if (queueLength > 0)
                utilization += (events[1][numberOfEvents - 1] - lastFree);
            server[test] = utilization / events[1][numberOfEvents - 1];
            for (double z : delay)
                totalDelay += z;
            customerDelay[test] = totalDelay / k;
            queue[test] = area / events[1][numberOfEvents - 1];
        }
        System.out.println("Avg queue length is: " + getAvg(queue)); // area/totalTimeElapsed
        System.out.println("Average delay per customer is: " + getAvg(customerDelay));
        System.out.println("The utilization of server is: " + getAvg(server));
    }
}