long xstrtol (char *p, char **ep, int base)
{
    errno = 0;

    long tmp = strtol (p, ep, base);

    /* Check for various possible errors */
    if ((errno == ERANGE && (tmp == LONG_MIN || tmp == LONG_MAX)) ||
        (errno != 0 && tmp == 0)) {
        perror ("strtol");
        exit (EXIT_FAILURE);
    }

    if (*ep == p) {
        fprintf (stderr, "No digits were found\n");
        exit (EXIT_FAILURE);
    }

    return tmp;
}