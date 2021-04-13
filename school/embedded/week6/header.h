typedef int fn_readint(char *data);

int readint_little(char *data);
int readint_big(char *data);



/* Test read ints */
int test_readint(
  char *name,           /* function name */
  fn_readint *fn,       /* function to test */
  int big               /* endianness */
);

#define TEST_READINT(name, big) errors += test_readint(#name, (fn_readint*)&name, big);
