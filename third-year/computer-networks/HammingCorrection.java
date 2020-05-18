import java.util.NoSuchElementException;
import java.util.Scanner;

public class HammingCorrection {

    String message;
    int[] codeword;
    int[] temp;
    int n, check;
    char parity;
    Scanner read;

    HammingCorrection() {
        parity = 'E';
        message = "";
        n = 0;
        check = 0;
        codeword = new int[50];
        temp = new int[50];
        read = new Scanner(System.in);
    }

    void generate() {
        System.out.print("Enter the message in binary : ");
        message = read.next();
        n = message.length();
        System.out.print("Odd(O)/Even(E) Parity ? ");
        parity = Character.toUpperCase(read.next().charAt(0));
        for (int i = 0; i < n; i++) {
            char ch = message.charAt(i);
            temp[i + 1] = (ch == '1') ? 1 : 0;
        }
        computeCode();
    }

    void computeCode() {
        check = findr();
        System.out.println("Number of check bits: " + check);
        System.out.println("Number of bits in codeword: " + (n + check));
        for (int i = (n + check), j = n; i > 0; i--) {
            if ((i & (i - 1)) != 0)
                codeword[i] = temp[j--];
            else
                codeword[i] = setParity(i);
        }
        System.out.println("Parity Bits - ");
        for (int i = 0; i < check; i++)
            System.out.print("P" + (int) Math.pow(2, i) + " : " + codeword[(int) Math.pow(2, i)] + "\t");
        System.out.println("\nCodeword :");
        for (int i = 1; i <= (n + check); i++)
            System.out.print(codeword[i] + " ");
        System.out.println();
    }

    void clearBuffer() {
        try {
            read.nextLine();
        } catch (NoSuchElementException e) {
            clearBuffer();
        }
    }

    void correct() {
        System.out.print("Enter the received codeword : ");
        clearBuffer();
        message = read.nextLine();
        for (int i = 0; i < n; i++) {
            char ch = message.charAt(i);
            codeword[i + 1] = (ch == '1') ? 1 : 0;
        }
        detect();
    }

    void detect() {
        int position = 0;
        System.out.println("Parity Bits - ");
        for (int i = 0; i < check; i++) {
            boolean flag = true;
            int x = (int) Math.pow(2, i);
            int bit = codeword[x];
            if (x == 1) {
                for (int j = x + 1; j <= (n + check); j++) {
                    if (j % 2 == 1)
                        bit ^= codeword[j];
                }
            } else {
                for (int k = x + 1; k <= (n + check); k++) {
                    if (flag)
                        bit ^= codeword[k];
                    if ((k + 1) % x == 0)
                        flag = !flag;
                }
            }
            System.out.print("P" + x + ": " + bit + "\t");
            if (parity == 'E' && bit == 1)
                position += x;
            if (parity == 'O' && bit == 0)
                position += x;
        }
        System.out.println("\nReceived Codeword :");
        for (int i = 0; i < (n + check); i++)
            System.out.print(codeword[i] + " ");
        System.out.println();
        if (position != 0) {
            System.out.println("Error at bit : " + position);
            codeword[position] = codeword[position] == 1 ? 0 : 1;
            System.out.println("Corrected Codeword : ");
            for (int i = 1; i <= (n + check); i++)
                System.out.print(codeword[i] + " ");
            System.out.println();
        } else
            System.out.println("No Error in Received code.");
        System.out.println("Received Message is : ");
        for (int i = 1; i <= (n + check); i++)
            if ((i & (i - 1)) != 0)
                System.out.print(codeword[i] + " ");
        System.out.println();
    }

    int findr() {
        for (int i = 1;; i++) {
            if (n + i + 1 <= Math.pow(2, i))
                return i;
        }
    }

    int setParity(int x) {
        boolean flag = true;
        int bit;
        if (x == 1) {
            bit = codeword[x + 2];
            for (int j = x + 3; j <= (n + check); j++) {
                if (j % 2 == 1)
                    bit ^= codeword[j];
            }
        } else {
            bit = codeword[x + 1];
            for (int i = x; i <= (n + check); i++) {
                if (flag) {
                    if (i == x || i == x + 1)
                        bit = codeword[x + 1];
                    else
                        bit ^= codeword[i];
                }
                if ((i + 1) % x == 0)
                    flag = !flag;
            }
        }
        if (parity == 'O')
            return bit == 0 ? 1 : 0;
        else
            return bit;
    }

    public static void main(String[] args) {
        HammingCorrection obj = new HammingCorrection();
        System.out.println("At Sender's side : ");
        obj.generate();
        System.out.println("At Receiver's Side : ");
        obj.correct();
    }
}