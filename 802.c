void dfs(int now, int** graph, int *graphColSize, int *visited, int *safe){
    if(visited[now]) return;
    visited[now] = 1;
    for(int i = 0; i < graphColSize[now]; i++){
        int next = graph[now][i];
        dfs(next, graph, graphColSize, visited, safe);
        if(!safe[next]){
            safe[now] = 0;
            return;
        }
    }
    safe[now] = 1;
}
int* eventualSafeNodes(int** graph, int graphSize, int* graphColSize, int* returnSize) {
    int *visited = (int *)calloc(graphSize, sizeof(int));
    int *safe = (int *)calloc(graphSize, sizeof(int));
    for(int i = 0; i < graphSize; i++){
        if(!visited[i]) dfs(i, graph, graphColSize, visited, safe);
    }
    int *res = (int *)malloc(graphSize * sizeof(int));
    int idx = 0;
    for(int i = 0; i < graphSize; i++){
        if(safe[i]) res[idx++] = i;
    }
    *returnSize = idx;
    free(visited);
    free(safe);
    return res;

}