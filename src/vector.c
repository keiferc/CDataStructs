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
 * error
 * 
 * Temporary measure until finished with assert. Prints
 * out given error message to stderr and exits with exit
 * code 1
 */
static inline void error(char *msg);

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
	char *error_msg;

	vec = malloc(sizeof(struct vector_t));
	error_msg = "Error: unable to malloc Vector_T\n";
	
	//TODO: Write function to throw error if failed
	//	to alloc memory
	//Temporary solution below
	if (vec == NULL)
		error(error_msg);
	
	vec->capacity = hint;
	vec->size = 0;
	vec->array = malloc(vec->capacity * sizeof(void *));

	if (vec->array == NULL)
		error(error_msg);
	
	return vec;
}

/*-------------------------------------
 * Helper/Private Definitions
 -------------------------------------*/
static inline void error(char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

/*
static inline void expand() {
	//TODO
}
*/
