#include "vector.h"

/*-------------------------------------
 * Function Prototypes
 -------------------------------------*/


/*-------------------------------------
 * Main
 -------------------------------------*/
int main() {
        Vector_T vec;

        vec = Vector_new(100);
        assert(vec != NULL);

        //Unit Tests


        //Cleanup
        Vector_free(&vec);
}

/*-------------------------------------
 * Function Definitions
 -------------------------------------*/
