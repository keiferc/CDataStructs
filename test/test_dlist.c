#include "dlinkedlist.h"

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
void test_list_length(DLinkedList_T list);
void test_list_set(DLinkedList_T list, Test_T test1);
void test_list_get(DLinkedList_T list);
void test_list_lo(DLinkedList_T list);
void test_list_hi(DLinkedList_T list);
void test_list_remove(DLinkedList_T list);
void test_list_pops(DLinkedList_T list);

/*-------------------------------------
 * Main
 -------------------------------------*/
int main(int argc, char *argv[]) {
	DLinkedList_T list;
	Test_T test1 = NULL;

	(void) argc, (void) argv;

	list = DLinkedList_new(7);
	assert(list != NULL);

	test1 = malloc(sizeof(struct test));
	assert(test1 != NULL);
	test1->x = 10;
	test1->y = -5;

	fprintf(stderr, "\n"); //formatting

	//Unit Tests
	test_list_length(list);
	test_list_set(list, test1);
	//test_list_get(list);
	//test_list_lo(list);
	//test_list_hi(list);
	//test_list_remove(list);
	//test_list_pops(list);

	//Cleanup
	free(test1);
	DLinkedList_free(&list);
}

/*-------------------------------------
 * Function Definitions
 -------------------------------------*/
void test_list_length(DLinkedList_T list)
{
	DLinkedList_T null_list = NULL;
	unsigned length;

	fprintf(stderr, ">>>>>>>>>>>>>>>>>>>> Testing DLinkedList_length\n");

	//Valid Cases
	fprintf(stderr, "Valid Cases --------\n");
	length = DLinkedList_length(list);
	fprintf(stderr, "Length of list: %u\n", length);

	//Edge Cases
	(void) null_list;
	fprintf(stderr, "Edge Cases ---------\n");
	//length = DLinkedList_length(null_list); //expected assertion

	fprintf(stderr, ">>>>>>>>>> Tests Passed.\n\n");
}

void test_list_set(DLinkedList_T list, Test_T test1)
{
	DLinkedList_T null_list = NULL;
	unsigned index = 0;
	unsigned i;
	int n = 1234;
	int *n_ptr = &n;

	fprintf(stderr, ">>>>>>>>>>>>>>>>>>>> Testing DLinkedList_set\n");

	//Valid Cases
	fprintf(stderr, "Valid Cases --------\n");
	DLinkedList_set(list, n_ptr, index);

	DLinkedList_set(list, test1, index);

	fprintf(stderr, "old length: %u\n", DLinkedList_length(list));
	DLinkedList_set(list, test1, DLinkedList_length(list));
	fprintf(stderr, "new length: %u\n", DLinkedList_length(list));

	// for (i = 0; i < 10; i++) {
	// 	DLinkedList_set(list, test1, i);
	// }
	(void) i;

	//Edge Cases
	(void) null_list;
	fprintf(stderr, "Edge Cases ---------\n");
	//DLinkedList_set(list, n_ptr, 1000); //expected assertion
	//DLinkedList_set(list, NULL, 0); // expected assertion
	//DLinkedList_set(null_list, test1, 1); // expected assertion
	//DLinkedList_set(list, test1, -1); //expected assertion

	fprintf(stderr, ">>>>>>>>>> Tests Passed.\n\n");
}

void test_list_get(DLinkedList_T list)
{
	DLinkedList_T null_list = NULL;
	Test_T test2 = NULL;
	int *ptr;
	unsigned i;
	unsigned index = 0;
	unsigned last = DLinkedList_length(list) - 1;

	fprintf(stderr, ">>>>>>>>>>>>>>>>>>>> Testing DLinkedList_get\n");

	//Valid Cases
	fprintf(stderr, "Valid Cases --------\n");
	test2 = (Test_T) DLinkedList_get(list, index);
	if (test2 == NULL)
		fprintf(stderr, "SUCCESS!!!!!!!\n");

	fprintf(stderr, "list[%u]->x: %u\n", index, test2->x);
	fprintf(stderr, "list[%u]->y: %d\n", index, test2->y);

	test2 = (Test_T) DLinkedList_get(list, last);
	fprintf(stderr, "list[%u]->x: %u\n", last, test2->x);
	fprintf(stderr, "list[%u]->y: %d\n", last, test2->y);

	//Edge Cases
	(void) null_list, (void) ptr, (void) i;
	fprintf(stderr, "\nEdge Cases ---------\n");
	//ptr = (int *) DLinkedList_get(list, -1); //expected assertion
	//ptr = (int *) DLinkedList_get(list, last + 1); //expected assertion
	//ptr = (int *) DLinkedList_get(list, last + 10); //expected assertion
	//ptr = (int *) DLinkedList_get(null_list, 0); //expected assertion
	/* expected assertion
	for (i = 0; i < last + 20; i++) {
		ptr = (int *) DLinkedList_get(list, i);
		fprintf(stderr, "got list[%u]\n", i);
	}
	*/

	fprintf(stderr, ">>>>>>>>>> Tests Passed.\n\n");
}

