#include <stdio.h>
#include <stdlib.h>
#include "sinhvien.h"

int main() {
    SinhVien ds[100];
    int n;

    docFile(ds, &n);

    // sắp xếp theo tên
    qsort(ds, n, sizeof(SinhVien), cmpTen);
    printf("Theo ten:\n");
    for (int i = 0; i < n; i++)
        printf("%s %s %d\n", ds[i].ho, ds[i].ten, ds[i].tuoi);

    // sắp xếp theo họ
    qsort(ds, n, sizeof(SinhVien), cmpHo);
    printf("\nTheo ho:\n");
    for (int i = 0; i < n; i++)
        printf("%s %s %d\n", ds[i].ho, ds[i].ten, ds[i].tuoi);

    // apply
    printf("\n>20 tuoi:\n");
    apply(ds, n, isOlder);

    return 0;
}