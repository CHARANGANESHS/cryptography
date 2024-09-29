import java.util.Random;

public class RNG {

    // Generate random integers between 1 and 1000
    public static int[] generateRandomNumbers(long seed, int count) {
        Random random = new Random(seed);
        int[] randomSequence = new int[count];
        for (int i = 0; i < count; i++) {
            randomSequence[i] = random.nextInt(1000) + 1;
        }
        return randomSequence;
    }

    // Generate random floats between 0 and 5
    public static double[] generateRandomFloats(long seed, int count) {
        Random random = new Random(seed);
        double[] randomSequence = new double[count];
        for (int i = 0; i < count; i++) {
            randomSequence[i] = 5 * random.nextDouble();
        }
        return randomSequence;
    }

    // Chi-square test
    public static double chiSquareTest(int[] randomSequence, int bins) {
        long[] observedFreq = new long[bins];
        double expectedFreq = (double) randomSequence.length / bins;

        // Calculate observed frequencies
        for (int value : randomSequence) {
            int bin = (value - 1) / (1000 / bins);
            observedFreq[bin]++;
        }

        // Calculate Chi-square statistic
        double chiSquareStat = 0.0;
        for (long observed : observedFreq) {
            chiSquareStat += Math.pow(observed - expectedFreq, 2) / expectedFreq;
        }

        return chiSquareStat;
    }

    // KS Test (D-statistic calculation)
    public static double ksTest(double[] randomSequence, int count) {
        double D_statistic = 0.0;

        // Sort the random sequence
        java.util.Arrays.sort(randomSequence);

        // Calculate the D-statistic
        for (int i = 0; i < count; i++) {
            double F_observed = (i + 1) / (double) count;
            double F_expected = randomSequence[i] / 5.0;  // CDF of uniform distribution U[0, 5]
            D_statistic = Math.max(D_statistic, Math.abs(F_observed - F_expected));
        }

        return D_statistic;
    }

    // Get Chi-square critical value from table for df = bins - 1 (at 95% confidence)
    public static double getChiSquareCriticalValue(int df) {
        return 1073.64; // df = 999, alpha = 0.05 (95% confidence)
    }

    // Get KS critical value for a given confidence level
    public static double getKSCriticalValue(int count, double confidenceLevel) {
        if (confidenceLevel == 0.05) {
            return 1.36 / Math.sqrt(count); // 95% confidence
        } else if (confidenceLevel == 0.01) {
            return 1.63 / Math.sqrt(count); // 99% confidence
        }
        return 0.0;
    }

    public static void main(String[] args) {
        long[] seeds = {10, 202, 303, 404, 505, 606, 707, 808, 909, 1001, 1102, 1203, 1304};
        int bins = 1000;

        int run = 1;
        for (long seed : seeds) {
            // Chi-square test
            int[] randomSeq = generateRandomNumbers(seed, 5000);
            double chiStat = chiSquareTest(randomSeq, bins);

            // 95% Confidence for Chi-square
            double chiCritical95 = getChiSquareCriticalValue(bins - 1);
            System.err.println("Run " + run++ + ": ");
            System.out.println("1. Chi-square test");
            System.out.println("    Testing seed -> " + seed);
            System.out.println("    Statistic = " + chiStat);
            System.out.println("    Chi-square critical value(95%) = " + chiCritical95);
            if (chiStat < chiCritical95) {
                System.out.println("    Conclusion(95%): Random (Accept)");
            } else {
                System.out.println("    Conclusion(95%): Not Random (Reject)");
            }

            System.out.println();

            // KS test
            double[] randomFloats = generateRandomFloats(seed, 30);
            double D_statistic = ksTest(randomFloats, 30);

            // 95% and 99% Confidence for KS test
            double ksCritical95 = getKSCriticalValue(30, 0.05);
            double ksCritical99 = getKSCriticalValue(30, 0.01);

            System.out.println("2. KS test");
            System.out.println("    Testing seed -> " + seed);
            System.out.println("    Statistic = " + D_statistic);
            System.out.println("    KS critical value(95%) = " + ksCritical95);
            if (D_statistic < ksCritical95) {
                System.out.println("    Conclusion(95%): Random (Accept)");
            } else {
                System.out.println("    Conclusion(95%): Not Random (Reject)");
            }

            System.out.println();
            System.out.println("    KS critical value(99%)  = " + ksCritical99);
            if (D_statistic < ksCritical99) {
                System.out.println("    Conclusion(99%): Random (Accept)");
            } else {
                System.out.println("    Conclusion(99%): Not Random (Reject)");
            }
            System.out.println("--------------------------------------------------\n");
        }
        System.out.println("OS: " + System.getProperty("os.name"));
        System.out.println("Kernel Version: " + System.getProperty("os.version"));
    }
    
}
