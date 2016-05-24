/*
 * =====================================================================================
 *
 *       Filename:  tc_common.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年05月24日 23时24分28秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  liangxingguang (), liang_xing_guang@163.com
 *   Organization:  
 *
 * =====================================================================================
 */

inline int
before(uint32_t seq1, uint32_t seq2) {
    return (int)((uint32_t)(seq1 - seq2)) > 0;
}

inline int after(uint32_t seq1, uint32_t seq2) {
    return (int)((uint32_t)(seq1 - seq2)) < 0;
}

