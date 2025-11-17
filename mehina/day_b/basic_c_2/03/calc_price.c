/*------------------------------------------------------
* Filename: [calc_price.c]
* Description: [calculate and print the price of a delivery]
* Author: [Kiran Kabaso]
-------------------------------------------------------*/

#include <stdio.h>

//define fees
#define DELIVERY_FEE 5.5
#define WEIGHT_FEE 11
#define SQUARED_CM_FEE 0.3
#define SIZE_CM_SOURED_DEV_WEIGHT_FEE 0.1

float calculate_price(int length_in_mm, int width_in_mm, int weight_in_g);
/*------------------------------------------------------
* Function Name - [main]
*
* Function Purpose - [calculate and print the price of a delivery]
*
* Parameters –  NONE
*
* Return Values - [0]
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
int main() {
  int length_in_mm = 0;
  int width_in_mm = 0;
  int weight_in_g = 0;

  // get data from user
  printf("Please enter the length(mm), width(mm) and weight(g) of the package.\n");
  scanf("%d %d %d", &length_in_mm, &width_in_mm, &weight_in_g);

  //calculate price
  float price = calculate_price(length_in_mm, width_in_mm, weight_in_g);

  //final prints
  float package_size_cm = (float)length_in_mm/10 * (float)width_in_mm/10;
  float package_weight_kg = (float)weight_in_g/1000;
  printf("Package size in cm: %.2f\n", package_size_cm);
  printf("Package weight in kg: %.3f\n", package_weight_kg);
  printf("Package price: %.2f\n", price);

  return 0;
}


/*------------------------------------------------------
* Function Name - [calculate_price]
*
* Function Purpose - [calculate the price of a package given its length, width and weight]
*
* Parameters –  [int length_in_mm, int width_in_mm, int weight_in_g]
*
* Return Values - [float price]
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
float calculate_price(int length_in_mm, int width_in_mm, int weight_in_g){
  float weight_kg = (float)weight_in_g/1000;
  float size_squared_cm = (float)length_in_mm/10 * (float)width_in_mm/10;

  float delivery_fee = DELIVERY_FEE;
  float weight_fee = WEIGHT_FEE*weight_kg;
  float squared_cm_fee = SQUARED_CM_FEE* size_squared_cm;
  float size_cm_squared_dev_weight_fee = SIZE_CM_SOURED_DEV_WEIGHT_FEE*size_squared_cm/weight_kg;

  return delivery_fee + weight_fee + squared_cm_fee + size_cm_squared_dev_weight_fee;
}