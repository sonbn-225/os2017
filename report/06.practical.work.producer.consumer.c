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

void produce(item *i) {
  while ((first + 1) % BUFFER_SIZE == last) {
    // do nothing -- no free buffer item
  }
  memcpy(&buffer[first], i, sizeof(item));
  first = (first + 1) % BUFFER_SIZE;
}

item *consume() {
  item *i = malloc(sizeof(item));
  while (first == last) {
    // do nothing -- nothing to consume
  }
  memcpy(i, &buffer[last], sizeof(item));
  last = (last + 1) % BUFFER_SIZE;
  return i;
}

int main() {
  item i;
  i.type = '0';
  i.amount = 1000;
  i.unit = '1';

  printf("Type: %c \nAmount: %d \nUnit: %c \n", i.type, i.amount, i.unit);

  produce(&i);
  printf("After produce: First: %d Last %d \n", first, last);

  item *j = consume();
  printf("After consume: First: %d Last %d \n", first, last);
  return 0;
}
