#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* solve() {
    char s[1005];
    if (scanf("%s", s) != 1) return "NO";
    
    int n = strlen(s);
    char stack[1005];
    int top = -1;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        } 
        else {
            if (top == -1) return "NO";
            
            char last = stack[top--];
            if ((s[i] == ')' && last != '(') ||
                (s[i] == '}' && last != '{') ||
                (s[i] == ']' && last != '[')) {
                return "NO";
            }
        }
    }
    return (top == -1) ? "YES" : "NO";
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    
    while (t--) {
        printf("%s\n", solve());
    }
    
    return 0;
}
