#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 10

typedef struct {
  char type; // 0=fried chicken, 1=French fries
  int amount; // pieces or weight
  char unit; // 0=piece, 1=gram
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void *produce(item *i) {
  while ((first + 1) % BUFFER_SIZE == last) {
    // do nothing -- no free buffer item
  }
  memcpy(&buffer[first], i, sizeof(item));
  first = (first + 1) % BUFFER_SIZE;
}

void *consume() {
  item *i = malloc(sizeof(item));
  while (first == last) {
    // do nothing -- nothing to consume
  }
  memcpy(i, &buffer[last], sizeof(item));
  last = (last + 1) % BUFFER_SIZE;
  //return i;
}

int pthread_create(
  pthread_t *thread,
  const pthread_attr_t *attr,
  void *(*start_routine) (void *),
  void *arg
);

int main() {
  item i1;
  i1.type = '0';
  i1.amount = 1000;
  i1.unit = '1';

  // i2.type = '1';
  // i2.amount = 2;
  // i2.unit = '0';
  //
  // i3.type = '0';
  // i3.amount = 500;
  // i3.unit = '1';
  printf("Type: %c Amount: %d Unit: %c \n", i1.type, i1.amount, i1.unit);
  // printf("Type: %c Amount: %d Unit: %c \n", i2.type, i2.amount, i2.unit);
  // printf("Type: %c Amount: %d Unit: %c \n", i3.type, i3.amount, i3.unit);

  //create a background thread
  pthread_t tid1, tid2;
  pthread_create(
    &tid1,
    NULL,
    produce(&i1),
    NULL
  );
  pthread_create(
    &tid1,
    NULL,
    produce(&i1),
    NULL
  );
  pthread_create(
    &tid1,
    NULL,
    produce(&i1),
    NULL
  );


  pthread_create(
    &tid2,
    NULL,
    &consume,
    NULL
  );
  printf("After produce: First: %d Last %d \n", first, last);

  // item *j = consume();
  // item *k = consume();
  consume();
  consume();
  printf("After consume: First: %d Last %d \n", first, last);

  //pthread_join(tid, NULL);
  return 0;
}
