#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

typedef struct
{
	char *buf_s;
	char *buf_e;
	int cnt;
}sprintbuf;

static void putch_str(int ch,sprintbuf * buf)
{
	buf->cnt++;
	*buf->buf_s++ = ch;
}

static inline unsigned int __mulu10(unsigned int n)
{
  return (n << 3) + (n << 1);
}

static inline unsigned int __divu10(unsigned int n)
{
  unsigned int q, r;
  q = (n >> 1) + (n >> 2);
  q = q + (q >> 4);
  q = q + (q >> 8);
  q = q + (q >> 16);
  q = q >> 3;
  r = n - __mulu10(q);
  return q + ((r + 6) >> 4);
}

int printf(const char *fmt, ...) {
  panic("Not implemented");
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}


int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

static void printnum(void (*_putch)(char, void *), void *cnt, unsigned int num,
                     unsigned int base, int width, int padc)
{
	unsigned int result = num;
	unsigned int mod = 0;
	if(base == 10)
	{
		unsigned int t = __divu10(result);
		mod = result - __mulu10(t);
		result = t;
	}
	else if (base == 8)
	{
		mod = result & 0x7;
		result = result >> 3;
	}
        else
	{
		mod = result & 0xF;
		result = result >> 4;
	}

	if(num >= base)
	{
		printnum(_putch,cnt,result,base,width -1,padc);
	}	
	else
	{
		while(--width > 0)
		{
			_putch(padc,cnt);
		}
	}
	_putch("0123456789abcdef"[mod], cnt);
}

static long long getint(va_list *ap, int lflag)
{
  if (lflag >= 2)
  {
    return va_arg(*ap, long long);
  }
  else if (lflag)
  {
    return va_arg(*ap, long);
  }
  else
  {
    return va_arg(*ap, int);
  }
}

static void vprintfmt(void (*_putch)(char,void *),void *cnt,const char *fmt,va_list ap)
{
	register const char *p;
	register int ch;
	unsigned long long num;
	int base, width, precision, lflag, altflag;
	while(1)
	{
		while((ch = *(unsigned char*)fmt++) != '%')
		{
			if(ch == '\0')
			{
				return;
			}
		}
		_putch(ch,cnt);
	}
	char padc = ' ';
	width = precision = -1;
	lflag = altflag = 0;

	switch(ch = *(unsigned char*)fmt++)
	{
		case 's':
			if((p = va_arg(ap,char*)) == NULL)
			{
				p = "(null)";
			}
			if(width > 0 && padc != '-')
			{
				for(width -= strnlen(p,precision); width > 0; width--)
				{
					_putch(padc,cnt);
				}
			}
			for(;(ch == *p++) != '\0' && (precision < 0 || --precision >= 0);
			width--)
			{
				if(altflag && (ch < ' ' || ch > '~'))
				{
					_putch('?',cnt);
				}
				else
				{
					_putch(ch,cnt);
				}
			}
			for(;width > 0; width--)
			{
				_putch(' ',cnt);
			}
			break;
		case 'd':
			num = getint(&ap,lflag);
			if ((long long)num < 0)
     			 {
        			_putch('-', cnt);
        			num = -(long long)num;
      			}
     			 base = 10;
      			goto number;
		number:
			printnum(_putch,cnt,num,base,width,padc);
			break;
	}
}
			                            


int vsnprintf(char *out, size_t n, const char *fmt, va_list ap){
    sprintbuf buf;
    buf.buf_s = out;
    buf.buf_e = NULL;
    buf.cnt = 0;
    vprintfmt((void*)putch_str, &buf,fmt,ap);
    *(buf.buf_s) = '\0';
    return buf.cnt;
}

int sprintf(char *out, const char *fmt, ...) {
      va_list ap;
      int cnt;
      va_start(ap,fmt);
      cnt = vsprintf(out,fmt,ap);
      va_end(ap);
      return cnt; 
}


#endif
