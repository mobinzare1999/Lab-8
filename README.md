# Lab-8
Lab 08 Exercise 01 of ProgrammingTechniques Politecnico Di Torino
Detection of black regions (with parameters passed by pointers)
Re-implement exercise 1 of Laboratory 7 as follows.
 Supposing that you have declared in the main a matrix of integers M of dimension NR x NC, with NR and NC equal to 50, the acquisition of the content of the matrix from the text file should be handled by a function readMatrix, that should be able to return the actual number of rows and columns of the acquired matrix to the caller “by reference” (or better, “by pointer”). This function may have the following prototype:
void readMatrix(int mat[][NC], int* nrp, int *ncp);
and may be called by the main with the following instructions:
real matrix(M,&nr,&nc);
As a result of the function call, the integer variables nr and nc should contain the actual number of rows and columns of the acquired matrix, M.
The file name should be hardcoded inside the function.
 The detection of regions should be handled by a function detection region that, given a box of the matrix identified by row and column indexes r and c, should determine whether this box represents the upper left corner of a rectangular region. The function should return a Boolean integer as the return value: respectively, 1 if the region is found, and 0 otherwise. The dimensions (width and height) of the rectangle should also be returned to the caller “by reference”, as it was done for nr and nc in the previous point. The function should be called as follows:
if (detectRegion(M,nr,nc,r,c,&w,&h)) {
… … …
}
