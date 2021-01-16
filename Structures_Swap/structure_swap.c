#include <stdlib.h>
#include <stdio.h>
/*==============================================================================*/
double rand_double( double a, double b) {

  double random_num;
  if ( b > a ) {
   /* assuming b > a  for the formula to work*/
  random_num = ((double) rand() / (double) RAND_MAX) * ((b - a ) + a);
  } else {

    double original_a = a;
     a = b;
     b = original_a;
    random_num = ((double) rand() / (double) RAND_MAX) * ((b - a ) + a);
 }

  return random_num;
}

/*==============================================================================*/
struct foobarbaz {

  int foo;
  double bar;
  int baz;

};
/*==============================================================================*/
struct foobarbaz *rand_foobarbaz( ) {
  struct foobarbaz *numbers = malloc (sizeof(struct foobarbaz));
  numbers -> foo = rand()%50;
  numbers -> bar = rand()%101;
  numbers -> baz = rand()%100;
  /* allocates memory for foobarbaz and initialize variables in struct */
  return numbers;
}
/*==============================================================================*/
#define MIN 0
#define MAX 20
struct foobarbaz **many_foobarbaz ( ) {

  int i;
  struct foobarbaz  **store_array = malloc( sizeof(struct foobarbaz)  * 20);
  for (i = MIN; i <  MAX; i++) {
    store_array[i] = rand_foobarbaz();
  } /*allocates 20 struct foobarbaz */

   return store_array;
}
/*==============================================================================*/
void print_foobarbaz (struct  foobarbaz **store_array) {

    int i;

    for (i = MIN; i < MAX; i++) {
        printf ("%02d\t%02lf\t%02d\n", store_array[i] -> foo, store_array[i] -> bar, store_array[i] -> baz);
    }

    putchar('\n');
}
/*==============================================================================*/
/* swap the two functions being pointed at */
void swap_structure ( struct foobarbaz **store_array, int a, int b) {

  int foo_A = store_array[a]-> foo;
  double bar_A = store_array[a]-> bar;
  int baz_A = store_array[a]-> baz;

  store_array[a] -> foo = store_array[b]-> foo;
  store_array[a] -> bar = store_array[b]-> bar;
  store_array[a] -> baz = store_array[b]-> baz;

  store_array[b] -> foo = foo_A;
  store_array[b] -> bar = foo_A;
  store_array[b] -> baz = foo_A;

}
/*==============================================================================*/
void free_foobarbaz (struct foobarbaz **store_array){

  int i;

  for (i = MIN; i < MAX; i++) {
    free(store_array[i]);
  }
  
  free(store_array);
}

/*==============================================================================*/

int main () {

  double a = MIN;
  double b = MAX;
  struct foobarbaz **store_array;

  store_array = many_foobarbaz();  /* stores the array of struct foobarbaz*/
  print_foobarbaz(store_array);

  int x = rand_double(a,b);
  int y = rand_double(a,b);
  printf("%d\n\n%d\n\n", x, y);

  swap_structure(store_array, x-1, y-1);
  print_foobarbaz(store_array);

  free_foobarbaz(store_array);


  return (0);

}/* end of program */
