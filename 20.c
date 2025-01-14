bool isValid(char* s) {
    char *stack = calloc(strlen(s), sizeof(char));
    int top = -1;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            stack[++top] = s[i];
        }else{
            if(top == -1) return false;
            char topChar = stack[top--];
            if((topChar != '(' && s[i] == ')') || (topChar != '[' && s[i] == ']') || (topChar != '{' && s[i] == '}')) return false;
        }
    }
    bool res = (top == -1);
    free(stack);
    return res;
}

// bool isValid(char* s) {
//     if(strlen(s)%2) return false;
//     int cntS = 0, cntM = 0, cntL = 0, idx = 0;
//     int *left = calloc(strlen(s), sizeof(int));
//     for(int i = 0; s[i] != '\0'; i++){
//         if(s[i] == '(') {
//             cntS++;
//             left[idx++] = 1;
//         }else if(s[i] == '[') {
//             cntM++;
//             left[idx++] = 2;
//         }else if(s[i] == '{') {
//             cntL++;
//             left[idx++] = 3;
//         }else if(s[i] == ')') {
//             cntS--;
//             if(cntS < 0) return false;
//             if(left[idx-1] != 1){
//                 return false;
//             }else{
//                 left[idx-1] = 0;
//                 idx--;
//             }
//         }else if(s[i] == ']') {
//             cntM--;
//             if(cntM < 0) return false;
//             if(left[idx-1] != 2){
//                 return false;
//             }else{
//                 left[idx-1] = 0;
//                 idx--;
//             }
//         }else if(s[i] == '}') {
//             cntL--;
//             if(cntL < 0) return false;
//             if(left[idx-1] != 3){
//                 return false;
//             }else{
//                 left[idx-1] = 0;
//                 idx--;
//             }
//         }
//     }
//     if(cntS != 0 || cntM != 0 || cntL != 0) return false;
//     return true;
// }