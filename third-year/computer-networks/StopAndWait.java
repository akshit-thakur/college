import java.util.Random;

public class StopAndWait {
    static class Timer {
        long begTime;

        public void start() {
            begTime = System.currentTimeMillis();
        }

        public long elapsedTime() {
            return (System.currentTimeMillis() - begTime) * 2;
        }

        boolean isTimeout(long seconds) {
            return seconds >= elapsedTime();
        }
    }

    public static void main(String[] args) {
        int frames[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        long seconds = 1;
        Timer t = new Timer();
        Random random = new Random();
        System.out.println("Sender has to send frames : ");
        for (int i = 0; i < 10; i++)
            System.out.print(frames[i] + " ");
        System.out.println();
        int count = 0;
        boolean delay = false;
        System.out.println("Sender\t\t\t\t\tReceiver");
        do {
            if (count < 0)
                count = 0;
            boolean timeout = false;
            System.out.print("Sending Frame : " + frames[count] + "\t\t");
            t.start();
            if (random.nextInt() % 2 == 1) {
                int to = 24600 + random.nextInt() % (64000 - 24600) + 1;
                for (int i = 0; i < 64000; i++)
                    for (int j = 0; j < to; j++) {
                    }
            }

            if (t.elapsedTime() <= seconds) {
                System.out.println("Received Frame : " + frames[count] + " ");
                if (delay) {
                    System.out.println("Duplicate");
                    delay = false;
                }
                count++;
            } else {
                System.out.println("---\nTimeout");
                timeout = true;
            }
            t.start();
            if (random.nextInt() % 2 == 1 || !timeout) {
                int to = 24600 + random.nextInt() % (64000 - 24600) + 1;
                for (int i = 0; i < 64000; i++)
                    for (int j = 0; j < to; j++) {
                    }
                if (t.elapsedTime() > seconds) {
                    System.out.println("Delayed Ack");
                    count--;
                    delay = true;
                } else if (!timeout) {
                    System.out.println("Acknowledgement : " + (frames[count - 1]));
                }
            }
        } while (count != 10);
    }
}