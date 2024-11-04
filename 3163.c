char* compressedString(char* word) {
    char *comp = (char *)malloc((strlen(word)*2 + 1) * sizeof(char));
    int temp = 1, idx = 0;
    for(int i = 0; word[i] != '\0'; i++){
        // calculate number of same character 
        if(word[i] == word[i+1] && temp < 9) temp ++;
        else{
            comp[idx++] = temp + '0';
            comp[idx++] = word[i];
            temp = 1;
        }
    }
    comp[idx] = '\0';
    return comp;
}


// char* compressedString(char* word) {
//     char *comp = (char *)malloc((strlen(word)*2 + 1) * sizeof(char));
//     int temp = 1, idx = 0;
//     for(int i = 0; word[i] != '\0'; i++){
//         if(word[i] == word[i+1]){
//             temp ++;
//         }else{
//             //if temp > 9
//             if(temp > 9){
//                 while(temp > 9){
//                     comp[idx++] = 9 + '0';
//                     temp-=9;
//                     comp[idx++] = word[i];
//                 }
//             }
//             comp[idx++] = temp + '0';
//             comp[idx++] = word[i];
//             temp = 1;
//         }
//     }
//     comp[idx] = '\0';
//     return comp;
// }