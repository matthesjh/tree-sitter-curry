const decimal = /\d+/;

const exponent = /(e|E)(\+|-)?\d+/;

const floatLiteral = choice(
  seq(decimal, '.', decimal, optional(exponent)),
  seq(decimal, exponent)
);

const PREC = {
  PRAGMA: 1
};

module.exports = grammar({
  name: 'curry',

  extras: $ => [
    $.cpp_directive,
    $.comment,
    $.pragma,
    /\s|\\n/
  ],

  externals: $ => [
    $._layout_semicolon,
    $._layout_open_brace,
    $._layout_close_brace,
    '->',
    $._qualified_module_dot,
    $._initialize_layout
  ],

  word: $ => $._identifier,

  conflicts: $ => [
    [$.qualified_module_identifier, $._qualified_module_identifier],
    [$.qualified_module_identifier],
    [$.function_identifier, $.variable_identifier],
    [$._qualified_function_identifier, $._function],
    [$._qualified_function_identifier, $._fun_op],
    [$.type_identifier, $.data_constructor_identifier],
    [$.type_identifier, $.class_identifier],
    [$._qualified_class_identifier, $.class_declaration],
    [$._function, $._variable],
    [$._qualified_function, $._qualified_data_constructor],
    [$._qualified_infix_operator, $._function, $._variable],
    [$._qualified_infix_operator, $._variable],
    [$._qualified_infix_operator, $._fun_op],
    [$._qual_fun_op, $._qual_con_op],
    [$._import_declaration],
    [$.simple_type],
    [$.data_constructor],
    [$.constructor_pattern],
    [$.constructor_pattern, $.simple_pattern],
    [$.constructor_pattern, $.basic_expression],
    [$.constructor_pattern, $.simple_pattern, $.basic_expression],
    [$.constructor_pattern, $._literal],
    [$.simple_pattern, $.basic_expression],
    [$.simple_pattern, $.general_data_constructor]
  ],

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
        repeat(seq($._top_declaration, choice($.terminal, $._layout_semicolon)))
      )
    ),

    _identifier: $ => /[a-z](\w|')*/,
    _capitalized_identifier: $ => /[A-Z](\w|')*/,
    _operator: $ => token(choice(
      /\.\.[~!@#$%^&*+\-=<>?./|\\:]+/,                      // Prevents matching `..`.
      /\.[~!@#$%^&*+\-=<>?/|\\:][~!@#$%^&*+\-=<>?./|\\:]*/, // Prevents matching `..`.
      /\./,                                                 // Matches the composition operator `.`.
      /:[~!@#$%^&*+\-=<>?./|\\][~!@#$%^&*+\-=<>?./|\\:]*/,  // Prevents matching `:`.
      /::[~!@#$%^&*+\-=<>?./|\\:]+/,                        // Prevents matching `::`.
      /=[~!@#$%^&*+\-=<?./|\\:][~!@#$%^&*+\-=<>?./|\\:]*/,  // Prevents matching `=`.
      /=>[~!@#$%^&*+\-=<>?./|\\:]+/,                        // Prevents matching `=>`.
      /\\[~!@#$%^&*+\-=<>?./|\\:]+/,                        // Prevents matching `\`.
      /\|[~!@#$%^&*+\-=<>?./|\\:]+/,                        // Prevents matching `|`.
      /<-[~!@#$%^&*+\-=<>?./|\\:]+/,                        // Prevents matching `<-`.
      /<[~!@#$%^&*+=<>?./|\\:][~!@#$%^&*+\-=<>?./|\\:]*/,   // Prevents matching `<-`.
      /</,                                                  // Matches the lower than operator `<`.
      /->[~!@#$%^&*+\-=<>?./|\\:]+/,                        // Prevents matching `->`.
      /-[~!@#$%^&*+\-=<?./|\\:][~!@#$%^&*+\-=<>?./|\\:]*/,  // Prevents matching `->`.
      /-/,                                                  // Matches the minus operator `-`.
      /@[~!@#$%^&*+\-=<>?./|\\:]+/,                         // Prevents matching `@`.
      /~[~!@#$%^&*+\-=<>?./|\\:]+/,                         // Prevents matching `~`.
      /[!#$%^&*+>?/\\]+[~!@#$%^&*+\-=<>?./|\\:]*/           // Matches every other operator.
    )),

    module_identifier: $ => $._capitalized_identifier,
    qualified_module_identifier: $ => seq(
      repeat1(seq($.module_identifier, $._qualified_module_dot)),
      $.module_identifier
    ),
    _qualified_module_identifier: $ => choice(
      $.qualified_module_identifier,
      $.module_identifier
    ),

    variable_identifier: $ => $._identifier,
    qualified_variable_identifier: $ => seq(
      $._qualified_module_identifier,
      $._qualified_module_dot,
      $.variable_identifier
    ),
    _qualified_variable_identifier: $ => choice(
      $.qualified_variable_identifier,
      $.variable_identifier
    ),

    function_identifier: $ => $._identifier,
    qualified_function_identifier: $ => seq(
      $._qualified_module_identifier,
      $._qualified_module_dot,
      $.function_identifier
    ),
    _qualified_function_identifier: $ => choice(
      $.qualified_function_identifier,
      $.function_identifier
    ),

    label_identifier: $ => $._identifier,
    qualified_label_identifier: $ => seq(
      $._qualified_module_identifier,
      $._qualified_module_dot,
      $.label_identifier
    ),
    _qualified_label_identifier: $ => choice(
      $.qualified_label_identifier,
      $.label_identifier
    ),

    infix_operator: $ => $._operator,
    qualified_infix_operator: $ => seq(
      $._qualified_module_identifier,
      $._qualified_module_dot,
      $.infix_operator
    ),
    _qualified_infix_operator: $ => choice(
      $.qualified_infix_operator,
      $.infix_operator
    ),

    type_identifier: $ => $._capitalized_identifier,
    qualified_type_identifier: $ => seq(
      $._qualified_module_identifier,
      $._qualified_module_dot,
      $.type_identifier
    ),
    _qualified_type_identifier: $ => choice(
      $.qualified_type_identifier,
      $.type_identifier
    ),

    class_identifier: $ => $._capitalized_identifier,
    qualified_class_identifier: $ => seq(
      $._qualified_module_identifier,
      $._qualified_module_dot,
      $.class_identifier
    ),
    _qualified_class_identifier: $ => choice(
      $.qualified_class_identifier,
      $.class_identifier
    ),

    data_constructor_identifier: $ => $._capitalized_identifier,
    qualified_data_constructor_identifier: $ => seq(
      $._qualified_module_identifier,
      $._qualified_module_dot,
      $.data_constructor_identifier
    ),
    _qualified_data_constructor_identifier: $ => choice(
      $.qualified_data_constructor_identifier,
      $.data_constructor_identifier
    ),

    _variable: $ => choice(
      $.variable_identifier,
      parens($.infix_operator)
    ),

    _function: $ => choice(
      $.function_identifier,
      parens($.infix_operator)
    ),

    _qualified_function: $ => choice(
      $._qualified_function_identifier,
      parens($._qualified_infix_operator)
    ),

    _label: $ => choice(
      $.label_identifier,
      parens($.infix_operator)
    ),

    _qualified_label: $ => choice(
      $._qualified_label_identifier,
      parens($._qualified_infix_operator)
    ),

    _data_constructor: $ => choice(
      $.data_constructor_identifier,
      parens($.infix_operator)
    ),

    _qualified_data_constructor: $ => choice(
      $._qualified_data_constructor_identifier,
      parens($._qualified_infix_operator)
    ),

    _op: $ => choice(
      $.infix_operator,
      backticks(choice(
        $.function_identifier,
        $.data_constructor_identifier
      ))
    ),

    _qual_op: $ => choice(
      ':',
      $._qualified_infix_operator,
      backticks(choice(
        $._qualified_function_identifier,
        $._qualified_data_constructor_identifier
      ))
    ),

    _fun_op: $ => choice(
      $.infix_operator,
      backticks($.function_identifier)
    ),

    _qual_fun_op: $ => choice(
      $._qualified_infix_operator,
      backticks($._qualified_function_identifier)
    ),

    _label_op: $ => choice(
      $.infix_operator,
      backticks($.label_identifier)
    ),

    _qual_label_op: $ => choice(
      $._qualified_infix_operator,
      backticks($._qualified_label_identifier)
    ),

    _con_op: $ => choice(
      $.infix_operator,
      backticks($.data_constructor_identifier)
    ),

    _qual_con_op: $ => choice(
      ':',
      $._qualified_infix_operator,
      backticks($._qualified_data_constructor_identifier)
    ),

    type_variable_identifier: $ => $._identifier,
    _type_variable: $ => choice(
      $.type_variable_identifier,
      '_'
    ),

    terminal: $ => ';',

    comment: $ => token(choice(
      seq('--', /.*/),
      seq(
        '{-',
        repeat(choice(/[^-]/, /-[^}]/)),
        '-}'
      )
    )),

    cpp_directive: $ => token(seq('#', /.*/)),

    pragma: $ => token(prec(PREC.PRAGMA, seq(
      '{-#',
      repeat(choice(/[^#]/, /#[^-]/, /#-[^}]/)),
      '#-}'
    ))),

    int: $ => token(choice(
      /0(b|B)[0-1]+/,
      /0(o|O)[0-7]+/,
      /0(x|X)[0-9A-Fa-f]+/,
      decimal
    )),

    float: $ => token(floatLiteral),

    char: $ => token(/'(\\(NUL|SOH|STX|ETX|EOT|ENQ|ACK|BEL|BS|HT|LF|VT|FF|CR|SO|SI|DLE|DC1|DC2|DC3|DC4|NAK|SYN|ETB|CAN|EM|SUB|ESC|FS|GS|RS|US|SP|DEL|[abfnrtv"'\\]|\d+|o[0-7]+|x[0-9A-Fa-f]+|\^[@-_])|[ -[\]-~])'/),

    string: $ => token(seq(
      '"',
      repeat(choice(
        /[^\\"\n]/,
        /\\(\^)?(.|\n)/
      )),
      '"'
    )),

    _literal: $ => choice(
      $.int,
      $.float,
      $.char,
      $.string
    ),

    exports: $ => parens(seq(
      optional(sep1(',', $.export)),
      optional(',')
    )),

    export: $ => choice(
      $.module_export,
      $._qualified_function,
      seq(
        $._qualified_type_identifier,
        optional(choice(
          $.all_constructors,
          parens(optional(sep1(',', choice(
            $._function,
            $.data_constructor_identifier
          ))))
        ))
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
      braces(repeat(seq($._top_declaration, optional($.terminal)))),
      seq(
        $._layout_open_brace,
        repeat(seq($._top_declaration, choice($.terminal, $._layout_semicolon))),
        $._layout_close_brace
      )
    ),

    _top_declaration: $ => choice(
      $.import_declaration,
      $.fixity_declaration,
      $.default_declaration,
      $.datatype_declaration,
      $.newtype_declaration,
      $.type_synonym_declaration,
      $.class_declaration,
      $.instance_declaration,
      $._declaration
    ),

    import_declaration: $ => seq(
      'import',
      optional('qualified'),
      $._import_declaration
    ),

    _import_declaration: $ => seq(
      choice(
        $.import_alias,
        $._qualified_module_identifier
      ),
      optional(choice(
        $.import_spec,
        $.hiding_import_spec
      ))
    ),

    import_alias: $ => seq(
      $._qualified_module_identifier,
      'as',
      $._qualified_module_identifier
    ),

    import_spec: $ => parens(optional(sep1(',', $.import))),

    hiding_import_spec: $ => seq(
      'hiding',
      parens(optional(sep1(',', $.import)))
    ),

    import: $ => choice(
      $._function,
      seq(
        $.type_identifier,
        optional(choice(
          $.all_constructors,
          parens(optional(sep1(',', choice(
            $._function,
            $.data_constructor_identifier
          ))))
        ))
      )
    ),

    fixity_declaration: $ => seq(
      choice('infixl', 'infixr', 'infix'),
      optional($.int),
      sep1(',', $._op)
    ),

    default_declaration: $ => seq(
      'default',
      parens(optional(sep1(',', $.type_expression)))
    ),

    type_expression: $ => seq(
      repeat($.forall_vars),
      optional($.context),
      $.func_type_expression
    ),

    forall_vars: $ => seq(
      'forall',
      repeat1($.type_variable_identifier),
      '.'
    ),

    context: $ => seq(
      choice(
        $.constraint,
        parens(optional(sep1(',', $.constraint)))
      ),
      '=>'
    ),

    constraint: $ => seq(
      $._qualified_class_identifier,
      choice(
        $.type_variable_identifier,
        parens(seq(
          $.type_variable_identifier,
          $.app_type_expression
        ))
      )
    ),

    func_type_expression: $ => prec.right(seq(
      $.app_type_expression,
      optional(seq(
        '->',
        $.type_expression
      ))
    )),

    app_type_expression: $ => prec.left(repeat1($.simple_type_expression)),

    simple_type_expression: $ => choice(
      $._type_variable,
      $.type_constructor,
      $.tuple_type,
      $.list_type,
      $.paren_type
    ),

    tuple_type: $ => parens(seq(
      $.type_expression,
      ',',
      sep1(',', $.type_expression)
    )),

    list_type: $ => brackets($.type_expression),

    paren_type: $ => parens($.type_expression),

    type_constructor: $ => choice(
      '()',
      '[]',
      '(->)',
      $.tuple_constructor,
      $._qualified_type_identifier
    ),

    tuple_constructor: $ => /\(,+\)/,

    simple_type: $ => seq(
      $.type_identifier,
      repeat($._type_variable)
    ),

    newtype_declaration: $ => seq(
      'newtype',
      $.simple_type,
      '=',
      $.newtype_constructor,
      optional($.deriving)
    ),

    datatype_declaration: $ => choice(
      seq(
        'external',
        'data',
        $.simple_type
      ),
      seq(
        'data',
        $.simple_type,
        optional(seq('=', $.constructor_declarations)),
        optional($.deriving)
      )
    ),

    constructor_declarations: $ => sep1(
      '|',
      choice(
        $.data_constructor,
        $.infix_data_constructor,
        $.record_data_constructor
      )
    ),

    data_constructor: $ => seq(
      $.data_constructor_identifier,
      repeat($.simple_type_expression)
    ),

    infix_data_constructor: $ => seq(
      $.app_type_expression,
      $._con_op,
      $.app_type_expression
    ),

    record_data_constructor: $ => seq(
      $.data_constructor_identifier,
      $.fields
    ),

    fields: $ => braces(sep1(',', $.field)),

    field: $ => seq(
      sep1(',', $._label),
      '::',
      $.type_expression
    ),

    newtype_constructor: $ => seq(
      $.data_constructor_identifier,
      choice(
        $.simple_type_expression,
        braces($.newtype_field)
      )
    ),

    newtype_field: $ => seq(
      $._label,
      '::',
      $.type_expression
    ),

    deriving: $ => seq(
      'deriving',
      parens(optional(sep1(',', $._qualified_class_identifier)))
    ),

    class_declaration: $ => seq(
      'class',
      optional($.simple_context),
      $.class_identifier,
      $.type_variable_identifier,
      $._where
    ),

    instance_declaration: $ => seq(
      'instance',
      optional($.simple_context),
      $._qualified_class_identifier,
      $.instance_type,
      $._where
    ),

    instance_type: $ => choice(
      $.type_constructor,
      parens(seq($.type_constructor, repeat($.type_variable_identifier))),
      parens(seq($.type_variable_identifier, ',', sep1(',', $.type_variable_identifier))),
      brackets($.type_variable_identifier),
      parens(seq($.type_variable_identifier, '->', $.type_variable_identifier))
    ),

    simple_context: $ => seq(
      choice(
        $.simple_constraint,
        parens(optional(sep1(',', $.simple_constraint)))
      ),
      '=>'
    ),

    simple_constraint: $ => seq(
      $._qualified_class_identifier,
      $.type_variable_identifier
    ),

    _where: $ => seq(
      'where',
      $._declarations
    ),

    type_synonym_declaration: $ => seq(
      'type',
      $.simple_type,
      '=',
      $.type_expression
    ),

    _declarations: $ => choice(
      braces(repeat(seq($._declaration, optional($.terminal)))),
      seq(
        $._layout_open_brace,
        repeat(seq($._declaration, choice($.terminal, $._layout_semicolon))),
        $._layout_close_brace
      )
    ),

    _declaration: $ => choice(
      $.signature,
      $.external_declaration,
      $.equation
    ),

    functions: $ => sep1(',', $._function),

    signature: $ => seq(
      $.functions,
      '::',
      $.type_expression
    ),

    external_declaration: $ => seq(
      $.functions,
      'external'
    ),

    equation: $ => seq(
      $.function_lhs,
      $.rhs
    ),

    function_lhs: $ => choice(
      seq($._function, repeat($.simple_pattern)),
      seq($.constructor_pattern, $._fun_op, $.constructor_pattern),
      seq(parens($.function_lhs), repeat1($.simple_pattern))
    ),

    rhs: $ => choice(
      seq('=', $.expression, optional($._local_where)),
      seq($._guards, optional($._local_where))
    ),

    _guards: $ => repeat1($.guard),

    guard: $ => seq(
      '|',
      $.infix_expression,
      '=',
      $.expression
    ),

    _local_where: $ => seq(
      'where',
      $._local_declarations
    ),

    _local_declarations: $ => choice(
      braces(repeat(seq($._local_declaration, optional($.terminal)))),
      seq(
        $._layout_open_brace,
        repeat(seq($._local_declaration, choice($.terminal, $._layout_semicolon))),
        $._layout_close_brace
      )
    ),

    _local_declaration: $ => choice(
      $._declaration,
      $.pattern_declaration,
      seq(repeat1($._variable), 'free'),
      $.fixity_declaration
    ),

    pattern_declaration: $ => seq(
      $.pattern,
      $.rhs
    ),

    pattern: $ => seq(
      $.constructor_pattern,
      optional(seq($._qual_con_op, $.pattern))
    ),

    constructor_pattern: $ => choice(
      seq($.general_data_constructor, repeat1($.simple_pattern)),
      seq('-', choice($.int, $.float)),
      $.simple_pattern
    ),

    simple_pattern: $ => choice(
      $._variable,
      '_',
      $.general_data_constructor,
      $._literal,
      $.paren_pattern,
      $.list_pattern,
      $.tuple_pattern,
      seq($._variable, '@', $.simple_pattern),
      seq('~', $.simple_pattern),
      parens(seq($._qualified_function, repeat1($.simple_pattern))),
      parens(seq($.constructor_pattern, $._qual_fun_op, $.pattern)),
      seq($._qualified_data_constructor, $.pattern_fields)
    ),

    tuple_pattern: $ => parens(seq(
      $.pattern,
      ',',
      sep1(',', $.pattern)
    )),

    list_pattern: $ => brackets(sep1(',', $.pattern)),

    paren_pattern: $ => parens($.pattern),

    pattern_fields: $ => braces(sep1(',', $.pattern_field)),

    pattern_field: $ => seq(
      $._qualified_label,
      '=',
      $.pattern
    ),

    expression: $ => prec.right(seq(
      $.infix_expression,
      optional(seq('::', $.type_expression))
    )),

    infix_expression: $ => choice(
      prec.right(seq($.no_operator_expression, optional(seq($._qual_op, $.infix_expression)))),
      seq('-', $.infix_expression)
    ),

    no_operator_expression: $ => choice(
      seq('\\', repeat1($.simple_pattern), '->', $.expression),
      seq('let', $._local_declarations, 'in', $.expression),
      seq('if', $.expression, 'then', $.expression, 'else', $.expression),
      seq('case', $.expression, 'of', $._alts),
      seq('fcase', $.expression, 'of', $._alts),
      $.do,
      $.function_expression
    ),

    do: $ => seq(
      'do',
      $._statements
    ),

    _statements: $ => choice(
      braces(seq(
        repeat(seq($.statement, optional($.terminal))),
        $.expression
      )),
      seq(
        $._layout_open_brace,
        repeat(seq($.statement, choice($.terminal, $._layout_semicolon))),
        $._layout_close_brace
      )
    ),

    statement: $ => choice(
      seq($.pattern, '<-', $.expression),
      seq('let', $._local_declarations),
      $.expression
    ),

    _alts: $ => choice(
      braces(repeat1(seq($.alt, optional($.terminal)))),
      seq(
        $._layout_open_brace,
        repeat1(seq($.alt, choice($.terminal, $._layout_semicolon))),
        $._layout_close_brace
      )
    ),

    alt: $ => choice(
      seq($.pattern, '->', $.expression, $._local_where),
      seq($.pattern, $.gdalts, $._local_where)
    ),

    gdalts: $ => seq(
      '|',
      $.infix_expression,
      '->',
      $.expression,
      optional($.gdalts)
    ),

    function_expression: $ => prec.left(repeat1($.basic_expression)),

    basic_expression: $ => choice(
      $._variable,
      '_',
      $._qualified_function,
      $.general_data_constructor,
      $._literal,
      $.paren_expression,
      $.list_expression,
      $.tuple_expression,
      brackets(seq($.expression, optional(seq(',', $.expression)), '..', optional($.expression))),
      brackets(seq($.expression, '|', repeat1($.statement))),
      parens(seq($.infix_expression, $._qual_op)),
      parens(seq($._qual_op, $.infix_expression)),
      seq($.basic_expression, $.field_binds)
    ),

    tuple_expression: $ => parens(seq(
      $.expression,
      ',',
      sep1(',', $.expression)
    )),

    list_expression: $ => brackets(sep1(',', $.expression)),

    paren_expression: $ => parens($.expression),

    field_binds: $ => braces(optional(sep1(',', $.field_bind))),

    field_bind: $ => seq(
      $._qualified_label,
      '=',
      $.expression
    ),

    general_data_constructor: $ => choice(
      '()',
      '[]',
      $.tuple_constructor,
      $._qualified_data_constructor
    ),
  }
});

function sep1(sep, rule) {
  return seq(rule, repeat(seq(sep, rule)));
}

function parens(rule) {
  return seq('(', rule, ')');
}

function brackets(rule) {
  return seq('[', rule, ']');
}

function braces(rule) {
  return seq('{', rule, '}');
}

function backticks(rule) {
  return seq('`', rule, '`');
}