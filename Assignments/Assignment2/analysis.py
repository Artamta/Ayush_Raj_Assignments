import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# Manually create the DataFrame from the provided data
data = {
    'input_size': [1, 2, 3, 4, 5, 6],
    'selection_sort': [8.34e-07, 1.8292e-05, 0.00128688, 0.123397, 12.0948, 213.977],
    'insertion_sort': [3.33e-07, 9.334e-06, 0.000900167, 0.0781644, 8.02238, 150.188],
    'bubble_sort': [6.67e-07, 3.0875e-05, 0.00312329, 0.326796, 34.1841, 625.198]
}

df = pd.DataFrame(data)

def plot_time_taken(df):
    plt.figure(figsize=(10, 6))
    for column in df.columns[1:]:
        plt.plot(df['input_size'], df[column], label=column)
    plt.xlabel('Input Size')
    plt.ylabel('Time Taken (seconds)')
    plt.title('Time Taken by Sorting Algorithms')
    plt.legend()
    plt.yscale('log')
    plt.xscale('log')
    plt.grid(True)
    plt.show()

def theoretical_time_complexity(input_size, complexity):
    if complexity == 'O(n^2)':
        return input_size ** 2
    elif complexity == 'O(n log n)':
        return input_size * np.log2(input_size)
    else:
        raise ValueError("Unsupported complexity")

def plot_theoretical_vs_experimental(df):
    plt.figure(figsize=(10, 6))
    for column in df.columns[1:]:
        plt.plot(df['input_size'], df[column], label=f'Experimental {column}')
        theoretical = theoretical_time_complexity(df['input_size'], 'O(n^2)')
        plt.plot(df['input_size'], theoretical, '--', label=f'Theoretical {column} O(n^2)')
    plt.xlabel('Input Size')
    plt.ylabel('Time Taken (seconds)')
    plt.title('Theoretical vs Experimental Performance')
    plt.legend()
    plt.yscale('log')
    plt.xscale('log')
    plt.grid(True)
    plt.show()

def calculate_max_input_size(time_limit, complexity):
    if complexity == 'O(n^2)':
        return int(np.sqrt(time_limit))
    elif complexity == 'O(n log n)':
        # Solve n log n = time_limit
        from scipy.optimize import fsolve
        func = lambda n: n * np.log2(n) - time_limit
        return int(fsolve(func, 1e6)[0])
    else:
        raise ValueError("Unsupported complexity")

def main():
    plot_time_taken(df)
    
    # Plot theoretical vs experimental performance
    plot_theoretical_vs_experimental(df)
    
    # Calculate maximum input size for 5-minute execution time limit
    time_limit = 5 * 60  # 5 minutes in seconds
    algorithms = ['selection_sort', 'insertion_sort', 'bubble_sort']
    for algo in algorithms:
        max_input_size = calculate_max_input_size(time_limit, 'O(n^2)')
        print(f'Theoretical maximum input size for {algo} within 5 minutes: {max_input_size}')

if __name__ == '__main__':
    main()