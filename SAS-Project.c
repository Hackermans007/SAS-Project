#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct
{
    char title[50], descr[50], status[50];
    int id, stat, deadline;
} Task;

// tableux to store tasks
Task tasks[100];
int count = 0;

void addtask()
{
    Task task;
    int n, i, stat, jours;

    do
    {
        printf("--------------enter how many tasks you want to add : ---------------\n");

        if (scanf("%d", &n) == 1)
        {
            if (n > 0)
            {

                for (i = 0; i < n; i++)
                {

                    task.id = count + 1;
                    printf("Task n° :%d\n", i + 1);
                    printf("-------------------enter task Title : -------------------\n");
                    scanf("%s", task.title);
                    printf("-------------------enter task description : -------------------\n");
                    scanf("%s", task.descr);
                    printf("Days to complet the task : \n");
                    scanf("%d", &jours);
                    long long tmp = (long long)jours * 86400;
                    time_t tempactuell;
                    time(&tempactuell);
                    tmp += tempactuell;
                    task.deadline = tmp;

                    printf("-------------------enter task status : -------------------\n");
                    do
                    {
                        printf("1: To do\n 2: doing\n 3: done\n");
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
                                    strcpy(task.status, "en cours de réalisati");
                                    break;
                                case 3:
                                    strcpy(task.status, "finalisée");
                                    break;
                                }
                            }
                            else
                                printf("invalid choise!!!!");
                        }
                        else
                        {
                            printf("Invalid choise\n");
                            while (getchar() != '\n')
                                ;
                        }

                    } while (stat < 1 && stat > 3);
                    tasks[count++] = task;
                }
            }
            else
                printf("Invalid input!!!");
        }
        else
            printf("Invalid input!!!\n");
        while (getchar() != '\n')
            ;
    } while (n <= 0);
}
//***************************************************************************************
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
            printf("task ID %d non trouvé.!!!", taskId);
    }
    else
    {

        printf("Invalid input. Please enter a valid integer.\n");

        while (getchar() != '\n')
            ;
    }

    
}
//**********************************************************************************************

//*********************************************************************************************
void displaytasks()
{
    if(count>0){
    printf("----------------------------------------------------------------------\n");
    printf("---------------------         Your tasks are       -------------------\n");

    for (int i = 0; i < count; i++)
    {
        printf("**********************************************************************");

        printf("\n-------------------         Task n° %d :         -------------------", i + 1);
        printf("\n-------------------         Task title : %s      -------------------", tasks[i].title);
        printf("\n-------------------         Description : %s     -------------------", tasks[i].descr);
        printf("\n-------------------         Status : %s          -------------------", tasks[i].status);
        printf("\n-------------------         id is %d             -------------------", tasks[i].id);
        printf("\n-------------------         task deadline        -------------------");

        time_t temprestant = tasks[i].deadline - time(NULL);
        printf("\n-------------------  task %d deadline is in %ld days ---> %ld hrs.-------------------", i + 1, (long)(temprestant / 86400), (long)(temprestant / 3600));

        printf("\n********************************************************************");
    }
    }else printf("you have no tasks\n");
}
//**********************************************************************************************
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
//**************************NEEDS TO BE CHANGED TO DEISPLAY TASK INFO*************************//
void recherchetaskID()
{
    int id;
    printf("enter ID  : ");
    if (scanf("%d", &id) == 1)
    {
        if (id > 0 && id <= count)
        {
            for (int i = 0; i < count; i++)
            {
                if (tasks[i].id == id)
                {
                    printf("task is in position %d\n", i);
                }
            }
        }
        else
            printf("No task with ID %d!!!\n",id);
    }
    else
    {
        printf("wrong input!!!!");
        while (getchar() != '\n')
            ;
    }
}

