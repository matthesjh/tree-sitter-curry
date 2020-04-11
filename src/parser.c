#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 11
#define STATE_COUNT 4
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 12
#define ALIAS_COUNT 0
#define TOKEN_COUNT 11
#define EXTERNAL_TOKEN_COUNT 6
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 1

enum {
  anon_sym_module = 1,
  sym_comment = 2,
  sym_cpp_directive = 3,
  sym_pragma = 4,
  anon_sym_DASH_GT = 5,
  sym__layout_semicolon = 6,
  sym__layout_open_brace = 7,
  sym__layout_close_brace = 8,
  sym__qualified_module_dot = 9,
  sym__initialize_layout = 10,
  sym_module = 11,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_module] = "module",
  [sym_comment] = "comment",
  [sym_cpp_directive] = "cpp_directive",
  [sym_pragma] = "pragma",
  [anon_sym_DASH_GT] = "->",
  [sym__layout_semicolon] = "_layout_semicolon",
  [sym__layout_open_brace] = "_layout_open_brace",
  [sym__layout_close_brace] = "_layout_close_brace",
  [sym__qualified_module_dot] = "_qualified_module_dot",
  [sym__initialize_layout] = "_initialize_layout",
  [sym_module] = "module",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_module] = anon_sym_module,
  [sym_comment] = sym_comment,
  [sym_cpp_directive] = sym_cpp_directive,
  [sym_pragma] = sym_pragma,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [sym__layout_semicolon] = sym__layout_semicolon,
  [sym__layout_open_brace] = sym__layout_open_brace,
  [sym__layout_close_brace] = sym__layout_close_brace,
  [sym__qualified_module_dot] = sym__qualified_module_dot,
  [sym__initialize_layout] = sym__initialize_layout,
  [sym_module] = sym_module,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_module] = {
    .visible = true,
    .named = false,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_cpp_directive] = {
    .visible = true,
    .named = true,
  },
  [sym_pragma] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DASH_GT] = {
    .visible = true,
    .named = false,
  },
  [sym__layout_semicolon] = {
    .visible = false,
    .named = true,
  },
  [sym__layout_open_brace] = {
    .visible = false,
    .named = true,
  },
  [sym__layout_close_brace] = {
    .visible = false,
    .named = true,
  },
  [sym__qualified_module_dot] = {
    .visible = false,
    .named = true,
  },
  [sym__initialize_layout] = {
    .visible = false,
    .named = true,
  },
  [sym_module] = {
    .visible = true,
    .named = true,
  },
};

static TSSymbol ts_alias_sequences[1][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(15);
      if (lookahead == '#') ADVANCE(19);
      if (lookahead == '-') ADVANCE(3);
      if (lookahead == '\\') SKIP(14)
      if (lookahead == 'm') ADVANCE(10);
      if (lookahead == '{') ADVANCE(4);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == '#') ADVANCE(2);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 2:
      if (lookahead == '#') ADVANCE(6);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == '-') ADVANCE(18);
      if (lookahead == '>') ADVANCE(21);
      END_STATE();
    case 4:
      if (lookahead == '-') ADVANCE(1);
      END_STATE();
    case 5:
      if (lookahead == '-') ADVANCE(12);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 6:
      if (lookahead == '-') ADVANCE(13);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 7:
      if (lookahead == 'd') ADVANCE(11);
      END_STATE();
    case 8:
      if (lookahead == 'e') ADVANCE(16);
      END_STATE();
    case 9:
      if (lookahead == 'l') ADVANCE(8);
      END_STATE();
    case 10:
      if (lookahead == 'o') ADVANCE(7);
      END_STATE();
    case 11:
      if (lookahead == 'u') ADVANCE(9);
      END_STATE();
    case 12:
      if (lookahead == '}') ADVANCE(17);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 13:
      if (lookahead == '}') ADVANCE(20);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 14:
      if (eof) ADVANCE(15);
      if (lookahead == 'n') SKIP(0)
      END_STATE();
    case 15:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_module);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(18);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(sym_cpp_directive);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(19);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_pragma);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
};

enum {
  ts_external_token__layout_semicolon = 0,
  ts_external_token__layout_open_brace = 1,
  ts_external_token__layout_close_brace = 2,
  ts_external_token_DASH_GT = 3,
  ts_external_token__qualified_module_dot = 4,
  ts_external_token__initialize_layout = 5,
};

static TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__layout_semicolon] = sym__layout_semicolon,
  [ts_external_token__layout_open_brace] = sym__layout_open_brace,
  [ts_external_token__layout_close_brace] = sym__layout_close_brace,
  [ts_external_token_DASH_GT] = anon_sym_DASH_GT,
  [ts_external_token__qualified_module_dot] = sym__qualified_module_dot,
  [ts_external_token__initialize_layout] = sym__initialize_layout,
};

static bool ts_external_scanner_states[2][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__layout_semicolon] = true,
    [ts_external_token__layout_open_brace] = true,
    [ts_external_token__layout_close_brace] = true,
    [ts_external_token_DASH_GT] = true,
    [ts_external_token__qualified_module_dot] = true,
    [ts_external_token__initialize_layout] = true,
  },
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_module] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
    [sym_cpp_directive] = ACTIONS(3),
    [sym_pragma] = ACTIONS(3),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [sym__layout_semicolon] = ACTIONS(1),
    [sym__layout_open_brace] = ACTIONS(1),
    [sym__layout_close_brace] = ACTIONS(1),
    [sym__qualified_module_dot] = ACTIONS(1),
    [sym__initialize_layout] = ACTIONS(1),
  },
  [1] = {
    [sym_module] = STATE(3),
    [anon_sym_module] = ACTIONS(5),
    [sym_comment] = ACTIONS(3),
    [sym_cpp_directive] = ACTIONS(3),
    [sym_pragma] = ACTIONS(3),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(7), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [9] = 2,
    ACTIONS(9), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 9,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.count = 0, .reusable = false},
  [1] = {.count = 1, .reusable = false}, RECOVER(),
  [3] = {.count = 1, .reusable = true}, SHIFT_EXTRA(),
  [5] = {.count = 1, .reusable = true}, SHIFT(2),
  [7] = {.count = 1, .reusable = true}, REDUCE(sym_module, 1),
  [9] = {.count = 1, .reusable = true},  ACCEPT_INPUT(),
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_curry_external_scanner_create(void);
void tree_sitter_curry_external_scanner_destroy(void *);
bool tree_sitter_curry_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_curry_external_scanner_serialize(void *, char *);
void tree_sitter_curry_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_curry(void) {
  static TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .symbol_metadata = ts_symbol_metadata,
    .parse_table = (const unsigned short *)ts_parse_table,
    .small_parse_table = (const uint16_t *)ts_small_parse_table,
    .small_parse_table_map = (const uint32_t *)ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .lex_modes = ts_lex_modes,
    .symbol_names = ts_symbol_names,
    .public_symbol_map = ts_symbol_map,
    .alias_sequences = (const TSSymbol *)ts_alias_sequences,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .lex_fn = ts_lex,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .external_scanner = {
      (const bool *)ts_external_scanner_states,
      ts_external_scanner_symbol_map,
      tree_sitter_curry_external_scanner_create,
      tree_sitter_curry_external_scanner_destroy,
      tree_sitter_curry_external_scanner_scan,
      tree_sitter_curry_external_scanner_serialize,
      tree_sitter_curry_external_scanner_deserialize,
    },
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
