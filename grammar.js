module.exports = grammar({
  name: 'curry',

  extras: $ => [
    $.cpp_directive,
    $.comment,
    /\s|\\n/,
    $.pragma
  ],

  externals: $ => [
    $._layout_semicolon,
    $._layout_open_brace,
    $._layout_close_brace,
    '->',
    $._qualified_module_dot,
    $._initialize_layout
  ],

  conflicts: $ => [
    [$._qualified_module_identifier, $.qualified_module_identifier],
    [$.qualified_module_identifier]
  ],

  word: $ => $._variable_identifier,

  rules: {
    module: $ => choice(
      seq(
        'module',
        $._qualified_module_identifier,
        optional($.exports),
        $._top_where
      ),
      seq(
        $._initialize_layout,
        repeat(seq($._top_declaration, choice($._terminal, $._layout_semicolon)))
      )
    ),

    module_identifier: $ => /[A-Z](\w|')*/,
    qualified_module_identifier: $ => seq(
      repeat1(seq($.module_identifier, $._qualified_module_dot)),
      $.module_identifier
    ),
    _qualified_module_identifier: $ => choice(
      $.qualified_module_identifier,
      $.module_identifier
    ),

    exports: $ => seq(
      '(',
      optional(sep1(',', $.export)),
      optional(','),
      ')'
    ),

    export: $ => seq(
      choice(
        $.module_export,
        $._qualified_variable,
        seq(
          $._qualified_type_identifier,
          optional(choice(
            optional($.all_constructors),
            seq(
              '(',
              optional(sep1(',', choice(
                $._label,
                $.constructor_identifier
              ))),
              ')'
            )
          ))
        )
      )
    ),

    module_export: $ => seq(
      'module',
      $._qualified_module_identifier
    ),

    all_constructors: $ => '(..)',

    _top_where: $ => seq(
      'where',
      $._top_declarations
    ),

    _top_declarations: $ => choice(
      seq(
        '{',
        repeat(seq($._top_declaration, optional($._terminal))),
        '}'
      ),
      seq(
        $._layout_open_brace,
        repeat(seq($._top_declaration, choice($._terminal, $._layout_semicolon))),
        $._layout_close_brace
      )
    ),

    _top_declaration: $ => 'DECL',

    _variable_identifier: $ => /[a-z](\w|')*/,
    variable_identifier: $ => $._variable_identifier,
    qualified_variable_identifier: $ => seq(
      $._qualified_module_identifier,
      $._qualified_module_dot,
      $.variable_identifier
    ),
    _qualified_variable_identifier: $ => choice(
      $.qualified_variable_identifier,
      $.variable_identifier
    ),

    variable_operator: $ => /[~!@#$%^&*+\-=<>?./|\\\\:]+/,
    qualified_variable_operator: $ => seq(
      $._qualified_module_identifier,
      $._qualified_module_dot,
      $.variable_operator
    ),
    _qualified_variable_operator: $ => choice(
      $.qualified_variable_operator,
      $.variable_operator
    ),

    _variable: $ => choice(
      $.variable_identifier,
      seq(
        '(',
        $.variable_operator,
        ')'
      )
    ),
    _qualified_variable: $ => choice(
      $._qualified_variable_identifier,
      seq(
        '(',
        $._qualified_variable_operator,
        ')'
      )
    ),

    _label: $ => choice(
      alias($.variable_identifier, $.label_identifier),
      seq(
        '(',
        alias($.variable_operator, $.label_operator),
        ')'
      )
    ),

    type_identifier: $ => /[A-Z](\w|')*/,
    qualified_type_identifier: $ => seq(
      $._qualified_module_identifier,
      $._qualified_module_dot,
      $.type_identifier
    ),
    _qualified_type_identifier: $ => choice(
      $.qualified_type_identifier,
      $.type_identifier
    ),

    constructor_identifier: $ => /[A-Z](\w|')*/,

    _terminal: $ => ';',

    comment: $ => token(choice(
      seq('--', /.*/),
      seq(
        '{-',
        /[^#]/,
        repeat(choice(/[^-]/, /-[^}]/)),
        '-}'
      )
    )),

    cpp_directive: $ => token(seq('#', /.*/)),

    pragma: $ => token(
      seq(
        '{-#',
        repeat(choice(/[^#]/, /#[^-]/, /#\-[^}]/)),
        '#-}'
      )
    ),
  }
});

function sep1(sep, rule) {
  return seq(rule, repeat(seq(sep, rule)))
}