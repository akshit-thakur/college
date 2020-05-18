import java.util.Scanner;

public class IterativeDeepening {
    private static boolean[] visited; // boolean array to keep check of vertex already visited
    private static int n; // number of vertices
    private static int[][] G; // adjacency matrix
	private static int nodes;	//number of nodes visited for a given level
    private static int GOAL;
    
    static void doDFS(int i,int level) {
        if(level<0)
	        return;
        nodes+=1;
        System.out.print((i + 1) + " ");
        if((i+1) == GOAL){
            System.out.println("\nGoal Node Found");
            System.exit(0);
        }
        visited[i] = true;
        
        for (int j = 0; j < n; j++) {
            if ((!visited[j]) && G[i][j] == 1) // if the vertex is unvisited and there is an edge
                doDFS(j,level-1); // go down one level to that node
        }
    }
    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        
        System.out.println("Enter number of vertices: ");
        n = read.nextInt();

        G = new int[n][n];

        // read the adjecency matrix
        System.out.println("Enter adjecency matrix of the graph: ");

        for (int i = 0; i < n; i++) { // enter the adjacency matrix
            for (int j = 0; j < n; j++)
                G[i][j] = read.nextInt();
        }
        System.out.println("Enter goal node: ");
        GOAL = read.nextInt();
        System.out.println("Enter the maximum number of levels to search: ");
        int max = read.nextInt();
        for(int k=0;k<max;k++){
            System.out.println("Level "+k);
            visited = new boolean[n];
            doDFS(0,k);
            if(nodes == n){
                System.out.println();
                break;
            }
            nodes = 0;
            System.out.println();
        }
        System.out.println("Goal node not found");
        read.close();
    }
}
