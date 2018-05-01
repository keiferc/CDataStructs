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

        free(*vec);
        *vec = NULL;
}

//////////////////////////////////
//      Getter Functions        //
//////////////////////////////////
unsigned Vector_length(Vector_T vec)
{
        assert(vec != NULL);

        return vec->size;
}

void *Vector_get(Vector_T vec, unsigned index)
{
        assert(vec != NULL);
        assert(index <= vec->size);

        if (vec->size == 0)
                return NULL;

        return vec->array[index];
}

void *Vector_gethi(Vector_T vec)
{
        assert(vec != NULL);

        if (vec->size == 0)
                return NULL;

        return vec->array[(vec->size - 1)];
}

void *Vector_getlo(Vector_T vec)
{
        assert(vec != NULL);

        if (vec->size == 0)
                return NULL;

        return vec->array[0];
}

//////////////////////////////////
//      Setter Functions        //
//////////////////////////////////
void Vector_set(Vector_T vec, void *elem, unsigned index)
{
        assert(vec != NULL);
        assert(elem != NULL);
        assert(index <= vec->size);

        if (index == vec->size)
                vec->size++;

        if (vec->size >= vec->capacity)
                expand(vec);

        vec->array[index] = elem;
}

void Vector_sethi(Vector_T vec, void *elem)
{
        Vector_set(vec, elem, vec->size);
}

void Vector_setlo(Vector_T vec, void *elem)
{
        unsigned length;
        unsigned i;

        assert(vec != NULL);
        assert(elem != NULL);

        length = vec->size;

        for (i = length; i > 0; i--)
                Vector_set(vec, Vector_get(vec, i - 1), i);

        Vector_set(vec, elem, 0);
}

//////////////////////////////////
//      Remove Functions        //
//////////////////////////////////


/*-------------------------------------
 * Helper/Private Definitions
 -------------------------------------*/
static inline void expand(Vector_T vec)
{
        Array_T new_arr;
        unsigned new_cap;

        assert(vec != NULL);

        new_cap = (vec->capacity * 2) + 1;
        new_arr = malloc(new_cap * sizeof(void *));
        assert(new_arr != NULL);

        if (vec->capacity != 0)
                memcpy(new_arr, vec->array, vec->size *
                       sizeof(void *));

        free(vec->array);
        vec->array = new_arr;
        vec->capacity = new_cap;
}
