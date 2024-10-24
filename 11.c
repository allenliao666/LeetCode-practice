int min(int a, int b){
    return (a > b) ? b : a;
}

//using 2 pointers, guaranteeing width is decreasing. O(n)
int maxArea(int* height, int heightSize) {
    int max = 0;
    int left = 0, right = heightSize - 1;
    while(left != right){
        int temp = (right - left) * min(height[left], height[right]);
        if(max < temp) max= temp;
        if(height[left] < height[right]){
            left++;
        } else right--;
    }
    return max;
}

//    brutal solution O(n^2)
int maxArea(int* height, int heightSize) {
    int max = 0;
    for(int i = 0; i < heightSize; i++){
        for(int j = i + 1; j < heightSize;j++){
            int temp = (j - i) * min(height[i], height[j]);
            if(max < temp) max= temp;
        }
    }
     return max;
}
   