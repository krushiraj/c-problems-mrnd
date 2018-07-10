/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Year 999 will be represented as 0999.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
struct node{
	int data;
	struct node *next;
};
int between_days(struct node *date1head, struct node *date2head)
{
	if (date1head == NULL || date2head == NULL)
	{
		return -1;
	}
	int count = 0;
	struct node *temp1 = (node*)malloc(sizeof(struct node));
	struct node *temp2 = (node*)malloc(sizeof(struct node));
	temp1 = date1head;
	temp2 = date2head;
	int day1 = 0, day2 = 0, mnth1 = 0, mnth2 = 0, yr1 = 0, yr2 = 0;
	while (temp1 != NULL && temp2 != NULL)
	{
		if (count < 2)
		{
			day1 = day1 * 10 + temp1->data;
			day2 = day2 * 10 + temp2->data;
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		if (count < 4 && count >= 2)
		{
			mnth1 = mnth1 * 10 + temp1->data;
			mnth2 = mnth2 * 10 + temp2->data;
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		if (count < 8 && count >= 4)
		{
			yr1 = yr1 * 10 + temp1->data;
			yr2 = yr2 * 10 + temp2->data;
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		count++;
	}
	if (day1 == day2&&mnth1 == mnth2&&yr1 == yr2)return 0;
	long int totalday1 = 0;
	long int totalday2 = 0;
	int leap1 = 0, leap2 = 0;
	if (mnth1 > 2)
	{
		leap1 = yr1 / 4 - yr1 / 100 + yr1 / 400;
	}
	else if (mnth1 <= 2)
	{
		leap1 = (yr1 - 1) / 4 - (yr1 - 1) / 100 + (yr1 - 1) / 400;
	}
	if (mnth2 > 2)
	{
		leap2 = yr2 / 4 - yr2 / 100 + yr2 / 400;
	}
	else if (mnth2 <= 2)
	{
		leap2 = (yr2 - 1) / 4 - (yr2 - 1) / 100 + (yr2 - 1) / 400;
	}

	totalday1 = yr1 * 365 + leap1;
	totalday2 = yr2 * 365 + leap2;
	int count1 = 1, count2 = 1;
	while (count1 != mnth1)
	{
		if (count1 == 1 || count1 == 3 || count1 == 5 || count1 == 7 || count1 == 8 || count1 == 10 || count1 == 12)
		{
			totalday1 = totalday1 + 31;
		}
		else if (count1 == 4 || count1 == 6 || count1 == 9 || count1 == 11)
		{
			totalday1 = totalday1 + 30;
		}
		else if (count1 == 2)
		{
			totalday1 = totalday1 + 28;
		}
		count1++;
	}
	while (count2 != mnth2)
	{
		if (count2 == 1 || count2 == 3 || count2 == 5 || count2 == 7 || count2 == 8 || count2 == 10 || count2 == 12)
		{
			totalday2 = totalday2 + 31;
		}
		else if (count2 == 4 || count2 == 6 || count2 == 9 || count2 == 11)
		{
			totalday2 = totalday2 + 30;
		}
		else if (count2 == 2)
		{
			totalday2 = totalday2 + 28;
		}
		count2++;
	}
	totalday1 = totalday1 + day1;
	totalday2 = totalday2 + day2;
	if (totalday1 > totalday2)return totalday1 - totalday2 - 1;
	else return totalday2 - totalday1 - 1;
}
/*#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

int between_days(struct node *date1head, struct node *date2head){
	if (date1head == NULL || date2head == NULL)
	{
		return - 1;
	}
	int d1=0, d2=0, m1=0, m2=0, y1=0, y2=0,count=1,i,res=0,t;
	struct node *temp1 = (node*)malloc(sizeof(struct node));
	struct node *temp2 = (node*)malloc(sizeof(struct node));
	temp1 = date1head;
	temp2 = date2head;
	i = 1;
	while (count <= 2)
	{
		d1 = d1 + temp1->data*pow(10.0, i);
		d2 = d2 + temp2->data*pow(10.0, i);
		temp1 = temp1->next;
		temp2 = temp2->next;
		i--;
		count++;
	}
	i = 1;
	count = 1;
	while (count <= 2)
	{
		m1 = m1 + temp1->data*pow(10.0, i);
		m2 = m2 + temp2->data*pow(10.0, i);
		temp1 = temp1->next;
		temp2 = temp2->next;
		i--;
		count++;
	}
	i = 3;
	count = 1;
	while (count <= 4)
	{
		y1 = y1 + temp1->data*pow(10.0, i);
		y2 = y2 + temp2->data*pow(10.0, i);
		temp1 = temp1->next;
		temp2 = temp2->next;
		i--;
		count++;
	}
	if (y1 == y2)
	{
		if (m1 == m2)
		{
			if (d1 == d2 || d1 - d2 == 1 || d2 - d1 == 1)
			{
				return 0;
			}
			else
			{
				if (d2 > d1)
				{
					res = d2 - d1 - 1;
				}
				else
				{
					res = d1 - d2 - 1;
				}
				return res;
			}
		}
		else
		{
			//t = m2 - m1;
			if (m1 - m2 != -1 || m1 - m2 != 1)
			{

			}
			if ((m2-m1==1)||m2-m1==-1)
			{
				if (m1 > m2)
				{
					res = (d1 - 1) + (31 - d2);
					//return res;
				}
				else if (m1 < m2)
				{
					res = (d2 - 1)+(31-d1);
					//return res;
				}
				return res;
			}
			else
			{ }
		}
	}
	else
	{
		if (y1 - y2 != -1 || y1 - y2 != 1)
		{
			if (y1 > y2)
			{
				t = y1 - y2 - 1;
			}
			else
			{
				t = y2 - y1 - 1;
			}
			res = t * 365;
			if (m1 == m2)
			{
				if (d1 == d2)
				{
					res = res + 365;
					return res;
				}
			}
			if (y1 > y2)
			{
				m1 = m1 + 12;
			}
			else if (y1<y2)
			{
				m2 = m2 + 12;
			}
			if (m1 - m2 == -1 || m1 - m2 == 1)
			{
				if (m1 > m2)
				{
					res = (d1 - 1) + (31 - d2);
					//return res;
				}
				else if (m1 < m2)
				{
					res = (d2 - 1) + (31 - d1);
					//return res;
				}
				return res;
			}
			else
			{
				if (m1 > m2)
				{
					t = m1 - m2 - 1;
				}
				else
				{
					t = m2 - m1 - 1;
				}
				res = t * 30.4;
				if (m1 > m2)
				{
					res = res + (d1 - 1) + (31 - d2);
					//return res;
				}
				else if (m1 < m2)
				{
					res = res + (d2 - 1) + (31 - d1);
					//return res;
				}
				return res;

			}

		}
		else
		{
			if (m1 > m2)
			{
				m1 = m1 + 12;
			}
			else
			{
				m2 = m2 + 12;
			}
			if (m1 - m2 == -1 || m1 - m2 == 1)
			{
				if (m1 > m2)
				{
					res = (d1 - 1) + (31 - d2);
					//return res;
				}
				else if (m1 < m2)
				{
					res = (d2 - 1) + (31 - d1);
					//return res;
				}
				return res;
			}
			else
			{
				if (m1 > m2)
				{
					t = m1 - m2 - 1;
				}
				else
				{
					t = m2 - m1 - 1;
				}
				res = t * 30.4;
				if (m1 > m2)
				{
					res = res+(d1 - 1) + (31 - d2);
					//return res;
				}
				else if (m1 < m2)
				{
					res = res+(d2 - 1) + (31 - d1);
					//return res;
				}
				return res;
				
			}
		}
	}
	return 0;
}*/