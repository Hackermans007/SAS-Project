#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct
{
    char title[50], descr[50], status[50];
    int id, stat, deadline;
} Task;

// Tableau pour stocker les tâches
Task tasks[100];
int count = 0;

void addtask()
{
    Task task;
    int n, i, stat, jours;

    do
    {
        printf("-------------- Entrez combien de tâches vous souhaitez ajouter : ---------------\n");

        if (scanf("%d", &n) == 1)
        {   
            if (n > 0)
            {
                for (i = 0; i < n; i++)
                {
                    task.id = count + 1;
                    printf("Tâche n° : %d\n", i + 1);
                    printf("------------------- Entrez le titre de la tâche : -------------------\n");
                    scanf("%s", task.title);
                    printf("------------------- Entrez la description de la tâche : -------------------\n");
                    scanf("%s", task.descr);
                    printf("Jours pour terminer la tâche : \n");
                    scanf("%d", &jours);
                    long long tmp = (long long)jours * 86400;
                    time_t tempactuell;
                    time(&tempactuell);
                    tmp += tempactuell;
                    task.deadline = tmp;

                    printf("------------------- Entrez l'état de la tâche : -------------------\n");
                    do
                    {
                        printf("1: À faire\n 2: En cours\n 3: Terminée\n");
                        if (scanf("%d", &stat) == 1)
                        {
                            if (stat >= 1 && stat <= 3)
                            {
                                switch (stat)
                                {
                                case 1:
                                    strcpy(task.status, "à réaliser");
                                    break;
                                case 2:
                                    strcpy(task.status, "en cours de réalisation");
                                    break;
                                case 3:
                                    strcpy(task.status, "finalisée");
                                    break;
                                }
                            }
                            else
                                printf("Choix invalide!!!!");
                        }
                        else
                        {
                            printf("Choix invalide\n");
                            while (getchar() != '\n')
                                ;
                        }

                    } while (stat < 1 || stat > 3);
                    tasks[count++] = task;
                }
            }
            else
                printf("Saisie invalide!!!");
        }
        else
            printf("Saisie invalide!!!\n");
        while (getchar() != '\n');
            
    } while (n <= 0);
}

void deleteTask()
{
    int taskId;

    printf("Entrez l'ID de la tâche à supprimer : ");

    if (scanf("%d", &taskId) == 1)
    {
        if (taskId >= 1 && taskId <= count)
        {
            for (int i = 0; i < count; i++)
            {
                if (tasks[i].id == taskId)
                {
                    for (int j = i; j < count - 1; j++)
                    {
                        tasks[j] = tasks[j + 1];
                    }
                    count--;
                    printf("Tâche supprimée avec succès.\n");
                    return;
                }
            }
        }
        else
            printf("Tâche avec l'ID %d non trouvée.!!!", taskId);
    }
    else
    {
        printf("Saisie invalide. Veuillez entrer un entier valide.\n");
        while (getchar() != '\n')
            ;
    }
}

void displaytasks()
{
    if (count > 0)
    {
        printf("----------------------------------------------------------------------\n");
        printf("--------------------- Vos tâches sont les suivantes -------------------\n");

        for (int i = 0; i < count; i++)
        {
            printf("**********************************************************************");

            printf("\n------------------- Tâche n° %d : -------------------", i + 1);
            printf("\n------------------- Titre de la tâche : %s -------------------", tasks[i].title);
            printf("\n------------------- Description : %s -------------------", tasks[i].descr);
            printf("\n------------------- État : %s -------------------", tasks[i].status);
            printf("\n------------------- ID : %d -------------------", tasks[i].id);
            printf("\n------------------- Date limite de la tâche -------------------");

            time_t temprestant = tasks[i].deadline - time(NULL);
            printf("\n------------------- La date limite de la tâche %d est dans %ld jours -------------------", i + 1, (long)(temprestant / 86400));
            printf("\n------------------- La date limite de la tâche %d est dans %ld heures -------------------", i + 1, (long)(temprestant / 3600));
            printf("\n********************************************************************");
        }
    }
    else
        printf("Vous n'avez aucune tâche\n");
}

void triagealpha()
{
    Task tmp;
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (strcmp(tasks[i].title, tasks[j].title) > 0)
            {
                tmp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = tmp;
            }
        }
    }
}

