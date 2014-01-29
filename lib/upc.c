#include "upc.h"

uint8_t check_digit_of(char upc[]);
uint8_t upc_sum(char upc[]);
uint8_t real_value_of(char digit, size_t current_digit);

bool check_upc_integrity(char upc[])
{
    size_t upc_len;
    uint8_t check_digit;

    upc_len = strlen(upc);

    if (upc_len != 12)
        return false;

    check_digit = upc[upc_len];

    return check_digit == check_digit_of(upc);
}

uint8_t check_digit_of(char upc[])
{
    return 9 - ((upc_sum(upc) - 1) % 10);
}

uint8_t upc_sum(char upc[])
{
    size_t upc_len;
    uint8_t total = 0;
    size_t current_digit;

    upc_len = strlen(upc);

    for (current_digit = 0; current_digit < upc_len; ++current_digit)
        total += real_value_of(upc[current_digit], current_digit);

    return total;
}

uint8_t real_value_of(char digit, size_t current_digit)
{
    uint8_t number;

    number = digit - '0';

    if (current_digit % 2)
        return number;

    return number * 3;
}