void test_list_lo(DLinkedList_T list)
{
	DLinkedList_T null_list = NULL;
	Test_T null_test = NULL;
	Test_T out;
	Test_T test2 = malloc(sizeof(struct test));
	assert(test2 != NULL);
	test2->x = 4321;
	test2->y = -1234;

	fprintf(stderr, ">>>>>>>>>>>>>>>>>>>> Testing getlo and setlo\n");

	//Valid Cases
	fprintf(stderr, "Valid Cases --------\n");
	DLinkedList_setlo(list, test2);
	out = DLinkedList_getlo(list);
	fprintf(stderr, "lo x: %u\nlo y: %d\n", out->x, out->y);
	fprintf(stderr, "list length: %u\n", DLinkedList_length(list));

	out = DLinkedList_get(list, 1);
	fprintf(stderr, "next x: %u\nnext y: %d\n", out->x, out->y);

	//Edge Cases
	(void) null_list, (void) null_test;
	fprintf(stderr, "Edge Cases ---------\n");
	//DLinkedList_setlo(null_list, test2); //expected assertion
	//DLinkedList_setlo(list, null_test); //expected assertion
	//DLinkedList_setlo(null_list, null_test); //expected assertion
	//out = DLinkedList_getlo(null_list); //expected assertion

	//Empty list
	null_list = DLinkedList_new(0);
	out = DLinkedList_getlo(null_list);
	//assert(out != NULL); //expected assertion
	fprintf(stderr, "null_list length: %u\n", DLinkedList_length(null_list));

	//DLinkedList_setlo(null_list, null_test); //expected assertion
	DLinkedList_setlo(null_list, test2); //should work
	out = DLinkedList_getlo(null_list); //should work
	fprintf(stderr, "first elem in null_list: %u\n", out->x);
	fprintf(stderr, "null_list length: %u\n", DLinkedList_length(null_list));

	fprintf(stderr, ">>>>>>>>>> Tests Passed.\n\n");
	free(test2);
	DLinkedList_free(&null_list);
}

void test_list_hi(DLinkedList_T list)
{
	DLinkedList_T null_list = NULL;
	Test_T null_test = NULL;
	Test_T out;
	Test_T test2 = malloc(sizeof(struct test));
	assert(test2 != NULL);
	test2->x = 42;
	test2->y = -42;

	fprintf(stderr, ">>>>>>>>>>>>>>>>>>>> Testing gethi and sethi\n");

	//Valid Cases
	fprintf(stderr, "Valid Cases --------\n");
	out = DLinkedList_gethi(list);
	fprintf(stderr, "hi1 x: %u\nhi1 y: %d\n", out->x, out->y);
	fprintf(stderr, "list length: %u\n", DLinkedList_length(list));
	DLinkedList_sethi(list, test2);
	out = DLinkedList_gethi(list);
	fprintf(stderr, "hi2 x: %u\nhi2 y: %d\n", out->x, out->y);
	fprintf(stderr, "list length: %u\n", DLinkedList_length(list));


	//Edge Cases
	(void) null_list, (void) null_test;
	fprintf(stderr, "Edge Cases ---------\n");
	//DLinkedList_sethi(null_list, test2); //expected assertion
	//DLinkedList_sethi(list, null_test); //expected assertion
	//DLinkedList_sethi(null_list, null_test); //expected assertion
	//out = DLinkedList_gethi(null_list); //expected assertion

	//Empty list
	null_list = DLinkedList_new(0);
	out = DLinkedList_gethi(null_list);
	//assert(out != NULL); //expected assertion
	fprintf(stderr, "null_list length: %u\n", DLinkedList_length(null_list));

	//DLinkedList_setlo(null_list, null_test); //expected assertion
	DLinkedList_sethi(null_list, test2); //should work
	out = DLinkedList_gethi(null_list); //should work
	fprintf(stderr, "first elem in null_list: %u\n", out->x);
	fprintf(stderr, "null_list length: %u\n", DLinkedList_length(null_list));

	fprintf(stderr, ">>>>>>>>>> Tests Passed.\n\n");
	free(test2);
	DLinkedList_free(&null_list);
}

