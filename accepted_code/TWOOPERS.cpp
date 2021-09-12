#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std ;

#define fi( a , b , c ) for ( int a = b ; a <= c ; a ++ )
#define fo( a , b , c ) for ( int a = b ; a >= c ; a -- )
#define long long long

const int N = 3000000;
const long base[3] = { int(1e9) + 3 , int(1e9) + 7 , 21070103 } ;

string s1 , s2 ;
int n , m ;
long ans ;
long h[2][3][N] , poww[3][N] ;

void prepare(){

     fi( k , 0 , 2 ){
          poww[k][0] = 1 ;
          fi( i , 1 , N )
               poww[k][i] = poww[k][i - 1] * 26 % base[k] ;
     }

}

long get( int i , int j , int k , int typee ){

     long x = ( h[typee][k][j] - h[typee][k][i - 1] * poww[k][j - i + 1] + base[k] * base[k] ) % base[k] ;
     return x ;

}

void hashh(){

     fi( k , 0 , 2 )
          fi( i , 1 , m )
               h[1][k][i] = ( ( h[1][k][i - 1] * 26 ) % base[k] + s2[i - 1] - 'A' ) % base[k] ;

     fi( k , 0 , 2 )
          fi( i , 1 , m )
               h[0][k][i] = ( ( h[0][k][i - 1] * 26 ) % base[k] + s1[i - 1] - 'A' ) % base[k] ;

}

bool check( int i , int d ){

     fi( k , 0 , 2 ){

          long x = get( i , i + d - 1 , k , 0 ) ;
          long y = get( 1 , d , k , 1 ) ;
          if ( x != y )
               return false ;

     }

     return true ;

}

int main(){

     prepare() ;

     cin >> s1 >> s2 ;
     n = s1.length() ; m = n * 2 - 1 ;
     s1 += s1 ; s2 += s2 ;

     hashh() ;

     fi( i , 1 , n ){

          int l = 0 , r = n + 1 ;
          while ( l + 1 < r ){

               int mid = ( l + r ) / 2 ;
               if ( check( i , mid ) )
                    l = mid ;
               else
                    r = mid ;

          }

          if ( l == n ){
               ans += n ;
               continue ;
          }

          bool ok = true ;
          fi( k , 0 , 2 )
               if ( get( i + l + 1 , i + n - 1 , k , 0 ) != get( l + 2 , n , k , 1 ) ){
                    ok = false ; break ;
               }

          if ( ok )
               ans ++ ;

     }

     printf( "%lld" , ans ) ;

     return 0 ;

}