void triagedeadline()
{
    Task tmp;
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (tasks[i].deadline > tasks[j].deadline)
            {
                tmp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = tmp;
            }
        }
    }
}

void recherchetaskID()
{
    int id;
    printf("Entrez l'ID : ");
    if (scanf("%d", &id) == 1)
    {
        if (id > 0 && id <= count)
        {
            for (int i = 0; i < count; i++)
            {
                if (tasks[i].id == id)
                {
                    printf("**********************************************************************");
                    printf("\n------------------- Tâche n° %d : -------------------", i + 1);
                    printf("\n------------------- Titre de la tâche : %s -------------------", tasks[i].title);
                    printf("\n------------------- Description : %s -------------------", tasks[i].descr);
                    printf("\n------------------- État : %s -------------------", tasks[i].status);
                    printf("\n------------------- ID : %d -------------------", tasks[i].id);
                    printf("\n------------------- Date limite de la tâche -------------------");

                    time_t temprestant = tasks[i].deadline - time(NULL);
                    printf("\n------------------- La date limite de la tâche %d est dans %ld jours ---> %ld heures -------------------", i + 1, (long)(temprestant / 86400), (long)(temprestant / 3600));

                    printf("\n********************************************************************");
                }
            }
        }
        else
            printf("Aucune tâche avec l'ID %d!!!\n", id);
    }
    else
    {
        printf("Saisie incorrecte!!!!");
        while (getchar() != '\n')
            ;
    }
}

void recherchetaskTitle()
{
    char tit[20];

    do
    {
        printf("Entrez le titre : ");
        if (scanf("%s", tit) == 1)
        {
            for (int i = 0; i < count; i++)
            {
                if (strcmp(tasks[i].title, tit) == 0)
                {
                    printf("**********************************************************************");

                    printf("\n------------------- Tâche n° %d : -------------------", i + 1);
                    printf("\n------------------- Titre de la tâche : %s -------------------", tasks[i].title);
                    printf("\n------------------- Description : %s -------------------", tasks[i].descr);
                    printf("\n------------------- État : %s -------------------", tasks[i].status);
                    printf("\n------------------- ID : %d -------------------", tasks[i].id);
                    printf("\n------------------- Date limite de la tâche -------------------");

                    time_t temprestant = tasks[i].deadline - time(NULL);
                    printf("\n------------------- La date limite de la tâche %d est dans %ld jours ---> %ld heures -------------------", i + 1, (long)(temprestant / 86400), (long)(temprestant / 3600));

                    printf("\n********************************************************************");
                    return;
                }
            }
            printf("Aucune tâche avec le titre '' %s '' trouvée", tit);
            return;
        }
        else
        {
            printf("Saisie incorrecte!!!!");
            while (getchar() != '\n')
                ;
        }
    } while (1);
}

void modifyalltask()
{
    int n, stat, ID, days;
    do
    {
        printf("Entrez l'ID de la tâche : ");
        if (scanf("%d", &n) == 1)
        {
            if (n > 0 && n <= count)
            {
                for (int i = 0; i < count; i++)
                {
                    if (tasks[i].id == n)
                    {
                        printf("------------------- Entrez le titre de la tâche : -------------------\n");
                        scanf("%s", tasks[i].title);
                        printf("------------------- Entrez la description de la tâche : -------------------\n");
                        scanf("%s", tasks[i].descr);
                        do
                        {
                            printf("Entrez l'ID de la tâche : ");
                            if (scanf("%d", &ID) == 1)
                            {
                                if (ID >= 1 && ID <= count)
                                {
                                    for (int i = 0; i < count; i++)
                                    {
                                        if (tasks[i].id == ID)
                                        {
                                            printf("Entrez la nouvelle date limite en jours : \n");
                                            scanf("%d", &days);
                                            long long tmp = (long long)days * 86400;
                                            time_t tempactuell;
                                            time(&tempactuell);
                                            tmp += tempactuell;
                                            tasks[i].deadline = tmp;
                                            printf("\n Voilà !! \n");
                                            return;
                                        }
                                    };
                                }
                                else
                                {
                                    printf("Aucune tâche avec l'ID saisi!!!!\n");
                                }
                            }
                            else
                            {
                                printf("Saisie incorrecte!!!!\n");
                                while (getchar() != '\n')
                                    ;
                            }
                        } while (ID < 1 || ID > count);
                        do
                        {
                            printf("------------------- Entrez l'état de la tâche : -------------------\n");
                            printf("1: À faire\n 2: En cours\n 3: Terminée\n");
                            if (scanf("%d", &stat) == 1)
                            {
                                if (stat >= 1 && stat <= 3)
                                {
                                    switch (stat)
                                    {
                                    case 1:
                                        strcpy(tasks[i].status, "à réaliser");
                                        break;
                                    case 2:
                                        strcpy(tasks[i].status, "en cours de réalisation");
                                        break;
                                    case 3:
                                        strcpy(tasks[i].status, "finalisée");
                                        break;
                                    }
                                }
                                else
                                    printf("Choix invalide!!!!");
                            }
                            else
                            {
                                printf("Choix invalide\n");
                                while (getchar() != '\n')
                                    ;
                            }
                        }
                        while (1);
                    }
                }
            }
            else
                printf("ID %d inexistant", n);
        }
        else
            printf("Saisie incorrecte!!!");
        while (getchar() != '\n')
            ;
    } while (n < 1 || n > count);
}

