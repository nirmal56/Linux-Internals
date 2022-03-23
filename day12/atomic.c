#include "atomic.h"
#include <stdio.h>

int main(){

	atomic_t v;                   /* define v */
	atomic_t u = ATOMIC_INIT(0);  /* define u and initialize it to zero */

	atomic_set(&v, 4);     /* v = 4 (atomically) */
	printf("%d\n", atomic_read(&v));

	atomic_add(2, &v);     /* v = v + 2 = 6 (atomically) */
	printf("%d\n", atomic_read(&v));

	atomic_inc(&v);        /* v = v + 1 = 7 (atomically) */
	printf("%d\n", atomic_read(&v));

	atomic_sub(1, &v);     /* v = v + 2 = 6 (atomically) */
	printf("%d\n", atomic_read(&v));

	atomic_dec(&v);        /* v = v + 1 = 7 (atomically) */
	printf("%d\n", atomic_read(&v));
	
	return 0;
}