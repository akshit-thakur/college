import java.util.Scanner;

class DFS {
    private static boolean[] visited; // boolean array to keep check of vertex already visited
    private static int n; // number of vertex
    private static int[][] G; // adjacency matrix

    static void doDFS(int i) {
        System.out.print((i + 1) + " ");
        visited[i] = true;
        for (int j = 0; j < n; j++) {
            if ((!visited[j]) && G[i][j] == 1) // if the vertex is unvisited and there is an edge
                doDFS(j); // go down one level to that node
        }
    }

    public static void main(String args[]) {
        Scanner read = new Scanner(System.in);
        int i, j;
        System.out.println("Enter number of vertices: ");
        n = read.nextInt();

        G = new int[n][n];
        visited = new boolean[n];

        // read the adjecency matrix
        System.out.println("Enter adjecency matrix of the graph: ");

        for (i = 0; i < n; i++) { // enter the adjacency matrix
            for (j = 0; j < n; j++) {
                G[i][j] = read.nextInt();
            }
        }

        // visited is initialized to false
        for (i = 0; i < n; i++)
            visited[i] = false;

        // Print result
        System.out.println("The DFS traversal is: ");
        doDFS(0); // object calls doDFS() with vertex number 1 passed as starting point
        System.out.println();
        read.close();
    }
}