import java.util.Scanner;

class Node{ //class to implement a node of Queue. Similar to struct in C++
    protected int data; //data part of node
    protected Node link; //containing address of next node in queue
    public Node(){
        data = 0;
        link = null;
    }
    public Node(int d,Node n){
        this.data = d;
        this.link = n;
    }
    public int getData(){
        return data;
    }
    public Node getLink(){
        return link;
    }
    public void setData(int d){
        this.data = d;
    }
    public void setLink(Node n){
        this.link = n;
    }
}

class Queue{
    protected Node front;   //points to start of the queue
    protected Node rear;    //points to the end of the queue
    protected int size;     //size of the queue
    Queue(){
        this.front = null;
        this.rear = null;
        size = 0;
    }
    public void insert(int item){   //insert a node in the end of queue
        Node newNode = new Node();
        newNode.setData(item);
        newNode.setLink(null);
        if(rear == null){   //if item inserted is first item
            this.front = newNode;
            this.rear = newNode;
        } else{ 
            this.rear.setLink(newNode);
            this.rear = newNode;
        }
        size += 1;  //increase the size of queue
    }
    public void remove(){
        if(front == null){  //if queue empty,print error
            System.out.println("Queue Empty");
        } else{     //remove from front
            if(this.front == this.rear ){   //if only one item in queue
                this.front = null;
                this.rear = null;
            } else{ 
                this.front = this.front.getLink();
            }
            size -= 1;
        }
    }
    public void traverse(){
        if(front.getLink() == null){    //if only one node present
            System.out.println(front.getData()+"!");
        }
        else{   //traverse the queue
            Node ptr = front;
            while(ptr.getLink() != rear){   //print n-1 nodes of queue
                System.out.print(ptr.getData() + "->");
                ptr = ptr.getLink();
            }
            System.out.println(ptr.getData()+"!");  //printing the last node
        }
    }

    public int size(){  //returns the size of queue
        return this.size;
    }
    public boolean isEmpty(){   //checks if queue is empty
        return this.front == null;
    }
}

public class BFS{
    static boolean[] marked;    //marks a vertex true if visited.
    static Queue open = new Queue();    //Queue containing nodes still to be checked
    static Queue closed = new Queue();  //Queue containing nodes who are completely checked
    private static int[][] adjMatrix;   //adjacency matrix of graph
    private static int n;               //number of nodes in the graph
    /*does BFS on the graph*/
    private static void breadthFirstSearch(int vertex){
        closed.insert(vertex); //store the vertex in the result
        for (int i = 0; i < n; i++) { // for the current vertex
            if( adjMatrix[vertex-1][i] ==1 ){   //if an edge exists to some other vertex
                if(!(marked[i])){   //and the other vertex is still not visited
                    open.insert(i+1);   //insert the other vertex in the open queue and mark it visited
                    marked[i] = true;
                }
            }
        }
        open.remove();  //remove the current vertex
        if(closed.size() == n){ /*special case*/
            closed.insert(vertex); //if size of result/closed queue is equal..insert one more time
        }
        if(!open.isEmpty()){    //if there are still vertex to be visited
            breadthFirstSearch( open.front.getData() ); //go to the vertex pointed to by open.
        }
    }
    
    public static void main(String args[]){
        Scanner read = new Scanner(System.in);
        /*Take input*/
        System.out.println("Enter the number of vertices: ");
        n = read.nextInt();
        /*Initialize the arrays*/
        adjMatrix = new int[n][n];
        marked = new boolean[n];
        System.out.println("Enter the adjacency matrix: ");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                adjMatrix[i][j] = read.nextInt();
            }
        }
        /*do a BFS from vertex 1*/
        marked[0] = true;
        open.insert(1);
        breadthFirstSearch(1);
        /*Print the result*/
        System.out.println("The breadth first search of the graph is: ");
        closed.traverse();
        read.close();
    }
}