cmake_minimum_required(VERSION 3.19)
project(data_structure_source_code)

set(CMAKE_CXX_STANDARD 14)


add_executable(static_locate 第一章_线性表/顺序表/静态分配.cpp)
add_executable(dynamic_locate 第一章_线性表/顺序表/动态分配.cpp)
add_executable(sequence_insert 第一章_线性表/顺序表/插入操作.cpp)
add_executable(sequence_delete 第一章_线性表/顺序表/删除操作.cpp)
add_executable(find_element_by_position 第一章_线性表/顺序表/按位查找.cpp )
add_executable(find_element_by_value 第一章_线性表/顺序表/按值查找.cpp)