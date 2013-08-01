#define MAX_WORDS 1000
#define MAX_WORD_LEN 100
#define MAGIC_NUM 31

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char *word;
    unsigned count;
    struct node *next;
} hash_node_t;

hash_node_t *WORDS[MAX_WORDS];

unsigned hash_code(const char *s) {
    unsigned code = 0;
    for (; *s; s++)
        code = code * MAGIC_NUM + *s;
    return code % MAX_WORDS;
}

void insert_word(const char *word) {
    unsigned code = hash_code(word);
    hash_node_t *hn;

    // find from the hash table
    for (hn = WORDS[code]; hn; hn = hn->next)
        if (!strcmp(hn->word, word)) {
            hn->count++;
            return;
        }

    // insert into the hash table
    hn = (hash_node_t *)malloc(sizeof(hash_node_t));
    hn->word = strdup(word);
    hn->count = 1;
    hn->next = WORDS[code];
    WORDS[code] = hn;
}

int main() {
    char word[MAX_WORD_LEN];
    hash_node_t *hn;
    int i;

    // init
    for (i = 0; i < MAX_WORDS; i++)
        WORDS[i] = NULL;

    // input
    while (scanf("%s", word) != EOF)
        insert_word(word);

    // dump
    for (i = 0; i < MAX_WORDS; i++)
        for (hn = WORDS[i]; hn; hn = hn->next)
            printf("%s:\t%d\n", hn->word, hn->count);
 
    return 0;
}
