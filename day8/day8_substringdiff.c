
 
#include <stdio.h>
#include <string.h>

#define MAXN 1501

char s1[MAXN], s2[MAXN];

static int can(int n, int k, int len)
{
    for (int d = -(n - 1); d <= n - 1; ++d) {
        int j_lo = (d > 0) ? 0 : -d;          
        int j_hi = (d < 0) ? n - 1 : n - 1 - d; 

        if (j_hi - j_lo + 1 < len)
            continue;                          

        int mis = 0;

    
        for (int j = j_lo; j < j_lo + len; ++j)
            mis += (s1[j + d] != s2[j]);

        if (mis <= k)
            return 1;

      
        for (int j = j_lo + len; j <= j_hi; ++j) {
            mis += (s1[j + d] != s2[j]);
            mis -= (s1[j + d - len] != s2[j - len]);
            if (mis <= k)
                return 1;
        }
    }
    return 0;
}

int substringDiff(int k, const char *a, const char *b)
{
    int n = (int)strlen(a);
    memcpy(s1, a, n + 1);
    memcpy(s2, b, n + 1);

    int lo = 0, hi = n, ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (can(n, k, mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

int main(void)
{
    int t;
    if (scanf("%d", &t) != 1)
        return 0;

    while (t--) {
        int k;
        char a[MAXN], b[MAXN];
        if (scanf("%d %s %s", &k, a, b) != 3)
            return 0;

        printf("%d\n", substringDiff(k, a, b));
    }

    return 0;
}
