/* Using Gauss-Jordan Matrix Elimination
 * to solve linear equation set in time complexity O(n^3).
 * Bubblesort is used for label sorting as example, which
 * can be replaced by any other sorting algorithm.
 *
 * Coded by m.Just 2015-08-07
 */
 
int solve(double* a, double* y, int h, int w, double* buff) {
        int i, j;
        for (i = w-1; i >= 0; i--) {
                buff[i] = y[i];
                for (j = w-1; j > i; j--) {
                        buff[i] -= a[i*w+j]*buff[j];
                }
                buff[i] = buff[i] / a[i*w+i];
        }
}

int getTriMatrix(double* origin, double* originY, int h, int w, double* buff, double* buffY) {
        if (h <= 0 || w <= 0 || NULL == origin || NULL == buff) return 0;
        double order[h];
        int label[h];
        int i, j, k, cnt = 0;
        for (i = 0; i < h; i++) {
                label[i] = i;
                order[i] = 0;
                for (j = 0; j < w; j++) {
                        if (origin[i*h+j]) {
                                order[i] = w-j;
                                break;
                        }
                }
        }
        
        // sort the equations from higher to lower order
        bubbleSort(order, label, h);

        for (i = 0; i < h; i++) {
                buffY[i] = originY[label[i]];
                for (j = 0; j < w; j++) {
                        buff[i*w+j] = origin[label[i]*w+j];
                }
        }

        // elimanate terms in equation in the order of ``label''
        for (i = 0; i < w-1; i++) {
                if (0 == buff[i*w+i]) {
                        printf("Infinite solutions!\n");
                        return 0;
                }
                for (j = i+1; j < h; j++) {
                        if (0 == buff[j*w+i]) break;
                        double para = buff[i*w+i] / buff[j*w+i];
                        buffY[j] = buffY[i] - para * buffY[j];
                        for (k = i; k < w; k++) {
                                buff[j*w+k] = buff[i*w+k] - para * buff[j*w+k];
                        }
                }
        }

        for (i = w; i < h; i++) {
                if (buffY[i-1]/buff[i*w-1] != buffY[i]/buff[(i+1)*w-1]) {
                        printf("No solution!\n");
                        return 0;
                }
        }
        return 1;
}

int bubbleSort(double* num, int* label, int length) {
        int i, j;
        for (i = length-1; i > 0; i--)
                for (j = length-1; j > 0; j--)
                        if (num[j] > num[j-1]) {
                                int tmp; tmp = num[j]; num[j] = num[j-1]; num[j-1] = tmp;
                                if (NULL != label)
                                        tmp = label[j]; label[j] = label[j-1]; label[j-1] = tmp;
                        }
}



