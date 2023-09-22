#include<stdio.h>
#include<string.h>



typedef struct 
{
    char title[50],descr[50],status[50];
    int id,stat;
} Task;

// tableux to store tasks
Task tasks[100];
int count = 0 ;
void addtask(){
    Task task;
    int n , i, stat;
    printf("--------------enter how many tasks you want to add : ---------------\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
    task.id = count + 1 ;   
    printf("Task n° :%d\n",i+1);
    printf("-------------------enter task Title : -------------------\n");
    scanf("%s",task.title);
    printf("-------------------enter task description : -------------------\n");
    scanf("%s",task.descr);
    printf("-------------------enter task status : -------------------\n");
    do{
    printf("1: à réaliser\n 2: en cours de réalisation\n 3: finalisée\n");
    scanf("%d",&stat);
    if (stat < 1 || stat > 3) printf("Wrong\n");
    else {
        switch(task.stat){
        case 1 :  strcpy(task.status,"à réaliser"); 
            break;
        case 2 :  strcpy(task.status,"en cours de réalisati");
            break;
        case 3 :  strcpy(task.status,"finalisée\n");
            break;
        }
    }
    }while (stat<1 || stat>3);
    tasks[count++]=task;


    
}
}
void displaytasks(){
    
    printf("-------------------------------------------------------\n");
    printf("-------------------Your tasks are-------------------\n");
    
    for(int i = 0 ; i < count ; i++){
        printf("**********************************************");
        Task task = tasks[i];
        printf("\n-------------------Task n° %d : -------------------",i+1);
        printf("\n-------------------Task title : %s -------------------",task.title);
        printf("\n-------------------Description : %s -------------------",task.descr);
        printf("\n-------------------Status : %s -------------------",task.status);
        printf("\n-------------------id is %d -------------------",task.id );
        printf("\n**********************************************");    
    }

}


void sortalpha(){
Task tmp;
for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(tasks[i].title, tasks[j].title) > 0) {
                //Task temp = tasks[i];
                tmp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = tmp;
            }
        }
    }

}

void modifyalltask(){

    int n;
    printf("enter task id : ");
    scanf("%d",&n);
    for(int i=0;i<count;i++){
        if(tasks[i].id==n){
            printf("-------------------enter task Title : -------------------\n");
            scanf("%s",tasks[i].title);
            printf("-------------------enter task description : -------------------\n");
            scanf("%s",tasks[i].descr);
            printf("-------------------enter task status : -------------------\n");
            scanf("%s",tasks[i].status);
            
            }
        }
    
}

void modifytitle(){

    int n;
    printf("enter task id : ");
    scanf("%d",&n);
    Task task;
    for(int i=0;i<count;i++){
        if(tasks[i].id=n){
            printf("-------------------enter task Title : -------------------\n");
            scanf("%s",task.title);
            
            break;
            }
        }
    
}
void modifydescription(){

    int n;
    printf("enter task id : ");
    scanf("%d",&n);
    Task task;
    for(int i=0;i<count;i++){
        if(tasks[i].id=n){
            
            printf("-------------------enter task description : -------------------\n");
            scanf("%s",task.descr);
            
            break;
            }
        }
    
}
void modifystatus(){

    int n,stat;
    
    
    Task task;
    do
    {
    printf("enter task id : ");
    scanf("%d",&n);    
    
    for(int i=0;i<count;i++){
        if(tasks[i].id=n){
            printf("-------------------enter task status : -------------------\n");
            do{
                printf("1: à réaliser\n 2: en cours de réalisation\n 3: finalisée\n");
                scanf("%d",&stat);
                if (stat < 1 || stat > 3) printf("Wrong\n");
                else {
                switch(task.stat){
                case 1 :  strcpy(task.status,"à réaliser"); 
                        break;
                case 2 :  strcpy(task.status,"en cours de réalisati");
                        break;
                case 3 :  strcpy(task.status,"finalisée\n");
                        break;
        }
    }
    }while (stat<1 || stat>3);
            break;
            }
        }
    
    }while (n<=0 || n>=count);
}









int main(){
    int casse;
    do{
        printf("--------------hello----------\n");
        
        printf(" to add press 1\n ");
        printf("to display press 2\n");
        printf(" to modify task press 3\n ");
        printf("for Statistiques : press 4 : \n");
        printf(" to exit press 0\n ");
        scanf("%d",&casse);

    switch (casse)
    {
    case 1:
        addtask();
        break;
    case 2:
    int choise;
    printf("enter your choise");
    printf("\n display by id press 1 ");
    printf("\n display by alphab... press 2  ");
    
    scanf("%d",&choise);
    switch (choise)
    {

    case 1:
        displaytasks();
        break;
    
    case 2:
        sortalpha();
        displaytasks();
        break;
    
    }
    break;





    case 3:
    int d;
    printf("to modify task description press 1 : \n");
    printf("to modify task status press 2 : \n");
    printf("to modify task title press 3 : \n");
    
    scanf("%d",&d);
    switch (d)
    {
    case 1:
        modifytitle();
        break;
    case 2:
        modifystatus();
        break;
    case 3:
        modifystatus();
        break;
    
    default:
        break;
    }
    break;
    case 4:
        printf("total tasks : %d \n",count);

    break;
    }
    }while (casse !=0);
}
   
    


