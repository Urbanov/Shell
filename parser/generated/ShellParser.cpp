
// Generated from ShellParser.g4 by ANTLR 4.7.1


#include "ShellParserVisitor.h"

#include "ShellParser.h"


using namespace antlrcpp;
using namespace antlr4;

ShellParser::ShellParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ShellParser::~ShellParser() {
  delete _interpreter;
}

std::string ShellParser::getGrammarFileName() const {
  return "ShellParser.g4";
}

const std::vector<std::string>& ShellParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ShellParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- StatementContext ------------------------------------------------------------------

ShellParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ShellParser::AssignmentContext* ShellParser::StatementContext::assignment() {
  return getRuleContext<ShellParser::AssignmentContext>(0);
}

ShellParser::RunnableContext* ShellParser::StatementContext::runnable() {
  return getRuleContext<ShellParser::RunnableContext>(0);
}


size_t ShellParser::StatementContext::getRuleIndex() const {
  return ShellParser::RuleStatement;
}

antlrcpp::Any ShellParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShellParserVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

ShellParser::StatementContext* ShellParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 0, ShellParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(18);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ShellParser::VARIABLE_TOKEN: {
        enterOuterAlt(_localctx, 1);
        setState(16);
        assignment();
        break;
      }

      case ShellParser::COMMAND_TOKEN:
      case ShellParser::PATH_TOKEN: {
        enterOuterAlt(_localctx, 2);
        setState(17);
        runnable();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

ShellParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShellParser::AssignmentContext::VARIABLE_TOKEN() {
  return getToken(ShellParser::VARIABLE_TOKEN, 0);
}

tree::TerminalNode* ShellParser::AssignmentContext::EQUALS_TOKEN() {
  return getToken(ShellParser::EQUALS_TOKEN, 0);
}

ShellParser::ValueContext* ShellParser::AssignmentContext::value() {
  return getRuleContext<ShellParser::ValueContext>(0);
}


size_t ShellParser::AssignmentContext::getRuleIndex() const {
  return ShellParser::RuleAssignment;
}

antlrcpp::Any ShellParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShellParserVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

ShellParser::AssignmentContext* ShellParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 2, ShellParser::RuleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(20);
    match(ShellParser::VARIABLE_TOKEN);
    setState(21);
    match(ShellParser::EQUALS_TOKEN);
    setState(22);
    value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueContext ------------------------------------------------------------------

ShellParser::ValueContext::ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> ShellParser::ValueContext::BACK_QUOTE_TOKEN() {
  return getTokens(ShellParser::BACK_QUOTE_TOKEN);
}

tree::TerminalNode* ShellParser::ValueContext::BACK_QUOTE_TOKEN(size_t i) {
  return getToken(ShellParser::BACK_QUOTE_TOKEN, i);
}

ShellParser::RunnableContext* ShellParser::ValueContext::runnable() {
  return getRuleContext<ShellParser::RunnableContext>(0);
}

tree::TerminalNode* ShellParser::ValueContext::VARIABLE_VALUE_TOKEN() {
  return getToken(ShellParser::VARIABLE_VALUE_TOKEN, 0);
}

tree::TerminalNode* ShellParser::ValueContext::RETURN_TOKEN() {
  return getToken(ShellParser::RETURN_TOKEN, 0);
}

tree::TerminalNode* ShellParser::ValueContext::PATH_TOKEN() {
  return getToken(ShellParser::PATH_TOKEN, 0);
}

tree::TerminalNode* ShellParser::ValueContext::VARIABLE_TOKEN() {
  return getToken(ShellParser::VARIABLE_TOKEN, 0);
}

tree::TerminalNode* ShellParser::ValueContext::QUOTE_STRING_TOKEN() {
  return getToken(ShellParser::QUOTE_STRING_TOKEN, 0);
}

tree::TerminalNode* ShellParser::ValueContext::CONSTANT_TOKEN() {
  return getToken(ShellParser::CONSTANT_TOKEN, 0);
}


size_t ShellParser::ValueContext::getRuleIndex() const {
  return ShellParser::RuleValue;
}

antlrcpp::Any ShellParser::ValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShellParserVisitor*>(visitor))
    return parserVisitor->visitValue(this);
  else
    return visitor->visitChildren(this);
}

