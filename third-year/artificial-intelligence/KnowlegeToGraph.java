import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class KnowlegeToGraph {
    static class Node {
        int x;
        int y;
        int id;

        public Node(int x, int y, int n) {
            this.x = x;
            this.y = y;
            this.id = n;
        }
    }

    static int[][] adjMat;
    static boolean[] visited;
    static int count;
    static Node GOAL;
    static ArrayList<Node> nodes;
    static ArrayList<Node> path;

    public static void main(String[] args) {
        try {
            Scanner read = new Scanner(new File("waterjug.txt"));
            Scanner input = new Scanner(System.in);
            adjMat = new int[1000][1000];
            nodes = new ArrayList<>();
            System.out.println("Enter the goal x and y: ");
            GOAL = new Node(input.nextInt(), input.nextInt(), 0);
            while (read.hasNextLine()) {
                int x, y, x1, y1;
                String line = read.nextLine();
                String[] letters = line.split(",", 4);
                x = Integer.valueOf(letters[0]);
                y = Integer.valueOf(letters[1]);
                x1 = Integer.valueOf(letters[2]);
                y1 = Integer.valueOf(letters[3]);
                boolean found = false, found2 = false;
                int index = 0, index2 = 0;
                for (Node i : nodes) {
                    if (i.x == x && i.y == y) {
                        found = true;
                        index = i.id - 1;
                    }
                    if (i.x == x1 && i.y == y1) {
                        found2 = true;
                        index2 = i.id - 1;
                    }
                }
                if (found && found2)
                    adjMat[index][index2] = 1;
                else if (!found && found2) {
                    nodes.add(new Node(x, y, nodes.size() + 1));
                    if (nodes.size() - 1 != index2) // directed graph
                        adjMat[nodes.size() - 1][index2] = 1;
                } else if (!found2 && found) {
                    nodes.add(new Node(x1, y1, nodes.size() + 1));
                    if (nodes.size() - 1 != index)
                        adjMat[index][nodes.size() - 1] = 1;
                } else { // both not found
                    nodes.add(new Node(x, y, nodes.size() + 1));
                    nodes.add(new Node(x1, y1, nodes.size() + 1));
                    adjMat[nodes.size() - 2][nodes.size() - 1] = 1;
                }
            }
            for (int i = 0; i < 100; i++) {
                visited = new boolean[nodes.size()];
                path = new ArrayList<>();
                doDFS(0, i);
                if (count == nodes.size())
                    break;
                count = 0;
            }
            System.out.println("\nGoal node not found");
            read.close();
            input.close();
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        }
    }

    static void doDFS(int i, int level) {
        if (level < 0)
            return;
        count += 1;
        Node n = nodes.get(i);
        path.add(n);
        if (n.x == GOAL.x && n.y == GOAL.y) {
            System.out.println("Goal node found\nThe steps are: ");
            for (Node j : path)
                System.out.print("( " + j.x + "," + j.y + " ) ");
            System.out.println();
            System.exit(0);
        }
        visited[i] = true;
        for (int j = 0; j < nodes.size(); j++) {
            if ((!visited[j]) && adjMat[i][j] == 1) // if the vertex is unvisited and there is an edge
                doDFS(j, level - 1); // go down one level to that node
        }
        path.remove(n);
    }
}


