double average(int* salary, int salarySize) {
    int min = salary[0], max = salary[0];
    double total = 0;
    for(int i = 0; i < salarySize; i++){
        if(max <= salary[i]) max = salary[i];
        if(min >= salary[i]) min = salary[i];
        total += salary[i];
    }
    return ((total - min - max)/ (salarySize - 2));
}