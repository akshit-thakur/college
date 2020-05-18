import java.util.Scanner;

public class DistanceVectorRouting {
    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        System.out.println("Enter the number of nodes");
        int n = read.nextInt();
        int[][] graph = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                graph[i][j] = -1;
        }
        char[] stations = new char[n];
        // filling the station names with capital letters
        for (int i = 0; i < n; i++)
            stations[i] = (char) (i + 65);
        for (int i = 0; i < n; i++) {
            System.out.println("Enter distance between " + stations[i] + " and ");
            for (int j = 0; j < n; j++) {
                if (i == j)
                    graph[i][j] = 0;
                if (graph[i][j] == -1) {
                    System.out.print(stations[j] + ": ");
                    graph[i][j] = read.nextInt();
                    graph[j][i] = graph[i][j];
                }
            }
        }
        int[][] via = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                via[i][j] = -1;
        }
        int[][][] share = new int[n][n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if ((graph[i][j] > -1) && (graph[j][k] > -1))
                        share[i][j][k] = graph[j][k] + graph[i][j];
                    else
                        share[i][j][k] = -1;
                }
            }
        }
        int[][] result = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = graph[i][j];
                via[i][j] = i;
                for (int k = 0; k < n; k++) {
                    if ((result[i][j] > share[i][k][j]) || (result[i][j] == -1)) {
                        if (share[i][k][j] > -1) {
                            result[i][j] = share[i][k][j];
                            via[i][j] = k;
                        }
                    }
                }
                if (result[i][j] == -1) {
                    for (int k = 0; k < n; k++) {
                        if ((result[i][k] != -1) && (result[k][j] != -1)) {
                            if ((result[i][j] == -1)
                                    || ((result[i][j] != -1) && (result[i][j] > result[i][k] + result[k][j]))) {
                                if (result[i][k] + result[k][j] > -1) {
                                    result[i][j] = result[i][k] + result[k][j];
                                    via[i][j] = k;
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            System.out.println(stations[i] + " Table");
            System.out.println("Node\tDist\tVia");
            for (int j = 0; j < n; j++) {
                System.out.print(stations[j] + "\t" + result[i][j] + "\t");
                if (i == via[i][j])
                    System.out.println("-");
                else
                    System.out.println(stations[via[i][j]]);
            }
        }
        read.close();
    }
}

// OUTPUT

// Enter Number of Nodes:5

// Enter Distance between A - B : 5

// Enter Distance between A - C : 2

// Enter Distance between A - D : 3

// Enter Distance between A - E : -1

// Enter Distance between B - C : 4

// Enter Distance between B - D : -1

// Enter Distance between B - E : 3

// Enter Distance between C - D : -1

// Enter Distance between C - E : 4

// Enter Distance between D - B : -1

// Enter Distance between D - C : -1

// Enter Distance between D - E : -1

// Enter Distance between E - A : -1

// Enter Distance between E - D : -1

// After Initialization
// A Table
// Node Dist Via
// A 0 -1
// B 5 -1
// C 2 -1
// D 3 -1
// E -1 -1
// B Table
// Node Dist Via
// A 5 -1
// B 0 -1
// C 4 -1
// D -1 -1
// E 3 -1
// C Table
// Node Dist Via
// A 2 -1
// B 4 -1
// C 0 -1
// D -1 -1
// E 4 -1
// D Table
// Node Dist Via
// A 3 -1
// B -1 -1
// C -1 -1
// D 0 -1
// E -1 -1
// E Table
// Node Dist Via
// A -1 -1
// B 3 -1
// C 4 -1
// D -1 -1
// E 0 -1

// For A
// From A
// A 0
// B 5
// C 2
// D 3
// E -1
// From B
// A 10
// B 5
// C 9
// D -1
// E 8
// From C
// A 4
// B 6
// C 2
// D -1
// E 6
// From D
// A 6
// B -1
// C -1
// D 3
// E -1
// From E
// A -1
// B -1
// C -1
// D -1
// E -1

// For B
// From A
// A 5
// B 10
// C 7
// D 8
// E -1
// From B
// A 5
// B 0
// C 4
// D -1
// E 3
// From C
// A 6
// B 8
// C 4
// D -1
// E 8
// From D
// A -1
// B -1
// C -1
// D -1
// E -1
// From E
// A -1
// B 6
// C 7
// D -1
// E 3

// For C
// From A
// A 2
// B 7
// C 4
// D 5
// E -1
// From B
// A 9
// B 4
// C 8
// D -1
// E 7
// From C
// A 2
// B 4
// C 0
// D -1
// E 4
// From D
// A -1
// B -1
// C -1
// D -1
// E -1
// From E
// A -1
// B 7
// C 8
// D -1
// E 4

// For D
// From A
// A 3
// B 8
// C 5
// D 6
// E -1
// From B
// A -1
// B -1
// C -1
// D -1
// E -1
// From C
// A -1
// B -1
// C -1
// D -1
// E -1
// From D
// A 3
// B -1
// C -1
// D 0
// E -1
// From E
// A -1
// B -1
// C -1
// D -1
// E -1

// For E
// From A
// A -1
// B -1
// C -1
// D -1
// E -1
// From B
// A 8
// B 3
// C 7
// D -1
// E 6
// From C
// A 6
// B 8
// C 4
// D -1
// E 8
// From D
// A -1
// B -1
// C -1
// D -1
// E -1
// From E
// A -1
// B 3
// C 4
// D -1
// E 0
// After Update :
// A Table
// Node Dist Via
// A 0 -
// B 5 -
// C 2 -
// D 3 -
// E 6 C
// B Table
// Node Dist Via
// A 5 -
// B 0 -
// C 4 -
// D 8 A
// E 3 -
// C Table
// Node Dist Via
// A 2 -
// B 4 -
// C 0 -
// D 5 A
// E 4 -
// D Table
// Node Dist Via
// A 3 -
// B 8 A
// C 5 A
// D 0 -
// E 9 A
// E Table
// Node Dist Via
// A 6 C
// B 3 -
// C 4 -
// D 9 A
// E 0 -