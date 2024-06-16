#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>
#include <assert.h>
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
            *dt = (*srct);
	    dt++;
            srct++;	    
	}
	*dt = '\0';
	return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
  panic("Not implemented");
}

char *strcat(char *dst, const char *src) {
	const char *srct = src;
        char* p = dst;			//将目的数组赋给p
	while (*p != '\0'){		//循环看大小
		p++;
	}
	while (*srct != '\0'){			//注意指针的用法
		*p = *srct;
		p++;			//依次加加进行连接
		srct++;
	}
	*p = '\0';
	return dst;
}

int strcmp(const char *s1, const char *s2) {
    // size_t s1len = strlen(s1);
    // size_t s2len = strlen(s2);
     const char *s1p = s1;
     const char *s2p = s2;
    // if(s1len != s2len) return 1;
     while((*s1p) != '\0')
     {
	  if((*s1p)!=(*s2p))
	  {
		  return -1;
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
        char *st = s;  
	while(n != 0)
	{
		n--;
		*st++ = c;
	}	
	return  s;
}

void *memmove(void *dst, const void *src, size_t n) {
  panic("Not implemented");
}

void *memcpy(void *out, const void *in, size_t n) {
  panic("Not implemented");
}

int memcmp(const void *s1, const void *s2, size_t n) {
         const unsigned char *su1, *su2;
	int res = 0;
	for (su1 = s1, su2 = s2; 0 < n; su1++, su2++, n--)
		if ((res = *su1 - *su2) != 0)
			break;
	return res;
}

#endif
