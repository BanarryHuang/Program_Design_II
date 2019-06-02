
//
//  實作高斯消去法
//

int n,m;
int M[1000][20];

//
//  需要使用到的 Row operations

void swap_rows( int a, int b );  // swap row a and row b
void add_to( int a, int b );    // add row a into row b and take modulo 2

int is_zero( int a );

//
//
//

void Gaussian_Elimination()
{

    for( i=0; i<m; i++)
    {
        //
        //  At the i-th iteration,
        //  we try to find the i-th linearly independent vector
        //

        //  1. Find the first non-zero row in row i to row m-1
        //
        //     Let the index of the row be j
        //
        //     If this is not possible,
        //     then we have found all linearly independent vectors
        //     so we can leave the loop.
        //

        //  2. Swap row i and row j
        //

        //  3. Find the index of the first non-zero column at row i
        //
        //     Let the index be k

        //  4. For each row j from i+1 to m-1,
        //
        //     Add row i to row j if M[j][k] == 1
        //
    }
}
