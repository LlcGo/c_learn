#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
    size_t i = 0;
    while((*s) != '\0')
    {
	    i++;
	    s++;
    }
    return i;
}

char *strcpy(char *dst, const char *src) {
  panic("Not implemented");
}

char *strncpy(char *dst, const char *src, size_t n) {
  panic("Not implemented");
}

char *strcat(char *dst, const char *src) {
  panic("Not implemented");
}

int strcmp(const char *s1, const char *s2) {
     size_t s1len = strlen(s1);
     size_t s2len = strlen(s2);
     const char *s1p = s1;
     const char *s2p = s2;
     if(s1len != s2len) return 1;
     while((*s1p) != '\0')
     {
	  if((*s1p)!=(*s2p))
	  {
		  return 1;
	  }	  
	  s1p++;
	  s2p++;
     }
     return 0;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  panic("Not implemented");
}

void *memset(void *s, int c, size_t n) {
  panic("Not implemented");
}

void *memmove(void *dst, const void *src, size_t n) {
  panic("Not implemented");
}

void *memcpy(void *out, const void *in, size_t n) {
  panic("Not implemented");
}

int memcmp(const void *s1, const void *s2, size_t n) {
  panic("Not implemented");
}

#endif
