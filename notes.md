### TODO

<!--
1. Common time cost
```latex
10**5 0.2ms
10**6 2ms
10**7 20ms
10**8 200ms
10**9 2s
```


1m = 2**10 kb == 2**20b

Careful with overflow

Modulo properties
1. ( a + b ) % c = ( ( a % c ) + ( b % c ) ) % c
2. ( a * b ) % c = ( ( a % c ) * ( b % c ) ) % c
3. ( a – b ) % c = ( ( a % c ) - ( b % c ) ) % c ( see notes at bottom )
4  ( a / b ) % c = a * inv(b) % c
5. ( a * b * c ) % M is the same as ( ( ( a * b ) % M ) * c ) % M
6. ( a + b + c ) % M is the same as ( ( ( a + b ) % M ) + c ) % M
7. dont use a=(a%c); b=(b%c); ans=( a - b )%c;
7. instead use a=a%c; b=b%c; ans = ( a - b + c ) % c;
 -->


