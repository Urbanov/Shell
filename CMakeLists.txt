cmake_minimum_required(VERSION 3.5)
project(shell)

set(CMAKE_CXX_STANDARD 14)

include_directories(antlr4-runtime/)

set(parser
    parser/generated/ShellParser.cpp
    parser/generated/ShellLexer.cpp
    parser/generated/ShellParserVisitor.cpp
    parser/Parser.cpp parser/Parser.h parser/Visitor.cpp parser/Visitor.h)

add_executable(shell main.cpp ${parser} Shell.cpp Shell.h Statement.cpp Statement.h Variable.cpp Variable.h Assignment.cpp Assignment.h Value.h Environment.cpp Environment.h Return.cpp Return.h Constant.cpp Constant.h Runnable.cpp Runnable.h Command.cpp Command.h Process.cpp Process.h Pipe.cpp Pipe.h)

target_link_libraries(shell "${PROJECT_SOURCE_DIR}/libs/libantlr4-runtime.so")

add_custom_command(TARGET shell POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/libs/libantlr4-runtime.so"
        $<TARGET_FILE_DIR:shell>)