#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct UserInfo {
    char name[100];
    int age;
    int score;
};
void getUserInfo( struct UserInfo* user) {
    printf("Enter your name: ");
    gets(user->name);
    printf("Enter your age: ");
    scanf("%d", &user->age);
}
void saveUserInfo(struct UserInfo* user) {
    FILE* file ;
	file= fopen("user_info.txt", "w");
	if (file != NULL) {
        fprintf(file, "Name: %s\nAge: %d\nScore: %d\n", user->name, user->age, user->score);
        fclose(file);
    } else 
        printf("Error opening file");
}
int generateMathProblem() 
{   int num1 = rand() % 100;
    int num2 = rand() % 100;
    int operator = rand() % 4;
    int answer;
    switch (operator) 
	{   case 0:
            printf("What is %d + %d?\n", num1, num2);
            answer = num1 + num2;
            break;
        case 1:
            printf("What is %d - %d?\n", num1, num2);
            answer = num1 - num2;
            break;
        case 2:
            printf("What is %d * %d?\n ", num1, num2);
            answer = num1 * num2;
            break;
        case 3:
            printf("What is %d / %d?\n", num1, num2);
            answer = num1 / num2;
            break;
    }
    int userAnswer;
    scanf("%d", &userAnswer);
    if (userAnswer == answer) {
        printf("Correct!\n");
        return 1;
    } else {
        printf("Sorry, that's incorrect. The answer was %d.\n", answer);
        return 0;
    }
}
int main() {
	srand(time(NULL));
     struct UserInfo user;
    getUserInfo(&user);
    int correctAnswers = 0;
    int totalQuestions = 0;
 char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') {
        if (generateMathProblem()) 
		{
            correctAnswers++;
        }
        totalQuestions++;
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    }
    user.score = correctAnswers;
    saveUserInfo(&user);
    printf("Thanks for playing ! Your final score is %d/%d.", correctAnswers, totalQuestions);
return 0;
}
