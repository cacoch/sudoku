#include <stdio.h>
#include <stdlib.h>



//9 2 3 4 3
char data[] =     "467100805912835607085647192296351470708920351531408926073064510624519783159783064";
charsolution[]=   "467192835912835647385647192296351478748926351531478926873264519624519783159783264";

// number of 0's, what we have to solve
int num_holes = 0;
// linear position 0'so
int arr_holes[40];
// # current guess
int current_hole=0;

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


void show_holes()
{
    for (int i =0; i < 81; i++)
    {
        if(data[i] == '0') {
            printf("%d ", i);
            arr_holes[num_holes]= i ;
            num_holes++;

        }

    }
    // printf("\n Holes %d \n", num_holes);
}

int prev_pos(void) {

    if (current_hole == 0) {
        printf("ups , it shouldn't happend");
        exit(0);
    }
    else
        current_hole--;



    return arr_holes[current_hole];
}

int next_pos(void ) {
    if (current_hole == num_holes) {
        printf("Done");
        display(data);
        if ( strcmp( data, charsolution) == 0) {
            printf("The solution is ok\n");
            exit(0);

        }
        else
            current_hole++;



        return arr_holes[current_hole];
    }

    void find_match(int pos) {
        for(int i =1; i <11; i++) {
            if (i == 10) {
                data[pos] = 0 + 48;
                pos = prev_pos();
                find_match(pos);
            }
            if( 	check_num(pos, i) == 0) {
                printf("Match %d on position %d.\n", i, pos);
                data[pos] = i + 48;
                //display(data);
                pos = next_pos();
                find_match(pos);


            }
        }
    }


    int main()
    {
        display(data);
        //check_ncolumn(0,1);
        //printf("=\n");
        //check_ncolumn(1,1);
        //printf("=\n");
        //check_ncolumn(7,1);
        //printf("=\n");
        //check_ncolumn(8,1);
        //printf("=\n");

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

        show_holes();
        find_match(4);

        return 0;
    }
