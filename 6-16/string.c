#include <stdio.h>
#include <stdbool.h>
int istrlen(const char *s) {
    int i = 0;
    const char * sp = s;
    while((*sp) != '\0')
    {
	    i++;
	    sp++;
    }
    return i;
}

char *istrcpy(char *dst, const char *src) {
	char * dt = dst;
	const char *srct = src;
	while((*srct) != '\0')
	{
            *dt = (*srct);
	    dt++;
            srct++;	    
	}
	*dt = *srct;
	return dst;
}


char *istrcat(char *dst, const char *src) {
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

int istrcmp(const char *s1, const char *s2) {
    // size_t s1len = strlen(s1);
    // size_t s2len = strlen(s2);
     const char *s1p = s1;
     const char *s2p = s2;
    // if(s1len != s2len) return 1;
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


void *imemset(void *s, int c, int n) {
        char *st = (char*)s;  
	while(n != 0)
	{
		n--;
		*st++ = c;
	}	
	return s;
}


int imemcmp(const void *s1, const void *s2, int n) {
         const unsigned char *su1, *su2;
	int res = 0;
	for (su1 = s1, su2 = s2; 0 < n; su1++, su2++, n--)
		if ((res = *su1 - *su2) != 0)
			break;
	return res;
}

void check(bool cond) {
  if (!cond) printf("error");
}


char *s[] = {
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
        ", World!\n",
        "Hello, World!\n",
        "#####"
};

char str1[] = "Hello";
char str[20];

int main() {
	check(istrcmp(s[0], s[2])==0);
//      check(strcmp(s[0] + 1, s[1] + 1) < 0);
//      check(strcmp(s[0] + 2, s[1] + 2) < 0);
//      check(strcmp(s[0] + 3, s[1] + 3) < 0);

// check(strcmp( strcat(strcpy(str, str1), s[3]), s[4]) == 0);

//      check(memcmp(memset(str, '#', 5), s[5], 5) == 0);

        return 0;
}

