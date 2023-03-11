#include <gtest/gtest.h>
#include <iostream>
using namespace std;
extern "C"
{
    #include "../list/list.h"
    #include "../list/stack/stack.h"
    #include "../list/queue/queue.h"
    #include "../list/hashtable/hashtable.h"
}

/*
Test list_h
*/
//create_list()
TEST(createlistcase, createlist){
    cout<< "<<Test create_list>>: Start\n"; 
    list_t* new_list=NULL;
    new_list=create_list(new_list);
    EXPECT_NE(new_list,nullptr);
    EXPECT_EQ(new_list->prev,new_list);
    EXPECT_EQ(new_list->next,new_list);
}

//list_add_head()
TEST(listaddheadcase, listaddhead){
    cout<< "<<Test list_add_head>>: Start\n";
    list_t* new_list=NULL;
    new_list=create_list(new_list);
    list_t *node1=MALLOC_LIST()
    list_add_head(&new_list,node1);
    EXPECT_EQ(new_list,node1);
}

//list_add_tail()
TEST(listaddtailcase, listaddtail){
    cout<< "<<Test list_add_tail>>: Start\n";
    list_t* new_list=NULL;
    new_list=create_list(new_list);
    list_t *node1=MALLOC_LIST()
    list_add_tail(new_list,node1);
    EXPECT_EQ(new_list->prev,node1);
    EXPECT_EQ(new_list, node1->next);
}

//list_remove_head()
TEST(listremoveheadcase,listremovehead){
    cout<< "<<Test list_remove_head>>: Start\n";
    list_t* new_list=NULL;
    new_list=create_list(new_list);
    list_t *node1=MALLOC_LIST()
    list_add_tail(new_list,node1);
    list_t *temp=new_list->next;
    list_remove_head(&new_list);
    EXPECT_EQ(new_list,temp);
}

//list_remove_tail()
TEST(listremovetailcase,listremovetail){
    cout<< "<<Test list_remove_tail>>: Start\n";
    list_t* new_list=NULL;
    new_list=create_list(new_list);
    list_t *node1=MALLOC_LIST()
    list_t *node2=MALLOC_LIST()
    list_add_tail(new_list,node1);
    list_add_tail(new_list,node2);
    list_t *temp=new_list->prev->prev;
    list_remove_tail(&new_list);
    EXPECT_EQ(new_list,temp->next);
}

//free_list()
TEST(freelistcase,freelist){
    cout<< "<<Test free_list>>: Start\n";
    list_t* new_list=NULL;
    new_list=create_list(new_list);
    list_t *node1=MALLOC_LIST()
    list_t *node2=MALLOC_LIST()
    list_add_tail(new_list,node1);
    list_add_tail(new_list,node2);
    free_list(&new_list);
    EXPECT_EQ(new_list,nullptr);
}

/*
Test mul_stack_t
*/
//create_stack()
TEST(createstackcase,createstack){
    cout<< "<<Test create_stack>>: Start\n"; 
    mul_stack_t *stack=NULL;
    stack=create_stack(stack,10);
    EXPECT_NE(stack,nullptr);
    EXPECT_EQ(stack->capacity,10);
    EXPECT_EQ(stack->insert, list_add_tail);
    EXPECT_EQ(stack->remove,list_remove_tail);
    EXPECT_EQ(stack->count,0);
}

//push()
TEST(pushcase,push){
    cout<< "<<Test push>>: Start\n"; 
    mul_stack_t *stack=NULL;
    stack=create_stack(stack,10);
    push(stack);
    EXPECT_NE(stack->top,nullptr);
    EXPECT_EQ(stack->count,1);
    push(stack);
    push(stack);
    EXPECT_EQ(stack->count,3);
    push(stack);
    push(stack);
    EXPECT_EQ(stack->count,5);
}

//pop()
TEST(popcase,pop){
    cout<< "<<Test pop>>: Start\n"; 
    mul_stack_t *stack=NULL;
    stack=create_stack(stack,10);
    push(stack);
    push(stack);
    pop(stack);
    EXPECT_EQ(stack->count,1);
    push(stack);
    pop(stack);
    EXPECT_EQ(stack->count,1);
    push(stack);
    push(stack);
    pop(stack);
    EXPECT_EQ(stack->count,2);
}

//free_stack()
TEST(freecase,freestack){
    cout<< "<<Test free_stack>>: Start\n"; 
    mul_stack_t *stack=NULL;
    stack=create_stack(stack,10);
    push(stack);
    push(stack);
    pop(stack);
    push(stack);
    pop(stack);
    push(stack);
    push(stack);
    pop(stack);
    free_stack(&stack);
    EXPECT_EQ(stack,nullptr);
    stack=create_stack(stack,10);
    push(stack);
    push(stack);
    free_stack(&stack);
    EXPECT_EQ(stack,nullptr);
}

