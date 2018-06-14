cmake_minimum_required(VERSION 3.5)
project(shell)

set(CMAKE_CXX_STANDARD 14)

include_directories(antlr4-runtime/)

set(parser
    parser/generated/ShellParser.cpp
    parser/generated/ShellLexer.cpp
    parser/generated/ShellParserVisitor.cpp
    parser/Parser.cpp
    parser/Parser.h
    parser/Visitor.cpp
    parser/Visitor.h
    parser/ErrorListener.cpp
    parser/ErrorListener.h)

set(statements
    statements/Statement.h
    statements/Assignment.cpp
    statements/Assignment.h)

set(values
    values/Variable.cpp
    values/Variable.h
    values/Value.h
    values/Return.cpp
    values/Return.h
    values/Constant.cpp
    values/Constant.h)

set(runnables
    runnables/Runnable.cpp
    runnables/Runnable.h
    runnables/Command.cpp
    runnables/Command.h
    runnables/Process.cpp
    runnables/Process.h
    runnables/Pipe.cpp
    runnables/Pipe.h)

add_executable(shell main.cpp Shell.cpp Shell.h Environment.cpp Environment.h ${parser} ${statements} ${values} ${runnables})

target_link_libraries(shell "${PROJECT_SOURCE_DIR}/libs/libantlr4-runtime.so")

add_custom_command(TARGET shell POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${PROJECT_SOURCE_DIR}/libs/libantlr4-runtime.so"
    $<TARGET_FILE_DIR:shell>)