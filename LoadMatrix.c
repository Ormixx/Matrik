int LoadMatrix (matrix *m)
{
    FILE *stuff;
    char line[MAXLN] = {0};     /* line buffer */
    char *p, *ep;     /* pointers for strtol   */
    size_t row = 0;   /* simple row counter    */
    // char c;

    if ((stuff = fopen ("matrix.txt", "r")) == NULL) {
        printf ("File missing..."); /* should be fprintf */
        exit (1);
    }

    while (fgets (line, MAXLN, stuff)) /* read each line in file */
    {
        size_t col = 0;    /* initialize variables for each row */
        p = ep = line;
        errno = 0;

        /* skip to first digit in line */
        while (*p && *p != '-' && (*p < '0' || *p > '9')) p++;

        while (errno == 0)
        {   /* read each number in row */
            m->matrixgrafh[row][col++] = (int)xstrtol (p, &ep, 10);

            if (col == MAX) { /* check col against MAX */
                fprintf (stderr, "LoadMatrix() error: MAX columns reached.\n");
                break;
            }

            /* skip to next number */
            while (*ep && *ep != '-' && (*ep < '0' || *ep > '9')) ep++;
            if (*ep) p = ep;
            else break;
        }

        if (row == 0) m->cols = col;    /* set the number of colums in each row */
        if (col != m->cols) {           /* validate each row against first      */
            fprintf (stderr, "LoadMatrix() error: invalid number of columns, row '%zu'.\n",
                    row);
            fclose (stuff);
            return -1;
        }
        row++;

        if (row == MAX) { /* check col against MAX */
            fprintf (stderr, "LoadMatrix() error: MAX rows reached.\n");
            break;
        }
    }