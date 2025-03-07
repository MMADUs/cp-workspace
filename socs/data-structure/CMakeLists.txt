cmake_minimum_required(VERSION 3.29)
project(fundamental C)

set(CMAKE_C_STANDARD 11)

# practice executable
add_executable(practice-test practice/test.c)
add_executable(practice-single-linked-list practice/linked-list.c)
add_executable(practice-double-linked-list practice/double-linked-list.c)
add_executable(practice-queue practice/queue.c)
add_executable(practice-stack practice/stack.c)
add_executable(practice-hash-table practice/hash-table.c)
add_executable(practice-bfs-tree practice/binary-search-tree.c)
add_executable(practice-linked-list practice/single-linked-list.c)
add_executable(practice-priority-queue practice/priority-queue.c)