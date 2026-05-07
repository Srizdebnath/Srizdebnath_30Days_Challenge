import sys

def precompute(limit):
   
    dp = list(range(limit))
    
    for i in range(1, limit):
       
        if dp[i] > dp[i-1] + 1:
            dp[i] = dp[i-1] + 1
        for j in range(2, i + 1):
            target = i * j
            if target >= limit:
                break
            if dp[target] > dp[i] + 1:
                dp[target] = dp[i] + 1
                
    return dp

def main():
    MAX_N = 1000001
    dp = precompute(MAX_N)
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    try:
        Q = int(input_data[0])
        queries = input_data[1:Q+1]
        
        results = [str(dp[int(n)]) for n in queries]
        sys.stdout.write("\n".join(results) + "\n")
    except (ValueError, IndexError):
        pass

if __name__ == "__main__":
    main()
