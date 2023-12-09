#include "shell.h"

char **string_to_words(char *sentence, char *delimiters) {
    int index_i, index_j, index_k, index_m, word_count = 0;
    char **word_array;

    if (sentence == NULL || sentence[0] == 0)
        return (NULL);
    if (!delimiters)
        delimiters = " ";
    for (index_i = 0; sentence[index_i] != '\0'; index_i++)
        if (!is_delimiter(sentence[index_i], delimiters) && (is_delimiter(sentence[index_i + 1], delimiters) || !sentence[index_i + 1]))
            word_count++;

    if (word_count == 0)
        return (NULL);
    word_array = malloc((1 + word_count) * sizeof(char *));
    if (!word_array)
        return (NULL);
    for (index_i = 0, index_j = 0; index_j < word_count; index_j++) {
        while (is_delimiter(sentence[index_i], delimiters))
            index_i++;
        index_k = 0;
        while (!is_delimiter(sentence[index_i + index_k], delimiters) && sentence[index_i + index_k])
            index_k++;
        word_array[index_j] = malloc((index_k + 1) * sizeof(char));
        if (!word_array[index_j]) {
            for (index_k = 0; index_k < index_j; index_k++)
                free(word_array[index_k]);
            free(word_array);
            return (NULL);
        }
        for (index_m = 0; index_m < index_k; index_m++)
            word_array[index_j][index_m] = sentence[index_i++];
        word_array[index_j][index_m] = 0;
    }
    word_array[index_j] = NULL;
    return (word_array);
}

char **string_to_words_v2(char *sentence, char delimiter) {
    int index_i, index_j, index_k, index_m, word_count = 0;
    char **word_array;

    if (sentence == NULL || sentence[0] == 0)
        return (NULL);
    for (index_i = 0; sentence[index_i] != '\0'; index_i++)
        if ((sentence[index_i] != delimiter && sentence[index_i + 1] == delimiter) ||
            (sentence[index_i] != delimiter && !sentence[index_i + 1]) || sentence[index_i + 1] == delimiter)
            word_count++;
    if (word_count == 0)
        return (NULL);
    word_array = malloc((1 + word_count) * sizeof(char *));
    if (!word_array)
        return (NULL);
    for (index_i = 0, index_j = 0; index_j < word_count; index_j++) {
        while (sentence[index_i] == delimiter && sentence[index_i] != delimiter)
            index_i++;
        index_k = 0;
        while (sentence[index_i + index_k] != delimiter && sentence[index_i + index_k] && sentence[index_i + index_k] != delimiter)
            index_k++;
        word_array[index_j] = malloc((index_k + 1) * sizeof(char));
        if (!word_array[index_j]) {
            for (index_k = 0; index_k < index_j; index_k++)
                free(word_array[index_k]);
            free(word_array);
            return (NULL);
        }
        for (index_m = 0; index_m < index_k; index_m++)
            word_array[index_j][index_m] = sentence[index_i++];
        word_array[index_j][index_m] = 0;
    }
    word_array[index_j] = NULL;
    return (word_array);
}

