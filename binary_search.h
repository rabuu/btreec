#ifndef BINARY_SEARCH_H_
#define BINARY_SEARCH_H_

#include "types.h"

/*
* Find the index of a key or where a key should go using binary search.
*
* `start` has to be less than or equal to `end`
*/
size_t search_key_index(BTreeKey *keys, BTreeKey k, size_t start, size_t end);

#endif // BINARY_SEARCH_H_
