#include "hashmap.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>


unsigned int hash(const char *string) {
    int i = 0;
    unsigned int hash = 0;
    while (string[i] != '\0') {
        hash += string[i];
        i++;
    }
    return hash;
}

size_t myStrLen(const char *str) {
    return strlen(str) + 1;
}

HashMap *create_hashmap(size_t key_space) {

    HashMap *hm = (HashMap *) malloc(key_space * sizeof(Bucket *));

    //I was doing something wrong here, why?
    //Bucket *bucket = (Bucket *) malloc(key_space * sizeof(Bucket));

    hm->size = key_space;
    hm->buckets = (Bucket **) malloc(key_space * sizeof(Bucket));


    for (int i = 0; i < hm->size; i++) {
        hm->buckets[i] = NULL;
    }

    return hm;

}


char *copyString(const char *string) {
    int len = myStrLen(string);
    char *res = (char *) malloc(sizeof(char) * len);
    for (int i = 0; i < len; i++) {
        res[i] = string[i];
    }

    return res;
}

void insert_data(HashMap *hm, const char *key, void *data, ResolveCollisionCallback resolve_collision) {

    if (hm != NULL && key != NULL) {
        unsigned int i = (hm->size % hash(key));

        if (hm->buckets[i] == NULL) {
            Bucket *bucket = (Bucket *) malloc(sizeof(Bucket));
            bucket->data = data;

//            int keylen = myStrLen(key);

            //this is not needed since strcpy does malloc?
//            char *k = (char *) malloc(keylen * sizeof(char));

            //(strcpy(k, key));

            bucket->key = copyString(key);


            bucket->next = NULL;
            hm->buckets[i] = bucket;

        } else {
            Bucket *current = hm->buckets[i];

            while (current != NULL) {
                if (strcmp(key, current->key) != 0) {
                    current = current->next;
                } else {
                    current->data = resolve_collision(current->data, data);
                    return;
                }
            }

            Bucket *bucket = (Bucket *) malloc(sizeof(Bucket));
            bucket->data = data;

//            int keylen = myStrLen(key);
//            char *k = (char *) malloc(keylen * sizeof(char));
//            strcpy(k, key);

            bucket->key = copyString(key);
            bucket->next = hm->buckets[i];
            hm->buckets[i] = bucket;

        }
    }
}

void iterate(HashMap *hm, CallBack callBack) {
    if (hm != NULL) {
        unsigned int size = hm->size;

        int i = 0;
        while (i < size) {
            if (hm->buckets[i] != NULL) {
                Bucket *current = hm->buckets[i];
                while (current != NULL) {
                    callBack(current->key, current->data);
                    current = current->next;
                }
            }
            i++;
        }
    }
}

void *get_data(HashMap *hm, const char *key) {
    if (hm == NULL)
        return NULL;
    unsigned int i = hm->size % hash(key);
    if (key == NULL || hm->buckets[i] == NULL) {
        return NULL;
    } else {
        Bucket *current = hm->buckets[i];
        while (current != NULL) {
            if (strcmp(key, current->key) == 0) {
                return current->data;
            }
            current = current->next;
        }
    }
}

void remove_data(HashMap *hm, const char *key, DestroyDataCallback destroy_data) {
    if (key != NULL && hm != NULL) {
        unsigned int i = (hm->size % hash(key));
        Bucket *current = hm->buckets[i];
        Bucket *prev = hm->buckets[i];
        int c = 0;
        while (current != NULL) {
            if (strcmp(key, current->key) == 0) {
                if (destroy_data != NULL) {
                    destroy_data(current->data);
                }
                if (c == 0) {
                    hm->buckets[i] = current->next;
                    free(current);
                    break;
                } else {
                    prev->next = current->next;
                    free(current);
                    break;
                }
            } else {
                if (c != 0) {
                    prev = current;
                }
                current = current->next;
                c = 1;
            }
        }
    }
}

void freeBucketList(Bucket *bucket, DestroyDataCallback destroy_data) {
    if (bucket->next == NULL) {
        if (destroy_data != NULL) {
            destroy_data(bucket->data);
        }
        //maybe not needed?
        bucket = NULL;

        free(bucket);
        return;
    }
    freeBucketList(bucket->next, destroy_data);
}

void delete_hashmap(HashMap *hm, DestroyDataCallback destroy_data) {
    if (hm != NULL) {
        int size = hm->size;
        int i = 0;
        Bucket *current;
        while (i < size) {
            current = hm->buckets[i];
            if (current != NULL) {
                freeBucketList(current, destroy_data);
            }
            i++;
        }
        free((hm->buckets));
        free(hm);
    }
}