#include <stdio.h>
#include <math.h>
void calculateRepayment(float loan,float interestRate,int years);
int main()
{
	int years;
	float loan,interestRate;
	
	printf("Enter Loan: ");
	scanf("%f", &loan);
	printf("\nEnter Years: ");
	scanf("%d", &years);
	printf("\nEnter Interest Rate percentage: ");
	scanf("%f", &interestRate);
	interestRate/=100;
	calculateRepayment(loan, interestRate, years);
	printf("\n");
	return 0;
}

void calculateRepayment(float loan,float interestRate,int years)
{
	float installment;
	static float totalrepay=0;
	static int i=1;
	//This is the base case, if the years are completed or if loan becomes approximately 0.
	if (years==0 || loan<1)
	{
		printf("\n\nThe total repayment will be %.3f", totalrepay);
		return;
	}
	//The formula or calculation below is called "loan amortization (installment) formula".
	//It is used to calculate the installment you need to pay in such a way that the loan always equals to 0 in the end.
	//Also, as the loan amount each year changes, it actually wont have any effect on the installment formula because the years decrease.
	installment = (loan * interestRate*pow(1+interestRate, years))/(pow(1+interestRate, years)-1);
	totalrepay+=installment;
	//This is the loan calculation.
	loan = (loan + loan*interestRate)-installment;
	printf("\nYear %d: Remaining Loan = %.1f", i, loan);
	++i;
	//recursion
	calculateRepayment(loan, interestRate, years-1);
}

