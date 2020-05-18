import java.util.ArrayList;
import java.util.Scanner;
import java.util.concurrent.ThreadLocalRandom;

public class MeanBucket {
    static ArrayList<ArrayList<Integer>> buckets;
    static ArrayList<Integer> means;
    static int rows;
    static int cols;

    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        int[] numbers = new int[100];
        for (int i = 0; i < 100; i++)
            numbers[i] = ThreadLocalRandom.current().nextInt(40, 100 + 1);
        System.out.println("Enter the number of buckets: ");
        rows = read.nextInt();
        while (100 % rows != 0) {
            System.out.println("Need to be perfect divisor of 100. Enter again: ");
            rows = read.nextInt();
        }
        cols = 100 / rows;
        buckets = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < cols; i++) {
            buckets.get(0).add(numbers[i]);
        }
        int currentRow = 0;
        means.add(currentRow,getMean(buckets.get(currentRow));
        for (int i = cols; i < 100; i++) {
            if (buckets.get(i / cols - 1).size() == cols) {
                currentRow += 1;
            }
            findFarthest(numbers[i]);
        }
        read.close();
    }

    private static void findFarthest(int value) {
        for(int i=0;i<means.size();i++){
            int farthest = Math.abs(means.get(i)-);
            for(Integer j:buckets.get(i))
            if(Math.abs(means.get(i)-j)>farthest);
        }
    }

    private static int getMean(ArrayList<Integer> arrayList) {
        int mean = 0;
        for (Integer i : arrayList) {
            mean += i;
        }
        return mean / cols;
    }
}

// import java.util.Scanner;
// import java.util.concurrent.ThreadLocalRandom;

// public class MeanBucket {
// static int[][] buckets;
// static int[] means;
// static int rows;
// static int cols;

// private static void findFarthest(int value, int index) {
// boolean changed = false;
// int farthestR = index / cols;
// int farthestC = index % cols;
// int farthest = Integer.MIN_VALUE;
// for (int i = 0; i < index / cols; i++) {
// int mean = means[i];
// if (farthest < Math.abs(mean - value)) {
// farthest = Math.abs(mean - value);
// farthestR = index / cols;
// farthestC = index % cols;
// changed = false;
// }
// for (int k = 0; k < cols; k++) {
// if (Math.abs(mean - buckets[i][k]) > farthest) {
// farthest = buckets[i][k];
// farthestR = i;
// farthestC = k;
// changed = true;
// }
// }
// }
// if (changed) {
// buckets[index / cols][index % cols] = buckets[farthestR][farthestC];
// buckets[farthestR][farthestC] = value;
// } else {
// buckets[index / cols][index % cols] = value;
// }
// calculateMeans(index);
// }

// private static void calculateMeans(int index) {
// for (int i = 0; i < index / cols; i++) {
// for (int j = 0; j < cols; j++) {
// means[i] += buckets[i][j];
// }
// means[i] /= cols;
// }
// if (index % cols != 0) {
// for (int i = 0; i < index % cols; i++) {
// means[index / cols] += buckets[index / cols][i];
// }
// }
// means[index / cols] /= cols;
// }

// public static void main(String[] args) {
// Scanner read = new Scanner(System.in);
// int[] numbers = new int[100];
// for (int i = 0; i < 100; i++)
// numbers[i] = ThreadLocalRandom.current().nextInt(40, 100 + 1);
// System.out.println("Enter the number of buckets: ");
// rows = read.nextInt();
// while (100 % rows != 0) {
// System.out.println("Need to be perfect divisor of 100. Enter again: ");
// rows = read.nextInt();
// }
// cols = 100 / rows;
// // ArrayList<ArrayList<Integer>> buckets = new
// ArrayList<ArrayList<Integer>>();
// // for (int i = 0; i < 100 / rows; i++)
// // buckets.get(0).add(numbers[i]);
// // for(Integer i:buckets.get(0))
// // means[0] += i;
// // means[0] /= cols;
// buckets = new int[rows][cols];
// means = new int[rows];
// for (int i = 0; i < cols; i++) {
// buckets[0][i] = numbers[i];
// means[0] += numbers[i];
// }
// means[0] /= cols;
// for (int i = cols; i < 100; i++) {
// findFarthest(numbers[i], i);
// }
// read.close();
// }
// }