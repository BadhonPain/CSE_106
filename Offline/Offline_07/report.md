# Dynamic Programming Offline


## 1. DP Table (for Sample input 2)

**Input:** `I=2  D=2  R=3  |  S="CAT"  |  T="CUT"`

```
       ""    C     U     T
  ""  [ 0]  [ 2]  [ 4]  [ 6]    ← dp[0][j] = j × I
   C  [ 2]  [ 0]  [ 2]  [ 4]
   A  [ 4]  [ 2]  [ 3]  [ 2]    ← dp[2][3]: A≠T, min(3+3, 2+2, 2+2)=4... wait, see below
   T  [ 6]  [ 4]  [ 4]  [ 2]    ← dp[n][m] = 2... no, cost=3 for this example
```

**Correct table for CAT→CUT (I=2, D=2, R=3):**

```
       ""    C     U     T
  ""    0    2     4     6
   C    2    0     2     4
   A    4    2     3     5
   T    6    4     5     3      ← dp[3][3] = 3  
```

**Backtrack path:** (3,3)→(2,2)→(1,1)→(0,0)
- (3,3): T=T → Match T, move to (2,2)
- (2,2): A≠U, dp=3=dp[1][1]+R=0+3 → Replace A with U, move to (1,1)
- (1,1): C=C → Match C, move to (0,0)
- Reversed: **Match C → Replace A with U → Match T**

---

## 2. Recurrence Relation 

```
Base Cases: 
dp[i][j] = 0                              
dp[i][0] = i × D                          
dp[0][j] = j × I                          

dp[i][j] = dp[i-1][j-1]                   if source[i-1] == target[j-1]   (match)
dp[i][j] = min(
              dp[i-1][j-1] + R,           Replace source[i-1] with target[j-1]
              dp[i-1][j]   + D,           Delete source[i-1]
              dp[i][j-1]   + I            Insert target[j-1]
           )                              otherwise
```

---

## 3. Time & Space Complexity

| Metric | Value | Reason |
|--------|-------|--------|
| **Time** | **O(n × m)** | Two nested loops: outer runs n times, inner runs m times → n×m cells filled, O(1) work each |
| **Space** | **O(n × m)** | Full (n+1)×(m+1) DP table stored for backtracking |
| Backtracking | O(n + m) | At each step either i or j (or both) decrease; max n+m steps |
| Total time | **O(n × m)** | Dominates |


