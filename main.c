#include <stdio.h>
#define NR 50
#define NC 50

void readMatrix(int mat[][NC], int* nrp, int *ncp);
int detectRegion(int mat[][NC], int nr, int nc, int r, int c, int *wp, int *hp);
int main() {
    int arr[NR][NC];
    int nr;
    int nc;
    readMatrix(arr,&nr,&nc);
    int w;
    int h;
    printf("please input the row & column: ");
    int ro = 0;
    int co = 0;
    scanf("%d %d",&ro,&co);
    if (detectRegion(arr,nr,nc,ro,co,&w,&h)){
        printf("upper left corner=(%d,%d), height=%d, width=%d, area= %d\n",ro,co,h,w,(h * w));
    }
    return 0;
}

void readMatrix(int mat[][NC], int *nrp, int *ncp){
    FILE *fin;
    fin = fopen("input.txt","r");
    if(fin == NULL){
        printf("error");
        return;
    }
    int nr = 0;
    int nc = 0;
    while (!feof(fin) && nr < NR) {
        nc = 0;
        while (!feof(fin) && nc < NC) {
            fscanf(fin, "%d", &mat[nr][nc]);
            nc++;
        }
        nr++;
    }

    *nrp = nr;
    *ncp = nc;
    fclose(fin);
}
int detectRegion(int mat[][NC], int nr, int nc, int r, int c, int *wp, int *hp){
        if (mat[r][c] != 1) {
            return 0;
        }
        int width = 1, height = 1;
        int col = c + 1;
        while (col < nc && mat[r][col] == 1) {
            width++;
            col++;
        }
        int row = r + 1;
        while (row < nr && mat[row][c] == 1) {
            height++;
            row++;
        }
        *wp = width;
        *hp = height;
        return 1;
}
