//record the initial sum of substring. Compare the difference between isVowel(s[i]) and isVowel(s[i - k]).
int isVowel(char s){
    if(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') return 1;
    return 0;
}
int maxVowels(char* s, int k) {
    int sum = 0;
    for(int i = 0;i < k;i++)
        sum+=isVowel(s[i]);
    int max = sum;
    for(int i = k;s[i] !='\0';i++){
        sum+=(isVowel(s[i]) - isVowel(s[i - k]));
        if(max < sum) max = sum;
    }
    return max;
}

//brutal solution O(length(s) * k)
// int maxVowels(char* s, int k) {
//     int max = 0;
//     for(int i = 0; i < strlen(s) - k + 1; i++){
//         int temp = 0;
//         for(int j = i; j < i + k; j++){
//             if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') temp++;
//         }
//         if(max < temp) max = temp;
//     }
// }