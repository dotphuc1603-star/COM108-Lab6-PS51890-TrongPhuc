#include <stdio.h>

// --- INTERFACE BẮT BUỘC - KHÔNG ĐỔI CHỮ KÝ HÀM ---
void nenDelta(int goc[], int delta[], int n);
void giaiNenDelta(int delta[], int khoiPhuc[], int n);

#ifndef UNIT_TEST
int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    int goc[n], delta[n], khoiPhuc[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap goc[%d]: ", i);
        scanf("%d", &goc[i]);
    }

    nenDelta(goc, delta, n);
    giaiNenDelta(delta, khoiPhuc, n);

    printf("\n--- KET QUAI NEN & GIAI NEN DELTA ---");
    printf("\nMang goc: ");
    for (int i = 0; i < n; i++) printf("%d ", goc[i]);

    printf("\nMang Delta (Nen): ");
    for (int i = 0; i < n; i++) printf("%d ", delta[i]);

    printf("\nMang khoi phuc (Giai nen): ");
    for (int i = 0; i < n; i++) printf("%d ", khoiPhuc[i]);
    printf("\n");

    return 0;
}
#endif

// --- SINH VIÊN VIẾT CODE CỦA HÀM DƯỚI ĐÂY ---
void nenDelta(int goc[], int delta[], int n) {
    // TODO: Viết code nén Delta (Không dùng printf)
    if (n <= 0) return;

    delta[0] = goc[0];
    for (int i = 1; i < n; i++) {
        delta[i] = goc[i] - goc[i - 1];
    }
}

void giaiNenDelta(int delta[], int khoiPhuc[], int n) {
    // TODO: Viết code giải nén Delta (Không dùng printf)
    if (n <= 0) return;

    khoiPhuc[0] = delta[0];
    for (int i = 1; i < n; i++) {
        khoiPhuc[i] = khoiPhuc[i - 1] + delta[i];
    }
}