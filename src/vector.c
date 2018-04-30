/*
 *      filename:       vector.c
 *      author:         @keiferchiang
 *      date:           23 Apr. 2018
 *      version:        0.0.1
 *
 *      description:    Implementation of the Vector module
 */

#include "vector.h"

/*-------------------------------------
 * Representation
 -------------------------------------*/
typedef void **Array_T;

struct vector_t {
        Array_T array;
        unsigned capacity;
        unsigned size;
};

/*-------------------------------------
 * Helper/Private Prototypes
 -------------------------------------*/
/*
 * expand
 *
 * Increases the capacity of vector from n to (2n + 1)
 */
static inline void expand(Vector_T vec);

/*-------------------------------------
 * Function Definitions
 -------------------------------------*/
Vector_T Vector_new(unsigned hint)
{
        Vector_T vec;

        vec = malloc(sizeof(struct vector_t));
        assert(vec != NULL);

        vec->capacity = hint;
        vec->size = 0;
        vec->array = malloc(vec->capacity * sizeof(void *));
        assert(vec->array != NULL);

        return vec;
}

void Vector_free(Vector_T *vec)
{
        assert(vec != NULL);
        assert(*vec != NULL);

        if ((*vec)->array != NULL) {
                free((*vec)->array);
        }

        (*vec)->size = 0;
        (*vec)->capacity = 0;
        free(*vec);
        *vec = NULL;
}

unsigned Vector_length(Vector_T vec)
{
        assert(vec != NULL);
        return vec->size;
}

void *Vector_at(Vector_T vec, unsigned index)
{
        assert(vec != NULL);

        /*
        while (index >= vec->capacity)
                expand(vec);

        return vec->array[index];
        */

        (void) index;
        unsigned cap;
        fprintf(stderr, "Testing expand\n");

        cap = vec->capacity;
        fprintf(stderr, "Orig cap: %u\n", cap);

        expand(vec);
        cap = vec->capacity;
        fprintf(stderr, "New cap: %u\n", cap);

        expand(vec);
        cap = vec->capacity;
        fprintf(stderr, "New cap2: %u\n", cap);

        return NULL;
}

/*-------------------------------------
 * Helper/Private Definitions
 -------------------------------------*/
static inline void expand(Vector_T vec) {
        Array_T new_arr;
        unsigned new_cap;
        unsigned i;

        assert(vec != NULL);

        new_cap = (vec->capacity * 2) + 1;
        new_arr = malloc(new_cap * sizeof(void *));

        for (i = 0; i < vec->capacity; i++) {
                new_arr[i] = (void *) (uintptr_t) vec->array[i];

                fprintf(stderr, "new_arr[%u]: %p\n", i, new_arr[i]);
                fprintf(stderr, "old_arr[%u]: %p\n", i, vec->array[i]);
        }

        free(vec->array);
        vec->array = new_arr;
        vec->capacity = new_cap;
}
