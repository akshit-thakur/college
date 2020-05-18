import java.util.Scanner;

public class HammingDistance {

    public static int findHammingDistance(String first, String second) {
        int hammingDistance = 0;
        for (int i = 0; i < first.length(); i++) {
            int firstBit = (int) first.charAt(i);
            int secondBit = (int) second.charAt(i);
            int xor = firstBit ^ secondBit;
            if (xor == 1)
                hammingDistance += 1;
        }
        return hammingDistance;
    }

    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        try {
            while (true) {
                System.out.println("Enter the 2 binary code words");
                String firstCode = read.next();
                String secondCode = read.next();
                if (firstCode.length() == secondCode.length()) {
                    int result = findHammingDistance(firstCode, secondCode);
                    System.out.println("The Hamming Distance is: " + result);
                    break;
                } else
                    System.out.println("Error! Unequal lengths");
            }
            read.close();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}