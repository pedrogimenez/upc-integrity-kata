#include "upc.h"

uint8_t check_digit_of(const char *upc, size_t upc_len);
uint8_t upc_sum(const char *upc, size_t upc_len);
uint8_t real_value_of(const char *upc, const char *i);

bool check_upc_integrity(const char *upc)
{
    size_t upc_len;
    uint8_t check_digit;

    upc_len = strlen(upc);

    if (upc_len != 12)
        return false;

    check_digit = upc[upc_len];

    return check_digit == check_digit_of(upc, upc_len);
}

uint8_t check_digit_of(const char *upc, size_t upc_len)
{
    return 9 - ((upc_sum(upc, upc_len) - 1) % 10);
}

uint8_t upc_sum(const char *upc, size_t upc_len)
{
    char *current_digit;
    char *end;
    uint8_t total = 0;

    current_digit = (char *)upc;
    end = current_digit + upc_len;

    for (; current_digit < end; ++current_digit) {
        total += real_value_of(upc, current_digit);
    }

    return total;
}

uint8_t real_value_of(const char *upc, const char *current_digit)
{
    uint8_t index;
    uint8_t number;

    index = current_digit - upc;
    number = *current_digit - '0';

    if (index % 2)
        return number;

    return number * 3;
}
