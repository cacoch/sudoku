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
 * check  n-row for existence j
 * input: row number
 *        j number to check
 * output: 1 exist
 *         0 no
 */
int check_nrow(int row, int j)
{
  printf("Row %d : ", row);

  for (int i = row * 9; i < 9 * (row + 1); i++)
    printf(" %c ", data[i]);
  printf("\n");
  return 1;
}

int main()
{
  printf("%s", formated_data);
  display(data);
  check_nrow(0, 1);
  printf("===\n");
  check_nrow(1, 1);
  printf("===\n");
  check_nrow(2, 1);
  printf("===\n");
  check_nrow(3, 1);
  printf("===\n");
  check_nrow(4, 1);
  printf("===\n");
  check_nrow(5, 1);
  printf("===\n");
  check_nrow(6, 1);
  printf("===\n");
  check_nrow(7, 1);
  printf("===\n");
  check_nrow(8, 1);
  printf("===\n");

  return 0;
}
