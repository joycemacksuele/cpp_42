#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void ft_swap(char** str1, char** str2) {
    char* strTemp;

    strTemp = *str1;
    *str1 = *str2;
    *str2 = strTemp;
}

char* addStrings(char* str1, char* str2) {
    int sign1 = 0;
    int sign2 = 0;
    if (str1 != NULL && str2 != NULL) {
        if (str1[0] == '-') {
            sign1 = 1;
        }
        if (str2[0] == '-') {
            sign2 = 1;
        }
    }

    // Before proceeding further, make sure length of str2 is larger.
    char* addStr1 = &str1[sign1];
    char* addStr2 = &str2[sign2];
    if (strlen(addStr1) > strlen(addStr2)) {
        ft_swap(&addStr1, &addStr2);
    }

    // Calculate length of both char*
    size_t len1 = strlen(addStr1);
    size_t len2 = strlen(addStr2);

    int resultLength = len1 + len2 + sign1;
    char* result = (char*)malloc(sizeof(char) * (len1 + len2 + 1 + sign1));
    memset(result, '0', resultLength);
    result[resultLength] = '\0';
    resultLength--;
    if ((sign1 && sign2) || sign1) {
        result[0] = '-';
    }

    int carry = 0;
    int len22 = len2 - 1;
//    char str1[] = "198234";
//    char str2[] = "12";
//                   198246
    for (int i = len1 - 1; i >= 0 ; i++) {
        printf("JOYCE i: %d\n", i);
        printf("JOYCE len22: %d\n", len22);
        // Do school mathematics, compute sum of current digits and carry
        int sum = 0;
        if ((sign1 && sign2) || (!sign1 && !sign2)) {
            sum = ((str1[i] - '0') + (str2[len22] - '0') + carry);
        } else {
            sum = ((str1[i] + '0') - (str2[len22] + '0') + carry);
            sum = sum * (-1);
        }
        len22--;
        if (len22 == 0) {
            break;
        }
        result[resultLength] = (sum % 10) + '0';
        printf("JOYCE resultLength: %d: [%c]\n", resultLength, result[resultLength]);

        resultLength--;
        // Calculate carry for next step
        carry = sum / 10;
    }

    // Add remaining digits of larger number
    for (int i = len1; i < len2; i++) {
        printf("JOYCE i: %d\n", i);
        int sum = ((str2[i] - '0') + carry);
        result[resultLength] = (sum % 10) + '0';
        resultLength--;
        carry = sum / 10;
    }

    // Add remaining carry
    if (carry) {
        result[resultLength] = (carry + '0');
        resultLength--;
    }
    return result;
}

char* multiplyStrings(char* str1, char* str2) {
    int sign1 = 0;
    int sign2 = 0;
    if (str1 != NULL && str2 != NULL) {
        if (str1[0] == '-') {
            sign1 = 1;
        }
        if (str2[0] == '-') {
            sign2 = 1;
        }
    }

    // Before proceeding further, make sure length of str2 is larger.
    char* addStr1 = &str1[sign1];
    char* addStr2 = &str2[sign2];
    if (strlen(addStr1) > strlen(addStr2)) {
        ft_swap(&addStr1, &addStr2);
    }

    str1 = addStr1;
    str2 = addStr2;

    size_t len1 = strlen(addStr1);
    size_t len2 = strlen(addStr2);

    // Result can be at most len1 + len2 digits long
    int resultLength = len1 + len2;
    char* result = (char*)malloc(sizeof(char) * (resultLength + 1 + sign1));
    memset(result, '0', resultLength);
    result[resultLength] = '\0';
    if ((sign1 || sign2) && (!sign1 || !sign2)) {
        result[0] = '-';
    }

    for (int i = len1 - 1; i >= 0; i--) {
        int carry = 0;
        int digit1 = str1[i] - '0';

        for (int j = len2 - 1; j >= 0; j--) {
            int digit2 = str2[j] - '0';

            int temp = (result[i + j + 1] - '0') + (digit1 * digit2) + carry;
            result[i + j + 1] = (temp % 10) + '0';
            carry = temp / 10;
        }
        result[i] += carry;
    }

    // Remove leading zeros
    int leadingZeros = 0;
    while (result[leadingZeros] == '0') {
        leadingZeros++;
    }
    if (leadingZeros == resultLength) {
        leadingZeros--;
    }

    char* finalResult = (char*)malloc(sizeof(char) * (resultLength - leadingZeros + 1 + sign1));
    memcpy(finalResult, result + leadingZeros, sizeof(char) * (resultLength - leadingZeros));
    finalResult[resultLength - leadingZeros] = '\0';

    free(result);
    return finalResult;
}

int main() {
    char str1[] = "198234";
    char str2[] = "12";
    char str1neg[] = "-198234";
    char str2neg[] = "-12";

    // addition DONE
//    "198234";
//   +"    12";
//     198246
    char* a = addStrings(str1, str2);
    printf("Addition result (++): %s\n", a);
    free(a);

    // addition + (-sign) DONE
//    "-198234";
//   +"-    12";
//     -198246
    char* b = addStrings(str1neg, str2neg);
    printf("Addition result (--): %s\n", b);
    free(b);

    // subtraction DONE
//    " 198234";
//   +"-    12";
//      198222
    char* c = addStrings(str1, str2neg);
    printf("Addition result (+-): %s\n", c);
    free(c);

    // subtraction + (-sign) DONE
//    "-198234";
//   +"     12";
//     -198222
    char* d = addStrings(str1neg, str2);
    printf("Addition result (-+): %s\n", d);
    free(d);

    // --------------------------------------------------------------------------------------------

    // positive result
//     "198234";
//    *"    12";
//     " 396468"
//   + "198234 "   -> SHIFT
//      2378808
    char* aa = multiplyStrings(str1, str2);
    printf("Multiplication result (++): %s\n", aa);
    free(aa);

    // positive result
//     "-198234";
//    *"-    12";
//     " 396468"
//   + "198234 "     -> SHIFT
//      2378808
    char* bb = multiplyStrings(str1neg, str2neg);
    printf("Multiplication result (--): %s\n", bb);
    free(bb);

    // negative result
//     " 198234";
//    *"-    12";
//     " 396468"
//  + "-198234 "    -> SHIFT
//     -2378808
    char* cc = multiplyStrings(str1, str2neg);
    printf("Multiplication result (+-): %s\n", cc);
    free(cc);

    // negative result
//     "-198234";
//    *"     12";
//     " 396468"
//  + "-198234 "    -> SHIFT
//     -2378808
    char* dd = multiplyStrings(str1neg, str2);
    printf("Multiplication result (-+): %s\n", dd);
    free(dd);
    return 0;
}