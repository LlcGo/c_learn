#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
    size_t i = 0;
    const char * sp = s;
    while((*sp) != '\0')
    {
	    i++;
	    sp++;
    }
    return i;
}

char *strcpy(char *dst, const char *src) {
	char * dt = dst;
	const char *srct = src;
	while((*srct) != '\0')
	{
            *dst = (*srct);
	    dst++;
            srct++;	    
	}
	return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
  panic("Not implemented");
}

char *strcat(char *dst, const char *src) {
	char *dstt = dst;
	const char *srct = src;
	while((*dstt) != '\0')
	{
		dstt++;
	}
	while((*srct) != '\0')
	{
		*dstt = (*srct);
	        dstt++;
	        srct++;   	
	}
	return dst;
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
        char *st = (char*)s;  
	while(n != 0)
	{
		n--;
		st++ = (char)c;
	}	
	return (void*)s;
}

void *memmove(void *dst, const void *src, size_t n) {
  panic("Not implemented");
}

void *memcpy(void *out, const void *in, size_t n) {
  panic("Not implemented");
}

int memcmp(const void *s1, const void *s2, size_t n) {
        const void *s1t = s1;
	const void *s2t = s2;
	while(n != 0)
	{
           if((*s1t) != (*s2t))
	   {
		   return 1;
	   }
	   s1t++;
	   s2t++;
	}
	return 0;
}

#endif
