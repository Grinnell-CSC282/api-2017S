/**
 * test-ali.c
 *    Tests for the ali library.
 *
 * <insert appropriate open source license>
 */

// +---------+-------------------------------------------------------
// | Headers |
// +---------+

#include <assert.h>
#include <string.h>
#include "alilib.h"

// +------+----------------------------------------------------------
// | Main |
// +------+

int
main ()
{
	// Initialize library
	ali_init();

	// Initialize sample values
	ALInt * int_2034 = int2ali (2034);
	ALInt * int_1234567 = int2ali (-1234567);
	ALInt * int_5 = int2ali (5);
	ALInt * int_12 = int2ali (-12);

	// int2ali
	assert (int_2034->ndigits == 4);
	assert (int_2034->sign == 1);
	assert (int_1234567->ndigits == 7);
	assert (int_1234567->sign == -1);
	assert (int_5->ndigits == 1);
	assert (int_5->sign == 1);
	assert (int_12->ndigits == 2);
	assert (int_12->sign == -1);

	// ali2long
	//assert (ali2long (int_2034) == (long) 2034);
	//assert (ali2long (int_1234567) == (long) 1234567);
	//assert (ali2long (int_5) == (long) 5);
	//assert (ali2long (int_12) == (long) 12);

	// ali2str
	assert (ali2int (int_2034) == 2034);
	assert (ali2int (int_1234567) == -1234567);
	assert (ali2int (int_5) == 5);
	assert (ali2int (int_12) == -12);

	// ali_add
	ALInt * int_7 = ali_add(int_5, int_12);
	ALInt * int_2039 = ali_add(int_2034, int_5);
	ALInt * int_1234589 = ali_add(int_1234567, int_12);

	assert (ali2int (int_7) == 7);
	assert (ali2int (int_2039) == 2039);
	assert (ali2int (int_1234589) == -12345689);

	
	// ali_subtract
	ALInt * int_17 = ali_subtract(int_5, int_12);
	ALInt * int_2046 = ali_subtract(int_12, int_2034);
	ALInt * int_2029 = ali_subtract(int_2034, int_5);

	assert (ali2int (int_17) == 17);
	assert (ali2int (int_2046) == -2046);
	assert (ali2int (int_2029) == 2029);

	// ali_multiply
	

	// ali_quotient
	
	// ali_remainder
	
	// ali_free
	ali_free (int_2034);
	ali_free (int_1234567);
	ali_free (int_5);
	ali_free (int_12);

	// Cleanup
	ali_cleanup();
	
	// Done with tests, return
	return 0;
} // main