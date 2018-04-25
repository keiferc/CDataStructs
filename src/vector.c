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
//static inline void expand(Vector_T vec);

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

/*-------------------------------------
 * Helper/Private Definitions
 -------------------------------------*/

/*
static inline void expand() {
        //TODO
}
*/
