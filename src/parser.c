#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 11
#define STATE_COUNT 82
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 48
#define ALIAS_COUNT 2
#define TOKEN_COUNT 23
#define EXTERNAL_TOKEN_COUNT 6
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 5

enum {
  sym__variable_identifier = 1,
  anon_sym_module = 2,
  aux_sym_module_identifier_token1 = 3,
  anon_sym_LPAREN = 4,
  anon_sym_COMMA = 5,
  anon_sym_RPAREN = 6,
  sym_all_constructors = 7,
  anon_sym_where = 8,
  anon_sym_LBRACE = 9,
  anon_sym_RBRACE = 10,
  sym__top_declaration = 11,
  sym_variable_operator = 12,
  sym__terminal = 13,
  sym_comment = 14,
  sym_cpp_directive = 15,
  sym_pragma = 16,
  anon_sym_DASH_GT = 17,
  sym__layout_semicolon = 18,
  sym__layout_open_brace = 19,
  sym__layout_close_brace = 20,
  sym__qualified_module_dot = 21,
  sym__initialize_layout = 22,
  sym_module = 23,
  sym_module_identifier = 24,
  sym_qualified_module_identifier = 25,
  sym__qualified_module_identifier = 26,
  sym_exports = 27,
  sym_export = 28,
  sym_module_export = 29,
  sym__top_where = 30,
  sym__top_declarations = 31,
  sym_variable_identifier = 32,
  sym_qualified_variable_identifier = 33,
  sym__qualified_variable_identifier = 34,
  sym_qualified_variable_operator = 35,
  sym__qualified_variable_operator = 36,
  sym__qualified_variable = 37,
  sym__label = 38,
  sym_type_identifier = 39,
  sym_qualified_type_identifier = 40,
  sym__qualified_type_identifier = 41,
  sym_constructor_identifier = 42,
  aux_sym_module_repeat1 = 43,
  aux_sym_qualified_module_identifier_repeat1 = 44,
  aux_sym_exports_repeat1 = 45,
  aux_sym_export_repeat1 = 46,
  aux_sym__top_declarations_repeat1 = 47,
  alias_sym_label_identifier = 48,
  alias_sym_label_operator = 49,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym__variable_identifier] = "_variable_identifier",
  [anon_sym_module] = "module",
  [aux_sym_module_identifier_token1] = "module_identifier_token1",
  [anon_sym_LPAREN] = "(",
  [anon_sym_COMMA] = ",",
  [anon_sym_RPAREN] = ")",
  [sym_all_constructors] = "all_constructors",
  [anon_sym_where] = "where",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [sym__top_declaration] = "_top_declaration",
  [sym_variable_operator] = "variable_operator",
  [sym__terminal] = "_terminal",
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
  [sym_module_identifier] = "module_identifier",
  [sym_qualified_module_identifier] = "qualified_module_identifier",
  [sym__qualified_module_identifier] = "_qualified_module_identifier",
  [sym_exports] = "exports",
  [sym_export] = "export",
  [sym_module_export] = "module_export",
  [sym__top_where] = "_top_where",
  [sym__top_declarations] = "_top_declarations",
  [sym_variable_identifier] = "variable_identifier",
  [sym_qualified_variable_identifier] = "qualified_variable_identifier",
  [sym__qualified_variable_identifier] = "_qualified_variable_identifier",
  [sym_qualified_variable_operator] = "qualified_variable_operator",
  [sym__qualified_variable_operator] = "_qualified_variable_operator",
  [sym__qualified_variable] = "_qualified_variable",
  [sym__label] = "_label",
  [sym_type_identifier] = "type_identifier",
  [sym_qualified_type_identifier] = "qualified_type_identifier",
  [sym__qualified_type_identifier] = "_qualified_type_identifier",
  [sym_constructor_identifier] = "constructor_identifier",
  [aux_sym_module_repeat1] = "module_repeat1",
  [aux_sym_qualified_module_identifier_repeat1] = "qualified_module_identifier_repeat1",
  [aux_sym_exports_repeat1] = "exports_repeat1",
  [aux_sym_export_repeat1] = "export_repeat1",
  [aux_sym__top_declarations_repeat1] = "_top_declarations_repeat1",
  [alias_sym_label_identifier] = "label_identifier",
  [alias_sym_label_operator] = "label_operator",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym__variable_identifier] = sym__variable_identifier,
  [anon_sym_module] = anon_sym_module,
  [aux_sym_module_identifier_token1] = aux_sym_module_identifier_token1,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [sym_all_constructors] = sym_all_constructors,
  [anon_sym_where] = anon_sym_where,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [sym__top_declaration] = sym__top_declaration,
  [sym_variable_operator] = sym_variable_operator,
  [sym__terminal] = sym__terminal,
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
  [sym_module_identifier] = sym_module_identifier,
  [sym_qualified_module_identifier] = sym_qualified_module_identifier,
  [sym__qualified_module_identifier] = sym__qualified_module_identifier,
  [sym_exports] = sym_exports,
  [sym_export] = sym_export,
  [sym_module_export] = sym_module_export,
  [sym__top_where] = sym__top_where,
  [sym__top_declarations] = sym__top_declarations,
  [sym_variable_identifier] = sym_variable_identifier,
  [sym_qualified_variable_identifier] = sym_qualified_variable_identifier,
  [sym__qualified_variable_identifier] = sym__qualified_variable_identifier,
  [sym_qualified_variable_operator] = sym_qualified_variable_operator,
  [sym__qualified_variable_operator] = sym__qualified_variable_operator,
  [sym__qualified_variable] = sym__qualified_variable,
  [sym__label] = sym__label,
  [sym_type_identifier] = sym_type_identifier,
  [sym_qualified_type_identifier] = sym_qualified_type_identifier,
  [sym__qualified_type_identifier] = sym__qualified_type_identifier,
  [sym_constructor_identifier] = sym_constructor_identifier,
  [aux_sym_module_repeat1] = aux_sym_module_repeat1,
  [aux_sym_qualified_module_identifier_repeat1] = aux_sym_qualified_module_identifier_repeat1,
  [aux_sym_exports_repeat1] = aux_sym_exports_repeat1,
  [aux_sym_export_repeat1] = aux_sym_export_repeat1,
  [aux_sym__top_declarations_repeat1] = aux_sym__top_declarations_repeat1,
  [alias_sym_label_identifier] = alias_sym_label_identifier,
  [alias_sym_label_operator] = alias_sym_label_operator,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym__variable_identifier] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_module] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_module_identifier_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [sym_all_constructors] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_where] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym__top_declaration] = {
    .visible = false,
    .named = true,
  },
  [sym_variable_operator] = {
    .visible = true,
    .named = true,
  },
  [sym__terminal] = {
    .visible = false,
    .named = true,
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
  [sym_module_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_qualified_module_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym__qualified_module_identifier] = {
    .visible = false,
    .named = true,
  },
  [sym_exports] = {
    .visible = true,
    .named = true,
  },
  [sym_export] = {
    .visible = true,
    .named = true,
  },
  [sym_module_export] = {
    .visible = true,
    .named = true,
  },
  [sym__top_where] = {
    .visible = false,
    .named = true,
  },
  [sym__top_declarations] = {
    .visible = false,
    .named = true,
  },
  [sym_variable_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_qualified_variable_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym__qualified_variable_identifier] = {
    .visible = false,
    .named = true,
  },
  [sym_qualified_variable_operator] = {
    .visible = true,
    .named = true,
  },
  [sym__qualified_variable_operator] = {
    .visible = false,
    .named = true,
  },
  [sym__qualified_variable] = {
    .visible = false,
    .named = true,
  },
  [sym__label] = {
    .visible = false,
    .named = true,
  },
  [sym_type_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_qualified_type_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym__qualified_type_identifier] = {
    .visible = false,
    .named = true,
  },
  [sym_constructor_identifier] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_module_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_qualified_module_identifier_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_exports_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_export_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__top_declarations_repeat1] = {
    .visible = false,
    .named = false,
  },
  [alias_sym_label_identifier] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_label_operator] = {
    .visible = true,
    .named = true,
  },
};

