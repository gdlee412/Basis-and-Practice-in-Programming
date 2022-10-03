#include <stdio.h>
#include <string.h>

struct node {
	char country[80];
	char country_code[3];
	int totalCases;
	int totalDeaths;
	struct node * NextPtr;
};

// This function takes a pointer to a linked list as parameter, and calculate the length (i.e. number of node) in the linked list as return value.
int Length(node * chain)
{
	int cnt = 0;
	while(chain != NULL){
		chain = chain->NextPtr;
		cnt++;
	}
	return cnt;
}

// This function takes a pointer to a linked list as parameter, and then print out all the data in the linked list. This function does not have any return value.
void PrintALL(node * chain) 
{	
	while(chain != NULL){
		printf("Country: %s; Country code: %s\nTotal Cases: %d\nTotal Deaths: %d\n", chain->country, chain->country_code, chain->totalCases, chain->totalDeaths);
		chain = chain->NextPtr;
	}
	printf("\n");
}

// This function takes a pointer to a linked list and a character string as input, and then find if there ia any node that matches the country_code with the 
// character string. The function returns a pointer pointing to the node if a match is found, and returns 0 if no found.
node * Find(node * chain, char * input)
{	
	while(chain != NULL){
		if(strcmp(chain->country_code, input) == 0)	return chain;
		chain = chain->NextPtr;
	}
	return 0;
}

int main(void)
{	node chain[500];			// The linked list!
	node * maxTotalCases=0;		// A pointer pointing at the node with max total infection cases
	node * maxTotalDeaths=0;	// A pointer pointing at the node with max total death cases
	node * head=&chain[0];		// A pointer pointing at the first node of the linked list
	
	int cases, deaths, day = 0, j = 0;
	char cnt_c_code[3]="?", cnt_c[80], trash[100];

	FILE *fptr = fopen("covid-19.csv", "r");
	if(j == 0) {
		fscanf(fptr, "%s %s %s %d %d", trash, &chain[j].country_code, &chain[j].country, &chain[j].totalCases, &chain[j].totalDeaths);
	}
	for(int i=0; !feof(fptr); i++){
		fscanf(fptr, "%s %s %s %d %d", trash, cnt_c_code, cnt_c, &cases, &deaths);
		if(strcmp(chain[j].country_code, cnt_c_code)) { //국가 코드가 바뀔 때, 새 노드 생성
			strcpy(chain[j+1].country_code, cnt_c_code);
			strcpy(chain[j+1].country, cnt_c);
			chain[j+1].totalCases = cases;
			chain[j+1].totalDeaths = deaths;
			chain[j+1].NextPtr = NULL;
			chain[j].NextPtr = &chain[j+1];
			j++;
		} else { //안 바뀌면 그대로 
			chain[j].totalCases += cases;
			chain[j].totalDeaths += deaths;
		}
	}
	fclose(fptr);
	
	maxTotalCases = head;
	maxTotalDeaths = head;
	int max_c = -999, max_d = -999;
	while(head != NULL){
		if(head->totalCases > max_c){
			max_c = head->totalCases;
			maxTotalCases = head;
		}
		if(head->totalDeaths > max_d){
			max_d = head->totalDeaths;
			maxTotalDeaths = head;
		}
		head = head->NextPtr;
	}
	
	printf("There are %d countries in the data.\n",Length(chain));		// Display number of countries
	printf("Max Total Cases: %s %d\n",maxTotalCases->country,maxTotalCases->totalCases);		// Display country with maximum total infection cases
	printf("Max Total Deaths: %s %d\n",maxTotalDeaths->country,maxTotalDeaths->totalDeaths);	// Display country with maximum total death cases
		
	char Input[4];
	while(strcmp(Input,"q"))		// A loop asking for user input, and then display the corresponding data
	{	printf("===============================\n");
		printf("Enter the country code to display the total number of cases and total number of death of the country.\n");
		printf("Enter \"ALL\" to display all data.\n");
		printf("Enter (q to quit): ");
		scanf("%s",Input);
		
		if(!strcmp(Input, "q"))	break; //q가 눌리면 종료하기 위한 코드 (수정해도 된다고 교수님께 허락 받았습니다!)		
		if(!strcmp(Input,"ALL"))	// Display all data in the linked list
			PrintALL(chain);
		else
		{	node * ResultPtr = Find(chain,Input);
			if (ResultPtr == 0)		// Country code not found in the linked list
				printf("Country Code not found!\n");
			else					// Country code found, display data of that country
				printf("Country: %s; Country code: %s\nTotal Cases: %d\nTotal Deaths: %d\n",ResultPtr->country,ResultPtr->country_code,ResultPtr->totalCases,ResultPtr->totalDeaths);
		}
	}

	return 0;
}
