#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

float plus(int num1, int num2) {
    return num1 + num2;
}

float minus(int num1, int num2) {
    return num1 - num2;
}

float multiply(int num1, int num2) {
    return num1 * num2;
}

float divide(int num1, int num2) {
    return (float)num1 / (float)num2;
}

void logging(char *calculation) {
    time_t now_time;
    char buf[256];

    time(&now_time);
    ctime_s(buf, sizeof(buf), &now_time);

    FILE* fp = NULL;

    if (fopen_s(&fp, "log_calc.json", "a") != 0) {
        perror("파일 열기 실패");
        return;
    }

    fprintf(fp, "{ \"calculation\": \"%s\", \"timestamp\": \"%s\" }\n", calculation, buf);

    fclose(fp);
}

int main()
{
    while (true) {
        int num1, num2;
        char sign;
        float result;
        char calculation[100];

        printf("숫자를 입력하세요: ");
        scanf_s("%d", &num1);

        printf("부호를 입력하세요: ");
        scanf_s(" %c", &sign);

        printf("숫자를 입력하세요: ");
        scanf_s("%d", &num2);

        if (sign == '+') {
            result = plus(num1, num2);
        } 
        else if (sign == '-') {
            result = minus(num1, num2);
        }
        else if (sign == '*') {
            result = multiply(num1, num2);
        }
        else if (sign == '/') {
            result = divide(num1, num2);
        }
        else {
            printf("연산 오류");
        }

        sprintf_s(calculation, sizeof(calculation), "%d %c %d %c %.5g", num1, sign, num2, '=', result);

        printf("계산 : %s\n", calculation);
        logging(calculation);
    }

    return 0;
}