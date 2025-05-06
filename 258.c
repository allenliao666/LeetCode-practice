int addDigits(int num) {
    if(num == 0) return 0;
    if(num % 9 == 0) return 9;
    return num % 9;
}
// int addDigits(int num) {
//     while(num>9){
//         num = num % 10 + num / 10;
//     }
//     return num;
// }