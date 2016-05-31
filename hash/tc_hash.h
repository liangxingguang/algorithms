/*
 * =====================================================================================
 *
 *       Filename:  tc_hash.h
 *
 *    Description:  the code copied from tcpcopy project in github,
 *                  can see it on github when search tcpcopy
 *
 *        Version:  1.0
 *        Created:  2016年05月31日 22时47分30秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  liangxingguang (), liang_xing_guang@163.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef TC_HASH_INCLUDED
#define TC_HASH_INCLUDED


typedef struct hash_node_s {
    uint64_t key;
    uint32_t visit_cnt;
    time_t access_time;
    void *data;
}hash_node_t, hash_node;


typedef struct hash_table_s {
    uint32_t tatal;
    uint32_t size;
    uint64_t total_visit;
    uint64_t total_key_compared;
    int timeout;
    char name[64];
    link_list **lists;
}hash_table_t, hash_table;

hash_table *hash_create(size_t size);
inline link_list_t *get_link_list(hash_table *table, uint64_t key);
void hash_set_timeout(hash_table*, int);
bool hash_add(hash_table*, uint64_t, void *);
void *hash_find(hash_table*, uint64_t);
bool hash_del(hash_table*, uint);
void hash_destroy(hash_table*);
void hash_deep_destroy(hash_table *table);

#endif
