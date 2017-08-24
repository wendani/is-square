struct cord{
    int x,
    int y,
};

int is_square(struct cord[])
{
    int dist[6] = {0};
    int idx = 0;

    for (i = 0; i < 4, i++)
        for (j = i + 1; j < 4; j++) {
            dist[idx] = (cord[i].x - cord[j].x)^2 + (cord[i].y - cord[j].y)^2;
            idx++;
        }
   
    sort(dist);
   
    for(i = 1; i < 4; i++)
        if (dist[i] != dist[0])
            return false;
    for(i = 4; i< 6; i++)
        if (dist[i] != 2 * dist[0])
            return false;
           
    return true;
}
