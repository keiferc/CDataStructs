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
void test_vector_lo(Vector_T vec);
void test_vector_hi(Vector_T vec);
void test_vector_remove(Vector_T vec);
void test_vector_pops(Vector_T vec);

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
        //test_vector_get(vec);
        //test_vector_lo(vec);
        //test_vector_hi(vec);
        //test_vector_remove(vec);
        test_vector_pops(vec);

        //Cleanup
        //free(test1);
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
        fprintf(stderr, "Edge Cases ---------\n");
        //length = Vector_length(null_vec); //expected assertion

        fprintf(stderr, ">>>>>>>>>> Tests Passed.\n\n");
}

void test_vector_set(Vector_T vec, Test_T test1)
{
        Vector_T null_vec = NULL;
        unsigned index = 0;
        unsigned i;
        int n = 1234;
        int *n_ptr = &n;

        fprintf(stderr, ">>>>>>>>>>>>>>>>>>>> Testing Vector_set\n");

        //Valid Cases
        fprintf(stderr, "Valid Cases --------\n");
        Vector_set(vec, n_ptr, index);

        Vector_set(vec, test1, index);

        fprintf(stderr, "old length: %u\n", Vector_length(vec));
        Vector_set(vec, test1, Vector_length(vec));
        fprintf(stderr, "new length: %u\n", Vector_length(vec));

        for (i = 0; i < 10; i++) {
                Vector_set(vec, test1, i);
        }

        //Edge Cases
        (void) null_vec;
        fprintf(stderr, "Edge Cases ---------\n");
        //Vector_set(vec, n_ptr, 1000); //expected assertion
        //Vector_set(vec, NULL, 0); // expected assertion
        //Vector_set(null_vec, test1, 1); // expected assertion
        //Vector_set(vec, test1, -1); //expected assertion

        fprintf(stderr, ">>>>>>>>>> Tests Passed.\n\n");
}

void test_vector_get(Vector_T vec)
{
        Vector_T null_vec = NULL;
        Test_T test2 = NULL;
        int *ptr;
        unsigned i;
        unsigned index = 0;
        unsigned last = Vector_length(vec) - 1;

        fprintf(stderr, ">>>>>>>>>>>>>>>>>>>> Testing Vector_get\n");

        //Valid Cases
        fprintf(stderr, "Valid Cases --------\n");
        test2 = (Test_T) Vector_get(vec, index);
        fprintf(stderr, "vec[%u]->x: %u\n", index, test2->x);
        fprintf(stderr, "vec[%u]->y: %d\n", index, test2->y);

        test2 = (Test_T) Vector_get(vec, last);
        fprintf(stderr, "vec[%u]->x: %u\n", last, test2->x);
        fprintf(stderr, "vec[%u]->y: %d\n", last, test2->y);

        //Edge Cases
        (void) null_vec, (void) ptr, (void) i;
        fprintf(stderr, "\nEdge Cases ---------\n");
        //ptr = (int *) Vector_get(vec, -1); //expected assertion
        //ptr = (int *) Vector_get(vec, last + 1); //expected assertion
        //ptr = (int *) Vector_get(vec, last + 10); //expected assertion
        //ptr = (int *) Vector_get(null_vec, 0); //expected assertion
        /* expected assertion
        for (i = 0; i < last + 20; i++) {
                ptr = (int *) Vector_get(vec, i);
                fprintf(stderr, "got vec[%u]\n", i);
        }
        */

        fprintf(stderr, ">>>>>>>>>> Tests Passed.\n\n");
}

void test_vector_lo(Vector_T vec)
{
        Vector_T null_vec = NULL;
        Test_T null_test = NULL;
        Test_T out;
        Test_T test2 = malloc(sizeof(struct test));
        assert(test2 != NULL);
        test2->x = 4321;
        test2->y = -1234;

        fprintf(stderr, ">>>>>>>>>>>>>>>>>>>> Testing getlo and setlo\n");

        //Valid Cases
        fprintf(stderr, "Valid Cases --------\n");
        Vector_setlo(vec, test2);
        out = Vector_getlo(vec);
        fprintf(stderr, "lo x: %u\nlo y: %d\n", out->x, out->y);
        fprintf(stderr, "vec length: %u\n", Vector_length(vec));

        out = Vector_get(vec, 1);
        fprintf(stderr, "next x: %u\nnext y: %d\n", out->x, out->y);

        //Edge Cases
        (void) null_vec, (void) null_test;
        fprintf(stderr, "Edge Cases ---------\n");
        //Vector_setlo(null_vec, test2); //expected assertion
        //Vector_setlo(vec, null_test); //expected assertion
        //Vector_setlo(null_vec, null_test); //expected assertion
        //out = Vector_getlo(null_vec); //expected assertion

        //Empty vector
        null_vec = Vector_new(0);
        out = Vector_getlo(null_vec);
        //assert(out != NULL); //expected assertion
        fprintf(stderr, "null_vec length: %u\n", Vector_length(null_vec));

        //Vector_setlo(null_vec, null_test); //expected assertion
        Vector_setlo(null_vec, test2); //should work
        out = Vector_getlo(null_vec); //should work
        fprintf(stderr, "first elem in null_vec: %u\n", out->x);
        fprintf(stderr, "null_vec length: %u\n", Vector_length(null_vec));

        fprintf(stderr, ">>>>>>>>>> Tests Passed.\n\n");
        free(test2);
        Vector_free(&null_vec);
}