ShellParser::ValueContext* ShellParser::value() {
  ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, getState());
  enterRule(_localctx, 4, ShellParser::RuleValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(34);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ShellParser::BACK_QUOTE_TOKEN: {
        enterOuterAlt(_localctx, 1);
        setState(24);
        match(ShellParser::BACK_QUOTE_TOKEN);
        setState(25);
        runnable();
        setState(26);
        match(ShellParser::BACK_QUOTE_TOKEN);
        break;
      }

      case ShellParser::VARIABLE_VALUE_TOKEN: {
        enterOuterAlt(_localctx, 2);
        setState(28);
        match(ShellParser::VARIABLE_VALUE_TOKEN);
        break;
      }

      case ShellParser::RETURN_TOKEN: {
        enterOuterAlt(_localctx, 3);
        setState(29);
        match(ShellParser::RETURN_TOKEN);
        break;
      }

      case ShellParser::PATH_TOKEN: {
        enterOuterAlt(_localctx, 4);
        setState(30);
        match(ShellParser::PATH_TOKEN);
        break;
      }

      case ShellParser::VARIABLE_TOKEN: {
        enterOuterAlt(_localctx, 5);
        setState(31);
        match(ShellParser::VARIABLE_TOKEN);
        break;
      }

      case ShellParser::QUOTE_STRING_TOKEN: {
        enterOuterAlt(_localctx, 6);
        setState(32);
        match(ShellParser::QUOTE_STRING_TOKEN);
        break;
      }

      case ShellParser::CONSTANT_TOKEN: {
        enterOuterAlt(_localctx, 7);
        setState(33);
        match(ShellParser::CONSTANT_TOKEN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RunnableContext ------------------------------------------------------------------

ShellParser::RunnableContext::RunnableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ShellParser::ProcessContext* ShellParser::RunnableContext::process() {
  return getRuleContext<ShellParser::ProcessContext>(0);
}

ShellParser::CommandContext* ShellParser::RunnableContext::command() {
  return getRuleContext<ShellParser::CommandContext>(0);
}

ShellParser::PipeContext* ShellParser::RunnableContext::pipe() {
  return getRuleContext<ShellParser::PipeContext>(0);
}


size_t ShellParser::RunnableContext::getRuleIndex() const {
  return ShellParser::RuleRunnable;
}

antlrcpp::Any ShellParser::RunnableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShellParserVisitor*>(visitor))
    return parserVisitor->visitRunnable(this);
  else
    return visitor->visitChildren(this);
}

ShellParser::RunnableContext* ShellParser::runnable() {
  RunnableContext *_localctx = _tracker.createInstance<RunnableContext>(_ctx, getState());
  enterRule(_localctx, 6, ShellParser::RuleRunnable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(39);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(36);
      process();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(37);
      command();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(38);
      pipe();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

ShellParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ShellParser::ValueContext *> ShellParser::ArgumentsContext::value() {
  return getRuleContexts<ShellParser::ValueContext>();
}

ShellParser::ValueContext* ShellParser::ArgumentsContext::value(size_t i) {
  return getRuleContext<ShellParser::ValueContext>(i);
}


size_t ShellParser::ArgumentsContext::getRuleIndex() const {
  return ShellParser::RuleArguments;
}

antlrcpp::Any ShellParser::ArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShellParserVisitor*>(visitor))
    return parserVisitor->visitArguments(this);
  else
    return visitor->visitChildren(this);
}

ShellParser::ArgumentsContext* ShellParser::arguments() {
  ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 8, ShellParser::RuleArguments);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(44);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(41);
        value(); 
      }
      setState(46);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcessContext ------------------------------------------------------------------

ShellParser::ProcessContext::ProcessContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShellParser::ProcessContext::PATH_TOKEN() {
  return getToken(ShellParser::PATH_TOKEN, 0);
}

ShellParser::ArgumentsContext* ShellParser::ProcessContext::arguments() {
  return getRuleContext<ShellParser::ArgumentsContext>(0);
}

tree::TerminalNode* ShellParser::ProcessContext::INPUT_REDIRECTION_TOKEN() {
  return getToken(ShellParser::INPUT_REDIRECTION_TOKEN, 0);
}

tree::TerminalNode* ShellParser::ProcessContext::OUTPUT_REDIRECTION_TOKEN() {
  return getToken(ShellParser::OUTPUT_REDIRECTION_TOKEN, 0);
}


size_t ShellParser::ProcessContext::getRuleIndex() const {
  return ShellParser::RuleProcess;
}

antlrcpp::Any ShellParser::ProcessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShellParserVisitor*>(visitor))
    return parserVisitor->visitProcess(this);
  else
    return visitor->visitChildren(this);
}

