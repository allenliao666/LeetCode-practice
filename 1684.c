// bitmap
int countConsistentStrings(char * allowed, char ** words, int wordsSize){
    int *allow = (char *) calloc(26, sizeof(int));
    for(int i = 0; allowed[i] != '\0'; i++)
        allow[allowed[i] - 97] = 1;

    int notConsistent = 0;
    for(int i = 0; i < wordsSize; i++){
        for(int j = 0; words[i][j] != '\0'; j++){
            if(!allow[words[i][j] - 97]){
              notConsistent++;
              break;  
            } 
        }
    }    
    return wordsSize - notConsistent;
}


// int countConsistentStrings(char * allowed, char ** words, int wordsSize){
//     int notConsistent = 0;
//     for(int i = 0; allowed[i] != '\0'; i++){
//         for(int j = 0; j < wordsSize; j++){
//             for(int k = 0; words[j][k] != '\0'; k++){
//                 if(allowed[i] == words[j][k]) words[j][k] = '0';
//             }
//         }
//     }
//     for(int j = 0; j < wordsSize; j++){
//         for(int k = 0; words[j][k] != '\0'; k++){
//             if(words[j][k] != '0'){
//                 notConsistent++;
//                 break;
//             } 
//         }
//     }
//     return wordsSize - notConsistent;
// }