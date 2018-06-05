#include <stdio.h>


int main () {

	int num_denominations, *coin_list, use_these[100], iterator, owed;
    time_t t;

    srand((unsigned) time(&t));

    //alocare dinamica memorie vector
	coin_list = calloc(num_denominations,sizeof(int));

    //citire numar de monede
    printf("Enter number of coins : ");
	scanf("%d", &num_denominations);

	printf("\nThe coins: ");

    //generare random a monedelor
	for(iterator=0; iterator< num_denominations; iterator++) {

		coin_list[iterator] = (rand() % 50) + 1;

		// use_these[i] = 0;
	}

	//functie care ordoneaza monedele descrescator
    insertion_sort(coin_list, num_denominations);

    for(iterator=0; iterator < num_denominations; iterator++)
		printf("%d ", coin_list[iterator]);

	printf("\nEnter the amount : ");
	scanf("%d", &owed);

	for(iterator=0; iterator < num_denominations; iterator++) {

        //se verifica de cate ori intra moneda i in suma,
        //efectuand catul impartirii
		use_these[iterator] = owed / coin_list[iterator];

        //se scade din suma valoarea monedei
		owed = owed % coin_list[iterator];
	}
    //afisarea solutiei
	printf("\nSolution: \n");

	for(iterator=0; iterator < num_denominations; iterator++) {

		printf("%d coins of %d\n", use_these[iterator], coin_list[iterator]);
	}
}
