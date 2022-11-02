#include <stdio.h>

//Nanmanat Varisthanist 6509618200 22
//Teerajet Chanpha 6509618184 20
//Group ID: 6

int get_problem();
float get_rate_drop_factor();
float fig_drop_min(float rate , float dropfac);
int fig_ml_hr(int hr);
float get_kg_rate_conc();
float by_weight(float flowrate,float weight_1,float drug);
int get_unit_conc(); 
int by_units(int rate,int units);
int main()
{
	
	int input = get_problem();
	do
	{
		if (input == 1)
			get_rate_drop_factor();
		if (input == 2)
		{
			int hr;
        	printf("Enter number of hours: ");
        	scanf("%d",&hr);
        	printf("The rate in milliliters per hour is %d.\n",fig_ml_hr(hr));
		}
		if (input == 3)
			get_kg_rate_conc();
		if (input == 4)
			get_unit_conc();
	}while(input != 5);


	return 0;
}
int get_problem()
{
	int Num;
	printf("Enter thenumber of the problem you wish to solve.\n");
	printf("\tGIVEN A MEDICAL ORDER IN\t\tCALCULATE RATE IN\n");
	printf("(1)\tml/hr & tubing drop factor\t\tdrop / min\n");
	printf("(2)\t1 L for n hr\t\t\t\tml / hr\n");
	printf("(3)\tmg/kg/hr & concentration in mg/ml\tml / hr\n");
	printf("(4)\tunit/hr & concentration in unit/ml\tml / hr\n");
	printf("(5)\tQUIT\n");
	printf("Problem: ");
	scanf("%d",&Num);
	return Num;
}
float get_rate_drop_factor() //Function 1
{
	float rate1,dropfactor,droprate;
	printf("Enter rate in ml/hr:");
	scanf("%f",&rate1);
	printf("Enter tubing's drop factor(drop/ml):");
	scanf("%f",&dropfactor);
	printf("The drop rate per minute is %.0f.\n",fig_drop_min(rate1,dropfactor));
	return fig_drop_min(rate1,dropfactor);
}
float fig_drop_min(float rate , float dropfac) //CalFunction 1
{
	float droprate;
	droprate = (rate / 60) * dropfac;
	return droprate;
}
int fig_ml_hr(int hr) // calProblem 2
{
    int rate_per_hour = 1000/hr;
    return rate_per_hour;
}
float get_kg_rate_conc() //Function3
{
	float rate_3,weight,conc;
	printf("Enter rate in mg/kg/hr: ");
	scanf("%f",&rate_3);
	printf("Enter patient weight in kg: ");
	scanf("%f",&weight);
	printf("Enter concentration in mg/ml: ");
	scanf("%f",&conc);
	printf("The rate in milliliters per hour is %.0f",by_weight(rate_3,weight,conc));
	return by_weight(rate_3,weight,conc);
}
float by_weight(float flowrate,float weight_1,float drug) //calFunction3
{
	float Result;
	Result = (flowrate * weight_1) * drug;
	return Result;
}
int get_unit_conc() //Function4
{
	int rate,units;
        printf("Enter rate in units/hr: ");
        scanf("%d",&rate);
        printf("Enter concentration in units/ml: ");
        scanf("%d",&units);
        printf("The rate in milliliters per hour is %d.\n",by_units(rate,units));
        return by_units(rate,units);
}
int by_units(int rate,int units) //calFunction4
{
	int rate_mill = rate/units;
	return rate_mill;
}