#include<stdio.h>
#include<stdlib.h>
//--------------------------------------------------------------
struct node
{
	int a3,a1,a2;
	int class;

}instance[9];
//--------------------------------------------------------------
void gini (struct node *instance)           				//Calculate Gini values for all three attributes
{
	int c1=0,c2=0,arr[9],count;
	float g1=0,g2=0,g3=0,s1=0,s2=0,s[7],sum;
	
	for(int i=0;i<9;i++)						//Count the number of attribute values in a1
	{
		
		if(instance[0].a1==instance[i].a1)
			c1++;
		else
			c2++;

	}
	s1=(float)c1/(float)(c1+c2);
	s2=(float)c2/(float)(c1+c2);
	s1*=s1;
	s2*=s2;
	g1=1-s1-s2;							  //Calculation of gini for attribute 1
	printf("Gini for a1 = %f\n",g1);
	c1=0,c2=0;
	g1=0,g2=0,g3=0,s1=0,s2=0;
	for(int i=0;i<9;i++)						//Count the number of attribute values in a2
	{
		
		if(instance[0].a2==instance[i].a2)
			c1++;
		else
			c2++;

	}
	s1=(float)c1/(float)(c1+c2);
	s2=(float)c2/(float)(c1+c2);
	s1*=s1;
	s2*=s2;
	g2=1-s1-s2;							  //Calculation of gini for attribute 2
	printf("Gini for a2 = %f\n",g2);
	for(int i=0;i<9;i++)
		arr[i]=-1;
	for(int i=0; i<9; i++)                                   //Count the number of attribute values in a3
    {
        count = 1;
        for(int j=i+1; j<9; j++)
        {
            if(instance[i].a3==instance[j].a3)
            {
                count++;
                arr[j] = 0;
            }
        }
 
        if(arr[i]!=0)
        {
            arr[i] = count;
        }
    }
 
	for(int i=0;i<9;i++)
		sum+=arr[i];
	for(int i=0;i<9;i++)
	{
		s[i]=(float)arr[i]/sum;
		s[i]*=s[i];
	}
	sum=0;

	for(int i=0;i<9;i++)						//Calculation of gini for attribute 3
		sum+=s[i];
	g3=1-sum;
	printf("Gini for a3 = %f\n",g3);


}

//--------------------------------------------------------------
int main()
{
	
	for(int i=0;i<9;i++)
		scanf("%d",&instance[i].a1);


	for(int i=0;i<9;i++)
		scanf("%d",&instance[i].a2);

	for(int i=0;i<9;i++)
		scanf("%d",&instance[i].a3);

	for(int i=0;i<9;i++)
		scanf("%d",&instance[i].class);

	gini(instance);							  //To calculate gini values for all attributes


	printf("Instance\ta1\ta2\ta3\tclass\n\n");
	for (int  i= 0; i < 9; ++i)
	{
		printf("%d\t\t%d\t%d\t%d\t%d\n",i+1,instance[i].a1,instance[i].a2,instance[i].a3,instance[i].class);
	}
	return 0;

}
