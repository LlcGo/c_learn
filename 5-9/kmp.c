#inlucde <stdio.h>
#include <stdlib.h>

getNext(int * next,char * str)
{
	int nextSize = strlen(str);
	// 获得容量
	next = (int *)malloc(nextSize * sizeof(int));
	
	next[0] = -1; 
	next[1] = 0;
	
	int i = 2; //提前走了俩步
	int k = 0; // 前一项的next索引数值 
	while(i < nextSize)
	{
		// 如果前面的一个字符与next下标所代表的字符相等
		if(k == -1 || *(str + (i - 1)) == *(str + k))
		{
			next[i] = k + 1;
			i++;
			k++;// 代表next列表中的值
		}
		else
		{
			//如果不相等就一直回退
			k = next[k];
		}
	}
	
}

// str1 主串  str2 匹配串
int kmp(char * str1, char * str2)
{
	int strlen1 = strlen(str1);
	int strlen2 = strlen(str2);
	int i = 0;// str1下标
	int j = 0;// str2下标
	
	int * next;
	
	getNext(next,str2);
	
	while(strlen1 < i && strlen2 < j)
	{
		//如果一开始就没有匹配到直接++
		if(j == -1 ||*(str1+i) == *(str2+j))
		{
			j++;
			i++;
		}
		else
		{
			// next数组定位
			j = *(next+j);
		}
	}
	
	if(i >= strlen1)
	{
		return -1;
	}
	
	// 返回出现在主串中的索引
	return i - j;
	
}
