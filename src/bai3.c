#include <stdio.h>

#ifndef MAX_COLS
#define MAX_COLS 100
#endif

// --- INTERFACE BẮT BUỘC - KHÔNG ĐỔI CHỮ KÝ HÀM ---
void lamMoMaTran(int src[100][MAX_COLS], int dest[100][MAX_COLS], int rows, int cols);

#ifndef UNIT_TEST
int main() {
    int rows, cols;
    printf("Nhap so hang: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);

    int src[100][MAX_COLS];
    int dest[100][MAX_COLS] = {0};

    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &src[i][j]);
        }
    }

    lamMoMaTran(src, dest, rows, cols);

    printf("\n--- MA TRAN SAU KHI LAM MO (BOX BLUR) ---\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", dest[i][j]);
        }
        printf("\n");
    }

    return 0;
}
#endif

// --- SINH VIÊN VIẾT CODE CỦA HÀM DƯỚI ĐÂY ---
void lamMoMaTran(int src[100][MAX_COLS], int dest[100][MAX_COLS], int rows, int cols) {
    // TODO: Viết thuật toán Box Blur 3x3
    // Yêu cầu tuyệt đối: Không dùng printf trong hàm này!

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int sum = 0;
            int count = 0;

            // Duyệt qua vùng lân cận 3x3 xung quanh điểm (i, j)
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    int ni = i + di;
                    int nj = j + dj;

                    // Kiểm tra xem ô lân cận có nằm trong biên của ma trận hay không
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                        sum += src[ni][nj];
                        count++;
                    }
                }
            }

            // Tính trung bình cộng theo số lượng ô lân cận thực tế
            if (count > 0) {
                dest[i][j] = sum / count;
            } else {
                dest[i][j] = src[i][j];
            }
        }
    }
}