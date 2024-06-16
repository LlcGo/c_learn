#include <stdio.h>
#include <stdbool.h>
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


char *istrcpy(char *dst, const char *src) {
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
     while((*s1p) != '\0' && (*s1p == *s2p))
     {
	  s1p++;
	  s2p++;
     }
     int t;
     t = *s1p - *s2p;
     return t;
}


void *imemset(void *s, int c, size_t n) {
        char *st = s;  
	while(n != 0)
	{
		n--;
		*st++ = c;
	}	
	return  s;
}


int imemcmp(const void *s1, const void *s2, size_t n) {
         const unsigned char *su1, *su2;
	int res = 0;
	for (su1 = s1, su2 = s2; 0 < n; su1++, su2++, n--)
		if ((res = *su1 - *su2) != 0)
			break;
	return res;
}

int main(){
	int i;
        i = istrcmp(s[0], s[2]); //0
        i = istrcmp(s[0], s[1]); //< 0
        i = istrcmp(s[0] + 1, s[1] + 1);// < 0);
        i = istrcmp(s[0] + 2, s[1] + 2);// < 0);
        i = istrcmp(s[0] + 3, s[1] + 3);// < 0);

        i = istrcmp( istrcat(istrcpy(str, str1), s[3]), s[4]); //== 0

        i = imemcmp(imemset(str, '#', 5), s[5], 5);// == 0);

	return 0;
}
