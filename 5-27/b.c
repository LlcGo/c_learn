void printfptr(void *p)
{
    printf("p=%p; *p = %016lx\n", p, *(long*)p);
}

int x;

int main(int argc,char *argv[])
{
  printfptr(main);
  printfptr(&main);
  printfptr(&x);
  printfptr(&argc);
  printfptr(argv);
  printfptr(&argv);
  printfptr(argv[0]);
}
