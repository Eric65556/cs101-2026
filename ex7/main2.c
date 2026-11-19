#include <stdio.h>
#include <string.h>

#define NUM_BOOKS 6
#define TITLE_LEN 64

typedef struct Books {
    int id;
    int price;
    char title[TITLE_LEN];
} book_t;

/* 計算所有書籍的總價錢 */
void total_price(const book_t books[], int n, int *total) {
    *total = 0;
    for (int i = 0; i < n; i++)
        *total += books[i].price;
}

/* 輸出書籍資料到螢幕 */
void list_books(const book_t books[], int n) {
    printf("%-4s %-8s %s\n", "Id", "Price", "Title");
    for (int i = 0; i < n; i++)
        printf("%-4d %-8d %s\n", books[i].id, books[i].price, books[i].title);
}

int main() {
    /* 在 main 中建立書籍資料 */
    book_t books[NUM_BOOKS] = {
        {1, 1000, "All the Light We Cannot See"},
        {2, 300,  "The 38 Letters from J.D. Rockefeller to his son"},
        {3, 1000, "The Ballad of Songbirds and Snakes"},
        {4, 550,  "Killers of the Flower Moon"},
        {5, 870,  "Elon Musk"},
        {6, 1344, "Milk and Honey 12-Month 2024"}
    };

    /* 將書籍資料以二進位寫入 Book.bin */
    FILE *fp = fopen("Book.bin", "wb");
    if (fp == NULL) {
        printf("無法開啟 Book.bin\n");
        return 1;
    }
    fwrite(books, sizeof(book_t), NUM_BOOKS, fp);
    fclose(fp);

    /* 從 Book.bin 讀回資料，確認檔案內容正確 */
    book_t loaded[NUM_BOOKS];
    fp = fopen("Book.bin", "rb");
    if (fp == NULL) {
        printf("無法讀取 Book.bin\n");
        return 1;
    }
    int cnt = (int)fread(loaded, sizeof(book_t), NUM_BOOKS, fp);
    fclose(fp);

    list_books(loaded, cnt);

    int total;
    total_price(loaded, cnt, &total);
    printf("Total price: %d\n", total);

    return 0;
}
