cmake_minimum_required(VERSION 3.19)
project(data_structure_source_code)

set(CMAKE_CXX_STANDARD 14)


add_executable(static_locate 第一章_线性表/顺序表/静态分配.cpp)
add_executable(dynamic_locate 第一章_线性表/顺序表/动态分配.cpp)
add_executable(sequence_insert 第一章_线性表/顺序表/插入操作.cpp)
add_executable(sequence_delete 第一章_线性表/顺序表/删除操作.cpp)
add_executable(find_element_by_position 第一章_线性表/顺序表/按位查找.cpp )
add_executable(find_element_by_value 第一章_线性表/顺序表/按值查找.cpp)
add_executable(link_list_init 第一章_线性表/链表/单链表/初始化.cpp)
add_executable(link_list_insert 第一章_线性表/链表/单链表/链表插入.cpp)
add_executable(link_list_insert_before_after 第一章_线性表/链表/单链表/指定节点的前插后插操作.cpp)
add_executable(link_list_delete_by_position 第一章_线性表/链表/单链表/按位序删除.cpp)
add_executable(link_list_delete_by_point 第一章_线性表/链表/单链表/指定节点删除.cpp)
add_executable(link_list_find_by_position 第一章_线性表/链表/单链表/按位查找.cpp)
add_executable(double_link_list_find_init 第一章_线性表/链表/双链表/初始化.cpp)
add_executable(double_link_list_insert 第一章_线性表/链表/双链表/插入_删除_遍历.cpp)
add_executable(cyc_single_link_list_init 第一章_线性表/链表/循环链表/循环单链表/初始化.cpp)
add_executable(cyc_double_link_list_init 第一章_线性表/链表/循环链表/循环双链表/初始化.cpp)
add_executable(cyc_double_link_list_insert_delete 第一章_线性表/链表/循环链表/循环双链表/插入_删除.cpp)
add_executable(static_link_list_basic 第一章_线性表/链表/静态链表/静态链表基本操作.cpp)

