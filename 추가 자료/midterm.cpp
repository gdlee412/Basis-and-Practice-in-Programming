#include <stdio.h>

double s[80]={51700000, 0, };
double e[80], i[80], r[80];
int j, day;
double infected;

void printframe(void);
void result(void);
int choice(void);
void histo(char whatplot);

int main()
{
	result();
	return 0;
}

void printframe(){ //틀 출력  
	int a;
	printf("Day     S");
	printf("               ");
	printf("E");
	printf("               ");
	printf("I");
	printf("               ");
	printf("R          \n");
	for(a=0; a<67; a++)
		printf("=");
	printf("\n");
}

void result(){ //seir 모델 결과값 출력 
	double beta, sigma, gamma;
	printf("Enter the number of infected people in Day 0: ");
	scanf("%lf", &infected);
	printf("Enter the value of Beta (Transmission Rate): ");
	scanf("%lf", &beta);
	printf("Enter the value of Sigma (Incubation Rate): ");
	scanf("%lf", &sigma);
	printf("Enter the value of Gamma (Recovery Rate): ");
	scanf("%lf", &gamma);
	printf("How many days do you want to run the simulation: ");
	scanf("%d", &day);
	i[0] = infected; //기본 설정 
	
	for(j=0; j<day+1; j++){ //다음 날 거 계산 
		double stoe = beta*s[j]*i[j]/(51700000+infected);
		double etoi = sigma*e[j];
		double itor = gamma*i[j];
		s[j+1] = s[j]-stoe;
		if(s[j+1]<0) {
			s[j+1] = 0;
			e[j+1] = e[j]+s[j]-etoi; //인구가 stoe보다 적으니까 인구만큼만 빼줘야함  
		} else {
			e[j+1] = e[j]+stoe-etoi;
		}
		if(e[j+1]<0) {
			e[j+1] = 0;
			i[j+1] = i[j]+e[j]-itor;
		} else {
			i[j+1] = i[j]+etoi-itor;
		}
		if(i[j+1]<0) {
			i[j+1] = 0;
			r[j+1] = r[j]+i[j];
		} else {
			r[j+1] = r[j]+itor;
		}
		if(r[j+1]<0)	r[j+1]=0;
	}
	
	printframe();
	for(j=0; j<day+1; j++){
		if(j<10)	printf("Day %d:  %-16lf%-16lf%-16lf%-11lf\n", j,s[j],e[j],i[j],r[j]);
		else		printf("Day %d: %-16lf%-16lf%-16lf%-11lf\n", j,s[j],e[j],i[j],r[j]);
	}
	choice();
}

int choice(){ //선택의 시간  
	char plot, whatplot, again;
	printf("\nDo you want to plot the result [y/n]? ");
	scanf("  %s", &plot);
	while(plot != 'y' && plot != 'n'){ //plot 빙글빙글   
		printf("Input Error! Please enter [y/n].\n");
		printf("Do you want to plot the result [y/n]? ");
		scanf("  %s", &plot);
	}
	if(plot == 'y'){ //히스토그램 ㄱㄱ  
		printf("Which data would you like to plot? [s/e/i/r] ");
		scanf("  %s", &whatplot);
		//아랫줄은 어떤 플롯  빙글빙글 
		while(whatplot != 's' && whatplot != 'e' && whatplot != 'i' && whatplot != 'r'){
			printf("Input Error! Please enter [y/n].\n");
			printf("Which data would you like to plot? [s/e/i/r] ");
			scanf("  %s", &whatplot);
		}
		histo(whatplot);
	}
	else if(plot == 'n'){ //히스토그램 ㄴㄴ  
		printf("Do you want to run the simulation again [y/n]? ");
		scanf("  %s", &again);
		while(again != 'y' && again != 'n'){ //다시 돌릴래 빙글빙글  
			printf("Input Error! Please enter [y/n].\n");
			printf("Do you want to run the simulation again [y/n]? ");
			scanf("  %s", &again);
		}
		if(again == 'y'){
			printf("\n");
			result();
		} else if(again == 'n')	return 0;
	}
}

void histo(char whatplot){ //히스토그램 출력  
	double percentage;
	switch(whatplot) {
		case 's':
			for(j=0; j<day+1; j++){
				percentage = s[j]/(51700000+infected)*100;
				printf("Day %-4d(%d%%)	| ", j, (int)percentage);
				for(int k=0; k<(int)percentage; k++)	printf("*");
				printf("\n");
			}
			break;
		case 'e':
			for(j=0; j<day+1; j++){
				percentage = e[j]/(51700000+infected)*100;
				printf("Day %-4d(%d%%)	| ", j, (int)percentage);
				for(int k=0; k<(int)percentage; k++)	printf("*");
				printf("\n");
			}
			break;
		case 'i':
			for(j=0; j<day+1; j++){
				percentage = i[j]/(51700000+infected)*100;
				printf("Day %-4d(%d%%)	| ", j, (int)percentage);
				for(int k=0; k<(int)percentage; k++)	printf("*");
				printf("\n");
			}
			break;
		case 'r':
			for(j=0; j<day+1; j++){
				percentage = r[j]/(51700000+infected)*100;
				printf("Day %-4d(%d%%)	| ", j, (int)percentage);
				for(int k=0; k<(int)percentage; k++)	printf("*");
				printf("\n");
			}
			break;
	}
	choice(); 
}
