
/*
0       1       1       1       0       0       0       0       0       0
1       0       0       0       1       1       0       0       0       0
1       0       0       0       0       1       1       0       0       0
1       0       0       0       0       0       0       1       1       0
0       1       0       0       0       0       0       0       0       1
0       1       1       0       0       0       0       0       0       1
0       0       1       0       0       0       0       0       0       0
0       0       0       1       0       0       0       0       0       0
0       0       0       1       0       0       0       0       0       0
0       0       0       0       1       1       0       0       0       0
*/
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class BeamSearch {
    static int n;
    static int[][] adjMat;
    static int w;
    static int goal;
    private static void beamSearch() {
        boolean[] visited = new boolean[n];
        Queue<Integer> queue = new LinkedList<Integer>();
        queue.add(0); //assuming beam search starts from first node
        visited[0] = true;
        boolean found = false;
        while(!queue.isEmpty()){
            int count = 0;
            int s = queue.poll();
            System.out.print((s+1)+" ");
            if((s+1)==goal){
                found =true;
                break;
            }
            for(int i=0;i<n;i++){
                if(!visited[i] && adjMat[s][i] !=0 ){ //if node not visited and there is an edge from current node
                    visited[i] = true;
                    queue.add(i);
                    count+=1;
                }
                if(count == w) //if width of beam reached
                    break;
            }
        }
        if(found)
            System.out.println("\nGoal node found");
        else
            System.out.println("\nGoal not found");
    }

    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        System.out.println("Enter the number of vertices: ");
        n = read.nextInt();
        adjMat = new int[n][n];
        System.out.println("Enter the adjacency matrix: ");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                adjMat[i][j] = read.nextInt();
        }
        System.out.println("Enter goal node: ");
        goal = read.nextInt();
        System.out.println("Enter the width of beam: ");
        w = read.nextInt();
        System.out.println("Beam search: ");
        beamSearch();
        read.close();
    }
}