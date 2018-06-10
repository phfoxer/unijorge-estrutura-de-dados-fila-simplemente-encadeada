#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "listLib.h"

main()
{
	char guessWord[100];
	printf("Qual a palavra chave?\n", guessWord);
	scanf("%[^\t\n]", &guessWord);
	hangmanGame(guessWord);
	system("pause");
	return 1;
}

hangmanGame(char word[100]){
	// Word size
	int len = strlen(word);
	// Set error occurrence
	int errosCount, correctCount = 0;

	// Current letter
	char currentLetter;
	//
	LIST_TYPE *myList;
	LIST_TYPE *myListAnswers;
	LIST_TYPE *myListConstant;
	
	myList = startPointer(); // Dinamic list
	myListAnswers = startPointer(); // Store leters
	myListConstant = startPointer(); // preserve original name

	int i;
	// Add the work key in list
	for (i = 0; i < len; i++)
	{
		int l = (word[i] - 0);
		insertIntoList(&myList, l);
		insertIntoList(&myListConstant, l);
	}
	int currentLetterInt;
	// You can be wrong six times
	while (errosCount < 7 && listEmpty(myList)==0)
	{
		system("@cls||clear");
		// 
		divider();
		printf("Letras que acertou: "); 
		correctLetters(myListAnswers,word);
		divider();
		printf("Letras utilizadas: "); listAllAnswers(myListAnswers);
		divider();
		scenes(errosCount);
		divider();
		if (errosCount < 6)
		{
			printf("Digite uma letra:\n", correctCount);
			scanf(" %c", &currentLetter);
			// Transforma o char em um inteiro equivalente na tabela ASCII
			// https://www.asciitable.com
			currentLetterInt = (currentLetter - 0);
		} else {
			myList = NULL;
		}

		// Verificar se a letra não foi encontrada
		if (
			searchItem(myListConstant, currentLetterInt) == 0 &&  // Verifica se a letra não existe na palavra original
			searchItem(myListAnswers, currentLetter) == 0 // verifica se a letra já foi utilizada
		)		
		{
			errosCount++;
		}
		else // Se encontrada:
		{
			// Incrementa acertos
			correctCount++;
			// remove todas as ocorrencias da letra que está correta
			for (i = 0; i < len; i++)
			{
				removeElement(&myList, currentLetterInt); // tenta remover o elemento N vezes pois pode ter mais de uma ocorrencia da letra
			}
		}
		// verifica se a letra inserida já foi inserida anteriormente
		if (searchItem(myListAnswers, currentLetter) == 0){
			// andiciona nova letra a lista de letras que já foram utilizadas
			insertIntoList(&myListAnswers, currentLetter);
		}
	}
	divider();
	printf("\nA palavra correta eh: %s",word);
	
}

void correctLetters(LIST_TYPE *list, char word[100]){
	// Tamanho da palavra

	int len = strlen(word);
	int i;

	LIST_TYPE *listAux;
	listAux = startPointer();
	listAux = list;
	while (listAux != NULL)
	{
		system("@cls||clear");
		for (i = 0; i < len; i++)
		{
			int letter = (word[i] - 0);
			if(searchItem(list, letter) == 0){
				printf("-");
			} else {
				printf("%c",word[i]);
			}
		}
		listAux = listAux->next;
	}
}

void listAllAnswers(LIST_TYPE *list)
{
	while (list != NULL)
	{
		printf("%c,", list->information);
		list = list->next;
	}
}

void scenes(int i)
{
	printf("\n_ _ _ _\n");
	if (i == 0)
	{
		printf("-----|-------\n");
		printf("-------------\n");
		printf("-------------\n");
		printf("-------------\n");
		printf("-------------\n");
		printf("-------------\n");
	}
	if (i == 1)
	{
		printf("-----|-------\n");
		printf("-----O-------\n");
		printf("-------------\n");
		printf("-------------\n");
		printf("-------------\n");
		printf("-------------\n");
	}
	if (i == 2)
	{
		printf("-----|-------\n");
		printf("-----O-------\n");
		printf("-----|-------\n");
		printf("-------------\n");
		printf("-------------\n");
		printf("-------------\n");
	}
	if (i == 3)
	{
		printf("-----|-------\n");
		printf("-----O-------\n");
		printf("----/|-------\n");
		printf("-------------\n");
		printf("-------------\n");
		printf("-------------\n");
	}
	if (i == 4)
	{
		printf("-----|-------\n");
		printf("-----O-------\n");
		printf("----/|-------\n");
		printf("----/--------\n");
		printf("-------------\n");
		printf("-------------\n");
	}
	if (i == 5)
	{
		printf("-----|-------\n");
		printf("-----O-------\n");
		printf("----/|\\------\n");
		printf("----/--------\n");
		printf("-------------\n");
		printf("-------------\n");
	}
	if (i == 6)
	{
		printf("-----|-------\n");
		printf("-----O-------\n");
		printf("----/|\\------\n");
		printf("----/-\\------\n");
		printf("-------------\n");
		printf("--Enforcado--\n");
		printf("-------------\n");
	}
}

void divider(){
printf("\n_______________________________________\n");
}
