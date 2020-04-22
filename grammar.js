const digit = /[0-9]/;
const binit = /[0-1]/;
const octit = /[0-7]/;
const hexit = /[0-9A-Fa-f]/;

const decimal = repeat1(digit);
const binary = repeat1(binit);
const octal = repeat1(octit);
const hexaDecimal = repeat1(hexit);

const binaryLiteral = seq('0', choice('b', 'B'), binary);
const octalLiteral = seq('0', choice('o', 'O'), octal);
const hexaDecimalLiteral = seq('0', choice('x', 'X'), hexaDecimal);

const exponent = seq(choice('e', 'E'), optional(choice('+', '-')), decimal);

const floatLiteral = choice(
  seq(decimal, '.', decimal, optional(exponent)),
  seq(decimal, exponent)
);

const PREC = {
  CLASS_DECLARATION: 1,
  INSTANCE_DECLARATION: 1,
  PRAGMA: 1,
  RECORD_DATA_CONSTRUCTOR: 1,
  TYPE_CONSTRUCTOR: 1
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

  conflicts: $ => [
    [$._qualified_module_identifier, $.qualified_module_identifier],
    [$.qualified_module_identifier],
    [$.type_identifier, $.constructor_identifier]
  ],

  word: $ => $._identifier,

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
      /\.\.[~!@#$%^&*+\-=<>?./|\\\\:]+/,                       // Prevents matching `..`.
      /\./,                                                    // Matches the composition operator `.`.
      /:[~!@#$%^&*+\-=<>?./|\\][~!@#$%^&*+\-=<>?./|\\\\:]*/,   // Prevents matching `:`.
      /::[~!@#$%^&*+\-=<>?./|\\\\:]+/,                         // Prevents matching `::`.
      /=[~!@#$%^&*+\-=<?./|\\\\:][~!@#$%^&*+\-=<>?./|\\\\:]*/, // Prevents matching `=`.
      /=>[~!@#$%^&*+\-=<>?./|\\\\:]+/,                         // Prevents matching `=>`.
      /\\[~!@#$%^&*+\-=<>?./|\\\\:]+/,                         // Prevents matching `\`.
      /\|[~!@#$%^&*+\-=<>?./|\\\\:]+/,                         // Prevents matching `|`.
      /<-[~!@#$%^&*+\-=<>?./|\\\\:]+/,                         // Prevents matching `<-`.
      /<[~!@#$%^&*+=<>?./|\\\\:][~!@#$%^&*+\-=<>?./|\\\\:]*/,  // Prevents matching `<-`.
      /</,                                                     // Matches the lower than operator `<`.
      /->[~!@#$%^&*+\-=<>?./|\\\\:]+/,                         // Prevents matching `->`.
      /-[~!@#$%^&*+\-=<?./|\\\\:][~!@#$%^&*+\-=<>?./|\\\\:]*/, // Prevents matching `->`.
      /-/,                                                     // Matches the minus operator `-`.
      /@[~!@#$%^&*+\-=<>?./|\\\\:]+/,                          // Prevents matching `@`.
      /~[~!@#$%^&*+\-=<>?./|\\\\:]+/,                          // Prevents matching `~`.
      /[!#$%^&*+>?/\\]+[~!@#$%^&*+\-=<>?./|\\\\:]*/            // Matches every other operator.
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

    variable_operator: $ => $._operator,
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

    _op: $ => choice(
      $.variable_operator,
      seq(
        '`',
        choice(
          $.variable_identifier,
          $.constructor_identifier
        ),
        '`'
      )
    ),

    _con_op: $ => choice(
      $.variable_operator,
      seq(
        '`',
        $.constructor_identifier,
        '`'
      )
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

    type_variable_identifier: $ => $._identifier,

    constructor_identifier: $ => $._capitalized_identifier,

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
      binaryLiteral,
      octalLiteral,
      hexaDecimalLiteral,
      decimal
    )),

    float: $ => token(floatLiteral),

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
            $.all_constructors,
            seq(
              '(',
              optional(sep1(',', choice(
                alias($._variable, $.label),
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
        repeat(seq($._top_declaration, optional($.terminal))),
        '}'
      ),
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
      $.class_declaration,
      $.instance_declaration
    ),

    import_declaration: $ => seq(
      'import',
      optional('qualified'),
      $._import_declaration
    ),

    _import_declaration: $ => prec.right(seq(
      choice(
        $.import_alias,
        $._qualified_module_identifier
      ),
      optional(choice(
        $.import_spec,
        $.hiding_import_spec
      ))
    )),

    import_alias: $ => seq(
      $._qualified_module_identifier,
      'as',
      $._qualified_module_identifier
    ),

    import_spec: $ => seq(
      '(',
      optional(sep1(',', $.import)),
      ')'
    ),

    hiding_import_spec: $ => seq(
      'hiding',
      '(',
      optional(sep1(',', $.import)),
      ')'
    ),

    import: $ => seq(
      choice(
        $._variable,
        seq(
          $.type_identifier,
          optional(choice(
            $.all_constructors,
            seq(
              '(',
              optional(sep1(',', choice(
                alias($._variable, $.label),
                $.constructor_identifier
              ))),
              ')'
            )
          ))
        )
      )
    ),

    fixity_declaration: $ => seq(
      choice('infixl', 'infixr', 'infix'),
      optional($.int),
      sep1(',', $._op)
    ),

    default_declaration: $ => seq(
      'default',
      '(',
      optional(sep1(',', $.type_expression)),
      ')'
    ),

    type_expression: $ => seq(
      repeat($.forall_vars),
      optional(seq($.context, '=>')),
      $.func_type_expression
    ),

    forall_vars: $ => seq(
      'forall',
      repeat1($.type_variable_identifier),
      '.'
    ),

    context: $ => choice(
      $.constraint,
      seq(
        '(',
        optional(sep1(',', $.constraint)),
        ')'
      )
    ),

    constraint: $ => choice(
      seq($._qualified_type_identifier, $.type_variable_identifier),
      seq(
        $._qualified_type_identifier,
        '(',
        $.type_variable_identifier,
        repeat1($.simple_type_expression),
        ')'
      )
    ),

    func_type_expression: $ => seq(
      $.app_type_expression,
      optional(seq(
        '->',
        $.type_expression
      ))
    ),

    app_type_expression: $ => repeat1($.simple_type_expression),

    simple_type_expression: $ => choice(
      '_',
      $.type_variable_identifier,
      $.type_constructor,
      $.tuple_type,
      $.list_type,
      $.paren_type
    ),

    tuple_type: $ => seq(
      '(',
      $.type_expression,
      ',',
      sep1(',', $.type_expression),
      ')'
    ),

    list_type: $ => seq(
      '[',
      $.type_expression,
      ']'
    ),

    paren_type: $ => seq(
      '(',
      $.type_expression,
      ')'
    ),

    type_constructor: $ => prec(PREC.TYPE_CONSTRUCTOR, choice(
      '()',
      '[]',
      '(->)',
      seq('(', repeat1(','), ')'),
      $._qualified_type_identifier
    )),

    simple_type: $ => prec.right(seq(
      $.type_identifier,
      repeat($.type_variable_identifier)
    )),

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

    data_constructor: $ => prec.left(seq(
      $.constructor_identifier,
      repeat($.simple_type_expression)
    )),

    infix_data_constructor: $ => prec.left(seq(
      $.app_type_expression,
      $._con_op,
      $.app_type_expression
    )),

    record_data_constructor: $ => prec(PREC.RECORD_DATA_CONSTRUCTOR, seq(
      $.constructor_identifier,
      $.fields
    )),

    fields: $ => seq(
      '{',
      sep1(',', $.field),
      '}'
    ),

    field: $ => prec.left(seq(
      sep1(',', alias($._variable, $.label)),
      '::',
      $.type_expression
    )),

    newtype_constructor: $ => choice(
      seq(
        $.constructor_identifier,
        $.simple_type_expression
      ),
      seq(
        $.constructor_identifier,
        '{',
        $.newtype_field,
        '}'
      )
    ),

    newtype_field: $ => seq(
      alias($._variable, $.label),
      '::',
      $.type_expression
    ),

    deriving: $ => seq(
      'deriving',
      seq(
        '(',
        optional(sep1(',', $._qualified_type_identifier)),
        ')'
      )
    ),

    instance_type: $ => choice(
      $.type_constructor,
      seq('(', $.type_constructor, repeat($.type_variable_identifier), ')'),
      seq('(', $.type_variable_identifier, ',', sep1(',', $.type_variable_identifier), ')'),
      seq('[', $.type_variable_identifier, ']'),
      seq('(', $.type_variable_identifier, '->', $.type_variable_identifier, ')')
    ),

    simple_context: $ => choice(
      $.simple_constraint,
      seq(
        '(',
        optional(sep1(',', $.simple_constraint)),
        ')'
      )
    ),

    simple_constraint: $ => seq(
      $._qualified_type_identifier,
      $.type_variable_identifier
    ),

    class_declaration: $ => prec(PREC.CLASS_DECLARATION, seq(
      'class',
      optional(seq($.simple_context, '=>')),
      $.type_identifier,
      $.type_variable_identifier,
      $._where
    )),

    instance_declaration: $ => prec(PREC.INSTANCE_DECLARATION, seq(
      'instance',
      optional(seq($.simple_context, '=>')),
      $._qualified_type_identifier,
      $.instance_type,
      $._where
    )),

    _where: $ => seq(
      'where',
      $._declarations
    ),

    _declarations: $ => 'DECL'
  }
});

function sep1(sep, rule) {
  return seq(rule, repeat(seq(sep, rule)));
}