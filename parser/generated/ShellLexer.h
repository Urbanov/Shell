
// Generated from ShellLexer.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  ShellLexer : public antlr4::Lexer {
public:
  enum {
      WHITESPACE = 1, COMMAND_TOKEN = 2, VARIABLE_TOKEN = 3, PATH_TOKEN = 4,
      QUOTE_STRING_TOKEN = 5, PIPE_TOKEN = 6, BACK_QUOTE_TOKEN = 7, EQUALS_TOKEN = 8,
      VARIABLE_VALUE_TOKEN = 9, RETURN_TOKEN = 10, INPUT_REDIRECTION_TOKEN = 11,
      OUTPUT_REDIRECTION_TOKEN = 12, CONSTANT_TOKEN = 13
  };

  ShellLexer(antlr4::CharStream *input);
  ~ShellLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