static TSSymbol ts_alias_sequences[3][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [1] = {
    [0] = alias_sym_label_identifier,
  },
  [2] = {
    [1] = alias_sym_label_operator,
  },
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(19);
      if (lookahead == '#') ADVANCE(37);
      if (lookahead == '(') ADVANCE(22);
      if (lookahead == ')') ADVANCE(24);
      if (lookahead == ',') ADVANCE(23);
      if (lookahead == '-') ADVANCE(7);
      if (lookahead == ';') ADVANCE(34);
      if (lookahead == 'D') ADVANCE(13);
      if (lookahead == '\\') SKIP(18)
      if (lookahead == '{') ADVANCE(26);
      if (lookahead == '}') ADVANCE(27);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(29);
      END_STATE();
    case 1:
      if (lookahead == '#') ADVANCE(37);
      if (lookahead == '(') ADVANCE(21);
      if (lookahead == ')') ADVANCE(24);
      if (lookahead == ',') ADVANCE(23);
      if (lookahead == '-') ADVANCE(6);
      if (lookahead == '\\') SKIP(15)
      if (lookahead == '{') ADVANCE(8);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(20);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(29);
      END_STATE();
    case 2:
      if (lookahead == '#') ADVANCE(31);
      if (lookahead == '-') ADVANCE(30);
      if (lookahead == '\\') ADVANCE(32);
      if (lookahead == '{') ADVANCE(8);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (lookahead == '!' ||
          ('$' <= lookahead && lookahead <= '&') ||
          lookahead == '*' ||
          lookahead == '+' ||
          lookahead == '.' ||
          lookahead == '/' ||
          lookahead == ':' ||
          ('<' <= lookahead && lookahead <= '@') ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(32);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(20);
      END_STATE();
    case 3:
      if (lookahead == '#') ADVANCE(4);
      if (lookahead != 0) ADVANCE(9);
      END_STATE();
    case 4:
      if (lookahead == '#') ADVANCE(10);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 5:
      if (lookahead == ')') ADVANCE(25);
      END_STATE();
    case 6:
      if (lookahead == '-') ADVANCE(36);
      END_STATE();
    case 7:
      if (lookahead == '-') ADVANCE(36);
      if (lookahead == '>') ADVANCE(39);
      END_STATE();
    case 8:
      if (lookahead == '-') ADVANCE(3);
      END_STATE();
    case 9:
      if (lookahead == '-') ADVANCE(16);
      if (lookahead != 0) ADVANCE(9);
      END_STATE();
    case 10:
      if (lookahead == '-') ADVANCE(17);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 11:
      if (lookahead == '.') ADVANCE(5);
      END_STATE();
    case 12:
      if (lookahead == 'C') ADVANCE(14);
      END_STATE();
    case 13:
      if (lookahead == 'E') ADVANCE(12);
      END_STATE();
    case 14:
      if (lookahead == 'L') ADVANCE(28);
      END_STATE();
    case 15:
      if (lookahead == 'n') SKIP(1)
      END_STATE();
    case 16:
      if (lookahead == '}') ADVANCE(35);
      if (lookahead != 0) ADVANCE(9);
      END_STATE();
    case 17:
      if (lookahead == '}') ADVANCE(38);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 18:
      if (eof) ADVANCE(19);
      if (lookahead == 'n') SKIP(0)
      END_STATE();
    case 19:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(aux_sym_module_identifier_token1);
      if (lookahead == '\'' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      if (lookahead == '.') ADVANCE(11);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym_all_constructors);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      if (lookahead == '-') ADVANCE(3);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym__top_declaration);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym__variable_identifier);
      if (lookahead == '\'' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(29);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_variable_operator);
      if (lookahead == '-') ADVANCE(33);
      if (lookahead == '!' ||
          ('#' <= lookahead && lookahead <= '&') ||
          lookahead == '*' ||
          lookahead == '+' ||
          lookahead == '.' ||
          lookahead == '/' ||
          lookahead == ':' ||
          ('<' <= lookahead && lookahead <= '@') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(32);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_variable_operator);
      if (lookahead == '!' ||
          ('#' <= lookahead && lookahead <= '&') ||
          lookahead == '*' ||
          lookahead == '+' ||
          ('-' <= lookahead && lookahead <= '/') ||
          lookahead == ':' ||
          ('<' <= lookahead && lookahead <= '@') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(31);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(37);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_variable_operator);
      if (lookahead == '!' ||
          ('#' <= lookahead && lookahead <= '&') ||
          lookahead == '*' ||
          lookahead == '+' ||
          ('-' <= lookahead && lookahead <= '/') ||
          lookahead == ':' ||
          ('<' <= lookahead && lookahead <= '@') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(32);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_variable_operator);
      if (lookahead == '!' ||
          ('#' <= lookahead && lookahead <= '&') ||
          lookahead == '*' ||
          lookahead == '+' ||
          ('-' <= lookahead && lookahead <= '/') ||
          lookahead == ':' ||
          ('<' <= lookahead && lookahead <= '@') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(33);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(36);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym__terminal);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(36);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_cpp_directive);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(37);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_pragma);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (lookahead == '\\') SKIP(1)
      if (lookahead == 'm') ADVANCE(2);
      if (lookahead == 'w') ADVANCE(3);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == 'n') SKIP(0)
      END_STATE();
    case 2:
      if (lookahead == 'o') ADVANCE(4);
      END_STATE();
    case 3:
      if (lookahead == 'h') ADVANCE(5);
      END_STATE();
    case 4:
      if (lookahead == 'd') ADVANCE(6);
      END_STATE();
    case 5:
      if (lookahead == 'e') ADVANCE(7);
      END_STATE();
    case 6:
      if (lookahead == 'u') ADVANCE(8);
      END_STATE();
    case 7:
      if (lookahead == 'r') ADVANCE(9);
      END_STATE();
    case 8:
      if (lookahead == 'l') ADVANCE(10);
      END_STATE();
    case 9:
      if (lookahead == 'e') ADVANCE(11);
      END_STATE();
    case 10:
      if (lookahead == 'e') ADVANCE(12);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_where);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_module);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 0, .external_lex_state = 2},
  [2] = {.lex_state = 1},
  [3] = {.lex_state = 1},
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 1},
  [6] = {.lex_state = 2},
  [7] = {.lex_state = 1},
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 1, .external_lex_state = 3},
  [11] = {.lex_state = 1, .external_lex_state = 3},
  [12] = {.lex_state = 1},
  [13] = {.lex_state = 0, .external_lex_state = 3},
  [14] = {.lex_state = 1, .external_lex_state = 3},
  [15] = {.lex_state = 1},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 1},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 1},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 1},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0, .external_lex_state = 4},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0, .external_lex_state = 4},
  [33] = {.lex_state = 0, .external_lex_state = 5},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 1},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0, .external_lex_state = 4},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0, .external_lex_state = 6},
  [45] = {.lex_state = 0, .external_lex_state = 4},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0, .external_lex_state = 6},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0, .external_lex_state = 3},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0, .external_lex_state = 3},
  [64] = {.lex_state = 2},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 0, .external_lex_state = 3},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 1},
  [74] = {.lex_state = 2},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 0, .external_lex_state = 3},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 0, .external_lex_state = 3},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 0},
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

