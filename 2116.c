bool canBeValid(char* s, char* locked) {
    int n = strlen(s);
    if(n%2) return false;
    int open = 0, close = 0, unlocked = 0, unlocked1 = 0;
    for(int i = 0; i < n; i++){
        if(locked[i] == '0') unlocked++;
        else if(s[i] == '(') open++;
        else if(s[i] == ')') open--;
        if(unlocked + open < 0) return false;

        int j = n - 1 - i;
        if(locked[j] == '0') unlocked1++;
        else if(s[j] == ')') close++;
        else if(s[j] == '(') close--;
        if(unlocked1 + close < 0) return false;
    }
    return true;
}