cmake_minimum_required(VERSION 3.13)
project(algorithm_c C)

set(CMAKE_C_STANDARD 11)

include_directories(Aha_Algorithm)

add_executable(algorithm_c
        Aha_Algorithm/2-1-queue.c
        Aha_Algorithm/2-1-queue.h
        Aha_Algorithm/2-2-stack.c
        Aha_Algorithm/2-2-stack.h
        Aha_Algorithm/2-3-QueueAndStack.c
        Aha_Algorithm/2-3-QueueAndStack.h
        Aha_Algorithm/2-4-Link_List.c
        Aha_Algorithm/2-4-Link_List.h
        Aha_Algorithm/2-5-Simulation_Link.c
        Aha_Algorithm/2-5-Simulation_Link.h
        Aha_Algorithm/4-1-dfs.c
        Aha_Algorithm/4-1-dfs.h
        Aha_Algorithm/4-2-dfs_maze.c
        Aha_Algorithm/4-2-dfs_maze.h
        Aha_Algorithm/4-3-bfs_maze.c
        Aha_Algorithm/4-3-bfs_maze.h
        Aha_Algorithm/4-4-Bomb_man.c
        Aha_Algorithm/4-4-Bomb_man.h
        Aha_Algorithm/4-5-Island_Adventure.c
        Aha_Algorithm/4-5-Island_Adventure.h
        Aha_Algorithm/4-6-water_pip.c
        Aha_Algorithm/4-6-water_pip.h
        Aha_Algorithm/5-1-dfs_bfs.c
        Aha_Algorithm/5-1-dfs_bfs.h
        algorithm/base.c
        algorithm/binarySearch.c
        algorithm/bubbleSort.c
        algorithm/find_k.c
        algorithm/heapSort.c
        algorithm/insertSort.c
        algorithm/mergingSort.c
        algorithm/quickSort.c
        algorithm/selectSort.c
        algorithm/shellSort.c
        data_structure/adjacencyList.c
        data_structure/adjacencyListTest.c
        data_structure/adjacencyMatricTest.c
        data_structure/adjacencyMatrix.c
        data_structure/binaryLinkedList.c
        data_structure/binarySortTree.c
        data_structure/circularLinkedList.c
        data_structure/circularQueque.c
        data_structure/doubleLinkedList.c
        data_structure/linearLinkedList.c
        data_structure/linearQueue.c
        data_structure/linearStack.c
        data_structure/orthogonalList.c
        data_structure/queue.c
        data_structure/sequenceLinkedList.c
        data_structure/sequenceStack.c
        data_structure/test.c
        data_structure/threadedBinaryLikedList.c
        practice/practice.c
        main2.c data_structure2/linkList.h main.c)
