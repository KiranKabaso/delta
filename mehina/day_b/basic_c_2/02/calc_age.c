/*------------------------------------------------------
* Filename: [calc_age.c]
* Description: [gets the date and birthdate and prints the age in years, months and days independently]
* Author: [Kiran Kabaso]
-------------------------------------------------------*/
#include <stdio.h>

/*------------------------------------------------------
* Function Name - [main]
*
* Function Purpose - [gets the date and birthdate and prints the age in years, months and days independently]
*
* Parameters –  NONE
*
* Return Values - [0]
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
int main() {

  int current_date_days = 0;
  int current_date_months = 0;
  int current_date_years = 0;

  int birthday_days = 0;
  int birthday_months = 0;
  int birthday_years = 0;

  int current_date_days_sum = 0;
  int birthday_days_sum = 0;
  int days_difference = 0;

  float age_in_months = 0.0;
  float age_in_years = 0.0;

  printf("Enter current date:\n");
  scanf("%d/%d/%d", &current_date_days, &current_date_months, &current_date_years);

  printf("Enter Gary's Birthday:\n");
  scanf("%d/%d/%d", &birthday_days, &birthday_months, &birthday_years);

  current_date_days_sum = current_date_days + current_date_months*30 + current_date_years*365;
  birthday_days_sum = birthday_days + birthday_months*30 + birthday_years*365;

  days_difference = current_date_days_sum - birthday_days_sum;
  age_in_months = (float)days_difference / 30.0;
  age_in_years = (float)days_difference / 365.0;

  printf("Gary's age in days %d\n", days_difference);
  printf("Gary's age in months %.6f\n", age_in_months);
  printf("Gary's age in years %.6f\n", age_in_years);

  return 0;
}
