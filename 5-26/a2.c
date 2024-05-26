extern int printf(const char *__restrict __format, ...);

int main()
{
  #ifdef __x86_64
    printf("__x86_64__\n");
  #else 
    printf("x86\n");
  #endif

  #if aa==bb
     printf("YES\n");
  #else
     printf("No\n");
  #endif
}
