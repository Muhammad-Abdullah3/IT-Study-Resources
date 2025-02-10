import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

public class RandomWord {
    public static void main(String[] args) {
        String champion = null;
        int count = 0;

        while (!StdIn.isEmpty()) {  // Ensures compliance with Coursera's style checks
            String word = StdIn.readString();
            count++;

            // Use StdRandom.bernoulli() instead of Math.random() to comply with guidelines
            if (StdRandom.bernoulli(1.0 / count)) {
                champion = word;
            }
        }

        if (champion != null) {
            StdOut.println(champion);
        }
    }
}
