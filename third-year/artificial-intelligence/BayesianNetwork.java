import java.util.ArrayList;
import java.util.Scanner;

public class BayesianNetwork {
    static int n, start, goal;	
    static double answer;
    static double[][] adjMat;	
    static boolean[] visited;
    static ArrayList<Integer> pathList; //list of nodes in current path

    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        System.out.println("Enter the number of vertices:");
        n = read.nextInt();
        adjMat = new double[n][n];
        System.out.println("Enter the adjcancecy matrix"); //-1 if no edge
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                adjMat[i][j] = read.nextDouble();
        }
        System.out.println("Enter start and goal nodes: ");
        start = read.nextInt();
        goal = read.nextInt();
        pathList = new ArrayList<Integer>();
        visited = new boolean[n];
        pathList.add(start);
        findProbability(start, 1);
        System.out.println("Total probability of reaching from  " + start + " to " + goal + " is: " + answer);
        read.close();
    }

    private static void findProbability(int u, double pathCost) {
        visited[u] = true;
        if (u == goal) {
            answer += pathCost;	//add the cost of current path to the answer
            visited[u] = false;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i] && adjMat[u][i] > 0) {    //if not visited and there is an edge
                pathList.add(i);
                pathCost *= adjMat[u][i];
                findProbability(i, pathCost);
                pathList.remove((Integer) i); // object and not index to be removed
                pathCost /= adjMat[u][i];
            }
        }
        visited[u] = false;
    }
}
/*
OUTPUT

Enter the number of vertices:
8
Enter the adjcancecy matrix
0		0.3     0.4     0.5     -1      -1      -1      -1
0.8     0       -1      -1      0.6     0.7     -1      -1
-1      -1      0       -1      -1      0.4     0.3     0.8
-1      -1      -1      0       -1      -1      -1      0.6
-1      -1      -1      -1      0       0.4     -1      -1
-1      -1      -1      -1      -1      0       0.5     -1
-1      -1      -1      -1      -1      -1      0       0.6
-1      -1      -1      -1      -1      -1      -1      0
Enter start and goal nodes: 
0       6
Total probability of reaching from  0 to 6 is: 0.341

*/
