void mx_printchar(char c);

void mx_cube(int n) {
    if (n <= 1)
        return;

    int z = (double)(n / 2) != (int)(n / 2) ? 0 : 1;
    int i = 0;

    while (i < n / 2 + z) {
        mx_printchar(' ');
        i++;
    }
    mx_printchar('+');

    i = 0;
    while (i < 2 * n) {
        mx_printchar('-');
        i++;
    }

    mx_printchar('+');
    mx_printchar('\n');

    int k = 1, m = (int)(n / 2) * 2 - n / 2;
    i = n / 2;
    while (i > 0) {
        int j = m;
        while (j > 0) {
            mx_printchar(' ');
            j--;
        }
        mx_printchar('/');

        j = 0;
        while (j < n * 2) {
            mx_printchar(' ');
            j++;
        }

        mx_printchar('/');
        j = 1;
        while (j < k) {
                    mx_printchar(' ');
            j++;
        }

        mx_printchar('|');
        mx_printchar('\n');
        i--; m--; k++;
    }

    mx_printchar('+');

    i = 0;
    while (i < 2 * n) {
        mx_printchar('-');
        i++;
    }

    mx_printchar('+');

    int j = 1;
    while (j < n / 2 + 1) {
        mx_printchar(' ');
        j++;
    }

    mx_printchar('|');
    mx_printchar('\n');

    i = 0;
    while (i < n / 2.0 - z) {
        mx_printchar('|');

        j = 0;
        while (j < n * 2) {
            mx_printchar(' ');
            j++;
        }

        mx_printchar('|');

        j = 0;
        while (j < n / 2) {
            mx_printchar(' ');
            j++;
        }

        mx_printchar('|');
        mx_printchar('\n');
        i++;
    }

    mx_printchar('|');

    j = 0;
    while (j < n * 2) {
        mx_printchar(' ');
        j++;
    }

    mx_printchar('|');

    j = 0;
    while (j < n / 2) {
        mx_printchar(' ');
        j++;
    }

    mx_printchar('+');
    mx_printchar('\n');

    k = n / 2.0 - 1;
    i = n / 2;
    while (i > 0) {
        mx_printchar('|');

        j = 0;
        while (j < n * 2) {
            mx_printchar(' ');
            j++;
        }

        mx_printchar('|');

        j = 0;
        while (j < k) {
            mx_printchar(' ');
            j++;
        }

        mx_printchar('/');
        mx_printchar('\n');
        i--; k--;
    }

    mx_printchar('+');

    i = 0;
    while (i < n * 2) {
        mx_printchar('-');
        i++;
    }

    mx_printchar('+');
    mx_printchar('\n');
}

