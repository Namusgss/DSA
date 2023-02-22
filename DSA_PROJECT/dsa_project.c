// hospital management system
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct node
{
    char name[100];
    int age;
    char address[100];
    int phone;
    char bloodgroup[100];
    int reg;
    int priority;
    struct node *next;
};
struct node *head = NULL;
struct node *insert(struct node *,int);
struct node *delete(struct node *);
void display(struct node * );
void table();
void print_disease(int);
int main()
{

    int option;
    do
    {
        system("COLOR 20");
        printf("\t\t\t-------------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t\t\t\t\t\n");
        printf("\t\t\t WELCOME TO MR NAMUS HOSPITAL!\n");
        printf("\t\t\t\t\t\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t\t\t\t\t\n");
        printf("\t\t\t-------------------------------\n");
        printf("\t\t\t1.ADD A PATIENT\n");
        printf("\t\t\t2.DELETE A RECORD\n");
        printf("\t\t\t3.DISPLAY ALL APPOINTMENTS\n");
        printf("\t\t\tEnter your choice:");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
             table();
            int priority;
            printf("\nPRIORITY FOR THE PATIENT CASE :");
            scanf("%d",&priority);
            head = insert(head,priority);
            getchar();
            system("cls");
            break;
        case 2:
            head = delete (head);
            getchar();
            system("cls");
            break;
        case 3:
            display(head);
            getchar();
            system("cls");
            break;
        case 4:
            exit(0);
            break;
        }
    } while (option != 4);
}
struct node *insert(struct node *head, int priority)
{
    struct node *newnode, *ptr;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter patient Name:");
    scanf(" %s", newnode->name);
    printf("Enter the patient's age:");
    scanf("%d", &newnode->age);
    printf("Enter your home address:");
    scanf(" %s", newnode->address);
    printf("Enter your phone number:");
    scanf("%d", &newnode->phone);
    printf("Enter the blood group of Patient:");
    scanf(" %s", newnode->bloodgroup);
    printf("Enter the reg no:");
    scanf("%d", &newnode->reg);
    table();
    printf("Enter your disease Number:");
    scanf("%d", &newnode->priority);
    if (head == NULL || priority < head->priority)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        //INSERTION AT THE END
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        newnode->next = NULL;
        ptr->next = newnode;
    }
    return head;
};
struct node *delete(struct node *head)
{
    struct node *newnode;
    if (head == NULL)
    {
        printf("\n NO PATIENT RECORD TO DELETE");
        return ;
    }
    else
    {
        newnode = head;
        printf("\n Deleted Record is : %d", newnode->reg);
        head = head->next;
        free(newnode);
    }
    return head;
};
void display(struct node *head)
{
    struct node *newnode;
    if (head == NULL)
        printf("\nTHERE IS NO PATIENT\n");
    else
    {
        newnode = head;
        printf("\nPRIORITY WISE APPOINTMENT ARE\n");
        while (newnode != NULL)
        {
            printf("The name of patient is:%s\n", newnode->name);
            printf("The age of patient is:%d\n", newnode->age);
            printf("The address of patient is : %s\n", newnode->address);
            printf("Phone Number:%d\n", newnode->phone);
            printf("The blood group of patient is:%s\n", newnode->bloodgroup);
            printf("Disease of the patient is :  ");
            print_disease(newnode->priority);
            printf("---------------------------------------------------\n");
            newnode = newnode->next;
        }
    }
    getchar();
}
void table()
{
    printf("\n\t\t\t ENTER THE DISEASE OF PATIENT!\n");
    printf("\t1.EMERGENCY CASE\n");
    printf("\t2.HEART ATTACK\n");
    printf("\t3.SEVERE WOUND/BLEEDING\n");
    printf("\t4.CANCER\n");
    printf("\t5.CHEST PAIN\n");
    printf("\t6.FRACTURE\n");
    printf("\t7.DIABETES CHECKUP\n");
    printf("\t8.INFECTION\n");
    printf("\t9.VIRAL FEVER\n");
    printf("\t10.COMMON COLD/HEAD ACHE\n");
}
void print_disease(int priority)
{
    switch (priority)
    {
    case 1:
        printf("EMERGENCY CASE\n");
        break;

    case 2:
        printf("HEART ATTACK\n");
        break;
    case 3:
        printf("SEVERE WOUND/BLEEDING\n");
        break;
    case 4:
        printf("CANCER\n");
        break;
    case 5:
        printf("CHEST PAIN\n");
        break;
    case 6:
        printf("FRACTURE\n");
        break;
    case 7:
        printf("\nDIABETES CHECKUP");
        break;
    case 8:
        printf("INFECTION\n");
        break;
    case 9:
        printf("VIRAL FEVER\n");
        break;
    case 10:
        printf("Common Cold/Head ache\n");
        break;
    default:
        exit(0);
    }
}
