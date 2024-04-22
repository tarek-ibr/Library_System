cmake_minimum_required(VERSION 3.26)
project(project)

set(CMAKE_CXX_STANDARD 17)

add_executable(project main.cpp
        Book.cpp
        Book.h
        Member.cpp
        Custom_String_Class.cpp
        Custom_String_Class.h
        Librarian.cpp
        User.h
        Loan.cpp
        Loan.h
        json.h
        Date.cpp
        Date.h
        Functionalities.h
        Functionalities.cpp
)
