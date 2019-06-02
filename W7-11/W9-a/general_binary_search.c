
//
//  To find:
//             the index of the first 1 in a 0-1 monotone sequence
//

int binary_search( int left, int right )
{
    if( test(left) == 1 )
        return left;

    if( test(right) == 0 )
        return -1;

    int mid;

    while( left < right - 1 )
    {
        mid = ( left + right ) / 2;

        if( test(mid) == 0 )
            left = mid;
        else
            right = mid;
    }

    return right;
}
