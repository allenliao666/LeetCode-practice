#include <stdlib.h>
#include <limits.h>

typedef struct {
    int time, x, y;
} HNode;

typedef struct {
    HNode *buf;
    int size, cap;
} Heap;

static Heap* _heap_create(int cap) {
    Heap *h = malloc(sizeof *h);
    h->buf = malloc(sizeof *h->buf * cap);
    h->size = 0; h->cap = cap;
    return h;
}

static void _hswap(HNode *a, HNode *b) {
    HNode tmp = *a; *a = *b; *b = tmp;
}

static void _heap_push(Heap *h, HNode v) {
    if (h->size == h->cap) {
        h->cap <<= 1;
        h->buf = realloc(h->buf, sizeof *h->buf * h->cap);
    }
    int i = h->size++;
    h->buf[i] = v;
    while (i > 0) {
        int p = (i - 1) >> 1;
        if (h->buf[p].time <= h->buf[i].time) break;
        _hswap(&h->buf[p], &h->buf[i]);
        i = p;
    }
}

static HNode _heap_pop(Heap *h) {
    HNode ret = h->buf[0];
    h->buf[0] = h->buf[--h->size];
    int i = 0;
    while (1) {
        int l = (i<<1) + 1, r = l + 1, best = i;
        if (l < h->size && h->buf[l].time < h->buf[best].time) best = l;
        if (r < h->size && h->buf[r].time < h->buf[best].time) best = r;
        if (best == i) break;
        _hswap(&h->buf[i], &h->buf[best]);
        i = best;
    }
    return ret;
}

static void _heap_free(Heap *h) {
    free(h->buf);
    free(h);
}

/* LeetCode entry point */
int minTimeToReach(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    if (n == 0) return -1;
    int m = gridColSize[0];

    const int INF = INT_MAX;
    int **dist = malloc(n * sizeof *dist);
    for (int i = 0; i < n; i++) {
        dist[i] = malloc(m * sizeof *dist[i]);
        for (int j = 0; j < m; j++)
            dist[i][j] = INF;
    }

    Heap *pq = _heap_create(n * m);
    _heap_push(pq, (HNode){ .time = 0, .x = 0, .y = 0 });
    dist[0][0] = 0;

    int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

    while (pq->size) {
        HNode cur = _heap_pop(pq);
        int t = cur.time, x = cur.x, y = cur.y;
        if (t > dist[x][y]) continue;
        if (x == n - 1 && y == m - 1) break;

        for (int d = 0; d < 4; d++) {
            int nx = x + dirs[d][0], ny = y + dirs[d][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                int nt = t + 1;
                if (grid[nx][ny] + 1 > nt) nt = grid[nx][ny] + 1;
                if (nt < dist[nx][ny]) {
                    dist[nx][ny] = nt;
                    _heap_push(pq, (HNode){ .time = nt, .x = nx, .y = ny });
                }
            }
        }
    }

    int ans = dist[n-1][m-1];
    for (int i = 0; i < n; i++) free(dist[i]);
    free(dist);
    _heap_free(pq);
    return ans;
}