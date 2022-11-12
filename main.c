#include "Header.h"

node* start;
enum state LR;
int data_array[500];

void *sorter(void *params); /* thread that performs basic sorting algorithm */
void *merger(void *params); /* thread that performs merging of results */
void initialize_list(node** list); /* Initialize the struct */
int Add_data(node** start, char* data);
void * create_new_node(node* root, char* data, enum state LR);
void print_tree(node** start);

int main(void) {
    const char* input_file_name = "IntegerList.txt";
    const char* output_file_name = "SortedIntegerList.txt";
    char* token;
    int count=0;

    /*Check argument number*/
    if (fopen_s(&input, input_file_name, "r") != 0)
    {
        printf("Error opening file >%s< \n", input_file_name);
        getchar();
        return -1;
    }
    fopen_s(&output, output_file_name, "w");
    initialize_list(&start); /* Initialize the struct */

    /*
	-File exists and is open, read the input and record.
	-Stop at End of file
	*/
    fgets(Input_str, Max_Len, input);
    token = strtok(Input_str,",");
    data_array[count++] = atoi(token);
    while(token != NUL){
        token = (NULL,",");
        data_array[count++] = atoi(token);
    }
    if((count+1)%2==0){

    }
    /* thread identifier*/
    pthread_t thread_sorter1, thread_sorter2, thread_merge;
    parameters *data = (parameters *) malloc(sizeof(parameters));

    //data->starting_index = N1;
    //data->ending_index = N2;
    /* create the first sorting thread */
    pthread_create(&thread_sorter1, NULL, sorter, data);
    /* create the second sorting thread */
    pthread_create(&thread_sorter2, NULL, sorter, data);
    /* now wait for the 2 sorting threads to finish */
    pthread_join(thread_sorter1,NULL);
    pthread_join(thread_sorter2,NULL);
    /* create the merge thread */
    pthread_create(&thread_merge, NULL, merger, data);
    /* wait for the merge thread to finish */
    pthread_join(thread_merge,NULL);
    /* output the sorted array */

    fclose(input);
    fclose(output);
    return 0;
}

void *sorter(void *params){
    /* sorting algorithm implementation */
    return NULL;
}

void *merger(void *params){
    /* merging algorithm implementation */
    return NULL;
}

void initialize_list(node** list)
{
    /* List is empty */
    *list = NULL;
}

//int Add_Data(node** start, char* data)
//{
//    /*
//    - Set the root of tree
//    - Compare the data and store them in sorted
//    - Create link list to store all the data in binary tree structure
//    The ideas and most of the code been taught by Dr. Larry Hughes
//    */
//
//    // Initialize the local varaiable
//    node* root;
//    int boolean;
//
//    // Set the position
//    root = *start;
//
//    // link list is empty, set first word as root
//    if (root->data == NULL) {
//        /*
//        - Create node, copy data into new node
//        - Initialize the content of left and right
//        - Update starting address
//        */
//        root = malloc(sizeof(node));
//        strcpy_s(root->data, Max_Len, data);
//        root->left = NULL;
//        root->right = NULL;
//        root->count = 1;
//        *start = root;
//        return True;
//    }
//
//    // Compare the current root with new word been get
//    boolean = _strcmpi(root->data, data);
//    if (boolean > 0) {
//        // New word is smaller than the root
//        // Check the left of root whether exist a word or not
//        // If yes, go to the next left node
//        if (root->left != NULL) {
//            Add_Data(&root->left, data);
//        }
//            // If not, create a node at left of current node
//        else {
//            create_new_node(root, data, left);
//        }
//    }
//        // New word is bigger than the root
//    else if (boolean < 0) {
//        // Check the right of root whether exist a word or not
//        // If yes, go to the next right node
//        if (root->right != NULL) {
//            Add_Data(&root->right, data);
//        }
//            // If not, create a node at right of current node
//        else {
//            create_new_node(root, data, right);
//        }
//    }
//        // If same word appear, increment the count number
//    else { root->count++; }
//}
//
//void * create_new_node(node* root, char* data, enum state LR)
//{
//    /*
//    Function will create a new node
//    Initialize the node
//    Copy the current word to node structure
//    Store the address of new node into previous structure
//    */
//
//    node* new_node;
//    /* Create new entry */
//    new_node = malloc(sizeof(node));
//    if (new_node == NULL)
//    {
//        /* No heap space */
//        return False;
//    }
//    // Store the current word to node structure
//    // Initialize the whole structure of the node
//    strcpy_s(new_node->data, Max_Len, data);
//    new_node->left = NULL;
//    new_node->right = NULL;
//    new_node->count = 1;
//    // Store new address to previous node structure
//    if (LR == left) { root->left = new_node; }
//    else { root->right = new_node; }
//}
//
//void print_tree(node** start)
//{
//    /* Print out the content of binary tree */
//
//    // Initialize the local variable
//    node* root;
//    root = *start;
//
//    // Check the root whether going to the further left
//    // if yes, print it out, if no going to next left node
//    // After check the left, check the right exist word or not
//    // if yes print it out, if no going to the next right node
//    if (root->left != NULL)
//    {
//        print_tree(&root->left);
//    }
//    while (root->count >= 1) {
//        printf("%s\n", root->data);
//        root->count--;
//    }
//
//    if (root->right != NULL)
//    {
//        print_tree(&root->right);
//    }
//}