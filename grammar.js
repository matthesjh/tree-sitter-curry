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

  rules: {
    module: $ => 'module',

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