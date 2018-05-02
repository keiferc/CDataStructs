#include "linkedlist.h"

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
void test_list_length(LinkedList_T list);
void test_list_set(LinkedList_T list, Test_T test1);
void test_list_get(LinkedList_T list);
void test_list_lo(LinkedList_T list);
void test_list_hi(LinkedList_T list);
void test_list_remove(LinkedList_T list);
void test_list_pops(LinkedList_T list);

/*-------------------------------------
 * Main
 -------------------------------------*/
int main(int argc, char *argv[]) {
        LinkedList_T list;
        Test_T test1 = NULL;

        (void) argc, (void) argv;

        list = LinkedList_new(10);
        assert(list != NULL);

        test1 = malloc(sizeof(struct test));
        assert(test1 != NULL);
        test1->x = 10;
        test1->y = -5;

        fprintf(stderr, "\n"); //formatting

        //Unit Tests
        //test_list_length(list);
        //test_list_set(list, test1);
        //test_list_get(list);
        //test_list_lo(list);
        //test_list_hi(list);
        //test_list_remove(list);
        //test_list_pops(list);

        //Cleanup
        free(test1);
        LinkedList_free(&list);
}

/*-------------------------------------
 * Function Definitions
 -------------------------------------*/
void test_list_length(LinkedList_T list)
{
        LinkedList_T null_list = NULL;
        unsigned length;

        fprintf(stderr, ">>>>>>>>>>>>>>>>>>>> Testing LinkedList_length\n");

        //Valid Cases
        fprintf(stderr, "Valid Cases --------\n");
        length = LinkedList_length(list);
        fprintf(stderr, "Length of list: %u\n", length);

        //Edge Cases
        (void) null_list;
        fprintf(stderr, "Edge Cases ---------\n");
        //length = LinkedList_length(null_list); //expected assertion

        fprintf(stderr, ">>>>>>>>>> Tests Passed.\n\n");
}

void test_list_set(LinkedList_T list, Test_T test1)
{
        LinkedList_T null_list = NULL;
        unsigned index = 0;
        unsigned i;
        int n = 1234;
        int *n_ptr = &n;

        fprintf(stderr, ">>>>>>>>>>>>>>>>>>>> Testing LinkedList_set\n");

        //Valid Cases
        fprintf(stderr, "Valid Cases --------\n");
        LinkedList_set(list, n_ptr, index);

        LinkedList_set(list, test1, index);

        fprintf(stderr, "old length: %u\n", LinkedList_length(list));
        LinkedList_set(list, test1, LinkedList_length(list));
        fprintf(stderr, "new length: %u\n", LinkedList_length(list));

        for (i = 0; i < 10; i++) {
                LinkedList_set(list, test1, i);
        }

        //Edge Cases
        (void) null_list;
        fprintf(stderr, "Edge Cases ---------\n");
        //LinkedList_set(list, n_ptr, 1000); //expected assertion
        //LinkedList_set(list, NULL, 0); // expected assertion
        //LinkedList_set(null_list, test1, 1); // expected assertion
        //LinkedList_set(list, test1, -1); //expected assertion

        fprintf(stderr, ">>>>>>>>>> Tests Passed.\n\n");
}

void test_list_get(LinkedList_T list)
{
        LinkedList_T null_list = NULL;
        Test_T test2 = NULL;
        int *ptr;
        unsigned i;
        unsigned index = 0;
        unsigned last = LinkedList_length(list) - 1;

        fprintf(stderr, ">>>>>>>>>>>>>>>>>>>> Testing LinkedList_get\n");

        //Valid Cases
        fprintf(stderr, "Valid Cases --------\n");
        test2 = (Test_T) LinkedList_get(list, index);
        fprintf(stderr, "list[%u]->x: %u\n", index, test2->x);
        fprintf(stderr, "list[%u]->y: %d\n", index, test2->y);

        test2 = (Test_T) LinkedList_get(list, last);
        fprintf(stderr, "list[%u]->x: %u\n", last, test2->x);
        fprintf(stderr, "list[%u]->y: %d\n", last, test2->y);

        //Edge Cases
        (void) null_list, (void) ptr, (void) i;
        fprintf(stderr, "\nEdge Cases ---------\n");
        //ptr = (int *) LinkedList_get(list, -1); //expected assertion
        //ptr = (int *) LinkedList_get(list, last + 1); //expected assertion
        //ptr = (int *) LinkedList_get(list, last + 10); //expected assertion
        //ptr = (int *) LinkedList_get(null_list, 0); //expected assertion
        /* expected assertion
        for (i = 0; i < last + 20; i++) {
                ptr = (int *) LinkedList_get(list, i);
                fprintf(stderr, "got list[%u]\n", i);
        }
        */

        fprintf(stderr, ">>>>>>>>>> Tests Passed.\n\n");
}

