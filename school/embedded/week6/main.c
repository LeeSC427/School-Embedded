
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main(void)
{
  int errors=0;
  
  printf("Testing examples for endian \n");

  TEST_READINT(readint_little,0);
  TEST_READINT(readint_big,1);
  

  if (errors)
  {
    printf("Test finished with %d errors.\n", errors);
    return 1;
  }
  else
  {
    printf("Test passed.\n");
  }
  return 0;
}


int test_readint(
  char *name,           /* function name */
  fn_readint *fn,       /* function to test */
  int big               /* endianness */
)
{
  int errors=0;
  int ref, val;
  
  char data[]={1,2,3,4};
  
  printf("Testing function: %s\n", name);
  if (big)
  {
  
    //big endian
    ref = 0x01020304;
  }
  else
  {
  
    //little endian
    ref = 0x04030201;
  }
  val = (*fn)(data);
  
  if (ref!=val)
  {
    errors++;
    printf("Mismatch: %08x %08x\n", ref, val);
  }else
  {
  printf("Matched: %08x %08x\n", ref, val);
  }

  return errors;
}