/*
Test mul_queue_t
*/
//create_queue()
TEST(createqueuecase,createqueue){
    cout<< "<<Test create_queue>>: Start\n"; 
    mul_queue_t *queue=NULL;
    queue=create_queue(queue,10);
    EXPECT_NE(queue,nullptr);
    EXPECT_EQ(queue->counter,0);
    EXPECT_EQ(queue->capacity,10);
    EXPECT_EQ(queue->enqueue,list_add_tail);
    EXPECT_EQ(queue->dequeue,list_remove_head);
}

//enqueue()
TEST(enqueuecase, enqueue){
    cout<< "<<Test enqueue>>: Start\n"; 
    mul_queue_t *queue=NULL;
    queue=create_queue(queue,10);
    enqueue(queue);
    EXPECT_NE(queue->list,nullptr);
    EXPECT_EQ(queue->counter,1);
    enqueue(queue);
    EXPECT_EQ(queue->counter,2);
    enqueue(queue);
    EXPECT_EQ(queue->counter,3);
}

//dequeue()
TEST(dequeuecase, dequeue){
    cout<< "<<Test dequeue>>: Start\n"; 
    mul_queue_t *queue=NULL;
    queue=create_queue(queue,10);
    enqueue(queue);
    enqueue(queue);
    dequeue(&queue);
    EXPECT_EQ(queue->counter,1);
    dequeue(&queue);
    EXPECT_EQ(queue->counter,0);
}

//free_queue()
TEST(freequeuecase,freequeue){
    cout<< "<<Test free_queue>>: Start\n"; 
    mul_queue_t *queue=NULL;
    queue=create_queue(queue,10);
    enqueue(queue);
    enqueue(queue);
    dequeue(&queue);
    dequeue(&queue);
    free_queue(&queue);
    EXPECT_EQ(queue,nullptr);
    queue=create_queue(queue,10);
    enqueue(queue);
    dequeue(&queue);
    free_queue(&queue);
    EXPECT_EQ(queue,nullptr);
}

/*
Test mul_hash_t
*/
//create_hash_table()
TEST(createhashtablecase,createhashtable){
    cout<< "<<Test create_hash_table>>: Start\n";
    mul_hash_t *hash=create_hash_table(77);
    EXPECT_NE(hash,nullptr);
    int i=0;
    for(i=0;i<HASH_TABLE_SIZE;i++){
        EXPECT_EQ(hash[i].key,-1);
        EXPECT_EQ(hash[i].count,0);
    } 
}

//pack_hash_data()
TEST(packhashdatacase, packhashdata){
    mul_hash_t *hash=create_hash_table(77);
    mul_hash_data_t *hash_data1=pack_hash_data(hash,127);
    EXPECT_EQ(hash_data1->hashtable,hash);
    EXPECT_EQ(hash_data1->value,127);
    mul_hash_data_t *hash_data2=pack_hash_data(hash,50);
    EXPECT_EQ(hash_data2->hashtable,hash);
    EXPECT_EQ(hash_data2->value,50);
    mul_hash_data_t *hash_data3=pack_hash_data(hash,50);
    EXPECT_EQ(hash_data3->hashtable,hash);
    EXPECT_EQ(hash_data3->value,50);
}

//insert_hash()
TEST(inserthashcase,inserthash){
    mul_hash_t *hash=create_hash_table(77);
    mul_hash_data_t *hash_data1=pack_hash_data(hash,127);
    mul_hash_data_t *hash_data2=pack_hash_data(hash,50);
    mul_hash_data_t *hash_data3=pack_hash_data(hash,50);
    mul_hash_data_t *hash_data4=pack_hash_data(hash,50);
    mul_hash_data_t *hash_data5=pack_hash_data(hash,22);
    insert_hash(hash_data1);
    EXPECT_EQ(hash[50].key,127);
    EXPECT_EQ(hash[50].count,1);
    insert_hash(hash_data2);
    insert_hash(hash_data3);
    EXPECT_EQ(hash[50].count,3);
    insert_hash(hash_data4);
    insert_hash(hash_data5);
    EXPECT_EQ(hash[22].count,1);
    EXPECT_EQ(hash[50].count,4);
}

//delete_hash()
TEST(deletehashcase,deletehash){
    mul_hash_t *hash=create_hash_table(77);
    mul_hash_data_t *hash_data1=pack_hash_data(hash,127);
    mul_hash_data_t *hash_data2=pack_hash_data(hash,50);
    mul_hash_data_t *hash_data3=pack_hash_data(hash,50);
    mul_hash_data_t *hash_data4=pack_hash_data(hash,50);
    insert_hash(hash_data1);
    insert_hash(hash_data2);
    insert_hash(hash_data3);
    delete_hash(hash_data4);
    EXPECT_EQ(hash[50].count,2);
}