static bool ts_external_scanner_states[7][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__layout_semicolon] = true,
    [ts_external_token__layout_open_brace] = true,
    [ts_external_token__layout_close_brace] = true,
    [ts_external_token_DASH_GT] = true,
    [ts_external_token__qualified_module_dot] = true,
    [ts_external_token__initialize_layout] = true,
  },
  [2] = {
    [ts_external_token__initialize_layout] = true,
  },
  [3] = {
    [ts_external_token__qualified_module_dot] = true,
  },
  [4] = {
    [ts_external_token__layout_close_brace] = true,
  },
  [5] = {
    [ts_external_token__layout_open_brace] = true,
  },
  [6] = {
    [ts_external_token__layout_semicolon] = true,
  },
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym__variable_identifier] = ACTIONS(1),
    [anon_sym_module] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [sym_all_constructors] = ACTIONS(1),
    [anon_sym_where] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [sym__top_declaration] = ACTIONS(1),
    [sym__terminal] = ACTIONS(1),
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
    [sym_module] = STATE(69),
    [anon_sym_module] = ACTIONS(5),
    [sym_comment] = ACTIONS(3),
    [sym_cpp_directive] = ACTIONS(3),
    [sym_pragma] = ACTIONS(3),
    [sym__initialize_layout] = ACTIONS(7),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 13,
    ACTIONS(9), 1,
      sym__variable_identifier,
    ACTIONS(11), 1,
      anon_sym_module,
    ACTIONS(13), 1,
      aux_sym_module_identifier_token1,
    ACTIONS(15), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_COMMA,
    ACTIONS(19), 1,
      anon_sym_RPAREN,
    STATE(27), 1,
      sym_export,
    STATE(35), 1,
      aux_sym_qualified_module_identifier_repeat1,
    STATE(76), 1,
      sym_module_identifier,
    STATE(60), 2,
      sym_qualified_module_identifier,
      sym__qualified_module_identifier,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
    STATE(16), 3,
      sym_type_identifier,
      sym_qualified_type_identifier,
      sym__qualified_type_identifier,
    STATE(56), 5,
      sym_module_export,
      sym_variable_identifier,
      sym_qualified_variable_identifier,
      sym__qualified_variable_identifier,
      sym__qualified_variable,
  [49] = 12,
    ACTIONS(9), 1,
      sym__variable_identifier,
    ACTIONS(11), 1,
      anon_sym_module,
    ACTIONS(13), 1,
      aux_sym_module_identifier_token1,
    ACTIONS(15), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_RPAREN,
    STATE(35), 1,
      aux_sym_qualified_module_identifier_repeat1,
    STATE(54), 1,
      sym_export,
    STATE(76), 1,
      sym_module_identifier,
    STATE(60), 2,
      sym_qualified_module_identifier,
      sym__qualified_module_identifier,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
    STATE(16), 3,
      sym_type_identifier,
      sym_qualified_type_identifier,
      sym__qualified_type_identifier,
    STATE(56), 5,
      sym_module_export,
      sym_variable_identifier,
      sym_qualified_variable_identifier,
      sym__qualified_variable_identifier,
      sym__qualified_variable,
  [95] = 12,
    ACTIONS(9), 1,
      sym__variable_identifier,
    ACTIONS(11), 1,
      anon_sym_module,
    ACTIONS(13), 1,
      aux_sym_module_identifier_token1,
    ACTIONS(15), 1,
      anon_sym_LPAREN,
    ACTIONS(23), 1,
      anon_sym_RPAREN,
    STATE(35), 1,
      aux_sym_qualified_module_identifier_repeat1,
    STATE(54), 1,
      sym_export,
    STATE(76), 1,
      sym_module_identifier,
    STATE(60), 2,
      sym_qualified_module_identifier,
      sym__qualified_module_identifier,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
    STATE(16), 3,
      sym_type_identifier,
      sym_qualified_type_identifier,
      sym__qualified_type_identifier,
    STATE(56), 5,
      sym_module_export,
      sym_variable_identifier,
      sym_qualified_variable_identifier,
      sym__qualified_variable_identifier,
      sym__qualified_variable,
  [141] = 11,
    ACTIONS(9), 1,
      sym__variable_identifier,
    ACTIONS(11), 1,
      anon_sym_module,
    ACTIONS(13), 1,
      aux_sym_module_identifier_token1,
    ACTIONS(15), 1,
      anon_sym_LPAREN,
    STATE(35), 1,
      aux_sym_qualified_module_identifier_repeat1,
    STATE(54), 1,
      sym_export,
    STATE(76), 1,
      sym_module_identifier,
    STATE(60), 2,
      sym_qualified_module_identifier,
      sym__qualified_module_identifier,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
    STATE(16), 3,
      sym_type_identifier,
      sym_qualified_type_identifier,
      sym__qualified_type_identifier,
    STATE(56), 5,
      sym_module_export,
      sym_variable_identifier,
      sym_qualified_variable_identifier,
      sym__qualified_variable_identifier,
      sym__qualified_variable,
  [184] = 7,
    ACTIONS(25), 1,
      aux_sym_module_identifier_token1,
    ACTIONS(27), 1,
      sym_variable_operator,
    STATE(35), 1,
      aux_sym_qualified_module_identifier_repeat1,
    STATE(76), 1,
      sym_module_identifier,
    STATE(63), 2,
      sym_qualified_module_identifier,
      sym__qualified_module_identifier,
    STATE(81), 2,
      sym_qualified_variable_operator,
      sym__qualified_variable_operator,
    ACTIONS(29), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [210] = 7,
    ACTIONS(31), 1,
      sym__variable_identifier,
    ACTIONS(33), 1,
      aux_sym_module_identifier_token1,
    ACTIONS(35), 1,
      anon_sym_LPAREN,
    ACTIONS(37), 1,
      anon_sym_RPAREN,
    STATE(41), 1,
      sym_variable_identifier,
    STATE(25), 2,
      sym__label,
      sym_constructor_identifier,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [235] = 6,
    ACTIONS(31), 1,
      sym__variable_identifier,
    ACTIONS(33), 1,
      aux_sym_module_identifier_token1,
    ACTIONS(35), 1,
      anon_sym_LPAREN,
    STATE(41), 1,
      sym_variable_identifier,
    STATE(48), 2,
      sym__label,
      sym_constructor_identifier,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [257] = 5,
    ACTIONS(39), 1,
      aux_sym_module_identifier_token1,
    STATE(11), 1,
      sym_module_identifier,
    STATE(28), 1,
      aux_sym_qualified_module_identifier_repeat1,
    STATE(17), 2,
      sym_qualified_module_identifier,
      sym__qualified_module_identifier,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [276] = 2,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
    ACTIONS(41), 5,
      sym__qualified_module_dot,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_where,
  [289] = 3,
    ACTIONS(45), 1,
      sym__qualified_module_dot,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
    ACTIONS(43), 4,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_where,
  [304] = 5,
    ACTIONS(39), 1,
      aux_sym_module_identifier_token1,
    STATE(11), 1,
      sym_module_identifier,
    STATE(28), 1,
      aux_sym_qualified_module_identifier_repeat1,
    STATE(42), 2,
      sym_qualified_module_identifier,
      sym__qualified_module_identifier,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [323] = 4,
    ACTIONS(41), 1,
      sym__qualified_module_dot,
    ACTIONS(47), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
    ACTIONS(49), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_all_constructors,
  [340] = 3,
    ACTIONS(45), 1,
      sym__qualified_module_dot,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
    ACTIONS(51), 4,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_where,
  [355] = 5,
    ACTIONS(31), 1,
      sym__variable_identifier,
    ACTIONS(53), 1,
      aux_sym_module_identifier_token1,
    STATE(19), 1,
      sym_type_identifier,
    STATE(51), 1,
      sym_variable_identifier,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [373] = 4,
    ACTIONS(55), 1,
      anon_sym_LPAREN,
    ACTIONS(59), 1,
      sym_all_constructors,
    ACTIONS(57), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [389] = 5,
    ACTIONS(61), 1,
      anon_sym_LPAREN,
    ACTIONS(63), 1,
      anon_sym_where,
    STATE(43), 1,
      sym_exports,
    STATE(78), 1,
      sym__top_where,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [407] = 3,
    ACTIONS(47), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
    ACTIONS(49), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_all_constructors,
  [421] = 3,
    ACTIONS(65), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
    ACTIONS(67), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      sym_all_constructors,
  [435] = 4,
    ACTIONS(69), 1,
      ts_builtin_sym_end,
    ACTIONS(71), 1,
      sym__top_declaration,
    STATE(29), 1,
      aux_sym_module_repeat1,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [450] = 4,
    ACTIONS(73), 1,
      anon_sym_COMMA,
    ACTIONS(76), 1,
      anon_sym_RPAREN,
    STATE(21), 1,
      aux_sym_export_repeat1,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [465] = 4,
    ACTIONS(78), 1,
      aux_sym_module_identifier_token1,
    STATE(22), 1,
      aux_sym_qualified_module_identifier_repeat1,
    STATE(71), 1,
      sym_module_identifier,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [480] = 4,
    ACTIONS(81), 1,
      anon_sym_COMMA,
    ACTIONS(83), 1,
      anon_sym_RPAREN,
    STATE(21), 1,
      aux_sym_export_repeat1,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [495] = 4,
    ACTIONS(85), 1,
      anon_sym_RBRACE,
    ACTIONS(87), 1,
      sym__top_declaration,
    STATE(24), 1,
      aux_sym__top_declarations_repeat1,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [510] = 4,
    ACTIONS(81), 1,
      anon_sym_COMMA,
    ACTIONS(90), 1,
      anon_sym_RPAREN,
    STATE(23), 1,
      aux_sym_export_repeat1,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [525] = 4,
    ACTIONS(92), 1,
      anon_sym_COMMA,
    ACTIONS(95), 1,
      anon_sym_RPAREN,
    STATE(26), 1,
      aux_sym_exports_repeat1,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [540] = 4,
    ACTIONS(97), 1,
      anon_sym_COMMA,
    ACTIONS(99), 1,
      anon_sym_RPAREN,
    STATE(34), 1,
      aux_sym_exports_repeat1,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [555] = 4,
    ACTIONS(39), 1,
      aux_sym_module_identifier_token1,
    STATE(14), 1,
      sym_module_identifier,
    STATE(22), 1,
      aux_sym_qualified_module_identifier_repeat1,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [570] = 4,
    ACTIONS(101), 1,
      ts_builtin_sym_end,
    ACTIONS(103), 1,
      sym__top_declaration,
    STATE(29), 1,
      aux_sym_module_repeat1,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [585] = 4,
    ACTIONS(106), 1,
      sym__top_declaration,
    ACTIONS(108), 1,
      sym__layout_close_brace,
    STATE(38), 1,
      aux_sym_module_repeat1,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [600] = 4,
    ACTIONS(108), 1,
      anon_sym_RBRACE,
    ACTIONS(110), 1,
      sym__top_declaration,
    STATE(37), 1,
      aux_sym__top_declarations_repeat1,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [615] = 4,
    ACTIONS(101), 1,
      sym__layout_close_brace,
    ACTIONS(112), 1,
      sym__top_declaration,
    STATE(32), 1,
      aux_sym_module_repeat1,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [630] = 4,
    ACTIONS(115), 1,
      anon_sym_LBRACE,
    ACTIONS(117), 1,
      sym__layout_open_brace,
    STATE(67), 1,
      sym__top_declarations,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [645] = 4,
    ACTIONS(23), 1,
      anon_sym_RPAREN,
    ACTIONS(119), 1,
      anon_sym_COMMA,
    STATE(26), 1,
      aux_sym_exports_repeat1,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [660] = 4,
    ACTIONS(39), 1,
      aux_sym_module_identifier_token1,
    STATE(22), 1,
      aux_sym_qualified_module_identifier_repeat1,
    STATE(79), 1,
      sym_module_identifier,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [675] = 3,
    ACTIONS(123), 1,
      sym__terminal,
    ACTIONS(121), 2,
      anon_sym_RBRACE,
      sym__top_declaration,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [688] = 4,
    ACTIONS(110), 1,
      sym__top_declaration,
    ACTIONS(125), 1,
      anon_sym_RBRACE,
    STATE(24), 1,
      aux_sym__top_declarations_repeat1,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [703] = 4,
    ACTIONS(106), 1,
      sym__top_declaration,
    ACTIONS(125), 1,
      sym__layout_close_brace,
    STATE(32), 1,
      aux_sym_module_repeat1,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [718] = 4,
    ACTIONS(71), 1,
      sym__top_declaration,
    ACTIONS(127), 1,
      ts_builtin_sym_end,
    STATE(20), 1,
      aux_sym_module_repeat1,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [733] = 2,
    ACTIONS(85), 2,
      anon_sym_RBRACE,
      sym__top_declaration,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [743] = 2,
    ACTIONS(129), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [753] = 2,
    ACTIONS(131), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [763] = 3,
    ACTIONS(63), 1,
      anon_sym_where,
    STATE(72), 1,
      sym__top_where,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [775] = 2,
    ACTIONS(133), 2,
      sym__layout_semicolon,
      sym__terminal,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [785] = 2,
    ACTIONS(101), 2,
      sym__layout_close_brace,
      sym__top_declaration,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [795] = 2,
    ACTIONS(135), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [805] = 2,
    ACTIONS(137), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [815] = 2,
    ACTIONS(76), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [825] = 2,
    ACTIONS(139), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [835] = 2,
    ACTIONS(141), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [845] = 2,
    ACTIONS(143), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [855] = 2,
    ACTIONS(145), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [865] = 2,
    ACTIONS(147), 2,
      sym__layout_semicolon,
      sym__terminal,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [875] = 2,
    ACTIONS(95), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [885] = 2,
    ACTIONS(149), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [895] = 2,
    ACTIONS(57), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [905] = 2,
    ACTIONS(151), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [915] = 2,
    ACTIONS(101), 2,
      ts_builtin_sym_end,
      sym__top_declaration,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [925] = 2,
    ACTIONS(153), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [935] = 2,
    ACTIONS(155), 1,
      sym__qualified_module_dot,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [944] = 2,
    ACTIONS(157), 1,
      anon_sym_where,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [953] = 2,
    ACTIONS(159), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [962] = 2,
    ACTIONS(161), 1,
      sym__qualified_module_dot,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [971] = 2,
    ACTIONS(163), 1,
      sym_variable_operator,
    ACTIONS(29), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [980] = 2,
    ACTIONS(165), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [989] = 2,
    ACTIONS(167), 1,
      anon_sym_where,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [998] = 2,
    ACTIONS(169), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [1007] = 2,
    ACTIONS(171), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [1016] = 2,
    ACTIONS(173), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [1025] = 2,
    ACTIONS(175), 1,
      anon_sym_where,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [1034] = 2,
    ACTIONS(45), 1,
      sym__qualified_module_dot,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [1043] = 2,
    ACTIONS(177), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [1052] = 2,
    ACTIONS(179), 1,
      aux_sym_module_identifier_token1,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [1061] = 2,
    ACTIONS(181), 1,
      sym_variable_operator,
    ACTIONS(29), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [1070] = 2,
    ACTIONS(99), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [1079] = 2,
    ACTIONS(183), 1,
      sym__qualified_module_dot,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [1088] = 2,
    ACTIONS(186), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [1097] = 2,
    ACTIONS(188), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [1106] = 2,
    ACTIONS(190), 1,
      sym__qualified_module_dot,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [1115] = 2,
    ACTIONS(193), 1,
      anon_sym_where,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
  [1124] = 2,
    ACTIONS(195), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 3,
      sym_comment,
      sym_cpp_directive,
      sym_pragma,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 49,
  [SMALL_STATE(4)] = 95,
  [SMALL_STATE(5)] = 141,
  [SMALL_STATE(6)] = 184,
  [SMALL_STATE(7)] = 210,
  [SMALL_STATE(8)] = 235,
  [SMALL_STATE(9)] = 257,
  [SMALL_STATE(10)] = 276,
  [SMALL_STATE(11)] = 289,
  [SMALL_STATE(12)] = 304,
  [SMALL_STATE(13)] = 323,
  [SMALL_STATE(14)] = 340,
  [SMALL_STATE(15)] = 355,
  [SMALL_STATE(16)] = 373,
  [SMALL_STATE(17)] = 389,
  [SMALL_STATE(18)] = 407,
  [SMALL_STATE(19)] = 421,
  [SMALL_STATE(20)] = 435,
  [SMALL_STATE(21)] = 450,
  [SMALL_STATE(22)] = 465,
  [SMALL_STATE(23)] = 480,
  [SMALL_STATE(24)] = 495,
  [SMALL_STATE(25)] = 510,
  [SMALL_STATE(26)] = 525,
  [SMALL_STATE(27)] = 540,
  [SMALL_STATE(28)] = 555,
  [SMALL_STATE(29)] = 570,
  [SMALL_STATE(30)] = 585,
  [SMALL_STATE(31)] = 600,
  [SMALL_STATE(32)] = 615,
  [SMALL_STATE(33)] = 630,
  [SMALL_STATE(34)] = 645,
  [SMALL_STATE(35)] = 660,
  [SMALL_STATE(36)] = 675,
  [SMALL_STATE(37)] = 688,
  [SMALL_STATE(38)] = 703,
  [SMALL_STATE(39)] = 718,
  [SMALL_STATE(40)] = 733,
  [SMALL_STATE(41)] = 743,
  [SMALL_STATE(42)] = 753,
  [SMALL_STATE(43)] = 763,
  [SMALL_STATE(44)] = 775,
  [SMALL_STATE(45)] = 785,
  [SMALL_STATE(46)] = 795,
  [SMALL_STATE(47)] = 805,
  [SMALL_STATE(48)] = 815,
  [SMALL_STATE(49)] = 825,
  [SMALL_STATE(50)] = 835,
  [SMALL_STATE(51)] = 845,
  [SMALL_STATE(52)] = 855,
  [SMALL_STATE(53)] = 865,
  [SMALL_STATE(54)] = 875,
  [SMALL_STATE(55)] = 885,
  [SMALL_STATE(56)] = 895,
  [SMALL_STATE(57)] = 905,
  [SMALL_STATE(58)] = 915,
  [SMALL_STATE(59)] = 925,
  [SMALL_STATE(60)] = 935,
  [SMALL_STATE(61)] = 944,
  [SMALL_STATE(62)] = 953,
  [SMALL_STATE(63)] = 962,
  [SMALL_STATE(64)] = 971,
  [SMALL_STATE(65)] = 980,
  [SMALL_STATE(66)] = 989,
  [SMALL_STATE(67)] = 998,
  [SMALL_STATE(68)] = 1007,
  [SMALL_STATE(69)] = 1016,
  [SMALL_STATE(70)] = 1025,
  [SMALL_STATE(71)] = 1034,
  [SMALL_STATE(72)] = 1043,
  [SMALL_STATE(73)] = 1052,
  [SMALL_STATE(74)] = 1061,
  [SMALL_STATE(75)] = 1070,
  [SMALL_STATE(76)] = 1079,
  [SMALL_STATE(77)] = 1088,
  [SMALL_STATE(78)] = 1097,
  [SMALL_STATE(79)] = 1106,
  [SMALL_STATE(80)] = 1115,
  [SMALL_STATE(81)] = 1124,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.count = 0, .reusable = false},
  [1] = {.count = 1, .reusable = false}, RECOVER(),
  [3] = {.count = 1, .reusable = true}, SHIFT_EXTRA(),
  [5] = {.count = 1, .reusable = true}, SHIFT(9),
  [7] = {.count = 1, .reusable = true}, SHIFT(39),
  [9] = {.count = 1, .reusable = false}, SHIFT(55),
  [11] = {.count = 1, .reusable = false}, SHIFT(12),
  [13] = {.count = 1, .reusable = true}, SHIFT(13),
  [15] = {.count = 1, .reusable = true}, SHIFT(6),
  [17] = {.count = 1, .reusable = true}, SHIFT(75),
  [19] = {.count = 1, .reusable = true}, SHIFT(61),
  [21] = {.count = 1, .reusable = true}, SHIFT(66),
  [23] = {.count = 1, .reusable = true}, SHIFT(70),
  [25] = {.count = 1, .reusable = false}, SHIFT(10),
  [27] = {.count = 1, .reusable = false}, SHIFT(81),
  [29] = {.count = 1, .reusable = false}, SHIFT_EXTRA(),
  [31] = {.count = 1, .reusable = true}, SHIFT(55),
  [33] = {.count = 1, .reusable = true}, SHIFT(57),
  [35] = {.count = 1, .reusable = true}, SHIFT(64),
  [37] = {.count = 1, .reusable = true}, SHIFT(59),
  [39] = {.count = 1, .reusable = true}, SHIFT(10),
  [41] = {.count = 1, .reusable = true}, REDUCE(sym_module_identifier, 1),
  [43] = {.count = 1, .reusable = true}, REDUCE(sym__qualified_module_identifier, 1),
  [45] = {.count = 1, .reusable = true}, SHIFT(73),
  [47] = {.count = 1, .reusable = false}, REDUCE(sym_type_identifier, 1),
  [49] = {.count = 1, .reusable = true}, REDUCE(sym_type_identifier, 1),
  [51] = {.count = 1, .reusable = true}, REDUCE(sym_qualified_module_identifier, 2),
  [53] = {.count = 1, .reusable = true}, SHIFT(18),
  [55] = {.count = 1, .reusable = false}, SHIFT(7),
  [57] = {.count = 1, .reusable = true}, REDUCE(sym_export, 1),
  [59] = {.count = 1, .reusable = true}, SHIFT(46),
  [61] = {.count = 1, .reusable = true}, SHIFT(2),
  [63] = {.count = 1, .reusable = true}, SHIFT(33),
  [65] = {.count = 1, .reusable = false}, REDUCE(sym_qualified_type_identifier, 3),
  [67] = {.count = 1, .reusable = true}, REDUCE(sym_qualified_type_identifier, 3),
  [69] = {.count = 1, .reusable = true}, REDUCE(sym_module, 2),
  [71] = {.count = 1, .reusable = true}, SHIFT(53),
  [73] = {.count = 2, .reusable = true}, REDUCE(aux_sym_export_repeat1, 2), SHIFT_REPEAT(8),
  [76] = {.count = 1, .reusable = true}, REDUCE(aux_sym_export_repeat1, 2),
  [78] = {.count = 2, .reusable = true}, REDUCE(aux_sym_qualified_module_identifier_repeat1, 2), SHIFT_REPEAT(10),
  [81] = {.count = 1, .reusable = true}, SHIFT(8),
  [83] = {.count = 1, .reusable = true}, SHIFT(47),
  [85] = {.count = 1, .reusable = true}, REDUCE(aux_sym__top_declarations_repeat1, 2),
  [87] = {.count = 2, .reusable = true}, REDUCE(aux_sym__top_declarations_repeat1, 2), SHIFT_REPEAT(36),
  [90] = {.count = 1, .reusable = true}, SHIFT(52),
  [92] = {.count = 2, .reusable = true}, REDUCE(aux_sym_exports_repeat1, 2), SHIFT_REPEAT(5),
  [95] = {.count = 1, .reusable = true}, REDUCE(aux_sym_exports_repeat1, 2),
  [97] = {.count = 1, .reusable = true}, SHIFT(4),
  [99] = {.count = 1, .reusable = true}, SHIFT(80),
  [101] = {.count = 1, .reusable = true}, REDUCE(aux_sym_module_repeat1, 2),
  [103] = {.count = 2, .reusable = true}, REDUCE(aux_sym_module_repeat1, 2), SHIFT_REPEAT(53),
  [106] = {.count = 1, .reusable = true}, SHIFT(44),
  [108] = {.count = 1, .reusable = true}, SHIFT(77),
  [110] = {.count = 1, .reusable = true}, SHIFT(36),
  [112] = {.count = 2, .reusable = true}, REDUCE(aux_sym_module_repeat1, 2), SHIFT_REPEAT(44),
  [115] = {.count = 1, .reusable = false}, SHIFT(31),
  [117] = {.count = 1, .reusable = true}, SHIFT(30),
  [119] = {.count = 1, .reusable = true}, SHIFT(3),
  [121] = {.count = 1, .reusable = true}, REDUCE(aux_sym__top_declarations_repeat1, 1),
  [123] = {.count = 1, .reusable = true}, SHIFT(40),
  [125] = {.count = 1, .reusable = true}, SHIFT(62),
  [127] = {.count = 1, .reusable = true}, REDUCE(sym_module, 1),
  [129] = {.count = 1, .reusable = true}, REDUCE(sym__label, 1, .production_id = 1),
  [131] = {.count = 1, .reusable = true}, REDUCE(sym_module_export, 2),
  [133] = {.count = 1, .reusable = true}, SHIFT(45),
  [135] = {.count = 1, .reusable = true}, REDUCE(sym_export, 2),
  [137] = {.count = 1, .reusable = true}, REDUCE(sym_export, 5),
  [139] = {.count = 1, .reusable = true}, REDUCE(sym__qualified_variable, 3),
  [141] = {.count = 1, .reusable = true}, REDUCE(sym__label, 3, .production_id = 2),
  [143] = {.count = 1, .reusable = true}, REDUCE(sym_qualified_variable_identifier, 3),
  [145] = {.count = 1, .reusable = true}, REDUCE(sym_export, 4),
  [147] = {.count = 1, .reusable = true}, SHIFT(58),
  [149] = {.count = 1, .reusable = true}, REDUCE(sym_variable_identifier, 1),
  [151] = {.count = 1, .reusable = true}, REDUCE(sym_constructor_identifier, 1),
  [153] = {.count = 1, .reusable = true}, REDUCE(sym_export, 3),
  [155] = {.count = 1, .reusable = true}, SHIFT(15),
  [157] = {.count = 1, .reusable = true}, REDUCE(sym_exports, 2),
  [159] = {.count = 1, .reusable = true}, REDUCE(sym__top_declarations, 3),
  [161] = {.count = 1, .reusable = true}, SHIFT(74),
  [163] = {.count = 1, .reusable = false}, SHIFT(68),
  [165] = {.count = 1, .reusable = true}, REDUCE(sym_qualified_variable_operator, 3),
  [167] = {.count = 1, .reusable = true}, REDUCE(sym_exports, 5),
  [169] = {.count = 1, .reusable = true}, REDUCE(sym__top_where, 2),
  [171] = {.count = 1, .reusable = true}, SHIFT(50),
  [173] = {.count = 1, .reusable = true},  ACCEPT_INPUT(),
  [175] = {.count = 1, .reusable = true}, REDUCE(sym_exports, 4),
  [177] = {.count = 1, .reusable = true}, REDUCE(sym_module, 4),
  [179] = {.count = 1, .reusable = true}, REDUCE(aux_sym_qualified_module_identifier_repeat1, 2),
  [181] = {.count = 1, .reusable = false}, SHIFT(65),
  [183] = {.count = 2, .reusable = true}, REDUCE(sym__qualified_module_identifier, 1), SHIFT(73),
  [186] = {.count = 1, .reusable = true}, REDUCE(sym__top_declarations, 2),
  [188] = {.count = 1, .reusable = true}, REDUCE(sym_module, 3),
  [190] = {.count = 2, .reusable = true}, REDUCE(sym_qualified_module_identifier, 2), SHIFT(73),
  [193] = {.count = 1, .reusable = true}, REDUCE(sym_exports, 3),
  [195] = {.count = 1, .reusable = true}, SHIFT(49),
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
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym__variable_identifier,
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
