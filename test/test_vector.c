#include "vector.h"

/*-------------------------------------
 * Function Prototypes
 -------------------------------------*/
void test_vector_length(Vector_T vec);
void test_vector_at(Vector_T vec);

/*-------------------------------------
 * Main
 -------------------------------------*/
int main(int argc, char *argv[]) {
        Vector_T vec;

        (void) argc, (void) argv;

        vec = Vector_new(5);
        assert(vec != NULL);

        //Unit Tests
        test_vector_length(vec);
        test_vector_at(vec);

        //Cleanup
        Vector_free(&vec);
}

/*-------------------------------------
 * Function Definitions
 -------------------------------------*/
void test_vector_length(Vector_T vec)
{
        Vector_T null_vec = NULL;
        unsigned length;

        fprintf(stderr, "Testing Vector_length\n");

        assert(vec != NULL);

        //Valid Cases
        fprintf(stderr, "Valid Cases --------\n");
        length = Vector_length(vec);
        fprintf(stderr, "Length of vec: %u\n", length);

        //Edge Cases
        (void) null_vec;
        //fprintf(stderr, "\nEdge Cases --------\n");
        //length = Vector_length(null_vec); //expected assertion
}

void test_vector_at(Vector_T vec)
{
        Vector_T null_vec = NULL;
        unsigned index = 0;

        fprintf(stderr, "Testing Vector_at\n");

        assert(vec != NULL);

        //Valid Cases
        fprintf(stderr, "Valid Cases --------\n");
        Vector_at(vec, index);

        //Edge Cases
        (void) null_vec;
        //fprintf(stderr, "\nEdge Cases --------\n");
        //length = Vector_length(null_vec); //expected assertion
}
