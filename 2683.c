bool doesValidArrayExist(int* derived, int derivedSize) {
    for(int i = 1; i < derivedSize; i++)
        derived[0] ^= derived[i];
    return (!derived[0]) ? true : false;
}

// bool doesValidArrayExist(int* derived, int derivedSize) {
//     if(derivedSize==1) return (derived[0]) ? false : true;
//     int *ori = calloc((derivedSize + 1) , sizeof(int));
//     for(int i = 1; i <= derivedSize; i++){
//         ori[i] = ori[i-1] ^ derived[i-1];
//     }
//     return (!ori[derivedSize]) ? true : false;
// }