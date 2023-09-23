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
    do
    {
        printf("--------------enter how many tasks you want to add : ---------------\n");
        scanf("%d",&n);
    } while (n<=0 );
    
    
    for(i=0;i<n;i++){
    task.id = count + 1 ;   
    printf("Task n° :%d\n",i+1);
    printf("-------------------enter task Title : -------------------\n");
    scanf("%s",task.title);
    printf("-------------------enter task description : -------------------\n");
    scanf("%s",task.descr);
    printf("-------------------enter task status : -------------------\n");
    do{
    printf("1: To do\n 2: doing\n 3: done\n");
    scanf("%d",&stat);
    if (stat < 1 || stat > 3) printf("Invalid choise\n");
    else {
        switch(stat){
        case 1 :  strcpy(task.status,"à réaliser"); 
            break;
        case 2 :  strcpy(task.status,"en cours de réalisati");
            break;
        case 3 :  strcpy(task.status,"finalisée");
            break;
        }
    }
    }while (stat<1 || stat>3);
    tasks[count++]=task;


    
}
}

void deleteTask() {
    int taskId;
    printf("Entrez l'ID de la tâche à supprimer : ");
    scanf("%d", &taskId);

    for (int i = 0; i < count; i++) {
        if (tasks[i].id == taskId) {
            // Supprimez la tâche en la déplaçant vers la fin du tableau
            for (int j = i; j < count-1 ; j++) {
                tasks[j] = tasks[j + 1];
            }
            
            return;
            count--;
            printf("Tâche supprimée avec succès.\n");
            
        }
    }

    printf("ID de tâche non trouvé.\n");
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
//**************************
void recherchetaskID(){
    int id;
    printf("enter ID\n");
    scanf("%d",&id);
    for(int i=0;i<count;i++){
        if(tasks[i].id==id) {  printf("task is in position %d\n",i);
        }else printf("walo");
    }
}

void recherchetaskTitle(){
    char tit[20];
    printf("enter title");
    scanf("%s",tit);
    for(int i=0;i<count;i++){
        if(strcmp(tasks[i].title,tit)==0){
            printf("task position is %d",i);
        }
    }


}
//----------------------------
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
    //Task task ;
    for(int i=0;i<count;i++){
        if(tasks[i].id==n){
            printf("-------------------enter task Title : -------------------\n");
            scanf("%s",tasks[i].title);
            
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
//-----------------------------
void modifystatus(){

    int n,d;
    
    
    Task task;
    do
    {
    printf("enter task id : ");
    scanf("%d",&n);    
    
    for(int i=0;i<count;i++){
        if(tasks[i].id=n){
            
            printf("-------------------enter task status : -------------------\n");
            scanf("%d",&d);
            if(d<1 || d>3 ) printf("Wrong input");
            else{
                switch (d)
                {
                case 1:strcpy(task.status,"à réaliser");
                    break;
                
                case 2 :  strcpy(task.status,"en cours de réalisati");
                    break;
                
                case 3 :  strcpy(task.status,"finalisée");
                          printf("\n");
                    break;
                
                default:
                    break;
                }
            }
            break;
            }
        }
    
    }while (n<=0 || n>=count);
}

void todo_done(){

    Task task;
    int countdon = 0 , countundone=0 ;
    for(int i=0;i<count;i++){
        if(strcmp(tasks[i].status,"finalisée")==0)
        countdon++;
    else {
        if(strcmp(task.status,"finalisée")!=0)
         countundone++;
    }
    }

    
    printf("le nombre de tâches complètes : %d\n",countdon);
    printf("le nombre de tâches incoplet : %d",countundone);


}






int main(){
    int casse;
    do{
        printf("--------------hello----------\n");
        
        printf(" to add press 1\n ");
        printf("to display press 2\n");
        printf(" to modify task press 3\n ");
        printf("for Statistiques : press 4 : \n");
        printf(" recherch par id press 5\n");
        printf(" recherch par title press 6\n");
        printf(" delete press 7\n");
        printf(" to exit press 0\n ");
        scanf("%d",&casse);

    switch (casse) 
    {

    case 1:
        addtask();
        break;



    case 2:
    
        sortalpha();
        displaytasks();
        break;
    
    
    break;





    case 3:
    int d;
    do{
    printf("to modify everything about the task press 1\n");
    printf("to modify task description press 2 : \n");
    printf("to modify task status press 3 : \n");
    printf("to modify task title press 4 : \n");
    
    scanf("%d",&d);
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
    default:
        break;
    }
    }while(d<=0 || d>4);
    break;



    case 4:
    
        printf("total tasks : %d \n",count);
        todo_done();

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
}while (casse !=0);
}
    






 
