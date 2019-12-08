#include <stddef.h>
#include <string.h>

//Buckets implement a linked list.
typedef struct Bucket {
    struct Bucket *next;
    char *key;
    void *data;
} Bucket;

//HashMap have a size and an array of pointers to the tails of each list of buckets.
typedef struct HashMap {
    int size;
    Bucket **buckets;
} HashMap;

//call back functions defines.
typedef void *(*ResolveCollisionCallback)(void *old_data, void *new_data);

typedef void (*CallBack)(const char *key, void *data);

typedef void (*DestroyDataCallback)(void *data);



/*==========Function declarations======================*/
/**
 * sum up the ascii chars and divide by the number of indexes we have.  the remainder of the op is the hash of the string.
 * @param string to be hashed.
 * @return hash value.
 */
unsigned int hash(const char *string);

size_t myStrLen(const char *str);

HashMap *create_hashmap(size_t key_space);

char *copyString(const char *string);

void insert_data(HashMap *hm, const char *key, void *data, ResolveCollisionCallback resolve_collision);

void iterate(HashMap *hm, CallBack callBack);

void *get_data(HashMap *hm, const char *key);

void remove_data(HashMap *hm, const char *key, DestroyDataCallback destroy_data);

void freeBucketList(Bucket *bucket, DestroyDataCallback destroy_data);

void delete_hashmap(HashMap *hm, DestroyDataCallback destroy_data);

/*===================================================*/


