#include <stdio.h>

// --- INTERFACE BẮT BUỘC - KHÔNG ĐỔI CHỮ KÝ HÀM ---
void lamMinTinHieu(float raw[], float smooth[], int n);

#ifndef UNIT_TEST
int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    float raw[n], smooth[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap raw[%d]: ", i);
        scanf("%f", &raw[i]);
    }

    lamMinTinHieu(raw, smooth, n);

    printf("\n--- KET QUA LAM MIN TIN HIEU ---");
    printf("\nMang goc: ");
    for (int i = 0; i < n; i++) printf("%.2f ", raw[i]);
    
    printf("\nMang sau khi lam min: ");
    for (int i = 0; i < n; i++) printf("%.2f ", smooth[i]);
    printf("\n");

    return 0;
}
#endif

// --- SINH VIÊN VIẾT CODE CỦA HÀM DƯỚI ĐÂY ---
void lamMinTinHieu(float raw[], float smooth[], int n) {
    // TODO: Viết code thuật toán Moving Average
    // Yêu cầu: Không được dùng printf ở đây!
    
    if (n <= 0) return;

    // Trường hợp đặc biệt khi mảng chỉ có 1 phần tử
    if (n == 1) {
        smooth[0] = raw[0];
        return;
    }

    // Xử lý phần tử đầu tiên (biên trái)
    smooth[0] = (raw[0] + raw[1]) / 2.0f;

    // Xử lý các phần tử ở giữa
    for (int i = 1; i < n - 1; i++) {
        smooth[i] = (raw[i - 1] + raw[i] + raw[i + 1]) / 3.0f;
    }

    // Xử lý phần tử cuối cùng (biên phải)
    smooth[n - 1] = (raw[n - 2] + raw[n - 1]) / 2.0f;
}