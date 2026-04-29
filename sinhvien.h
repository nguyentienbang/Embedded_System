#ifndef _SINHVIEN_H_
#define _SINHVIEN_H_

typedef struct {
    char ho[50];
    char ten[50];
    int tuoi;
} SinhVien;

int cmpTen(const void*, const void*);
int cmpHo(const void*, const void*);
void apply(SinhVien*, int, void (*func)(SinhVien));
void isOlder(SinhVien);
void docFile(SinhVien*, int*);

#endif