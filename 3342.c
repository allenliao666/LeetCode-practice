
typedef struct{
    int time, x, y;
} Node;

typedef struct{
    Node *buf;
    int size, cap;
} Heap;

static Heap *create(int cap){
    Heap *h = malloc(sizeof *h);
    h->buf = malloc(sizeof *h->buf * cap);
    h->size = 0; h->cap = cap;
    return h;
}

static void swap(Node *a, Node *b){
    Node temp = *a;
    *a = *b;
    *b = temp;
}

static void push(Heap *h, Node v){
    if(h->size == h->cap){
        h->cap <<= 1;
        h->buf = realloc(h->buf, sizeof *h->buf * h->cap);
    }
    int i = h->size++;
    h->buf[i] = v;
    while(i){
        int p = (i-1) >> 1;
        if(h->buf[p].time <= h->buf[i].time) break;
        swap(&h->buf[p] , &h->buf[i]);
        i = p;
    }
} 

static Node pop(Heap *h){
    Node ret = h->buf[0];
    h->buf[0] = h->buf[--h->size];
    int i = 0;
    while(1){
        int l = (i << 1) + 1, r = l + 1, best = i;
        if(l < h->size && h->buf[l].time < h->buf[best].time) best = l; 
        if(r < h->size && h->buf[r].time < h->buf[best].time) best = r;
        if(i == best) break;
        swap(&h->buf[best], &h->buf[i]);
        i = best; 
    }
    return ret;
}

static void _free(Heap *h){
    free(h->buf);
    free(h);
}


int minTimeToReach(int** moveTime, int moveTimeSize, int* moveTimeColSize) {
    int n = moveTimeSize, m = moveTimeColSize[0];
    if(n == 0) return -1;
    int **dist = malloc(n * sizeof *dist);
    for(int i = 0; i < n; i++){
        dist[i] = malloc(m * sizeof *dist[i]);
        for(int j = 0; j < m; j++){
            dist[i][j] = INT_MAX;
        } 
    } 

    Heap *h = create(n * m);
    push(h, (Node){.time = 0, .x = 0, .y = 0});
    dist[0][0] = 0;

    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while(h->size){
        Node cur = pop(h);
        int t = cur.time, x = cur.x, y = cur.y;
        if(t > dist[x][y]) continue;
        if((x == n-1) && (y == m-1)) break;
        for(int i = 0; i < 4; i++){
            int nx = x + dirs[i][0], ny = y + dirs[i][1];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                int nt = (moveTime[nx][ny] < t ? t : moveTime[nx][ny]) + 2 - (nx+ny) % 2;
                if(nt < dist[nx][ny]){
                    dist[nx][ny] = nt;
                    push(h, (Node){.time = nt, .x = nx, .y = ny});
                }
            }
        }
    }
    
    int res = dist[n-1][m-1];
    for(int i = 0; i < n; i++) free(dist[i]);
    free(dist);
    _free(h);
    return res;
}