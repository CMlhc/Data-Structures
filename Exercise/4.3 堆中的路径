#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define TYPE int
#define MINNUM -10001
void PrintPath( TYPE* A, int N, int i );
void Insert( TYPE *A, int N, TYPE X );

int main( ){
    int N;
    int M;
    int* A;
    scanf( "%d %d", &N, &M );
    A = ( TYPE* ) malloc( sizeof( TYPE ) * ( N + 1 ) );
    A[ 0 ] = MINNUM;
    if( !A ){
        exit( EXIT_FAILURE );
    }
    for( int i = 1; i <= N; i++ ){
        TYPE data;
        scanf( "%d", &data );
        Insert( A, i, data ); //?data??
    }
    for( int i = 0; i < M; i++ ){
        int k;
        scanf( "%d", &k );
        PrintPath( A, N, k );
    }
    free( A );
    return 0;
}


void Insert( TYPE *A, int N, TYPE X ){
    int i = N;
    for( i = N; A[ i / 2 ] > X; i /= 2 ){
        A[ i ] = A [ i / 2 ];
    }
    A[ i ] = X;
}

void PrintPath( TYPE* A, int N, int i ){
    while( i > 0 ){
        if( i > 1 ){
            printf( "%d ", A[ i ] );
        }
        else{
            printf( "%d\n", A[ i ] );
        }
        i /= 2;
    }
}
