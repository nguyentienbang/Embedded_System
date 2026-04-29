#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sinhvien.h"

int cmpTen(const void *a, const void *b) {
    return strcmp(((SinhVien*)a)->ten, ((SinhVien*)b)->ten);
}

int cmpHo(const void *a, const void *b) {
    return strcmp(((SinhVien*)a)->ho, ((SinhVien*)b)->ho);
}

void apply(SinhVien *ds, int n, void (*func)(SinhVien)) {
    for (int i = 0; i < n; i++) {
        func(ds[i]);
    }
}

void isOlder(SinhVien sv) {
    if (sv.tuoi > 20) {
        printf("%s %s %d\n", sv.ho, sv.ten, sv.tuoi);
    }
}

void docFile(SinhVien *ds, int *n) {
    FILE *f = fopen("data.txt", "r");
    char line[200];
    *n = 0;

    while (fgets(line, sizeof(line), f)) {
        char *token;

        token = strtok(line, " ,\n");
        if (!token) continue;
        strcpy(ds[*n].ho, token);

        token = strtok(NULL, " ,\n");
        if (!token) continue;
        strcpy(ds[*n].ten, token);

        token = strtok(NULL, " ,\n");
        if (!token) continue;
        ds[*n].tuoi = atoi(token);

        (*n)++;
    }
    fclose(f);
}