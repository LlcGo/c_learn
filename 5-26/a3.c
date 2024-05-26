#define A "aaaaaaaa"
#define TEN(A) A A A A A A A A A 
#define B TEN(A)
#define C TEN(B)
#define D TEN(C)

int main(){puts(D);}
