import java.util.Scanner;

public class CRC {

    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        int[] message = new int[50];
        int[] gen = new int[50];
        int[] temp = new int[50];
        System.out.println("At Sender's End");
        System.out.println("Enter the number of message bits : ");
        int n = read.nextInt();
        System.out.println("Enter the number of generator bits : ");
        int r = read.nextInt();
        System.out.println("Enter the message : ");
        for (int i = 0; i < n; i++)
            message[i] = read.nextInt();
        System.out.println("Enter the generator : ");
        for (int i = 0; i < r; i++)
            gen[i] = read.nextInt();
        r--;
        for (int i = 0; i < r; i++)
            message[n + i] = 0;
        for (int i = 0; i < n + r; i++)
            temp[i] = message[i];
        division(temp, gen, n, r);
        System.out.println("CRC:");
        for (int i = 0; i < r; i++) {
            System.out.print(temp[n + i] + " ");
            message[n + i] = temp[n + i];
        }
        System.out.println();
        System.out.println("Transmitted Message : ");
        for (int i = 0; i < n + r; i++)
            System.out.print(message[i] + " ");
        System.out.println("\nAt Receiver's End ");
        System.out.println("Enter the received message : ");
        for (int i = 0; i < n + r; i++)
            message[i] = read.nextInt();
        for (int i = 0; i < n + r; i++)
            temp[i] = message[i];
        division(temp, gen, n, r);
        read.close();
        for (int i = 0; i < r; i++) {
            if (temp[n + i] == 1) {
                System.out.println("Error detected in received message.");
                System.exit(0);
            }
        }
        System.out.println("No error in received Message.\nReceived Message : ");
        for (int i = 0; i < n; i++)
            System.out.print(message[i] + " ");

    }

    private static void division(int[] temp, int[] gen, int n, int r) {
        for (int i = 0; i < n; i++) {
            if (gen[0] == temp[i]) {
                for (int j = 0, k = i; j < r + 1; j++, k++)
                    temp[k] = (temp[k] ^ gen[j]);
            }
        }
    }
}