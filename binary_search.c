#include <assert.h>

#include "binary_search.h"

size_t search_key_index(BTreeKey *keys, BTreeKey k, size_t start, size_t end) {
	assert(start <= end);

	if (k == 0) return 0;

	if (start == end) {
		return (k <= keys[start]) ? start : start + 1;
	}

	const size_t mid = (start + end) / 2;

	if (k == keys[mid]) return mid;
	if (k > keys[mid] && k < keys[mid + 1]) return mid + 1;

	if (k < keys[mid]) {
		return search_key_index(keys, k, start, mid - 1);
	} else {
		return search_key_index(keys, k, mid + 1, end);
	}
}