void modifytitle()
{
    int n;
    do
    {
        printf("Entrez l'ID de la tâche : ");
        if (scanf("%d", &n) == 1)
        {
            if (n > 0 && n <= count)
            {
                for (int i = 0; i < count; i++)
                {
                    if (tasks[i].id == n)
                    {
                        printf("------------------- Entrez le titre de la tâche : -------------------\n");
                        scanf("%s", tasks[i].title);
                        break;
                    }
                }
            }
            else
            {
                printf("Aucune tâche existante avec l'ID %d ", n);
                return;
            }
        }
        else
        {
            printf("Saisie incorrecte!!!!");
            while (getchar() != '\n')
                ;
        }
    } while (n < 1 || n > count);
}

void modifydescription()
{
    int n;
    do
    {
        printf("Entrez l'ID de la tâche : ");
        if (scanf("%d", &n) == 1)
        {
            if (n > 0 && n <= count)
            {
                for (int i = 0; i < count; i++)
                {
                    if (tasks[i].id == n)
                    {
                        printf("------------------- Entrez la description de la tâche : -------------------\n");
                        scanf("%s", tasks[i].descr);
                        break;
                    }
                }
            }
            else
            {
                printf("Aucune tâche existante avec l'ID %d", n);
                return;
            }
        }
        else
        {
            printf("Choix invalide!!!");
            while (getchar() != '\n')
                ;
        }
    } while (n < 1 || n > count);
}

void modifystatus()
{
    int n, d;
    do
    {
        printf("Entrez l'ID de la tâche : ");
        if (scanf("%d", &n) == 1)
        {
            if (n > 0 && n <= count)
            {
                for (int i = 0; i < count; i++)
                {
                    if (tasks[i].id = n)
                    {
                        printf("------------------- Entrez l'état de la tâche : -------------------\n");
                        if (scanf("%d", &d) == 1)
                        {
                            if (d < 1 || d > 3)
                                printf("Saisie incorrecte");
                            else
                            {
                                switch (d)
                                {
                                case 1:
                                    strcpy(tasks[i].status, "à réaliser");
                                    break;

                                case 2:
                                    strcpy(tasks[i].status, "en cours de réalisation");
                                    break;

                                case 3:
                                    strcpy(tasks[i].status, "finalisée");
                                    printf("\n");
                                    break;

                                default:
                                    break;
                                }
                            }
                            break;
                        }
                        else
                        {
                            printf("Saisie incorrecte!!");
                            while (getchar() != '\n')
                                ;
                        }
                    }
                }
            }
            else
            {
                printf("Aucune tâche existante avec l'ID %d", n);
                return;
            }
        }
        else
        {
            printf("Saisie incorrecte!!!");
            while (getchar() != '\n')
                ;
        }
    } while (n <= 0 || n >= count);
}

