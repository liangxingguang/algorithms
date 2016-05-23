/*
 * =====================================================================================
 *
 *       Filename:  tc_link_list.h
 *
 *    Description:  this is copy from tcpcopy git
 *
 *        Version:  1.0
 *        Created:  2016年05月23日 23时02分33秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  liangxingguang (), liang_xing_guang@163.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef TC_LINK_LIST_INCLUDE
#define TC_LINK_LIST_INCLUDE

#include<stdlib.h>

//链表节点结构
typedef struct link_node_s {
    //前驱节点
    struct link_node_s *prev;
    //后继节点
    struct link_node_s *next;
    //数据指针
    void *data;
    uint32_t key;
} link_node_t, link_node, *p_link_node;

//链表结构
typedef struct link_list_s {
    int size;
    link_node head;
} link_list_t, link_list;


p_link_node link_node_malloc(void *data);
inline void link_node_internal_free(p_link_node p);

link_list *link_list_create();
int link_list_clear(link_list *l);
inline void link_list_append(link_List *l, p_link_node);
void link_list_append_by_order(link_list *l, p_link_node);

inline void link_list_push(link_list *l, p_link_node);
inline p_link_node link_list_remove(link_list *l, p_link_node node);
inline p_link_node list_list_first(link_list *l);
inline p_link_node list_list_tail(link_list *l);
inline p_link_node link_list_pop_frist(link_list *l);
inline p_link_node link_list_pop_tail(link_list *l);
inline p_link_node link_list_get_next(link_list *l, p_link_node p);
inline bool link_list_is_empty(link_list *l);
#endif

