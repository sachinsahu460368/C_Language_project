#include <stdio.h>
#include <string.h>
int main()
{
    int roll_no[2][75];
    char answer_key[20][3], user_input[20][3], choice;
    int roll, count, search;
    int r = 1;
    printf(" ----Roll numbers are available----\n");
    // We must set scores to -1 so the report knows who hasn't played.
    for (int j = 0; j < 75; j++)
    {
        roll_no[0][j] = r; // Sets roll numbers 1-75
        roll_no[1][j] = -1;
        r = r + 1;
    }
    printf("Enter the anwey key answers : ");
    for (int i = 0; i < 20; i++)
    {
        scanf("%2s", answer_key[i]);
    }
    do
    {
        count = 0;
        printf("Enter the student roll no ");
        scanf("%d", &roll);
        printf("Enter the user input: \n");
        for (int i = 0; i < 20; i++)
        {
            scanf("%2s", user_input[i]);
        }
        printf("   ----:Checking process start:---- \n");
        for (int i = 0; i < 20; i++)
        {
            if (strcmp(answer_key[i], user_input[i]) == 0)
            {
                count = count + 1;
            }
        }
        if (roll >= 1 && roll <= 75)
        {

            for (int j = 0; j < 75; j++)
            {
                if (roll_no[0][j] == roll)
                {
                    roll_no[1][j] = count;
                    printf("The student result out of 20 :%d is saved as roll no %d  ", count, roll);
                }
            }
        }
        else
        {
            printf("Roll no is not available ");
            printf("Enter roll no between 1 and 75");
        }
        printf("\nGrade another student? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');
    printf("\n\n--- FINAL SCORE REPORT ---\n");
    printf("ROLL NO\t| SCORE\n");
    for (int j = 0; j < 75; j++)
    {
        if (roll_no[1][j] != -1)
        {
            printf("%d\t| %d / 20\n", roll_no[0][j], roll_no[1][j]);
        }
    }
    do
    {
        printf("----Search the student score----\n");
        printf("Enter student roll no: ");
        scanf("%d", &search);
        if (search >= 1 && search <= 75)
        {
            if (roll_no[1][search - 1] != -1)
            {
                printf("RESULT FOUND:\n");
                printf("Roll No: %d | Score: %d / 20\n", roll_no[0][search - 1], roll_no[1][search - 1]);
            }
            else
            {
                printf("No score recorded for Roll No %d.\n", search);
            }
        }
        else
        {
            printf("Invalid Roll Number! Please enter a number between 1 and 75.\n");
        }
        printf("\nSearch another student? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    int max = 0;
    float sum = 0, students_who_took_test = 0;
    for (int j = 0; j < 75; j++)
    {
        if (roll_no[1][j] != -1)
        {
            if (roll_no[1][j] > max)
            {
                max = roll_no[1][j];
            }
            sum += roll_no[1][j];
            students_who_took_test++;
        }
    }
    printf("\n\n--- CLASS STATISTICS ---");
    if (students_who_took_test > 0)
    {
        printf("\nClass Average: %.2f / 20", sum / students_who_took_test);
        printf("\nHighest Score: %d / 20\n", max);
    }
    else
    {
        printf("\nNo test data available to calculate statistics.\n");
    }

    return 0;
}
