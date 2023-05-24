#include "main.h"

/**
 * _strtok - Splits a string into tokens based on delimiters.
 * @str: given string.
 * @delim: delimiter
 *
 * Return: NULL terminated string.
 */
char *_strtok(char *str, const char *delim)
{
    static char *next_token = NULL;
    char *token_start = NULL;
    int is_delim = 0;

    if (str != NULL)
    {
        next_token = str;
    }

    if (next_token == NULL || *next_token == '\0')
    {
        return (NULL);
    }

    while (*next_token != '\0')
    {
        is_delim = 0;
        for (const char *d = delim; *d != '\0'; d++)
	{
            if (*next_token == *d)
	    {
                is_delim = 1;
                break;
            }
        }
        if (!is_delim)
	{
            break;
        }
        next_token++;
    }

    if (*next_token == '\0')
    {
        return (NULL);
    }

    token_start = next_token;  

    while (*next_token != '\0')
    {
        is_delim = 0;
        for (const char *d = delim; *d != '\0'; d++) 
	{
            if (*next_token == *d)
	    {
                is_delim = 1;
                break;
            }
        }
        if (is_delim) 
	{
            break;
        }
        next_token++;
    }

    if (*next_token == '\0')
    {
        next_token = NULL;
    } 
    else 
    {
        *next_token = '\0';
        next_token++;
    }
    return (token_start);
}
