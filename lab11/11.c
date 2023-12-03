#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isBinaryDigit(char c) {
    return (c == '0' || c == '1');
}

int main() {
    enum State {
        START, 
        WORD, 
        SPACE
    };
    enum State state = START;

    char word[1000];
    int wordIdx = 0;
    int wordCount = 0;
    char input;
    char res[1000];

    while ((input = getchar()) != EOF) {
        switch (state) {
            case START:
                if (isBinaryDigit(input)) {
                    memset(word, 0, strlen(word) * sizeof(int));
                    word[wordIdx] = input;
                    wordIdx++;
                    state = WORD;
                }
                break;

            case WORD:
                if (isBinaryDigit(input)) {
                    word[wordIdx] = input;
                    wordIdx++;
                    } 
                else if (isspace(input) || input == '\n' || input == '\t' || input == ',') {
                    word[strlen(word) + 1] = '\0';
                    wordCount++;
                    if (wordCount % 3 == 0) {
                        int length = strlen(word);
                        int lenres = strlen(res);
                        for (int i = 0; i < length; i++) {
                            if (word[i] == '0' || word[i] == '1') {
                                res[i + lenres] = word[i];
                            }
                        }
                        res[lenres + length] = ' ';
                    }
                    wordIdx = 0;
                    state = START;
                }
                else {
                    wordIdx = 0; 
                    state = SPACE;
                }
                break;

            case SPACE:
                if (isspace(input) || input == '\n' || input == '\t' || input == ',') {
                    state = START;
                }
                break;
        }
    }
    int k = strlen(res);
    for (int i = 0; i < k; i++) {
        if (isspace(res[i]) || res[i] == '1' || res[i] == '0') {
            printf("%c", res[i]);
        }
    }
    return 0;
}