#include <stdlib.h>
#include <math.h>
#include "ali_conv.h" 

#define MIN(a,b) ((a < b) ? a : b)

alint*
int2alint (int var)
{
  alint* ret = alint_init(sizeof(var));
  ret->sign = (var < 0) ? 1 : 0;
  var = abs(var);
  data_t *point = (data_t *)&var;
  for (int i = 0; i < (sizeof(int) / sizeof(data_t)); i++)
      ret->data[i] = point[i];
  ret->size = sizeof(var);
  return ret;
}

alint*
long2alint (long var)
{
  alint* ret = alint_init(sizeof(var));
  ret->sign = (var < 0) ? 1 : 0;
  var = labs(var);
  /* Sections like these could probably be replaced with memcpy */
  data_t *point = (data_t *)&var;
  for (int i = 0; i < (sizeof(long) / sizeof(data_t)); i++)
      ret->data[i] = point[i];
  ret->size = sizeof(var);
  return ret;
}

/* Convert an arbitrarily large integer to a regular int. Undefined
 when the value contained in integer is outside the bounds of int
*/
int
ali2int (alint *integer)
{
  int ret = 0;
  data_t *point = (data_t *)&ret;
  for (int i = 0; i < MIN(integer->size, sizeof(ret)); i++)
    point[i] = integer->data[i];
  ret = integer->sign ? -ret : ret;
  return ret;
}

long
ali2long (alint *integer)
{
  long ret = 0;
  data_t *point = (data_t *)&ret;
  for (int i = 0; i < MIN(integer->size, sizeof(ret)); i++)
    point[i] = integer->data[i];
  ret = integer->sign ? -ret : ret;
  return ret;
}
