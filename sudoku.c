#include <stdio.h>




char data[] = "467100805912835607085647192296351470708920351531408926073064510624519783159783064";

char formated_data[] = " 467100805\n 912835607\n 085647192\n 296351470\n 708920351\n 531408926\n 073064510\n 624519783\n 159783064\n";

char solution[] = "467192835912835647385647192296351478748926351531478926873264519624519783159783264";


void display(char *d)
{
    printf("+---------+---------+---------+\n");

    for (int j = 0; j < 9; j++)
    {
        printf("|");
        for (int i = j * 9 ; i < 9 * (j + 1); i++)
        {
            printf(" %c ",  d[i]);
            if ( i % 3 == 2)
                printf("|");
        }
        printf("\n");
        if ( j % 3 == 2)
            printf("+---------+---------+---------+\n");


    }

}

/*
 * check  n-row for j existence
 * input: row number
 *        j number to check
 * output: 1 exist
 *         0 no
 */
int check_nrow(int row, int j)
{

    for (int i = row * 9; i < 9 * (row + 1); i++) {
        if (j == (int)data[i] -48) return 1;
    }
    return 0;
}

/*
 * check  n-column for j existence
 * input: column number
 *        j number to check
 * output: 1 exist
 *         0 no
 */
int check_ncolumn(int column, int j)
{

    for (int i = 0; i < 81; i++) {
        if( i % 9 == column) {
            if (j == (int)data[i] -48) return 1;
        }

    }
    return 0;
}

/*
 * check  n-square for j existence
 * input: square number
 *        j number to check
 * output: 1 exist
 *         0 no
 *
 *   squares numbering
 *         0 1 2
 *         3 4 5
 *         6 7 8
 */
int check_nsquare(int sqr, int x)
{

    switch(sqr) {
    case  0:
        for (int j=0; j <3; j++) {
            printf("\n");
            for (int i = 0; i< 3; i++) {
                //  printf(" %c ",	data[i + j*9 ]);
                if (x == (int)data[i + j*9] -48) return 1;


            }
        }
    case  1:
        for (int j=0; j <3; j++) {
            printf("\n");
            for (int i = 3; i< 6; i++) {
                //  printf(" %c ",	data[i + j*9 ]);

                if (x == (int)data[i + j*9] -48) return 1;

            }
        }

    case  2:
        for (int j=0; j <3; j++) {
            printf("\n");
            for (int i = 6; i< 9; i++) {
                //  printf(" %c ",	data[i + j*9 ]);

                if (x == (int)data[i + j*9] -48) return 1;

            }
        }

    case  3:
        for (int j=0; j <3; j++) {
            printf("\n");
            for (int i = 0; i< 3; i++) {
                //  printf(" %c ",	data[i + j*9 +3*9 ]);

                if (x == (int)data[i + j*9 + 3*9] -48) return 1;

            }
        }

    case  4:
        for (int j=0; j <3; j++) {
            printf("\n");
            for (int i = 3; i< 6; i++) {
                //  printf(" %c ",	data[i + j*9 +3*9 ]);
                if (x == (int)data[i + j*9 +3*9] -48) return 1;


            }
        }

    case  5:
        for (int j=0; j <3; j++) {
            printf("\n");
            for (int i = 6; i< 9; i++) {
                //  printf(" %c ",	data[i + j*9 +3*9 ]);

                if (x == (int)data[i + j*9 +3*9] -48) return 1;

            }
        }
    case  6:
        for (int j=0; j <3; j++) {
            printf("\n");
            for (int i = 0; i< 3; i++) {
                //  printf(" %c ",	data[i + j*9 +6*9 ]);

                if (x == (int)data[i + j*9 +6*9] -48) return 1;

            }
        }
    case  7:
        for (int j=0; j <3; j++) {
            printf("\n");
            for (int i = 3; i< 6; i++) {
                //  printf(" %c ",	data[i + j*9 +6*9 ]);

                if (x == (int)data[i + j*9 +6*9] -48) return 1;

            }
        }
    case  8:
        for (int j=0; j <3; j++) {
            printf("\n");
            for (int i = 6; i< 9; i++) {
                //  printf(" %c ",	data[i + j*9 +6*9 ]);

                if (x == (int)data[i + j*9 +6*9] -48) return 1;

            }
        }
    } //end switch


    return 0;
}


/*
 * check if number fit
 * input: pos linear position
 *        j number to check
 * output: 1 exist (doesn't fit)
 *         0 no (fit )
 *
 */
int check_num(int pos,  int j)
{
    int row, col, sqr;
    int result;

    row = pos/9;
//	printf("row %d, ", row);
    result = check_nrow( row, j);

    if ( result == 1)
        return 1;

    col = pos % 9;
    //printf("col %d - ", col);
    result =  check_ncolumn( col, j);

    if ( result == 1)
        return 1;

    if(row < 3) {
        if(col < 3)
            sqr = 0;
        else if ((col <6) && (col>2))
            sqr = 1;
        else
            sqr = 2;
    }

    else if( (row < 6) && (row >2)) {
        if(col < 3)
            sqr = 3;
        else if ((col <6) && (col>2))
            sqr = 4;
        else
            sqr = 5;
    }

    else  {
        if(col < 3)
            sqr = 6;
        else if ((col <6) && (col>2))
            sqr = 7;
        else
            sqr = 8;
    }

    //printf("%d\n", sqr);

    return 0;
}

int main()
{
    printf("%s", formated_data);
    display(data);
    check_ncolumn(0,1);
    printf("=\n");
    check_ncolumn(1,1);
    printf("=\n");
    check_ncolumn(7,1);
    printf("=\n");
    check_ncolumn(8,1);
    printf("=\n");

    // check_nsquare(0,1);
    //  check_nsquare(1,1);
    //  check_nsquare(2,1);
    // check_nsquare(3,1);

    // check_nsquare(4,1);
    // check_nsquare(5,1);
    //  check_nsquare(6,1);
    // check_nsquare(7,1);
    //check_nsquare(8,1);
  //  for (int i=0; i < 81; i++) {
  //      printf( "%d  :", i);
  //      check_num(i, 10);
  //  }

    return 0;
}