void test_list_lo(LinkedList_T list)
{
        LinkedList_T null_list = NULL;
        Test_T null_test = NULL;
        Test_T out;
        Test_T test2 = malloc(sizeof(struct test));
        assert(test2 != NULL);
        test2->x = 4321;
        test2->y = -1234;

        fprintf(stderr, ">>>>>>>>>>>>>>>>>>>> Testing getlo and setlo\n");

        //Valid Cases
        fprintf(stderr, "Valid Cases --------\n");
        LinkedList_setlo(list, test2);
        out = LinkedList_getlo(list);
        fprintf(stderr, "lo x: %u\nlo y: %d\n", out->x, out->y);
        fprintf(stderr, "list length: %u\n", LinkedList_length(list));

        out = LinkedList_get(list, 1);
        fprintf(stderr, "next x: %u\nnext y: %d\n", out->x, out->y);

        //Edge Cases
        (void) null_list, (void) null_test;
        fprintf(stderr, "Edge Cases ---------\n");
        //LinkedList_setlo(null_list, test2); //expected assertion
        //LinkedList_setlo(list, null_test); //expected assertion
        //LinkedList_setlo(null_list, null_test); //expected assertion
        //out = LinkedList_getlo(null_list); //expected assertion

        //Empty list
        null_list = LinkedList_new(0);
        out = LinkedList_getlo(null_list);
        //assert(out != NULL); //expected assertion
        fprintf(stderr, "null_list length: %u\n", LinkedList_length(null_list));

        //LinkedList_setlo(null_list, null_test); //expected assertion
        LinkedList_setlo(null_list, test2); //should work
        out = LinkedList_getlo(null_list); //should work
        fprintf(stderr, "first elem in null_list: %u\n", out->x);
        fprintf(stderr, "null_list length: %u\n", LinkedList_length(null_list));

        fprintf(stderr, ">>>>>>>>>> Tests Passed.\n\n");
        free(test2);
        LinkedList_free(&null_list);
}

void test_list_hi(LinkedList_T list)
{
        LinkedList_T null_list = NULL;
        Test_T null_test = NULL;
        Test_T out;
        Test_T test2 = malloc(sizeof(struct test));
        assert(test2 != NULL);
        test2->x = 42;
        test2->y = -42;

        fprintf(stderr, ">>>>>>>>>>>>>>>>>>>> Testing gethi and sethi\n");

        //Valid Cases
        fprintf(stderr, "Valid Cases --------\n");
        out = LinkedList_gethi(list);
        fprintf(stderr, "hi1 x: %u\nhi1 y: %d\n", out->x, out->y);
        fprintf(stderr, "list length: %u\n", LinkedList_length(list));
        LinkedList_sethi(list, test2);
        out = LinkedList_gethi(list);
        fprintf(stderr, "hi2 x: %u\nhi2 y: %d\n", out->x, out->y);
        fprintf(stderr, "list length: %u\n", LinkedList_length(list));


        //Edge Cases
        (void) null_list, (void) null_test;
        fprintf(stderr, "Edge Cases ---------\n");
        //LinkedList_sethi(null_list, test2); //expected assertion
        //LinkedList_sethi(list, null_test); //expected assertion
        //LinkedList_sethi(null_list, null_test); //expected assertion
        //out = LinkedList_gethi(null_list); //expected assertion

        //Empty list
        null_list = LinkedList_new(0);
        out = LinkedList_gethi(null_list);
        //assert(out != NULL); //expected assertion
        fprintf(stderr, "null_list length: %u\n", LinkedList_length(null_list));

        //LinkedList_setlo(null_list, null_test); //expected assertion
        LinkedList_sethi(null_list, test2); //should work
        out = LinkedList_gethi(null_list); //should work
        fprintf(stderr, "first elem in null_list: %u\n", out->x);
        fprintf(stderr, "null_list length: %u\n", LinkedList_length(null_list));

        fprintf(stderr, ">>>>>>>>>> Tests Passed.\n\n");
        free(test2);
        LinkedList_free(&null_list);
}

