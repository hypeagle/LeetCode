#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    char allTxt[10][6] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    char **retStrs, *tmpStr;
    int len = strlen(digits);
    int totalSize, tmpLen;
    int i, j, k, index, tmpIndex;

    if(len == 0) {
        *returnSize = 0;
        return NULL;
    }

    totalSize = 1;
    for(i = 0; i < len; i++) {
        tmpLen = strlen(allTxt[digits[i] - '0']);
        if(tmpLen > 0) {
            totalSize *= tmpLen;
        }
    }

    *returnSize = totalSize;
    retStrs = (char **)malloc(totalSize * sizeof(char *));

    index = 0;
    for(j = 0; allTxt[digits[0] - '0'][j] != '\0'; j++) {
        tmpStr = (char *)malloc(len + 2);
        tmpStr[0] = allTxt[digits[0] - '0'][j];
        tmpStr[1] = '\0';
        retStrs[index++] = tmpStr;
    }

    for(i = 1; i < len; i++) {
        if(strlen(allTxt[digits[i] - '0']) > 0) {
            tmpIndex = index;
            for(k = 0; k < tmpIndex; k++) {
                tmpLen = strlen(retStrs[k]);
                retStrs[k][tmpLen] = allTxt[digits[i] - '0'][0];
                retStrs[k][tmpLen + 1] = '\0';
            }
            for(j = 1; allTxt[digits[i] - '0'][j] != '\0'; j++) {
                for(k = 0; k < tmpIndex; k++) {
                    tmpLen = strlen(retStrs[k]);

                    tmpStr = (char *)malloc(len + 2);
                    strcpy(tmpStr, retStrs[k]);

                    tmpStr[tmpLen - 1] = allTxt[digits[i] - '0'][j];
                    tmpStr[tmpLen] = '\0';
                    retStrs[index] = tmpStr;
                    index++;
                }
            }
        }
        
    }

    return retStrs;
}

int main()
{
    int retSize, i;
    char **ret;

    ret = letterCombinations("342", &retSize);
    printf("%d\n", retSize);
    for(i = 0; i < retSize; i ++) {
        printf("%s\n", ret[i]);
        free(ret[i]);
    }
    free(ret);

    return 0;
}