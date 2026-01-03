#include <stdio.h>
extern void bad_function(void);
int main(void) {
    bad_function();
    return 0;
}
