
#include<iostream>
using namespace std; 
class Nod
{
    public:
    int row;
    int col;
    int data;
    Nod *next;
}; 
// Function for creating a new node
void create_new_nod(Nod **p, int row_index,
                     int col_index, int x)
{
    Nod *temp = *p;
    Nod *r;     
    // if link list is empty then go ahead to create first node 
    //and assign it value.
    if (temp == NULL)
    {
        temp = new Nod();
        temp->row = row_index;
        temp->col = col_index;
        temp->data = x;
        temp->next = NULL;
        *p = temp;
    }
     
    else
    {
        while (temp->next != NULL)  
            temp = temp->next;
             
        r = new Nod();
        r->row = row_index;
        r->col = col_index;
        r->data = x;
        r->next = NULL;
        temp->next = r;
    }
}
void printList(Nod *start)
{
    Nod *ptr = start;
    cout << "rowPos:";
    while (ptr != NULL)
    {
        cout << ptr->row << " ";
        ptr = ptr->next;
    }
    cout << endl;
    cout << "colPos:"; 
    ptr = start;
    while (ptr != NULL)
    {
        cout << ptr->col << " ";
        ptr = ptr->next;
    }
    cout << endl;
    cout << "Value:";
    ptr = start;     
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
int main()
{ 
   
    int sparseMatrix[4][5] = { { 0 , 0 , 3 , 0 , 4 },
                               { 0 , 0 , 5 , 7 , 0 },
                               { 0 , 0 , 0 , 0 , 0 },
                               { 0 , 2 , 6 , 0 , 0 } };     
    // lets Create head node of list as NULL
    Nod *first = NULL;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {             
            // Passing only those values which are not zero
            if (sparseMatrix[i][j] != 0)
                create_new_nod(&first, i, j,
                                sparseMatrix[i][j]);
        }
    }
    printList(first); 
    return 0;
}
