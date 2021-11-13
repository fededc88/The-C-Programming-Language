/*
 * Exercise 1-2. Experiment to find out what happens when printf's argument
 * string contains \c, where c is some character not listed above. 
 *
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of submission
 * are welcome. 
 */

#include <stdio.h>

void main(void) {
    printf("\v \p \x hello, world\n");
}

//
// End of file.
//
