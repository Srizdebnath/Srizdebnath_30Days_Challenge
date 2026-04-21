#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

int op_val[MAXN];
char op_type[MAXN];
int unique_vals[MAXN];
int freq[MAXN];
int bit[MAXN];
int M = 0;

int cmp(const void *a, const void *b) {
    int ia = *(const int *)a;
    int ib = *(const int *)b;
    if (ia < ib) return -1;
    if (ia > ib) return 1;
    return 0;
}

int get_idx(int v) {
    int l = 0, r = M - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (unique_vals[mid] == v) return mid + 1;
        if (unique_vals[mid] < v) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

void add(int idx, int delta) {
    for (; idx <= M; idx += idx & -idx)
        bit[idx] += delta;
}

int find_kth(int k) {
    int idx = 0;
    for (int i = 17; i >= 0; --i) {
        int next_idx = idx + (1 << i);
        if (next_idx <= M && bit[next_idx] < k) {
            idx = next_idx;
            k -= bit[idx];
        }
    }
    return idx + 1;
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;
    
    for (int i = 0; i < N; ++i) {
        if (scanf(" %c %d", &op_type[i], &op_val[i]) != 2) return 0;
        unique_vals[i] = op_val[i];
    }
    
    qsort(unique_vals, N, sizeof(int), cmp);
    
    if (N > 0) {
        M = 1;
        for (int i = 1; i < N; ++i) {
            if (unique_vals[i] != unique_vals[i - 1]) {
                unique_vals[M++] = unique_vals[i];
            }
        }
    }
    
    int S = 0;
    for (int i = 0; i < N; ++i) {
        int v = op_val[i];
        int idx = get_idx(v);
        
        if (op_type[i] == 'a') {
            freq[idx]++;
            add(idx, 1);
            S++;
        } else if (op_type[i] == 'r') {
            if (freq[idx] == 0) {
                printf("Wrong!\n");
                continue;
            } else {
                freq[idx]--;
                add(idx, -1);
                S--;
            }
        }
        
        if (S == 0) {
            printf("Wrong!\n");
        } else if (S % 2 != 0) {
            int k = (S + 1) / 2;
            int res_idx = find_kth(k);
            printf("%d\n", unique_vals[res_idx - 1]);
        } else {
            int k1 = S / 2;
            int k2 = S / 2 + 1;
            int idx1 = find_kth(k1);
            int idx2 = find_kth(k2);
            long long v1 = unique_vals[idx1 - 1];
            long long v2 = unique_vals[idx2 - 1];
            long long sum = v1 + v2;
            if (sum % 2 == 0) {
                printf("%lld\n", sum / 2);
            } else {
                if (sum < 0) {
                    long long abs_sum = -sum;
                    printf("-%lld.5\n", abs_sum / 2);
                } else {
                    printf("%lld.5\n", sum / 2);
                }
            }
        }
    }
    
    return 0;
}