void recherchetaskTitle()
{
    char tit[20];

    do
    {
        printf("enter title : ");
        if (scanf("%s", tit) == 1)
        {
            for (int i = 0; i < count; i++)
            {
                if (strcmp(tasks[i].title, tit) == 0)
                {
                    printf("task position is %d", i);
                    return;
                }
            }
            printf("no task with '' %s '' title is found", tit);
            return;
        }
        else
        {
            printf("invalid inputt!!!!");
            while (getchar() != '\n')
                ;
        }
    } while (1);
}
//*********************************************************************************************//
//-----------------------------
void modifyalltask()
{

    int n, stat , ID ,days;
    do
    {
        printf("enter task id : ");
        if (scanf("%d", &n) == 1)
        {
            if (n > 0 && n <= count)
            {
                for (int i = 0; i < count; i++)
                {
                    if (tasks[i].id == n)
                    {
                        printf("-------------------enter task Title : -------------------\n");
                        scanf("%s", tasks[i].title);
                        printf("-------------------enter task description : -------------------\n");
                        scanf("%s", tasks[i].descr);
                        do
                        {
                            printf("enter Task id : ");
                            if (scanf("%d", &ID) == 1)
                            {
                                if (ID >= 1 && ID <= count)
                                {
                                    for (int i = 0; i < count; i++)
                                    {
                                        if (tasks[i].id == ID)
                                        {
                                            printf("enter Task new deadline in dyas : \n");
                                            scanf("%d", &days);
                                            long long tmp = (long long)days * 86400;
                                            time_t tempactuell;
                                            time(&tempactuell);
                                            tmp += tempactuell;
                                            tasks[i].deadline = tmp;
                                            printf("\n Voila !! \n");
                                            return;
                                        }
                                    };
                                }
                                else
                                {
                                    printf("No task with entered ID!!!!\n");
                                }
                            }
                            else
                            {
                                printf("wrong input!!!!\n");
                                while (getchar() != '\n')
                                    ;
                            }
                        } while (ID < 1 && ID > count) ;
                        do
                        {
                            printf("-------------------enter task status : -------------------\n");
                            printf("1: To do\n 2: doing\n 3: done\n");
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
                                        strcpy(tasks[i].status, "en cours de réalisati");
                                        break;
                                    case 3:
                                        strcpy(tasks[i].status, "finalisée");
                                        break;
                                    }
                                }
                                else
                                    printf("invalid choise!!!!");
                            }
                            else
                            {
                                printf("Invalid choise\n");
                                while (getchar() != '\n')
                                    ;
                            }
                        }
                        while (1)
                            ;
                    }
                }
            }
            else
                printf("ID %d not existing", n);
        }
        else
            printf("wrong ipunt!!!");
        while (getchar() != '\n')
            ;
    } while (n < 1 && n > count);
}
void modifytitle()
{

    int n;
    do
    {
        printf("enter task id : ");
        if (scanf("%d", &n) == 1)
        {
            if (n > 0 && n <= count)
            {
                for (int i = 0; i < count; i++)
                {
                    if (tasks[i].id == n)
                    {

                        printf("-------------------enter task Title : -------------------\n");
                        scanf("%s", tasks[i].title);

                        break;
                    }
                }
            }
            else
            {
                printf("No existing task with ID %d ", n);
                return;
            }
        }
        else
        {
            printf("wrong input!!!!");
            while (getchar() != '\n')
                ;
        }
    } while (n < 1 && n > count);
}
void modifydescription()
{

    int n;
    do
    {
        printf("enter task id : ");
        if (scanf("%d", &n) == 1)
        {
            if (n > 0 && n <= count)
            {

                for (int i = 0; i < count; i++)
                {
                    if (tasks[i].id == n)
                    {

                        printf("-------------------enter task description : -------------------\n");
                        scanf("%s", tasks[i].descr);

                        break;
                    }
                }
            }
            else
            {
                printf("no existing task with ID %d", n);
                return;
            }
        }
        else
        {
            printf("invalid choise!!!");
            while (getchar() != '\n')
                ;
        }
    } while (n < 1 && n > count);
}
void modifystatus()
{

    int n, d;

    do
    {
        printf("enter task id : ");
        if (scanf("%d", &n) == 1)
        {
            if (n > 0 && n <= count)
            {

                for (int i = 0; i < count; i++)
                {
                    if (tasks[i].id = n)
                    {

                        printf("-------------------enter task status : -------------------\n");
                        if (scanf("%d", &d) == 1)
                        {
                            if (d < 1 || d > 3)
                                printf("Wrong input");
                            else
                            {
                                switch (d)
                                {
                                case 1:
                                    strcpy(tasks[i].status, "à réaliser");
                                    break;

                                case 2:
                                    strcpy(tasks[i].status, "en cours de réalisati");
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
                            printf("wrong input!!");
                            while (getchar() != '\n')
                                ;
                        }
                    }
                }
            }
            else
            {
                printf("no existing task with ID %d", n);
                return;
            }
        }
        else
        {
            printf("invalid input!!!");
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
        printf("enter Task id : ");
        if (scanf("%d", &ID) == 1)
        {
            if (ID >= 1 && ID <= count)
            {
                for (int i = 0; i < count; i++)
                {
                    if (tasks[i].id == ID)
                    {
                        printf("enter Task new deadline in dyas : \n");
                        scanf("%d", &days);
                        long long tmp = (long long)days * 86400;
                        time_t tempactuell;
                        time(&tempactuell);
                        tmp += tempactuell;
                        tasks[i].deadline = tmp;
                        printf("\n Voila !! \n");
                        return;
                    }
                };
            }
            else
            {
                printf("No task with entered ID!!!!\n");
            }
        }
        else
        {
            printf("wrong input!!!!\n");
            while (getchar() != '\n')
                ;
        }
    } while (ID < 1 && ID > count);
}

void Dline3jours(){
int i;

for(i=0;i<count;i++){

     time_t temprestant = tasks[i].deadline - time(NULL);
      if(temprestant<=259200){
        printf("\n-------------------            task ID %d deadline is %ld days -- %ld hrs         ------------------- \n",i+1 ,(long)(temprestant/86400) , (long)(temprestant/3600));
    }
    return;
}
printf("\n 0 tache dont le deadline est dans 3 jours ou moins!!\n");

}

//-----------------------------
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

    printf("le nombre de tâches complètes : %d\n", countdon);
    printf("le nombre de tâches incoplet : %d\n", countundone);
    printf("*************************************\n");
    printf("*************************************\n");
    printf("*************************************\n");
}
//-----------------------------



int main()
{
    int casse;
    do
    {
        printf("\n--------------Welcom Back----------\n");

        printf("\n        to add tasks press 1\n ");
        printf("\n         to display press 2\n               (***)\n");
        printf("\n       to modify task press 3\n              (*****)\n");
        printf("\n      for Statistiques : press 4 : \n");
        printf("\n       recherch par id press 5\n");
        printf("\n      recherch par title press 6\n");
        printf("\n          delete press 7\n");
        printf("\n          to exit press 0\n ");
        scanf("%d", &casse);

        switch (casse)
        {

        case 1:
            addtask();
            break;

        case 2:
            int choi;
            printf("1- Trier les taches par order alphabetique\n");
            printf("2- Trier les taches par deadline\n");
            printf("3- afficher les taches dont le deadline est dans 3 jours ou moins\n");
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

            break;

        case 3:
            int d;
            do
            {
                printf("to modify everything about the task press 1\n");
                printf("to modify task description press 2 : \n");
                printf("to modify task status press 3 : \n");
                printf("to modify task title press 4 : \n");
                printf("to modify deadline press 5");

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
            printf("total tasks : %d \n", count);
            todo_done();
            break;
        case 5:
            recherchetaskID();
            break;
        case 6:
            recherchetaskTitle();
            break;

        case 7:
            deleteTask();
            break;
        }
    } while (casse != 0);
}
