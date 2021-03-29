cmake_minimum_required(VERSION 3.13)
project(algorithm_c C)

set(CMAKE_C_STANDARD 99)

add_executable(algorithm_c main.c binaryLinkedList.c threadedBinaryLikedList.c adjacencyMatrix.c adjacencyList.c orthogonalList.c queue.c linearLinkedList.c sequenceLinkedList.c circularLinkedList.c doubleLinkedList.c sequenceStack.c linearStack.c circularQueque.c linearQueue.c)