/******************************************************************************
 * Function: itob
 ******************************************************************************/
void itob(int n, char s[], int b)
{
    int i = 0;
    unsigned int num;

    num = (n < 0) ? -n : n;

    do
    {
        int digit = num % b;
        s[i++] = (digit < 10) ? digit + '0' : digit - 10 + 'A';
        num /= b;
    } while(num > 0);

    if(n < 0)
        s[i++] = '-';

    s[i] = '\0';

    reverse(s);
}