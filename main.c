#include <stdio.h>
#include <string.h>

#define BUFFER_LEN 1024
#define LINE_LEN 128

void convert(char *arr[],const int count) {
    const char *alp[] =
            {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    char num_arr[BUFFER_LEN] = {0}, part[10];
    int n, m;
    for (int arr_line = 0; arr_line < count; ++arr_line) {
        n = strlen(arr[arr_line]);
        for (int i = 0; i < n; ++i) {
            if ((*(arr[arr_line] + i)) == ' ') {
                strcat(num_arr, " ");
                continue;
            } else if ((*(arr[arr_line] + i)) == '\n') {
                strcat(num_arr, "\n");
                break;
            } else {
                for (int j = 0; j < 8; ++j) {
                    m = strlen(alp[j]);
                    for (int k = 0; k < m; ++k) {
                        if ((*(arr[arr_line] + i)) == (*alp[j] + k)) {
                            sprintf(part, "(%d)%d", j + 2, k + 1);
                            strcat(num_arr, part);
                            break;
                        }
                    }
                }
            }
        }
        strcpy(arr[arr_line], num_arr);
        strcpy(num_arr, "");
    }
}
int main() {
    char line[BUFFER_LEN];
    char buffer[LINE_LEN][BUFFER_LEN];
    char *arr[LINE_LEN];

    int count = 0;

    //Press CTRL + D to terminate typing
    while (fgets(line, BUFFER_LEN - 1, stdin) != NULL) {
        arr[count] = buffer[count];
        strncpy(buffer[count++], line, BUFFER_LEN - 1);
    }
    convert(arr, count);
    for (int i = 0; i < count; i++) {
        printf("%s", arr[i]);
    }

}