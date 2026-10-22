#include <stdio.h>

int main() {
    FILE *fp;
    int i; // 宣告變數 i，避免在 for 迴圈內宣告造成編譯錯誤
    
    // 定義要寫入的 3 個陣列
    int a[] = {0, 1, 2};
    char b[] = "ABC";
    float c[] = {1.1f, 1.2f, 1.3f};
    
    // 用於存放讀取出來的資料的變數/陣列
    int ra[3];
    char rb[4]; // 多留一個空間給字串結尾的 '\0'
    float rc[3];
    
    // 1. 以二進位寫入模式 ("wb") 開啟檔案 a.bin
    fp = fopen("a.bin", "wb");
    if (fp == NULL) {
        printf("無法開啟檔案進行寫入！\n");
        return 1;
    }
    
    // 2. 透過二進位形式 (fwrite) 寫入 3 個陣列
    fwrite(a, sizeof(int), 3, fp);
    fwrite(b, sizeof(char), 3, fp); // 寫入 3 個字元 'A', 'B', 'C'
    fwrite(c, sizeof(float), 3, fp);
    
    // 關閉檔案
    fclose(fp);
    
    // 3. 以二進位讀取模式 ("rb") 再次開啟檔案
    fp = fopen("a.bin", "rb");
    if (fp == NULL) {
        printf("無法開啟檔案進行讀取！\n");
        return 1;
    }
    
    // 4. 透過二進位形式 (fread) 讀取內容
    fread(ra, sizeof(int), 3, fp);
    fread(rb, sizeof(char), 3, fp);
    rb[3] = '\0'; // 加上字串結束字元
    fread(rc, sizeof(float), 3, fp);
    
    // 關閉檔案
    fclose(fp);
    
    // 5. 輸出 3 個陣列的內容
    // 輸出整數陣列
    for (i = 0; i < 3; i++) {
        printf("%d ", ra[i]);
    }
    printf("\n");
    
    // 輸出字元陣列
    printf("%s\n", rb);
    
    // 輸出浮點數陣列
    for (i = 0; i < 3; i++) {
        printf("%f ", rc[i]);
    }
    printf("\n");

    return 0;
}
