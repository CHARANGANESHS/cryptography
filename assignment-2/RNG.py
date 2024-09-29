import numpy as np #type: ignore
import platform

# Manually implemented Chi-square test
def chi_square_test(random_sequence, bins=1000):
    # Calculate observed frequencies
    observed_freq, _ = np.histogram(random_sequence, bins=bins, range=(1, 1000))
    expected_freq = len(random_sequence) / bins
    
    # Manually calculate the Chi-square statistic
    chi_square_stat = sum((observed - expected_freq) ** 2 / expected_freq for observed in observed_freq)
    
    return chi_square_stat

# Manually implemented Kolmogorov-Smirnov (KS) test
def ks_test(random_sequence):
    n = len(random_sequence)
    
    # Sort the random sequence
    sorted_sequence = np.sort(random_sequence)
    
    # Calculate D-statistic manually
    D_statistic = 0.0
    for i, value in enumerate(sorted_sequence):
        # Empirical CDF (F_observed) for uniform distribution
        F_observed = (i + 1) / n
        # Theoretical CDF for uniform distribution over range (0, 5)
        F_expected = value / 5.0  # Since the random floats are in [0, 5]
        
        # Calculate the D-statistic
        D_statistic = max(D_statistic, abs(F_observed - F_expected))
    
    return D_statistic

# Generate random integers between 1 and 1000 using numpy
def generate_random_numbers(seed, count=5000):
    np.random.seed(seed)
    return np.random.randint(1, 1001, count)

# Generate random floats between 0 and 5
def generate_random_floats(seed, count=30):
    np.random.seed(seed)
    return np.random.uniform(0, 5, count)

# Chi-square critical value lookup for df = bins-1 and 95% confidence level
def get_chi_square_critical_value(df):
    chi_square_critical_95 = 1073.64  # df=999 at 95% confidence from Chi-square table
    return chi_square_critical_95

# KS test critical values for a given sample size and confidence level
def get_ks_critical_value(n, confidence_level):
    if confidence_level == 0.05:  # 95% confidence
        return 1.36 / np.sqrt(n)
    elif confidence_level == 0.01:  # 99% confidence
        return 1.63 / np.sqrt(n)
    return 0.0


if __name__ == "__main__":
    seeds = [10, 202, 303, 404, 505, 606, 707, 808, 909, 1001, 1102, 1203, 1304]  # List of seeds for 13 runs
    run = 1
    for seed in seeds:
        print(f"Run {run}:")
        run += 1
        print(f"Testing seed {seed}:")
        
        # Chi-square test
        random_seq = generate_random_numbers(seed)
        chi_stat = chi_square_test(random_seq)
        chi_critical_95 = get_chi_square_critical_value(999)
        
        print(" 1. Chi-square")
        print(f"    Statistic = {chi_stat}")
        print(f"    Critical Value at 95% = {chi_critical_95}")
        if chi_stat < chi_critical_95:
            print("    Conclusion(95%): Random (Accept)\n")
        else:
            print("    Conclusion(95%): Not Random (Reject)\n")
        
        # Kolmogorov-Smirnov test (KS)
        random_floats = generate_random_floats(seed)
        ks_stat = ks_test(random_floats)
        
        ks_critical_95 = get_ks_critical_value(len(random_floats), 0.05)
        ks_critical_99 = get_ks_critical_value(len(random_floats), 0.01)
        
        print(" 2. Kolmogorov-Smirnov")
        print(f"    Statistic = {ks_stat}")
        print(f"    Critical value at 95% = {ks_critical_95}")
        if ks_stat < ks_critical_95:
            print("    Conclusion(95%): Random (Accept)")
        else:
            print("    Conclusion(95%): Not Random (Reject)")
        
        print(f"    Critical value at 99% confidence = {ks_critical_99}")
        if ks_stat < ks_critical_99:
            print("    Conclusion(99%): Random (Accept)\n")
        else:
            print("    Conclusion(99%): Not Random (Reject)\n")
        
        print("--------------------------------------------------")

    # Print system info
    print("\nKernel Version:", platform.release())
    print("OS Version:", platform.platform())
