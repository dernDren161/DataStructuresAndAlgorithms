// Problem Link: https://www.geeksforgeeks.org/write-a-c-program-to-calculate-powxn/

int power(int x, int y)
{
    int result = 1;
    while (y > 0) {
        if (y % 2 == 0) // y is even
        {
            x = x * x;
            y = y / 2;
        }
        else // y isn't even
        {
            result = result * x;
            y = y - 1;
        }
    }
    return result;
}
