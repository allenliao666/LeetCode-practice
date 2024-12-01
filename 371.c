int getSum(int a, int b) {
    while(b){
        unsigned int temp = (unsigned int)(a&b)<<1;
        a = a^b;
        b = temp;
    }
    return a;
}

// int getSum(int a, int b) {
//     int carry = 0;
//     int res = 0;
//     for(int i = 0; i < 32; i++){
//         unsigned int sum;
//         if((a & (1u << i)) ^ (b & (1u << i))) sum = 1;
//         else if(!((a & (1u << i)) ^ (b & (1u << i))) && (a & (1u << i))) sum = 2;
//         else sum = 0;

//         if(carry){
//             if(sum == 2){
//                 carry = 1;
//                 res |= 1u << i;                

//             }else if(carry & sum){
//                 carry = 1;
//             }else{
//                 carry = 0;
//                 res |= 1u << i;                
//             }
//         }else{
//             if(sum == 2){
//                 carry = 1;

//             }else{
//                 res |= sum << i;                
//             }
//         }
//     }
//     return res;
// }