ShellParser::ProcessContext* ShellParser::process() {
  ProcessContext *_localctx = _tracker.createInstance<ProcessContext>(_ctx, getState());
  enterRule(_localctx, 10, ShellParser::RuleProcess);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(47);
    match(ShellParser::PATH_TOKEN);
    setState(48);
    arguments();
    setState(50);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ShellParser::INPUT_REDIRECTION_TOKEN) {
      setState(49);
      match(ShellParser::INPUT_REDIRECTION_TOKEN);
    }
    setState(53);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ShellParser::OUTPUT_REDIRECTION_TOKEN) {
      setState(52);
      match(ShellParser::OUTPUT_REDIRECTION_TOKEN);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommandContext ------------------------------------------------------------------

ShellParser::CommandContext::CommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShellParser::CommandContext::COMMAND_TOKEN() {
  return getToken(ShellParser::COMMAND_TOKEN, 0);
}

ShellParser::ArgumentsContext* ShellParser::CommandContext::arguments() {
  return getRuleContext<ShellParser::ArgumentsContext>(0);
}


size_t ShellParser::CommandContext::getRuleIndex() const {
  return ShellParser::RuleCommand;
}

antlrcpp::Any ShellParser::CommandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShellParserVisitor*>(visitor))
    return parserVisitor->visitCommand(this);
  else
    return visitor->visitChildren(this);
}

ShellParser::CommandContext* ShellParser::command() {
  CommandContext *_localctx = _tracker.createInstance<CommandContext>(_ctx, getState());
  enterRule(_localctx, 12, ShellParser::RuleCommand);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(55);
    match(ShellParser::COMMAND_TOKEN);
    setState(56);
    arguments();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PipeContext ------------------------------------------------------------------

ShellParser::PipeContext::PipeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ShellParser::ProcessContext *> ShellParser::PipeContext::process() {
  return getRuleContexts<ShellParser::ProcessContext>();
}

ShellParser::ProcessContext* ShellParser::PipeContext::process(size_t i) {
  return getRuleContext<ShellParser::ProcessContext>(i);
}

std::vector<tree::TerminalNode *> ShellParser::PipeContext::PIPE_TOKEN() {
  return getTokens(ShellParser::PIPE_TOKEN);
}

tree::TerminalNode* ShellParser::PipeContext::PIPE_TOKEN(size_t i) {
  return getToken(ShellParser::PIPE_TOKEN, i);
}


size_t ShellParser::PipeContext::getRuleIndex() const {
  return ShellParser::RulePipe;
}

antlrcpp::Any ShellParser::PipeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShellParserVisitor*>(visitor))
    return parserVisitor->visitPipe(this);
  else
    return visitor->visitChildren(this);
}

