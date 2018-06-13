
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

ShellParser::ExportEnvContext* ShellParser::StatementContext::exportEnv() {
  return getRuleContext<ShellParser::ExportEnvContext>(0);
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
    setState(21);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ShellParser::VARIABLE_TOKEN: {
        enterOuterAlt(_localctx, 1);
        setState(18);
        assignment();
        break;
      }

      case ShellParser::EXPORT_TOKEN: {
        enterOuterAlt(_localctx, 2);
        setState(19);
        exportEnv();
        break;
      }

      case ShellParser::COMMAND_TOKEN:
      case ShellParser::PATH_TOKEN: {
        enterOuterAlt(_localctx, 3);
        setState(20);
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
    setState(23);
    match(ShellParser::VARIABLE_TOKEN);
    setState(24);
    match(ShellParser::EQUALS_TOKEN);
    setState(25);
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

std::vector<tree::TerminalNode *> ShellParser::ValueContext::BACK_QOUTE_TOKEN() {
  return getTokens(ShellParser::BACK_QOUTE_TOKEN);
}

tree::TerminalNode* ShellParser::ValueContext::BACK_QOUTE_TOKEN(size_t i) {
  return getToken(ShellParser::BACK_QOUTE_TOKEN, i);
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
      case ShellParser::BACK_QOUTE_TOKEN: {
        enterOuterAlt(_localctx, 1);
        setState(27);
        match(ShellParser::BACK_QOUTE_TOKEN);
        setState(28);
        runnable();
        setState(29);
        match(ShellParser::BACK_QOUTE_TOKEN);
        break;
      }

      case ShellParser::VARIABLE_VALUE_TOKEN: {
        enterOuterAlt(_localctx, 2);
        setState(31);
        match(ShellParser::VARIABLE_VALUE_TOKEN);
        break;
      }

      case ShellParser::RETURN_TOKEN: {
        enterOuterAlt(_localctx, 3);
        setState(32);
        match(ShellParser::RETURN_TOKEN);
        break;
      }

      case ShellParser::CONSTANT_TOKEN: {
        enterOuterAlt(_localctx, 4);
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

//----------------- ExportEnvContext ------------------------------------------------------------------

ShellParser::ExportEnvContext::ExportEnvContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShellParser::ExportEnvContext::EXPORT_TOKEN() {
  return getToken(ShellParser::EXPORT_TOKEN, 0);
}

tree::TerminalNode* ShellParser::ExportEnvContext::VARIABLE_TOKEN() {
  return getToken(ShellParser::VARIABLE_TOKEN, 0);
}

ShellParser::AssignmentContext* ShellParser::ExportEnvContext::assignment() {
  return getRuleContext<ShellParser::AssignmentContext>(0);
}


size_t ShellParser::ExportEnvContext::getRuleIndex() const {
  return ShellParser::RuleExportEnv;
}

antlrcpp::Any ShellParser::ExportEnvContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShellParserVisitor*>(visitor))
    return parserVisitor->visitExportEnv(this);
  else
    return visitor->visitChildren(this);
}

ShellParser::ExportEnvContext* ShellParser::exportEnv() {
  ExportEnvContext *_localctx = _tracker.createInstance<ExportEnvContext>(_ctx, getState());
  enterRule(_localctx, 6, ShellParser::RuleExportEnv);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(36);
    match(ShellParser::EXPORT_TOKEN);
    setState(39);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      setState(37);
      match(ShellParser::VARIABLE_TOKEN);
      break;
    }

    case 2: {
      setState(38);
      assignment();
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
  enterRule(_localctx, 8, ShellParser::RuleRunnable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(44);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(41);
      process();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(42);
      command();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(43);
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
  enterRule(_localctx, 10, ShellParser::RuleArguments);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(49);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(46);
        value(); 
      }
      setState(51);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
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
  enterRule(_localctx, 12, ShellParser::RuleProcess);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(52);
    match(ShellParser::PATH_TOKEN);
    setState(53);
    arguments();
    setState(55);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ShellParser::INPUT_REDIRECTION_TOKEN) {
      setState(54);
      match(ShellParser::INPUT_REDIRECTION_TOKEN);
    }
    setState(58);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ShellParser::OUTPUT_REDIRECTION_TOKEN) {
      setState(57);
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
  enterRule(_localctx, 14, ShellParser::RuleCommand);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(60);
    match(ShellParser::COMMAND_TOKEN);
    setState(61);
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
  enterRule(_localctx, 16, ShellParser::RulePipe);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(63);
    process();
    setState(66); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(64);
      match(ShellParser::PIPE_TOKEN);
      setState(65);
      process();
      setState(68); 
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
  "statement", "assignment", "value", "exportEnv", "runnable", "arguments", 
  "process", "command", "pipe"
};

std::vector<std::string> ShellParser::_literalNames = {
  "", "", "", "'export'", "", "", "", "", "'|'", "'`'", "'='", "", "'$?'"
};

std::vector<std::string> ShellParser::_symbolicNames = {
  "", "WHITESPACE", "COMMAND_TOKEN", "EXPORT_TOKEN", "VARIABLE_TOKEN", "PATH_TOKEN", 
  "QUOTE_STRING_TOKEN", "ARGUMENTS_WHITESPACE", "PIPE_TOKEN", "BACK_QOUTE_TOKEN", 
  "EQUALS_TOKEN", "VARIABLE_VALUE_TOKEN", "RETURN_TOKEN", "INPUT_REDIRECTION_TOKEN", 
  "OUTPUT_REDIRECTION_TOKEN", "CONSTANT_TOKEN"
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
    0x3, 0x11, 0x49, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x5, 0x2, 0x18, 0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x5, 0x4, 0x25, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 
    0x5, 0x2a, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x2f, 0xa, 
    0x6, 0x3, 0x7, 0x7, 0x7, 0x32, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x35, 0xb, 
    0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x3a, 0xa, 0x8, 0x3, 0x8, 
    0x5, 0x8, 0x3d, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x6, 0xa, 0x45, 0xa, 0xa, 0xd, 0xa, 0xe, 0xa, 0x46, 0x3, 
    0xa, 0x2, 0x2, 0xb, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x2, 
    0x2, 0x2, 0x4b, 0x2, 0x17, 0x3, 0x2, 0x2, 0x2, 0x4, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0x24, 0x3, 0x2, 0x2, 0x2, 0x8, 0x26, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0x2e, 0x3, 0x2, 0x2, 0x2, 0xc, 0x33, 0x3, 0x2, 0x2, 0x2, 0xe, 0x36, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x12, 0x41, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x18, 0x5, 0x4, 0x3, 0x2, 0x15, 0x18, 0x5, 0x8, 
    0x5, 0x2, 0x16, 0x18, 0x5, 0xa, 0x6, 0x2, 0x17, 0x14, 0x3, 0x2, 0x2, 
    0x2, 0x17, 0x15, 0x3, 0x2, 0x2, 0x2, 0x17, 0x16, 0x3, 0x2, 0x2, 0x2, 
    0x18, 0x3, 0x3, 0x2, 0x2, 0x2, 0x19, 0x1a, 0x7, 0x6, 0x2, 0x2, 0x1a, 
    0x1b, 0x7, 0xc, 0x2, 0x2, 0x1b, 0x1c, 0x5, 0x6, 0x4, 0x2, 0x1c, 0x5, 
    0x3, 0x2, 0x2, 0x2, 0x1d, 0x1e, 0x7, 0xb, 0x2, 0x2, 0x1e, 0x1f, 0x5, 
    0xa, 0x6, 0x2, 0x1f, 0x20, 0x7, 0xb, 0x2, 0x2, 0x20, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0x21, 0x25, 0x7, 0xd, 0x2, 0x2, 0x22, 0x25, 0x7, 0xe, 0x2, 
    0x2, 0x23, 0x25, 0x7, 0x11, 0x2, 0x2, 0x24, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0x24, 0x21, 0x3, 0x2, 0x2, 0x2, 0x24, 0x22, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0x25, 0x7, 0x3, 0x2, 0x2, 0x2, 0x26, 0x29, 
    0x7, 0x5, 0x2, 0x2, 0x27, 0x2a, 0x7, 0x6, 0x2, 0x2, 0x28, 0x2a, 0x5, 
    0x4, 0x3, 0x2, 0x29, 0x27, 0x3, 0x2, 0x2, 0x2, 0x29, 0x28, 0x3, 0x2, 
    0x2, 0x2, 0x2a, 0x9, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2f, 0x5, 0xe, 0x8, 
    0x2, 0x2c, 0x2f, 0x5, 0x10, 0x9, 0x2, 0x2d, 0x2f, 0x5, 0x12, 0xa, 0x2, 
    0x2e, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0x2d, 0x3, 0x2, 0x2, 0x2, 0x2f, 0xb, 0x3, 0x2, 0x2, 0x2, 0x30, 0x32, 
    0x5, 0x6, 0x4, 0x2, 0x31, 0x30, 0x3, 0x2, 0x2, 0x2, 0x32, 0x35, 0x3, 
    0x2, 0x2, 0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x3, 0x2, 
    0x2, 0x2, 0x34, 0xd, 0x3, 0x2, 0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0x37, 0x7, 0x7, 0x2, 0x2, 0x37, 0x39, 0x5, 0xc, 0x7, 0x2, 
    0x38, 0x3a, 0x7, 0xf, 0x2, 0x2, 0x39, 0x38, 0x3, 0x2, 0x2, 0x2, 0x39, 
    0x3a, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3d, 
    0x7, 0x10, 0x2, 0x2, 0x3c, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0x3, 
    0x2, 0x2, 0x2, 0x3d, 0xf, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3f, 0x7, 0x4, 
    0x2, 0x2, 0x3f, 0x40, 0x5, 0xc, 0x7, 0x2, 0x40, 0x11, 0x3, 0x2, 0x2, 
    0x2, 0x41, 0x44, 0x5, 0xe, 0x8, 0x2, 0x42, 0x43, 0x7, 0xa, 0x2, 0x2, 
    0x43, 0x45, 0x5, 0xe, 0x8, 0x2, 0x44, 0x42, 0x3, 0x2, 0x2, 0x2, 0x45, 
    0x46, 0x3, 0x2, 0x2, 0x2, 0x46, 0x44, 0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 
    0x3, 0x2, 0x2, 0x2, 0x47, 0x13, 0x3, 0x2, 0x2, 0x2, 0xa, 0x17, 0x24, 
    0x29, 0x2e, 0x33, 0x39, 0x3c, 0x46, 
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
