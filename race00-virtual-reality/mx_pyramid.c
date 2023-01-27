void mx_printchar(char c);

void mx_pyramid(int n) {
    if (n <= 1 || n % 2 != 0)
        return;

    int i = 0;
    while (i < n) {
        if (i == 0) {
            int j = 0;
            while (j < n - 1) {
                mx_printchar(' ');
                j++;
            }
            mx_printchar('/');
            mx_printchar('\\');
        }
        else if (i !=n -1 && i + 1 <= n / 2) {
            int k = 0;
            while (k < n - i - 1) {
                mx_printchar(' ');
                k++;
            }
            mx_printchar('/');

            int l = 0;
            while (l < i * 2 -1) {
                mx_printchar(' ');
                l++;
            }
            mx_printchar('\\');

            int m = 0;
            while (m < i) {
                mx_printchar(' ');
                m++;
            }
            mx_printchar('\\');
        }
        else if (i != n -1) {
            int k = 0;
            while (k < n - i - 1) {
                mx_printchar(' ');
                k++;
            }
            mx_printchar('/');

            int l = 0;
            while (l < i * 2 -1) {
                mx_printchar(' ');
                l++;
            }
            mx_printchar('\\');

            int m = 0;
            while (m < n - i - 1) {
                mx_printchar(' ');
                m++;
            }
            mx_printchar('|');
        }
        else {
            mx_printchar('/');

            int l = 0;
            while (l < i * 2 -1) {
                mx_printchar('_');
                l++;
            }
            mx_printchar('\\');
            mx_printchar('|');
        }

        mx_printchar('\n');
        i++;
    }
}