void test_list_remove(LinkedList_T list)
{
        LinkedList_T null_list = NULL;
        Test_T out;
        Test_T test2 = malloc(sizeof(struct test));
        assert(test2 != NULL);
        test2->x = 1212121;
        test2->y = -2121212;

        fprintf(stderr, ">>>>>>>>>>>>>>>>>>>> Testing LinkedList_remove\n");

        //Valid Cases
        fprintf(stderr, "Valid Cases --------\n");
        LinkedList_setlo(list, test2);
        out = LinkedList_getlo(list);
        fprintf(stderr, "length1: %u\n", LinkedList_length(list));
        fprintf(stderr, "lo1->x: %u\nlo1->y: %d\n", out->x, out->y);

        free(test2);
        test2 = NULL;
        LinkedList_remove(list, 0);
        out = LinkedList_getlo(list);
        fprintf(stderr, "lo2->x: %u\nlo2->y: %d\n", out->x, out->y);
        fprintf(stderr, "length2: %u\n", LinkedList_length(list));

        fprintf(stderr, "removing all\n");
        free(out);
        while (LinkedList_length(list) != 0)
                LinkedList_remove(list, 0);
        fprintf(stderr, "length3: %u\n", LinkedList_length(list));

        //Edge Cases
        (void) null_list;
        fprintf(stderr, "Edge Cases ---------\n");
        //LinkedList_remove(null_list, 0); //expected assertion

        //Empty LinkedList
        //LinkedList_remove(list, 0); //expected assertion
        //LinkedList_remove(list, -1); //expected assertion

        fprintf(stderr, ">>>>>>>>>> Tests Passed.\n\n");
        //free(test2);
}

void test_list_pops(LinkedList_T list)
{
        LinkedList_T null_list = NULL;
        Test_T out;
        Test_T test2 = malloc(sizeof(struct test));
        assert(test2 != NULL);
        test2->x = 56789;
        test2->y = -876;

        fprintf(stderr, ">>>>>>>>>>>>>>>>>>>> Testing removhi & removlo\n");

        //Valid Cases
        fprintf(stderr, "Valid Cases --------\n");
        LinkedList_setlo(list, test2);
        out = LinkedList_getlo(list);
        fprintf(stderr, "length1: %u\n", LinkedList_length(list));
        fprintf(stderr, "lo1->x: %u\nlo1->y: %d\n", out->x, out->y);

        LinkedList_removelo(list);
        out = LinkedList_getlo(list);
        fprintf(stderr, "lo2->x: %u\nlo2->y: %d\n", out->x, out->y);
        fprintf(stderr, "length2: %u\n", LinkedList_length(list));

        LinkedList_sethi(list, test2);
        out = LinkedList_gethi(list);
        fprintf(stderr, "length3: %u\n", LinkedList_length(list));
        fprintf(stderr, "lo3->x: %u\nlo3->y: %d\n", out->x, out->y);

        LinkedList_removehi(list);
        out = LinkedList_gethi(list);
        fprintf(stderr, "lo4->x: %u\nlo4->y: %d\n", out->x, out->y);
        fprintf(stderr, "length4: %u\n", LinkedList_length(list));

        fprintf(stderr, "removing all\n");
        while (LinkedList_length(list) != 0) {
                //LinkedList_removehi(list);
                LinkedList_removelo(list);
        }
        fprintf(stderr, "length3: %u\n", LinkedList_length(list));

        //Edge Cases
        (void) null_list;
        fprintf(stderr, "Edge Cases ---------\n");
        //LinkedList_removelo(null_list); //expected assertion
        //LinkedList_removehi(null_list); //expected assertion

        //Empty LinkedList
        //LinkedList_removelo(list); //expected assertion
        //LinkedList_removehi(list); //expected assertion

        fprintf(stderr, ">>>>>>>>>> Tests Passed.\n\n");
        free(test2);
}
