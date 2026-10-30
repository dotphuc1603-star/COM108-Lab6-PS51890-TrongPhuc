#include <stdio.h>

#ifndef MAX_COLS
#define MAX_COLS 100
#endif

// --- INTERFACE BẮT BUỘC - KHÔNG ĐỔI CHỮ KÝ HÀM ---
int doDiemNong(int a[100][MAX_COLS], int rows, int cols, int hang[], int cot[], int val[]);

#ifndef UNIT_TEST
int main() {
    int rows, cols;
    printf("Nhap so hang: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);

    int a[100][MAX_COLS];
    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int hang[100], cot[100], val[100];
    int count = doDiemNong(a, rows, cols, hang, cot, val);

    printf("\n--- KET QUA TIM DIEM NONG (PEAK) ---\n");
    printf("So luong diem nong tim thay: %d\n", count);
    for (int k = 0; k < count; k++) {
        printf("Diem %d: a[%d][%d] = %d\n", k + 1, hang[k], cot[k], val[k]);
    }

    return 0;
}
#endif

// --- SINH VIÊN VIẾT CODE CỦA HÀM DƯỚI ĐÂY ---
int doDiemNong(int a[100][MAX_COLS], int rows, int cols, int hang[], int cot[], int val[]) {
    // TODO: Viết thuật toán dò Peak Detection
    // Yêu cầu: Không dùng printf trong hàm này! Sử dụng toán tử lớn hơn nghiêm ngặt (>)

    int count = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int current = a[i][j];
            int isPeak = 1;

            // Duyệt các ô lân cận 3x3 xung quanh (i, j)
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    // Bỏ qua chính ô hiện tại
                    if (di == 0 && dj == 0) continue;

                    int ni = i + di;
                    int nj = j + dj;

                    // Kiểm tra nếu ô lân cận nằm trong biên
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                        // Nếu có ô lân cận lớn hơn hoặc bằng thì không phải là Peak
                        if (a[ni][nj] >= current) {
                            isPeak = 0;
                            break;
                        }
                    }
                }
                if (!isPeak) break;
            }

            // Nếu thỏa mãn là điểm nóng, lưu lại thông tin
            if (isPeak) {
                hang[count] = i;
                cot[count] = j;
                val[count] = current;
                count++;
            }
        }
    }

    return count;
}