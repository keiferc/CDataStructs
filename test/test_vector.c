#include "vector.h"

/*-------------------------------------
 * Representation
 -------------------------------------*/
typedef struct test {
        unsigned x;
        int y;
} *Test_T;

/*-------------------------------------
 * Function Prototypes
 -------------------------------------*/
void test_vector_length(Vector_T vec);
void test_vector_set(Vector_T vec, Test_T test1);
void test_vector_get(Vector_T vec);

/*-------------------------------------
 * Main
 -------------------------------------*/
int main(int argc, char *argv[]) {
        Vector_T vec;
        Test_T test1 = NULL;

        (void) argc, (void) argv;

        vec = Vector_new(10);
        assert(vec != NULL);

        test1 = malloc(sizeof(struct test));
        assert(test1 != NULL);
        test1->x = 10;
        test1->y = -5;

        fprintf(stderr, "\n"); //formatting

        //Unit Tests
        test_vector_length(vec);
        test_vector_set(vec, test1);
        test_vector_get(vec);

        //Cleanup
        free(test1);
        Vector_free(&vec);
}

/*-------------------------------------
 * Function Definitions
 -------------------------------------*/
void test_vector_length(Vector_T vec)
{
        Vector_T null_vec = NULL;
        unsigned length;

        fprintf(stderr, ">>>>>>>>>>>>>>>>>>>> Testing Vector_length\n");

        //Valid Cases
        fprintf(stderr, "Valid Cases --------\n");
        length = Vector_length(vec);
        fprintf(stderr, "Length of vec: %u\n", length);

        //Edge Cases
        (void) null_vec;
        fprintf(stderr, "\nEdge Cases ---------\n");
        //length = Vector_length(null_vec); //expected assertion

        fprintf(stderr, ">>>>>>>>>> Tests Passed.\n\n");
}

void test_vector_set(Vector_T vec, Test_T test1)
{
        Vector_T null_vec = NULL;
        unsigned index = 0;

        fprintf(stderr, ">>>>>>>>>>>>>>>>>>>> Testing Vector_set\n");

        //Valid Cases
        fprintf(stderr, "Valid Cases --------\n");
        Vector_set(vec, test1, index);

        //Edge Cases
        (void) null_vec;
        fprintf(stderr, "\nEdge Cases ---------\n");
        //length = Vector_length(null_vec); //expected assertion

        fprintf(stderr, ">>>>>>>>>> Tests Passed.\n\n");
}

void test_vector_get(Vector_T vec)
{
        Vector_T null_vec = NULL;
        Test_T test2 = NULL;
        unsigned index = 0;

        fprintf(stderr, ">>>>>>>>>>>>>>>>>>>> Testing Vector_get\n");

        //Valid Cases
        fprintf(stderr, "Valid Cases --------\n");
        test2 = (Test_T) Vector_get(vec, index);
        fprintf(stderr, "vec[%u]->x: %u\n", index, test2->x);
        fprintf(stderr, "vec[%u]->y: %d\n", index, test2->y);

        //Edge Cases
        (void) null_vec;
        fprintf(stderr, "\nEdge Cases ---------\n");
        //length = Vector_length(null_vec); //expected assertion

        fprintf(stderr, ">>>>>>>>>> Tests Passed.\n\n");
}
