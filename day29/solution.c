#include <stdio.h>
#include <stdlib.h>


#define MAXN 500005
#define MAXLOG 20

int A[MAXN];
int sortedA[MAXN];
int st[MAXLOG][MAXN];
int lg2[MAXN];
int n;

void build_st() {
    lg2[1] = 0;
    for (int i = 2; i <= n; i++) lg2[i] = lg2[i / 2] + 1;
    for (int i = 1; i <= n; i++) st[0][i] = i;
    for (int j = 1; j < MAXLOG; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            int a = st[j - 1][i];
            int b = st[j - 1][i + (1 << (j - 1))];
            if (A[a] > A[b]) st[j][i] = a;
            else if (A[a] < A[b]) st[j][i] = b;
            else st[j][i] = a; 
        }
    }
}

int query_st(int L, int R) {
    if (L > R) return 0;
    int j = lg2[R - L + 1];
    int a = st[j][L];
    int b = st[j][R - (1 << j) + 1];
    if (A[a] >= A[b]) return a;
    else return b;
}

struct Node {
    int L, R, count;
} tree[MAXN * 40];

int roots[MAXN];
int node_count = 0;

int update(int prev, int L, int R, int val) {
    int curr = ++node_count;
    tree[curr] = tree[prev];
    tree[curr].count++;
    if (L == R) return curr;
    int mid = L + (R - L) / 2;
    if (val <= mid) tree[curr].L = update(tree[prev].L, L, mid, val);
    else tree[curr].R = update(tree[prev].R, mid + 1, R, val);
    return curr;
}

int query_pst(int nodeL, int nodeR, int L, int R, int qL, int qR) {
    if (qL > R || qR < L || !nodeR) return 0;
    if (qL <= L && R <= qR) return tree[nodeR].count - tree[nodeL].count;
    int mid = L + (R - L) / 2;
    return query_pst(tree[nodeL].L, tree[nodeR].L, L, mid, qL, qR) +
           query_pst(tree[nodeL].R, tree[nodeR].R, mid + 1, R, qL, qR);
}

int distinct_count;
int get_rank(int val) {
    int L = 1, R = distinct_count, ans = 0;
    while (L <= R) {
        int mid = L + (R - L) / 2;
        if (sortedA[mid] <= val) {
            ans = mid;
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    return ans;
}

int get_exact_rank(int val) {
    int L = 1, R = distinct_count;
    while (L <= R) {
        int mid = L + (R - L) / 2;
        if (sortedA[mid] == val) return mid;
        if (sortedA[mid] < val) L = mid + 1;
        else R = mid - 1;
    }
    return 0;
}

long long ans = 0;

void solve(int L, int R) {
    if (L >= R) return;
    int M = query_st(L, R);
    
    if (M - L < R - M) {
      
        for (int i = L; i < M; i++) {
          
            if (A[i] <= 1) ans++;
      
            long long target = (long long)A[M] / A[i];
            int rank = get_rank((int)target);
            if (rank > 0) ans += query_pst(roots[M], roots[R], 1, distinct_count, 1, rank);
        }
       
        int rank1 = get_rank(1);
        if (rank1 > 0) ans += query_pst(roots[M], roots[R], 1, distinct_count, 1, rank1);
    } else {
        
        for (int j = M + 1; j <= R; j++) {
           
            if (A[j] <= 1) ans++;
         
            long long target = (long long)A[M] / A[j];
            int rank = get_rank((int)target);
            if (rank > 0) ans += query_pst(roots[L - 1], roots[M - 1], 1, distinct_count, 1, rank);
        }
  
        int rank1 = get_rank(1);
        if (rank1 > 0) ans += query_pst(roots[L - 1], roots[M - 1], 1, distinct_count, 1, rank1);
    }
    
    solve(L, M - 1);
    solve(M + 1, R);
}

int compare_ints(const void* a, const void* b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int main() {
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 1; i <= n; i++) {
        if (scanf("%d", &A[i]) != 1) break;
        sortedA[i] = A[i];
    }
    
    qsort(sortedA + 1, n, sizeof(int), compare_ints);
    distinct_count = 0;
    if (n > 0) {
        distinct_count = 1;
        for (int i = 2; i <= n; i++) {
            if (sortedA[i] != sortedA[distinct_count]) {
                sortedA[++distinct_count] = sortedA[i];
            }
        }
    }
    
    build_st();
    
    roots[0] = 0;
    for (int i = 1; i <= n; i++) {
        int rank = get_exact_rank(A[i]);
        roots[i] = update(roots[i - 1], 1, distinct_count, rank);
    }
    
    solve(1, n);
    printf("%lld\n", ans);
    
    return 0;
}
