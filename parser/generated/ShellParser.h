
// Generated from ShellParser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  ShellParser : public antlr4::Parser {
public:
  enum {
    WHITESPACE = 1, COMMAND_TOKEN = 2, EXPORT_TOKEN = 3, VARIABLE_TOKEN = 4, 
    PATH_TOKEN = 5, QUOTE_STRING_TOKEN = 6, ARGUMENTS_WHITESPACE = 7, PIPE_TOKEN = 8, 
    BACK_QOUTE_TOKEN = 9, EQUALS_TOKEN = 10, VARIABLE_VALUE_TOKEN = 11, 
    RETURN_TOKEN = 12, INPUT_REDIRECTION_TOKEN = 13, OUTPUT_REDIRECTION_TOKEN = 14, 
    CONSTANT_TOKEN = 15
  };

  enum {
    RuleStatement = 0, RuleAssignment = 1, RuleValue = 2, RuleExportEnv = 3, 
    RuleRunnable = 4, RuleArguments = 5, RuleProcess = 6, RuleCommand = 7, 
    RulePipe = 8
  };

  ShellParser(antlr4::TokenStream *input);
  ~ShellParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class StatementContext;
  class AssignmentContext;
  class ValueContext;
  class ExportEnvContext;
  class RunnableContext;
  class ArgumentsContext;
  class ProcessContext;
  class CommandContext;
  class PipeContext; 

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AssignmentContext *assignment();
    ExportEnvContext *exportEnv();
    RunnableContext *runnable();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  AssignmentContext : public antlr4::ParserRuleContext {
  public:
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VARIABLE_TOKEN();
    antlr4::tree::TerminalNode *EQUALS_TOKEN();
    ValueContext *value();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentContext* assignment();

  class  ValueContext : public antlr4::ParserRuleContext {
  public:
    ValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> BACK_QOUTE_TOKEN();
    antlr4::tree::TerminalNode* BACK_QOUTE_TOKEN(size_t i);
    RunnableContext *runnable();
    antlr4::tree::TerminalNode *VARIABLE_VALUE_TOKEN();
    antlr4::tree::TerminalNode *RETURN_TOKEN();
    antlr4::tree::TerminalNode *CONSTANT_TOKEN();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ValueContext* value();

  class  ExportEnvContext : public antlr4::ParserRuleContext {
  public:
    ExportEnvContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXPORT_TOKEN();
    antlr4::tree::TerminalNode *VARIABLE_TOKEN();
    AssignmentContext *assignment();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExportEnvContext* exportEnv();

  class  RunnableContext : public antlr4::ParserRuleContext {
  public:
    RunnableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProcessContext *process();
    CommandContext *command();
    PipeContext *pipe();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RunnableContext* runnable();

  class  ArgumentsContext : public antlr4::ParserRuleContext {
  public:
    ArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgumentsContext* arguments();

  class  ProcessContext : public antlr4::ParserRuleContext {
  public:
    ProcessContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PATH_TOKEN();
    ArgumentsContext *arguments();
    antlr4::tree::TerminalNode *INPUT_REDIRECTION_TOKEN();
    antlr4::tree::TerminalNode *OUTPUT_REDIRECTION_TOKEN();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProcessContext* process();

  class  CommandContext : public antlr4::ParserRuleContext {
  public:
    CommandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMAND_TOKEN();
    ArgumentsContext *arguments();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CommandContext* command();

  class  PipeContext : public antlr4::ParserRuleContext {
  public:
    PipeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ProcessContext *> process();
    ProcessContext* process(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PIPE_TOKEN();
    antlr4::tree::TerminalNode* PIPE_TOKEN(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PipeContext* pipe();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

