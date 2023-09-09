#include "../incl/so_long.h"

int ft_check_char(char *str_map)
{
    int i;

    i = 0;
    while(str_map[i])
    {
        if(str_map[i] == '0' || str_map[i] == 'E' || str_map[i] == 'P' || str_map[i] == '1' || str_map[i] == 'C')
            i++;
        else
            return(0);
    }
    return(1);
}

int ft_check_char_amount(char *str_map)
{
    int i;
    int j;
    int k;
    int l;

    i = 0;
    j = 0;
    k = 0;
    l = 0;
    while(str_map[i])
    {
        if(str_map[i] == 'E')
            j++;
        if(str_map[i] == 'P')
            k++;
        if(str_map[i] == 'C')
            l++;
        i++;
    }
    if (j == 1 && k == 1 && l >= 1)
        return(1);
    else
        return(0);
}

int ft_check_amount_lines(char *str_map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(str_map[i])
    {
        if (str_map[i] == '\n')
            j++;
        i++;
    }
    if (j > 128)
        return(0);
    else if (j > 5)
        return(0);
    return(1);
}

int ft_check_line_length(char *str_map)
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    while (str_map[i] != '\n')
        i++;
    j = i;
    while (str_map[j])
    {
        k = 0;
        while (str_map[j] != '\n')
        {
            j++;
            k++;
        }
        if (k != i)
            return (0);
    }
    return (1);
}

void ft_validate_map(char *str_map)
{
    if(!(ft_check_char(str_map)))
        ft_error(E_CHAR);
    if(!(ft_check_char_amount(str_map)))
        ft_error(E_CHAR); //I can create a specific error message for this
    if(!(ft_check_amount_lines(str_map)))
        ft_error(E_MAX);
    if(!(ft_check_line_length(str_map)))
        ft_error(E_MAPNOTVALID);
}