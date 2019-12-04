#include <stddef.h>

typedef struct HashMap HashMap;

typedef void *(*ResolveCollisionCallback)(void *old_data, void *new_data);

typedef void (*CallBack)(char *key, void *data);

typedef void (*DestroyDataCallback)(void *data);

/**
 * sum up the ascii chars and divide by the number of indexes we have.  the remainder of the op is the hash of the string.
 * @param string
 * @return
 */
unsigned int hash(char *string);

HashMap *create_hashmap(size_t key_space);

void insert_data(HashMap *hm, char *key, void *data, ResolveCollisionCallback resolve_collision);

void *get_data(HashMap *hm, CallBack callBack);

void remove_data(HashMap *hm, char *key, DestroyDataCallback destroy_data);