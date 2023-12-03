#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool is_consonant(char ch) {
// проверяю, что буква согласная
    const char consonants[] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    for (int i = 0; i < sizeof(consonants) - 1; i++) {
        if (ch == consonants[i]) {
            return true;
        }
    }
    return false;
}

bool is_unique_consonants(char* word) {
    // проверяю, что все согласные разные
    int len = strlen(word);
    bool is_consonant_used[26] = { 0 };
    for (int i = 0; i < len; i++) {
        if (is_consonant(word[i])) {
            int index = (int)(tolower(word[i]) - 'a');
            if (is_consonant_used[index]) {
                return false;
            }
            is_consonant_used[index] = true;
        }
    }
    return true;
}

int main() {
    enum State {
        START,
        WORD,
        SPACE,
    };
    enum State state = START;


    char word[1000];
    int wordIdx = 0;
    char input;
    int wordCount = 0;
    char res[1000] = {0};

    while ((input = getchar()) != EOF) {
        switch (state) {
            case START:
                if (isalpha(input)) {
                    word[wordIdx] = input;
                    wordIdx++;
                    state = WORD;
                }
                break;

            case WORD:
                if (isalpha(input)) {
                    word[wordIdx] = input;
                    wordIdx++;
                } 
                else if (isspace(input) || input == '\n' || input == '\t' || input == ',') {
                    word[wordIdx] = '\0';
                    if (is_unique_consonants(word)) {
                        wordCount++;
                        if (wordCount != 1) {
                            strcat(res, ", ");
                        }
                        strcat(res, word);
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
    if (wordCount == 0) {
        printf("There aren't any true words.");
    }
    else {
        printf("There are %d true words: %s.\n", wordCount, res);
    }
    return 0;
}