void modifydeadline()
{
    int ID, days;
    do
    {
        printf("Entrez l'ID de la tâche : ");
        if (scanf("%d", &ID) == 1)
        {
            if (ID >= 1 && ID <= count)
            {
                for (int i = 0; i < count; i++)
                {
                    if (tasks[i].id == ID)
                    {
                        printf("Entrez la nouvelle date limite en jours : \n");
                        scanf("%d", &days);
                        long long tmp = (long long)days * 86400;
                        time_t tempactuell;
                        time(&tempactuell);
                        tmp += tempactuell;
                        tasks[i].deadline = tmp;
                        printf("\n Voilà !! \n");
                        return;
                    }
                };
            }
            else
            {
                printf("Aucune tâche avec l'ID saisi!!!!\n");
            }
        }
        else
        {
            printf("Saisie incorrecte!!!!\n");
            while (getchar() != '\n')
                ;
        }
    } while (ID < 1 || ID > count);
}

void Dline3jours()
{
    int i;

    for (i = 0; i < count; i++)
    {
        time_t temprestant = tasks[i].deadline - time(NULL);
        if (temprestant <= 259200)
        {
            printf("\n----------------  Date limite de la tâche ID %d dans %ld jours -- %ld heures         ---------------- \n", i + 1, (long)(temprestant / 86400), (long)(temprestant / 3600));
            printf("\n------------------- Titre de la tâche : %s      -------------------", tasks[i].title);
            printf("\n------------------- Description : %s     -------------------", tasks[i].descr);
            printf("\n------------------- État : %s          -------------------\n", tasks[i].status);
        }
    }
}

void todo_done()
{
    int countdon = 0, countundone = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(tasks[i].status, "finalisée") == 0)
            countdon++;
        else
        {
            countundone++;
        }
    }

    printf("Nombre de tâches complètes : %d\n", countdon);
    printf("Nombre de tâches incomplètes : %d\n", countundone);
    printf("*************************************\n");
    printf("*************************************\n");
    printf("*************************************\n");
}

int main()
{
    int casse;
    do
    {
        printf("\n                   --------------Bienvenue--------------\n");

        printf("\n                            Pour ajouter des tâches, appuyez sur 1\n ");
        printf("\n                            Pour afficher les tâches, appuyez sur 2\n                                   (***)\n");
        printf("\n                            Pour modifier les tâches, appuyez sur 3\n                                  (*****)\n");
        printf("\n                            Pour les statistiques : appuyez sur 4 : \n");
        printf("\n                            Pour rechercher par ID, appuyez sur 5\n");
        printf("\n                            Pour rechercher par titre, appuyez sur 6\n");
        printf("\n                            Pour supprimer, appuyez sur 7\n");
        printf("\n                            Pour quitter, appuyez sur 0\n ");
        scanf("%d", &casse);

        switch (casse)
        {

        case 1:
            addtask();
            break;

        case 2:
            int choi;
            printf("1- Trier les tâches par ordre alphabétique\n");
            printf("2- Trier les tâches par date limite\n");
            printf("3- Afficher les tâches dont la date limite est dans 3 jours ou moins\n");
            scanf("%d", &choi);
            switch (choi)
            {
            case 1:
                triagealpha();
                displaytasks();
                break;
            case 2:
                triagedeadline();
                displaytasks();
                break;
            case 3:
                Dline3jours();
                break;
            default:
                break;
            }
            break;

        case 3:
            int d;
            do
            {
                printf("Pour modifier tous les aspects de la tâche, appuyez sur 1\n");
                printf("Pour modifier la description de la tâche, appuyez sur 2 : \n");
                printf("Pour modifier l'état de la tâche, appuyez sur 3 : \n");
                printf("Pour modifier le titre de la tâche, appuyez sur 4 : \n");
                printf("Pour modifier la date limite, appuyez sur 5");

                scanf("%d", &d);
                switch (d)
                {
                case 1:
                    modifyalltask();
                    break;
                case 2:
                    modifydescription();
                    break;
                case 3:
                    modifystatus();
                    break;
                case 4:
                    modifytitle();
                case 5:
                    modifydeadline();
                    break;
                default:
                    break;
                }
            } while (d <= 0 || d > 5);
            break;

        case 4:
            printf("*************************************\n");
            printf("*************************************\n");
            printf("*************************************\n");
            printf("Nombre total de tâches : %d \n", count);
            todo_done();
            break;
        case 5:
            recherchetaskID();
            break;
        case 6 :
        recherchetaskTitle();
            break;

        case 7:
            deleteTask();
            break;
        case 0:
            break;
        default:
            printf("Entrée invalide");
            while (getchar() != '\n')
                ;
            break;
        }
    } while (casse != 0);

    return 0;
}