void test_list_remove(DLinkedList_T list)
{
	DLinkedList_T null_list = NULL;
	Test_T out;
	Test_T test2 = malloc(sizeof(struct test));
	assert(test2 != NULL);
	test2->x = 1212121;
	test2->y = -2121212;

	fprintf(stderr, ">>>>>>>>>>>>>>>>>>>> Testing DLinkedList_remove\n");

	//Valid Cases
	fprintf(stderr, "Valid Cases --------\n");
	DLinkedList_setlo(list, test2);
	out = DLinkedList_getlo(list);
	fprintf(stderr, "length1: %u\n", DLinkedList_length(list));
	fprintf(stderr, "lo1->x: %u\nlo1->y: %d\n", out->x, out->y);

	free(test2);
	test2 = NULL;
	DLinkedList_remove(list, 0);
	out = DLinkedList_getlo(list);
	fprintf(stderr, "lo2->x: %u\nlo2->y: %d\n", out->x, out->y);
	fprintf(stderr, "length2: %u\n", DLinkedList_length(list));

	fprintf(stderr, "removing all\n");
	free(out);
	while (DLinkedList_length(list) != 0)
		DLinkedList_remove(list, 0);
	fprintf(stderr, "length3: %u\n", DLinkedList_length(list));

	//Edge Cases
	(void) null_list;
	fprintf(stderr, "Edge Cases ---------\n");
	//DLinkedList_remove(null_list, 0); //expected assertion

	//Empty DLinkedList
	//DLinkedList_remove(list, 0); //expected assertion
	//DLinkedList_remove(list, -1); //expected assertion

	fprintf(stderr, ">>>>>>>>>> Tests Passed.\n\n");
	//free(test2);
}

void test_list_pops(DLinkedList_T list)
{
	DLinkedList_T null_list = NULL;
	Test_T out;
	Test_T test2 = malloc(sizeof(struct test));
	assert(test2 != NULL);
	test2->x = 56789;
	test2->y = -876;

	fprintf(stderr, ">>>>>>>>>>>>>>>>>>>> Testing removhi & removlo\n");

	//Valid Cases
	fprintf(stderr, "Valid Cases --------\n");
	DLinkedList_setlo(list, test2);
	out = DLinkedList_getlo(list);
	fprintf(stderr, "length1: %u\n", DLinkedList_length(list));
	fprintf(stderr, "lo1->x: %u\nlo1->y: %d\n", out->x, out->y);

	DLinkedList_removelo(list);
	out = DLinkedList_getlo(list);
	fprintf(stderr, "lo2->x: %u\nlo2->y: %d\n", out->x, out->y);
	fprintf(stderr, "length2: %u\n", DLinkedList_length(list));

	DLinkedList_sethi(list, test2);
	out = DLinkedList_gethi(list);
	fprintf(stderr, "length3: %u\n", DLinkedList_length(list));
	fprintf(stderr, "lo3->x: %u\nlo3->y: %d\n", out->x, out->y);

	DLinkedList_removehi(list);
	out = DLinkedList_gethi(list);
	fprintf(stderr, "lo4->x: %u\nlo4->y: %d\n", out->x, out->y);
	fprintf(stderr, "length4: %u\n", DLinkedList_length(list));

	fprintf(stderr, "removing all\n");
	while (DLinkedList_length(list) != 0) {
		//DLinkedList_removehi(list);
		DLinkedList_removelo(list);
	}
	fprintf(stderr, "length3: %u\n", DLinkedList_length(list));

	//Edge Cases
	(void) null_list;
	fprintf(stderr, "Edge Cases ---------\n");
	//DLinkedList_removelo(null_list); //expected assertion
	//DLinkedList_removehi(null_list); //expected assertion

	//Empty DLinkedList
	//DLinkedList_removelo(list); //expected assertion
	//DLinkedList_removehi(list); //expected assertion

	fprintf(stderr, ">>>>>>>>>> Tests Passed.\n\n");
	free(test2);
}
