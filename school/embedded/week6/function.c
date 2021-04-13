#include "header.h"


int readint_little(char *data)
{
  int a0,a1,a2,a3;
  int ret;

  a0 = *(data++);
  a1 = *(data++);
  a2 = *(data++);
  a3 = *(data++);
  
  ret = (a0|(a1<<8)|(a2<<16)|(a3<<24));
   
  return ret;
}

int readint_big(char *data)
{
  int a0,a1,a2,a3;
  int ret;

  a0 = *(data++);
  a1 = *(data++);
  a2 = *(data++);
  a3 = *(data++);
  
  ret = (a3|(a2<<8)|(a1<<16)|(a0<<24));
  
  return ret;
}
