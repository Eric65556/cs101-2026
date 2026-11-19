#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SETS 5
#define NUMS 7
#define MAX_NUM 69

/* 產生一組 7 個不重複的數字 (01 ~ 69) */
void gen_one_set(int set[NUMS]) {
    int used[MAX_NUM + 1] = {0};
    int cnt = 0;
    while (cnt < NUMS) {
        int r = rand() % MAX_NUM + 1;
        if (!used[r]) {
            used[r] = 1;
            set[cnt++] = r;
        }
    }
    /* 前 6 個由小到大排序，第 7 個(特別號)維持不動 */
    for (int i = 0; i < NUMS - 2; i++)
        for (int j = 0; j < NUMS - 2 - i; j++)
            if (set[j] > set[j + 1]) {
                int t = set[j];
                set[j] = set[j + 1];
                set[j + 1] = t;
            }
}

int main() {
    int n;

    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩：");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_SETS) {
        printf("輸入錯誤，請輸入 1 ~ %d 之間的整數\n", MAX_SETS);
        return 1;
    }

    srand((unsigned)time(NULL));

    FILE *fp = fopen("lotto.txt", "w");
    if (fp == NULL) {
        printf("無法開啟 lotto.txt\n");
        return 1;
    }

    time_t now = time(NULL);
    char *timestr = ctime(&now); /* 例如 "Wed Mar  2 14:12:47 2022\n" */

    fprintf(fp, "======== lotto649 ==========\n");
    fprintf(fp, "= %.24s =\n", timestr);

    for (int i = 0; i < MAX_SETS; i++) {
        fprintf(fp, "[%d]:", i + 1);
        if (i < n) {
            int set[NUMS];
            gen_one_set(set);
            for (int j = 0; j < NUMS; j++)
                fprintf(fp, " %02d", set[j]);
        } else {
            for (int j = 0; j < NUMS; j++)
                fprintf(fp, " --");
        }
        fprintf(fp, "\n");
    }

    fprintf(fp, "======== csie@CGU =========\n");
    fclose(fp);

    printf("以為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);
    return 0;
}
