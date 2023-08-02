#include <stdio.h>

char *infinite_add(char *n1, char *n2, char *r, int size_r) {
    int carry = 0; // Initialize carry to 0
    int idx_n1 = 0;
    int idx_n2 = 0;
    int idx_r = 0;

    // Find the lengths of the input strings
    while (n1[idx_n1] != '\0')
        idx_n1++;
    while (n2[idx_n2] != '\0')
        idx_n2++;

    // Adding digits from the end to the beginning
    while (idx_n1 > 0 || idx_n2 > 0) {
        int digit1 = (idx_n1 > 0) ? (n1[idx_n1 - 1] - '0') : 0;
        int digit2 = (idx_n2 > 0) ? (n2[idx_n2 - 1] - '0') : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        int digitSum = sum % 10;

        if (idx_r < size_r - 1) {
            r[idx_r] = digitSum + '0';
            idx_r++;
        } else {
            // If the result can't be stored in r, return 0
            return 0;
        }

        if (idx_n1 > 0)
            idx_n1--;
        if (idx_n2 > 0)
            idx_n2--;
    }

    // If there's still a carry after processing all digits
    if (carry > 0) {
        if (idx_r < size_r - 1) {
            r[idx_r] = carry + '0';
            idx_r++;
        } else {
            return 0;
        }
    }

    // Null-terminate the result string
    r[idx_r] = '\0';

    // Reverse the result string
    int i = 0;
    int j = idx_r - 1;
    while (i < j) {
        char temp = r[i];
        r[i] = r[j];
        r[j] = temp;
        i++;
        j--;
    }

    return r;
}

int main(void) {
    char *n = "1234567892434574367823574575678477685785645685876876774586734734563456453743756756784458";
    char *m = "9034790663470697234682914569346259634958693246597324659762347956349265983465962349569346";
    char r[100];

    char *res = infinite_add(n, m, r, 100);
    if (res == 0) {
        printf("Error\n");
    } else {
        printf("%s + %s = %s\n", n, m, res);
    }

    return 0;
}