void test_vector_hi(Vector_T vec)
{
        Vector_T null_vec = NULL;
        Test_T null_test = NULL;
        Test_T out;
        Test_T test2 = malloc(sizeof(struct test));
        assert(test2 != NULL);
        test2->x = 42;
        test2->y = -42;

        fprintf(stderr, ">>>>>>>>>>>>>>>>>>>> Testing gethi and sethi\n");

        //Valid Cases
        fprintf(stderr, "Valid Cases --------\n");
        out = Vector_gethi(vec);
        fprintf(stderr, "hi1 x: %u\nhi1 y: %d\n", out->x, out->y);
        fprintf(stderr, "vec length: %u\n", Vector_length(vec));
        Vector_sethi(vec, test2);
        out = Vector_gethi(vec);
        fprintf(stderr, "hi2 x: %u\nhi2 y: %d\n", out->x, out->y);
        fprintf(stderr, "vec length: %u\n", Vector_length(vec));


        //Edge Cases
        (void) null_vec, (void) null_test;
        fprintf(stderr, "Edge Cases ---------\n");
        //Vector_sethi(null_vec, test2); //expected assertion
        //Vector_sethi(vec, null_test); //expected assertion
        //Vector_sethi(null_vec, null_test); //expected assertion
        //out = Vector_gethi(null_vec); //expected assertion

        //Empty vector
        null_vec = Vector_new(0);
        out = Vector_gethi(null_vec);
        //assert(out != NULL); //expected assertion
        fprintf(stderr, "null_vec length: %u\n", Vector_length(null_vec));

        //Vector_setlo(null_vec, null_test); //expected assertion
        Vector_sethi(null_vec, test2); //should work
        out = Vector_gethi(null_vec); //should work
        fprintf(stderr, "first elem in null_vec: %u\n", out->x);
        fprintf(stderr, "null_vec length: %u\n", Vector_length(null_vec));

        fprintf(stderr, ">>>>>>>>>> Tests Passed.\n\n");
        free(test2);
        Vector_free(&null_vec);
}

void test_vector_remove(Vector_T vec)
{
        Vector_T null_vec = NULL;
        Test_T out;
        Test_T test2 = malloc(sizeof(struct test));
        assert(test2 != NULL);
        test2->x = 1212121;
        test2->y = -2121212;

        fprintf(stderr, ">>>>>>>>>>>>>>>>>>>> Testing Vector_remove\n");

        //Valid Cases
        fprintf(stderr, "Valid Cases --------\n");
        Vector_setlo(vec, test2);
        out = Vector_getlo(vec);
        fprintf(stderr, "length1: %u\n", Vector_length(vec));
        fprintf(stderr, "lo1->x: %u\nlo1->y: %d\n", out->x, out->y);

        free(test2);
        test2 = NULL;
        Vector_remove(vec, 0);
        out = Vector_getlo(vec);
        fprintf(stderr, "lo2->x: %u\nlo2->y: %d\n", out->x, out->y);
        fprintf(stderr, "length2: %u\n", Vector_length(vec));

        fprintf(stderr, "removing all\n");
        free(out);
        while (Vector_length(vec) != 0)
                Vector_remove(vec, 0);
        fprintf(stderr, "length3: %u\n", Vector_length(vec));

        //Edge Cases
        (void) null_vec;
        fprintf(stderr, "Edge Cases ---------\n");
        //Vector_remove(null_vec, 0); //expected assertion

        //Empty Vector
        //Vector_remove(vec, 0); //expected assertion
        //Vector_remove(vec, -1); //expected assertion

        fprintf(stderr, ">>>>>>>>>> Tests Passed.\n\n");
        //free(test2);
}

void test_vector_pops(Vector_T vec)
{
        (void) vec;
}
