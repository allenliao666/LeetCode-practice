typedef struct{
    int *queue;
    int tail;
    int rear;
    int size;
} RecentCounter;

RecentCounter *recentCounterCreate(){
    RecentCounter *cnt = (RecentCounter*) malloc(sizeof(RecentCounter));
    cnt->size = 10000;
    cnt->queue = (int*) malloc(cnt->size * sizeof(int));
    cnt->tail = 0;
    cnt->rear = 0;
    return cnt;
}

int recentCounterPing(RecentCounter *obj, int t){
    obj->queue[obj->rear++] = t; //record the time of new ping in index obj->rear
    while(obj->queue[obj->tail] < t - 3000){
        obj->tail++;
    }
    return obj->rear - obj->tail;
}

void recentCounterFree(RecentCounter *obj){
    free(obj->queue);
    free(obj);
}