ShellParser::PipeContext* ShellParser::pipe() {
  PipeContext *_localctx = _tracker.createInstance<PipeContext>(_ctx, getState());
  enterRule(_localctx, 14, ShellParser::RulePipe);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(58);
    process();
    setState(61); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(59);
      match(ShellParser::PIPE_TOKEN);
      setState(60);
      process();
      setState(63); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == ShellParser::PIPE_TOKEN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> ShellParser::_decisionToDFA;
atn::PredictionContextCache ShellParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ShellParser::_atn;
std::vector<uint16_t> ShellParser::_serializedATN;

std::vector<std::string> ShellParser::_ruleNames = {
    "statement", "assignment", "value", "runnable", "arguments", "process",
    "command", "pipe"
};

std::vector<std::string> ShellParser::_literalNames = {
    "", "", "", "", "", "", "'|'", "'`'", "'='", "", "'$?'"
};

std::vector<std::string> ShellParser::_symbolicNames = {
    "", "WHITESPACE", "COMMAND_TOKEN", "VARIABLE_TOKEN", "PATH_TOKEN", "QUOTE_STRING_TOKEN",
    "PIPE_TOKEN", "BACK_QUOTE_TOKEN", "EQUALS_TOKEN", "VARIABLE_VALUE_TOKEN",
    "RETURN_TOKEN", "INPUT_REDIRECTION_TOKEN", "OUTPUT_REDIRECTION_TOKEN",
    "CONSTANT_TOKEN"
};

dfa::Vocabulary ShellParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ShellParser::_tokenNames;

ShellParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
      0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964,
      0x3, 0xf, 0x44, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9,
      0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4,
      0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x15,
      0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4,
      0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4,
      0x3, 0x4, 0x5, 0x4, 0x25, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5,
      0x5, 0x2a, 0xa, 0x5, 0x3, 0x6, 0x7, 0x6, 0x2d, 0xa, 0x6, 0xc, 0x6, 0xe,
      0x6, 0x30, 0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x35, 0xa,
      0x7, 0x3, 0x7, 0x5, 0x7, 0x38, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8,
      0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x6, 0x9, 0x40, 0xa, 0x9, 0xd, 0x9, 0xe,
      0x9, 0x41, 0x3, 0x9, 0x2, 0x2, 0xa, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe,
      0x10, 0x2, 0x2, 0x2, 0x48, 0x2, 0x14, 0x3, 0x2, 0x2, 0x2, 0x4, 0x16,
      0x3, 0x2, 0x2, 0x2, 0x6, 0x24, 0x3, 0x2, 0x2, 0x2, 0x8, 0x29, 0x3, 0x2,
      0x2, 0x2, 0xa, 0x2e, 0x3, 0x2, 0x2, 0x2, 0xc, 0x31, 0x3, 0x2, 0x2, 0x2,
      0xe, 0x39, 0x3, 0x2, 0x2, 0x2, 0x10, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x12,
      0x15, 0x5, 0x4, 0x3, 0x2, 0x13, 0x15, 0x5, 0x8, 0x5, 0x2, 0x14, 0x12,
      0x3, 0x2, 0x2, 0x2, 0x14, 0x13, 0x3, 0x2, 0x2, 0x2, 0x15, 0x3, 0x3,
      0x2, 0x2, 0x2, 0x16, 0x17, 0x7, 0x5, 0x2, 0x2, 0x17, 0x18, 0x7, 0xa,
      0x2, 0x2, 0x18, 0x19, 0x5, 0x6, 0x4, 0x2, 0x19, 0x5, 0x3, 0x2, 0x2,
      0x2, 0x1a, 0x1b, 0x7, 0x9, 0x2, 0x2, 0x1b, 0x1c, 0x5, 0x8, 0x5, 0x2,
      0x1c, 0x1d, 0x7, 0x9, 0x2, 0x2, 0x1d, 0x25, 0x3, 0x2, 0x2, 0x2, 0x1e,
      0x25, 0x7, 0xb, 0x2, 0x2, 0x1f, 0x25, 0x7, 0xc, 0x2, 0x2, 0x20, 0x25,
      0x7, 0x6, 0x2, 0x2, 0x21, 0x25, 0x7, 0x5, 0x2, 0x2, 0x22, 0x25, 0x7,
      0x7, 0x2, 0x2, 0x23, 0x25, 0x7, 0xf, 0x2, 0x2, 0x24, 0x1a, 0x3, 0x2,
      0x2, 0x2, 0x24, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x24, 0x1f, 0x3, 0x2, 0x2,
      0x2, 0x24, 0x20, 0x3, 0x2, 0x2, 0x2, 0x24, 0x21, 0x3, 0x2, 0x2, 0x2,
      0x24, 0x22, 0x3, 0x2, 0x2, 0x2, 0x24, 0x23, 0x3, 0x2, 0x2, 0x2, 0x25,
      0x7, 0x3, 0x2, 0x2, 0x2, 0x26, 0x2a, 0x5, 0xc, 0x7, 0x2, 0x27, 0x2a,
      0x5, 0xe, 0x8, 0x2, 0x28, 0x2a, 0x5, 0x10, 0x9, 0x2, 0x29, 0x26, 0x3,
      0x2, 0x2, 0x2, 0x29, 0x27, 0x3, 0x2, 0x2, 0x2, 0x29, 0x28, 0x3, 0x2,
      0x2, 0x2, 0x2a, 0x9, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2d, 0x5, 0x6, 0x4,
      0x2, 0x2c, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x30, 0x3, 0x2, 0x2, 0x2,
      0x2e, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x2f,
      0xb, 0x3, 0x2, 0x2, 0x2, 0x30, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32,
      0x7, 0x6, 0x2, 0x2, 0x32, 0x34, 0x5, 0xa, 0x6, 0x2, 0x33, 0x35, 0x7,
      0xd, 0x2, 0x2, 0x34, 0x33, 0x3, 0x2, 0x2, 0x2, 0x34, 0x35, 0x3, 0x2,
      0x2, 0x2, 0x35, 0x37, 0x3, 0x2, 0x2, 0x2, 0x36, 0x38, 0x7, 0xe, 0x2,
      0x2, 0x37, 0x36, 0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 0x3, 0x2, 0x2, 0x2,
      0x38, 0xd, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x7, 0x4, 0x2, 0x2, 0x3a,
      0x3b, 0x5, 0xa, 0x6, 0x2, 0x3b, 0xf, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3f,
      0x5, 0xc, 0x7, 0x2, 0x3d, 0x3e, 0x7, 0x8, 0x2, 0x2, 0x3e, 0x40, 0x5,
      0xc, 0x7, 0x2, 0x3f, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 0x3, 0x2,
      0x2, 0x2, 0x41, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x3, 0x2, 0x2,
      0x2, 0x42, 0x11, 0x3, 0x2, 0x2, 0x2, 0x9, 0x14, 0x24, 0x29, 0x2e, 0x34,
      0x37, 0x41,
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ShellParser::Initializer ShellParser::_init;
