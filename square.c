#include <stdio.h>

enum {
	false = 0,
	true  = 1,
};

struct coord{
    int x;
    int y;
};

void inser_sort(int a[], int size)
{
	int i, j, temp;

	if ((!a) || (size < 2))
		return;

	for (i = 1; i < size; i++) {
		temp = a[i];
		for (j = i - 1; j >= 0 && temp < a[j]; j--)
			a[j + 1] = a[j];
		a[j + 1] = temp;
	}
}

int is_square(struct coord point[])
{
    int dist_sq[6] = {0};
    int i, j;
    int idx = 0;

    for (i = 0; i < 4; i++)
        for (j = i + 1; j < 4; j++) {
            dist_sq[idx] = (point[i].x - point[j].x) * (point[i].x - point[j].x)
				+ (point[i].y - point[j].y) * (point[i].y - point[j].y);
	    if (!dist_sq[idx])
		return false;
            idx++;
        }
   
    inser_sort(dist_sq, 6);
   
    for(i = 1; i < 4; i++)
        if (dist_sq[i] != dist_sq[0])
            return false;

    for(i = 4; i < 6; i++)
        if (dist_sq[i] != 2 * dist_sq[0])
            return false;
           
    return true;
}

int main(int argc, char *argv[])
{
	int i;
	struct coord pnt[] = {
		{0, 0},
		{0, 1},
		{1, 0},
		{1, 1},
	};

	printf("is square? %s\n", is_square(pnt) ? "yes" : "no");

	for (i = 0; i < 4; i++) {
		pnt[i].x = 0;
		pnt[i].y = 0;
	}

	printf("is square? %s\n", is_square(pnt) ? "yes" : "no");

	return 0;
}
