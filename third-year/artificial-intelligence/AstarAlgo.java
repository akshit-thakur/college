import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.Scanner;

public class AstarAlgo {

    final int INFY = Integer.MAX_VALUE;
    int[][] adjMat;
    int[] heuristic;
    int[] parent;
    boolean[] dfs;
    int vertices;
    HashMap<Integer, Integer> open;
    ArrayList<Integer> closed;
    static Scanner read = new Scanner(System.in);

    AstarAlgo(int n) {
        this.vertices = n;
        this.adjMat = new int[n][n];
        this.heuristic = new int[n];
        this.parent = new int[n];
        this.open = new HashMap<>();
        this.closed = new ArrayList<>();
    }

    private void input() {
        System.out.println("Enter the adjacency matrix: ");
        for (int i = 0; i < this.vertices; i++) {
            for (int j = 0; j < this.vertices; j++)
                this.adjMat[i][j] = read.nextInt();
        }
        System.out.println("Enter the heuristic array: ");
        for (int i = 0; i < this.vertices; i++)
            this.heuristic[i] = read.nextInt();
    }

    private int findRoot(int i) {
        int sum = 0;
        while (i != 0) {
            sum += adjMat[i][parent[i]];
            i = parent[i];
        }
        return sum;
    }

    private void dfs(int bestnode) {
        int f, g, h;
        for (int s = 0; s < this.vertices; s++) {
            if (adjMat[bestnode][s] != 0 && (dfs[s] == false)) {
                g = findRoot(bestnode) + adjMat[bestnode][s];
                h = heuristic[s];
                f = g + h;
                if (open.containsKey(s) && f < open.get(s)) {
                    parent[s] = bestnode;
                    open.put(s, f);
                } else if (closed.contains(s)) {
                    g = findRoot(s);
                    if (f < g + h)
                        parent[s] = bestnode;
                    dfs[s] = true;
                    dfs(s);
                } else {
                    open.put(s, f);
                }
            }
        }
    }

    private void aStar() {
        final int GOAL = this.vertices - 1;
        int f, g, h;
        g = 0;
        h = heuristic[0];
        f = g + h;
        open.put(0, f);
        int bestnode = -1;
        while (true) {
            if (open.size() == 0) {
                System.out.println("Failed to reach goal");
                break;
            }
            if (bestnode == GOAL) {
                System.out.println("The path is: ");
                int cost = 0, prev = 0;
                for (int k : closed) {
                    System.out.print((k + 1) + " ");
                    cost += adjMat[prev][k];
                    prev = k;
                }
                System.out.println("\nThe cost is: " + cost);
                break;
            }
            int min = Integer.MAX_VALUE;
            for (Entry<Integer, Integer> mapElement : open.entrySet()) {
                int value = mapElement.getValue();
                if (value < min) {
                    min = value;
                    bestnode = mapElement.getKey();
                }
            }
            open.remove(bestnode);
            closed.add(bestnode);
            for (int s = 0; s < this.vertices; s++) {
                dfs = new boolean[this.vertices];
                if (adjMat[bestnode][s] != 0) {
                    g = findRoot(bestnode) + adjMat[bestnode][s];
                    h = heuristic[s];
                    f = g + h;
                    if (open.containsKey(s) && (f < open.get(s))) {
                        parent[s] = bestnode;
                        open.put(s, f);
                    } else if (closed.contains(s)) {
                        g = findRoot(s);
                        if (f < g + h)
                            parent[s] = bestnode;
                        dfs[s] = true;
                        dfs(s);
                    } else {
                        open.put(s, f);
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        System.out.println("Enter the number of vertices: ");
        int n = read.nextInt();
        AstarAlgo obj = new AstarAlgo(n);
        obj.input();
        obj.aStar();
        read.close();
    }
}
