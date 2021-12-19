#include <stdio.h>

typedef long long ll;

int main(){
    ll n,m,a;
    ll Altura, Largura, Quantidade;
    
    scanf("%lld %lld %lld", &n, &m, &a);
    
    Largura = (n+a-1)/a;
    Altura = (m+a-1)/a;

    Quantidade = Altura*Largura;

    printf("%lld", Quantidade);
}